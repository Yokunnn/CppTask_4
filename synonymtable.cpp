#include "synonymtable.h"

#include <string>
#include <vector>
#include <sstream>

using namespace std;

SynonymTable::SynonymTable()
{

}

void SynonymTable::addSynonyms(string synonymsLine)
{
    stringstream synonymsStream(synonymsLine);
    string word;
    vector<string> words;
    while(synonymsStream >> word)
    {
        words.push_back(word);
    }

    for (string w1 : words)
    {
        vector<string> synonyms;
        for (string w2 : words)
        {
            if(w1!=w2)
            {
                synonyms.push_back(w2);
            }
        }
        _synonyms[w1] = synonyms;
    }
}

string SynonymTable::getRndSynonym(string word)
{
    map<string, vector<string>> :: iterator it = _synonyms.find(word);
    if(it==_synonyms.end())
    {
        return word;
    }
    vector<string> temp = _synonyms[word];
    int rnd = rand() % temp.size();
    return temp[rnd];
}
