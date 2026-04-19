#include "parser.hpp"
#include <vector>

int main()
{
    //std::vector<Token> input_tokens{ {TokenType::IDENT, "val"}, {TokenType::ASSIGN, "="}, {TokenType::NUMBER, "10"}, {TokenType::PLUS, "+"}, {TokenType::NUMBER, "20"} };
    std::vector<Token> input_tokens{ {TokenType::IDENT, "val"}, {TokenType::ASSIGN, "="}, 
                                     {TokenType::NUMBER, "3"}, {TokenType::PLUS, "+"}, {TokenType::NUMBER, "7"} };

    parser(input_tokens);
}
