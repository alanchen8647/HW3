#ifndef Part1TestFormatter_H
#define Part1TestFormatter_H

#include "../BaseClass/testformatter.h"
#include <string>

class Part1TestFormatter : public TestFormatter {
    public:
        Part1TestFormatter(const std::string& header, const std::string& contentHeader, const std::string& outputFileName)
            : header(header), contentHeader(contentHeader), outputFileName(outputFileName) {}
        std::string formatTest(const std::vector<Problem*>& test, const std::string& title, const std::string& outputFileName) override;
    private:
        std::string header;
        std::string contentHeader;
        std::string outputFileName;
};

#endif