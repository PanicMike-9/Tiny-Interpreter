#include "lexer.hpp"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string input = "val = val1 + 1";

    std::vector<Token> token = tokenize(input);

    for(const auto& tokens : token)
    {
        std::cout << tokens.value << ' ';
    }
}
