module.exports = grammar({
  name: "effekt",

  rules: {
    source_file: ($) => repeat($._definition),

    _definition: ($) => choice($.line_comment, $.record, $.type),

    line_comment: ($) => token(seq("//", /.*/)),

    record: ($) =>
      seq("record", field("name", $.ident), "(", repeat($.record_field), ")"),

    record_field: ($) => seq($.ident, ":", $._type_ident, optional(",")),

    type: ($) =>
      seq("type", field("name", $.ident), "{", repeat($.type_field), "}"),

    type_field: ($) => seq($.ident, "(", ")", optional(";")),

    ty_ident: ($) => seq($.ident, ":", $._type_ident),

    _type_ident: ($) => seq($.ident, optional(seq("[", $.generic_ident, "]"))),

    ident: ($) => /[a-zA-Z][0-9a-zA-Z_]+/,

    generic_ident: ($) => /[a-zA-Z]+/,
  },
});
