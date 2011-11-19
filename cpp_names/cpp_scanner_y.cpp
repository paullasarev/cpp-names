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
#line 246 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(5) - (5)].name));
    }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 250 "cpp_scanner.y"
    {
      (yysemantic_stack_[(8) - (5)].name).Parents = (yysemantic_stack_[(8) - (7)].list);
      (yysemantic_stack_[(8) - (5)].name).IsTemplate = true;
    }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 255 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(12) - (10)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(12) - (5)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(12) - (5)].name));
      context.scopes.PopScope();
    }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 262 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 266 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 270 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 274 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 281 "cpp_scanner.y"
    {
    }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 284 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(2) - (2)].list);
    }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 290 "cpp_scanner.y"
    {
      (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 294 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
      (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
    }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 301 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
      (yyval.name).Access = context.scopes.ScopeAccess();
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(2) - (1)].flag);
    }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 308 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (3)].name);
      (yyval.name).Access = (yysemantic_stack_[(3) - (2)].access);
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(3) - (1)].flag);
    }
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 317 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_CLASS);
  }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 320 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_STRUCT);
    (yyval.name).Access = NameInfo::ACCESS_PUBLIC;
  }
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 327 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_ENUM);
  }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 332 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_UNION);
  }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 336 "cpp_scanner.y"
    {}
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 337 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    context.scopes.SetAccess((yysemantic_stack_[(3) - (2)].access));
  }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 341 "cpp_scanner.y"
    {
    (yysemantic_stack_[(2) - (2)].name).Access = context.scopes.ScopeAccess();
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 346 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 353 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PUBLIC; }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 354 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PRIVATE; }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 355 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PROTECTED; }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 359 "cpp_scanner.y"
    {
     (yyval.name) = NameInfo((yysemantic_stack_[(4) - (3)].ident), NameInfo::NAME_TYPE);
     (yyval.name).Alias = (yysemantic_stack_[(4) - (2)].name).Name;

  }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 366 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
  }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 369 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(3) - (2)].name);
    (yyval.name).IsFriend = true;
  }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 377 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(9) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(9) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(9) - (1)].flag);
    (yyval.name).IsAbstract = (yysemantic_stack_[(9) - (8)].flag);
  }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 385 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsFriend = true;
  }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 394 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 398 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(11) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(11) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(11) - (1)].flag);
  }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 406 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 410 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(14) - (6)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(14) - (10)].flag);
    (yyval.name).IsTemplate = true;
  }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 418 "cpp_scanner.y"
    {}
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 420 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 424 "cpp_scanner.y"
    {
  }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 432 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 436 "cpp_scanner.y"
    {
    (yyval.flag) = true;
    if ((yysemantic_stack_[(2) - (2)].intvalue) != 0)
    {
      error(yylloc, "invalid INT value");
      YYERROR;
    }
  }
    break;

  case 57:

/* Line 677 of lalr1.cc  */
#line 446 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 58:

/* Line 677 of lalr1.cc  */
#line 450 "cpp_scanner.y"
    {
    (yyval.flag) = true;
  }
    break;

  case 59:

/* Line 677 of lalr1.cc  */
#line 454 "cpp_scanner.y"
    {}
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 455 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 458 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 461 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 469 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 473 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 477 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(4) - (2)].ident);
  }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 481 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 485 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(4) - (2)].ident);
  }
    break;

  case 68:

/* Line 677 of lalr1.cc  */
#line 491 "cpp_scanner.y"
    {}
    break;

  case 69:

/* Line 677 of lalr1.cc  */
#line 492 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 495 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 498 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 504 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
   }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 507 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 512 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Type = NameInfo::NAME_TYPE;
   }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 516 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 519 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 522 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (1)].name);
   }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 525 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
   }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 529 "cpp_scanner.y"
    {
     (yyval.flag) = false;
   }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 532 "cpp_scanner.y"
    {
     (yyval.flag) = true;
   }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 537 "cpp_scanner.y"
    {
        (yyval.name) = NameInfo((yysemantic_stack_[(1) - (1)].ident));
      }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 541 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident));
      (yyval.name).Qualified = true;
    }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 546 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(3) - (1)].name).Name + "::" + (yysemantic_stack_[(3) - (3)].ident));
    }
    break;



/* Line 677 of lalr1.cc  */
#line 1171 "cpp_scanner_y.cpp"
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
  const signed char CppBisonParser::yypact_ninf_ = -101;
  const short int
  CppBisonParser::yypact_[] =
  {
      -101,     6,    25,  -101,  -101,     5,   -26,   -21,   -19,   -18,
    -101,   100,    24,   -12,  -101,  -101,  -101,    -7,    19,    48,
    -101,  -101,  -101,  -101,    24,  -101,    50,  -101,  -101,  -101,
    -101,    35,    24,  -101,    55,    93,    82,   148,   104,  -101,
      42,  -101,  -101,    93,    66,  -101,  -101,  -101,  -101,  -101,
    -101,    70,    45,    65,    87,    85,    89,    91,    99,  -101,
     151,   116,   126,    98,   101,    77,  -101,    86,  -101,    24,
    -101,  -101,   105,   107,   100,   104,  -101,   111,  -101,     4,
    -101,   122,   123,    24,  -101,   129,   128,  -101,   154,    24,
      24,  -101,    93,  -101,   116,  -101,  -101,  -101,    17,    82,
    -101,  -101,  -101,   139,   152,    24,  -101,    38,    38,    42,
     115,  -101,    82,   133,   142,  -101,  -101,   176,    24,   155,
    -101,  -101,   153,  -101,    26,  -101,   159,  -101,  -101,  -101,
     156,   161,  -101,   142,   158,  -101,  -101,   149,   182,  -101,
     162,  -101,   174,  -101,   160,   168,  -101,    96,   174,  -101,
     169,  -101,   192,  -101,   163,  -101
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  CppBisonParser::yydefact_[] =
  {
         3,     0,     0,     1,     7,     0,     0,     0,     0,     0,
      58,     0,     0,     0,     4,     5,     6,    14,     0,     0,
      13,    10,    11,    12,     0,     3,     0,    30,    31,    32,
      33,     0,     0,    81,     0,     0,    74,     0,    59,    42,
      24,    20,    22,     0,     0,     3,    82,    78,    43,    75,
      76,     0,     0,     0,     0,     0,     0,     0,    60,    61,
       0,    57,     0,     0,     0,     0,     9,     0,    77,    68,
      83,    41,    64,    66,     0,     0,    63,    25,    26,     0,
      15,     0,     0,    68,     8,     0,    69,    70,    72,     0,
       0,    17,     0,    62,    57,    39,    38,    40,     0,    28,
      34,    21,    23,     0,     0,     0,    73,    65,    67,    24,
       0,    27,    29,    57,    79,    45,    71,     0,    68,     0,
      36,    37,     0,    80,    55,    18,     0,    16,    35,    46,
       0,     0,    34,    79,     0,    56,    44,    57,     0,    50,
       0,    48,    47,    19,     0,     0,    50,     0,    49,    54,
       0,    53,     0,    51,     0,    52
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yypgoto_[] =
  {
      -101,  -101,    -3,  -101,   -84,   -57,  -101,  -101,  -101,  -101,
    -101,  -101,    90,  -101,   106,    -8,  -101,  -101,    69,   119,
    -101,  -101,  -101,  -101,  -101,  -101,    56,  -101,  -101,  -101,
     -53,  -101,  -101,   130,   -79,  -101,  -100,   -11,    71,   -33
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yydefgoto_[] =
  {
        -1,     1,     2,    14,    15,    16,    40,   100,   109,   132,
      63,    64,    62,    77,    78,    17,    18,    19,   113,   122,
      20,    21,    22,    23,   134,   144,   142,   154,   150,   131,
      24,    57,    58,    59,    85,    86,    87,    88,   124,    36
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char CppBisonParser::yytable_ninf_ = -58;
  const short int
  CppBisonParser::yytable_[] =
  {
        35,    37,    52,    34,   103,   116,     3,    27,    79,    25,
      65,    31,    28,    43,    29,    30,    95,    96,    97,    38,
      39,    47,    44,    41,    31,    -2,     4,    60,     5,   120,
     129,    31,   -57,     6,     7,     8,     9,    33,    26,   126,
      10,    79,    67,    11,    12,    13,    99,   151,    32,   -57,
      33,    53,    42,   120,    45,   130,   121,    33,   -57,   110,
      49,    50,    51,    92,    60,   112,    91,     4,    46,     5,
      69,    66,    61,   -57,     6,     7,     8,     9,   107,   108,
     121,    10,    48,    53,    11,    12,    13,     4,    53,     5,
     -57,    84,    68,   -57,     6,     7,     8,     9,    70,   -57,
      31,    10,    83,    31,    11,    12,    13,    31,     6,     7,
     -57,    31,    55,   149,    71,    49,    50,    51,    72,   -57,
      32,    53,    73,    74,    32,    56,    33,    75,    32,    33,
      80,    10,    81,    33,    89,    82,    90,    33,   119,    94,
     118,     6,     7,     8,     9,    95,    96,    97,    10,   101,
     102,    11,    12,    13,   140,   104,   105,     6,     7,     8,
       9,    95,    96,    97,    10,   114,   123,    11,    12,    13,
      49,    50,    51,    49,    50,    51,    49,    50,    51,   115,
     125,    54,   127,   128,    76,   133,   141,   106,   136,   143,
     145,   135,   139,   147,   146,   152,   153,   155,    98,   117,
     111,   137,   148,     0,   138,    93
  };

  /* YYCHECK.  */
  const short int
  CppBisonParser::yycheck_[] =
  {
        11,    12,    35,    11,    83,   105,     0,    33,    61,     4,
      43,     7,    33,    24,    33,    33,    12,    13,    14,    31,
      27,    32,    25,     4,     7,     0,     1,    38,     3,   113,
       4,     7,     7,     8,     9,    10,    11,    33,    33,   118,
      15,    94,    45,    18,    19,    20,    79,   147,    24,    24,
      33,     6,     4,   137,     4,    29,   113,    33,    33,    92,
      22,    23,    24,    74,    75,    98,    74,     1,    33,     3,
      25,     5,    30,     7,     8,     9,    10,    11,    89,    90,
     137,    15,    27,     6,    18,    19,    20,     1,     6,     3,
      24,     5,    22,     7,     8,     9,    10,    11,    33,    33,
       7,    15,    25,     7,    18,    19,    20,     7,     8,     9,
      24,     7,     8,    17,    27,    22,    23,    24,    33,    33,
      24,     6,    33,    32,    24,    21,    33,    28,    24,    33,
       4,    15,    34,    33,    29,    34,    29,    33,     5,    28,
      25,     8,     9,    10,    11,    12,    13,    14,    15,    27,
      27,    18,    19,    20,     5,    26,    28,     8,     9,    10,
      11,    12,    13,    14,    15,    26,    24,    18,    19,    20,
      22,    23,    24,    22,    23,    24,    22,    23,    24,    27,
       4,    33,    27,    30,    33,    26,     4,    33,    27,    27,
      16,    35,    34,    25,    34,    26,     4,    34,    79,   109,
      94,   132,   146,    -1,   133,    75
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CppBisonParser::yystos_[] =
  {
         0,    37,    38,     0,     1,     3,     8,     9,    10,    11,
      15,    18,    19,    20,    39,    40,    41,    51,    52,    53,
      56,    57,    58,    59,    66,     4,    33,    33,    33,    33,
      33,     7,    24,    33,    51,    73,    75,    73,    31,    27,
      42,     4,     4,    73,    38,     4,    33,    73,    27,    22,
      23,    24,    75,     6,    33,     8,    21,    67,    68,    69,
      73,    30,    48,    46,    47,    75,     5,    38,    22,    25,
      33,    27,    33,    33,    32,    28,    33,    49,    50,    66,
       4,    34,    34,    25,     5,    70,    71,    72,    73,    29,
      29,    51,    73,    69,    28,    12,    13,    14,    55,    75,
      43,    27,    27,    70,    26,    28,    33,    73,    73,    44,
      75,    50,    75,    54,    26,    27,    72,    48,    25,     5,
      40,    41,    55,    24,    74,     4,    70,    27,    30,     4,
      29,    65,    45,    26,    60,    35,    27,    54,    74,    34,
       5,     4,    62,    27,    61,    16,    34,    25,    62,    17,
      64,    72,    26,     4,    63,    34
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
      58,    60,    62,   276,   277,   278
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CppBisonParser::yyr1_[] =
  {
         0,    36,    37,    38,    38,    38,    38,    38,    39,    39,
      40,    40,    40,    40,    42,    43,    41,    44,    45,    41,
      46,    41,    47,    41,    48,    48,    49,    49,    50,    50,
      51,    51,    52,    53,    54,    54,    54,    54,    55,    55,
      55,    56,    57,    57,    58,    58,    60,    59,    61,    59,
      62,    63,    62,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    75
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CppBisonParser::yyr2_[] =
  {
         0,     2,     1,     0,     2,     2,     2,     2,     5,     4,
       1,     1,     1,     1,     0,     0,     8,     0,     0,    12,
       0,     5,     0,     5,     0,     2,     1,     3,     2,     3,
       2,     2,     2,     2,     0,     3,     2,     2,     1,     1,
       1,     4,     2,     3,     9,     7,     0,    11,     0,    14,
       0,     0,     8,     1,     1,     0,     2,     0,     1,     0,
       1,     1,     3,     2,     2,     4,     2,     4,     0,     1,
       1,     3,     1,     2,     1,     2,     2,     3,     2,     0,
       1,     1,     2,     3
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
  "','", "'='", "':'", "'<'", "'>'", "IDENT", "FUNCTION_BODY", "INTVALUE",
  "$accept", "program", "declaration_list", "namespace_declaration",
  "name_declaration", "class_definition", "$@1", "$@2", "$@3", "$@4",
  "$@5", "$@6", "class_inheritance", "inheritance_list",
  "inheritance_name", "class_name", "enum_name", "union_name",
  "class_body", "access_qualifier", "typedef_declaration",
  "forward_declaration", "function_declaration", "function_definition",
  "$@7", "$@8", "catchlist", "$@9", "catch_parameter", "abstractqualifier",
  "virtualqualifier", "template_parameter_list",
  "nonempty_template_parameter_list", "template_parameter",
  "parameter_list", "nonempty_parameter_list", "parameter", "type",
  "constqualifier", "qualified_name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CppBisonParser::rhs_number_type
  CppBisonParser::yyrhs_[] =
  {
        37,     0,    -1,    38,    -1,    -1,    38,    39,    -1,    38,
      40,    -1,    38,    41,    -1,    38,     1,    -1,     3,    33,
       4,    38,     5,    -1,     3,     4,    38,     5,    -1,    57,
      -1,    58,    -1,    59,    -1,    56,    -1,    -1,    -1,    51,
      42,    48,     4,    43,    54,     5,    27,    -1,    -1,    -1,
      20,    31,    67,    32,    51,    44,    48,     4,    45,    54,
       5,    27,    -1,    -1,    52,     4,    46,    34,    27,    -1,
      -1,    53,     4,    47,    34,    27,    -1,    -1,    30,    49,
      -1,    50,    -1,    49,    28,    50,    -1,    66,    75,    -1,
      66,    55,    75,    -1,     8,    33,    -1,     9,    33,    -1,
      10,    33,    -1,    11,    33,    -1,    -1,    54,    55,    30,
      -1,    54,    40,    -1,    54,    41,    -1,    13,    -1,    12,
      -1,    14,    -1,    19,    73,    33,    27,    -1,    51,    27,
      -1,    18,    51,    27,    -1,    66,    73,    75,    25,    70,
      26,    74,    65,    27,    -1,    18,    73,    75,    25,    70,
      26,    27,    -1,    -1,    66,    73,    75,    25,    70,    26,
      74,     4,    60,    34,    62,    -1,    -1,    20,    31,    67,
      32,    73,    75,    25,    70,    26,    74,     4,    61,    34,
      62,    -1,    -1,    -1,    62,    16,    25,    64,    26,     4,
      63,    34,    -1,    72,    -1,    17,    -1,    -1,    29,    35,
      -1,    -1,    15,    -1,    -1,    68,    -1,    69,    -1,    68,
      28,    69,    -1,    73,    33,    -1,     8,    33,    -1,     8,
      33,    29,    73,    -1,    21,    33,    -1,    21,    33,    29,
      73,    -1,    -1,    71,    -1,    72,    -1,    71,    28,    72,
      -1,    73,    -1,    73,    33,    -1,    75,    -1,    73,    22,
      -1,    73,    23,    -1,    73,    24,    22,    -1,    24,    73,
      -1,    -1,    24,    -1,    33,    -1,     7,    33,    -1,    75,
       6,    33,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  CppBisonParser::yyprhs_[] =
  {
         0,     0,     3,     5,     6,     9,    12,    15,    18,    24,
      29,    31,    33,    35,    37,    38,    39,    48,    49,    50,
      63,    64,    70,    71,    77,    78,    81,    83,    87,    90,
      94,    97,   100,   103,   106,   107,   111,   114,   117,   119,
     121,   123,   128,   131,   135,   145,   153,   154,   166,   167,
     182,   183,   184,   193,   195,   197,   198,   201,   202,   204,
     205,   207,   209,   213,   216,   219,   224,   227,   232,   233,
     235,   237,   241,   243,   246,   248,   251,   254,   258,   261,
     262,   264,   266,   269
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CppBisonParser::yyrline_[] =
  {
         0,   186,   186,   191,   192,   196,   200,   204,   210,   215,
     223,   224,   225,   226,   230,   234,   229,   246,   250,   244,
     262,   261,   270,   269,   281,   283,   289,   293,   300,   307,
     317,   320,   327,   332,   336,   337,   341,   346,   353,   354,
     355,   358,   366,   369,   376,   384,   394,   393,   406,   404,
     418,   420,   419,   428,   429,   432,   435,   446,   449,   454,
     455,   458,   461,   468,   472,   476,   480,   484,   491,   492,
     495,   498,   504,   507,   512,   516,   519,   522,   525,   529,
     532,   537,   541,   546
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
      17,    18,    19,    20,    21,    24,    33,    34,    35
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CppBisonParser::yyeof_ = 0;
  const int CppBisonParser::yylast_ = 205;
  const int CppBisonParser::yynnts_ = 40;
  const int CppBisonParser::yyempty_ = -2;
  const int CppBisonParser::yyfinal_ = 3;
  const int CppBisonParser::yyterror_ = 1;
  const int CppBisonParser::yyerrcode_ = 256;
  const int CppBisonParser::yyntokens_ = 36;

  const unsigned int CppBisonParser::yyuser_token_number_max_ = 278;
  const CppBisonParser::token_number_type CppBisonParser::yyundef_token_ = 2;


/* Line 1053 of lalr1.cc  */
#line 6 "cpp_scanner.y"
} // CppNames

/* Line 1053 of lalr1.cc  */
#line 1746 "cpp_scanner_y.cpp"


/* Line 1055 of lalr1.cc  */
#line 552 "cpp_scanner.y"


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

