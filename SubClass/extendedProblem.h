#ifndef EXTENDEDPROBLEM_H
#define EXTENDEDPROBLEM_H

#include "../BaseClass/problem.h"
#include <string>

class ExtendedProblem : public Problem {
    public:
        std::string getQuestion() const override { return question;}
        std::string getAnswer() const override { return answer;}
        std::string getTopic() const { return topic; }
        int getDifficulty() const { return difficulty; }

        ExtendedProblem(std::string q, std::string a, std::string t, int d)
            : question(q), answer(a), topic(t), difficulty(d) {}
    private:
        std::string question;
        std::string answer;
        std::string topic;
        int difficulty;
};




#endif