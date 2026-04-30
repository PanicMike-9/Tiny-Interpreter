#include "parser.hpp"
#include <vector>

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
                                     {TokenType::DIVIDE, "/"},
                                     {TokenType::NUMBER, "10"},
                                    };
    

    parse(input_token1); // before precedence: val1 = 50 after precedence: val1 = 4
    parse(input_token2); 

}
