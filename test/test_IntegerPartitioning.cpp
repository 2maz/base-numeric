#include <boost/test/unit_test.hpp>
#include <numeric/IntegerPartitioning.hpp>

using namespace numeric;

BOOST_AUTO_TEST_CASE(it_should_compute_integer_partitions)
{

    IntegerPartitioning ip;
    ip.compute(16);

    BOOST_TEST_MESSAGE(ip.toString());
}
