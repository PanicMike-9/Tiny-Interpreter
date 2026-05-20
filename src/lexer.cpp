#include "lexer.hpp"

std::vector<Token> tokenize(const std::string& input)
{
    // store all tokens
    std::vector<Token> tokens; 

    int position = 0;

    bool is_dot = false; // check for decimal points

    while(position < input.size())
    {
        char current_char = input[position];

        // ignore spaces
        if(isspace(current_char)) 
        {
            position++;
            continue;
        }

        // -- Always check digit first -- //

        // check digit
        else if(isdigit(current_char))
        {
            int start = position;

            // read digit and decimal points
            while(position < input.size() && isdigit(input[position]) || (input[position] == '.' && is_dot == false)) 
            {
                // check the decimal points
                if(current_char == '.' && is_dot == false)
                {
                    if(input[position] == '.')
                    {
                        is_dot = true;
                    }
                }

                position++;
            }

            std::string number_string = input.substr(start, position - start);

            tokens.push_back( {TokenType::NUMBER, number_string} );

            continue;
        }

        // check alphabet and digits
        else if(isalnum(current_char))
        {
            int start = position;

            while(position < input.size() && isalnum(input[position]))
                position++;
            
            std::string identifier = input.substr(start, position - start);
            tokens.push_back( {TokenType::IDENT, identifier} );

            continue;
        }

        // check assign
        else if(current_char == '=')
        {
            tokens.push_back( {TokenType::ASSIGN, "="} );
            position++;
            continue;
        }

        // check plus sign
        else if(current_char == '+')
        {
            tokens.push_back( {TokenType::PLUS, "+"} );
            position++;
            continue;
        }

        // check minus sign
        else if(current_char == '-')
        {
            tokens.push_back( {TokenType::MINUS, "-"} );
            position++;
            continue;
        }

        // check multiply sign
        else if(current_char == '*')
        {
            tokens.push_back( {TokenType::STAR, "*"} );
            position++;
            continue;
        }

        // check divide sign
        else if(current_char == '/')
        {
            tokens.push_back( {TokenType::SLASH, "/"} );
            position++;
            continue;
        }

        // check open/left parenthesis
        else if(current_char == '(')
        {
            tokens.push_back( {TokenType::LEFT_PAREN, "("} );
            position++;
            continue;
        }

        // check close/right parenthesis
        else if(current_char == ')')
        {
            tokens.push_back( {TokenType::RIGHT_PAREN, ")"} );
            position++;
            continue;
        }

        // -- Longer tokens before --

        // greater equal 
        else if(current_char == '>' && input[position + 1] == '=')
        {
            tokens.push_back( {TokenType::GREATER_EQUAL, ">="} );
            position++; 
            position++;
            continue;
        }

        // lesser equal
        else if(current_char == '<' && input[position + 1] == '=')
        {
            tokens.push_back( {TokenType::LESS_EQUAL, "<="} );
            position++;
            position++;
            continue;
        }

        // greater than
        else if(current_char == '>')
        {
            tokens.push_back( {TokenType::GREATER, ">"} );
            position++;
            continue;
        }

        // leser than
        else if(current_char == '<')
        {
            tokens.push_back( {TokenType::LESS, "<"} );
            position++;
            continue;
        }

        else if(current_char == '!' && current_char == '=' )
        {
            tokens.push_back( {TokenType::BANG_EQUAL, "!="} );
            position++;
            position++;
            continue;
        }

        else if(current_char == '!')
        {
            tokens.push_back( {TokenType::BANG, "!"} );
            position++;
            continue;
        }

        position++;
    }

    return tokens;
}
