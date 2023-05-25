#ifndef SYNONYMTABLE_H
#define SYNONYMTABLE_H

#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class SynonymTable
{
private:
    map<string, vector<string>> _synonyms;
public:
    SynonymTable();
    void addSynonyms(string synonymsLine);
    string getRndSynonym(string word);
};

#endif // SYNONYMTABLE_H
