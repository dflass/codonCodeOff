#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::string;

class person
{

public:
    person(string perName, string snpId, string all);
    void push(string snpId, string all);
    string name;
//    vector<vector<string> > allelle;

    unordered_map<string,string> allelle;
    vector<string> confirmDis;

//signals:

//public slots:
};

#endif // PERSON_H
