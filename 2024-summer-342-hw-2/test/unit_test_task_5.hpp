/*
 * DO NOT MAKE ANY CHANGES
 */
#include "task_5/million_dollar_idea.h"
#include "gtest/gtest.h"

/*
 * Global variable. Usually bad idea to use.
 * Here these are used for singleton purpose.
 * I used the following resource: https://stackoverflow.com/questions/44359953/are-global-variables-in-c-stored-on-the-stack-heap-or-neither-of-them and GPT to answer this. Global vars are stored in an area of memory separate from the stack and heap. Uninitialized global vars are stored in the 'BSS (Block Started by Symbol) segment' and initialized vars are stored in the 'data segment'.
 */
Formula<double> formula_annual_compound("x_init_deposit + x_rate * x_init_deposit + x_yearly");
Compounder compounder(&formula_annual_compound);

class CompounderTestCase {
public:
    double init_deposit;
    double monthly_contribution;
    double expect_money_invested;
    double expect_money_accumulated;

    CompounderTestCase(double init_deposit,
                       double monthly_contribution,
                       double money_invested,
                       double money_accumulated)
            : init_deposit(init_deposit), monthly_contribution(monthly_contribution),
              expect_money_invested(money_invested),
              expect_money_accumulated(money_accumulated) {}

    virtual void verify(int case_id) = 0;

    void assert_result(CompoundResult &actual, int case_id) const {
        auto failure_msg = "Test case " + std::to_string(case_id) + " failed :(";
        ASSERT_FLOAT_EQ(expect_money_invested, actual.invested) << failure_msg;
        ASSERT_FLOAT_EQ(expect_money_accumulated, actual.accumulated) << failure_msg;
    }
};

class TestCasesConstRate : public CompounderTestCase {
public:
    int length_in_year;
    double interest_rate_in_percentage;

    TestCasesConstRate(double init_deposit, double monthly_contribution, int length_in_year,
                       double interest_rate_in_percentage,
                       double money_invested, double money_accumulated) :
            CompounderTestCase(init_deposit,
                               monthly_contribution,
                               money_invested,
                               money_accumulated),
            length_in_year(length_in_year), interest_rate_in_percentage(interest_rate_in_percentage) {}

    void verify(int case_id) override {
        CompoundResult actual = compounder.calculate(
                init_deposit,
                monthly_contribution,
                length_in_year,
                interest_rate_in_percentage);
        assert_result(actual, case_id);
    }
};

class TestCasesVaryingRate : public CompounderTestCase {
public:
    std::vector<double> interest_rates;

    TestCasesVaryingRate(double init_deposit, double monthly_contribution,
                         const std::vector<double> &interest_rates,
                         double money_invested, double money_accumulated) :
            CompounderTestCase(init_deposit, monthly_contribution,
                               money_invested, money_accumulated),
            interest_rates(interest_rates) {}

    void verify(int case_id) override {
        CompoundResult actual = compounder.calculate(init_deposit, monthly_contribution, interest_rates);
        assert_result(actual, case_id);
    }
};

#define RUN_TEST_CASES(c)  for (int i=0; i<(c).size(); i++) {(c)[i].verify(i);}