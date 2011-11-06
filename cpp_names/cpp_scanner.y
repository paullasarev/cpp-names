%require "2.4.1"
%skeleton "lalr1.cc"
%locations
%output "cpp_scanner_y.cpp"
%defines
%define namespace "CppNames"
%define parser_class_name "CppBisonParser"
%parse-param { CppNames::CppFlexScanner &scanner }
%lex-param   { CppNames::CppFlexScanner &scanner }
%parse-param { CppNames::NameInfoSet& names }

%code requires 
{
#include "name_info.h"

#include <string>
#include <list>
#include <algorithm>

namespace CppNames 
{
  class CppFlexScanner;


struct ParserStackType
{
	std::string ident;
  NameInfo name;
	std::list<NameInfo> list;
  bool flag;
};

}

#define YYSTYPE CppNames::ParserStackType

}

%code 
{
static int yylex(CppNames::CppBisonParser::semantic_type* yylval,  CppNames::CppBisonParser::location_type* yyloc,  CppNames::CppFlexScanner& scanner);
static void begin_function_body(CppNames::CppFlexScanner& scanner);

namespace CppNames
{
struct AddName
{
	NameInfoSet& Names;
	
	AddName(NameInfoSet& names): Names(names)
	{
	}

	void operator()(const NameInfo& name)
	{
		NameInfo info(name);
		Names.insert(info);
	}
};

struct AddNamespace
{
	const std::string& Namespace;
	
	AddNamespace(const std::string& pNamespace): Namespace(pNamespace)
	{
	}

	void operator()(NameInfo& info)
	{
    if (info.Qualified)
    {
      return;
    }

		info.Name = Namespace + "::" + info.Name;
	}
};

}

}

%token NAMESPACE '{' '}' QUALIFIER UNQUALIFIER CLASS STRUCT
%left CONST '*' '&'
%token '(' ')' ';' ',' 
%token<ident> IDENT FUNCTION_BODY
%type<list> program declaration_list name_space parameter_list nonempty_parameter_list
%type<list> class_body class_definition
%type<name> qualified_name type parameter classname
%type<name> forward_declaration function_declaration function_definition name_declaration
%type<flag> constqualifier

%%

program: declaration_list {
		for_each($1.begin(), $1.end(), AddName(names));
	}
	;

name_space:
	NAMESPACE IDENT '{' declaration_list '}' {
		$$ = $4;
		for_each($$.begin(), $$.end(), AddNamespace($2));
		$$.push_back(NameInfo($2, NameInfo::NAME_NAMESPACE));
	}
  | NAMESPACE '{' declaration_list '}' {
		$$ = $3;
		for_each($$.begin(), $$.end(), AddNamespace("anonymous"));
		$$.push_back(NameInfo("anonymous", NameInfo::NAME_NAMESPACE));
	}
	;

declaration_list: { }
	| declaration_list name_space {
		$$ = $1;
		$$.insert($$.end(), $2.begin(), $2.end());
  }
  | declaration_list name_declaration {
    $$ = $1;
    $$.push_back($2);
  }
	| declaration_list class_definition {
		$$ = $1;
		$$.insert($$.end(), $2.begin(), $2.end());
  }
	;

name_declaration:
  forward_declaration
  | function_declaration
  | function_definition

class_definition:
  classname '{' class_body '}' ';' {
		$$ = $3;
		for_each($$.begin(), $$.end(), AddNamespace($1.Name));
		$$.push_back($1);
  }
  ;

classname:
  CLASS IDENT {
    $$ = NameInfo($2, NameInfo::NAME_CLASS);
  }
  | STRUCT IDENT {
    $$ = NameInfo($2, NameInfo::NAME_STRUCT);
  }
  ;

class_body: {}
  | class_body name_declaration {
    $$ = $1;
    $$.push_back($2);
  }
	| class_body class_definition {
		$$ = $1;
		$$.insert($$.end(), $2.begin(), $2.end());
  }
  ;

forward_declaration:
  classname ';' {
    $$ = $1;
  }
  ;

function_declaration:
  type qualified_name '(' parameter_list ')' constqualifier ';' {
    $$ = $2;
    $$.Type = NameInfo::NAME_FUNCTION;
    $$.IsConst = $6;
  }
  ;

function_definition:
  type qualified_name '(' parameter_list ')' constqualifier '{' {
    begin_function_body(scanner);
  }  
  FUNCTION_BODY {
    $$ = $2;
    $$.Type = NameInfo::NAME_FUNCTION;
    $$.IsConst = $6;
  }
  ;

parameter_list: {}
  | nonempty_parameter_list {$$ = $1;}

nonempty_parameter_list:
  parameter {
    $$.push_back($1);
  }
  | nonempty_parameter_list ',' parameter {
    $$ = $1;
    $$.push_back($3);
  }
  ;

parameter: type {
    $$ = $1;
   }
   | type IDENT {
      $$ = $1;
   }
   ;

type: qualified_name {
      $$ = $1;
      $$.Type = NameInfo::NAME_TYPE;
   }
   | type '*' {
      $$ = $1;
   }
   | type '&' {
      $$ = $1;
   }
   |  type CONST '*' {
      $$ = $1;
   }
   |  CONST type {
      $$ = $2;
   }

constqualifier: {
     $$ = false;
   }
   | CONST {
     $$ = true;
   }
   

qualified_name: IDENT {
        $$ = NameInfo($1);
      }
    |
    UNQUALIFIER IDENT {
      $$ = NameInfo($2);
      $$.Qualified = true;
    }
    |
    qualified_name QUALIFIER IDENT {
      $$ = NameInfo($1.Name + "::" + $3);
    }
    ;


%%

#include "cpp_scanner_flex.h"

void CppNames::CppBisonParser::error(const CppNames::CppBisonParser::location_type& loc, const std::string& msg) 
{
	std::ostream& out = *scanner.get_yyout();
	out << std::endl << "Parse error: " << msg << std::endl;
	out << "at: " << loc << std::endl;
}

static int yylex(CppNames::CppBisonParser::semantic_type* yylval,  CppNames::CppBisonParser::location_type* yyloc,  CppNames::CppFlexScanner& scanner)
{
  return scanner.yylex(yylval, yyloc);
}

static void begin_function_body(CppNames::CppFlexScanner& scanner)
{
  scanner.begin_function_body();
}
