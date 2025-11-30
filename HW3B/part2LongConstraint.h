#ifndef PART2LONGCONSTRAINT_H
#define PART2LONGCONSTRAINT_H

#include "../BaseClass/testConstraint.h"

class LongConstraint : public TestConstraint {
public:
    LongConstraint(int minLong, int maxLong)
        : minLong(minLong), maxLong(maxLong) {}

    bool valid(const std::vector<Problem*>& test) const override;
private:
    int minLong;
    int maxLong;
};
#endif