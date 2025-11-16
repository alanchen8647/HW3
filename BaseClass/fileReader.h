#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
#include "problem.h"
#include <vector>

class FileReader {
    public:
    virtual ~FileReader() = default;
    virtual std::vector<Problem*> readProblems(const std::string& filename) = 0;
};

#endif