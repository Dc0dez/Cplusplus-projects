#include <iostream>
#include "formula.hpp"

FormulaService::FormulaService(const std::string &formula_str) {
    set_formula(formula_str);// Assigns input formula string to formula_str.
}

void FormulaService::set_formula(const std::string &formula_str) {
    this->formula_str = formula_str;// Sets the formula string.
}

int FormulaService::operation(char op, int a, int b) {// I created this helper method to check for if the correct operators were input by the user and return them if correct for use in the calculate method.
    if (op == '+') {
        return a + b;
    } else if(op == '*') {
        return a * b;
    }else
    {
        std::cerr << "Invalid input. Formula must contain only '*' or '+' operators." << std::endl;// Error handling is supposed to check for invalid operators.
        throw;
    }
}

int FormulaService::calculate(const std::vector<int> &values) {
    std::string formula(formula_str);// Creates a deep copy of the contents from 'formula_str'.

    for(size_t i = 0; i < formula.length(); i++)// I got help from GPT on lines 30 through 35.
    {
        char p = formula[i];
        if(std::isdigit(p)) {
            if (i==0 || formula[i-1]!='x') {// Checks if char p is a digit at the beginning of the string. This implementation ensures that the test is not accessing out of bounds, and ensures that the test is checking that the preceding char is not 'x'. If preceding char is not 'x', test fails.
                std::cerr << "Invalid input. Formula must not contain constants and variables must be set to 'x1, x2, and x3'."<< std::endl;
                throw;
            }
        }
        if (p == '(' || p == ')')// Check to ensure no parentheses are entered by the user.
        {
            std::cerr << "Invalid input. Formula must not contain parentheses." << std::endl;
        }
    }

    for (size_t i = 0; i < values.size(); i++){// I got help from GPT on writing the code to calculate the formula. Iterates through the variables entered by the user and constructs them into 'x1','x2', and 'x3'.
        std::string variable = "x" + std::to_string(i + 1);
        std::string value = std::to_string(values[i]);// Casts the values to string.

        size_t position = 0; // Sets the position for searching in the formula.
        while ((position = formula.find(variable, position)) != std::string::npos) {// Locates the variable's position in the formula.
            formula.replace(position, variable.length(), value); // Replaces the variable with the value.
            position += value.length(); // Updates the position in the formula and continues searching.
        }
    }

    int v1, v2, v3; // Integer variable declarations.
    char op1, op2;// Operator declarations.

    std::stringstream ss(formula); // String stream created from the formula.

    ss >> v1 >> op1 >> v2 >> op2 >> v3;// Extracts operands and operators from the formula. Used code from the util.cpp to create this.

    if(op2 == '*'){// Does multiplication first if the second operator is multiplication.
        v2 = operation(op2, v2, v3);
    }else{
        v1 = operation(op1, v1, v2);
        v2 = v3; // Assigns v2 to v3, preparing the second value for the next operation.
        op1 = op2;// Updates operator 1 to operator 2, prepares op1 for the next operation.
    }
    return operation(op1, v1, v2);// Returns the result of the call to this function.
}


