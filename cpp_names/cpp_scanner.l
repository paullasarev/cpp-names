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
%x PARAMETERS
%x COMMENT
%x STRING
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

<INITIAL,FUNCTION,PARAMETERS>{LINECOMMENT} {
}

<INITIAL,FUNCTION,PARAMETERS>"/*" {
  comment_state = YYSTATE;
  BEGIN(COMMENT);
}

<INITIAL,FUNCTION,PARAMETERS>L?\" {
  comment_state = YYSTATE;
  BEGIN(STRING);
}

<STRING>[^*\r\n\\\"]+ {
}

<STRING>\\\" {
}

<STRING>{NL} {
  yylloc->lines(1);
  yylloc->step();
}

<STRING>\" {
  BEGIN(comment_state);
  return CppBisonParser::token::STRINGVALUE;
}

<STRING>. {
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

<PREPROCESSOR>. {
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

0[xX]{H}+{INTSPEC}?		{ 
  yylval->intvalue = std::strtol(yytext, 0, 16); 
  return CppBisonParser::token::INTVALUE; 
}

0{D}+{INTSPEC}?		{
  std::strtol(yytext, 0, 8);
  return CppBisonParser::token::INTVALUE; 
}

{D}+{INTSPEC}? {
  yylval->intvalue = std::atoi(yytext); 
  return CppBisonParser::token::INTVALUE; 
}

L?\'(\\.|[^\\'])+\'	{
  std::strtol(yytext + 1, 0, 0);
  return CppBisonParser::token::INTVALUE; 
}


{D}+{E}{FLOATSPEC}?   { 
  return CppBisonParser::token::FLOATVALUE; 
}

{D}*"."{D}+({E})?{FLOATSPEC}? { 
  return CppBisonParser::token::FLOATVALUE; 
}

{D}+"."{D}*({E})?{FLOATSPEC}? { 
  return CppBisonParser::token::FLOATVALUE; 
}

\{  { return '{'; }
\}  {	return '}'; }
\(  { return '('; }
\)  { return ')';	}
\[  { return '['; }
\]  { return ']';	}
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

<PARAMETERS>[^\(\)\r\n/]+ {
}

<PARAMETERS>{NL}	{
  yylloc->lines(1);
  yylloc->step();
}

<PARAMETERS>\( {
    ++bracket_level;
}

<PARAMETERS>\) {
    --bracket_level;
    if (bracket_level == 0)
    {
      BEGIN(INITIAL);
		  yylval->ident = std::string(yytext, yyleng); 
		  return CppBisonParser::token::PARAMETER_LIST;
    }
}

<PARAMETERS>. {
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
