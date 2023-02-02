#include <iostream>
#include <map>
#include <vector>

using namespace std;

string normalize(string to_normalize)
{
    for (size_t i = 0; i < to_normalize.size(); i++)
    {
        char& c = to_normalize.at(i);

        c = tolower(c);
    }

    return to_normalize;   
}

int main(int argc, const char** argv)
{
    vector<string> words = vector<string>();
    map<string, unsigned int> count = map<string, unsigned int>();

    for (size_t i = 1; i < argc; i++)
    {
        words.push_back(string(argv[i]));
    }
    
    for (string& word : words)
    {
        string word_normalizated = normalize(word);

        map<string, unsigned int>::iterator it;

        it = count.find(word_normalizated);

        if(it == count.end()) // not found
        {
            count[word_normalizated] = 1;
            continue;
        }

        it->second++;
    }

    for(auto it = count.cbegin(); it != count.cend(); ++it)
    {
        cout << it->first << " -> " << it->second << endl;
    }

    return 0;
}