#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>

using std::vector;
using std::string;

class person
{
person(string perName, string snpId, string all);
public:

    void push(string snpId, string all);
    string name;
    vector<vector<string> > allelle;

//signals:

//public slots:
}

#endif // PERSON_H