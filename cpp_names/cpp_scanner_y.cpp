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
#line 128 "cpp_scanner.y"

static int yylex(CppNames::CppBisonParser::semantic_type* yylval,  CppNames::CppBisonParser::location_type* yyloc,  CppNames::CppFlexScanner& scanner);
static void begin_function_body(CppNames::CppFlexScanner& scanner);
static void begin_parameter_list(CppNames::CppFlexScanner& scanner);

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
#line 100 "cpp_scanner_y.cpp"

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
#line 168 "cpp_scanner_y.cpp"
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
  CppBisonParser::CppBisonParser (CppNames::CppFlexScanner &scanner_yyarg, CppNames::CppBisonParserContext &context_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      context (context_yyarg)
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
#line 191 "cpp_scanner.y"
    {
		for_each((yysemantic_stack_[(1) - (1)].list).begin(), (yysemantic_stack_[(1) - (1)].list).end(), AddName(context.names));
	}
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 197 "cpp_scanner.y"
    { }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 198 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 202 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 206 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 210 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
  }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 217 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(4) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_SYMBOL;
  }
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 222 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_SYMBOL;
  }
    break;

  case 10:

/* Line 677 of lalr1.cc  */
#line 227 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(6) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_SYMBOL;
  }
    break;

  case 11:

/* Line 677 of lalr1.cc  */
#line 232 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 236 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(8) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_SYMBOL;
  }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 240 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (3)].name);
  }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 244 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 248 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(11) - (3)].name);
  }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 265 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(5) - (4)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(5) - (2)].ident)));
		(yyval.list).push_back(NameInfo((yysemantic_stack_[(5) - (2)].ident), NameInfo::NAME_NAMESPACE));
	}
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 270 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(4) - (3)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace("anonymous"));
		(yyval.list).push_back(NameInfo("anonymous", NameInfo::NAME_NAMESPACE));
	}
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 286 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 290 "cpp_scanner.y"
    {
      (yysemantic_stack_[(4) - (1)].name).Parents = (yysemantic_stack_[(4) - (3)].list);
    }
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 294 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(8) - (6)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(8) - (1)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(8) - (1)].name));
      context.scopes.PopScope();
    }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 302 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(5) - (5)].name));
    }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 306 "cpp_scanner.y"
    {
      (yysemantic_stack_[(8) - (5)].name).Parents = (yysemantic_stack_[(8) - (7)].list);
      (yysemantic_stack_[(8) - (5)].name).IsTemplate = true;
    }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 311 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(12) - (10)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(12) - (5)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(12) - (5)].name));
      context.scopes.PopScope();
    }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 318 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 322 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 326 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 330 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 337 "cpp_scanner.y"
    {
    }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 340 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(2) - (2)].list);
    }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 346 "cpp_scanner.y"
    {
      (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 350 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
      (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
    }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 357 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
      (yyval.name).Access = context.scopes.ScopeAccess();
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(2) - (1)].flag);
    }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 364 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (3)].name);
      (yyval.name).Access = (yysemantic_stack_[(3) - (2)].access);
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(3) - (1)].flag);
    }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 373 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_CLASS);
  }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 376 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_STRUCT);
    (yyval.name).Access = NameInfo::ACCESS_PUBLIC;
  }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 383 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_ENUM);
  }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 388 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_UNION);
  }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 392 "cpp_scanner.y"
    {}
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 393 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    context.scopes.SetAccess((yysemantic_stack_[(3) - (2)].access));
  }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 397 "cpp_scanner.y"
    {
    (yysemantic_stack_[(2) - (2)].name).Access = context.scopes.ScopeAccess();
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 402 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 409 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PUBLIC; }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 410 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PRIVATE; }
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 411 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PROTECTED; }
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 415 "cpp_scanner.y"
    {
     (yyval.name) = NameInfo((yysemantic_stack_[(4) - (3)].ident), NameInfo::NAME_TYPE);
     (yyval.name).Alias = (yysemantic_stack_[(4) - (2)].name).Name;

  }
    break;

  case 58:

/* Line 677 of lalr1.cc  */
#line 422 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
  }
    break;

  case 59:

/* Line 677 of lalr1.cc  */
#line 425 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(3) - (2)].name);
    (yyval.name).IsFriend = true;
  }
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 433 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(9) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(9) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(9) - (1)].flag);
    (yyval.name).IsAbstract = (yysemantic_stack_[(9) - (8)].flag);
  }
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 441 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsFriend = true;
  }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 450 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 454 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(11) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(11) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(11) - (1)].flag);
  }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 462 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 466 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(14) - (6)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(14) - (10)].flag);
    (yyval.name).IsTemplate = true;
  }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 474 "cpp_scanner.y"
    {}
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 476 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 480 "cpp_scanner.y"
    {
  }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 488 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 492 "cpp_scanner.y"
    {
    (yyval.flag) = true;
    if ((yysemantic_stack_[(2) - (2)].intvalue) != 0)
    {
      error(yylloc, "invalid INT value");
      YYERROR;
    }
  }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 502 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 506 "cpp_scanner.y"
    {
    (yyval.flag) = true;
  }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 510 "cpp_scanner.y"
    {}
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 511 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 514 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 517 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 525 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 529 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
  }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 533 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(5) - (5)].name);
  }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 540 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 544 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(4) - (2)].ident);
  }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 552 "cpp_scanner.y"
    {}
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 553 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 556 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 89:

/* Line 677 of lalr1.cc  */
#line 559 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 90:

/* Line 677 of lalr1.cc  */
#line 565 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
   }
    break;

  case 91:

/* Line 677 of lalr1.cc  */
#line 568 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 92:

/* Line 677 of lalr1.cc  */
#line 573 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Type = NameInfo::NAME_TYPE;
   }
    break;

  case 93:

/* Line 677 of lalr1.cc  */
#line 577 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 94:

/* Line 677 of lalr1.cc  */
#line 580 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 95:

/* Line 677 of lalr1.cc  */
#line 583 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (1)].name);
   }
    break;

  case 96:

/* Line 677 of lalr1.cc  */
#line 586 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(4) - (1)].name);
      (yyval.name).IsTemplate = true;
   }
    break;

  case 97:

/* Line 677 of lalr1.cc  */
#line 590 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
   }
    break;

  case 98:

/* Line 677 of lalr1.cc  */
#line 596 "cpp_scanner.y"
    {
     (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
   }
    break;

  case 99:

/* Line 677 of lalr1.cc  */
#line 600 "cpp_scanner.y"
    {
     (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
     (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
   }
    break;

  case 100:

/* Line 677 of lalr1.cc  */
#line 605 "cpp_scanner.y"
    {
     (yyval.flag) = false;
   }
    break;

  case 101:

/* Line 677 of lalr1.cc  */
#line 608 "cpp_scanner.y"
    {
     (yyval.flag) = true;
   }
    break;

  case 102:

/* Line 677 of lalr1.cc  */
#line 613 "cpp_scanner.y"
    {
        (yyval.name) = NameInfo((yysemantic_stack_[(1) - (1)].ident));
      }
    break;

  case 103:

/* Line 677 of lalr1.cc  */
#line 617 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident));
      (yyval.name).Qualified = true;
    }
    break;

  case 104:

/* Line 677 of lalr1.cc  */
#line 622 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(3) - (1)].name).Name + "::" + (yysemantic_stack_[(3) - (3)].ident));
    }
    break;



/* Line 677 of lalr1.cc  */
#line 1277 "cpp_scanner_y.cpp"
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
  const signed char CppBisonParser::yypact_ninf_ = -128;
  const short int
  CppBisonParser::yypact_[] =
  {
      -128,    18,    80,  -128,  -128,    13,   -14,    -3,    15,    28,
    -128,    58,    95,    22,  -128,  -128,  -128,  -128,    59,    81,
      92,  -128,  -128,  -128,  -128,    95,  -128,    93,  -128,  -128,
    -128,  -128,    66,    95,  -128,    79,     3,   108,   127,   133,
    -128,    78,  -128,  -128,     3,   102,  -128,  -128,    85,  -128,
    -128,  -128,    96,    95,    14,    88,    97,  -128,   105,  -128,
     115,   132,  -128,  -128,   117,   181,   146,   151,   128,   130,
     140,  -128,   124,  -128,   187,    -9,    95,  -128,  -128,   133,
      58,   133,   134,  -128,   142,  -128,    23,  -128,   145,   155,
      17,  -128,     5,   150,  -128,    95,  -128,   157,   161,  -128,
     184,   167,  -128,     3,  -128,    95,   146,  -128,  -128,  -128,
      24,   108,  -128,  -128,  -128,  -128,  -128,  -128,    51,  -128,
     172,  -128,   186,  -128,   180,   187,   190,    95,  -128,     8,
      78,    67,   187,  -128,   108,   166,   193,    36,   197,   188,
    -128,    35,  -128,  -128,  -128,   218,    95,   196,  -128,  -128,
     195,  -128,  -128,  -128,    11,   199,  -128,   223,  -128,   202,
    -128,  -128,  -128,   191,   203,  -128,  -128,  -128,   197,   198,
    -128,  -128,   200,   182,   227,  -128,   205,   206,  -128,   219,
    -128,  -128,   201,   213,  -128,   121,   219,  -128,   214,  -128,
     235,  -128,   207,  -128
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  CppBisonParser::yydefact_[] =
  {
         3,     0,     0,     1,     7,     0,     0,     0,     0,     0,
      74,     0,     0,     0,    29,     4,     5,     6,    30,     0,
       0,    28,    25,    26,    27,     0,     3,     0,    46,    47,
      48,    49,     0,     0,   102,     0,     0,    92,     0,    75,
      58,    40,    36,    38,     0,     0,     3,   103,    97,    59,
      93,    94,     0,     0,     0,     0,     0,    84,     0,    85,
       0,    76,    77,    80,     0,     0,    73,     0,     0,     0,
       0,    24,     0,    95,    98,     0,    86,   104,    57,    75,
       0,     0,    82,    79,    41,    42,     0,    31,     0,     0,
      86,     8,     0,    16,    23,     0,    96,     0,    87,    88,
      90,     0,    33,     0,    78,     0,    73,    55,    54,    56,
       0,    44,    50,    37,    39,    20,    21,    22,     0,    18,
       0,    11,     0,    17,     0,    99,     0,     0,    91,     0,
      40,     0,    83,    43,    45,    73,     0,     0,   100,     0,
      10,     0,    61,    89,    81,     0,    86,     0,    52,    53,
       0,     9,    19,   101,    71,     0,    13,     0,    34,     0,
      32,    51,    62,     0,     0,    12,    14,    50,   100,     0,
      72,    60,     0,    73,     0,    66,     0,     0,    64,    63,
      15,    35,     0,     0,    66,     0,    65,    70,     0,    69,
       0,    67,     0,    68
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yypgoto_[] =
  {
      -128,  -128,   -13,  -128,  -128,  -128,  -128,  -128,   -86,  -128,
    -127,  -124,  -128,  -128,  -128,  -128,  -128,  -128,   111,  -128,
     136,    -8,  -128,  -128,    77,   159,  -128,  -128,  -128,  -128,
    -128,  -128,    62,  -128,  -128,  -128,   -59,   168,  -128,   169,
     119,  -128,   -85,  -128,  -125,   -11,  -128,    83,   -32
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yydefgoto_[] =
  {
        -1,     1,     2,    14,   139,   172,   124,   118,   119,    15,
      16,    17,    41,   112,   130,   167,    68,    69,    67,    84,
      85,    18,    19,    20,   135,   150,    21,    22,    23,    24,
     169,   182,   179,   192,   188,   164,    25,    60,    61,    62,
      63,    64,    97,    98,    99,   100,    75,   154,    37
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char CppBisonParser::yytable_ninf_ = -74;
  const short int
  CppBisonParser::yytable_[] =
  {
        36,    38,   143,    35,    54,   120,   122,    86,   148,   121,
      32,   149,    70,    45,    44,   162,    57,    26,     3,    95,
      55,    28,    48,    96,    32,    50,    51,    52,    65,    59,
      32,    32,    29,    72,    53,   107,   108,   109,    34,    76,
     163,    33,    74,   115,   116,   117,   148,    86,    27,   149,
      30,   152,    34,    39,   111,   115,   116,   117,    34,    34,
     189,   159,   156,    31,   157,    32,     6,     7,    65,   103,
      65,   131,   102,    55,   115,   116,   117,   136,   134,   137,
      -2,     4,    33,     5,   125,    42,    40,   -73,     6,     7,
       8,     9,   146,    34,   132,    10,    43,    46,    11,    12,
      13,    47,    32,     4,   -73,     5,    49,    71,    66,   -73,
       6,     7,     8,     9,    55,   -73,    53,    10,    73,    33,
      11,    12,    13,    77,    78,     4,   -73,     5,    32,    94,
      34,   -73,     6,     7,     8,     9,    79,   -73,   187,    10,
      32,    57,    11,    12,    13,    33,    55,    80,   -73,    50,
      51,    52,    82,    58,    59,    87,    34,    33,    53,   -73,
      81,    10,    56,   105,    88,    90,    89,    91,    34,    92,
     106,   147,   113,    93,     6,     7,     8,     9,   107,   108,
     109,    10,   114,   126,    11,    12,    13,   177,   123,   127,
       6,     7,     8,     9,   107,   108,   109,    10,   138,   129,
      11,    12,    13,    50,    51,    52,    50,    51,    52,    50,
      51,    52,    53,   140,   141,    53,    83,   142,    53,   128,
     151,   153,   158,   160,   155,   161,   165,   166,   168,   170,
     171,   178,   180,   181,   175,   183,   176,   184,   185,   191,
     190,   145,   133,   193,   173,   110,   186,   101,   144,     0,
     104,   174
  };

  /* YYCHECK.  */
  const short int
  CppBisonParser::yycheck_[] =
  {
        11,    12,   127,    11,    36,    90,    92,    66,   135,     4,
       7,   135,    44,    26,    25,     4,     8,     4,     0,    28,
       6,    35,    33,    32,     7,    22,    23,    24,    39,    21,
       7,     7,    35,    46,    31,    12,    13,    14,    35,    25,
      29,    24,    53,    38,    39,    40,   173,   106,    35,   173,
      35,   137,    35,    31,    86,    38,    39,    40,    35,    35,
     185,   146,    27,    35,    29,     7,     8,     9,    79,    80,
      81,   103,    80,     6,    38,    39,    40,    26,   110,    28,
       0,     1,    24,     3,    95,     4,    27,     7,     8,     9,
      10,    11,    25,    35,   105,    15,     4,     4,    18,    19,
      20,    35,     7,     1,    24,     3,    27,     5,    30,     7,
       8,     9,    10,    11,     6,    35,    31,    15,    22,    24,
      18,    19,    20,    35,    27,     1,    24,     3,     7,     5,
      35,     7,     8,     9,    10,    11,    31,    35,    17,    15,
       7,     8,    18,    19,    20,    24,     6,    32,    24,    22,
      23,    24,    35,    20,    21,     4,    35,    24,    31,    35,
      28,    15,    35,    29,    36,    25,    36,    27,    35,    29,
      28,     5,    27,    33,     8,     9,    10,    11,    12,    13,
      14,    15,    27,    26,    18,    19,    20,     5,    38,    28,
       8,     9,    10,    11,    12,    13,    14,    15,    26,    32,
      18,    19,    20,    22,    23,    24,    22,    23,    24,    22,
      23,    24,    31,    27,    34,    31,    35,    27,    31,    35,
      27,    24,     4,    27,    36,    30,    27,     4,    26,    38,
      27,     4,    27,    27,    36,    16,    36,    36,    25,     4,
      26,   130,   106,    36,   167,    86,   184,    79,   129,    -1,
      81,   168
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CppBisonParser::yystos_[] =
  {
         0,    42,    43,     0,     1,     3,     8,     9,    10,    11,
      15,    18,    19,    20,    44,    50,    51,    52,    62,    63,
      64,    67,    68,    69,    70,    77,     4,    35,    35,    35,
      35,    35,     7,    24,    35,    62,    86,    89,    86,    31,
      27,    53,     4,     4,    86,    43,     4,    35,    86,    27,
      22,    23,    24,    31,    89,     6,    35,     8,    20,    21,
      78,    79,    80,    81,    82,    86,    30,    59,    57,    58,
      89,     5,    43,    22,    86,    87,    25,    35,    27,    31,
      32,    28,    35,    35,    60,    61,    77,     4,    36,    36,
      25,    27,    29,    33,     5,    28,    32,    83,    84,    85,
      86,    78,    62,    86,    80,    29,    28,    12,    13,    14,
      66,    89,    54,    27,    27,    38,    39,    40,    48,    49,
      83,     4,    49,    38,    47,    86,    26,    28,    35,    32,
      55,    89,    86,    61,    89,    65,    26,    28,    26,    45,
      27,    34,    27,    85,    81,    59,    25,     5,    51,    52,
      66,    27,    49,    24,    88,    36,    27,    29,     4,    83,
      27,    30,     4,    29,    76,    27,     4,    56,    26,    71,
      38,    27,    46,    65,    88,    36,    36,     5,     4,    73,
      27,    27,    72,    16,    36,    25,    73,    17,    75,    85,
      26,     4,    74,    36
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  CppBisonParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   123,   125,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,    42,    38,   275,    40,    41,    59,    44,    61,
      58,    60,    62,    91,    93,   276,   277,   278,   279,   280,
     281
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CppBisonParser::yyr1_[] =
  {
         0,    41,    42,    43,    43,    43,    43,    43,    44,    44,
      44,    45,    44,    44,    46,    44,    47,    47,    48,    48,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      53,    54,    52,    55,    56,    52,    57,    52,    58,    52,
      59,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      65,    65,    65,    65,    66,    66,    66,    67,    68,    68,
      69,    69,    71,    70,    72,    70,    73,    74,    73,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    89
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CppBisonParser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     2,     2,     2,     4,     7,
       6,     0,     8,     7,     0,    11,     0,     1,     1,     3,
       1,     1,     1,     5,     4,     1,     1,     1,     1,     1,
       0,     0,     8,     0,     0,    12,     0,     5,     0,     5,
       0,     2,     1,     3,     2,     3,     2,     2,     2,     2,
       0,     3,     2,     2,     1,     1,     1,     4,     2,     3,
       9,     7,     0,    11,     0,    14,     0,     0,     8,     1,
       1,     0,     2,     0,     1,     0,     1,     1,     3,     2,
       1,     5,     2,     4,     1,     1,     0,     1,     1,     3,
       1,     2,     1,     2,     2,     3,     4,     2,     1,     3,
       0,     1,     1,     2,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const CppBisonParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NAMESPACE", "'{'", "'}'", "QUALIFIER",
  "UNQUALIFIER", "CLASS", "STRUCT", "ENUM", "UNION", "PRIVATE", "PUBLIC",
  "PROTECTED", "VIRTUAL", "CATCH", "THREEDOT", "FRIEND", "TYPEDEF",
  "TEMPLATE", "TYPENAME", "'*'", "'&'", "CONST", "'('", "')'", "';'",
  "','", "'='", "':'", "'<'", "'>'", "'['", "']'", "IDENT",
  "FUNCTION_BODY", "PARAMETER_LIST", "INTVALUE", "FLOATVALUE",
  "STRINGVALUE", "$accept", "program", "declaration_list",
  "variable_declaration", "$@1", "$@2", "arraysize", "constant_list",
  "constant", "namespace_declaration", "name_declaration",
  "class_definition", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "class_inheritance", "inheritance_list", "inheritance_name",
  "class_name", "enum_name", "union_name", "class_body",
  "access_qualifier", "typedef_declaration", "forward_declaration",
  "function_declaration", "function_definition", "$@9", "$@10",
  "catchlist", "$@11", "catch_parameter", "abstractqualifier",
  "virtualqualifier", "template_parameter_list",
  "nonempty_template_parameter_list", "template_parameter",
  "classtypename_parameter", "classtypename", "parameter_list",
  "nonempty_parameter_list", "parameter", "type", "type_list",
  "constqualifier", "qualified_name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CppBisonParser::rhs_number_type
  CppBisonParser::yyrhs_[] =
  {
        42,     0,    -1,    43,    -1,    -1,    43,    50,    -1,    43,
      51,    -1,    43,    52,    -1,    43,     1,    -1,    77,    86,
      89,    27,    -1,    77,    86,    89,    25,    48,    26,    27,
      -1,    77,    86,    89,    29,    49,    27,    -1,    -1,    77,
      86,    89,    29,     4,    45,    36,    27,    -1,    77,    86,
      89,    33,    47,    34,    27,    -1,    -1,    77,    86,    89,
      33,    47,    34,    29,     4,    46,    36,    27,    -1,    -1,
      38,    -1,    49,    -1,    48,    28,    49,    -1,    38,    -1,
      39,    -1,    40,    -1,     3,    35,     4,    43,     5,    -1,
       3,     4,    43,     5,    -1,    68,    -1,    69,    -1,    70,
      -1,    67,    -1,    44,    -1,    -1,    -1,    62,    53,    59,
       4,    54,    65,     5,    27,    -1,    -1,    -1,    20,    31,
      78,    32,    62,    55,    59,     4,    56,    65,     5,    27,
      -1,    -1,    63,     4,    57,    36,    27,    -1,    -1,    64,
       4,    58,    36,    27,    -1,    -1,    30,    60,    -1,    61,
      -1,    60,    28,    61,    -1,    77,    89,    -1,    77,    66,
      89,    -1,     8,    35,    -1,     9,    35,    -1,    10,    35,
      -1,    11,    35,    -1,    -1,    65,    66,    30,    -1,    65,
      51,    -1,    65,    52,    -1,    13,    -1,    12,    -1,    14,
      -1,    19,    86,    35,    27,    -1,    62,    27,    -1,    18,
      62,    27,    -1,    77,    86,    89,    25,    83,    26,    88,
      76,    27,    -1,    18,    86,    89,    25,    83,    26,    27,
      -1,    -1,    77,    86,    89,    25,    83,    26,    88,     4,
      71,    36,    73,    -1,    -1,    20,    31,    78,    32,    86,
      89,    25,    83,    26,    88,     4,    72,    36,    73,    -1,
      -1,    -1,    73,    16,    25,    75,    26,     4,    74,    36,
      -1,    85,    -1,    17,    -1,    -1,    29,    38,    -1,    -1,
      15,    -1,    -1,    79,    -1,    80,    -1,    79,    28,    80,
      -1,    86,    35,    -1,    81,    -1,    20,    31,    78,    32,
      81,    -1,    82,    35,    -1,    82,    35,    29,    86,    -1,
       8,    -1,    21,    -1,    -1,    84,    -1,    85,    -1,    84,
      28,    85,    -1,    86,    -1,    86,    35,    -1,    89,    -1,
      86,    22,    -1,    86,    23,    -1,    86,    24,    22,    -1,
      86,    31,    87,    32,    -1,    24,    86,    -1,    86,    -1,
      87,    28,    86,    -1,    -1,    24,    -1,    35,    -1,     7,
      35,    -1,    89,     6,    35,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  CppBisonParser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    12,    15,    18,    23,
      31,    38,    39,    48,    56,    57,    69,    70,    72,    74,
      78,    80,    82,    84,    90,    95,    97,    99,   101,   103,
     105,   106,   107,   116,   117,   118,   131,   132,   138,   139,
     145,   146,   149,   151,   155,   158,   162,   165,   168,   171,
     174,   175,   179,   182,   185,   187,   189,   191,   196,   199,
     203,   213,   221,   222,   234,   235,   250,   251,   252,   261,
     263,   265,   266,   269,   270,   272,   273,   275,   277,   281,
     284,   286,   292,   295,   300,   302,   304,   305,   307,   309,
     313,   315,   318,   320,   323,   326,   330,   335,   338,   340,
     344,   345,   347,   349,   352
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CppBisonParser::yyrline_[] =
  {
         0,   191,   191,   197,   198,   202,   206,   210,   216,   221,
     226,   232,   231,   240,   244,   243,   252,   253,   256,   257,
     260,   261,   262,   265,   270,   278,   279,   280,   281,   282,
     286,   290,   285,   302,   306,   300,   318,   317,   326,   325,
     337,   339,   345,   349,   356,   363,   373,   376,   383,   388,
     392,   393,   397,   402,   409,   410,   411,   414,   422,   425,
     432,   440,   450,   449,   462,   460,   474,   476,   475,   484,
     485,   488,   491,   502,   505,   510,   511,   514,   517,   524,
     528,   532,   539,   543,   549,   550,   552,   553,   556,   559,
     565,   568,   573,   577,   580,   583,   586,   590,   595,   599,
     605,   608,   613,   617,   622
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
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
      25,    26,    22,     2,    28,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    30,    27,
      31,    29,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    33,     2,    34,     2,     2,     2,     2,     2,     2,
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
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    24,    35,    36,    37,    38,
      39,    40
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CppBisonParser::yyeof_ = 0;
  const int CppBisonParser::yylast_ = 251;
  const int CppBisonParser::yynnts_ = 49;
  const int CppBisonParser::yyempty_ = -2;
  const int CppBisonParser::yyfinal_ = 3;
  const int CppBisonParser::yyterror_ = 1;
  const int CppBisonParser::yyerrcode_ = 256;
  const int CppBisonParser::yyntokens_ = 41;

  const unsigned int CppBisonParser::yyuser_token_number_max_ = 281;
  const CppBisonParser::token_number_type CppBisonParser::yyundef_token_ = 2;


/* Line 1053 of lalr1.cc  */
#line 6 "cpp_scanner.y"
} // CppNames

/* Line 1053 of lalr1.cc  */
#line 1898 "cpp_scanner_y.cpp"


/* Line 1055 of lalr1.cc  */
#line 628 "cpp_scanner.y"


#include "cpp_scanner_flex.h"

void CppNames::CppBisonParser::error(const CppNames::CppBisonParser::location_type& loc, const std::string& msg) 
{
  ++context.error_count;
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

static void begin_parameter_list(CppNames::CppFlexScanner& scanner)
{
  scanner.begin_parameter_list();
}

