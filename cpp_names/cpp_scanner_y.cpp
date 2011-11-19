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
#line 125 "cpp_scanner.y"

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
#line 186 "cpp_scanner.y"
    {
		for_each((yysemantic_stack_[(1) - (1)].list).begin(), (yysemantic_stack_[(1) - (1)].list).end(), AddName(context.names));
	}
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 191 "cpp_scanner.y"
    { }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 192 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 196 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 200 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 204 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
  }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 210 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(5) - (4)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(5) - (2)].ident)));
		(yyval.list).push_back(NameInfo((yysemantic_stack_[(5) - (2)].ident), NameInfo::NAME_NAMESPACE));
	}
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 215 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(4) - (3)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace("anonymous"));
		(yyval.list).push_back(NameInfo("anonymous", NameInfo::NAME_NAMESPACE));
	}
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 230 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 234 "cpp_scanner.y"
    {
      (yysemantic_stack_[(4) - (1)].name).Parents = (yysemantic_stack_[(4) - (3)].list);
    }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 238 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(8) - (6)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(8) - (1)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(8) - (1)].name));
      context.scopes.PopScope();
    }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 245 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 249 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 253 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 257 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 263 "cpp_scanner.y"
    {
    }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 266 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(2) - (2)].list);
    }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 272 "cpp_scanner.y"
    {
      (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 276 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
      (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
    }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 283 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
      (yyval.name).Access = context.scopes.ScopeAccess();
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(2) - (1)].flag);
    }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 290 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (3)].name);
      (yyval.name).Access = (yysemantic_stack_[(3) - (2)].access);
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(3) - (1)].flag);
    }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 299 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_CLASS);
  }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 302 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_STRUCT);
    (yyval.name).Access = NameInfo::ACCESS_PUBLIC;
  }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 309 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_ENUM);
  }
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 314 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_UNION);
  }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 318 "cpp_scanner.y"
    {}
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 319 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    context.scopes.SetAccess((yysemantic_stack_[(3) - (2)].access));
  }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 323 "cpp_scanner.y"
    {
    (yysemantic_stack_[(2) - (2)].name).Access = context.scopes.ScopeAccess();
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 328 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 335 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PUBLIC; }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 336 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PRIVATE; }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 337 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PROTECTED; }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 341 "cpp_scanner.y"
    {
     (yyval.name) = NameInfo((yysemantic_stack_[(4) - (3)].ident), NameInfo::NAME_TYPE);
     (yyval.name).Alias = (yysemantic_stack_[(4) - (2)].name).Name;

  }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 348 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
  }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 351 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(3) - (2)].name);
    (yyval.name).IsFriend = true;
  }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 359 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(9) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(9) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(9) - (1)].flag);
    (yyval.name).IsAbstract = (yysemantic_stack_[(9) - (8)].flag);
  }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 367 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsFriend = true;
  }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 376 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 380 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(11) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(11) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(11) - (1)].flag);
  }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 388 "cpp_scanner.y"
    {}
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 390 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 394 "cpp_scanner.y"
    {
  }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 402 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 406 "cpp_scanner.y"
    {
    (yyval.flag) = true;
    if ((yysemantic_stack_[(2) - (2)].intvalue) != 0)
    {
      error(yylloc, "invalid INT value");
      YYERROR;
    }
  }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 416 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 420 "cpp_scanner.y"
    {
    (yyval.flag) = true;
  }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 424 "cpp_scanner.y"
    {}
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 425 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 428 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 431 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 58:

/* Line 677 of lalr1.cc  */
#line 437 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
   }
    break;

  case 59:

/* Line 677 of lalr1.cc  */
#line 440 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 445 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Type = NameInfo::NAME_TYPE;
   }
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 449 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 452 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 455 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (1)].name);
   }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 458 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
   }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 462 "cpp_scanner.y"
    {
     (yyval.flag) = false;
   }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 465 "cpp_scanner.y"
    {
     (yyval.flag) = true;
   }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 470 "cpp_scanner.y"
    {
        (yyval.name) = NameInfo((yysemantic_stack_[(1) - (1)].ident));
      }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 474 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident));
      (yyval.name).Qualified = true;
    }
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 479 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(3) - (1)].name).Name + "::" + (yysemantic_stack_[(3) - (3)].ident));
    }
    break;



/* Line 677 of lalr1.cc  */
#line 1041 "cpp_scanner_y.cpp"
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
  const signed char CppBisonParser::yypact_ninf_ = -75;
  const short int
  CppBisonParser::yypact_[] =
  {
       -75,     5,     1,   -75,   -75,    -1,   -15,   -14,   -11,    -3,
     -75,    54,    63,   -75,   -75,   -75,    17,    45,    47,   -75,
     -75,   -75,   -75,    63,   -75,    61,   -75,   -75,   -75,   -75,
      24,    63,   -75,    44,    59,    67,    79,   -75,    46,   -75,
     -75,    59,    26,   -75,   -75,   -75,   -75,   -75,   -75,    55,
      16,    48,    68,    82,    94,    72,    74,    80,   -75,    49,
     -75,    63,   -75,   -75,    83,   -75,    77,   -75,    85,    86,
      63,   -75,    81,    88,   -75,   109,    82,   -75,   -75,   -75,
      14,    67,   -75,   -75,   -75,   100,    87,    63,   -75,   -75,
      67,   108,   103,   -75,   -75,   107,   -75,   -75,   105,   -75,
      13,   -75,   -75,   -75,    97,   110,   104,   -75,   -75,   -75,
     120,   114,    65,   -75,   115,   -75,   136,   -75,   111,   -75
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  CppBisonParser::yydefact_[] =
  {
         3,     0,     0,     1,     7,     0,     0,     0,     0,     0,
      53,     0,     0,     4,     5,     6,    14,     0,     0,    13,
      10,    11,    12,     0,     3,     0,    27,    28,    29,    30,
       0,     0,    67,     0,     0,    60,     0,    39,    21,    17,
      19,     0,     0,     3,    68,    64,    40,    61,    62,     0,
       0,     0,     0,    52,     0,     0,     0,     0,     9,     0,
      63,    54,    69,    38,    22,    23,     0,    15,     0,     0,
      54,     8,     0,    55,    56,    58,    52,    36,    35,    37,
       0,    25,    31,    18,    20,     0,     0,     0,    59,    24,
      26,    52,    65,    42,    57,     0,    33,    34,     0,    66,
      50,    16,    32,    43,     0,     0,     0,    51,    41,    45,
      44,     0,     0,    49,     0,    48,     0,    46,     0,    47
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yypgoto_[] =
  {
       -75,   -75,   -18,   -75,    51,    52,   -75,   -75,   -75,   -75,
     -75,   -75,    69,   133,   -75,   -75,   -75,    56,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -29,    76,   -75,
     -74,    84,   -75,   -34
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  CppBisonParser::yydefgoto_[] =
  {
        -1,     1,     2,    13,    14,    15,    38,    82,    55,    56,
      54,    64,    65,    16,    17,    18,    91,    80,    19,    20,
      21,    22,   106,   110,   118,   114,   105,    23,    72,    73,
      74,    75,   100,    35
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char CppBisonParser::yytable_ninf_ = -53;
  const signed char
  CppBisonParser::yytable_[] =
  {
        50,    -2,     4,    24,     5,     3,    42,    57,   -52,     6,
       7,     8,     9,    94,    26,    27,    10,   103,    28,    11,
      12,    30,    51,   -52,    66,    59,    29,     4,    25,     5,
     -52,    58,    81,   -52,     6,     7,     8,     9,   115,    61,
     104,    10,    37,    32,    11,    12,    90,    66,   -52,    39,
       4,    40,     5,    44,    71,   -52,   -52,     6,     7,     8,
       9,    30,     6,     7,    10,    43,    30,    11,    12,    46,
      30,   -52,    30,    51,    53,    60,    31,    62,   -52,    47,
      48,    49,   113,    32,    30,    31,    51,    31,    32,    77,
      78,    79,    32,    63,    32,    34,    36,    10,    67,    47,
      48,    49,    68,    70,    69,    86,    32,    41,    52,    76,
      83,    84,    93,    95,    87,    45,     6,     7,     8,     9,
      77,    78,    79,    10,    92,    99,    11,    12,   107,    47,
      48,    49,   101,   102,   109,   108,   111,   112,    88,   116,
     117,   119,    96,    97,    33,    89,    85,    98
  };

  /* YYCHECK.  */
  const unsigned char
  CppBisonParser::yycheck_[] =
  {
        34,     0,     1,     4,     3,     0,    24,    41,     7,     8,
       9,    10,    11,    87,    29,    29,    15,     4,    29,    18,
      19,     7,     6,    22,    53,    43,    29,     1,    29,     3,
      29,     5,    66,     7,     8,     9,    10,    11,   112,    23,
      27,    15,    25,    29,    18,    19,    80,    76,    22,     4,
       1,     4,     3,    29,     5,    29,     7,     8,     9,    10,
      11,     7,     8,     9,    15,     4,     7,    18,    19,    25,
       7,    22,     7,     6,    28,    20,    22,    29,    29,    20,
      21,    22,    17,    29,     7,    22,     6,    22,    29,    12,
      13,    14,    29,    25,    29,    11,    12,    15,     4,    20,
      21,    22,    30,    23,    30,    24,    29,    23,    29,    26,
      25,    25,    25,     5,    26,    31,     8,     9,    10,    11,
      12,    13,    14,    15,    24,    22,    18,    19,    31,    20,
      21,    22,    25,    28,    30,    25,    16,    23,    29,    24,
       4,    30,    91,    91,    11,    76,    70,    91
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CppBisonParser::yystos_[] =
  {
         0,    33,    34,     0,     1,     3,     8,     9,    10,    11,
      15,    18,    19,    35,    36,    37,    45,    46,    47,    50,
      51,    52,    53,    59,     4,    29,    29,    29,    29,    29,
       7,    22,    29,    45,    63,    65,    63,    25,    38,     4,
       4,    63,    34,     4,    29,    63,    25,    20,    21,    22,
      65,     6,    29,    28,    42,    40,    41,    65,     5,    34,
      20,    23,    29,    25,    43,    44,    59,     4,    30,    30,
      23,     5,    60,    61,    62,    63,    26,    12,    13,    14,
      49,    65,    39,    25,    25,    60,    24,    26,    29,    44,
      65,    48,    24,    25,    62,     5,    36,    37,    49,    22,
      64,    25,    28,     4,    27,    58,    54,    31,    25,    30,
      55,    16,    23,    17,    57,    62,    24,     4,    56,    30
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  CppBisonParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   123,   125,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
      42,    38,   273,    40,    41,    59,    44,    61,    58,   274,
     275,   276
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CppBisonParser::yyr1_[] =
  {
         0,    32,    33,    34,    34,    34,    34,    34,    35,    35,
      36,    36,    36,    36,    38,    39,    37,    40,    37,    41,
      37,    42,    42,    43,    43,    44,    44,    45,    45,    46,
      47,    48,    48,    48,    48,    49,    49,    49,    50,    51,
      51,    52,    52,    54,    53,    55,    56,    55,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CppBisonParser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     2,     2,     2,     5,     4,
       1,     1,     1,     1,     0,     0,     8,     0,     5,     0,
       5,     0,     2,     1,     3,     2,     3,     2,     2,     2,
       2,     0,     3,     2,     2,     1,     1,     1,     4,     2,
       3,     9,     7,     0,    11,     0,     0,     8,     1,     1,
       0,     2,     0,     1,     0,     1,     1,     3,     1,     2,
       1,     2,     2,     3,     2,     0,     1,     1,     2,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const CppBisonParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NAMESPACE", "'{'", "'}'", "QUALIFIER",
  "UNQUALIFIER", "CLASS", "STRUCT", "ENUM", "UNION", "PRIVATE", "PUBLIC",
  "PROTECTED", "VIRTUAL", "CATCH", "THREEDOT", "FRIEND", "TYPEDEF", "'*'",
  "'&'", "CONST", "'('", "')'", "';'", "','", "'='", "':'", "IDENT",
  "FUNCTION_BODY", "INTVALUE", "$accept", "program", "declaration_list",
  "namespace_declaration", "name_declaration", "class_definition", "$@1",
  "$@2", "$@3", "$@4", "class_inheritance", "inheritance_list",
  "inheritance_name", "class_name", "enum_name", "union_name",
  "class_body", "access_qualifier", "typedef_declaration",
  "forward_declaration", "function_declaration", "function_definition",
  "$@5", "catchlist", "$@6", "catch_parameter", "abstractqualifier",
  "virtualqualifier", "parameter_list", "nonempty_parameter_list",
  "parameter", "type", "constqualifier", "qualified_name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CppBisonParser::rhs_number_type
  CppBisonParser::yyrhs_[] =
  {
        33,     0,    -1,    34,    -1,    -1,    34,    35,    -1,    34,
      36,    -1,    34,    37,    -1,    34,     1,    -1,     3,    29,
       4,    34,     5,    -1,     3,     4,    34,     5,    -1,    51,
      -1,    52,    -1,    53,    -1,    50,    -1,    -1,    -1,    45,
      38,    42,     4,    39,    48,     5,    25,    -1,    -1,    46,
       4,    40,    30,    25,    -1,    -1,    47,     4,    41,    30,
      25,    -1,    -1,    28,    43,    -1,    44,    -1,    43,    26,
      44,    -1,    59,    65,    -1,    59,    49,    65,    -1,     8,
      29,    -1,     9,    29,    -1,    10,    29,    -1,    11,    29,
      -1,    -1,    48,    49,    28,    -1,    48,    36,    -1,    48,
      37,    -1,    13,    -1,    12,    -1,    14,    -1,    19,    63,
      29,    25,    -1,    45,    25,    -1,    18,    45,    25,    -1,
      59,    63,    65,    23,    60,    24,    64,    58,    25,    -1,
      18,    63,    65,    23,    60,    24,    25,    -1,    -1,    59,
      63,    65,    23,    60,    24,    64,     4,    54,    30,    55,
      -1,    -1,    -1,    55,    16,    23,    57,    24,     4,    56,
      30,    -1,    62,    -1,    17,    -1,    -1,    27,    31,    -1,
      -1,    15,    -1,    -1,    61,    -1,    62,    -1,    61,    26,
      62,    -1,    63,    -1,    63,    29,    -1,    65,    -1,    63,
      20,    -1,    63,    21,    -1,    63,    22,    20,    -1,    22,
      63,    -1,    -1,    22,    -1,    29,    -1,     7,    29,    -1,
      65,     6,    29,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  CppBisonParser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    12,    15,    18,    24,
      29,    31,    33,    35,    37,    38,    39,    48,    49,    55,
      56,    62,    63,    66,    68,    72,    75,    79,    82,    85,
      88,    91,    92,    96,    99,   102,   104,   106,   108,   113,
     116,   120,   130,   138,   139,   151,   152,   153,   162,   164,
     166,   167,   170,   171,   173,   174,   176,   178,   182,   184,
     187,   189,   192,   195,   199,   202,   203,   205,   207,   210
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CppBisonParser::yyrline_[] =
  {
         0,   186,   186,   191,   192,   196,   200,   204,   210,   215,
     223,   224,   225,   226,   230,   234,   229,   245,   244,   253,
     252,   263,   265,   271,   275,   282,   289,   299,   302,   309,
     314,   318,   319,   323,   328,   335,   336,   337,   340,   348,
     351,   358,   366,   376,   375,   388,   390,   389,   398,   399,
     402,   405,   416,   419,   424,   425,   428,   431,   437,   440,
     445,   449,   452,   455,   458,   462,   465,   470,   474,   479
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
       2,     2,     2,     2,     2,     2,     2,     2,    21,     2,
      23,    24,    20,     2,    26,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    28,    25,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
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
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    22,    29,    30,    31
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CppBisonParser::yyeof_ = 0;
  const int CppBisonParser::yylast_ = 147;
  const int CppBisonParser::yynnts_ = 34;
  const int CppBisonParser::yyempty_ = -2;
  const int CppBisonParser::yyfinal_ = 3;
  const int CppBisonParser::yyterror_ = 1;
  const int CppBisonParser::yyerrcode_ = 256;
  const int CppBisonParser::yyntokens_ = 32;

  const unsigned int CppBisonParser::yyuser_token_number_max_ = 276;
  const CppBisonParser::token_number_type CppBisonParser::yyundef_token_ = 2;


/* Line 1053 of lalr1.cc  */
#line 6 "cpp_scanner.y"
} // CppNames

/* Line 1053 of lalr1.cc  */
#line 1575 "cpp_scanner_y.cpp"


/* Line 1055 of lalr1.cc  */
#line 485 "cpp_scanner.y"


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

