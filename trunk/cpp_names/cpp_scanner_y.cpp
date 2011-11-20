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
#line 127 "cpp_scanner.y"

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
#line 189 "cpp_scanner.y"
    {
		for_each((yysemantic_stack_[(1) - (1)].list).begin(), (yysemantic_stack_[(1) - (1)].list).end(), AddName(context.names));
	}
    break;

  case 3:

/* Line 677 of lalr1.cc  */
#line 194 "cpp_scanner.y"
    { }
    break;

  case 4:

/* Line 677 of lalr1.cc  */
#line 195 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 5:

/* Line 677 of lalr1.cc  */
#line 199 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 6:

/* Line 677 of lalr1.cc  */
#line 203 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 7:

/* Line 677 of lalr1.cc  */
#line 207 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
  }
    break;

  case 8:

/* Line 677 of lalr1.cc  */
#line 213 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(5) - (4)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(5) - (2)].ident)));
		(yyval.list).push_back(NameInfo((yysemantic_stack_[(5) - (2)].ident), NameInfo::NAME_NAMESPACE));
	}
    break;

  case 9:

/* Line 677 of lalr1.cc  */
#line 218 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(4) - (3)].list);
		for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace("anonymous"));
		(yyval.list).push_back(NameInfo("anonymous", NameInfo::NAME_NAMESPACE));
	}
    break;

  case 14:

/* Line 677 of lalr1.cc  */
#line 233 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 15:

/* Line 677 of lalr1.cc  */
#line 237 "cpp_scanner.y"
    {
      (yysemantic_stack_[(4) - (1)].name).Parents = (yysemantic_stack_[(4) - (3)].list);
    }
    break;

  case 16:

/* Line 677 of lalr1.cc  */
#line 241 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(8) - (6)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(8) - (1)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(8) - (1)].name));
      context.scopes.PopScope();
    }
    break;

  case 17:

/* Line 677 of lalr1.cc  */
#line 249 "cpp_scanner.y"
    {
      context.scopes.PushScope((yysemantic_stack_[(5) - (5)].name));
    }
    break;

  case 18:

/* Line 677 of lalr1.cc  */
#line 253 "cpp_scanner.y"
    {
      (yysemantic_stack_[(8) - (5)].name).Parents = (yysemantic_stack_[(8) - (7)].list);
      (yysemantic_stack_[(8) - (5)].name).IsTemplate = true;
    }
    break;

  case 19:

/* Line 677 of lalr1.cc  */
#line 258 "cpp_scanner.y"
    {
		  (yyval.list) = (yysemantic_stack_[(12) - (10)].list);
		  for_each((yyval.list).begin(), (yyval.list).end(), AddNamespace((yysemantic_stack_[(12) - (5)].name).Name));
		  (yyval.list).push_back((yysemantic_stack_[(12) - (5)].name));
      context.scopes.PopScope();
    }
    break;

  case 20:

/* Line 677 of lalr1.cc  */
#line 265 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 21:

/* Line 677 of lalr1.cc  */
#line 269 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 22:

/* Line 677 of lalr1.cc  */
#line 273 "cpp_scanner.y"
    {
      begin_function_body(scanner);
    }
    break;

  case 23:

/* Line 677 of lalr1.cc  */
#line 277 "cpp_scanner.y"
    {
 		  (yyval.list).push_back((yysemantic_stack_[(5) - (1)].name));
    }
    break;

  case 24:

/* Line 677 of lalr1.cc  */
#line 284 "cpp_scanner.y"
    {
    }
    break;

  case 25:

/* Line 677 of lalr1.cc  */
#line 287 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(2) - (2)].list);
    }
    break;

  case 26:

/* Line 677 of lalr1.cc  */
#line 293 "cpp_scanner.y"
    {
      (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
    }
    break;

  case 27:

/* Line 677 of lalr1.cc  */
#line 297 "cpp_scanner.y"
    {
      (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
      (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
    }
    break;

  case 28:

/* Line 677 of lalr1.cc  */
#line 304 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
      (yyval.name).Access = context.scopes.ScopeAccess();
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(2) - (1)].flag);
    }
    break;

  case 29:

/* Line 677 of lalr1.cc  */
#line 311 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (3)].name);
      (yyval.name).Access = (yysemantic_stack_[(3) - (2)].access);
      (yyval.name).Type = NameInfo::NAME_CLASS;
      (yyval.name).IsVirtual = (yysemantic_stack_[(3) - (1)].flag);
    }
    break;

  case 30:

/* Line 677 of lalr1.cc  */
#line 320 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_CLASS);
  }
    break;

  case 31:

/* Line 677 of lalr1.cc  */
#line 323 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_STRUCT);
    (yyval.name).Access = NameInfo::ACCESS_PUBLIC;
  }
    break;

  case 32:

/* Line 677 of lalr1.cc  */
#line 330 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_ENUM);
  }
    break;

  case 33:

/* Line 677 of lalr1.cc  */
#line 335 "cpp_scanner.y"
    {
    (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident), NameInfo::NAME_UNION);
  }
    break;

  case 34:

/* Line 677 of lalr1.cc  */
#line 339 "cpp_scanner.y"
    {}
    break;

  case 35:

/* Line 677 of lalr1.cc  */
#line 340 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    context.scopes.SetAccess((yysemantic_stack_[(3) - (2)].access));
  }
    break;

  case 36:

/* Line 677 of lalr1.cc  */
#line 344 "cpp_scanner.y"
    {
    (yysemantic_stack_[(2) - (2)].name).Access = context.scopes.ScopeAccess();
    (yyval.list) = (yysemantic_stack_[(2) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(2) - (2)].name));
  }
    break;

  case 37:

/* Line 677 of lalr1.cc  */
#line 349 "cpp_scanner.y"
    {
		(yyval.list) = (yysemantic_stack_[(2) - (1)].list);
		(yyval.list).insert((yyval.list).end(), (yysemantic_stack_[(2) - (2)].list).begin(), (yysemantic_stack_[(2) - (2)].list).end());
  }
    break;

  case 38:

/* Line 677 of lalr1.cc  */
#line 356 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PUBLIC; }
    break;

  case 39:

/* Line 677 of lalr1.cc  */
#line 357 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PRIVATE; }
    break;

  case 40:

/* Line 677 of lalr1.cc  */
#line 358 "cpp_scanner.y"
    { (yyval.access) = NameInfo::ACCESS_PROTECTED; }
    break;

  case 41:

/* Line 677 of lalr1.cc  */
#line 362 "cpp_scanner.y"
    {
     (yyval.name) = NameInfo((yysemantic_stack_[(4) - (3)].ident), NameInfo::NAME_TYPE);
     (yyval.name).Alias = (yysemantic_stack_[(4) - (2)].name).Name;

  }
    break;

  case 42:

/* Line 677 of lalr1.cc  */
#line 369 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
  }
    break;

  case 43:

/* Line 677 of lalr1.cc  */
#line 372 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(3) - (2)].name);
    (yyval.name).IsFriend = true;
  }
    break;

  case 44:

/* Line 677 of lalr1.cc  */
#line 380 "cpp_scanner.y"
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
#line 388 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(7) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsFriend = true;
  }
    break;

  case 46:

/* Line 677 of lalr1.cc  */
#line 397 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 47:

/* Line 677 of lalr1.cc  */
#line 401 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(11) - (3)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(11) - (7)].flag);
    (yyval.name).IsVirtual = (yysemantic_stack_[(11) - (1)].flag);
  }
    break;

  case 48:

/* Line 677 of lalr1.cc  */
#line 409 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 49:

/* Line 677 of lalr1.cc  */
#line 413 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(14) - (6)].name);
    (yyval.name).Type = NameInfo::NAME_FUNCTION;
    (yyval.name).IsConst = (yysemantic_stack_[(14) - (10)].flag);
    (yyval.name).IsTemplate = true;
  }
    break;

  case 50:

/* Line 677 of lalr1.cc  */
#line 421 "cpp_scanner.y"
    {}
    break;

  case 51:

/* Line 677 of lalr1.cc  */
#line 423 "cpp_scanner.y"
    {
    begin_function_body(scanner);
  }
    break;

  case 52:

/* Line 677 of lalr1.cc  */
#line 427 "cpp_scanner.y"
    {
  }
    break;

  case 55:

/* Line 677 of lalr1.cc  */
#line 435 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 56:

/* Line 677 of lalr1.cc  */
#line 439 "cpp_scanner.y"
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
#line 449 "cpp_scanner.y"
    {
    (yyval.flag) = false;
  }
    break;

  case 58:

/* Line 677 of lalr1.cc  */
#line 453 "cpp_scanner.y"
    {
    (yyval.flag) = true;
  }
    break;

  case 59:

/* Line 677 of lalr1.cc  */
#line 457 "cpp_scanner.y"
    {}
    break;

  case 60:

/* Line 677 of lalr1.cc  */
#line 458 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 61:

/* Line 677 of lalr1.cc  */
#line 461 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 62:

/* Line 677 of lalr1.cc  */
#line 464 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 63:

/* Line 677 of lalr1.cc  */
#line 472 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 64:

/* Line 677 of lalr1.cc  */
#line 476 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
  }
    break;

  case 65:

/* Line 677 of lalr1.cc  */
#line 480 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(5) - (5)].name);
  }
    break;

  case 66:

/* Line 677 of lalr1.cc  */
#line 487 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(2) - (2)].ident);
  }
    break;

  case 67:

/* Line 677 of lalr1.cc  */
#line 491 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(4) - (2)].ident);
  }
    break;

  case 70:

/* Line 677 of lalr1.cc  */
#line 499 "cpp_scanner.y"
    {}
    break;

  case 71:

/* Line 677 of lalr1.cc  */
#line 500 "cpp_scanner.y"
    {(yyval.list) = (yysemantic_stack_[(1) - (1)].list);}
    break;

  case 72:

/* Line 677 of lalr1.cc  */
#line 503 "cpp_scanner.y"
    {
    (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
  }
    break;

  case 73:

/* Line 677 of lalr1.cc  */
#line 506 "cpp_scanner.y"
    {
    (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
    (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
  }
    break;

  case 74:

/* Line 677 of lalr1.cc  */
#line 512 "cpp_scanner.y"
    {
    (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
   }
    break;

  case 75:

/* Line 677 of lalr1.cc  */
#line 515 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 76:

/* Line 677 of lalr1.cc  */
#line 520 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(1) - (1)].name);
      (yyval.name).Type = NameInfo::NAME_TYPE;
   }
    break;

  case 77:

/* Line 677 of lalr1.cc  */
#line 524 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 78:

/* Line 677 of lalr1.cc  */
#line 527 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (1)].name);
   }
    break;

  case 79:

/* Line 677 of lalr1.cc  */
#line 530 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(3) - (1)].name);
   }
    break;

  case 80:

/* Line 677 of lalr1.cc  */
#line 533 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(4) - (1)].name);
      (yyval.name).IsTemplate = true;
   }
    break;

  case 81:

/* Line 677 of lalr1.cc  */
#line 537 "cpp_scanner.y"
    {
      (yyval.name) = (yysemantic_stack_[(2) - (2)].name);
   }
    break;

  case 82:

/* Line 677 of lalr1.cc  */
#line 543 "cpp_scanner.y"
    {
     (yyval.list).push_back((yysemantic_stack_[(1) - (1)].name));
   }
    break;

  case 83:

/* Line 677 of lalr1.cc  */
#line 547 "cpp_scanner.y"
    {
     (yyval.list) = (yysemantic_stack_[(3) - (1)].list);
     (yyval.list).push_back((yysemantic_stack_[(3) - (3)].name));
   }
    break;

  case 84:

/* Line 677 of lalr1.cc  */
#line 552 "cpp_scanner.y"
    {
     (yyval.flag) = false;
   }
    break;

  case 85:

/* Line 677 of lalr1.cc  */
#line 555 "cpp_scanner.y"
    {
     (yyval.flag) = true;
   }
    break;

  case 86:

/* Line 677 of lalr1.cc  */
#line 560 "cpp_scanner.y"
    {
        (yyval.name) = NameInfo((yysemantic_stack_[(1) - (1)].ident));
      }
    break;

  case 87:

/* Line 677 of lalr1.cc  */
#line 564 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(2) - (2)].ident));
      (yyval.name).Qualified = true;
    }
    break;

  case 88:

/* Line 677 of lalr1.cc  */
#line 569 "cpp_scanner.y"
    {
      (yyval.name) = NameInfo((yysemantic_stack_[(3) - (1)].name).Name + "::" + (yysemantic_stack_[(3) - (3)].ident));
    }
    break;



/* Line 677 of lalr1.cc  */
#line 1200 "cpp_scanner_y.cpp"
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
  const signed char CppBisonParser::yypact_ninf_ = -111;
  const short int
  CppBisonParser::yypact_[] =
  {
      -111,    17,    15,  -111,  -111,     3,   -14,    24,    27,    28,
    -111,   112,     4,    39,  -111,  -111,  -111,    47,    82,    83,
    -111,  -111,  -111,  -111,     4,  -111,    84,  -111,  -111,  -111,
    -111,    63,     4,  -111,    73,    31,   100,   154,   108,  -111,
      78,  -111,  -111,    31,    74,  -111,  -111,    79,  -111,  -111,
    -111,    89,     4,    40,    92,    99,  -111,   106,  -111,    98,
     103,  -111,  -111,   105,   157,   124,   136,   121,   122,    53,
    -111,    94,  -111,   111,   -20,     4,  -111,  -111,   108,   112,
     108,   117,  -111,   133,  -111,   110,  -111,   135,   144,     4,
    -111,     4,  -111,   146,   158,  -111,   160,   162,  -111,    31,
    -111,     4,   124,  -111,  -111,  -111,     7,   100,  -111,  -111,
    -111,   163,   111,   165,     4,  -111,    42,    78,    66,   111,
    -111,   100,   139,   171,  -111,  -111,  -111,   192,     4,   170,
    -111,  -111,   168,  -111,    16,  -111,   173,  -111,  -111,  -111,
     166,   175,  -111,   171,   169,  -111,  -111,   155,   196,  -111,
     177,  -111,   189,  -111,   172,   182,  -111,    25,   189,  -111,
     183,  -111,   204,  -111,   176,  -111
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
      33,     0,     0,    86,     0,     0,    76,     0,    59,    42,
      24,    20,    22,     0,     0,     3,    87,    81,    43,    77,
      78,     0,     0,     0,     0,     0,    68,     0,    69,     0,
      60,    61,    64,     0,     0,    57,     0,     0,     0,     0,
       9,     0,    79,    82,     0,    70,    88,    41,    59,     0,
       0,    66,    63,    25,    26,     0,    15,     0,     0,    70,
       8,     0,    80,     0,    71,    72,    74,     0,    17,     0,
      62,     0,    57,    39,    38,    40,     0,    28,    34,    21,
      23,     0,    83,     0,     0,    75,     0,    24,     0,    67,
      27,    29,    57,    84,    45,    73,    65,     0,    70,     0,
      36,    37,     0,    85,    55,    18,     0,    16,    35,    46,
       0,     0,    34,    84,     0,    56,    44,    57,     0,    50,
       0,    48,    47,    19,     0,     0,    50,     0,    49,    54,
       0,    53,     0,    51,     0,    52
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yypgoto_[] =
  {
      -111,  -111,   -16,  -111,   -91,   -71,  -111,  -111,  -111,  -111,
    -111,  -111,    95,  -111,   109,    -8,  -111,  -111,    71,   129,
    -111,  -111,  -111,  -111,  -111,  -111,    59,  -111,  -111,  -111,
     -59,   138,  -111,   137,   102,  -111,   -84,  -111,  -110,   -11,
    -111,    76,   -33
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  CppBisonParser::yydefgoto_[] =
  {
        -1,     1,     2,    14,    15,    16,    40,   108,   117,   142,
      67,    68,    66,    83,    84,    17,    18,    19,   122,   132,
      20,    21,    22,    23,   144,   154,   152,   164,   160,   141,
      24,    59,    60,    61,    62,    63,    93,    94,    95,    96,
      74,   134,    36
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char CppBisonParser::yytable_ninf_ = -58;
  const short int
  CppBisonParser::yytable_[] =
  {
        35,    37,    53,    34,   125,   111,    85,    25,    91,    44,
      69,    31,    92,    43,    31,    -2,     4,     3,     5,    27,
     139,    47,   -57,     6,     7,     8,     9,    64,    32,    71,
      10,   130,    31,    11,    12,    13,    26,    33,    31,   -57,
      33,    73,   159,    85,   136,   140,    54,   161,   -57,    32,
      56,   131,   107,    49,    50,    51,   130,    28,    33,    54,
      29,    30,    52,    58,    33,    75,   118,    64,    99,    64,
      38,    98,    54,   121,    39,     4,   131,     5,    89,    70,
     112,   -57,     6,     7,     8,     9,    41,    42,    45,    10,
     119,   128,    11,    12,    13,     4,    46,     5,   -57,    90,
      48,   -57,     6,     7,     8,     9,    54,   -57,    65,    10,
      52,    72,    11,    12,    13,    31,    56,    31,   -57,    31,
       6,     7,   103,   104,   105,    76,    77,   -57,    57,    58,
      79,    80,    32,    49,    50,    51,    32,    78,    81,    10,
      86,    33,    52,    33,   129,    33,   101,     6,     7,     8,
       9,   103,   104,   105,    10,    87,    88,    11,    12,    13,
     150,   102,   109,     6,     7,     8,     9,   103,   104,   105,
      10,   110,   113,    11,    12,    13,    49,    50,    51,    49,
      50,    51,    49,    50,    51,    52,   114,    55,    52,   123,
      82,    52,   124,   115,   116,   133,   135,   137,   138,   143,
     151,   145,   146,   149,   153,   155,   156,   157,   163,   162,
     165,   120,   127,   147,   106,   158,    97,   100,   126,   148
  };

  /* YYCHECK.  */
  const unsigned char
  CppBisonParser::yycheck_[] =
  {
        11,    12,    35,    11,   114,    89,    65,     4,    28,    25,
      43,     7,    32,    24,     7,     0,     1,     0,     3,    33,
       4,    32,     7,     8,     9,    10,    11,    38,    24,    45,
      15,   122,     7,    18,    19,    20,    33,    33,     7,    24,
      33,    52,    17,   102,   128,    29,     6,   157,    33,    24,
       8,   122,    85,    22,    23,    24,   147,    33,    33,     6,
      33,    33,    31,    21,    33,    25,    99,    78,    79,    80,
      31,    79,     6,   106,    27,     1,   147,     3,    25,     5,
      91,     7,     8,     9,    10,    11,     4,     4,     4,    15,
     101,    25,    18,    19,    20,     1,    33,     3,    24,     5,
      27,     7,     8,     9,    10,    11,     6,    33,    30,    15,
      31,    22,    18,    19,    20,     7,     8,     7,    24,     7,
       8,     9,    12,    13,    14,    33,    27,    33,    20,    21,
      32,    28,    24,    22,    23,    24,    24,    31,    33,    15,
       4,    33,    31,    33,     5,    33,    29,     8,     9,    10,
      11,    12,    13,    14,    15,    34,    34,    18,    19,    20,
       5,    28,    27,     8,     9,    10,    11,    12,    13,    14,
      15,    27,    26,    18,    19,    20,    22,    23,    24,    22,
      23,    24,    22,    23,    24,    31,    28,    33,    31,    26,
      33,    31,    27,    33,    32,    24,     4,    27,    30,    26,
       4,    35,    27,    34,    27,    16,    34,    25,     4,    26,
      34,   102,   117,   142,    85,   156,    78,    80,   116,   143
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  CppBisonParser::yystos_[] =
  {
         0,    37,    38,     0,     1,     3,     8,     9,    10,    11,
      15,    18,    19,    20,    39,    40,    41,    51,    52,    53,
      56,    57,    58,    59,    66,     4,    33,    33,    33,    33,
      33,     7,    24,    33,    51,    75,    78,    75,    31,    27,
      42,     4,     4,    75,    38,     4,    33,    75,    27,    22,
      23,    24,    31,    78,     6,    33,     8,    20,    21,    67,
      68,    69,    70,    71,    75,    30,    48,    46,    47,    78,
       5,    38,    22,    75,    76,    25,    33,    27,    31,    32,
      28,    33,    33,    49,    50,    66,     4,    34,    34,    25,
       5,    28,    32,    72,    73,    74,    75,    67,    51,    75,
      69,    29,    28,    12,    13,    14,    55,    78,    43,    27,
      27,    72,    75,    26,    28,    33,    32,    44,    78,    75,
      50,    78,    54,    26,    27,    74,    70,    48,    25,     5,
      40,    41,    55,    24,    77,     4,    72,    27,    30,     4,
      29,    65,    45,    26,    60,    35,    27,    54,    77,    34,
       5,     4,    62,    27,    61,    16,    34,    25,    62,    17,
      64,    74,    26,     4,    63,    34
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
      67,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    76,    76,    77,    77,    78,    78,    78
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
       1,     1,     3,     2,     1,     5,     2,     4,     1,     1,
       0,     1,     1,     3,     1,     2,     1,     2,     2,     3,
       4,     2,     1,     3,     0,     1,     1,     2,     3
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
        37,     0,    -1,    38,    -1,    -1,    38,    39,    -1,    38,
      40,    -1,    38,    41,    -1,    38,     1,    -1,     3,    33,
       4,    38,     5,    -1,     3,     4,    38,     5,    -1,    57,
      -1,    58,    -1,    59,    -1,    56,    -1,    -1,    -1,    51,
      42,    48,     4,    43,    54,     5,    27,    -1,    -1,    -1,
      20,    31,    67,    32,    51,    44,    48,     4,    45,    54,
       5,    27,    -1,    -1,    52,     4,    46,    34,    27,    -1,
      -1,    53,     4,    47,    34,    27,    -1,    -1,    30,    49,
      -1,    50,    -1,    49,    28,    50,    -1,    66,    78,    -1,
      66,    55,    78,    -1,     8,    33,    -1,     9,    33,    -1,
      10,    33,    -1,    11,    33,    -1,    -1,    54,    55,    30,
      -1,    54,    40,    -1,    54,    41,    -1,    13,    -1,    12,
      -1,    14,    -1,    19,    75,    33,    27,    -1,    51,    27,
      -1,    18,    51,    27,    -1,    66,    75,    78,    25,    72,
      26,    77,    65,    27,    -1,    18,    75,    78,    25,    72,
      26,    27,    -1,    -1,    66,    75,    78,    25,    72,    26,
      77,     4,    60,    34,    62,    -1,    -1,    20,    31,    67,
      32,    75,    78,    25,    72,    26,    77,     4,    61,    34,
      62,    -1,    -1,    -1,    62,    16,    25,    64,    26,     4,
      63,    34,    -1,    74,    -1,    17,    -1,    -1,    29,    35,
      -1,    -1,    15,    -1,    -1,    68,    -1,    69,    -1,    68,
      28,    69,    -1,    75,    33,    -1,    70,    -1,    20,    31,
      67,    32,    70,    -1,    71,    33,    -1,    71,    33,    29,
      75,    -1,     8,    -1,    21,    -1,    -1,    73,    -1,    74,
      -1,    73,    28,    74,    -1,    75,    -1,    75,    33,    -1,
      78,    -1,    75,    22,    -1,    75,    23,    -1,    75,    24,
      22,    -1,    75,    31,    76,    32,    -1,    24,    75,    -1,
      75,    -1,    76,    28,    75,    -1,    -1,    24,    -1,    33,
      -1,     7,    33,    -1,    78,     6,    33,    -1
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
     205,   207,   209,   213,   216,   218,   224,   227,   232,   234,
     236,   237,   239,   241,   245,   247,   250,   252,   255,   258,
     262,   267,   270,   272,   276,   277,   279,   281,   284
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  CppBisonParser::yyrline_[] =
  {
         0,   189,   189,   194,   195,   199,   203,   207,   213,   218,
     226,   227,   228,   229,   233,   237,   232,   249,   253,   247,
     265,   264,   273,   272,   284,   286,   292,   296,   303,   310,
     320,   323,   330,   335,   339,   340,   344,   349,   356,   357,
     358,   361,   369,   372,   379,   387,   397,   396,   409,   407,
     421,   423,   422,   431,   432,   435,   438,   449,   452,   457,
     458,   461,   464,   471,   475,   479,   486,   490,   496,   497,
     499,   500,   503,   506,   512,   515,   520,   524,   527,   530,
     533,   537,   542,   546,   552,   555,   560,   564,   569
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
  const int CppBisonParser::yylast_ = 219;
  const int CppBisonParser::yynnts_ = 43;
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
#line 1784 "cpp_scanner_y.cpp"


/* Line 1055 of lalr1.cc  */
#line 575 "cpp_scanner.y"


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

