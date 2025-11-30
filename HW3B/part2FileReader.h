#ifndef PART2FILEREADER_H
#define PART2FILEREADER_H

#include "../BaseClass/fileReader.h"
#include <vector>
#include <string>

class Part2FileReader : public FileReader {
    public:
        std::vector<Problem*> readProblems(const std::string& filename) override;
};

#endif