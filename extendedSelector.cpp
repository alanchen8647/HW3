#include "./SubClass/extendedSelector.h"
#include <algorithm>
#include <random>

std::vector<Problem*> ExtendedSelector::selectProblem(const std::vector<Problem*>& problems, int numProblems) {
    std::random_device rd;
    std::mt19937 gen(rd());

    while (true) {
        std::vector<Problem*> shuffledProblems = problems;
        std::shuffle(shuffledProblems.begin(), shuffledProblems.end(), gen);
        std::vector<Problem*> selectedProblems(shuffledProblems.begin(), shuffledProblems.begin() + numProblems);

        bool allConstraintsSatisfied = true;
        for (TestConstraint* constraint : constraints) {
            if (!constraint->valid(selectedProblems)) {
                allConstraintsSatisfied = false;
                break;
            }
        }

        if (allConstraintsSatisfied) {
            return selectedProblems;
        }
    }
}