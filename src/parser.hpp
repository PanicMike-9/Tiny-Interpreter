#pragma once

#include "token.hpp"
#include <vector>

double factor(const std::vector<Token>& tokens);
double term(const std::vector<Token>& tokens);
double comparison(const std::vector<Token>& tokens);
double expression(const std::vector<Token>& tokens);

void parse(const std::vector<Token>& tokens);

