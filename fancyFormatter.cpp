#include "./SubClass/fancyFormatter.h"
#include <iostream>
#include <fstream>

std::string FancyFormatter::formatTest(const std::vector<Problem*>& problems, const std::string& title, const std::string& outputFileName) {
    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return "";
    }

    // Write the header to the file
    outputFile << "\\input{" << texHeader << "}\n";
    outputFile << "\\newcommand{\\classname}{" << className << "}\n";
    outputFile << "\\newcommand{\\term}{" << term << "}\n";
    outputFile << "\\newcommand{\\examno}{" << examNo << "}\n";
    outputFile << "\\newcommand{\\dayeve}{" << dayEve << "}\n";
    outputFile << "\\newcommand{\\formletter}{" << formLetter << "}\n";
    outputFile << "\\newcommand{\\numproblems}{" << numProblems << " }\n";
    outputFile << "\\newcommand{\\testtitle}{" << title << "}\n";
    outputFile << "\\input{" << contentHeader << "}\n";

    // Write the problems to the file
    int problem_number = 1;
    for (Problem* problem : problems) {
        if (problem_number % 2 == 1) {       // Start a new page before 
            outputFile << "\\pagebreak\n\n"; // each odd-numbered problem
        } else {                                 // Insert blank space before
            outputFile << "\\vspace{350pt}\n\n"; // each even-numbered problem
        }
        outputFile << "\\item\\begin{tabular}[t]{p{5in} p{.3in} p{.8in}}\n";
        outputFile << problem->getQuestion();
        outputFile << "& & \\arabic{enumi}.\\hrulefill\n\\end{tabular}\n";
        problem_number += 1;
    }

    // End the file
    outputFile << "\\end{enumerate}\n\\end{document}";
    outputFile.close();

    return "Test formatted and written to " + outputFileName;
};