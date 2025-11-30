#include <ranges>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <map>
#include <set>
#include ".\part2Problem.h"
#include ".\part2ProblemSelector.h"
#include ".\part2LongConstraint.h"
#include ".\part2authorConstraint.h"
#include "..\SubClass\testConstraint\topicConstraint.h"
#include ".\part2FileReader.h"
#include ".\part2TestFormatter.h"

// ****************************************************************************
// Configuration details

// Variable information to be printed on the test
std::string CLASS = "Arithmetic";
std::string TERM = "Fall 2025";
std::string EXAM = "925";
std::string TIME = "Day";
std::string TITLE = "Final Exam";
std::string FORM = "A";

// Source file for problem bank
std::string BANK = "math_problems.tex";

// Filename for the created test
std::string FILENAME = "part2_test.tex";

// Constraints on the problem choice.
int NUM_PROBLEMS = 10; // The test must have 20 problems.
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(3, 4);
int NUM_LONG = dis(gen);



// tex files to include in the test file
std::string TEX_HEADER = "fancy_tex_header.tex";
std::string CONTENT_HEADER = "fancy_content_header.tex";

// ****************************************************************************

// Check whether a proposed test is valid according to the above constraints.
// bool valid(std::vector<Problem> test, std::set<std::string> topics) {
//     // Initialize metrics
//     int difficulty = 0;
//     std::map<std::string, int> topicCounts;
//     for (std::string topic : topics) {
//         topicCounts[topic] = 0;
//     }

//     // Calculate the metrics
//     for (Problem p : test) {
//         difficulty += p.getDifficulty();
//         topicCounts[p.getTopic()] += 1;
//     }

//     // Check the metrics
//     if (difficulty < MIN_DIFFICULTY || difficulty > MAX_DIFFICULTY) {
//         return false;
//     }
//     for (std::string topic : topics) {
//         int count = topicCounts[topic];
//         if (count < MIN_TOPIC || count > MAX_TOPIC) {
//             return false;
//         }
//     }
//     return true;
// }

// Given a bank of possible test problems, return randomly-chosen 
// problems that form a valid test, according to the contraints above.
// std::vector<Problem> testProblems(std::vector<Problem> bank) {
//     // Determine the topics covered on the test
//     std::set<std::string> topics;
//     for (Problem p : bank) {
//         topics.insert(p.getTopic());
//     }

//     // Used for random generation
//     std::random_device rd;
//     std::mt19937 gen(rd());

//     while (true) {
//         std::shuffle(bank.begin(), bank.end(), gen);
//         std::vector<Problem> testProblems(bank.begin(), bank.begin() + NUM_PROBLEMS);
//         if (valid(testProblems, topics)) {
//             return testProblems;
//         }
//     }
// }

int main() {
    Part2FileReader fileReader;
    std::vector<Problem*> bank = fileReader.readProblems(BANK);

    std::set<std::string> TOPICS;
    std::set<std::string> AUTHORS;
    for (Problem* problem : bank) {
        Part2Problem* p = dynamic_cast<Part2Problem*>(problem);
        if (p){
            TOPICS.insert(p->getTopic());
            AUTHORS.insert(p->getAuthor());
        }
    }

    auto authorConstraint = AuthorConstraint(AUTHORS, 1, 2);
    auto topicConstraint = TopicConstraint(TOPICS, 1, 2);
    auto LongConstraint = LongConstraint(NUM_LONG, NUM_LONG);

    std::vector<TestConstraint*> constraints = {&authorConstraint, &topicConstraint, &LongConstraint};
    Part2ProblemSelector selector(constraints, NUM_LONG, NUM_LONG, 1, 2, 1, 2);
    std::vector<Problem*> test = selector.selectProblem(bank, NUM_PROBLEMS);

    Part2TestFormatter formatter(
        TEX_HEADER,
        CONTENT_HEADER,
        CLASS,
        TERM,
        EXAM,
        TIME,
        FORM,
        TITLE,
        NUM_PROBLEMS
    );
    formatter.formatTest(test, TITLE, FILENAME);
    return 0;
}