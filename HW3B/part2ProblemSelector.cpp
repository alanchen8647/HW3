#include "part2ProblemSelector.h"
#include "part2Problem.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <map>

bool Part2ProblemSelector::canAddProblem(Problem* problem , const std::map<std::string, int>& authorCounts ,const std::map<std::string, int>& topicCounts,int longCount) const {
    Part2Problem* p = dynamic_cast<Part2Problem*>(problem);
    if (!p) {
        return false;
    }

    std::string author = p->getAuthor();
    std::string topic = p->getTopic();

    auto authorIt = authorCounts.find(author);
    if (authorIt!=authorCounts.end() && authorIt->second >= maxPerAuthor) {
        return false;
    }

    auto topicIt = topicCounts.find(topic);
    if (topicIt!=topicCounts.end() && topicIt->second >= maxPerTopic) {
        return false;
    }

    if (p->getIsLongProblem() && longCount >= maxLong) {
        return false;
    }

    return true;
}

std::vector<Problem*> Part2ProblemSelector::selectProblem(const std::vector<Problem*>& problems, int numProblems) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int attempt = 0;
    const int MAX_ATTEMPTS = 1000;  // Safety limit

    while (attempt < MAX_ATTEMPTS){
        attempt++;
        std::cout << "Attempt " << attempt << ": ";

        std::vector<Problem*> shuffled = problems;
        std::shuffle(shuffled.begin(), shuffled.end(), gen);

        std::vector<Problem*> selected;
        std::map<std::string, int> authorCounts;
        std::map<std::string, int> topicCounts;
        int longCount = 0;

        for (Problem* problem : shuffled) {
            if (selected.size() >= numProblems) {
                break;
            }
            Part2Problem* p = dynamic_cast<Part2Problem*>(problem);
            if(!p) {
                continue;
            }

            if(canAddProblem(problem, authorCounts, topicCounts, longCount)) {
                selected.push_back(problem);
                authorCounts[p->getAuthor()]+=1;
                topicCounts[p->getTopic()]+=1;
                if (p->getIsLongProblem()) {
                    longCount+=1;
                }
            }
        }
        if (selected.size() == numProblems) {
            bool allConstraintsSatisfied = true;
            for (TestConstraint* constraint : constraints) {
                if (!constraint->valid(selected)) {
                    allConstraintsSatisfied = false;
                    break;
                }
            }
            if (allConstraintsSatisfied) {
                return selected;
            }
        }
    }
    std::cout << "Failed to select problems after " << MAX_ATTEMPTS << " attempts.\n";
    return {};
}