#ifndef DIFFICULTYCONSTRAINT_H
#define DIFFICULTYCONSTRAINT_H

#include "../../BaseClass/testConstraint.h"
#include <string>
#include <set>

class DifficultyConstraint : public TestConstraint {
    public:
        DifficultyConstraint(int minDifficulty, int maxDifficulty)
            : minDifficulty(minDifficulty), maxDifficulty(maxDifficulty) {}
        bool valid(const std::vector<Problem*>& problems) const override;
    private:
        int minDifficulty;
        int maxDifficulty;  
};

#endif