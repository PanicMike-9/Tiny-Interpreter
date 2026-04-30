#pragma once

#include "token.hpp"
#include <vector>

int factor(const std::vector<Token>& tokens);
int term(const std::vector<Token>& tokens);
int expression(const std::vector<Token>& tokens);

void parse(const std::vector<Token>& tokens);

