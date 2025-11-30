#ifndef PART2AUTHORCONSTRAINT_H
#define PART2AUTHORCONSTRAINT_H

#include "../BaseClass/testConstraint.h"
#include <string>
#include <set>

class AuthorConstraint : public TestConstraint {
public:
    AuthorConstraint(const std::set<std::string>& authors, int minPerAuthor, int maxPerAuthor)
        : authors(authors), minPerAuthor(minPerAuthor), maxPerAuthor(maxPerAuthor) {}
    
    bool valid(const std::vector<Problem*>& test) const override;
    
private:
    std::set<std::string> authors;
    int minPerAuthor;
    int maxPerAuthor;
};

#endif