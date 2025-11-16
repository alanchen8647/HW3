#include ".\SubClass\testConstraint\topicConstraint.h"
#include ".\SubClass\extendedProblem.h"
#include <map>

bool TopicConstraint::valid(const std::vector<Problem*>& problems) const {

    std::map<std::string, int> topicCounts;
    for (const std::string& topic : topics) {
        topicCounts[topic] = 0;
    }

    // Count problems per topic
    for (const Problem* p : problems) {
        const ExtendedProblem* ep = dynamic_cast<const ExtendedProblem*>(p);
        if (ep) {
            topicCounts[ep->getTopic()] += 1;
        }
    }

    // Check counts against constraints
    for (const std::string& topic : topics) {
        int count = topicCounts[topic];
        if (count < min || count > max) {
            return false;
        }
    }
    return true;
}