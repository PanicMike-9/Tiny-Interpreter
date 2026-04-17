#include "parser.hpp"
#include <vector>

int main()
{
    std::vector<Token> input_tokens{ {TokenType::IDENT, "val"}, {TokenType::ASSIGN, "="}, {TokenType::NUMBER, "10"}, {TokenType::PLUS, "+"}, {TokenType::NUMBER, "20"} };

    parser(input_tokens);
}
