#pragma once
#include <sstream>
#include <cctype>
#include <string>
#include <vector>

class FormulaService {
private:
std::string formula_str;

public:
    FormulaService() = default;

    FormulaService(const std::string &formula_str);

    void set_formula(const std::string &formula_str);

    static int operation(char op, int a, int b);

    int calculate(const std::vector<int> &values);
};