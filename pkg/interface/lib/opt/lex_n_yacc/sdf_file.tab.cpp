/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         sdf_fileparse
#define yylex           sdf_filelex
#define yyerror         sdf_fileerror
#define yydebug         sdf_filedebug
#define yynerrs         sdf_filenerrs
#define yylval          sdf_filelval
#define yychar          sdf_filechar

/* First part of user prologue.  */
#line 1 "src/sdf_file.y"

// **************************************************************************
// File       [ sdf_file.y ]
// Author     [ littleshamoo ]
// Synopsis   [ Currently only supports SDF file header and absolute and
//              increment delay information ]
// Date       [ 2010/11/18 created ]
// **************************************************************************

// #define YYPARSE_PARAM param

#include <cstring>
#include <cstdio>

#include "sdf_file.h"

using namespace IntfNs;

extern char *sdf_filetext;
extern int  sdf_fileline;
int  sdf_filelex(void);
void sdf_fileerror(void* a, char const *msg);

IntfNs::SdfFile *sdf;


#line 105 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sdf_file.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DELAYFILE = 3,                  /* DELAYFILE  */
  YYSYMBOL_SDFVERSION = 4,                 /* SDFVERSION  */
  YYSYMBOL_DESIGN = 5,                     /* DESIGN  */
  YYSYMBOL_DATE = 6,                       /* DATE  */
  YYSYMBOL_VENDOR = 7,                     /* VENDOR  */
  YYSYMBOL_PROGRAM = 8,                    /* PROGRAM  */
  YYSYMBOL_VERSION = 9,                    /* VERSION  */
  YYSYMBOL_DIVIDER = 10,                   /* DIVIDER  */
  YYSYMBOL_VOLTAGE = 11,                   /* VOLTAGE  */
  YYSYMBOL_PROCESS = 12,                   /* PROCESS  */
  YYSYMBOL_TEMPERATURE = 13,               /* TEMPERATURE  */
  YYSYMBOL_TIMESCALE = 14,                 /* TIMESCALE  */
  YYSYMBOL_CELL = 15,                      /* CELL  */
  YYSYMBOL_CELLTYPE = 16,                  /* CELLTYPE  */
  YYSYMBOL_INSTANCE = 17,                  /* INSTANCE  */
  YYSYMBOL_DELAY = 18,                     /* DELAY  */
  YYSYMBOL_TIMINGCHECK = 19,               /* TIMINGCHECK  */
  YYSYMBOL_TIMINGENV = 20,                 /* TIMINGENV  */
  YYSYMBOL_PATHPULSE = 21,                 /* PATHPULSE  */
  YYSYMBOL_PATHPULSEPERCENT = 22,          /* PATHPULSEPERCENT  */
  YYSYMBOL_ABSOLUTE = 23,                  /* ABSOLUTE  */
  YYSYMBOL_INCREMENT = 24,                 /* INCREMENT  */
  YYSYMBOL_IOPATH = 25,                    /* IOPATH  */
  YYSYMBOL_RETAIN = 26,                    /* RETAIN  */
  YYSYMBOL_COND = 27,                      /* COND  */
  YYSYMBOL_SCOND = 28,                     /* SCOND  */
  YYSYMBOL_CCOND = 29,                     /* CCOND  */
  YYSYMBOL_CONDELSE = 30,                  /* CONDELSE  */
  YYSYMBOL_PORT = 31,                      /* PORT  */
  YYSYMBOL_INTERCONNECT = 32,              /* INTERCONNECT  */
  YYSYMBOL_DEVICE = 33,                    /* DEVICE  */
  YYSYMBOL_SETUP = 34,                     /* SETUP  */
  YYSYMBOL_HOLD = 35,                      /* HOLD  */
  YYSYMBOL_SETUPHOLD = 36,                 /* SETUPHOLD  */
  YYSYMBOL_RECOVERY = 37,                  /* RECOVERY  */
  YYSYMBOL_REMOVAL = 38,                   /* REMOVAL  */
  YYSYMBOL_RECREM = 39,                    /* RECREM  */
  YYSYMBOL_SKEW = 40,                      /* SKEW  */
  YYSYMBOL_WIDTH = 41,                     /* WIDTH  */
  YYSYMBOL_PERIOD = 42,                    /* PERIOD  */
  YYSYMBOL_NOCHANGE = 43,                  /* NOCHANGE  */
  YYSYMBOL_NAME = 44,                      /* NAME  */
  YYSYMBOL_EXCEPTION = 45,                 /* EXCEPTION  */
  YYSYMBOL_PATHCONSTRAINT = 46,            /* PATHCONSTRAINT  */
  YYSYMBOL_PERIODCONSTRAINT = 47,          /* PERIODCONSTRAINT  */
  YYSYMBOL_SUM = 48,                       /* SUM  */
  YYSYMBOL_DIFF = 49,                      /* DIFF  */
  YYSYMBOL_SKEWCONSTRAINT = 50,            /* SKEWCONSTRAINT  */
  YYSYMBOL_ARRIVAL = 51,                   /* ARRIVAL  */
  YYSYMBOL_DEPARTURE = 52,                 /* DEPARTURE  */
  YYSYMBOL_SLACK = 53,                     /* SLACK  */
  YYSYMBOL_WAVEFORM = 54,                  /* WAVEFORM  */
  YYSYMBOL_POSEDGE = 55,                   /* POSEDGE  */
  YYSYMBOL_NEGEDGE = 56,                   /* NEGEDGE  */
  YYSYMBOL_CASE_EQU = 57,                  /* CASE_EQU  */
  YYSYMBOL_CASE_INEQU = 58,                /* CASE_INEQU  */
  YYSYMBOL_EQU = 59,                       /* EQU  */
  YYSYMBOL_INEQU = 60,                     /* INEQU  */
  YYSYMBOL_L_AND = 61,                     /* L_AND  */
  YYSYMBOL_L_OR = 62,                      /* L_OR  */
  YYSYMBOL_LESS_OR_EQU = 63,               /* LESS_OR_EQU  */
  YYSYMBOL_GREATER_OR_EQU = 64,            /* GREATER_OR_EQU  */
  YYSYMBOL_RIGHT_SHIFT = 65,               /* RIGHT_SHIFT  */
  YYSYMBOL_LEFT_SHIFT = 66,                /* LEFT_SHIFT  */
  YYSYMBOL_U_NAND = 67,                    /* U_NAND  */
  YYSYMBOL_U_NOR = 68,                     /* U_NOR  */
  YYSYMBOL_U_XNOR = 69,                    /* U_XNOR  */
  YYSYMBOL_U_XNOR_ALT = 70,                /* U_XNOR_ALT  */
  YYSYMBOL_BIT_CONST = 71,                 /* BIT_CONST  */
  YYSYMBOL_ONE_CONST = 72,                 /* ONE_CONST  */
  YYSYMBOL_ZERO_CONST = 73,                /* ZERO_CONST  */
  YYSYMBOL_EDGE = 74,                      /* EDGE  */
  YYSYMBOL_PATH = 75,                      /* PATH  */
  YYSYMBOL_IDENTIFIER = 76,                /* IDENTIFIER  */
  YYSYMBOL_QSTRING = 77,                   /* QSTRING  */
  YYSYMBOL_NUMBER = 78,                    /* NUMBER  */
  YYSYMBOL_79_ = 79,                       /* '|'  */
  YYSYMBOL_80_ = 80,                       /* '^'  */
  YYSYMBOL_81_ = 81,                       /* '&'  */
  YYSYMBOL_82_ = 82,                       /* '<'  */
  YYSYMBOL_83_ = 83,                       /* '>'  */
  YYSYMBOL_84_ = 84,                       /* '+'  */
  YYSYMBOL_85_ = 85,                       /* '-'  */
  YYSYMBOL_86_ = 86,                       /* '*'  */
  YYSYMBOL_87_ = 87,                       /* '/'  */
  YYSYMBOL_88_ = 88,                       /* '%'  */
  YYSYMBOL_89_ = 89,                       /* '!'  */
  YYSYMBOL_90_ = 90,                       /* '~'  */
  YYSYMBOL_91_ = 91,                       /* '('  */
  YYSYMBOL_92_ = 92,                       /* ')'  */
  YYSYMBOL_93_ = 93,                       /* '.'  */
  YYSYMBOL_94_ = 94,                       /* '['  */
  YYSYMBOL_95_ = 95,                       /* ']'  */
  YYSYMBOL_96_ = 96,                       /* ':'  */
  YYSYMBOL_97_ = 97,                       /* '{'  */
  YYSYMBOL_98_ = 98,                       /* '}'  */
  YYSYMBOL_99_ = 99,                       /* ','  */
  YYSYMBOL_100_ = 100,                     /* '?'  */
  YYSYMBOL_YYACCEPT = 101,                 /* $accept  */
  YYSYMBOL_start = 102,                    /* start  */
  YYSYMBOL_initialize = 103,               /* initialize  */
  YYSYMBOL_delay_file = 104,               /* delay_file  */
  YYSYMBOL_sdf_header = 105,               /* sdf_header  */
  YYSYMBOL_sdf_version = 106,              /* sdf_version  */
  YYSYMBOL_design_name = 107,              /* design_name  */
  YYSYMBOL_date = 108,                     /* date  */
  YYSYMBOL_vendor = 109,                   /* vendor  */
  YYSYMBOL_program_name = 110,             /* program_name  */
  YYSYMBOL_program_version = 111,          /* program_version  */
  YYSYMBOL_hierarchy_divider = 112,        /* hierarchy_divider  */
  YYSYMBOL_hchar = 113,                    /* hchar  */
  YYSYMBOL_voltage = 114,                  /* voltage  */
  YYSYMBOL_process = 115,                  /* process  */
  YYSYMBOL_temperature = 116,              /* temperature  */
  YYSYMBOL_time_scale = 117,               /* time_scale  */
  YYSYMBOL_tsvalue = 118,                  /* tsvalue  */
  YYSYMBOL_cells = 119,                    /* cells  */
  YYSYMBOL_cell = 120,                     /* cell  */
  YYSYMBOL_add_cell = 121,                 /* add_cell  */
  YYSYMBOL_cell_type = 122,                /* cell_type  */
  YYSYMBOL_cell_instance = 123,            /* cell_instance  */
  YYSYMBOL_timing_specs = 124,             /* timing_specs  */
  YYSYMBOL_timing_spec = 125,              /* timing_spec  */
  YYSYMBOL_del_spec = 126,                 /* del_spec  */
  YYSYMBOL_deltypes = 127,                 /* deltypes  */
  YYSYMBOL_tc_spec = 128,                  /* tc_spec  */
  YYSYMBOL_tchk_defs = 129,                /* tchk_defs  */
  YYSYMBOL_te_spec = 130,                  /* te_spec  */
  YYSYMBOL_te_defs = 131,                  /* te_defs  */
  YYSYMBOL_deltype = 132,                  /* deltype  */
  YYSYMBOL_pathtype = 133,                 /* pathtype  */
  YYSYMBOL_valuetype = 134,                /* valuetype  */
  YYSYMBOL_del_path = 135,                 /* del_path  */
  YYSYMBOL_del_defs = 136,                 /* del_defs  */
  YYSYMBOL_input_output_path = 137,        /* input_output_path  */
  YYSYMBOL_del_def = 138,                  /* del_def  */
  YYSYMBOL_del_cond = 139,                 /* del_cond  */
  YYSYMBOL_del_def_iopath = 140,           /* del_def_iopath  */
  YYSYMBOL_cond_else_type = 141,           /* cond_else_type  */
  YYSYMBOL_tchk_def = 142,                 /* tchk_def  */
  YYSYMBOL_port_tchk = 143,                /* port_tchk  */
  YYSYMBOL_scond = 144,                    /* scond  */
  YYSYMBOL_ccond = 145,                    /* ccond  */
  YYSYMBOL_name = 146,                     /* name  */
  YYSYMBOL_exception = 147,                /* exception  */
  YYSYMBOL_cell_instances = 148,           /* cell_instances  */
  YYSYMBOL_te_def = 149,                   /* te_def  */
  YYSYMBOL_cns_def = 150,                  /* cns_def  */
  YYSYMBOL_port_instances = 151,           /* port_instances  */
  YYSYMBOL_constraint_paths = 152,         /* constraint_paths  */
  YYSYMBOL_tenv_def = 153,                 /* tenv_def  */
  YYSYMBOL_number_q = 154,                 /* number_q  */
  YYSYMBOL_constraint_path = 155,          /* constraint_path  */
  YYSYMBOL_port_spec = 156,                /* port_spec  */
  YYSYMBOL_port_edge = 157,                /* port_edge  */
  YYSYMBOL_edge_identifier = 158,          /* edge_identifier  */
  YYSYMBOL_port_instance = 159,            /* port_instance  */
  YYSYMBOL_port = 160,                     /* port  */
  YYSYMBOL_scalar_port = 161,              /* scalar_port  */
  YYSYMBOL_bus_port = 162,                 /* bus_port  */
  YYSYMBOL_edge_list = 163,                /* edge_list  */
  YYSYMBOL_pos_pairs = 164,                /* pos_pairs  */
  YYSYMBOL_neg_pairs = 165,                /* neg_pairs  */
  YYSYMBOL_pos_pair = 166,                 /* pos_pair  */
  YYSYMBOL_neg_pair = 167,                 /* neg_pair  */
  YYSYMBOL_value = 168,                    /* value  */
  YYSYMBOL_triple = 169,                   /* triple  */
  YYSYMBOL_delval = 170,                   /* delval  */
  YYSYMBOL_delval_list = 171,              /* delval_list  */
  YYSYMBOL_expression = 172,               /* expression  */
  YYSYMBOL_conditional_expression = 173,   /* conditional_expression  */
  YYSYMBOL_simple_expression = 174,        /* simple_expression  */
  YYSYMBOL_binary_expression = 175,        /* binary_expression  */
  YYSYMBOL_timing_check_condition = 176,   /* timing_check_condition  */
  YYSYMBOL_scalar_node = 177,              /* scalar_node  */
  YYSYMBOL_scalar_constant = 178,          /* scalar_constant  */
  YYSYMBOL_unary_op = 179,                 /* unary_op  */
  YYSYMBOL_inv_op = 180,                   /* inv_op  */
  YYSYMBOL_equ_op = 181                    /* equ_op  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   767

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  101
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  81
/* YYNRULES -- Number of rules.  */
#define YYNRULES  233
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  550

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,     2,     2,    88,    81,     2,
      91,    92,    86,    84,    99,    85,    93,    87,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    96,     2,
      82,     2,    83,   100,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    94,     2,    95,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    97,    79,    98,    90,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    94,    94,    98,   103,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   123,   128,   133,   138,
     143,   148,   153,   158,   159,   164,   165,   173,   177,   178,
     186,   191,   196,   197,   202,   203,   208,   213,   218,   219,
     220,   221,   226,   227,   232,   233,   234,   239,   244,   245,
     250,   255,   256,   261,   266,   267,   272,   273,   278,   279,
     284,   285,   290,   291,   292,   293,   298,   303,   312,   318,
     321,   324,   327,   333,   340,   346,   356,   357,   362,   369,
     380,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   405,   406,   407,
     412,   413,   418,   419,   423,   424,   428,   433,   434,   439,
     440,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   460,   461,   466,   467,   472,   473,   474,   475,
     476,   477,   478,   483,   484,   489,   494,   496,   502,   508,
     509,   510,   514,   518,   526,   530,   531,   536,   537,   538,
     542,   550,   558,   570,   571,   576,   577,   582,   583,   588,
     593,   598,   600,   604,   609,   613,   617,   621,   625,   629,
     633,   641,   643,   646,   654,   658,   663,   669,   678,   697,
     698,   699,   704,   705,   710,   711,   712,   713,   714,   715,
     716,   721,   722,   723,   724,   725,   726,   727,   728,   729,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     740,   745,   746,   747,   752,   757,   758,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,   773,   778,   779,
     784,   785,   786,   787
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DELAYFILE",
  "SDFVERSION", "DESIGN", "DATE", "VENDOR", "PROGRAM", "VERSION",
  "DIVIDER", "VOLTAGE", "PROCESS", "TEMPERATURE", "TIMESCALE", "CELL",
  "CELLTYPE", "INSTANCE", "DELAY", "TIMINGCHECK", "TIMINGENV", "PATHPULSE",
  "PATHPULSEPERCENT", "ABSOLUTE", "INCREMENT", "IOPATH", "RETAIN", "COND",
  "SCOND", "CCOND", "CONDELSE", "PORT", "INTERCONNECT", "DEVICE", "SETUP",
  "HOLD", "SETUPHOLD", "RECOVERY", "REMOVAL", "RECREM", "SKEW", "WIDTH",
  "PERIOD", "NOCHANGE", "NAME", "EXCEPTION", "PATHCONSTRAINT",
  "PERIODCONSTRAINT", "SUM", "DIFF", "SKEWCONSTRAINT", "ARRIVAL",
  "DEPARTURE", "SLACK", "WAVEFORM", "POSEDGE", "NEGEDGE", "CASE_EQU",
  "CASE_INEQU", "EQU", "INEQU", "L_AND", "L_OR", "LESS_OR_EQU",
  "GREATER_OR_EQU", "RIGHT_SHIFT", "LEFT_SHIFT", "U_NAND", "U_NOR",
  "U_XNOR", "U_XNOR_ALT", "BIT_CONST", "ONE_CONST", "ZERO_CONST", "EDGE",
  "PATH", "IDENTIFIER", "QSTRING", "NUMBER", "'|'", "'^'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'~'", "'('", "')'",
  "'.'", "'['", "']'", "':'", "'{'", "'}'", "','", "'?'", "$accept",
  "start", "initialize", "delay_file", "sdf_header", "sdf_version",
  "design_name", "date", "vendor", "program_name", "program_version",
  "hierarchy_divider", "hchar", "voltage", "process", "temperature",
  "time_scale", "tsvalue", "cells", "cell", "add_cell", "cell_type",
  "cell_instance", "timing_specs", "timing_spec", "del_spec", "deltypes",
  "tc_spec", "tchk_defs", "te_spec", "te_defs", "deltype", "pathtype",
  "valuetype", "del_path", "del_defs", "input_output_path", "del_def",
  "del_cond", "del_def_iopath", "cond_else_type", "tchk_def", "port_tchk",
  "scond", "ccond", "name", "exception", "cell_instances", "te_def",
  "cns_def", "port_instances", "constraint_paths", "tenv_def", "number_q",
  "constraint_path", "port_spec", "port_edge", "edge_identifier",
  "port_instance", "port", "scalar_port", "bus_port", "edge_list",
  "pos_pairs", "neg_pairs", "pos_pair", "neg_pair", "value", "triple",
  "delval", "delval_list", "expression", "conditional_expression",
  "simple_expression", "binary_expression", "timing_check_condition",
  "scalar_node", "scalar_constant", "unary_op", "inv_op", "equ_op", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-457)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -457,     4,   -76,  -457,     9,  -457,   -34,    61,   -11,  -457,
      37,   443,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,   -68,  -457,    33,    53,    58,    80,    91,   109,
      30,     0,   117,    10,   154,   149,   233,  -457,  -457,  -457,
     165,   172,   211,   215,   238,  -457,  -457,   262,    56,    11,
     269,   293,   157,   298,   175,   310,   239,   -56,   354,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,    35,   231,   385,  -457,
    -457,  -457,  -457,  -457,  -457,   399,   278,  -457,   -47,  -457,
    -457,  -457,  -457,   460,  -457,   386,   403,   405,  -457,   414,
     393,   437,   438,  -457,  -457,   105,   452,  -457,  -457,  -457,
     335,    92,  -457,   474,   112,  -457,   496,   151,  -457,  -457,
    -457,   459,   461,   472,  -457,  -457,  -457,  -457,  -457,  -457,
     114,   481,  -457,  -457,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,  -457,  -457,   161,   193,   482,   482,
     163,   163,   163,   193,   193,  -457,  -457,  -457,  -457,  -457,
     458,   471,   -70,   490,   492,   193,  -457,  -457,  -457,   492,
     304,   180,  -457,  -457,   -14,   159,  -457,  -457,  -457,   159,
     159,   159,   159,   159,   159,   492,   492,   159,   522,   193,
     193,   492,   193,   482,   482,    73,   492,   193,   492,   193,
     492,   492,   510,   512,   523,   167,  -457,   497,  -457,   492,
    -457,  -457,   163,   543,  -457,   193,   193,   171,   509,   509,
    -457,  -457,   190,  -457,  -457,  -457,  -457,  -457,   193,   492,
     492,   492,   492,   492,   492,   492,   524,   525,   492,   -49,
     193,   114,  -457,   209,   193,   534,   492,   537,   492,   492,
     492,   492,   492,   535,   247,   279,  -457,  -457,  -457,   193,
    -457,  -457,  -457,  -457,  -457,   568,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  -457,   619,   568,  -457,  -457,  -457,   407,
    -457,  -457,   101,   539,   193,   -71,   539,  -457,   539,   549,
     590,   550,   553,   556,   557,   185,  -457,  -457,  -457,   163,
     313,   301,   562,   563,   564,   492,   572,   574,   492,   575,
    -457,  -457,   492,   576,  -457,   114,  -457,   492,   586,  -457,
     577,   578,    78,   534,  -457,   290,   292,  -457,   492,   492,
     492,   492,   492,   341,   579,   581,   582,  -457,  -457,  -457,
     596,  -457,   598,   584,  -457,   439,   592,   580,   619,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   568,   619,
    -457,  -457,   585,   539,   492,   600,   539,  -457,  -457,  -457,
     615,   618,   163,   609,  -457,  -457,  -457,  -457,    -4,  -457,
    -457,  -457,  -457,   307,  -457,  -457,   309,  -457,   610,  -457,
     492,   613,   354,  -457,  -457,  -457,   314,  -457,   614,  -457,
     620,   492,   492,   492,   492,   492,   629,   633,  -457,   658,
    -457,   659,  -457,   621,   622,    -9,   626,  -457,   619,  -457,
     597,   597,   597,   597,   329,    79,   -55,   -55,   204,   204,
     511,   521,   281,   -55,   -55,   235,   235,  -457,  -457,  -457,
     623,   475,  -457,   628,   327,  -457,   539,   627,   630,   631,
    -457,  -457,   392,  -457,   332,   632,  -457,   368,   634,  -457,
     635,  -457,  -457,   370,  -457,   636,  -457,  -457,   492,   637,
     492,   638,    54,   643,   643,  -457,  -457,   539,  -457,   616,
     619,  -457,  -457,  -457,   639,   539,  -457,   236,   243,   703,
    -457,   641,  -457,  -457,   642,  -457,  -457,  -457,  -457,  -457,
     644,  -457,   645,  -457,   646,  -457,  -457,   647,   648,   649,
    -457,  -457,  -457,   539,   185,   650,   185,   651,  -457,  -457,
    -457,  -457,  -457,   653,   654,   655,   539,   656,  -457,   657,
    -457,   679,   691,  -457,   539,  -457,  -457,   672,   673,   539,
     643,   643,   539,   660,   661,   539,  -457,  -457,   539,  -457
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     1,     0,     2,     0,     0,     0,    15,
       0,     0,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,    32,    16,
       0,     0,     0,     0,     0,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,    22,    26,     0,     0,     0,    25,
      27,    29,    28,    31,    30,     0,     0,    34,     0,    43,
      44,    45,    46,     0,    36,     0,   164,   167,   169,     0,
       0,     0,     0,    35,    42,     0,   165,   166,   168,    37,
       0,     0,    49,     0,     0,    52,     0,     0,    55,   109,
     110,     0,     0,     0,    38,   170,    58,    59,    60,    61,
       0,     0,    47,    48,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    54,    39,    40,    41,
     148,   147,     0,     0,     0,     0,   144,   145,   146,    62,
       0,     0,    67,    69,     0,     0,    97,   137,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   163,     0,    56,    63,
      68,    64,     0,     0,    80,     0,     0,     0,     0,     0,
      57,    66,     0,   139,   140,   141,   142,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   161,   162,    65,     0,
     222,   224,   226,   227,   215,     0,   216,   223,   225,   221,
     217,   218,   219,   220,     0,     0,   186,    76,   179,   182,
     190,   188,     0,     0,     0,     0,     0,   171,   174,     0,
       0,     0,     0,   148,   147,     0,   228,   229,   214,     0,
     211,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      94,    95,     0,     0,   104,     0,   122,     0,     0,   113,
       0,     0,     0,     0,   125,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,   153,   154,   156,   158,   150,
       0,   149,     0,     0,    77,     0,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     187,   189,     0,     0,     0,     0,   175,    74,    70,    71,
       0,     0,     0,     0,   232,   233,   230,   231,     0,   212,
     138,    81,    82,     0,    87,    88,     0,    93,     0,   105,
       0,     0,     0,   114,   135,   124,     0,   115,     0,   119,
       0,     0,     0,     0,     0,     0,     0,     0,   132,     0,
     155,     0,   157,     0,     0,     0,     0,   184,     0,   180,
     198,   199,   196,   197,   200,   201,   203,   205,   209,   210,
     208,   207,   206,   202,   204,   191,   192,   193,   194,   195,
       0,     0,    72,     0,     0,    75,   176,     0,     0,     0,
      98,   213,     0,    83,     0,     0,    89,     0,     0,    96,
       0,   111,   108,     0,   117,     0,   116,   120,     0,     0,
       0,     0,     0,   134,   134,   152,   151,     0,    78,     0,
       0,   185,    73,   172,     0,     0,    99,     0,     0,     0,
      84,     0,    85,    90,     0,    91,   112,   106,   107,   118,
       0,   126,     0,   128,     0,   130,   133,     0,     0,     0,
     181,   183,   173,     0,     0,     0,     0,     0,    86,    92,
     127,   129,   131,     0,     0,     0,   177,     0,   100,     0,
     102,     0,     0,    79,     0,   101,   103,     0,     0,     0,
     134,   134,     0,     0,     0,     0,   159,   160,     0,   178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,   732,
    -457,  -457,  -386,  -457,   677,  -457,  -457,  -457,  -457,  -457,
    -457,   662,  -457,  -457,  -457,  -457,  -457,   595,  -457,   266,
    -457,   663,   -79,   371,  -381,  -457,  -457,  -457,   652,  -457,
     528,  -457,  -457,  -456,  -125,  -139,   338,  -457,   173,  -131,
    -210,  -457,  -457,  -457,  -457,   435,   436,  -120,   140,  -240,
    -236,  -246,  -249,    87,  -457,  -258,   470,  -269,  -457,  -457,
    -457
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,     5,     8,     9,    12,    13,    14,    15,
      16,    17,    47,    18,    19,    20,    21,    55,    22,    23,
      57,    58,    84,    78,    79,    80,   101,    81,   104,    82,
     107,   102,   120,   121,   153,   161,   154,   162,   208,   163,
     209,   105,   165,   454,   455,   179,   310,   463,   108,   109,
     231,   313,   110,   507,   183,   166,   167,   218,   168,   156,
     157,   158,   324,   325,   326,   327,   328,   277,   197,   278,
     279,   267,   268,   269,   270,   289,   290,   271,   272,   291,
     378
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     159,   186,   288,   361,     3,   458,   462,   195,   195,   334,
     346,   347,     6,   212,   184,     4,   337,   477,   508,   336,
     152,   196,   196,    36,    37,    49,    49,   372,   303,   353,
     354,   355,   356,   357,   199,    76,    77,   362,   366,   201,
     365,   213,   214,   304,    76,    93,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   226,   227,     7,   235,   236,
     215,   233,   216,   249,   217,    10,   237,   254,   239,   195,
     241,   242,   266,   491,   256,   288,   494,   498,    48,   248,
      11,   288,   152,   196,   543,   544,   219,    49,    52,    67,
     220,   221,   222,   223,   224,   225,    49,   416,   228,   293,
     294,   295,   296,   297,   298,   299,    49,    68,   302,   451,
     314,   307,   440,    85,    24,   315,   316,    45,   318,   319,
     320,   321,   322,    46,   266,    39,   446,   443,   213,   214,
      40,    86,   504,   266,   266,    41,   338,   339,   340,   341,
     342,   360,   344,   345,   346,   347,   505,   215,    65,   216,
     373,   217,    66,   150,   151,   364,   195,    42,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,    43,   479,
     196,    50,   254,    53,    49,   383,   150,   151,   386,   256,
     111,   112,   388,   100,   122,   390,    44,   391,   395,   150,
     151,   113,   359,   396,    51,   398,   400,   114,   401,   402,
     403,   404,   405,   103,   134,   152,   485,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   266,
     266,   266,   266,   266,   266,   266,   266,   266,   266,   515,
     517,   511,    54,   449,   150,   151,   150,   151,   150,   151,
      56,   509,   106,   145,   444,   513,   150,   151,    35,    71,
     164,    73,   178,    66,   185,    75,   527,    59,   529,   246,
     283,   284,   275,    66,    60,   283,   284,   285,   150,   151,
     460,   160,   210,   526,   286,   287,   465,   288,   288,   286,
     287,   468,   469,   470,   471,   472,   534,   266,   353,   354,
     355,   356,   357,   155,   539,   364,    90,    91,    92,   542,
     308,   309,   545,    61,   288,   548,   288,    62,   549,   180,
     181,   283,   284,   514,   188,   190,   191,   192,   283,   284,
     516,   355,   356,   357,   484,   286,   287,    87,   200,   202,
      63,   203,   286,   287,   204,   205,   206,   207,   338,   339,
     340,   341,   329,   330,   344,   345,   346,   347,   500,   266,
     502,   335,   230,   232,    64,   234,   116,   117,   118,   119,
     238,    69,   240,   351,   352,   353,   354,   355,   356,   357,
     374,   375,   376,   377,   331,   332,   283,   284,   273,   274,
     276,   152,   397,   152,   399,    70,   338,   339,   340,   341,
      72,   292,   344,   345,   346,   347,   406,   407,   452,   453,
     452,   456,    74,   232,   306,   152,   464,   311,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   152,   483,
     487,   488,   333,   489,   490,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,    83,   441,   363,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   489,
     493,    83,   497,    88,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   281,   282,    89,    95,   306,   187,
     189,    97,    96,    98,   100,   234,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,    99,   358,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   103,   106,
     115,   417,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   147,   193,   148,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   149,   194,   229,   481,   338,   339,
     340,   341,   160,   182,   344,   345,   346,   347,   338,   339,
     340,   341,   198,   152,   344,   345,   346,   347,   243,   247,
     244,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     280,   245,   350,   351,   352,   353,   354,   355,   356,   357,
     250,   251,   252,   253,   254,   202,   300,   301,   150,   151,
     255,   256,   257,   258,   259,   312,   323,   260,   261,   317,
     275,   392,   262,   263,   264,   250,   251,   252,   253,   254,
     265,   367,   368,   150,   151,   369,   256,   257,   258,   259,
     370,   371,   260,   261,   380,   381,   382,   262,   263,   264,
     344,   345,   346,   347,   384,   265,   385,   387,   389,   393,
     394,   408,   409,   411,   413,   415,   414,   442,   419,   351,
     352,   353,   354,   355,   356,   357,   250,   251,   252,   253,
     254,   418,   445,   447,   150,   151,   448,   256,   257,   258,
     259,   450,   459,   260,   261,   461,   466,   473,   262,   263,
     264,   474,   467,   406,   510,   407,   475,   476,   478,   480,
     482,   506,   329,   486,   492,   331,   495,   496,   499,   501,
     503,   512,   488,   518,   519,   537,   520,   521,   522,   523,
     524,   525,   528,   530,   531,   532,   538,   533,   535,   536,
     540,   541,   546,   547,    38,    94,   211,   457,   305,   146,
     410,   379,   412,   123,     0,     0,     0,   135
};

static const yytype_int16 yycheck[] =
{
     120,   140,   212,   272,     0,   386,   392,    78,    78,   255,
      65,    66,     3,    27,   139,    91,   265,    26,   474,   265,
      91,    92,    92,    91,    92,    96,    96,   285,    77,    84,
      85,    86,    87,    88,   154,    91,    92,   273,   278,   159,
     276,    55,    56,    92,    91,    92,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   175,   176,    91,   183,   184,
      74,   181,    76,   202,    78,     4,   186,    71,   188,    78,
     190,   191,   203,   454,    78,   285,   457,   463,    78,   199,
      91,   291,    91,    92,   540,   541,   165,    96,    78,    78,
     169,   170,   171,   172,   173,   174,    96,   333,   177,   219,
     220,   221,   222,   223,   224,   225,    96,    96,   228,   378,
     235,   231,   358,    78,    77,   235,   236,    87,   238,   239,
     240,   241,   242,    93,   255,    92,   366,   363,    55,    56,
      77,    96,    78,   264,   265,    77,    57,    58,    59,    60,
      61,   272,    63,    64,    65,    66,    92,    74,    92,    76,
     289,    78,    96,    75,    76,   275,    78,    77,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    77,   418,
      92,    31,    71,    33,    96,   295,    75,    76,   298,    78,
      75,    76,   302,    91,    92,   305,    77,   307,   313,    75,
      76,    86,    91,   313,    77,   315,   316,    92,   318,   319,
     320,   321,   322,    91,    92,    91,   446,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   487,
     488,   480,    78,   372,    75,    76,    75,    76,    75,    76,
      91,   477,    91,    92,   364,   485,    75,    76,    15,    92,
      91,    76,    91,    96,    91,    16,   514,    92,   516,    92,
      75,    76,    91,    96,    92,    75,    76,    77,    75,    76,
     390,    91,    92,   513,    89,    90,   396,   487,   488,    89,
      90,   401,   402,   403,   404,   405,   526,   418,    84,    85,
      86,    87,    88,   120,   534,   415,    18,    19,    20,   539,
      91,    92,   542,    92,   514,   545,   516,    92,   548,   136,
     137,    75,    76,    77,   141,   142,   143,   144,    75,    76,
      77,    86,    87,    88,   444,    89,    90,    96,   155,    25,
      92,    27,    89,    90,    30,    31,    32,    33,    57,    58,
      59,    60,    95,    96,    63,    64,    65,    66,   468,   480,
     470,   264,   179,   180,    92,   182,    21,    22,    23,    24,
     187,    92,   189,    82,    83,    84,    85,    86,    87,    88,
      57,    58,    59,    60,    95,    96,    75,    76,   205,   206,
     207,    91,    92,    91,    92,    92,    57,    58,    59,    60,
      92,   218,    63,    64,    65,    66,    55,    56,    91,    92,
      91,    92,    92,   230,   231,    91,    92,   234,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    91,    92,
      28,    29,   249,    91,    92,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,    91,   359,   274,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    91,
      92,    91,    92,    78,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   208,   209,    77,    17,   305,   141,
     142,    78,    96,    78,    91,   312,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    92,   100,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    91,    91,
      78,    92,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    92,    94,    92,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    92,    94,    44,    92,    57,    58,
      59,    60,    91,    91,    63,    64,    65,    66,    57,    58,
      59,    60,    92,    91,    63,    64,    65,    66,    78,    92,
      78,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      91,    78,    81,    82,    83,    84,    85,    86,    87,    88,
      67,    68,    69,    70,    71,    25,    92,    92,    75,    76,
      77,    78,    79,    80,    81,    91,    91,    84,    85,    92,
      91,    45,    89,    90,    91,    67,    68,    69,    70,    71,
      97,    92,    92,    75,    76,    92,    78,    79,    80,    81,
      94,    94,    84,    85,    92,    92,    92,    89,    90,    91,
      63,    64,    65,    66,    92,    97,    92,    92,    92,    92,
      92,    92,    91,    91,    78,    91,    78,    92,    98,    82,
      83,    84,    85,    86,    87,    88,    67,    68,    69,    70,
      71,    99,    92,    78,    75,    76,    78,    78,    79,    80,
      81,    92,    92,    84,    85,    92,    92,    78,    89,    90,
      91,    78,    92,    55,    98,    56,    95,    95,    92,    96,
      92,    78,    95,    92,    92,    95,    92,    92,    92,    92,
      92,    92,    29,    92,    92,    56,    92,    92,    92,    92,
      92,    92,    92,    92,    91,    91,    55,    92,    92,    92,
      78,    78,    92,    92,    22,    78,   161,   386,   230,   107,
     325,   291,   326,   101,    -1,    -1,    -1,   104
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   102,   103,     0,    91,   104,     3,    91,   105,   106,
       4,    91,   107,   108,   109,   110,   111,   112,   114,   115,
     116,   117,   119,   120,    77,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    91,    92,   120,    92,
      77,    77,    77,    77,    77,    87,    93,   113,    78,    96,
     169,    77,    78,   169,    78,   118,    91,   121,   122,    92,
      92,    92,    92,    92,    92,    92,    96,    78,    96,    92,
      92,    92,    92,    76,    92,    16,    91,    92,   124,   125,
     126,   128,   130,    91,   123,    78,    96,    96,    78,    77,
      18,    19,    20,    92,   125,    17,    96,    78,    78,    92,
      91,   127,   132,    91,   129,   142,    91,   131,   149,   150,
     153,    75,    76,    86,    92,    78,    21,    22,    23,    24,
     133,   134,    92,   132,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    92,   142,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    92,   149,    92,    92,    92,
      75,    76,    91,   135,   137,   159,   160,   161,   162,   168,
      91,   136,   138,   140,    91,   143,   156,   157,   159,   143,
     143,   143,   143,   143,   143,   143,   143,   143,    91,   146,
     159,   159,    91,   155,   155,    91,   156,   157,   159,   157,
     159,   159,   159,    94,    94,    78,    92,   169,    92,   168,
     159,   168,    25,    27,    30,    31,    32,    33,   139,   141,
      92,   138,    27,    55,    56,    74,    76,    78,   158,   143,
     143,   143,   143,   143,   143,   143,   168,   168,   143,    44,
     159,   151,   159,   168,   159,   155,   155,   168,   159,   168,
     159,   168,   168,    78,    78,    78,    92,    92,   168,   156,
      67,    68,    69,    70,    71,    77,    78,    79,    80,    81,
      84,    85,    89,    90,    91,    97,   160,   172,   173,   174,
     175,   178,   179,   159,   159,    91,   159,   168,   170,   171,
      91,   140,   140,    75,    76,    77,    89,    90,   161,   176,
     177,   180,   159,   168,   168,   168,   168,   168,   168,   168,
      92,    92,   168,    77,    92,   151,   159,   168,    91,    92,
     147,   159,    91,   152,   155,   168,   168,    92,   168,   168,
     168,   168,   168,    91,   163,   164,   165,   166,   167,    95,
      96,    95,    96,   159,   172,   174,   172,   173,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,   100,    91,
     160,   178,   171,   159,   168,   171,   170,    92,    92,    92,
      94,    94,   176,   156,    57,    58,    59,    60,   181,   177,
      92,    92,    92,   168,    92,    92,   168,    92,   168,    92,
     168,   168,    45,    92,    92,   155,   168,    92,   168,    92,
     168,   168,   168,   168,   168,   168,    55,    56,    92,    91,
     166,    91,   167,    78,    78,    91,   171,    92,    99,    98,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     172,   174,    92,   171,   168,    92,   170,    78,    78,   156,
      92,   178,    91,    92,   144,   145,    92,   144,   145,    92,
     168,    92,   123,   148,    92,   168,    92,    92,   168,   168,
     168,   168,   168,    78,    78,    95,    95,    26,    92,   173,
      96,    92,    92,    92,   168,   170,    92,    28,    29,    91,
      92,   145,    92,    92,   145,    92,    92,    92,   123,    92,
     168,    92,   168,    92,    78,    92,    78,   154,   154,   171,
      98,   173,    92,   170,    77,   176,    77,   176,    92,    92,
      92,    92,    92,    92,    92,    92,   170,   176,    92,   176,
      92,    91,    91,    92,   170,    92,    92,    56,    55,   170,
      78,    78,   170,   154,   154,   170,    92,    92,   170,   170
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   101,   102,   103,   104,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   113,   114,   114,   115,   116,   116,
     117,   118,   119,   119,   120,   120,   121,   122,   123,   123,
     123,   123,   124,   124,   125,   125,   125,   126,   127,   127,
     128,   129,   129,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   135,   135,   136,   136,   137,   138,
     138,   138,   138,   138,   138,   138,   139,   139,   140,   140,
     141,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   143,   143,   143,
     144,   144,   145,   145,   146,   146,   147,   148,   148,   149,
     149,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   151,   152,   152,   153,   153,   153,   153,
     153,   153,   153,   154,   154,   155,   156,   156,   157,   158,
     158,   158,   158,   158,   159,   160,   160,   161,   161,   161,
     161,   162,   162,   163,   163,   164,   164,   165,   165,   166,
     167,   168,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   170,   170,   170,   171,   171,   171,   171,   171,   172,
     172,   172,   173,   173,   174,   174,   174,   174,   174,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   176,   176,   176,   177,   178,   178,   179,   179,   179,
     179,   179,   179,   179,   179,   179,   179,   179,   180,   180,
     181,   181,   181,   181
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     5,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     1,     4,     4,     4,     4,
       4,     4,     4,     1,     1,     4,     4,     4,     4,     4,
       4,     2,     2,     1,     4,     5,     2,     4,     3,     4,
       4,     4,     2,     1,     1,     1,     1,     4,     2,     1,
       4,     2,     1,     4,     2,     1,     4,     4,     1,     1,
       1,     1,     1,     2,     2,     3,     2,     1,     2,     1,
       4,     4,     5,     6,     4,     5,     2,     3,     6,     9,
       1,     6,     6,     7,     8,     8,     9,     6,     6,     7,
       8,     8,     9,     6,     5,     5,     7,     1,     5,     6,
       4,     5,     4,     5,     3,     4,     4,     2,     1,     1,
       1,     7,     8,     5,     6,     6,     7,     7,     8,     6,
       7,     5,     2,     1,     2,     1,     8,     9,     8,     9,
       8,     9,     6,     1,     0,     4,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     6,     6,     1,     1,     2,     1,     2,     1,    10,
      10,     3,     3,     2,     3,     4,     4,     3,     4,     3,
       5,     1,     4,     5,     1,     2,     3,     6,    12,     1,
       3,     5,     1,     5,     3,     4,     1,     2,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (param, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, param); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void* param)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (param);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void* param)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, param);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void* param)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], param);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, param); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void* param)
{
  YY_USE (yyvaluep);
  YY_USE (param);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void* param)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* initialize: %empty  */
#line 98 "src/sdf_file.y"
      { sdf = (SdfFile *)(param); }
#line 1698 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 16: /* sdf_version: '(' SDFVERSION QSTRING ')'  */
#line 123 "src/sdf_file.y"
                                 { sdf->addVersion((yyvsp[-1].ychar)); }
#line 1704 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 17: /* design_name: '(' DESIGN QSTRING ')'  */
#line 128 "src/sdf_file.y"
                             { sdf->addDesign((yyvsp[-1].ychar)); }
#line 1710 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 18: /* date: '(' DATE QSTRING ')'  */
#line 133 "src/sdf_file.y"
                           { sdf->addDate((yyvsp[-1].ychar)); }
#line 1716 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 19: /* vendor: '(' VENDOR QSTRING ')'  */
#line 138 "src/sdf_file.y"
                             { sdf->addVendor((yyvsp[-1].ychar)); }
#line 1722 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 20: /* program_name: '(' PROGRAM QSTRING ')'  */
#line 143 "src/sdf_file.y"
                              { sdf->addProgName((yyvsp[-1].ychar)); }
#line 1728 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 21: /* program_version: '(' VERSION QSTRING ')'  */
#line 148 "src/sdf_file.y"
                              { sdf->addProgVersion((yyvsp[-1].ychar)); }
#line 1734 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 22: /* hierarchy_divider: '(' DIVIDER hchar ')'  */
#line 153 "src/sdf_file.y"
                            { sdf->addHierChar((yyvsp[-1].ychar)[0]); }
#line 1740 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 23: /* hchar: '/'  */
#line 158 "src/sdf_file.y"
          { (yyval.ychar)[0] = '/'; }
#line 1746 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 24: /* hchar: '.'  */
#line 159 "src/sdf_file.y"
          { (yyval.ychar)[0] = '.'; }
#line 1752 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 25: /* voltage: '(' VOLTAGE triple ')'  */
#line 164 "src/sdf_file.y"
                             { sdf->addVoltage((yyvsp[-1].yvalue)); }
#line 1758 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 26: /* voltage: '(' VOLTAGE NUMBER ')'  */
#line 165 "src/sdf_file.y"
                             { SdfValue v;
                               v.n = 1;
                               v.v[0] = (yyvsp[-1].yfloat);
                               sdf->addVoltage(v);  }
#line 1767 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 27: /* process: '(' PROCESS QSTRING ')'  */
#line 173 "src/sdf_file.y"
                              { sdf->addProcess((yyvsp[-1].ychar)); }
#line 1773 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 28: /* temperature: '(' TEMPERATURE triple ')'  */
#line 177 "src/sdf_file.y"
                                 { sdf->addTemperature((yyvsp[-1].yvalue)); }
#line 1779 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 29: /* temperature: '(' TEMPERATURE NUMBER ')'  */
#line 178 "src/sdf_file.y"
                                 { SdfValue v;
                                   v.n = 1;
                                   v.v[0] = (yyvsp[-1].yfloat);
                                   sdf->addTemperature(v);  }
#line 1788 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 31: /* tsvalue: NUMBER IDENTIFIER  */
#line 191 "src/sdf_file.y"
                        { sdf->addTimeScale((yyvsp[-1].yfloat), (yyvsp[0].ychar)); }
#line 1794 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 36: /* add_cell: cell_type cell_instance  */
#line 208 "src/sdf_file.y"
                              { sdf->addCell((yyvsp[-1].ychar), (yyvsp[0].ychar)); }
#line 1800 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 37: /* cell_type: '(' CELLTYPE QSTRING ')'  */
#line 213 "src/sdf_file.y"
                               { strcpy((yyval.ychar), (yyvsp[-1].ychar)); }
#line 1806 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 38: /* cell_instance: '(' INSTANCE ')'  */
#line 218 "src/sdf_file.y"
                                  { (yyval.ychar)[0] = '\0';   }
#line 1812 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 39: /* cell_instance: '(' INSTANCE PATH ')'  */
#line 219 "src/sdf_file.y"
                                  { strcpy((yyval.ychar), (yyvsp[-1].ychar)); }
#line 1818 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 40: /* cell_instance: '(' INSTANCE IDENTIFIER ')'  */
#line 220 "src/sdf_file.y"
                                  { strcpy((yyval.ychar), (yyvsp[-1].ychar)); }
#line 1824 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 41: /* cell_instance: '(' INSTANCE '*' ')'  */
#line 221 "src/sdf_file.y"
                                  { (yyval.ychar)[0] = '*';
                                    (yyval.ychar)[1] = '\0';   }
#line 1831 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 60: /* valuetype: ABSOLUTE  */
#line 284 "src/sdf_file.y"
                { (yyval.ydelayType) = DELAY_ABSOLUTE;  }
#line 1837 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 61: /* valuetype: INCREMENT  */
#line 285 "src/sdf_file.y"
                { (yyval.ydelayType) = DELAY_INCREMENT; }
#line 1843 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 66: /* del_defs: del_defs del_def  */
#line 298 "src/sdf_file.y"
                       {
        (yyval.ydelayDef) = (yyvsp[-1].ydelayDef);
        (yyvsp[-1].ydelayDef)->next = (yyvsp[0].ydelayDef);
        (yyvsp[0].ydelayDef)->head = (yyvsp[-1].ydelayDef)->head;
    }
#line 1853 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 67: /* del_defs: del_def  */
#line 303 "src/sdf_file.y"
              {
        (yyval.ydelayDef) = (yyvsp[0].ydelayDef);
        (yyval.ydelayDef)->head = (yyval.ydelayDef);
        (yyval.ydelayDef)->next = NULL;
    }
#line 1863 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 68: /* input_output_path: port_instance port_instance  */
#line 312 "src/sdf_file.y"
                                  { strcpy((yyval.yioPath).in, (yyvsp[-1].ychar));
                                    strcpy((yyval.yioPath).out, (yyvsp[0].ychar)); }
#line 1870 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 69: /* del_def: del_def_iopath  */
#line 318 "src/sdf_file.y"
                     {
        (yyval.ydelayDef) = (yyvsp[0].ydelayDef);
    }
#line 1878 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 70: /* del_def: '(' del_cond del_def_iopath ')'  */
#line 321 "src/sdf_file.y"
                                      {
        (yyval.ydelayDef) = (yyvsp[-1].ydelayDef);
    }
#line 1886 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 71: /* del_def: '(' cond_else_type del_def_iopath ')'  */
#line 324 "src/sdf_file.y"
                                            {
        (yyval.ydelayDef) = (yyvsp[-1].ydelayDef);
    }
#line 1894 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 72: /* del_def: '(' PORT port_instance delval_list ')'  */
#line 327 "src/sdf_file.y"
                                             {
        (yyval.ydelayDef) = new SdfDelayDef;
        (yyval.ydelayDef)->type = SdfDelayDef::PORT_DELAY;
        strcpy((yyval.ydelayDef)->p1, (yyvsp[-2].ychar));
        (yyval.ydelayDef)->vlist = (yyvsp[-1].ydelayValueList);
    }
#line 1905 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 73: /* del_def: '(' INTERCONNECT port_instance port_instance delval_list ')'  */
#line 333 "src/sdf_file.y"
                                                                   {
        (yyval.ydelayDef) = new SdfDelayDef;
        (yyval.ydelayDef)->type = SdfDelayDef::INTER_DELAY;
        strcpy((yyval.ydelayDef)->p1, (yyvsp[-3].ychar));
        strcpy((yyval.ydelayDef)->p2, (yyvsp[-2].ychar));
        (yyval.ydelayDef)->vlist = (yyvsp[-1].ydelayValueList);
    }
#line 1917 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 74: /* del_def: '(' DEVICE delval_list ')'  */
#line 340 "src/sdf_file.y"
                                 {
        (yyval.ydelayDef) = new SdfDelayDef;
        (yyval.ydelayDef)->type = SdfDelayDef::DEVICE_DELAY;
        (yyval.ydelayDef)->p1[0] = '\0';
        (yyval.ydelayDef)->vlist = (yyvsp[-1].ydelayValueList);
    }
#line 1928 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 75: /* del_def: '(' DEVICE port_instance delval_list ')'  */
#line 346 "src/sdf_file.y"
                                               {
        (yyval.ydelayDef) = new SdfDelayDef;
        (yyval.ydelayDef)->type = SdfDelayDef::DEVICE_DELAY;
        strcpy((yyval.ydelayDef)->p1, (yyvsp[-2].ychar));
        (yyval.ydelayDef)->vlist = (yyvsp[-1].ydelayValueList);
    }
#line 1939 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 78: /* del_def_iopath: '(' IOPATH port_spec port_instance delval_list ')'  */
#line 362 "src/sdf_file.y"
                                                         {
        (yyval.ydelayDef) = new SdfDelayDef;
        (yyval.ydelayDef)->type = SdfDelayDef::IO_DELAY;
        (yyval.ydelayDef)->pspec = (yyvsp[-3].yportSpec);
        strcpy((yyval.ydelayDef)->p1, (yyvsp[-2].ychar));
        (yyval.ydelayDef)->vlist = (yyvsp[-1].ydelayValueList);
    }
#line 1951 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 79: /* del_def_iopath: '(' IOPATH port_spec port_instance '(' RETAIN delval_list ')' ')'  */
#line 369 "src/sdf_file.y"
                                                                        {
        (yyval.ydelayDef) = new SdfDelayDef;
        (yyval.ydelayDef)->type = SdfDelayDef::IO_RETAIN;
        (yyval.ydelayDef)->pspec = (yyvsp[-6].yportSpec);
        strcpy((yyval.ydelayDef)->p1, (yyvsp[-5].ychar));
        (yyval.ydelayDef)->vlist = (yyvsp[-2].ydelayValueList);
    }
#line 1963 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 136: /* port_spec: port_instance  */
#line 494 "src/sdf_file.y"
                    { (yyval.yportSpec).type = SdfPortSpec::EDGE_NA;
                      strcpy((yyval.yportSpec).port, (yyvsp[0].ychar));            }
#line 1970 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 137: /* port_spec: port_edge  */
#line 496 "src/sdf_file.y"
                    { (yyval.yportSpec).type = (yyvsp[0].yportSpec).type;
                      strcpy((yyval.yportSpec).port, (yyval.yportSpec).port);       }
#line 1977 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 138: /* port_edge: '(' edge_identifier port_instance ')'  */
#line 502 "src/sdf_file.y"
                                            { (yyval.yportSpec).type = (yyvsp[-2].yportSpec).type;
                                              strcpy((yyval.yportSpec).port, (yyvsp[-1].ychar)); }
#line 1984 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 139: /* edge_identifier: POSEDGE  */
#line 508 "src/sdf_file.y"
                 { (yyval.yportSpec).type = SdfPortSpec::EDGE_01;     }
#line 1990 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 140: /* edge_identifier: NEGEDGE  */
#line 509 "src/sdf_file.y"
                 { (yyval.yportSpec).type = SdfPortSpec::EDGE_10;     }
#line 1996 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 141: /* edge_identifier: EDGE  */
#line 510 "src/sdf_file.y"
                 { if (!strcmp("0z", (yyvsp[0].ychar)))
                       (yyval.yportSpec).type = SdfPortSpec::EDGE_0Z;
                   else
                       (yyval.yportSpec).type = SdfPortSpec::EDGE_1Z; }
#line 2005 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 142: /* edge_identifier: IDENTIFIER  */
#line 514 "src/sdf_file.y"
                 { if (!strcmp("z0", (yyvsp[0].ychar)))
                       (yyval.yportSpec).type = SdfPortSpec::EDGE_Z0;
                   else
                       (yyval.yportSpec).type = SdfPortSpec::EDGE_Z1; }
#line 2014 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 143: /* edge_identifier: NUMBER  */
#line 518 "src/sdf_file.y"
                 { if ((yyvsp[0].yfloat) < 10.0)
                       (yyval.yportSpec).type = SdfPortSpec::EDGE_01;
                   else
                       (yyval.yportSpec).type = SdfPortSpec::EDGE_10; }
#line 2023 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 144: /* port_instance: port  */
#line 526 "src/sdf_file.y"
           { strcpy((yyval.ychar), (yyvsp[0].ychar)); }
#line 2029 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 145: /* port: scalar_port  */
#line 530 "src/sdf_file.y"
                  { strcpy((yyval.ychar), (yyvsp[0].ychar)); }
#line 2035 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 146: /* port: bus_port  */
#line 531 "src/sdf_file.y"
                  { strcpy((yyval.ychar), (yyvsp[0].ychar)); }
#line 2041 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 147: /* scalar_port: IDENTIFIER  */
#line 536 "src/sdf_file.y"
                                { strcpy((yyval.ychar), (yyvsp[0].ychar));                          }
#line 2047 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 148: /* scalar_port: PATH  */
#line 537 "src/sdf_file.y"
                                { strcpy((yyval.ychar), (yyvsp[0].ychar));                          }
#line 2053 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 149: /* scalar_port: IDENTIFIER '[' NUMBER ']'  */
#line 538 "src/sdf_file.y"
                                { strcpy((yyval.ychar), (yyvsp[-3].ychar));
                                  strcat((yyval.ychar), "[");
                                  sprintf(&(yyval.ychar)[strlen((yyval.ychar))], "%d", (int)(yyvsp[-1].yfloat));
                                  strcat((yyval.ychar), "]");                         }
#line 2062 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 150: /* scalar_port: PATH '[' NUMBER ']'  */
#line 542 "src/sdf_file.y"
                                { strcpy((yyval.ychar), (yyvsp[-3].ychar));
                                  strcat((yyval.ychar), "[");
                                  sprintf(&(yyval.ychar)[strlen((yyval.ychar))], "%d", (int)(yyvsp[-1].yfloat));
                                  strcat((yyval.ychar), "]");                         }
#line 2071 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 151: /* bus_port: IDENTIFIER '[' NUMBER ':' NUMBER ']'  */
#line 550 "src/sdf_file.y"
                                           {
        strcpy((yyval.ychar), (yyvsp[-5].ychar));
        strcat((yyval.ychar), "[");
        sprintf(&(yyval.ychar)[strlen((yyval.ychar))], "%d", (int)(yyvsp[-3].yfloat));
        strcat((yyval.ychar), ":");
        sprintf(&(yyval.ychar)[strlen((yyval.ychar))], "%d", (int)(yyvsp[-1].yfloat));
        strcat((yyval.ychar), "]");
    }
#line 2084 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 152: /* bus_port: PATH '[' NUMBER ':' NUMBER ']'  */
#line 558 "src/sdf_file.y"
                                     {
        strcpy((yyval.ychar), (yyvsp[-5].ychar));
        strcat((yyval.ychar), "[");
        sprintf(&(yyval.ychar)[strlen((yyval.ychar))], "%d", (int)(yyvsp[-3].yfloat));
        strcat((yyval.ychar), ":");
        sprintf(&(yyval.ychar)[strlen((yyval.ychar))], "%d", (int)(yyvsp[-1].yfloat));
        strcat((yyval.ychar), "]");
    }
#line 2097 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 161: /* value: '(' NUMBER ')'  */
#line 598 "src/sdf_file.y"
                     { (yyval.yvalue).n = 1;
                       (yyval.yvalue).v[0] = (yyvsp[-1].yfloat);      }
#line 2104 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 162: /* value: '(' triple ')'  */
#line 600 "src/sdf_file.y"
                     { (yyval.yvalue).n = (yyvsp[-1].yvalue).n;
                       (yyval.yvalue).v[0] = (yyvsp[-1].yvalue).v[0];
                       (yyval.yvalue).v[1] = (yyvsp[-1].yvalue).v[1];
                       (yyval.yvalue).v[2] = (yyvsp[-1].yvalue).v[2]; }
#line 2113 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 163: /* value: '(' ')'  */
#line 604 "src/sdf_file.y"
                     { (yyval.yvalue).n = 0;          }
#line 2119 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 164: /* triple: NUMBER ':' ':'  */
#line 609 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = (yyvsp[-2].yfloat);
                                     (yyval.yvalue).v[1] = 0;
                                     (yyval.yvalue).v[2] = 0;  }
#line 2128 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 165: /* triple: NUMBER ':' NUMBER ':'  */
#line 613 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = (yyvsp[-3].yfloat);
                                     (yyval.yvalue).v[1] = (yyvsp[-1].yfloat);
                                     (yyval.yvalue).v[2] = 0;  }
#line 2137 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 166: /* triple: NUMBER ':' ':' NUMBER  */
#line 617 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = (yyvsp[-3].yfloat);
                                     (yyval.yvalue).v[1] = 0;
                                     (yyval.yvalue).v[2] = (yyvsp[0].yfloat); }
#line 2146 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 167: /* triple: ':' NUMBER ':'  */
#line 621 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = 0;
                                     (yyval.yvalue).v[1] = (yyvsp[-1].yfloat);
                                     (yyval.yvalue).v[2] = 0;  }
#line 2155 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 168: /* triple: ':' NUMBER ':' NUMBER  */
#line 625 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = 0;
                                     (yyval.yvalue).v[1] = (yyvsp[-2].yfloat);
                                     (yyval.yvalue).v[2] = (yyvsp[0].yfloat); }
#line 2164 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 169: /* triple: ':' ':' NUMBER  */
#line 629 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = 0;
                                     (yyval.yvalue).v[1] = 0;
                                     (yyval.yvalue).v[2] = (yyvsp[0].yfloat); }
#line 2173 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 170: /* triple: NUMBER ':' NUMBER ':' NUMBER  */
#line 633 "src/sdf_file.y"
                                   { (yyval.yvalue).n = 3;
                                     (yyval.yvalue).v[0] = (yyvsp[-4].yfloat);
                                     (yyval.yvalue).v[1] = (yyvsp[-2].yfloat);
                                     (yyval.yvalue).v[2] = (yyvsp[0].yfloat); }
#line 2182 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 171: /* delval: value  */
#line 641 "src/sdf_file.y"
                                { (yyval.ydelayValue).n = 1;
                                  sdfValueCopy((yyval.ydelayValue).v[0], (yyvsp[0].yvalue)); }
#line 2189 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 172: /* delval: '(' value value ')'  */
#line 643 "src/sdf_file.y"
                                { (yyval.ydelayValue).n = 2;
                                  sdfValueCopy((yyval.ydelayValue).v[0], (yyvsp[-2].yvalue));
                                  sdfValueCopy((yyval.ydelayValue).v[1], (yyvsp[-1].yvalue)); }
#line 2197 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 173: /* delval: '(' value value value ')'  */
#line 646 "src/sdf_file.y"
                                { (yyval.ydelayValue).n = 3;
                                  sdfValueCopy((yyval.ydelayValue).v[0], (yyvsp[-3].yvalue));
                                  sdfValueCopy((yyval.ydelayValue).v[0], (yyvsp[-2].yvalue));
                                  sdfValueCopy((yyval.ydelayValue).v[1], (yyvsp[-1].yvalue)); }
#line 2206 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 174: /* delval_list: delval  */
#line 654 "src/sdf_file.y"
             {
        (yyval.ydelayValueList).n = 1;
        sdfDelayValueCopy((yyval.ydelayValueList).v[0], (yyvsp[0].ydelayValue));
    }
#line 2215 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 175: /* delval_list: delval delval  */
#line 658 "src/sdf_file.y"
                    {
        (yyval.ydelayValueList).n = 2;
        sdfDelayValueCopy((yyval.ydelayValueList).v[0], (yyvsp[-1].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[1], (yyvsp[-1].ydelayValue));
    }
#line 2225 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 176: /* delval_list: delval delval delval  */
#line 663 "src/sdf_file.y"
                           {
        (yyval.ydelayValueList).n = 3;
        sdfDelayValueCopy((yyval.ydelayValueList).v[0], (yyvsp[-2].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[1], (yyvsp[-1].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[2], (yyvsp[0].ydelayValue));
    }
#line 2236 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 177: /* delval_list: delval delval delval delval delval delval  */
#line 669 "src/sdf_file.y"
                                                {
        (yyval.ydelayValueList).n = 6;
        sdfDelayValueCopy((yyval.ydelayValueList).v[0], (yyvsp[-5].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[1], (yyvsp[-4].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[2], (yyvsp[-3].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[3], (yyvsp[-2].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[4], (yyvsp[-1].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[5], (yyvsp[0].ydelayValue));
    }
#line 2250 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;

  case 178: /* delval_list: delval delval delval delval delval delval delval delval delval delval delval delval  */
#line 678 "src/sdf_file.y"
                                                                                          {
        (yyval.ydelayValueList).n = 12;
        sdfDelayValueCopy((yyval.ydelayValueList).v[0], (yyvsp[-11].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[1], (yyvsp[-10].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[2], (yyvsp[-9].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[3], (yyvsp[-8].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[4], (yyvsp[-7].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[5], (yyvsp[-6].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[6], (yyvsp[-5].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[7], (yyvsp[-4].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[8], (yyvsp[-3].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[9], (yyvsp[-2].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[10], (yyvsp[-1].ydelayValue));
        sdfDelayValueCopy((yyval.ydelayValueList).v[11], (yyvsp[0].ydelayValue));
    }
#line 2270 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"
    break;


#line 2274 "lib/opt/lex_n_yacc/sdf_file.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (param, YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, param);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, param);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (param, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, param);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, param);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 791 "src/sdf_file.y"


void sdf_fileerror(void *a, char const *msg) {
    fprintf(stderr, "**ERROR sdf_fileerror(): ");
    fprintf(stderr, "At line %d. Near `%s'. ", sdf_fileline, sdf_filetext);
    fprintf(stderr, "%s\n", msg);
}


