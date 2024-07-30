const PREC = {
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
  // TODO: Rewrite for removal
  precedences: ($) => [
    ["match", "assignment"],
    ["multiplication", "addition"],
    ["statement", "expression"],
    ["function_call", "expression"],
    ["function_call", "constructor"],
    ["function_call", "identifier"],
    ["constructor_call", "tuple"],
    ["function_call", "pre_arg_function_call"],
  ],

  // supertypes that include a lot of other tokens
  //supertypes: ($) => [$._expression],

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
      ),

    expression_statement: ($) =>
      choice($._expression, prec(1, $._expression_ending_with_block)),

    _expression_ending_with_block: ($) =>
      choice(
        $.block,
        //$.if_expression,
        //$.match_expression,
        //$.try_expression,
        //$.while_expression,
      ),

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
      seq("(", sepBy(",", choice($.parameter, $._type)), optional(","), ")"),

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
      seq(
        $._type_identifier,
        field("type_parameters", optional($.type_parameters)),
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

    _expression: ($) => choice($.hole),

    hole: ($) => "<>",

    block: ($) => seq("{", repeat($._statement), "}"),

    // === section - patterns ===
    _pattern: ($) => choice($.identifier),

    // ======================== old ========================

    // _definition: ($) =>
    //   choice(
    //     $.comment,
    //     $.record_item,
    //     $.type_item,
    //     $.function_item,
    //     $.interface_item,
    //     $.effect_item,
    //     $.effect_alias_item,
    //   ),

    // // @deprecated
    // _type_parameters: ($) => seq("[", commaSep1($.generic_identifier), "]"),

    // parameters: ($) => commaSep1($.parameter),

    // parameter: ($) =>
    //   seq(
    //     field("name", $.identifier),
    //     ":",
    //     field("kind", choice($.parameter_type, $.tuple_parameter_type)),
    //   ),

    // parameter_type: ($) => seq($.type_identifier, optional($._type_parameters)),

    // tuple_parameter_type: ($) => seq("(", commaSep1($.parameter_type), ")"),

    // type_item: ($) =>
    //   seq("type", $.parameter_type, choice($._simple_type, $._complex_type)),

    // _simple_type: ($) => seq("=", $.parameter_type),
    // _complex_type: ($) =>
    //   seq("{", optional(field("members", $.type_item_members)), "}"),

    // type_item_members: ($) => semilicolonSep1($.type_item_member),

    // type_item_member: ($) =>
    //   seq(field("member", $.type_identifier), "(", optional($.parameters), ")"),

    // // TODO: rewrite block parameters
    // function_item: ($) =>
    //   seq(
    //     "def",
    //     field("name", $.identifier),
    //     optional(field("_type_parameters", $._type_parameters)),
    //     "(",
    //     optional(field("parameters", $.parameters)),
    //     ")",
    //     optional(field("block_parameters", $.block_parameters)),
    //     optional(seq(":", field("return_type", $.return_type))),
    //     "=",
    //     field("body", $._expression),
    //   ),

    // // todo rewrite block parameters to allow for higher order functions
    // block_parameters: ($) => seq("{", $.parameters, "}"),

    // return_type: ($) =>
    //   seq($.parameter_type, optional(field("effects", $.effects))),

    // effects: ($) => seq("/", "{", commaSep1($.type_identifier), "}"),

    // interface_item: ($) =>
    //   seq(
    //     "interface",
    //     $.parameter_type,
    //     "{",
    //     optional(field("members", $.interface_methods)),
    //     "}",
    //   ),

    // interface_methods: ($) => repeat1($.interface_method),

    // interface_method: ($) =>
    //   seq(
    //     "def",
    //     field("name", $.identifier),
    //     optional(field("_type_parameters", $._type_parameters)),
    //     "(",
    //     optional(field("parameters", $.parameters)),
    //     ")",
    //     optional(field("block_parameters", $.block_parameters)),
    //     optional(seq(":", field("return_type", $.return_type))),
    //   ),

    // effect_item: ($) =>
    //   seq(
    //     "effect",
    //     $.parameter_type,
    //     optional(seq("(", optional(field("parameters", $.parameters)), ")")),
    //     optional(seq(":", field("return_type", $.return_type))),
    //   ),

    // effect_alias_item: ($) =>
    //   seq(
    //     "effect",
    //     $.parameter_type,
    //     "=",
    //     "{",
    //     field("effects", commaSep($.parameter_type)),
    //     "}",
    //   ),

    // _expression: ($) =>
    //   prec(
    //     "expression",
    //     choice(
    //       $.block,
    //       $.number,
    //       $.boolean,
    //       $.tuple_expression,
    //       $.match_expression,
    //       $.try_expression,
    //       $.if_expression,
    //       $.function_call,
    //       $.constructor,
    //       $._identifier,
    //       $.string,
    //       $.array,
    //       $.assignment,
    //       $.binary_expression,
    //       $.unary_expression,
    //       $.not_implemented,
    //       $.resume,
    //       $.call_chain,
    //     ),
    //   ),

    // _identifier: ($) => prec("identifier", $.identifier),

    // binary_expression: ($) =>
    //   choice(
    //     prec.left(1, seq($._expression, "and", $._expression)),
    //     prec.left(2, seq($._expression, "is", $._expression)),
    //     prec.left("addition", seq($._expression, "+", $._expression)),
    //     prec.left("addition", seq($._expression, "-", $._expression)),
    //     prec.left("multiplication", seq($._expression, "*", $._expression)),
    //     prec.left("multiplication", seq($._expression, "/", $._expression)),
    //   ),

    // unary_expression: ($) => prec.right(seq("do", $._expression)),

    // statement: ($) =>
    //   prec(
    //     "statement",
    //     choice(
    //       $.assignment,
    //       $.while_expression,
    //       $.expression_statement,
    //       $.function_item,
    //     ),
    //   ),

    // resume: ($) => seq("resume", "(", $._expression, ")"),

    // assignment: ($) =>
    //   prec.left(
    //     "assignment",
    //     seq(
    //       choice("val", "var"),
    //       choice($.identifier, $.tuple_identifier),
    //       "=",
    //       $._expression,
    //     ),
    //   ),

    // tuple_identifier: ($) => seq("(", commaSep1($.identifier), ")"),

    // while_expression: ($) => seq("while", "(", $._expression, ")", $.block),

    // if_expression: ($) =>
    //   seq(
    //     "if",
    //     "(",
    //     $._expression,
    //     ")",
    //     $.block,
    //     optional(choice($.if_else_expression, $.else_expression)),
    //   ),

    // if_else_expression: ($) =>
    //   seq(
    //     "if",
    //     "else",
    //     "(",
    //     $._expression,
    //     ")",
    //     $.block,
    //     optional(choice($.if_else_expression, $.else_expression)),
    //   ),

    // else_expression: ($) => seq("else", $.block),

    // match_expression: ($) =>
    //   prec.left(
    //     "match",
    //     seq(
    //       field("value", $._expression),
    //       "match",
    //       "{",
    //       repeat1($.case_clause),
    //       "}",
    //     ),
    //   ),

    // case_clause: ($) =>
    //   seq(
    //     "case",
    //     field("pattern", $._pattern),
    //     "=>",
    //     field("body", $._expression),
    //   ),

    // _pattern: ($) =>
    //   choice(
    //     $.number,
    //     $.boolean,
    //     $.string,
    //     $.identifier,
    //     $.wildcard_pattern,
    //     $.tuple_pattern,
    //     $.constructor_pattern,
    //   ),

    // wildcard_pattern: ($) => "_",

    // tuple_pattern: ($) => seq("(", commaSep1($._pattern), ")"),

    // constructor_pattern: ($) =>
    //   seq(
    //     field("constructor", $.type_identifier),
    //     "(",
    //     optional(commaSep1($._pattern)),
    //     ")",
    //   ),

    // block: ($) => seq("{", optSemicolonNewlineSep($.statement), "}"),

    // tuple_expression: ($) =>
    //   prec("tuple", seq("(", commaSep1($._expression), ")")),

    // constructor: ($) =>
    //   prec(
    //     "constructor",
    //     seq(
    //       field("name", $.type_identifier),
    //       "(",
    //       optional(commaSep($.argument)),
    //       ")",
    //     ),
    //   ),

    // function_call: ($) =>
    //   prec.left(
    //     "function_call",
    //     seq(
    //       field("function", $.identifier),
    //       choice(
    //         seq("(", optional(commaSep($.argument)), ")"),
    //         repeat1($.block),
    //       ),
    //     ),
    //   ),

    // try_expression: ($) => seq("try", $.block, repeat1($.with_handler)),

    // with_handler: ($) =>
    //   seq(
    //     "with",
    //     $.parameter_type,
    //     "{",
    //     choice($.anonymous_function, repeat1($.handler_function)),
    //     "}",
    //   ),

    // handler_function: ($) =>
    //   seq(
    //     "def",
    //     $.identifier,
    //     optional(field("_type_parameters", $._type_parameters)),
    //     "(",
    //     optional(field("parameters", $.handler_function_parameters)),
    //     ")",
    //     "=",
    //     $._expression,
    //   ),

    // anonymous_function: ($) =>
    //   seq(
    //     "(",
    //     optional($.handler_function_parameters),
    //     ")",
    //     "=>",
    //     $._expression,
    //   ),

    // handler_function_parameters: ($) =>
    //   commaSep1(seq($.identifier, optional(seq(":", $.parameter_type)))),

    // call_chain: ($) =>
    //   seq(
    //     $.identifier,
    //     repeat1(seq(".", choice($.function_call, $.pre_arg_function_call))),
    //   ),

    // pre_arg_function_call: ($) => prec("pre_arg_function_call", $.identifier),

    // argument: ($) => $._expression,

    // string: ($) => /"([^"\\]|\\.)*"/,

    // array: ($) => seq("[", optional(commaSep($._expression)), "]"),

    // not_implemented: ($) => token(seq("<", ">")),

    // number: ($) => token(/[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?/),

    // boolean: ($) => choice(token("true"), token("false")),

    // generic_identifier: ($) => /[A-Za-z][a-zA-Z0-9_]*/,
    // type_identifier: ($) => /[A-Z][a-zA-Z0-9_]*/,

    identifier: ($) => /(r#)?[_\p{XID_Start}][_\p{XID_Continue}]*/,

    _type_identifier: ($) => alias($.identifier, $.type_identifier),
    _field_identifier: ($) => alias($.identifier, $.field_identifier),
  },
});

function commaSep(rule) {
  return optional(commaSep1(rule));
}

function commaSep1(rule) {
  return sep1(",", rule);
}

function trailingCommaSep(rule) {
  return optional(trailingCommaSep1(rule));
}

function trailingCommaSep1(rule) {
  return trailingSep1(",", rule);
}

function semilicolonSep1(rule) {
  return sep1(";", rule);
}

function optSemicolonNewlineSep(rule) {
  return optional(semilicolonSep1(rule));
}

function semicolonNewlineSep(rule) {
  return sep1(choice(";", /(\n)/), rule);
}

function trailingSep1(delimiter, rule) {
  return seq(sep1(delimiter, rule), optional(delimiter));
}

function sep1(delimiter, rule) {
  return seq(rule, repeat(seq(delimiter, rule)));
}

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
