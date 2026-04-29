#pragma once

#include "token.hpp"
#include <vector>

int parse_factor(const std::vector<Token>& tokens);
int parse_term(const std::vector<Token>& tokens);
int parse_expression(const std::vector<Token>& tokens);

void parser(const std::vector<Token>& tokens);

