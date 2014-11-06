#ifndef BASE_NUMERIC_INTEGER_PARTITIONING_HPP__
#define BASE_NUMERIC_INTEGER_PARTITIONING_HPP__

#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <iostream>
#include <boost/foreach.hpp>

namespace numeric {

typedef std::vector<int> IntegerPartition;

/**
 * Utitility class that allows to compute all integer partitions of a given integer
 * It uses the existing algorithm a Jerome Kelleher:
 * "Generating All Partitions: A Comparison Of Two Encodings", (Kelleher and O'Sullivan, 2009)
 *
 \beginverbatim
 IntegerPartitioning ip;
 // compute all partitions: [1,1,1,1,1],[2,1,1,1], ... [5]
 ip.compute(5);
 PartitionsMap partitionsMap = ip.getPartitionsMap();
 \endverbatim
 */
class IntegerPartitioning
{
public:
    typedef std::map<size_t, std::set< IntegerPartition > > PartitionsMap;

    PartitionsMap mPartitionsMap;

public:

    /**
     * Compute all integer partitions
     * Generating All Partitions: A Comparison Of Two Encodings
     * Jerome Kelleher, Barry O'Sullivan
     *
     * Translated from python and retrieved from http://jeromekelleher.net/partitions.php
     */
    void compute(size_t number);

    /**
     * Print all generated partitions
     * \return String representation of all generated integer partition
     */
    std::string toString() const;

    /**
     * Convert an integer partition to a string
     * \return String representation of an integer partition
     */
    static std::string toString(const IntegerPartition& partition);

    /**
     * Retrieve the partitions map
     * \return partition map
     */
    PartitionsMap getPartitionsMap() const { return mPartitionsMap; }

    /**
     * Compute the multiplicity of a value in a given integer partition
     * \return number of occurence of a single value in a given integer partition
     */
    static size_t multiplicity(const IntegerPartition& partition, int value);

};

std::ostream& operator<<(std::ostream& os, const IntegerPartition& list);

} // end namespace numeric
#endif // BASE_NUMERIC_INTEGER_PARTITIONING_HPP__
