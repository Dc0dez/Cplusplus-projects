/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */
#include "million_dollar_idea.h"
#include "../task_3/formula.hpp"
#include <iostream>

CompoundResult
Compounder::calculate_without_roundoff(double init_deposit, double monthly_contribution, int length_in_year,
                                       double interest_rate_in_percentage) {
    CompoundResult result;

    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        length_in_year <= 0) {
        return result;
    }

    double accumulated = init_deposit;
    double annual_contribution = monthly_contribution * 12;
    double invested = init_deposit; // Sets invested to initial deposit

    // I got help from Peng and GPT writing this code.

    // Creates a vector that matches values up with formula_str
    std::vector<double> data = {accumulated, (interest_rate_in_percentage / 100), accumulated, annual_contribution};

    // Creates a loop to handle yearly compound interest
    for (int i = 0; i < length_in_year; i++) {
        invested += annual_contribution;// Combines invested amount with annual contribution
        result.accumulated = formula->calculate(data); // Updates accumulated result calculation using formula
        //Updates values for accumulated in the data vector with the result obtained from formula
        data[0] = result.accumulated;
        data[2] = result.accumulated;
    }
    result.invested = invested; // Updates invested result to the total invested amount

    return result; // returns result of invested and accumulated calculations
}

CompoundResult
Compounder::calculate(double init_deposit, double monthly_contribution, int length_in_year, double rate_in_percentage) {
    CompoundResult result;

    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        length_in_year <= 0) {
        return result;
    }

    result = calculate_without_roundoff(init_deposit, monthly_contribution, length_in_year, rate_in_percentage);

    result.accumulated = roundOff(result.accumulated);

    return result;
}

// https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/
/*
 * This function rounds the value to the nearest hundredth place value. This function ensures that the result is formatted to two decimal places.
 */
double Compounder::roundOff(double value) {
    return std::round(value * 100.0) / 100.0;
}

CompoundResult
Compounder::calculate(double init_deposit, double monthly_contribution, std::vector<double> interest_rates) {
    CompoundResult result;
    if (init_deposit <= 0 ||
        monthly_contribution <= 0 ||
        interest_rates.empty()) {
        return result;
    }

    result.invested = 0;
    result.accumulated = 0;
    double invested = init_deposit;

    // size_t in the loop to prevent comparison warning
    // https://stackoverflow.com/questions/3660901/a-warning-comparison-between-signed-and-unsigned-integer-expressions
    for (std::size_t i = 0; i < interest_rates.size(); i++) {
        double rate = interest_rates[i];
        double deposit = (i == 0) ? init_deposit : result.accumulated;
        result = calculate_without_roundoff(deposit, monthly_contribution, 1, rate);
        invested += monthly_contribution * 12;
    }

    result.invested = invested;
    result.accumulated = roundOff(result.accumulated);

    return result;
}