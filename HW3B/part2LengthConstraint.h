#ifndef PART2LENGTHCONSTRAINT_H
#define PART2LENGTHCONSTRAINT_H

#include "../BaseClass/testConstraint.h"

class LengthConstraint : public TestConstraint {
public:
    LengthConstraint(int minLong, int maxLong)
        : minLong(minLong), maxLong(maxLong) {}

    bool valid(const std::vector<Problem*>& test) const override;
private:
    int minLong;
    int maxLong;
};
#endif