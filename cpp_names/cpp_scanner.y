%require "2.4.1"
%skeleton "lalr1.cc"
%locations
%output "cpp_scanner_y.cpp"
%defines
%define namespace "CppNames"
%define parser_class_name "CppBisonParser"
%lex-param   { CppNames::CppFlexScanner &scanner }
%parse-param   { CppNames::CppFlexScanner &scanner }
%parse-param { CppNames::CppBisonParserContext &context }

%code requires 
{
#include "name_info.h"

#include <string>
#include <list>
#include <algorithm>
#include <stack>

namespace CppNames 
{
  class CppFlexScanner;

  struct ParserStackType
  {
    std::string ident;
    NameInfo name;
    int intvalue;
    NameInfoList list;
    bool flag;
    NameInfo::NameAccess access;
    std::vector<std::string> ident_list;
  };

  struct ScopeElement
  {
    NameInfo::NameAccess Access;

    ScopeElement(): Access(NameInfo::ACCESS_PUBLIC)
    {
    }
  };

  class ScopeStack
  {
  private:
    std::stack<ScopeElement> stack;

    void Push(ScopeElement element)
    {
      stack.push(element);
    }

  public:
    ScopeElement &Top()
    {
      return stack.top();
    }

    bool Empty()
    {
      return stack.empty();
    }

    void PushScope(const NameInfo& info)
    {
      ScopeElement scope;

      if (info.Type == NameInfo::NAME_CLASS)
      {
        scope.Access = NameInfo::ACCESS_PRIVATE;
      }

      Push(scope);
    }
  
    void PopScope()
    {
      stack.pop();
    }

    NameInfo::NameAccess ScopeAccess()
    {
      if (stack.empty())
      {
        return NameInfo::ACCESS_PUBLIC;
      }

      ScopeElement& top = Top();
      return top.Access;
    }

    void SetAccess(NameInfo::NameAccess access)
    {
      if (stack.empty())
      {

        return;
      }

      ScopeElement& top = Top();
      top.Access = access;
    }
  };

  struct CppBisonParserContext
  {
    NameInfoSet& names;
    ScopeStack scopes;

    CppBisonParserContext(NameInfoSet& p_names)
      : names(p_names)
    {
    }
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

%token NAMESPACE '{' '}' QUALIFIER UNQUALIFIER CLASS STRUCT ENUM UNION PRIVATE PUBLIC PROTECTED
%token VIRTUAL CATCH THREEDOT FRIEND TYPEDEF TEMPLATE TYPENAME
%left CONST '*' '&'
%token '(' ')' ';' ',' '=' ':' '<' '>'
%token<ident> IDENT FUNCTION_BODY 
%token<intvalue> INTVALUE
%type<list> program declaration_list namespace_declaration parameter_list nonempty_parameter_list
%type<list> class_body class_definition template_parameter_list nonempty_template_parameter_list
%type<name> qualified_name type parameter class_name enum_name union_name template_parameter
%type<name> forward_declaration function_declaration function_definition name_declaration typedef_declaration
%type<list> class_inheritance inheritance_list catchlist
%type<name> inheritance_name
%type<flag> constqualifier virtualqualifier abstractqualifier
%type<access> access_qualifier

%%

program: declaration_list {
		for_each($1.begin(), $1.end(), AddName(context.names));
	}
	;

declaration_list: { }
	| declaration_list namespace_declaration {
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
  | declaration_list error {
    $$ = $1;
  }
	;

namespace_declaration:
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

name_declaration:
  forward_declaration
  | function_declaration
  | function_definition
  | typedef_declaration

class_definition:
    class_name 
    {
      context.scopes.PushScope($1);
    }
    class_inheritance '{' 
    {
      $1.Parents = $3;
    } 
    class_body '}' ';' 
    {
		  $$ = $6;
		  for_each($$.begin(), $$.end(), AddNamespace($1.Name));
		  $$.push_back($1);
      context.scopes.PopScope();
    }
  | TEMPLATE '<' template_parameter_list '>' 
    class_name 
    {
      context.scopes.PushScope($5);
    }
    class_inheritance '{' 
    {
      $5.Parents = $7;
      $5.IsTemplate = true;
    } 
    class_body '}' ';' 
    {
		  $$ = $10;
		  for_each($$.begin(), $$.end(), AddNamespace($5.Name));
		  $$.push_back($5);
      context.scopes.PopScope();
    }
  | enum_name '{' 
    {
      begin_function_body(scanner);
    }  
    FUNCTION_BODY ';'  
    {
 		  $$.push_back($1);
    }
  | union_name '{' 
    {
      begin_function_body(scanner);
    }  
    FUNCTION_BODY ';'  
    {
 		  $$.push_back($1);
    }
  ;


class_inheritance:
    {
    }
  | ':' inheritance_list
    {
      $$ = $2;
    }

inheritance_list:
    inheritance_name
    {
      $$.push_back($1);
    }
  | inheritance_list ',' inheritance_name
    {
      $$ = $1;
      $$.push_back($3);
    }

inheritance_name:
  virtualqualifier qualified_name
    {
      $$ = $2;
      $$.Access = context.scopes.ScopeAccess();
      $$.Type = NameInfo::NAME_CLASS;
      $$.IsVirtual = $1;
    }
  | virtualqualifier access_qualifier qualified_name
    {
      $$ = $3;
      $$.Access = $2;
      $$.Type = NameInfo::NAME_CLASS;
      $$.IsVirtual = $1;
    }   
  ;

class_name:
  CLASS IDENT {
    $$ = NameInfo($2, NameInfo::NAME_CLASS);
  }
  | STRUCT IDENT {
    $$ = NameInfo($2, NameInfo::NAME_STRUCT);
    $$.Access = NameInfo::ACCESS_PUBLIC;
  }
  ;

enum_name:
  ENUM IDENT {
    $$ = NameInfo($2, NameInfo::NAME_ENUM);
  }

union_name:
  UNION IDENT {
    $$ = NameInfo($2, NameInfo::NAME_UNION);
  }

class_body: {}
  | class_body access_qualifier ':' {
    $$ = $1;
    context.scopes.SetAccess($2);
  }
  | class_body name_declaration {
    $2.Access = context.scopes.ScopeAccess();
    $$ = $1;
    $$.push_back($2);
  }
	| class_body class_definition {
		$$ = $1;
		$$.insert($$.end(), $2.begin(), $2.end());
  }
  ;

access_qualifier:
  PUBLIC { $$ = NameInfo::ACCESS_PUBLIC; }
  | PRIVATE { $$ = NameInfo::ACCESS_PRIVATE; }
  | PROTECTED { $$ = NameInfo::ACCESS_PROTECTED; }

typedef_declaration:
  TYPEDEF type IDENT ';' 
  {
     $$ = NameInfo($3, NameInfo::NAME_TYPE);
     $$.Alias = $2.Name;

  }

forward_declaration:
  class_name ';' {
    $$ = $1;
  }
  | FRIEND class_name ';' {
    $$ = $2;
    $$.IsFriend = true;
  }
  ;

function_declaration:
  virtualqualifier type qualified_name '(' parameter_list ')' constqualifier abstractqualifier';' 
  {
    $$ = $3;
    $$.Type = NameInfo::NAME_FUNCTION;
    $$.IsConst = $7;
    $$.IsVirtual = $1;
    $$.IsAbstract = $8;
  }
  | FRIEND type qualified_name '(' parameter_list ')' ';' 
  {
    $$ = $3;
    $$.Type = NameInfo::NAME_FUNCTION;
    $$.IsFriend = true;
  }
  ;

function_definition:
  virtualqualifier type qualified_name '(' parameter_list ')' constqualifier '{' 
  {
    begin_function_body(scanner);
  }  
  FUNCTION_BODY catchlist
  {
    $$ = $3;
    $$.Type = NameInfo::NAME_FUNCTION;
    $$.IsConst = $7;
    $$.IsVirtual = $1;
  }
  | TEMPLATE '<' template_parameter_list '>' 
  type qualified_name '(' parameter_list ')' constqualifier '{' 
  {
    begin_function_body(scanner);
  }  
  FUNCTION_BODY catchlist
  {
    $$ = $6;
    $$.Type = NameInfo::NAME_FUNCTION;
    $$.IsConst = $10;
    $$.IsTemplate = true;
  }
  ;

catchlist: {}
  | catchlist CATCH '(' catch_parameter ')' '{'
  {
    begin_function_body(scanner);
  }
  FUNCTION_BODY
  {
  }

catch_parameter: 
  parameter
  | THREEDOT

abstractqualifier:
  {
    $$ = false;
  }
  | '=' INTVALUE
  {
    $$ = true;
    if ($2 != 0)
    {
      error(yylloc, "invalid INT value");
      YYERROR;
    }
  }

virtualqualifier:
  {
    $$ = false;
  }
  | VIRTUAL
  {
    $$ = true;
  }

template_parameter_list: {}
  | nonempty_template_parameter_list {$$ = $1;}

nonempty_template_parameter_list:
  template_parameter {
    $$.push_back($1);
  }
  | nonempty_template_parameter_list ',' template_parameter {
    $$ = $1;
    $$.push_back($3);
  }
  ;

template_parameter: 
  type IDENT 
  {
      $$ = $2;
  }
  | CLASS IDENT 
  {
      $$ = $2;
  }
  | CLASS IDENT '=' type
  {
      $$ = $2;
  }
  | TYPENAME IDENT 
  {
      $$ = $2;
  }
  | TYPENAME IDENT '=' type
  {
      $$ = $2;
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
