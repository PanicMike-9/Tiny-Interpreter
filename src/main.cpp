#include "parser.hpp"
#include "lexer.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>

int main()
{
    std::string input1 = "x = (10.0 + 10.0) * 2.5 + 5 / 6";
    std::vector<Token> token1 = tokenize(input1);
    
    // debugging to check correct token values and correct tokenization
    for(const Token& i : token1)
    {
        std::cout << i.value << ' ';
        std::cout << "token1 type: " << static_cast<int>(i.token) << '\n';
    }


    std::string input2 = "y = 3 + 5 * 3 / 2";
    std::vector<Token> token2 = tokenize(input2);

    for(const Token& i : token2)
    {
        std::cout << i.value << ' ';
        std::cout << "token2 type: " << static_cast<int>(i.token) << '\n';
    }

    parse(token1); // 40.8333
    parse(token2); // 10.5

    std::unordered_map<std::string, int> student_info;
}

