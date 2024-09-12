package tree_sitter_effekt_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_effekt "github.com/tree-sitter/tree-sitter-effekt/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_effekt.Language())
	if language == nil {
		t.Errorf("Error loading Effekt grammar")
	}
}
