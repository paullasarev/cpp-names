#ifndef CPP_SCANNER_FLEX_H
#define CPP_SCANNER_FLEX_H

#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif

//flex interface:
//
//class yyFlexLexer: public FlexLexer
//{
//yyFlexLexer::yyFlexLexer( std::istream* arg_yyin, std::ostream* arg_yyout )
//void yyFlexLexer::switch_streams( std::istream* new_in, std::ostream* new_out ) 
//int yyFlexLexer::yylex()
//const char* YYText() const
//int YYLeng()	const
//int lineno() const
//}

// Override the interface for yylex since we namespaced it
#undef YY_DECL
#define YY_DECL int CppNames::CppFlexScanner::yylex()

// Include Bison for types / tokens
#include "cpp_scanner_y.hpp"


namespace CppNames
{
	class CppFlexScanner : public yyFlexLexer 
	{
		public:
      CppFlexScanner(std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0)
        : yyFlexLexer(arg_yyin, arg_yyout)
      {
      }

			// save the pointer to yylval so we can change it, and invoke scanner
      int yylex(CppBisonParser::semantic_type* lval, CppBisonParser::location_type* yyloc)
			{ 
				yylval = lval; 
        yylloc = yyloc;

				return yylex(); 
			}
		
      std::istream* get_yyin()
      {
        return yyin;
      }

      std::ostream* get_yyout()
      {
        return yyout;
      }

      void begin_function_body()
      {
#define M_BEGIN (yy_start) = 1 + 2 *
#define M_FUNCTION 1
        M_BEGIN(M_FUNCTION);
        bracket_level = 1;
      }

		private:
			// Scanning function created by Flex; make this private to force usage
			// of the overloaded method so we can get a pointer to Bison's yylval
			int yylex();
			
			// point to yylval (provided by Bison in overloaded yylex)
			CppBisonParser::semantic_type* yylval;
      CppBisonParser::location_type* yylloc;
      int bracket_level;
      int comment_state;
	};
}
 

#endif
