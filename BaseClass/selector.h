#ifndef TESTGENERATOR_H
#define TESTGENERATOR_H

#include <vector>
#include "problem.h"

class Selector {
    public:
        virtual ~Selector() = default;
        virtual std::vector<Problem*> selectProblem(const std::vector<Problem*>& problems, int numProblems) = 0;
};

#endif