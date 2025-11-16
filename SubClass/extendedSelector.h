#ifndef EXTENDEDSELECTOR_H
#define EXTENDEDSELECTOR_H

#include "../BaseClass/selector.h"
#include <vector>
#include "../BaseClass/testConstraint.h"

class ExtendedSelector : public Selector {
    public:
        ExtendedSelector(const std::vector<TestConstraint*>& constraints) : constraints(constraints) {}
        std::vector<Problem*> selectProblem(const std::vector<Problem*>& problems, int numProblems) override;
    private:
        std::vector<TestConstraint*> constraints;
};

#endif