#include <iostream>
#include <vector>
#include <string>
#include "ast/lexer.hpp"
#include "token.hpp"

int main() {
    // Test code
    std::string_view source =
        "fun main() {\n"
        "    wtr x = 10;\n"
        "    print \"Hello, Aegis!\";\n"
        "}";

    std::cout << "--- Scanning Code ---" << std::endl;
    std::cout << source << std::endl;
    std::cout << "---------------------" << std::endl;

    aegis::Lexer lexer(source);
    std::vector <aegis::Token> tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        std::cout << "Line" << token.line << "|";
        // Display a number using TokenType
        std::cout << "Type: " << static_cast<int>(token.type) << "|";
        std::cout << "Literal: [" << token.literal << "]" << std::endl;
    }

    return 0;
}