#ifndef TESTCONSTRAINT_H
#define TESTCONSTRAINT_H

#include <vector>
#include "problem.h"

class TestConstraint{
    public:
        virtual ~TestConstraint() = default;
        virtual bool valid(const std::vector<Problem*>& problems) const = 0;
};

#endif