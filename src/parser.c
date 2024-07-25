#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 35
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 15
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 1
#define MAX_ALIAS_SEQUENCE_LENGTH 5
#define PRODUCTION_ID_COUNT 2

enum ts_symbol_identifiers {
  sym_line_comment = 1,
  anon_sym_record = 2,
  anon_sym_LPAREN = 3,
  anon_sym_RPAREN = 4,
  anon_sym_COLON = 5,
  anon_sym_COMMA = 6,
  anon_sym_type = 7,
  anon_sym_LBRACE = 8,
  anon_sym_RBRACE = 9,
  anon_sym_SEMI = 10,
  anon_sym_LBRACK = 11,
  anon_sym_RBRACK = 12,
  sym_ident = 13,
  sym_generic_ident = 14,
  sym_source_file = 15,
  sym__definition = 16,
  sym_record_definition = 17,
  sym_record_field = 18,
  sym_type_definition = 19,
  sym_type_field = 20,
  sym_type = 21,
  sym__type_ident = 22,
  aux_sym_source_file_repeat1 = 23,
  aux_sym_record_definition_repeat1 = 24,
  aux_sym_type_definition_repeat1 = 25,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_line_comment] = "line_comment",
  [anon_sym_record] = "record",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [anon_sym_COLON] = ":",
  [anon_sym_COMMA] = ",",
  [anon_sym_type] = "type",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_SEMI] = ";",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [sym_ident] = "ident",
  [sym_generic_ident] = "generic_ident",
  [sym_source_file] = "source_file",
  [sym__definition] = "_definition",
  [sym_record_definition] = "record_definition",
  [sym_record_field] = "record_field",
  [sym_type_definition] = "type_definition",
  [sym_type_field] = "type_field",
  [sym_type] = "type",
  [sym__type_ident] = "_type_ident",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym_record_definition_repeat1] = "record_definition_repeat1",
  [aux_sym_type_definition_repeat1] = "type_definition_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_line_comment] = sym_line_comment,
  [anon_sym_record] = anon_sym_record,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [sym_ident] = sym_ident,
  [sym_generic_ident] = sym_generic_ident,
  [sym_source_file] = sym_source_file,
  [sym__definition] = sym__definition,
  [sym_record_definition] = sym_record_definition,
  [sym_record_field] = sym_record_field,
  [sym_type_definition] = sym_type_definition,
  [sym_type_field] = sym_type_field,
  [sym_type] = sym_type,
  [sym__type_ident] = sym__type_ident,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym_record_definition_repeat1] = aux_sym_record_definition_repeat1,
  [aux_sym_type_definition_repeat1] = aux_sym_type_definition_repeat1,
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
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
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
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [sym_ident] = {
    .visible = true,
    .named = true,
  },
  [sym_generic_ident] = {
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
  [sym_record_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_record_field] = {
    .visible = true,
    .named = true,
  },
  [sym_type_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_type_field] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__type_ident] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_record_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_type_definition_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_name = 1,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(13);
      ADVANCE_MAP(
        '(', 16,
        ')', 17,
        ',', 19,
        '/', 2,
        ':', 18,
        ';', 23,
        '[', 24,
        ']', 25,
        'r', 5,
        't', 10,
        '{', 21,
        '}', 22,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      END_STATE();
    case 1:
      if (lookahead == ')') ADVANCE(17);
      if (lookahead == ',') ADVANCE(19);
      if (lookahead == ';') ADVANCE(23);
      if (lookahead == '[') ADVANCE(24);
      if (lookahead == '}') ADVANCE(22);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 2:
      if (lookahead == '/') ADVANCE(14);
      END_STATE();
    case 3:
      if (lookahead == 'c') ADVANCE(7);
      END_STATE();
    case 4:
      if (lookahead == 'd') ADVANCE(15);
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
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(11);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
      END_STATE();
    case 12:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_line_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_record);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_COMMA);
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
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(sym_ident);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(26);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(sym_generic_ident);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(27);
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
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 11},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_line_comment] = ACTIONS(1),
    [anon_sym_record] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(24),
    [sym__definition] = STATE(3),
    [sym_record_definition] = STATE(3),
    [sym_type_definition] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [sym_line_comment] = ACTIONS(5),
    [anon_sym_record] = ACTIONS(7),
    [anon_sym_type] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      sym_line_comment,
    ACTIONS(16), 1,
      anon_sym_record,
    ACTIONS(19), 1,
      anon_sym_type,
    STATE(2), 4,
      sym__definition,
      sym_record_definition,
      sym_type_definition,
      aux_sym_source_file_repeat1,
  [19] = 5,
    ACTIONS(7), 1,
      anon_sym_record,
    ACTIONS(9), 1,
      anon_sym_type,
    ACTIONS(22), 1,
      ts_builtin_sym_end,
    ACTIONS(24), 1,
      sym_line_comment,
    STATE(2), 4,
      sym__definition,
      sym_record_definition,
      sym_type_definition,
      aux_sym_source_file_repeat1,
  [38] = 3,
    ACTIONS(26), 1,
      anon_sym_RBRACE,
    ACTIONS(28), 1,
      sym_ident,
    STATE(14), 2,
      sym_type_field,
      aux_sym_type_definition_repeat1,
  [49] = 2,
    ACTIONS(32), 1,
      anon_sym_LBRACK,
    ACTIONS(30), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_ident,
  [58] = 3,
    ACTIONS(34), 1,
      anon_sym_RPAREN,
    ACTIONS(36), 1,
      sym_ident,
    STATE(9), 2,
      sym_record_field,
      aux_sym_record_definition_repeat1,
  [69] = 3,
    ACTIONS(28), 1,
      sym_ident,
    ACTIONS(38), 1,
      anon_sym_RBRACE,
    STATE(4), 2,
      sym_type_field,
      aux_sym_type_definition_repeat1,
  [80] = 1,
    ACTIONS(40), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [87] = 3,
    ACTIONS(36), 1,
      sym_ident,
    ACTIONS(42), 1,
      anon_sym_RPAREN,
    STATE(12), 2,
      sym_record_field,
      aux_sym_record_definition_repeat1,
  [98] = 1,
    ACTIONS(44), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [105] = 1,
    ACTIONS(46), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [112] = 3,
    ACTIONS(48), 1,
      anon_sym_RPAREN,
    ACTIONS(50), 1,
      sym_ident,
    STATE(12), 2,
      sym_record_field,
      aux_sym_record_definition_repeat1,
  [123] = 1,
    ACTIONS(53), 4,
      ts_builtin_sym_end,
      sym_line_comment,
      anon_sym_record,
      anon_sym_type,
  [130] = 3,
    ACTIONS(55), 1,
      anon_sym_RBRACE,
    ACTIONS(57), 1,
      sym_ident,
    STATE(14), 2,
      sym_type_field,
      aux_sym_type_definition_repeat1,
  [141] = 1,
    ACTIONS(60), 3,
      anon_sym_RPAREN,
      anon_sym_COMMA,
      sym_ident,
  [147] = 2,
    ACTIONS(64), 1,
      anon_sym_SEMI,
    ACTIONS(62), 2,
      anon_sym_RBRACE,
      sym_ident,
  [155] = 2,
    ACTIONS(68), 1,
      anon_sym_COMMA,
    ACTIONS(66), 2,
      anon_sym_RPAREN,
      sym_ident,
  [163] = 1,
    ACTIONS(70), 2,
      anon_sym_RBRACE,
      sym_ident,
  [168] = 2,
    ACTIONS(72), 1,
      sym_ident,
    STATE(32), 1,
      sym__type_ident,
  [175] = 1,
    ACTIONS(74), 2,
      anon_sym_RPAREN,
      sym_ident,
  [180] = 2,
    ACTIONS(72), 1,
      sym_ident,
    STATE(17), 1,
      sym__type_ident,
  [187] = 2,
    ACTIONS(76), 1,
      sym_ident,
    STATE(26), 1,
      sym_type,
  [194] = 1,
    ACTIONS(78), 1,
      anon_sym_COLON,
  [198] = 1,
    ACTIONS(80), 1,
      ts_builtin_sym_end,
  [202] = 1,
    ACTIONS(82), 1,
      anon_sym_COLON,
  [206] = 1,
    ACTIONS(84), 1,
      anon_sym_RPAREN,
  [210] = 1,
    ACTIONS(86), 1,
      sym_generic_ident,
  [214] = 1,
    ACTIONS(88), 1,
      sym_ident,
  [218] = 1,
    ACTIONS(90), 1,
      anon_sym_LPAREN,
  [222] = 1,
    ACTIONS(92), 1,
      sym_ident,
  [226] = 1,
    ACTIONS(94), 1,
      anon_sym_RBRACK,
  [230] = 1,
    ACTIONS(96), 1,
      anon_sym_RPAREN,
  [234] = 1,
    ACTIONS(98), 1,
      anon_sym_LBRACE,
  [238] = 1,
    ACTIONS(100), 1,
      anon_sym_LPAREN,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 19,
  [SMALL_STATE(4)] = 38,
  [SMALL_STATE(5)] = 49,
  [SMALL_STATE(6)] = 58,
  [SMALL_STATE(7)] = 69,
  [SMALL_STATE(8)] = 80,
  [SMALL_STATE(9)] = 87,
  [SMALL_STATE(10)] = 98,
  [SMALL_STATE(11)] = 105,
  [SMALL_STATE(12)] = 112,
  [SMALL_STATE(13)] = 123,
  [SMALL_STATE(14)] = 130,
  [SMALL_STATE(15)] = 141,
  [SMALL_STATE(16)] = 147,
  [SMALL_STATE(17)] = 155,
  [SMALL_STATE(18)] = 163,
  [SMALL_STATE(19)] = 168,
  [SMALL_STATE(20)] = 175,
  [SMALL_STATE(21)] = 180,
  [SMALL_STATE(22)] = 187,
  [SMALL_STATE(23)] = 194,
  [SMALL_STATE(24)] = 198,
  [SMALL_STATE(25)] = 202,
  [SMALL_STATE(26)] = 206,
  [SMALL_STATE(27)] = 210,
  [SMALL_STATE(28)] = 214,
  [SMALL_STATE(29)] = 218,
  [SMALL_STATE(30)] = 222,
  [SMALL_STATE(31)] = 226,
  [SMALL_STATE(32)] = 230,
  [SMALL_STATE(33)] = 234,
  [SMALL_STATE(34)] = 238,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [13] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(2),
  [16] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(28),
  [19] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(30),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [24] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [26] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [28] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [30] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_ident, 1, 0, 0),
  [32] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [34] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [36] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [38] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [40] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_definition, 4, 0, 1),
  [42] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_definition, 4, 0, 1),
  [46] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_definition, 5, 0, 1),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_record_definition_repeat1, 2, 0, 0),
  [50] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_record_definition_repeat1, 2, 0, 0), SHIFT_REPEAT(23),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_definition, 5, 0, 1),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_type_definition_repeat1, 2, 0, 0),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_type_definition_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [60] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__type_ident, 4, 0, 0),
  [62] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_field, 4, 0, 0),
  [64] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_field, 3, 0, 0),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_field, 5, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_record_field, 4, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [80] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [86] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [88] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [90] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [92] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [94] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [96] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 3, 0, 0),
  [98] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [100] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
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
