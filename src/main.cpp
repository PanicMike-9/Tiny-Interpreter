#include "parser.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<Token> input_token1{ {TokenType::IDENT, "val1"}, 
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

    std::vector<Token> input_token2{ {TokenType::IDENT, "val2"}, 
                                     {TokenType::ASSIGN, "="},
                                     {TokenType::NUMBER, "5"},
                                     {TokenType::MULTIPLY, "*"},
                                     {TokenType::NUMBER, "250"},
                                    };
    
    // test precendence separately
    std::vector<Token> exp_input { {TokenType::NUMBER, "2"},
                                   {TokenType::PLUS, "+"},
                                   {TokenType::NUMBER, "3"},
                                   {TokenType::MULTIPLY, "*"},
                                   {TokenType::NUMBER, "4"},
                                   {TokenType::MULTIPLY, "*"},
                                   {TokenType::NUMBER, "5"}
                                 };

    int i = 0;
    int result = expression(exp_input);
    std::cout << result << '\n';

//    parser(input_token1); // val1 = 50
//    parser(input_token2); // val2 = 1250
}
