#include "./part2TestFormatter.h"
#include "./part2Problem.h"
#include <iostream>
#include <fstream>

std::string Part2TestFormatter::formatTest(const std::vector<Problem*>& problems, const std::string& title, const std::string& outputFileName) {
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

    std::vector<Problem*> shortProblems;
    std::vector<Problem*> longProblems;

    for(Problem* problem: problems) {
        Part2Problem* p = dynamic_cast<Part2Problem*>(problem);
        if (p){
            if(p->getIsLongProblem()) {
                longProblems.push_back(problem);
            } else {
                shortProblems.push_back(problem);
            }
        }
    }

    // Write the problems to the file
    int problem_number = 1;
    for (Problem* problem : shortProblems){
        if(problem_number % 2 == 1) {
            outputFile << "\\pagebreak\n\n"; // Start a new page before 
        } else {                                 // each odd-numbered problem
            outputFile << "\\vspace{350pt}\n\n"; // Insert blank space before
        }
        outputFile << "\\item\\begin{tabular}[t]{p{5in} p{.3in} p{.8in}}\n";
        outputFile << problem->getQuestion();
        outputFile << "& & \\arabic{enumi}.\\hrulefill\n\\end{tabular}\n";
        problem_number += 1;
    }

    for (Problem* problem : longProblems) {
        outputFile << "\\pagebreak\n\n"; // Start a new page before each long problem
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