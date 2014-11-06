#include <boost/test/unit_test.hpp>
#include <numeric/Combinatorics.hpp>
#include <sstream>

using namespace numeric;

BOOST_AUTO_TEST_CASE(it_should_compute_binomial_coefficient)
{
    BOOST_REQUIRE_MESSAGE( 0 == binomialCoefficient(0,1), "1 out of 0 should be 0");
    BOOST_REQUIRE_MESSAGE( 1 == binomialCoefficient(10,10), "n out of n should be 1");
    BOOST_REQUIRE_MESSAGE( 10 == binomialCoefficient(10,1), "1 out of n should be n");
    BOOST_REQUIRE_MESSAGE( 220 == binomialCoefficient(12,3), "3 out of 12 should be 220: was " << binomialCoefficient(12,3));
}

BOOST_AUTO_TEST_CASE(it_should_generate_permutations)
{
    std::vector<int> items;
    items.push_back(1);
    items.push_back(2);
    items.push_back(0);
    items.push_back(4);

    Permutation<int> permutation(items);

    BOOST_ASSERT(permutation.numberOfPermutations() == 24);

    do
    {
        const std::vector<int>& permutedItems = permutation.current();
        BOOST_TEST_MESSAGE("Permutation " << permutedItems[0] << permutedItems[1] << permutedItems[2] << permutedItems[3]);
    } while(permutation.next());
}

BOOST_AUTO_TEST_CASE(it_should_generate_combinations_int)
{
    {
        std::vector<int> items;
        for(size_t i = 0; i < 9; ++i)
        {
            items.push_back(i);
        }

        std::vector<Mode> modes;
        modes.push_back(MAX);
        modes.push_back(MIN);
        modes.push_back(EXACT);

        for(size_t t = 0; t < modes.size(); ++t)
        {
            size_t count = 0;
            Combination<int> combination(items,items.size() - 1, modes[t]);
            do
            {
                std::vector<int> combinatedItems = combination.current();
                std::vector<int>::const_iterator cit = combinatedItems.begin();
                std::stringstream ss;
                for(; cit != combinatedItems.end(); ++cit)
                {
                    ss << *cit;
                }
                ++count;
                BOOST_TEST_MESSAGE("Combination: " << ss.str());
            } while(combination.next());
            BOOST_REQUIRE_MESSAGE( count == combination.numberOfCombinations(), "Number of expected combinations: " << combination.numberOfCombinations() << " vs. actual " << count );
        }
    }
}

BOOST_AUTO_TEST_CASE(it_should_generate_combinations_string)
{
    {
        std::vector<std::string> items;
        for(size_t i = 0; i <= 15; ++i)
        {
            std::stringstream ss;
            ss << "http://test#" << i;
            items.push_back( ss.str());
        }

        std::vector<Mode> modes;
        modes.push_back(MAX);
        modes.push_back(MIN);
        modes.push_back(EXACT);

        for(size_t t = 0; t < modes.size(); ++t)
        {
            size_t count = 0;
            Combination<std::string> combination(items,items.size(), modes[t]);
            do
            {
                std::vector<std::string> combinatedItems = combination.current();
                std::vector<std::string>::const_iterator cit = combinatedItems.begin();
                std::stringstream ss;
                for(; cit != combinatedItems.end(); ++cit)
                {
                    ss << *cit << " ";
                }
                ++count;
                BOOST_TEST_MESSAGE("Combination: " << ss.str());
            } while(combination.next());
            BOOST_REQUIRE_MESSAGE( count == combination.numberOfCombinations(), "Number of expected combinations: " << combination.numberOfCombinations() << " vs. actual " << count );
        }
    }
    {
        std::vector<std::string> items;
        for(size_t i = 0; i <= 15; ++i)
        {
            std::stringstream ss;
            ss << "http://test#" << i;
            items.push_back( ss.str());
        }

        std::vector<Mode> modes;
        modes.push_back(MAX);
        modes.push_back(MIN);
        modes.push_back(EXACT);

        for(size_t t = 0; t < modes.size(); ++t)
        {
            size_t count = 0;
            Combination<std::string> combination(items,2, modes[t]);
            do
            {
                std::vector<std::string> combinatedItems = combination.current();
                std::vector<std::string>::const_iterator cit = combinatedItems.begin();
                std::stringstream ss;
                for(; cit != combinatedItems.end(); ++cit)
                {
                    ss << *cit << " ";
                }
                ++count;
                BOOST_TEST_MESSAGE("Combination: " << ss.str());
            } while(combination.next());
            BOOST_REQUIRE_MESSAGE( count == combination.numberOfCombinations(), "Number of expected combinations: " << combination.numberOfCombinations() << " vs. actual " << count );
        }
    }
}

BOOST_AUTO_TEST_CASE(it_should_generate_combinations)
{
    {
        std::vector<char> input;
        char currentType = 'a';

        for(; currentType <= 'a' + 5; ++currentType)
        {
            input.push_back(currentType);
        }

        Combination<char> combination(input, 2, EXACT);
        int count = 0;
        do
        {
            std::vector<char> current = combination.current();
            std::string currentCombination(current.begin(), current.end());
            BOOST_TEST_MESSAGE("Current combination is: " << currentCombination);
            count++;
        } while(combination.next());

        BOOST_REQUIRE_MESSAGE(count == combination.numberOfCombinations(), "Expected number of combination is " << combination.numberOfCombinations() << " but received: " << count);
    }
    {
        std::vector<char> input;
        char currentType = 'a';

        for(; currentType <= 'a' + 10; ++currentType)
        {
            input.push_back(currentType);
        }

        Combination<char> combination(input, 2, EXACT);
        int count = 0;
        do
        {
            std::vector<char> current = combination.current();
            std::string currentCombination(current.begin(), current.end());
            BOOST_TEST_MESSAGE("Current combination is: " << currentCombination);
            count++;
        } while(combination.next());

        BOOST_REQUIRE_MESSAGE(count == combination.numberOfCombinations(), "Expected number of combination is " << combination.numberOfCombinations() << " but received: " << count);
    }

}