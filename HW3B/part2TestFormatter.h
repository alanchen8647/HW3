#ifndef PART2TESTFORMATTER_H
#define PART2TESTFORMATTER_H

#include "../BaseClass/testFormatter.h"
#include <string>

class Part2TestFormatter : public TestFormatter {
    public:
        Part2TestFormatter(
            const std::string& texHeader,
            const std::string& contentHeader,
            const std::string& className,
            const std::string& term,
            const std::string& examNo,
            const std::string& dayEve,
            const std::string& formLetter,
            const std::string& title, int nP)
            : texHeader(texHeader), contentHeader(contentHeader),
              className(className), term(term), examNo(examNo),
              dayEve(dayEve), formLetter(formLetter), title(title),
              numProblems(nP) {}
        std::string formatTest(const std::vector<Problem*>& problems, const std::string& title, const std::string& outputFileName) override;
    private:
        std::string texHeader;
        std::string contentHeader;
        std::string className;
        std::string term;
        std::string examNo;
        std::string dayEve;
        std::string formLetter;
        std::string title;
        int numProblems;
};

#endif