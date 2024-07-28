module.exports = grammar({
  name: "effekt",

  keyword: ($) =>
    choice(
      "record",
      "type",
      "interface",
      "def",
      "if",
      "else",
      "match",
      "case",
      "with",
      "do",
      "while",
      "val",
      "var",
    ),

  precedences: ($) => [
    ["match", "assignment"],
    ["multiplication", "addition"],
    ["statement", "expression"],
    ["function_call", "expression"],
    ["function_call", "constructor"],
    ["function_call", "identifier"],
    ["constructor_call", "tuple"],
  ],

  rules: {
    source_file: ($) => repeat($._definition),

    _definition: ($) =>
      choice(
        $.line_comment,
        $.record,
        $.type,
        $.function,
        $.interface,
        $.effect,
        $.effect_alias,
      ),

    line_comment: ($) => token(seq("//", /.*/)),

    record: ($) =>
      seq(
        "record",
        $.parameter_type,
        "(",
        optional(field("members", $.parameters)),
        ")",
      ),

    _type_parameters: ($) => seq("[", commaSep1($.generic_identifier), "]"),

    parameters: ($) => commaSep1($.parameter),

    parameter: ($) =>
      seq(field("name", $.identifier), ":", field("kind", $.parameter_type)),

    parameter_type: ($) => seq($.type_identifier, optional($._type_parameters)),

    type: ($) =>
      seq("type", $.parameter_type, choice($._simple_type, $._complex_type)),

    _simple_type: ($) => seq("=", $.parameter_type),
    _complex_type: ($) =>
      seq("{", optional(field("members", $.type_members)), "}"),

    type_members: ($) => semilicolonSep1($.type_member),

    type_member: ($) =>
      seq(field("member", $.type_identifier), "(", optional($.parameters), ")"),

    // TODO: rewrite block parameters
    function: ($) =>
      seq(
        "def",
        field("name", $.identifier),
        optional(field("_type_parameters", $._type_parameters)),
        "(",
        optional(field("parameters", $.parameters)),
        ")",
        optional(field("block_parameters", $.block_parameters)),
        optional(seq(":", field("return_type", $.return_type))),
        "=",
        field("body", $._expression),
      ),

    // todo rewrite block parameters to allow for higher order functions
    block_parameters: ($) => seq("{", $.parameters, "}"),

    return_type: ($) =>
      seq($.parameter_type, optional(field("effects", $.effects))),

    effects: ($) => seq("/", "{", commaSep1($.type_identifier), "}"),

    interface: ($) =>
      seq(
        "interface",
        field("name", $.type_identifier),
        "{",
        optional(field("members", $.interface_methods)),
        "}",
      ),

    interface_methods: ($) => repeat1($.interface_method),

    interface_method: ($) =>
      seq(
        "def",
        field("name", $.identifier),
        optional(field("_type_parameters", $._type_parameters)),
        "(",
        optional(field("parameters", $.parameters)),
        ")",
        optional(field("block_parameters", $.block_parameters)),
        optional(seq(":", field("return_type", $.return_type))),
      ),

    effect: ($) =>
      seq(
        "effect",
        $.parameter_type,
        optional(seq("(", optional(field("parameters", $.parameters)), ")")),
        optional(seq(":", field("return_type", $.return_type))),
      ),

    effect_alias: ($) =>
      seq(
        "effect",
        $.parameter_type,
        "=",
        "{",
        field("effects", commaSep($.parameter_type)),
        "}",
      ),

    _expression: ($) =>
      prec(
        "expression",
        choice(
          $.block,
          $.number,
          $.boolean,
          $.tuple_expression,
          $.match_expression,
          $.function_call,
          $.constructor,
          $._identifier,
          $.string,
          $.array,
          $.assignment,
          $.binary_expression,
          $.unary_expression,
          $.not_implemented,
          $.call_chain,
        ),
      ),

    _identifier: ($) => prec("identifier", $.identifier),

    binary_expression: ($) =>
      choice(
        prec.left(1, seq($._expression, "and", $._expression)),
        prec.left(2, seq($._expression, "is", $._expression)),
        prec.left("addition", seq($._expression, "+", $._expression)),
        prec.left("addition", seq($._expression, "-", $._expression)),
        prec.left("multiplication", seq($._expression, "*", $._expression)),
        prec.left("multiplication", seq($._expression, "/", $._expression)),
      ),

    unary_expression: ($) => prec.right(seq("do", $._expression)),

    statement: ($) =>
      prec(
        "statement",
        choice($.assignment, $.while_expression, $.expression_statement),
      ),

    expression_statement: ($) => $._expression,

    assignment: ($) =>
      prec.left(
        "assignment",
        seq(
          choice("val", "var"),
          choice($.identifier, $.tuple_identifier),
          "=",
          $._expression,
        ),
      ),

    tuple_identifier: ($) => seq("(", commaSep1($.identifier), ")"),

    while_expression: ($) => seq("while", $._expression, $.block),

    match_expression: ($) =>
      prec.left(
        "match",
        seq(
          field("value", $._expression),
          "match",
          "{",
          repeat1($.case_clause),
          "}",
        ),
      ),

    case_clause: ($) =>
      seq(
        "case",
        field("pattern", $._pattern),
        "=>",
        field("body", $._expression),
      ),

    _pattern: ($) =>
      choice(
        $.number,
        $.boolean,
        $.string,
        $.identifier,
        $.wildcard_pattern,
        $.tuple_pattern,
        $.constructor_pattern,
      ),

    wildcard_pattern: ($) => "_",

    tuple_pattern: ($) => seq("(", commaSep1($._pattern), ")"),

    constructor_pattern: ($) =>
      seq(
        field("constructor", $.type_identifier),
        "(",
        optional(commaSep1($._pattern)),
        ")",
      ),

    block: ($) => seq("{", repeat($.statement), "}"),

    tuple_expression: ($) =>
      prec("tuple", seq("(", commaSep1($._expression), ")")),

    constructor: ($) =>
      prec(
        "constructor",
        seq(
          field("name", $.type_identifier),
          "(",
          optional(commaSep($.argument)),
          ")",
        ),
      ),

    function_call: ($) =>
      prec.left(
        "function_call",
        seq(
          field("function", $.function_identifier),
          choice(
            seq("(", optional(commaSep($.argument)), ")"),
            repeat1($.block),
          ),
        ),
      ),

    call_chain: ($) => seq($.identifier, repeat1(seq(".", $.function_call))),

    argument: ($) => $._expression,

    string: ($) => /"([^"\\]|\\.)*"/,

    array: ($) => seq("[", optional(commaSep($._expression)), "]"),

    not_implemented: ($) => token(seq("<", ">")),

    number: ($) => token(/\d+/),

    boolean: ($) => choice(token("true"), token("false")),

    generic_identifier: ($) => /[A-Za-z][a-zA-Z0-9_]*/,
    type_identifier: ($) => /[A-Z][a-zA-Z0-9_]*/,
    identifier: ($) => /[A-za-z][a-zA-Z0-9_]*/,
    function_identifier: ($) => /[a-z][a-zA-Z0-9_]*/,
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

function trailingSep1(delimiter, rule) {
  return seq(sep1(delimiter, rule), optional(delimiter));
}

function sep1(delimiter, rule) {
  return seq(rule, repeat(seq(delimiter, rule)));
}
