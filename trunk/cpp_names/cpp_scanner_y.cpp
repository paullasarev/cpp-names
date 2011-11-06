/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2010 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* First part of user declarations.  */


/* Line 310 of lalr1.cc  */
#line 39 "cpp_scanner_y.cpp"


#include "cpp_scanner_y.hpp"

/* User implementation prologue.  */


/* Line 316 of lalr1.cc  */
#line 48 "cpp_scanner_y.cpp"
/* Unqualified %code blocks.  */

/* Line 317 of lalr1.cc  */
#line 40 "cpp_scanner.y"

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




/* Line 317 of lalr1.cc  */
#line 99 "cpp_scanner_y.cpp"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* Enable debugging if requested.  */
#if YYDEBUG

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


/* Line 379 of lalr1.cc  */
#line 6 "cpp_scanner.y"
namespace CppNames {

/* Line 379 of lalr1.cc  */
#line 167 "cpp_scanner_y.cpp"
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  CppBisonParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              /* Fall through.  */
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  CppBisonParser::CppBisonParser (CppNames::CppFlexScanner &scanner_yyarg, CppNames::NameInfoSet& names_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      names (names_yyarg)
  {
  }

  CppBisonParser::~CppBisonParser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  CppBisonParser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  CppBisonParser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif

  void
  CppBisonParser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  CppBisonParser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  CppBisonParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  CppBisonParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  CppBisonParser::debug_level_type
  CppBisonParser::debug_level () const
  {
    return yydebug_;
  }

  void
  CppBisonParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif

  int
  CppBisonParser::parse ()
  {
    /// Lookahead and lookahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    semantic_type yylval;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;

    /* Accept?  */
    if (yystate == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without lookahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a lookahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc, scanner);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Shift the lookahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted.  */
    yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:

/* Line 677 of lalr1.cc  */
#line 96 "cpp_scanner.y"
    {
		for_each((yysemantic_stack_[(1) - (1)].list).begin(), (yysemantic_stack_[(1) - (1)].list).end(), AddName(names));
	}
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 102 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(5) - (4)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(5) - (2)].ident)));
		(yyval.list).push_back(NameInfo((yysemantic_stack_[(5) - (2)].ident), NameInfo::NAME_NAMESPACE));
	}
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 107 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(4) - (3)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace("anonymous"));
		(yyval.list).push_back(NameInfo("anonymous", NameInfo::NAME_NAMESPACE));
	}
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 114 "cpp_scanner.y"
    { }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 115 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 119 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 123 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 135 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(5) - (3)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(5) - (1)].name).Name));
		(yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
  }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 143 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_CLASS);
  }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 146 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_STRUCT);
  }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 151 "cpp_scanner.y"
    {}
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 152 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 156 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 163 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
  }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 169 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (2)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(7) - (6)].flag);
  }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 177 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 180 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(9) - (2)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(9) - (6)].flag);
  }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 187 "cpp_scanner.y"
    {}
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 188 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 191 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 194 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 200 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
   }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 203 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 208 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Type = NameInfo::NAME_TYPE;
   }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 212 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 215 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 218 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (1)].name);
   }
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 221 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
   }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 225 "cpp_scanner.y"
    {
     (yyval.flag) = false;
   }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 228 "cpp_scanner.y"
    {
     (yyval.flag) = true;
   }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 233 "cpp_scanner.y"
    {
        (yyval.name) = NameInfo((yysemantic_stack_[(1) - (1)].ident));
      }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 237 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident));
      (yyval.name).Qualified = true;
    }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 242 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(3) - (1)].name).Name + "::" + (yysemantic_stack_[(3) - (3)].ident));
    }
    break;



/* Line 677 of lalr1.cc  */
#line 766 "cpp_scanner_y.cpp"
	default:
          break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
	  }
      }

    /* Else will try to reuse lookahead token after shifting the error
       token.  */
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the lookahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  CppBisonParser::yysyntax_error_ (int yystate)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char CppBisonParser::yypact_ninf_ = -14;
  const signed char
  CppBisonParser::yypact_[] =
  {
       -14,     2,    22,   -14,     7,   -13,    -4,     6,    37,   -14,
     -14,   -14,   -14,     5,   -14,   -14,   -14,    36,    13,   -14,
      52,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,    31,
      49,    15,    -2,   -14,    28,   -14,    37,   -14,   -14,     9,
      43,   -14,   -14,    45,    44,   -14,    40,   -14,   -14,    51,
      37,   -14,   -14,    23,   -14,   -14,   -14,    46,   -14
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  CppBisonParser::yydefact_[] =
  {
         5,     0,     2,     1,     0,     0,     0,     0,     0,    35,
       6,     7,     8,     0,     9,    10,    11,     0,    28,     5,
       0,    36,    13,    14,    32,    15,    18,    29,    30,     0,
       0,     0,     0,     5,     0,    31,    22,    37,     4,     0,
       0,    16,    17,     0,    23,    24,    26,     3,    12,    33,
       0,    27,    34,     0,    25,    20,    19,     0,    21
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  CppBisonParser::yypgoto_[] =
  {
       -14,   -14,   -14,   -11,    27,    32,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,    17,    -8,   -14,    48
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  CppBisonParser::yydefgoto_[] =
  {
        -1,     1,    10,     2,    11,    12,    13,    34,    14,    15,
      16,    57,    43,    44,    45,    17,    53,    18
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char CppBisonParser::yytable_ninf_ = -1;
  const unsigned char
  CppBisonParser::yytable_[] =
  {
        24,     4,     3,    38,    21,     5,     6,     7,    32,    25,
       8,    19,     4,    22,    47,     9,     5,     6,     7,    31,
      26,     8,    39,    23,    20,     4,     9,    55,    46,     5,
       6,     7,    37,    40,     8,     5,     6,     7,    56,     9,
       8,    35,    46,     5,     5,     9,    27,    28,    29,     8,
      27,    28,    29,     9,     9,    31,    33,    51,    48,    49,
      50,    41,    36,    52,    58,    30,    42,    54
  };

  /* YYCHECK.  */
  const unsigned char
  CppBisonParser::yycheck_[] =
  {
         8,     3,     0,     5,    17,     7,     8,     9,    19,     4,
      12,     4,     3,    17,     5,    17,     7,     8,     9,     6,
      15,    12,    33,    17,    17,     3,    17,     4,    36,     7,
       8,     9,    17,     5,    12,     7,     8,     9,    15,    17,
      12,    10,    50,     7,     7,    17,    10,    11,    12,    12,
      10,    11,    12,    17,    17,     6,     4,    17,    15,    14,
      16,    34,    13,    12,    18,    17,    34,    50
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CppBisonParser::yystos_[] =
  {
         0,    20,    22,     0,     3,     7,     8,     9,    12,    17,
      21,    23,    24,    25,    27,    28,    29,    34,    36,     4,
      17,    17,    17,    17,    34,     4,    15,    10,    11,    12,
      36,     6,    22,     4,    26,    10,    13,    17,     5,    22,
       5,    23,    24,    31,    32,    33,    34,     5,    15,    14,
      16,    17,    12,    35,    33,     4,    15,    30,    18
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  CppBisonParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   123,   125,   259,   260,   261,   262,
      42,    38,   263,    40,    41,    59,    44,   264,   265
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CppBisonParser::yyr1_[] =
  {
         0,    19,    20,    21,    21,    22,    22,    22,    22,    23,
      23,    23,    24,    25,    25,    26,    26,    26,    27,    28,
      30,    29,    31,    31,    32,    32,    33,    33,    34,    34,
      34,    34,    34,    35,    35,    36,    36,    36
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CppBisonParser::yyr2_[] =
  {
         0,     2,     1,     5,     4,     0,     2,     2,     2,     1,
       1,     1,     5,     2,     2,     0,     2,     2,     2,     7,
       0,     9,     0,     1,     1,     3,     1,     2,     1,     2,
       2,     3,     2,     0,     1,     1,     2,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const CppBisonParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NAMESPACE", "'{'", "'}'", "QUALIFIER",
  "UNQUALIFIER", "CLASS", "STRUCT", "'*'", "'&'", "CONST", "'('", "')'",
  "';'", "','", "IDENT", "FUNCTION_BODY", "$accept", "program",
  "name_space", "declaration_list", "name_declaration", "class_definition",
  "classname", "class_body", "forward_declaration", "function_declaration",
  "function_definition", "$@1", "parameter_list",
  "nonempty_parameter_list", "parameter", "type", "constqualifier",
  "qualified_name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CppBisonParser::rhs_number_type
  CppBisonParser::yyrhs_[] =
  {
        20,     0,    -1,    22,    -1,     3,    17,     4,    22,     5,
      -1,     3,     4,    22,     5,    -1,    -1,    22,    21,    -1,
      22,    23,    -1,    22,    24,    -1,    27,    -1,    28,    -1,
      29,    -1,    25,     4,    26,     5,    15,    -1,     8,    17,
      -1,     9,    17,    -1,    -1,    26,    23,    -1,    26,    24,
      -1,    25,    15,    -1,    34,    36,    13,    31,    14,    35,
      15,    -1,    -1,    34,    36,    13,    31,    14,    35,     4,
      30,    18,    -1,    -1,    32,    -1,    33,    -1,    32,    16,
      33,    -1,    34,    -1,    34,    17,    -1,    36,    -1,    34,
      10,    -1,    34,    11,    -1,    34,    12,    10,    -1,    12,
      34,    -1,    -1,    12,    -1,    17,    -1,     7,    17,    -1,
      36,     6,    17,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  CppBisonParser::yyprhs_[] =
  {
         0,     0,     3,     5,    11,    16,    17,    20,    23,    26,
      28,    30,    32,    38,    41,    44,    45,    48,    51,    54,
      62,    63,    73,    74,    76,    78,    82,    84,    87,    89,
      92,    95,    99,   102,   103,   105,   107,   110
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  CppBisonParser::yyrline_[] =
  {
         0,    96,    96,   102,   107,   114,   115,   119,   123,   130,
     131,   132,   135,   143,   146,   151,   152,   156,   163,   169,
     177,   177,   187,   188,   191,   194,   200,   203,   208,   212,
     215,   218,   221,   225,   228,   233,   237,   242
  };

  // Print the state stack on the debug stream.
  void
  CppBisonParser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  CppBisonParser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "):" << std::endl;
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  CppBisonParser::token_number_type
  CppBisonParser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
           0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    11,     2,
      13,    14,    10,     2,    16,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    15,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     4,     2,     5,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     6,
       7,     8,     9,    12,    17,    18
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CppBisonParser::yyeof_ = 0;
  const int CppBisonParser::yylast_ = 67;
  const int CppBisonParser::yynnts_ = 18;
  const int CppBisonParser::yyempty_ = -2;
  const int CppBisonParser::yyfinal_ = 3;
  const int CppBisonParser::yyterror_ = 1;
  const int CppBisonParser::yyerrcode_ = 256;
  const int CppBisonParser::yyntokens_ = 19;

  const unsigned int CppBisonParser::yyuser_token_number_max_ = 265;
  const CppBisonParser::token_number_type CppBisonParser::yyundef_token_ = 2;


/* Line 1053 of lalr1.cc  */
#line 6 "cpp_scanner.y"
} // CppNames

/* Line 1053 of lalr1.cc  */
#line 1232 "cpp_scanner_y.cpp"


/* Line 1055 of lalr1.cc  */
#line 248 "cpp_scanner.y"


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

