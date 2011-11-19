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
#line 185 "cpp_scanner.y"
    {
		for_each((yysemantic_stack_[(1) - (1)].list).begin(), (yysemantic_stack_[(1) - (1)].list).end(), AddName(context.names));
	}
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 191 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(5) - (4)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(5) - (2)].ident)));
		(yyval.list).push_back(NameInfo((yysemantic_stack_[(5) - (2)].ident), NameInfo::NAME_NAMESPACE));
	}
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 196 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(4) - (3)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace("anonymous"));
		(yyval.list).push_back(NameInfo("anonymous", NameInfo::NAME_NAMESPACE));
	}
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 203 "cpp_scanner.y"
    { }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 204 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 208 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 212 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 12:

/* Line 677 of lalr1.cc  */
#line 225 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 13:

/* Line 677 of lalr1.cc  */
#line 229 "cpp_scanner.y"
    {
      (yysemantic_stack_[(4) - (1)].name).Parents = (yysemantic_stack_[(4) - (3)].list);
    }
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 233 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(8) - (6)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(8) - (1)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(8) - (1)].name));
      context.scopes.PopScope();
    }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 240 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 244 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 248 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 252 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 258 "cpp_scanner.y"
    {
    }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 261 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(2) - (2)].list);
    }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 267 "cpp_scanner.y"
    {
      (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 271 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
      (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
    }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 278 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Access = context.scopes.ScopeAccess();
      (yyval.name).Type = NameInfo::NAME_CLASS;
    }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 284 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
      (yyval.name).Access = (yysemantic_stack_[(2) - (1)].access);
      (yyval.name).Type = NameInfo::NAME_CLASS;
    }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 292 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_CLASS);
  }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 295 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_STRUCT);
    (yyval.name).Access = NameInfo::ACCESS_PUBLIC;
  }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 302 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_ENUM);
  }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 307 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_UNION);
  }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 311 "cpp_scanner.y"
    {}
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 312 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    context.scopes.SetAccess((yysemantic_stack_[(3) - (2)].access));
  }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 316 "cpp_scanner.y"
    {
    (yysemantic_stack_[(2) - (2)].name).Access = context.scopes.ScopeAccess();
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 321 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 328 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PUBLIC; }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 329 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PRIVATE; }
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 330 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PROTECTED; }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 333 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
  }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 339 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (2)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(7) - (6)].flag);
  }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 347 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 350 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(9) - (2)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(9) - (6)].flag);
  }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 357 "cpp_scanner.y"
    {}
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 358 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 361 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 364 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 370 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
   }
    break;

  case 45:

/* Line 677 of lalr1.cc  */
#line 373 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 378 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Type = NameInfo::NAME_TYPE;
   }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 382 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 385 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 388 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (1)].name);
   }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 391 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
   }
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 395 "cpp_scanner.y"
    {
     (yyval.flag) = false;
   }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 398 "cpp_scanner.y"
    {
     (yyval.flag) = true;
   }
    break;

  case 53:

/* Line 677 of lalr1.cc  */
#line 403 "cpp_scanner.y"
    {
        (yyval.name) = NameInfo((yysemantic_stack_[(1) - (1)].ident));
      }
    break;

  case 54:

/* Line 677 of lalr1.cc  */
#line 407 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident));
      (yyval.name).Qualified = true;
    }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 412 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(3) - (1)].name).Name + "::" + (yysemantic_stack_[(3) - (3)].ident));
    }
    break;



/* Line 677 of lalr1.cc  */
#line 930 "cpp_scanner_y.cpp"
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
  const signed char CppBisonParser::yypact_ninf_ = -22;
  const signed char
  CppBisonParser::yypact_[] =
  {
       -22,    11,    21,   -22,     1,   -21,   -12,     9,    18,    19,
      50,   -22,   -22,   -22,   -22,    -6,    31,    69,   -22,   -22,
     -22,    53,    70,   -22,    75,   -22,   -22,   -22,   -22,   -22,
     -22,   -22,    57,   -22,   -22,   -22,   -22,    68,    66,    58,
      -1,   -22,    51,    77,    60,    61,   -22,    50,   -22,   -22,
      10,   -22,   -22,   -22,    71,   -22,    54,    70,   -22,    73,
      74,    72,    76,   -22,    24,   -22,    51,    70,   -22,   -22,
     -22,    78,    50,   -22,   -22,    42,   -22,    67,   -22,    79,
     -22,   -22,    65,   -22,   -22,   -22,   -22,    64,   -22
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  CppBisonParser::yydefact_[] =
  {
         5,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,    53,     6,     7,     8,    12,     0,     0,     9,    10,
      11,     0,    46,     5,     0,    54,    25,    26,    27,    28,
      50,    36,    19,    15,    17,    47,    48,     0,     0,     0,
       0,     5,     0,     0,     0,     0,    49,    40,    55,     4,
       0,    34,    33,    35,    20,    21,     0,    23,    13,     0,
       0,     0,    41,    42,    44,     3,     0,    24,    29,    16,
      18,    51,     0,    45,    22,     0,    52,     0,    43,     0,
      31,    32,     0,    38,    37,    14,    30,     0,    39
  };

  /* YYPGOTO[NTERM-NUM].  */
  const signed char
  CppBisonParser::yypgoto_[] =
  {
       -22,   -22,   -22,     3,    15,    23,   -22,   -22,   -22,   -22,
     -22,   -22,    30,   -22,   -22,   -22,   -22,    25,   -22,   -22,
     -22,   -22,   -22,   -22,    29,   -10,   -22,   -20
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  CppBisonParser::yydefgoto_[] =
  {
        -1,     1,    12,     2,    13,    14,    32,    68,    44,    45,
      43,    54,    55,    15,    16,    17,    75,    56,    18,    19,
      20,    87,    61,    62,    63,    21,    77,    22
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char CppBisonParser::yytable_ninf_ = -1;
  const unsigned char
  CppBisonParser::yytable_[] =
  {
        30,    38,     4,    25,    49,    23,     5,     6,     7,     8,
       9,     3,    26,     4,    31,    65,    10,     5,     6,     7,
       8,     9,    57,    11,     4,    24,    40,    10,     5,     6,
       7,     8,     9,    27,    11,    33,    67,    64,    10,    35,
      36,    37,    28,    29,    50,    11,    57,    79,    73,     5,
       6,     7,     8,     9,    51,    52,    53,     5,     5,    10,
       5,     5,    64,    51,    52,    53,    11,    10,    35,    36,
      37,    83,    39,    34,    11,    11,    39,    11,    11,    41,
      42,    58,    48,    46,    47,    59,    60,    84,    86,    88,
      80,    71,    66,    69,    70,    76,    74,    72,    81,    85,
      82,    78
  };

  /* YYCHECK.  */
  const unsigned char
  CppBisonParser::yycheck_[] =
  {
        10,    21,     3,    24,     5,     4,     7,     8,     9,    10,
      11,     0,    24,     3,    20,     5,    17,     7,     8,     9,
      10,    11,    42,    24,     3,    24,    23,    17,     7,     8,
       9,    10,    11,    24,    24,     4,    56,    47,    17,    15,
      16,    17,    24,    24,    41,    24,    66,     5,    24,     7,
       8,     9,    10,    11,    12,    13,    14,     7,     7,    17,
       7,     7,    72,    12,    13,    14,    24,    17,    15,    16,
      17,     4,     6,     4,    24,    24,     6,    24,    24,     4,
      23,     4,    24,    15,    18,    25,    25,    20,    23,    25,
      75,    19,    21,    20,    20,    17,    66,    21,    75,    20,
      75,    72
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CppBisonParser::yystos_[] =
  {
         0,    28,    30,     0,     3,     7,     8,     9,    10,    11,
      17,    24,    29,    31,    32,    40,    41,    42,    45,    46,
      47,    52,    54,     4,    24,    24,    24,    24,    24,    24,
      52,    20,    33,     4,     4,    15,    16,    17,    54,     6,
      30,     4,    23,    37,    35,    36,    15,    18,    24,     5,
      30,    12,    13,    14,    38,    39,    44,    54,     4,    25,
      25,    49,    50,    51,    52,     5,    21,    54,    34,    20,
      20,    19,    21,    24,    39,    43,    17,    53,    51,     5,
      31,    32,    44,     4,    20,    20,    23,    48,    25
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  CppBisonParser::yytoken_number_[] =
  {
         0,   256,   257,   258,   123,   125,   259,   260,   261,   262,
     263,   264,   265,   266,   267,    42,    38,   268,    40,    41,
      59,    44,    61,    58,   269,   270,   271
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  CppBisonParser::yyr1_[] =
  {
         0,    27,    28,    29,    29,    30,    30,    30,    30,    31,
      31,    31,    33,    34,    32,    35,    32,    36,    32,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    42,    43,
      43,    43,    43,    44,    44,    44,    45,    46,    48,    47,
      49,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    54,    54,    54
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  CppBisonParser::yyr2_[] =
  {
         0,     2,     1,     5,     4,     0,     2,     2,     2,     1,
       1,     1,     0,     0,     8,     0,     5,     0,     5,     0,
       2,     1,     3,     1,     2,     2,     2,     2,     2,     0,
       3,     2,     2,     1,     1,     1,     2,     7,     0,     9,
       0,     1,     1,     3,     1,     2,     1,     2,     2,     3,
       2,     0,     1,     1,     2,     3
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const CppBisonParser::yytname_[] =
  {
    "$end", "error", "$undefined", "NAMESPACE", "'{'", "'}'", "QUALIFIER",
  "UNQUALIFIER", "CLASS", "STRUCT", "ENUM", "UNION", "PRIVATE", "PUBLIC",
  "PROTECTED", "'*'", "'&'", "CONST", "'('", "')'", "';'", "','", "'='",
  "':'", "IDENT", "FUNCTION_BODY", "INTVALUE", "$accept", "program",
  "name_space", "declaration_list", "name_declaration", "class_definition",
  "$@1", "$@2", "$@3", "$@4", "class_inheritance", "inheritance_list",
  "inheritance_name", "class_name", "enum_name", "union_name",
  "class_body", "access_qualifier", "forward_declaration",
  "function_declaration", "function_definition", "$@5", "parameter_list",
  "nonempty_parameter_list", "parameter", "type", "constqualifier",
  "qualified_name", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const CppBisonParser::rhs_number_type
  CppBisonParser::yyrhs_[] =
  {
        28,     0,    -1,    30,    -1,     3,    24,     4,    30,     5,
      -1,     3,     4,    30,     5,    -1,    -1,    30,    29,    -1,
      30,    31,    -1,    30,    32,    -1,    45,    -1,    46,    -1,
      47,    -1,    -1,    -1,    40,    33,    37,     4,    34,    43,
       5,    20,    -1,    -1,    41,     4,    35,    25,    20,    -1,
      -1,    42,     4,    36,    25,    20,    -1,    -1,    23,    38,
      -1,    39,    -1,    38,    21,    39,    -1,    54,    -1,    44,
      54,    -1,     8,    24,    -1,     9,    24,    -1,    10,    24,
      -1,    11,    24,    -1,    -1,    43,    44,    23,    -1,    43,
      31,    -1,    43,    32,    -1,    13,    -1,    12,    -1,    14,
      -1,    40,    20,    -1,    52,    54,    18,    49,    19,    53,
      20,    -1,    -1,    52,    54,    18,    49,    19,    53,     4,
      48,    25,    -1,    -1,    50,    -1,    51,    -1,    50,    21,
      51,    -1,    52,    -1,    52,    24,    -1,    54,    -1,    52,
      15,    -1,    52,    16,    -1,    52,    17,    15,    -1,    17,
      52,    -1,    -1,    17,    -1,    24,    -1,     7,    24,    -1,
      54,     6,    24,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  CppBisonParser::yyprhs_[] =
  {
         0,     0,     3,     5,    11,    16,    17,    20,    23,    26,
      28,    30,    32,    33,    34,    43,    44,    50,    51,    57,
      58,    61,    63,    67,    69,    72,    75,    78,    81,    84,
      85,    89,    92,    95,    97,    99,   101,   104,   112,   113,
     123,   124,   126,   128,   132,   134,   137,   139,   142,   145,
     149,   152,   153,   155,   157,   160
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CppBisonParser::yyrline_[] =
  {
         0,   185,   185,   191,   196,   203,   204,   208,   212,   219,
     220,   221,   225,   229,   224,   240,   239,   248,   247,   258,
     260,   266,   270,   277,   283,   292,   295,   302,   307,   311,
     312,   316,   321,   328,   329,   330,   333,   339,   347,   347,
     357,   358,   361,   364,   370,   373,   378,   382,   385,   388,
     391,   395,   398,   403,   407,   412
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
       2,     2,     2,     2,     2,     2,     2,     2,    16,     2,
      18,    19,    15,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,    20,
       2,    22,     2,     2,     2,     2,     2,     2,     2,     2,
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
       7,     8,     9,    10,    11,    12,    13,    14,    17,    24,
      25,    26
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int CppBisonParser::yyeof_ = 0;
  const int CppBisonParser::yylast_ = 101;
  const int CppBisonParser::yynnts_ = 28;
  const int CppBisonParser::yyempty_ = -2;
  const int CppBisonParser::yyfinal_ = 3;
  const int CppBisonParser::yyterror_ = 1;
  const int CppBisonParser::yyerrcode_ = 256;
  const int CppBisonParser::yyntokens_ = 27;

  const unsigned int CppBisonParser::yyuser_token_number_max_ = 271;
  const CppBisonParser::token_number_type CppBisonParser::yyundef_token_ = 2;


/* Line 1053 of lalr1.cc  */
#line 6 "cpp_scanner.y"
} // CppNames

/* Line 1053 of lalr1.cc  */
#line 1433 "cpp_scanner_y.cpp"


/* Line 1055 of lalr1.cc  */
#line 418 "cpp_scanner.y"


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

