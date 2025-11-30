#include "part2authorConstraint.h"
#include "part2Problem.h"
#include <map>


bool AuthorConstraint::valid(const std::vector<Problem*>& test) const {
    std::map<std::string, int> authorCount;

    for (Problem* problem : test) {
        Part2Problem* p = dynamic_cast<Part2Problem*>(problem);
        if (p) {
            authorCount[p->getAuthor()]++;
        }
    }

    for (const auto& author : authors){
        int count = authorCount[author];
        if (count < minPerAuthor || count > maxPerAuthor) { 
            return false;
        }
    }
    return true;
}