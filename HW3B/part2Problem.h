#ifndef PART2PROBLEM_H
#define PART2PROBLEM_H

#include "../BaseClass/problem.h"
#include <string>

class Part2Problem : public Problem {
    public:
        std::string getQuestion() const override { return question;}
        std::string getAnswer() const override { return answer;}
        std::string getTopic() const { return topic; }
        std::string getAuthor() const { return author; }
        bool getIsLongProblem() const { return isLongProblem; }

        Part2Problem(std::string q, std::string a, std::string t, std::string au, bool isLong)
            : question(q), answer(a), topic(t), author(au), isLongProblem(isLong) {}
    private:
        std::string question;
        std::string answer;
        std::string topic;
        std::string author;
        bool isLongProblem;
};




#endif