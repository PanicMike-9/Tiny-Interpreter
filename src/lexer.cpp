#include "lexer.hpp"

std::vector<Token> tokenize(const std::string& input)
{
    // store all tokens
    std::vector<Token> tokens; 

    int i = 0;

    bool is_dot = false; // check for decimal points

    while(i < input.size())
    {
        char current_char = input[i];

        // ignore spaces
        if(isspace(current_char)) 
        {
            i++;
            continue;
        }

        // -- Always check digit first -- //


        // check digit
        else if(isdigit(current_char))
        {
            int start = i;

            // read digit and decimal points
            while(i < input.size() && isdigit(input[i]) || (input[i] == '.' && is_dot == false)) 
            {
                // check the decimal points
                if(current_char == '.' && is_dot == false)
                {
                    if(input[i] == '.')
                    {
                        is_dot = true;
                    }
                }

                i++;
            }

            std::string number_string = input.substr(start, i - start);

            tokens.push_back( {TokenType::NUMBER, number_string} );

            continue;
        }

        // check alphabet and digits
        else if(isalnum(current_char))
        {
            int start = i;

            while(i < input.size() && isalnum(input[i]))
                i++;
            
            std::string identifier = input.substr(start, i - start);
            tokens.push_back( {TokenType::IDENT, identifier} );

            continue;
        }

        // check assign
        else if(current_char == '=')
        {
            tokens.push_back( {TokenType::ASSIGN, "="} );
            i++;
            continue;
        }

        // check plus sign
        else if(current_char == '+')
        {
            tokens.push_back( {TokenType::PLUS, "+"} );
            i++;
            continue;
        }

        // check minus sign
        else if(current_char == '-')
        {
            tokens.push_back( {TokenType::MINUS, "-"} );
            i++;
            continue;
        }

        // check multiply sign
        else if(current_char == '*')
        {
            tokens.push_back( {TokenType::MULTIPLY, "*"} );
            i++;
            continue;
        }

        // check divide sign
        else if(current_char == '/')
        {
            tokens.push_back( {TokenType::DIVIDE, "/"} );
            i++;
            continue;
        }

        // check open/left parenthesis
        else if(current_char == '(')
        {
            tokens.push_back( {TokenType::LEFT_PAREN, "("} );
            i++;
            continue;
        }

        // check close/right parenthesis
        else if(current_char == ')')
        {
            tokens.push_back( {TokenType::RIGHT_PAREN, ")"} );
            i++;
            continue;
        }

        i++;
    }

    return tokens;
}
