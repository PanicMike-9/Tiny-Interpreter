#include "parser.hpp"
#include <vector>

int main()
{
    std::vector<Token> input_tokens{ {TokenType::IDENT, "val"}, 
                                     {TokenType::ASSIGN, "="}, 
                                     {TokenType::NUMBER, "3"}, 
                                     {TokenType::PLUS, "+"}, 
                                     {TokenType::NUMBER, "7"},
                                     {TokenType::PLUS, "+"}, 
                                     {TokenType::NUMBER, "10"},
                                     {TokenType::MINUS, "-"}, 
                                     {TokenType::NUMBER, "5"},
                                     {TokenType::MULTIPLY, "*"},
                                     {TokenType::NUMBER, "5"},
                                     {TokenType::DIVIDE, "/"},
                                     {TokenType::NUMBER, "3"},
                                     {TokenType::MULTIPLY, "*"},
                                     {TokenType::NUMBER, "2"},
                                   };

    parser(input_tokens);
}
