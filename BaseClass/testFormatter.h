#ifndef TESTFORMATTER_H
#define TESTFORMATTER_H

#include <vector>
#include "problem.h"

class TestFormatter {
    public:
        virtual ~TestFormatter() = default;
        virtual std::string formatTest(const std::vector<Problem*>& problems, const std::string& title, const std::string& outputFileName) = 0;
};

#endif