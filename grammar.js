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

    _definition: ($) => choice($.line_comment, $.record, $.type),

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

    // Defining identifiers for type names and variable names
    generic_identifier: ($) => /[A-Z][a-zA-Z0-9_]*/,
    type_identifier: ($) => /[A-Z][a-zA-Z0-9_]*/,
    identifier: ($) => /[a-z][a-zA-Z0-9_]*/,
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
