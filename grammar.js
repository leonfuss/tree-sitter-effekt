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
    ),

  precedences: (_) => [["multiplication", "addition"]],

  rules: {
    source_file: ($) => repeat($._definition),

    _definition: ($) =>
      choice($.line_comment, $.record, $.type, $.function, $.interface),

    line_comment: ($) => token(seq("//", /.*/)),

    record: ($) =>
      seq(
        "record",
        field("name", $.type_identifier),
        optional(field("parameters", $.type_parameters)),
        "(",
        optional(field("members", $.parameters)),
        ")",
      ),

    // Record the type parameters
    type_parameters: ($) => seq("[", commaSep1($.generic_identifier), "]"),

    // Define parameter list with possible trailing comma
    parameters: ($) => trailingCommaSep1($.parameter),

    // Define a parameter
    parameter: ($) =>
      seq(field("name", $.identifier), ":", field("kind", $.parameter_type)),

    // Define parameter type which may include generic arguments
    parameter_type: ($) =>
      seq(
        $.type_identifier,
        optional(seq("[", commaSep1($.generic_identifier), "]")),
      ),

    type: ($) =>
      seq(
        "type",
        field("name", $.type_identifier),
        optional(field("parameters", $.type_parameters)),
        "{",
        optional(field("members", $.type_members)),
        "}",
      ),

    type_members: ($) => semilicolonSep1($.type_member),

    type_member: ($) =>
      seq(field("member", $.type_identifier), "(", optional($.parameters), ")"),

    function: ($) =>
      seq(
        "def",
        field("name", $.identifier),
        optional(field("type_parameters", $.type_parameters)),
        "(",
        optional(field("parameters", $.parameters)),
        ")",
        optional(field("block_parameters", $.block_parameters)),
        optional(seq(":", field("return_type", $.return_type))),
        "=",
        field("body", $._expression),
      ),

    block_parameters: ($) => seq("{", $.parameters, "}"),

    return_type: ($) =>
      seq(
        $.type_identifier,
        optional(seq("[", commaSep1($.generic_identifier), "]")),
        optional(field("effekts", $.effekts)),
      ),

    effekts: ($) => seq("/", "{", commaSep1($.type_identifier), "}"),

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
        optional(field("type_parameters", $.type_parameters)),
        "(",
        optional(field("parameters", $.parameters)),
        ")",
        optional(field("block_parameters", $.block_parameters)),
        optional(seq(":", field("return_type", $.return_type))),
      ),

    _expression: ($) => choice($.block, $.number, $.not_implemented),

    not_implemented: ($) => token(seq("<", ">")),

    block: ($) => seq("{", optional($._block_content), "}"),

    _block_content: ($) => repeat1(choice($._expression, $.statement)),

    statement: ($) => choice($.assignment),
    assignment: ($) =>
      seq(
        choice("val", "var"),
        $.identifier,
        "=",
        choice($.expression, $.block),
      ),

    expression: ($) => choice($.number),

    number: ($) => token(/\d+/),

    // Defining identifiers for type names and variable names
    generic_identifier: ($) => /[A-Za-z][a-zA-Z0-9_]*/,
    type_identifier: ($) => /[A-Za-z][a-zA-Z0-9_]*/,
    identifier: ($) => /[A-Za-z][a-zA-Z0-9_]*/,
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
