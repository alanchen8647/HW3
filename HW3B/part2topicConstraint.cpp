#include "..\SubClass\testConstraint\topicConstraint.h"
#include ".\part2Problem.h"
#include <map>

bool TopicConstraint::valid(const std::vector<Problem*>& problems) const {
    std::map<std::string, int> topicCounts;

    // Count ALL topics that appear in the test
    for (const Problem* p : problems) {
        const Part2Problem* ep = dynamic_cast<const Part2Problem*>(p);
        if (ep) {
            topicCounts[ep->getTopic()] += 1;
        }
    }

    // Only check constraints for topics that are in our required set
    for (const std::string& topic : topics) {
        int count = topicCounts[topic];  // This will be 0 if topic doesn't appear in test
        if (count < min || count > max) {
            return false;
        }
    }
    return true;
}