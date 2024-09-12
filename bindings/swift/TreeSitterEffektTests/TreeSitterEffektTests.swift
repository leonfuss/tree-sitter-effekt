import XCTest
import SwiftTreeSitter
import TreeSitterEffekt

final class TreeSitterEffektTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_effekt())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Effekt grammar")
    }
}
