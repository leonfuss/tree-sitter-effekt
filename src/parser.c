#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 63
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 31
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 7

enum ts_symbol_identifiers {
  sym_line_comment = 1,
  anon_sym_record = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  anon_sym_LBRACK = 5,
  anon_sym_COMMA = 6,
  anon_sym_RBRACK = 7,
  anon_sym_COLON = 8,
  anon_sym_type = 9,
  anon_sym_LBRACE = 10,
  anon_sym_RBRACE = 11,
  anon_sym_SEMI = 12,
  aux_sym_generic_identifier_token1 = 13,
  sym_identifier = 14,
  sym_source_file = 15,
  sym__definition = 16,
  sym_record = 17,
  sym_type_parameters = 18,
  sym_parameters = 19,
  sym_parameter = 20,
  sym_parameter_type = 21,
  sym_type = 22,
  sym_type_members = 23,
  sym_type_member = 24,
  sym_generic_identifier = 25,
  sym_type_identifier = 26,
  aux_sym_source_file_repeat1 = 27,
  aux_sym_type_parameters_repeat1 = 28,
  aux_sym_parameters_repeat1 = 29,
  aux_sym_type_members_repeat1 = 30,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_line_comment] = "line_comment",
  [anon_sym_record] = "record",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_LBRACK] = "[",
  [anon_sym_COMMA] = ",",
  [anon_sym_RBRACK] = "]",
  [anon_sym_COLON] = ":",
  [anon_sym_type] = "type",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_SEMI] = ";",
  [aux_sym_generic_identifier_token1] = "generic_identifier_token1",
  [sym_identifier] = "identifier",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_record] = "record",
  [sym_type_parameters] = "type_parameters",
  [sym_parameters] = "parameters",
  [sym_parameter] = "parameter",
  [sym_parameter_type] = "parameter_type",
  [sym_type] = "type",
  [sym_type_members] = "type_members",
  [sym_type_member] = "type_member",
  [sym_generic_identifier] = "generic_identifier",
  [sym_type_identifier] = "type_identifier",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_type_parameters_repeat1] = "type_parameters_repeat1",
  [aux_sym_parameters_repeat1] = "parameters_repeat1",
  [aux_sym_type_members_repeat1] = "type_members_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_line_comment] = sym_line_comment,
  [anon_sym_record] = anon_sym_record,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [aux_sym_generic_identifier_token1] = aux_sym_generic_identifier_token1,
  [sym_identifier] = sym_identifier,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_record] = sym_record,
  [sym_type_parameters] = sym_type_parameters,
  [sym_parameters] = sym_parameters,
  [sym_parameter] = sym_parameter,
  [sym_parameter_type] = sym_parameter_type,
  [sym_type] = sym_type,
  [sym_type_members] = sym_type_members,
  [sym_type_member] = sym_type_member,
  [sym_generic_identifier] = sym_generic_identifier,
  [sym_type_identifier] = sym_type_identifier,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_type_parameters_repeat1] = aux_sym_type_parameters_repeat1,
  [aux_sym_parameters_repeat1] = aux_sym_parameters_repeat1,
  [aux_sym_type_members_repeat1] = aux_sym_type_members_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_line_comment] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_record] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_generic_identifier_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__definition] = {
    .visible = false,
    .named = true,
  },
  [sym_record] = {
    .visible = true,
    .named = true,
  },
  [sym_type_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_parameters] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter] = {
    .visible = true,
    .named = true,
  },
  [sym_parameter_type] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_type_members] = {
    .visible = true,
    .named = true,
  },
  [sym_type_member] = {
    .visible = true,
    .named = true,
  },
  [sym_generic_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_parameters_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_members_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_kind = 1,
  field_member = 2,
  field_members = 3,
  field_name = 4,
  field_parameters = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_kind] = "kind",
  [field_member] = "member",
  [field_members] = "members",
  [field_name] = "name",
  [field_parameters] = "parameters",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 2},
  [4] = {.index = 5, .length = 2},
  [5] = {.index = 7, .length = 3},
  [6] = {.index = 10, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_members, 3},
    {field_name, 1},
  [3] =
    {field_name, 1},
    {field_parameters, 2},
  [5] =
    {field_kind, 2},
    {field_name, 0},
  [7] =
    {field_members, 4},
    {field_name, 1},
    {field_parameters, 2},
  [10] =
    {field_member, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 40,
  [41] = 41,
  [42] = 42,
  [43] = 43,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 47,
  [48] = 48,
  [49] = 49,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(11);
      ADVANCE_MAP(
        '(', 14,
        ')', 15,
        ',', 17,
        '/', 2,
        ':', 19,
        ';', 23,
        '[', 16,
        ']', 18,
        'r', 5,
        't', 10,
        '{', 21,
        '}', 22,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(24);
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(15);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(12);
      END_STATE();
    case 3:
      if (lookahead == 'c') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'd') ADVANCE(13);
      END_STATE();
    case 5:
      if (lookahead == 'e') ADVANCE(3);
      END_STATE();
    case 6:
      if (lookahead == 'e') ADVANCE(20);
      END_STATE();
    case 7:
      if (lookahead == 'o') ADVANCE(9);
      END_STATE();
    case 8:
      if (lookahead == 'p') ADVANCE(6);
      END_STATE();
    case 9:
      if (lookahead == 'r') ADVANCE(4);
      END_STATE();
    case 10:
      if (lookahead == 'y') ADVANCE(8);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_record);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(aux_sym_generic_identifier_token1);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(24);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(25);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
  [40] = {.lex_state = 0},
  [41] = {.lex_state = 0},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 1},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 0},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(1),
    [anon_sym_record] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [aux_sym_generic_identifier_token1] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(57),
    [sym__definition] = STATE(2),
    [sym_record] = STATE(2),
    [sym_type] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(5),
    [anon_sym_record] = ACTIONS(7),
    [anon_sym_type] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(7), 1,
      anon_sym_record,
    ACTIONS(9), 1,
      anon_sym_type,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      sym_line_comment,
    STATE(3), 4,
      sym__definition,
      sym_record,
      sym_type,
      aux_sym_source_file_repeat1,
  [19] = 5,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      sym_line_comment,
    ACTIONS(20), 1,
      anon_sym_record,
    ACTIONS(23), 1,
      anon_sym_type,
    STATE(3), 4,
      sym__definition,
      sym_record,
      sym_type,
      aux_sym_source_file_repeat1,
  [38] = 1,
    ACTIONS(26), 5,
      anon_sym_LPAREN,
      anon_sym_RPAREN,
      anon_sym_LBRACK,
      anon_sym_COMMA,
      anon_sym_LBRACE,
  [46] = 5,
    ACTIONS(28), 1,
      anon_sym_RBRACE,
    ACTIONS(30), 1,
      aux_sym_generic_identifier_token1,
    STATE(26), 1,
      sym_type_member,
    STATE(58), 1,
      sym_type_members,
    STATE(60), 1,
      sym_type_identifier,
  [62] = 5,
    ACTIONS(30), 1,
      aux_sym_generic_identifier_token1,
    ACTIONS(32), 1,
      anon_sym_RBRACE,
    STATE(26), 1,
      sym_type_member,
    STATE(60), 1,
      sym_type_identifier,
    STATE(62), 1,
      sym_type_members,
  [78] = 1,
    ACTIONS(34), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [85] = 1,
    ACTIONS(36), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [92] = 1,
    ACTIONS(38), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [99] = 1,
    ACTIONS(40), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [106] = 4,
    ACTIONS(42), 1,
      anon_sym_RPAREN,
    ACTIONS(44), 1,
      sym_identifier,
    STATE(22), 1,
      sym_parameter,
    STATE(54), 1,
      sym_parameters,
  [119] = 4,
    ACTIONS(44), 1,
      sym_identifier,
    ACTIONS(46), 1,
      anon_sym_RPAREN,
    STATE(22), 1,
      sym_parameter,
    STATE(59), 1,
      sym_parameters,
  [132] = 1,
    ACTIONS(48), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [139] = 1,
    ACTIONS(50), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [146] = 1,
    ACTIONS(52), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [153] = 1,
    ACTIONS(54), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [160] = 4,
    ACTIONS(44), 1,
      sym_identifier,
    ACTIONS(56), 1,
      anon_sym_RPAREN,
    STATE(22), 1,
      sym_parameter,
    STATE(56), 1,
      sym_parameters,
  [173] = 3,
    ACTIONS(58), 1,
      anon_sym_RPAREN,
    ACTIONS(60), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_parameters_repeat1,
  [183] = 3,
    ACTIONS(63), 1,
      anon_sym_RBRACE,
    ACTIONS(65), 1,
      anon_sym_SEMI,
    STATE(19), 1,
      aux_sym_type_members_repeat1,
  [193] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    ACTIONS(70), 1,
      anon_sym_RBRACK,
    STATE(23), 1,
      aux_sym_type_parameters_repeat1,
  [203] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    ACTIONS(72), 1,
      anon_sym_RBRACK,
    STATE(20), 1,
      aux_sym_type_parameters_repeat1,
  [213] = 3,
    ACTIONS(74), 1,
      anon_sym_RPAREN,
    ACTIONS(76), 1,
      anon_sym_COMMA,
    STATE(30), 1,
      aux_sym_parameters_repeat1,
  [223] = 3,
    ACTIONS(78), 1,
      anon_sym_COMMA,
    ACTIONS(81), 1,
      anon_sym_RBRACK,
    STATE(23), 1,
      aux_sym_type_parameters_repeat1,
  [233] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    ACTIONS(83), 1,
      anon_sym_RBRACK,
    STATE(33), 1,
      aux_sym_type_parameters_repeat1,
  [243] = 3,
    ACTIONS(85), 1,
      anon_sym_LPAREN,
    ACTIONS(87), 1,
      anon_sym_LBRACK,
    STATE(55), 1,
      sym_type_parameters,
  [253] = 3,
    ACTIONS(89), 1,
      anon_sym_RBRACE,
    ACTIONS(91), 1,
      anon_sym_SEMI,
    STATE(34), 1,
      aux_sym_type_members_repeat1,
  [263] = 3,
    ACTIONS(44), 1,
      sym_identifier,
    ACTIONS(93), 1,
      anon_sym_RPAREN,
    STATE(44), 1,
      sym_parameter,
  [273] = 3,
    ACTIONS(30), 1,
      aux_sym_generic_identifier_token1,
    STATE(31), 1,
      sym_type_identifier,
    STATE(42), 1,
      sym_parameter_type,
  [283] = 3,
    ACTIONS(44), 1,
      sym_identifier,
    ACTIONS(95), 1,
      anon_sym_RPAREN,
    STATE(44), 1,
      sym_parameter,
  [293] = 3,
    ACTIONS(95), 1,
      anon_sym_RPAREN,
    ACTIONS(97), 1,
      anon_sym_COMMA,
    STATE(18), 1,
      aux_sym_parameters_repeat1,
  [303] = 2,
    ACTIONS(101), 1,
      anon_sym_LBRACK,
    ACTIONS(99), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [311] = 3,
    ACTIONS(87), 1,
      anon_sym_LBRACK,
    ACTIONS(103), 1,
      anon_sym_LBRACE,
    STATE(53), 1,
      sym_type_parameters,
  [321] = 3,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    ACTIONS(105), 1,
      anon_sym_RBRACK,
    STATE(23), 1,
      aux_sym_type_parameters_repeat1,
  [331] = 3,
    ACTIONS(91), 1,
      anon_sym_SEMI,
    ACTIONS(107), 1,
      anon_sym_RBRACE,
    STATE(19), 1,
      aux_sym_type_members_repeat1,
  [341] = 3,
    ACTIONS(30), 1,
      aux_sym_generic_identifier_token1,
    STATE(51), 1,
      sym_type_member,
    STATE(60), 1,
      sym_type_identifier,
  [351] = 1,
    ACTIONS(109), 2,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [356] = 1,
    ACTIONS(111), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [361] = 2,
    ACTIONS(30), 1,
      aux_sym_generic_identifier_token1,
    STATE(25), 1,
      sym_type_identifier,
  [368] = 2,
    ACTIONS(113), 1,
      aux_sym_generic_identifier_token1,
    STATE(24), 1,
      sym_generic_identifier,
  [375] = 1,
    ACTIONS(115), 2,
      anon_sym_LPAREN,
      anon_sym_LBRACE,
  [380] = 1,
    ACTIONS(117), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [385] = 1,
    ACTIONS(119), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [390] = 2,
    ACTIONS(113), 1,
      aux_sym_generic_identifier_token1,
    STATE(50), 1,
      sym_generic_identifier,
  [397] = 1,
    ACTIONS(58), 2,
      anon_sym_RPAREN,
      anon_sym_COMMA,
  [402] = 1,
    ACTIONS(121), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [407] = 1,
    ACTIONS(123), 2,
      anon_sym_RBRACE,
      anon_sym_SEMI,
  [412] = 2,
    ACTIONS(44), 1,
      sym_identifier,
    STATE(44), 1,
      sym_parameter,
  [419] = 2,
    ACTIONS(113), 1,
      aux_sym_generic_identifier_token1,
    STATE(21), 1,
      sym_generic_identifier,
  [426] = 2,
    ACTIONS(30), 1,
      aux_sym_generic_identifier_token1,
    STATE(32), 1,
      sym_type_identifier,
  [433] = 1,
    ACTIONS(81), 2,
      anon_sym_COMMA,
      anon_sym_RBRACK,
  [438] = 1,
    ACTIONS(63), 2,
      anon_sym_RBRACE,
      anon_sym_SEMI,
  [443] = 1,
    ACTIONS(125), 2,
      anon_sym_RBRACE,
      anon_sym_SEMI,
  [448] = 1,
    ACTIONS(127), 1,
      anon_sym_LBRACE,
  [452] = 1,
    ACTIONS(129), 1,
      anon_sym_RPAREN,
  [456] = 1,
    ACTIONS(131), 1,
      anon_sym_LPAREN,
  [460] = 1,
    ACTIONS(133), 1,
      anon_sym_RPAREN,
  [464] = 1,
    ACTIONS(135), 1,
      ts_builtin_sym_end,
  [468] = 1,
    ACTIONS(137), 1,
      anon_sym_RBRACE,
  [472] = 1,
    ACTIONS(139), 1,
      anon_sym_RPAREN,
  [476] = 1,
    ACTIONS(141), 1,
      anon_sym_LPAREN,
  [480] = 1,
    ACTIONS(143), 1,
      anon_sym_COLON,
  [484] = 1,
    ACTIONS(145), 1,
      anon_sym_RBRACE,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 38,
  [SMALL_STATE(5)] = 46,
  [SMALL_STATE(6)] = 62,
  [SMALL_STATE(7)] = 78,
  [SMALL_STATE(8)] = 85,
  [SMALL_STATE(9)] = 92,
  [SMALL_STATE(10)] = 99,
  [SMALL_STATE(11)] = 106,
  [SMALL_STATE(12)] = 119,
  [SMALL_STATE(13)] = 132,
  [SMALL_STATE(14)] = 139,
  [SMALL_STATE(15)] = 146,
  [SMALL_STATE(16)] = 153,
  [SMALL_STATE(17)] = 160,
  [SMALL_STATE(18)] = 173,
  [SMALL_STATE(19)] = 183,
  [SMALL_STATE(20)] = 193,
  [SMALL_STATE(21)] = 203,
  [SMALL_STATE(22)] = 213,
  [SMALL_STATE(23)] = 223,
  [SMALL_STATE(24)] = 233,
  [SMALL_STATE(25)] = 243,
  [SMALL_STATE(26)] = 253,
  [SMALL_STATE(27)] = 263,
  [SMALL_STATE(28)] = 273,
  [SMALL_STATE(29)] = 283,
  [SMALL_STATE(30)] = 293,
  [SMALL_STATE(31)] = 303,
  [SMALL_STATE(32)] = 311,
  [SMALL_STATE(33)] = 321,
  [SMALL_STATE(34)] = 331,
  [SMALL_STATE(35)] = 341,
  [SMALL_STATE(36)] = 351,
  [SMALL_STATE(37)] = 356,
  [SMALL_STATE(38)] = 361,
  [SMALL_STATE(39)] = 368,
  [SMALL_STATE(40)] = 375,
  [SMALL_STATE(41)] = 380,
  [SMALL_STATE(42)] = 385,
  [SMALL_STATE(43)] = 390,
  [SMALL_STATE(44)] = 397,
  [SMALL_STATE(45)] = 402,
  [SMALL_STATE(46)] = 407,
  [SMALL_STATE(47)] = 412,
  [SMALL_STATE(48)] = 419,
  [SMALL_STATE(49)] = 426,
  [SMALL_STATE(50)] = 433,
  [SMALL_STATE(51)] = 438,
  [SMALL_STATE(52)] = 443,
  [SMALL_STATE(53)] = 448,
  [SMALL_STATE(54)] = 452,
  [SMALL_STATE(55)] = 456,
  [SMALL_STATE(56)] = 460,
  [SMALL_STATE(57)] = 464,
  [SMALL_STATE(58)] = 468,
  [SMALL_STATE(59)] = 472,
  [SMALL_STATE(60)] = 476,
  [SMALL_STATE(61)] = 480,
  [SMALL_STATE(62)] = 484,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(3),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(38),
  [23] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(49),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_identifier, 1, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [30] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [34] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 4, 0, 1),
  [36] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 6, 0, 5),
  [38] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 6, 0, 5),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 5, 0, 3),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [44] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [46] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 5, 0, 2),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 5, 0, 3),
  [52] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 5, 0, 2),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record, 4, 0, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [58] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_parameters_repeat1, 2, 0, 0), SHIFT_REPEAT(47),
  [63] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_members_repeat1, 2, 0, 0),
  [65] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_members_repeat1, 2, 0, 0), SHIFT_REPEAT(35),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 1, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [78] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_parameters_repeat1, 2, 0, 0), SHIFT_REPEAT(43),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_parameters_repeat1, 2, 0, 0),
  [83] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [89] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_members, 1, 0, 0),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 3, 0, 0),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameters, 2, 0, 0),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_type, 1, 0, 0),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [107] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_members, 2, 0, 0),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 4, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_type, 4, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_parameters, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter_type, 5, 0, 0),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_parameter, 3, 0, 4),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_generic_identifier, 1, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_member, 4, 0, 6),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_member, 3, 0, 6),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [133] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [135] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [137] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [139] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [141] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [143] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_effekt(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
