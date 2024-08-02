const PREC = {
  constructor: 10,
  call: 9,
  field: 8,
  try: 7,
  unary: 6,
  multiplicative: 5,
  additive: 4,
  comparative: 3,
  and: 2,
  or: 1,
  assign: 0,
  closure: -1,
};

const primitiveTypes = [
  "Unit",
  "Bool",
  "Int",
  "Double",
  "String",
  "Char",
  "Byte",
  "Any",
  "Nothing",
  "IO",
];

const PUNCTUATION = ["+", "-", "*", "/", ";", ":", "=>"];

module.exports = grammar({
  name: "effekt",

  // can be used anywhere in the grammar
  extras: ($) => [/\s/, $.comment],

  // used for keyword extraction
  word: ($) => $.identifier,

  // local precedence rules
  precedences: ($) => [],

  // supertypes that include a lot of other tokens
  supertypes: ($) => [
    $._expression,
    $._literal,
    $._type,
    $._declaration_statement,
  ],

  // conflicts to be resolved at runtime using multiple stacks.
  // The first rule is prefered over the second one
  conflicts: ($) => [[$.function_item]],

  // external scanners to be used
  externals: ($) => [],

  inline: ($) => [$._expression_ending_with_block],

  // grammar rules
  rules: {
    // entry point
    source_file: ($) => repeat($._statement),

    // https://stackoverflow.com/questions/13014947/regex-to-match-a-c-style-multiline-comment/36328890#36328890
    comment: (_) =>
      token(
        choice(
          seq("//", /[^\r\n\u2028\u2029]*/),
          seq("/*", /[^*]*\*+([^/*][^*]*\*+)*/, "/"),
        ),
      ),

    _statement: ($) => choice($.expression_statement, $._declaration_statement),

    _declaration_statement: ($) =>
      choice(
        $.record_item,
        $.type_item,
        $.interface_item,
        $.effect_item,
        $.function_item,
        $.import_declaration,
        $.val_declaration,
        $.var_declaration,
      ),

    expression_statement: ($) =>
      choice($._expression, prec(1, $._expression_ending_with_block)),

    // === section - declarations ===

    record_item: ($) =>
      seq(
        "record",
        field("name", $._type_identifier),
        field("type_parameters", optional($.type_parameters)),
        field("body", $.field_item_list),
      ),

    type_parameters: ($) =>
      prec(1, seq("[", sepBy1(",", $._type_identifier), optional(","), "]")),

    field_item_list: ($) =>
      seq("(", sepBy(",", $.field_declaration), optional(","), ")"),

    field_declaration: ($) =>
      seq(field("name", $._field_identifier), ":", field("type", $._type)),

    type_item: ($) =>
      seq(
        "type",
        field("name", $._type_identifier),
        field("type_parameters", optional($.type_parameters)),
        choice(
          field("assignment", $.type_assignment),
          field("body", $.type_variant_list),
        ),
      ),

    type_assignment: ($) => seq("=", $._type),

    type_variant_list: ($) =>
      seq("{", sepBy(";", $.type_variant), optional(";"), "}"),

    type_variant: ($) =>
      seq(
        field("name", $._type_identifier),
        field("type_parameters", optional($.type_parameters)),
        field("body", $.field_item_list),
      ),

    interface_item: ($) =>
      seq(
        "interface",
        field("name", $._type_identifier),
        field("type_parameters", optional($.type_parameters)),
        field("body", $.declaration_list),
      ),

    declaration_list: ($) => seq("{", repeat($._declaration_statement), "}"),

    effect_item: ($) =>
      seq(
        "effect",
        field("name", $._type_identifier),
        field("type_parameters", optional($.type_parameters)),
        choice(
          seq(
            field("parameters", $.parameters),
            field("return_type", $.return_type),
          ),
          seq("=", field("alias", $.effect_alias_list)),
        ),
      ),

    effect_alias_list: ($) =>
      seq("{", sepBy(",", alias($._type, $.effect_alias)), "}"),

    function_item: ($) =>
      seq(
        "def",
        field("name", $.identifier),
        field("type_parameters", optional($.type_parameters)),
        choice(
          seq(
            field("parameters", $.parameters),
            field("block_parameter", repeat($.block_parameter)),
          ),
          field("block_parameter", repeat1($.block_parameter)),
        ),
        optional(field("return_type", $.return_type)),
        optional(seq("=", field("body", $.expression_statement))),
      ),

    parameters: ($) =>
      seq("(", sepBy(",", choice($.parameter, $._pattern)), optional(","), ")"),

    parameter: ($) =>
      seq(field("pattern", $._pattern), ":", field("type", $._type)),

    block_parameter: ($) =>
      seq(
        "{",
        field("name", $.identifier),
        ":",
        field("type", $._type),
        "=>",
        field("return_type", $.return_type),
        "}",
      ),

    return_type: ($) =>
      seq(":", field("type", $._type), field("effects", optional($.effects))),

    effects: ($) =>
      seq("/", choice(seq("{", sepBy(",", $.effect), "}"), $.effect)),

    effect: ($) =>
      prec.right(
        seq(
          $._type_identifier,
          field("type_parameters", optional($.type_parameters)),
        ),
      ),

    val_declaration: ($) =>
      seq(
        "val",
        field("name", $.identifier),
        "=",
        field("value", $._expression),
      ),

    var_declaration: ($) =>
      seq(
        "var",
        field("name", $.identifier),
        "=",
        field("value", $._expression),
      ),

    import_declaration: ($) => seq("import", field("path", $.path)),

    path: ($) => sepBy1("/", $.path_segment),

    path_segment: ($) => /[a-zA-Z0-9_]+/,

    // === section - type ===

    _type: ($) =>
      choice(
        //    $.function_type,
        $.generic_type,
        $.tuple_type,
        $.unit_type,
        $._type_identifier,
        alias(choice(...primitiveTypes), $.primitive_type),
      ),

    unit_type: ($) => seq("(", ")"),

    tuple_type: ($) => seq("(", sepBy1(",", $._type), optional(","), ")"),

    generic_type: ($) =>
      prec(
        1,
        seq(
          $._type_identifier,
          field("type_arguments", alias($.type_parameters, $.type_arguments)),
        ),
      ),

    // === section - expressions ===

    _expression: ($) =>
      choice(
        $.hole,
        $.unit_expression,
        $.unary_expression,
        $.constructor_expression,
        $.binary_expression,
        $.assignment_expression,
        $.call_expression,
        $.resume_expression,
        $.do_expression,
        $._literal,
        prec.left($.identifier),
        $.list_expression,
        $.tuple_expression,
        $.field_expression,
        $._expression_ending_with_block,
      ),

    hole: ($) => "<>",
    unit_expression: ($) => seq("(", ")"),

    unary_expression: ($) =>
      prec(PREC.unary, seq(choice("-", "!"), $._expression)),

    // https://github.com/tree-sitter/tree-sitter-rust/blob/master/grammar.js#L1024
    binary_expression: ($) => {
      const table = [
        [PREC.and, "and"],
        [PREC.or, "or"],
        [PREC.comparative, choice("==", "!=", "<", "<=", ">", ">=")],
        [PREC.additive, choice("+", "-", "++")],
        [PREC.multiplicative, choice("*", "/", "%")],
      ];

      return choice(
        ...table.map(([precedence, operator]) =>
          prec.left(
            precedence,
            seq(
              field("left", $._expression),
              field("operator", operator),
              field("right", $._expression),
            ),
          ),
        ),
      );
    },

    assignment_expression: ($) =>
      prec.left(
        PREC.assign,
        seq(field("left", $._expression), "=", field("right", $._expression)),
      ),

    call_expression: ($) =>
      prec(
        PREC.call,
        prec.right(
          seq(
            field("function", $._expression),
            field(
              "arguments",
              choice(
                seq($.arguments, repeat($.block_argument)),
                repeat1($.block_argument),
              ),
            ),
          ),
        ),
      ),

    constructor_expression: ($) =>
      prec(
        PREC.constructor,
        seq(
          field(
            "constructor",
            alias($._constructor_identifier, $._type_identifier),
          ),
          field("type_parameters", optional($.type_parameters)),
          field("arguments", $.arguments),
        ),
      ),

    arguments: ($) =>
      choice(seq("(", sepBy(",", $._expression), optional(","), ")")),

    block_argument: ($) =>
      seq("{", $.parameters, "=>", sepBy(",", $._expression), "}"),

    do_expression: ($) => prec.left(seq("do", $._expression)),

    list_expression: ($) =>
      seq("[", seq(sepBy(",", $._expression), optional(",")), "]"),

    tuple_expression: ($) =>
      seq("(", seq(sepBy1(",", $._expression), optional(",")), ")"),

    field_expression: ($) =>
      prec(
        PREC.field,
        seq(
          field("value", $._expression),
          ".",
          field("field", $._field_identifier),
        ),
      ),

    resume_expression: ($) =>
      prec(
        PREC.call,
        choice(
          seq("resume", "(", field("value", $._expression), ")"),
          seq(field("value", $._expression), ".", "resume"),
        ),
      ),

    // === section - block ===

    _expression_ending_with_block: ($) =>
      choice(
        $.block,
        $.if_expression,
        $.while_expression,
        $.try_expression,
        $.match_expression,
      ),

    block: ($) => seq("{", repeat(seq($._statement, optional(";"))), "}"),

    if_expression: ($) =>
      prec.right(
        seq(
          "if",
          field("condition", $._condition),
          field("block", $.block),
          repeat(field("if_else_clause", $.if_else_clause)),
          optional(field("else_clause", $.else_clause)),
        ),
      ),

    _condition: ($) => seq("(", $._expression, ")"),

    if_else_clause: ($) =>
      seq(
        "if",
        "else",
        field("condition", $._condition),
        field("block", $.block),
      ),

    else_clause: ($) => seq("else", field("block", $.block)),

    while_expression: ($) =>
      seq("while", field("condition", $._condition), field("block", $.block)),

    try_expression: ($) =>
      seq(
        "try",
        field("block", $.block),
        field("with_clause", repeat($.with_clause)),
      ),

    with_clause: ($) =>
      seq(
        "with",
        field("name", $._type_identifier),
        field("type_parameter", optional($.type_parameters)),
        field("block", choice($.function_list, $.block_argument)),
      ),

    function_list: ($) => seq("{", repeat($.function_item), "}"),

    match_expression: ($) =>
      seq(field("value", $._expression), "match", field("body", $.match_block)),

    match_block: ($) => seq("{", repeat($.match_arm), "}"),

    match_arm: ($) =>
      seq(
        "case",
        field("pattern", $.match_pattern),
        "=>",
        field("value", $._expression),
        optional(","),
      ),

    match_pattern: ($) =>
      seq($._pattern, optional(seq("if", field("condition", $._condition)))),

    // === section - patterns ===

    _pattern: ($) =>
      choice($._literal_pattern, $.identifier, $.tuple_pattern, $.list_pattern),

    tuple_pattern: ($) => seq("(", sepBy(",", $._pattern), optional(","), ")"),

    list_pattern: ($) => seq("[", sepBy(",", $._pattern), optional(","), "]"),

    _literal_pattern: ($) =>
      choice(
        $.string_literal,
        $.integer_literal,
        $.float_literal,
        $.boolean_literal,
        $.negative_literal,
      ),

    // === section - literals ===

    _literal: ($) =>
      choice(
        $.string_literal,
        $.integer_literal,
        $.float_literal,
        $.boolean_literal,
      ),

    negative_literal: ($) =>
      seq("-", choice($.integer_literal, $.float_literal)),

    float_literal: ($) =>
      token(
        prec.left(
          seq(
            choice(/[0-9][0-9_]*/, optional(seq(".", /[0-9][0-9_]*/))),
            seq(".", /[0-9][0-9_]*/),
          ),
        ),
      ),

    // https://github.com/tree-sitter/tree-sitter-rust/blob/master/grammar.js#L1470
    // not sure if this is necessary in effekt, but it's good to have it for syntax highlighting anyway
    integer_literal: (_) =>
      token(
        seq(choice(/[0-9][0-9_]*/, /0x[0-9a-fA-F_]+/, /0b[01_]+/, /0o[0-7_]+/)),
      ),

    string_literal: ($) => /"([^"\\]|\\.)*"/,

    boolean_literal: (_) => choice("true", "false"),

    identifier: ($) => /[_\p{XID_Start}][_\p{XID_Continue}]*/,

    _constructor_identifier: ($) => /[A-Z][_\p{XID_Continue}]*/,

    _type_identifier: ($) => alias($.identifier, $.type_identifier),
    _field_identifier: ($) => alias($.identifier, $.field_identifier),
  },
});

/**
 * Creates a rule to match one or more of the rules separated by the separator.
 *
 * @param {RuleOrLiteral} sep - The separator to use.
 * @param {RuleOrLiteral} rule
 *
 * @return {SeqRule}
 *
 */
function sepBy1(sep, rule) {
  return seq(rule, repeat(seq(sep, rule)));
}

/**
 * Creates a rule to optionally match one or more of the rules separated by the separator.
 *
 * @param {RuleOrLiteral} sep - The separator to use.
 * @param {RuleOrLiteral} rule
 *
 * @return {ChoiceRule}
 *
 */
function sepBy(sep, rule) {
  return optional(sepBy1(sep, rule));
}
