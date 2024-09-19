/*
 * DO NOT CHANGE CODE UNLESS SPECIFIED (such as TODOs)
 */

#include "unit_test_task_5.hpp"

TEST(task_5, negative_inputs_constant_interest_rate) {
    std::vector<TestCasesConstRate> test_cases = {
            /*
             * these are cases with invalid (negative) input
             */
            TestCasesConstRate(-2, 20, 1, 10, 0, 0),
            TestCasesConstRate(100, -1, 1, 10, 0, 0),
            TestCasesConstRate(100, 20, -1, 10, 0, 0),

            /*
             * interest rate can be negative, so the inputs to this following case are valid
             */
            TestCasesConstRate(100, 20, 1, -5, 340, 335),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, different_years) {
    double init_deposit = 100;
    double interest_rate_in_percentage = 10;
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(init_deposit, 20, 1, interest_rate_in_percentage, 340, 350),
            TestCasesConstRate(init_deposit, 20, 2, interest_rate_in_percentage, 580, 625),
            TestCasesConstRate(init_deposit, 20, 5, interest_rate_in_percentage, 1300.00, 1626.28),
            TestCasesConstRate(init_deposit, 20, 10, interest_rate_in_percentage, 2500, 4084.36),
            TestCasesConstRate(init_deposit, 40, 10, interest_rate_in_percentage, 4900, 7909.34),
            TestCasesConstRate(init_deposit, 40, 10, interest_rate_in_percentage, 4900, 7909.34),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, different_interest_rate) {
    double init_deposit = 100;
    double month_contribution = 40;
    int length_in_year = 10;
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(init_deposit, month_contribution, length_in_year, 10, 4900, 7909.34),
            TestCasesConstRate(init_deposit, month_contribution, length_in_year, 20, 4900, 13079.34),
            TestCasesConstRate(init_deposit, month_contribution, length_in_year, 30, 4900, 21835.94),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, different_init_deposit) {
    double month_contribution = 500;
    int length_in_year = 10;
    double interest_rate_in_percentage = 20;
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(100, month_contribution, length_in_year, interest_rate_in_percentage, 60100, 156371.27),
            TestCasesConstRate(1000, month_contribution, length_in_year, interest_rate_in_percentage, 61000, 161943.83),
            TestCasesConstRate(5000, month_contribution, length_in_year, interest_rate_in_percentage, 65000, 186710.77),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, different_monthly_contribute) {
    double init_deposit = 1000;
    int length_in_year = 10;
    double interest_rate_in_percentage = 20;
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(init_deposit, 1000, length_in_year, interest_rate_in_percentage, 121000, 317695.92),
            TestCasesConstRate(init_deposit, 2000, length_in_year, interest_rate_in_percentage, 241000, 629200.11),
            TestCasesConstRate(init_deposit, 3000, length_in_year, interest_rate_in_percentage, 361000, 940704.29),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, millionaire_in_10_years) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(7000, 4000, 10, 15, 487000, 1002897.38),
    };
    RUN_TEST_CASES(test_cases);
}

// Interesting observation: it takes 10 years to get to 1m, but only 5 years to 2m from 1m.
// First "bucket of gold" is the hardest.
TEST(task_5, from_1m_to_2m) {
    std::vector<TestCasesConstRate> test_cases = {
            TestCasesConstRate(1002897.38, 4000, 5, 15, 1242897.38, 2340819.15),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, negative_inputs_varying_rate) {
    std::vector<TestCasesVaryingRate> test_cases = {
            TestCasesVaryingRate(-1, 20,
                                 std::vector<double>{10},
                                 0, 0),
            TestCasesVaryingRate(100, -2,
                                 std::vector<double>{10},
                                 0, 0),
            TestCasesVaryingRate(100, 20,
                                 std::vector<double>{-5},
                                 340, 335),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, differnt_number_of_rates) {
    double init_deposit = 100;
    double month_contribution = 20;
    std::vector<TestCasesVaryingRate> test_cases = {
            TestCasesVaryingRate(init_deposit, month_contribution,
                                 std::vector<double>{10},
                                 340, 350),

            TestCasesVaryingRate(init_deposit, month_contribution,
                                 std::vector<double>{10, 10},
                                 580, 625),
            TestCasesVaryingRate(init_deposit, month_contribution,
                                 std::vector<double>{10, 20, -5},
                                 820, 867),
            TestCasesVaryingRate(init_deposit, month_contribution,
                                 std::vector<double>{-5, -10, 15},
                                 820, 862.73),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, real_sp500_rates) {
    std::vector<TestCasesVaryingRate> test_cases = {
            // actual S&P 500 rates from 2013 to 2021
            // https://www.macrotrends.net/2526/sp-500-historical-annual-returns
            TestCasesVaryingRate(100, 20,
                                 std::vector<double>{29.6, 11.39, -0.73, 9.54, 19.42, -6.24, 28.88, 16.26, 26.89},
                                 2260, 4361.90),
    };
    RUN_TEST_CASES(test_cases);
}

TEST(task_5, your_path_to_1m) {
    std::vector<TestCasesVaryingRate> test_cases = {
            TestCasesVaryingRate(100000, 5000,
                                 std::vector<double>{30.02, 15.22, -0.99, 11.86, 23.45, -9.72, 24.65, 10.26, 33.29},
                                 640000, 1327581.80),
    };
    RUN_TEST_CASES(test_cases);
}