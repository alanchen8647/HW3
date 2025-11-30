#include "part2LongConstraint.h"
#include "part2Problem.h"

bool LongConstraint::valid(const std::vector<Problem*>& test) const {
    int longCount = 0;

    for (Problem* problem : test) {
        Part2Problem* p = dynamic_cast<Part2Problem*>(problem);
        if (p && p->getIsLongProblem()) {
            longCount++;
        }
    }

    return longCount >= minLong && longCount <= maxLong;
}