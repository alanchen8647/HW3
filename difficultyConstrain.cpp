#include "./SubClass/testConstraint/difficultyConstraint.h"
#include "./SubClass/extendedProblem.h"

bool DifficultyConstraint::valid(const std::vector<Problem*>& problems) const {
    int totalDifficulty = 0;

    // Sum the difficulties of all problems
    for (const Problem* p : problems) {
        const ExtendedProblem* ep = dynamic_cast<const ExtendedProblem*>(p);
        if (ep) {
            totalDifficulty += ep->getDifficulty();
        }
    }

    // Check if total difficulty is within the specified range
    return (totalDifficulty >= minDifficulty && totalDifficulty <= maxDifficulty);
}