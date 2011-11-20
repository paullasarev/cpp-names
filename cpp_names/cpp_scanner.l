%{
#include "cpp_scanner_flex.h"
%}

%option nodefault
%option c++
%option batch
%option outfile="cpp_scanner_l.cpp"
%option yyclass="CppFlexScanner"
%option noyywrap
%option nounistd

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%x FUNCTION
%x COMMENT
%x PREPROCESSOR

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FLOATSPEC		(f|F|l|L)
INTSPEC			(u|U|l|L)*
NL \r?\n
SPACE [ \t]
IDENT [A-Za-z_][A-Za-z0-9_]*
NOTNL [^\r\n]
LINECOMMENT ^{SPACE}*"//"{NOTNL}*{NL}

%%

<INITIAL,FUNCTION>{LINECOMMENT} {
}

<INITIAL,FUNCTION>"/*" {
  comment_state = YYSTATE;
  BEGIN(COMMENT);
}

^"#" {
  BEGIN(PREPROCESSOR);
}

<PREPROCESSOR>{NOTNL}*"\\"{NL} {
  yylloc->lines(1);
  yylloc->step();
}

<PREPROCESSOR>{NOTNL}*{NL} {
  yylloc->lines(1);
  yylloc->step();
  BEGIN(INITIAL);
}

<COMMENT>[^*\r\n]+ {
}

<COMMENT>{NL} {
  yylloc->lines(1);
  yylloc->step();
}

<COMMENT>"*/" {
  BEGIN(comment_state);
}

<COMMENT>. {
}

"namespace"  { return CppBisonParser::token::NAMESPACE; }
"const"  { return CppBisonParser::token::CONST; }
"class"  { return CppBisonParser::token::CLASS; }
"struct"  { return CppBisonParser::token::STRUCT; }
"enum"  { return CppBisonParser::token::ENUM; }
"union"  { return CppBisonParser::token::UNION; }
"private"  { return CppBisonParser::token::PRIVATE; }
"public"  { return CppBisonParser::token::PUBLIC; }
"protected"  { return CppBisonParser::token::PROTECTED; }
"virtual"  { return CppBisonParser::token::VIRTUAL; }
"catch"  { return CppBisonParser::token::CATCH; }
"friend"  { return CppBisonParser::token::FRIEND; }
"typedef"  { return CppBisonParser::token::TYPEDEF; }
"template"  { return CppBisonParser::token::TEMPLATE; }
"typename"  { return CppBisonParser::token::TYPENAME; }

{D}+{INTSPEC}? {
  yylval->intvalue = std::atoi(yytext); 
  return CppBisonParser::token::INTVALUE; 
}

\{  { return '{'; }
\}  {	return '}'; }
\(  { return '('; }
\)  { return ')';	}
\<  { return '<'; }
\>  {	return '>'; }
\;  { return ';'; }
\,  { return ','; }
\*  { return '*'; }
\&  { return '&'; }
\=  { return '='; }

(^|{SPACE}+)"::" { 
  return CppBisonParser::token::UNQUALIFIER;
}

"::" { 
  return CppBisonParser::token::QUALIFIER;
}

":"  { return ':'; }

"..." { 
  return CppBisonParser::token::THREEDOT;
}

<FUNCTION>[^\{\}\r\n/]+ {
}

<FUNCTION>{NL}	{
  yylloc->lines(1);
  yylloc->step();
}

<FUNCTION>\{ {
    ++bracket_level;
}

<FUNCTION>\} {
    --bracket_level;
    if (bracket_level == 0)
    {
      BEGIN(INITIAL);
		  yylval->ident = std::string(yytext, yyleng); 
		  return CppBisonParser::token::FUNCTION_BODY;
    }
}

<FUNCTION>. {
}

{IDENT}	 { 
		yylval->ident = std::string(yytext, yyleng); 
		return CppBisonParser::token::IDENT;
}

{NL}	{
  yylloc->lines(1);
  yylloc->step();
}

. { 
}


%%