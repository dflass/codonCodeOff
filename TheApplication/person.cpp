
#include "person.h"

person::person(string perName, string snpId, string all)
{
    name = perName;
//    vector<string> a;
//    a.push_back(snpId);
//    a.push_back(all);
    allelle.insert(std::make_pair(snpId,all));
}

void person::push(string snpId, string all){
    //vector<string> a = {snpId, all};
//    vector<string> a;
//    a.push_back(snpId);
//    a.push_back(all);

//    allelle.push_back(a);
    allelle.insert(std::make_pair(snpId,all));
}
