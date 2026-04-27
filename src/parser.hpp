#pragma once

#include "token.hpp"
#include <vector>

int parse_factor();
void parse_term();
void parse_expression();

void parser(const std::vector<Token> &tokens);

