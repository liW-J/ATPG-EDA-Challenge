/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_SDF_FILE_LIB_OPT_LEX_N_YACC_SDF_FILE_TAB_HPP_INCLUDED
# define YY_SDF_FILE_LIB_OPT_LEX_N_YACC_SDF_FILE_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int sdf_filedebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DELAYFILE = 258,               /* DELAYFILE  */
    SDFVERSION = 259,              /* SDFVERSION  */
    DESIGN = 260,                  /* DESIGN  */
    DATE = 261,                    /* DATE  */
    VENDOR = 262,                  /* VENDOR  */
    PROGRAM = 263,                 /* PROGRAM  */
    VERSION = 264,                 /* VERSION  */
    DIVIDER = 265,                 /* DIVIDER  */
    VOLTAGE = 266,                 /* VOLTAGE  */
    PROCESS = 267,                 /* PROCESS  */
    TEMPERATURE = 268,             /* TEMPERATURE  */
    TIMESCALE = 269,               /* TIMESCALE  */
    CELL = 270,                    /* CELL  */
    CELLTYPE = 271,                /* CELLTYPE  */
    INSTANCE = 272,                /* INSTANCE  */
    DELAY = 273,                   /* DELAY  */
    TIMINGCHECK = 274,             /* TIMINGCHECK  */
    TIMINGENV = 275,               /* TIMINGENV  */
    PATHPULSE = 276,               /* PATHPULSE  */
    PATHPULSEPERCENT = 277,        /* PATHPULSEPERCENT  */
    ABSOLUTE = 278,                /* ABSOLUTE  */
    INCREMENT = 279,               /* INCREMENT  */
    IOPATH = 280,                  /* IOPATH  */
    RETAIN = 281,                  /* RETAIN  */
    COND = 282,                    /* COND  */
    SCOND = 283,                   /* SCOND  */
    CCOND = 284,                   /* CCOND  */
    CONDELSE = 285,                /* CONDELSE  */
    PORT = 286,                    /* PORT  */
    INTERCONNECT = 287,            /* INTERCONNECT  */
    DEVICE = 288,                  /* DEVICE  */
    SETUP = 289,                   /* SETUP  */
    HOLD = 290,                    /* HOLD  */
    SETUPHOLD = 291,               /* SETUPHOLD  */
    RECOVERY = 292,                /* RECOVERY  */
    REMOVAL = 293,                 /* REMOVAL  */
    RECREM = 294,                  /* RECREM  */
    SKEW = 295,                    /* SKEW  */
    WIDTH = 296,                   /* WIDTH  */
    PERIOD = 297,                  /* PERIOD  */
    NOCHANGE = 298,                /* NOCHANGE  */
    NAME = 299,                    /* NAME  */
    EXCEPTION = 300,               /* EXCEPTION  */
    PATHCONSTRAINT = 301,          /* PATHCONSTRAINT  */
    PERIODCONSTRAINT = 302,        /* PERIODCONSTRAINT  */
    SUM = 303,                     /* SUM  */
    DIFF = 304,                    /* DIFF  */
    SKEWCONSTRAINT = 305,          /* SKEWCONSTRAINT  */
    ARRIVAL = 306,                 /* ARRIVAL  */
    DEPARTURE = 307,               /* DEPARTURE  */
    SLACK = 308,                   /* SLACK  */
    WAVEFORM = 309,                /* WAVEFORM  */
    POSEDGE = 310,                 /* POSEDGE  */
    NEGEDGE = 311,                 /* NEGEDGE  */
    CASE_EQU = 312,                /* CASE_EQU  */
    CASE_INEQU = 313,              /* CASE_INEQU  */
    EQU = 314,                     /* EQU  */
    INEQU = 315,                   /* INEQU  */
    L_AND = 316,                   /* L_AND  */
    L_OR = 317,                    /* L_OR  */
    LESS_OR_EQU = 318,             /* LESS_OR_EQU  */
    GREATER_OR_EQU = 319,          /* GREATER_OR_EQU  */
    RIGHT_SHIFT = 320,             /* RIGHT_SHIFT  */
    LEFT_SHIFT = 321,              /* LEFT_SHIFT  */
    U_NAND = 322,                  /* U_NAND  */
    U_NOR = 323,                   /* U_NOR  */
    U_XNOR = 324,                  /* U_XNOR  */
    U_XNOR_ALT = 325,              /* U_XNOR_ALT  */
    BIT_CONST = 326,               /* BIT_CONST  */
    ONE_CONST = 327,               /* ONE_CONST  */
    ZERO_CONST = 328,              /* ZERO_CONST  */
    EDGE = 329,                    /* EDGE  */
    PATH = 330,                    /* PATH  */
    IDENTIFIER = 331,              /* IDENTIFIER  */
    QSTRING = 332,                 /* QSTRING  */
    NUMBER = 333                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "src/sdf_file.y"

    float                     yfloat;
    char                      ychar[IntfNs::NAME_LEN];
    IntfNs::SdfDelayType      ydelayType;
    IntfNs::SdfValue          yvalue;
    IntfNs::SdfDelayValue     ydelayValue;
    IntfNs::SdfDelayValueList ydelayValueList;
    IntfNs::SdfDelayDef       *ydelayDef;
    IntfNs::SdfIoPath         yioPath;
    IntfNs::SdfPortSpec       yportSpec;

#line 154 "lib/opt/lex_n_yacc/sdf_file.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE sdf_filelval;


int sdf_fileparse (void* param);


#endif /* !YY_SDF_FILE_LIB_OPT_LEX_N_YACC_SDF_FILE_TAB_HPP_INCLUDED  */
