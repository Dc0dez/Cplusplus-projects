#include <vector>
#include "gtest/gtest.h"
#include "problem_3.h"
using namespace std;

TEST(problem_3, no_input) { // I was not familiar with the syntax for writing these tests and was getting errors, asked GPT for assistance on this
    vector<Influencer> influencers; // creates empty vector of influencers
    vector<Follower> expected_result = CustomerFinder::find_customer(influencers);// calls the CustomerFinder::find_customer function
    ASSERT_TRUE(expected_result.empty()); // confirms that the vector is empty
}

TEST(problem_3, influencer_with_no_followers) {
    vector<Follower> followers;// creates empty vector for followers
    Influencer influencer_1("Peter", followers);// creates the influencer
    vector<Influencer> influencers = {influencer_1}; // creates influencer vector containing Peter
    vector<Follower> expected_result = CustomerFinder::find_customer(influencers);
    ASSERT_TRUE(expected_result.empty());// confirms that the vector is empty
}

TEST(problem_3, influencer_with_followers) { // I wrote this based on the second test, only this time I filled the follower vector with a couple of followers
    Follower follower_1("Chaz", 21);
    Follower follower_2("Troy", 50);
    vector<Follower> followers = {follower_1, follower_2};
    Influencer influencer_1("Harry", followers);
    vector <Influencer> influencers = {influencer_1};
    vector<Follower> expected_result = CustomerFinder::find_customer(influencers);
    ASSERT_EQ(expected_result.size(), 1);// checks that only one customer meets the criteria of being less than/equal to 25 years old
    ASSERT_EQ(expected_result[0].name, "Chaz");// checks that the follower is Chaz
    ASSERT_EQ(expected_result[0].age, 21);// confirms that Chaz is 21
}

TEST(problem_3, multiple_influencers_with_followers) { // similar to test 2, but this one tests multiple influencers without a common follower
    Follower follower_1("Chaz", 21);
    Follower follower_2("Eric", 23);
    vector<Follower> followers_A = {follower_1};
    vector<Follower> followers_B = {follower_2};
    Influencer influencer_1("Harry", followers_A);
    Influencer influencer_2("Peter", followers_B);
    vector <Influencer> influencers = {influencer_1, influencer_2};
    vector<Follower> expected_result = CustomerFinder::find_customer(influencers);
    ASSERT_TRUE(expected_result.empty());
}

TEST(problem_3, multiple_influencers_with_common_follower) { // tests multiple influencers with a common follower
    Follower follower_1("Chaz", 21);
    Follower follower_2("Eric", 23);
    Follower follower_3("Tina", 24);
    vector<Follower> followers_A = {follower_1, follower_3};
    vector<Follower> followers_B = {follower_2, follower_3};
    Influencer influencer_1("Harry", followers_A);
    Influencer influencer_2("Peter", followers_B);
    vector<Influencer> influencers = {influencer_1, influencer_2};
    vector<Follower> expected_result = CustomerFinder::find_customer(influencers);
    ASSERT_EQ(expected_result.size(), 1);// checks that only one customer is common between both influencers
    ASSERT_EQ(expected_result[0].name, "Tina");// checks that the follower is Tina
    ASSERT_EQ(expected_result[0].age, 24);// confirms that Tina is 24
}