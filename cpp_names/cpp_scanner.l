%{
 
#include "cpp_scanner_flex.h"
%}

%option nodefault
%option c++
%option batch
%option outfile="cpp_scanner_l.cpp"
%option nodefault
%option yyclass="CppFlexScanner"
%option noyywrap
%option nounistd

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%x FUNCTION
%x COMMENT

NL \r?\n
SPACE [ \t]
IDENT [A-Za-z_][A-Za-z0-9_]*
LINECOMMENT ^{SPACE}*"//"[^\r\n]*{NL}

%%

<INITIAL,FUNCTION>{LINECOMMENT} {
}

<INITIAL,FUNCTION>"/*" {
  comment_state = YYSTATE;
  BEGIN(COMMENT);
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

\{  { return '{'; }
\}  {	return '}'; }
\(  { return '('; }
\)  { return ')';	}
\;  { return ';'; }
\,  { return ','; }
\*  { return '*'; }
\&  { return '&'; }

(^|{SPACE}+)"::" { 
  return CppBisonParser::token::UNQUALIFIER;
}

"::" { 
  return CppBisonParser::token::QUALIFIER;
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
