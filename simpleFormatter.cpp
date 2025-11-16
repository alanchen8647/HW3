#include "./SubClass/simpleFormatter.h"
#include <iostream>
#include <fstream>

std::string SimpleFormatter::formatTest(const std::vector<Problem*>& problems, const std::string& title, const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return "";
    }

    // Write the header to the file
    outputFile << "\\input{" << header << "}\n";
    outputFile << "\\newcommand{\\testtitle}{" << title << "}\n";
    outputFile << "\\input{" << contentHeader << "}\n";

    // Write the problems to the file
    for (Problem* problem : problems) {
        outputFile << "\\item " << problem->getQuestion() << "\n";
    }

    // End the file
    outputFile << "\\end{enumerate}\n\\end{document}";
    outputFile.close();

    return "Test formatted and written to " + outputFileName;
};