#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include ".\part2Problem.h"
#include ".\part2FileReader.h"

std::vector<std::string> split(std::string s, std::string del) {
    std::vector<std::string> v;
    int start = 0;
    for (int end = s.find(del, start); end != std::string::npos; end = s.find(del, start)) {
        v.push_back(s.substr(start, end - start));
        start = end + del.size();
    }
    v.push_back(s.substr(start));
    return v;
}

std::vector<Problem*> Part2FileReader::readProblems(const std::string& filename) {
    std::string FORMAT = "^([\\s\\S]*)\\\\answer\\{([\\s\\S]*)\\}[\\s\\S]*\\\\topic\\{(.*)\\}[\\s\\S]*\\\\author\\{(.*)\\}[\\s\\S]*\\\\isLong\\{(.*)\\}";
    std::regex re(FORMAT);

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening the problem list" << std::endl;
        throw std::runtime_error("Cannot open problem list");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string str = buffer.str();

    std::vector<std::string> problemStrings = split(str, "\\item");
    problemStrings.erase(problemStrings.begin());

    std::vector<Problem*> problems = {};
    for (const std::string& problemString : problemStrings) {
        std::smatch match;
        if (!std::regex_search(problemString, match, re) == true) {
            std::cerr << "Invalid problem: " << problemString;
            throw std::runtime_error("Invalid problem");
        }
        std::string question = match.str(1);
        std::string answer = match.str(2);
        std::string topic = match.str(3);
        std::string author = match.str(4);
        std::string isLongProblem = match.str(5);
        bool isLong = (isLongProblem == "true");
        Part2Problem* problem = new Part2Problem(question, answer, topic, author, isLong);
        problems.push_back(problem);
    }
    return problems;
};