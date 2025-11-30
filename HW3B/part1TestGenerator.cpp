#include <ranges>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <random>
#include <map>
#include <set>
#include "..\BaseClass\problem.h"
#include "..\SubClass\extendedSelector.h"
#include ".\part1TestFormatter.h"
#include "..\SubClass\testConstraint\topicConstraint.h"
#include "..\SubClass\extendedFileReader.h"
#include "..\SubClass\testConstraint\difficultyConstraint.h"

// ****************************************************************************
// Configuration details

// Title to be printed at the beginning of the test
std::string TITLE = "Arithmetic Test";

// Source file for problem bank
std::string BANK = "arithmetic_problems.tex";

// Filename for the created test
std::string FILENAME = "simple_test.tex";

// Constraints on the problem choice.
int NUM_PROBLEMS = 20; // The test must have 20 problems.
int MIN_TOPIC = 3; // Each topic must be covered 
int MAX_TOPIC = 7; // by 3-7 problems.
std::set<std::string> TOPICS = {"addition", "subtraction", "multiplication", "division"};

int MIN_DIFFICULTY = 65; // Total difficulty (using the difficulty defined 
int MAX_DIFFICULTY = 75; // in the problem bank) must be 65-75.

// tex files to include in the test file
std::string TEX_HEADER = "answers_tex_header.tex";
std::string CONTENT_HEADER = "simple_content_header.tex";



int main() {
    ExtendedFileReader fileReader;
    std::vector<Problem*> bank = fileReader.readProblems(BANK);

    //set up topic constraint
    auto topicConstraint = new TopicConstraint(TOPICS, MIN_TOPIC, MAX_TOPIC);
    auto difficultyConstraint = new DifficultyConstraint(MIN_DIFFICULTY, MAX_DIFFICULTY);

    std::vector<TestConstraint*> constraints = {topicConstraint, difficultyConstraint};

    ExtendedSelector selector(constraints);
    std::vector<Problem*> selectedProblems = selector.selectProblem(bank, NUM_PROBLEMS);

    Part1TestFormatter formatter(TEX_HEADER, CONTENT_HEADER, FILENAME);
    formatter.formatTest(selectedProblems, TITLE, FILENAME);

    return 0;
}