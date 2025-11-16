#ifndef TOPICCONSTRAINT_H
#define TOPICCONSTRAINT_H

#include "../../BaseClass/testConstraint.h"
#include <string>
#include <set>

class TopicConstraint : public TestConstraint {
    public:
        TopicConstraint(const std::set<std::string>& topics, int min, int max)
            : topics(topics), min(min), max(max) {}
        bool valid(const std::vector<Problem*>& problems) const override;
    private:
        std::set<std::string> topics;
        int min;
        int max;
        
};

#endif