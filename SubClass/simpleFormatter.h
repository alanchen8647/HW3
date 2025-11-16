#ifndef SIMPLEFORMATTER_H
#define SIMPLEFORMATTER_H

#include "../BaseClass/testformatter.h"
#include <string>

class SimpleFormatter : public TestFormatter {
    public:
        SimpleFormatter(const std::string& header, const std::string& contentHeader, const std::string& outputFileName)
            : header(header), contentHeader(contentHeader), outputFileName(outputFileName) {}
        std::string formatTest(const std::vector<Problem*>& test, const std::string& title, const std::string& outputFileName) override;
    private:
        std::string header;
        std::string contentHeader;
        std::string outputFileName;
};

#endif