#ifndef PART2PROBLEMSELECTOR_H
#define PART2PROBLEMSELECTOR_H

#include "../BaseClass/selector.h"
#include "../BaseClass/testConstraint.h"
#include <vector>
#include <random>
#include <map>
#include <string>

class Part2ProblemSelector : public Selector {
    public:
        Part2ProblemSelector(const std::vector<TestConstraint*>& constraints, int minLong, int maxLong, int minPerAuthor, int maxPerAuthor, int minPerTopic, int maxPerTopic)
            : constraints(constraints), minLong(minLong), maxLong(maxLong), minPerAuthor(minPerAuthor), maxPerAuthor(maxPerAuthor), minPerTopic(minPerTopic), maxPerTopic(maxPerTopic) {}
        std::vector<Problem*> selectProblem(const std::vector<Problem*>& problems, int numProblems) override;
    private:
        std::vector<TestConstraint*> constraints;
        int minLong;
        int maxLong;
        int minPerAuthor;
        int maxPerAuthor;
        int minPerTopic;
        int maxPerTopic;

        bool canAddProblem(Problem* problem , const std::map<std::string, int>& authorCounts ,const std::map<std::string, int>& topicCounts,int longCount) const;
};

#endif 