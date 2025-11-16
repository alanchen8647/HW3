#ifndef EXTENDEDFILEREADER_H
#define EXTENDEDFILEREADER_H

#include "../BaseClass/fileReader.h"
#include <vector>
#include <string>

class ExtendedFileReader : public FileReader {
    public:
        std::vector<Problem*> readProblems(const std::string& filename) override;
};

#endif