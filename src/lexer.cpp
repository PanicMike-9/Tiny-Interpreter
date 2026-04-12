#include "lexer.hpp"

std::vector<Token> tokenize(const std::string& input)
{
    // hold all tokens
    std::vector<Token> tokens; 

    int i = 0;

    while(i < input.size())
    {
        char current_char = input[i];

        if(current_char == ' ') 
        {
            i++;
            continue;
        }

        // check alphabet
        else if(isalpha(current_char))
        {
            tokens.push_back({TokenType::IDENT});
        }

        // check number/digit
        else if(isdigit(current_char))
        {
            int start = i;

            while(i < input.size() && isdigit(input[i])) 
                i++;

            std::string number_string = input.substr(start, i - start);

            tokens.push_back({TokenType::NUMBER, number_string});

            continue;
        }

        // check plus sign
        else if(current_char == '+')
        {
            tokens.push_back({TokenType::PLUS, "+"});
        }

        // check minus sign
        else if(current_char == '-')
        {
            tokens.push_back({TokenType::MINUS, "-"});
        }

        // check multiply sign
        else if(current_char == '*')
        {
            tokens.push_back({TokenType::MULTIPLY, "*"});
        }

        // check assign
        else if(current_char == '=')
        {
            tokens.push_back({TokenType::ASSIGN, "="});
        }

        i++;
    }

    return tokens;
}
