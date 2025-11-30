#include "./part1TestFormatter.h"
#include <iostream>
#include <fstream>

std::string Part1TestFormatter::formatTest(const std::vector<Problem*>& problems, const std::string& title, const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return "";
    }
    
    // Write the header to the file
    outputFile << "\\input{" << header << "}\n";
    outputFile << "\\newcommand{\\testtitle}{" << title << "}\n";
    outputFile << "\\input{" << contentHeader << "}\n";

    std::cout << header << std::endl;
    std::cout << contentHeader << std::endl;

    // Write the problems to the file
    for (Problem* problem : problems) {
        outputFile << "\\item \\question{" << problem->getQuestion() << "}\n";
        outputFile << "\\answer{" << problem->getAnswer() << "}\n\n";
    }

    // End the file
    outputFile << "\\end{enumerate}\n\\end{document}";
    outputFile.close();

    return "Test formatted and written to " + outputFileName;
};