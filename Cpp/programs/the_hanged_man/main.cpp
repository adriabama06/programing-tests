#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// in
vector<char> filter_in(string& obj, vector<char>& used) {
    vector<char> found = vector<char>();

    for (size_t i = 0; i < used.size(); i++)
    {
        char& c = used.at(i);

        if(obj.find(c) == string::npos) continue;

        found.push_back(c);
    }

    return found;
}

// not in
vector<char> filter_not_in(string& obj, vector<char>& used) {
    vector<char> not_found = vector<char>();

    for (size_t i = 0; i < used.size(); i++)
    {
        char& c = used.at(i);

        if(obj.find(c) != string::npos) continue;

        not_found.push_back(c);
    }

    return not_found;
}

string create_remain_string(string& objective, vector<char>& chars_used) {
    string result = objective;
    vector<char> chars_found = filter_in(objective, chars_used);

    for (size_t i = 0; i < result.length(); i++)
    {
        char& c = result.at(i);

        if(find(chars_found.begin(), chars_found.end(), c) != chars_found.end()) continue;
        
        c = '_';
    }

    return result;
}

void score(string& objective, vector<char>& chars_used, int& attempts, int& max_attempts) {
    cout << "<";
    for(size_t i = 0; i < objective.length(); i++) {
        cout << "-";
    }
    cout << ">" << endl << endl;


    cout << " " << create_remain_string(objective, chars_used) << endl << endl;
    cout << " " << attempts << " / " << max_attempts << endl;


    vector<char> incorrect_chars_found = filter_not_in(objective, chars_used);


    cout << " ";
    size_t len = incorrect_chars_found.size();
    for (size_t i = 0; i < len; i++) {
        cout << incorrect_chars_found.at(i);

        if(i+1 < len) {
            cout << ", ";
        }
    }
    cout << endl;

    cout << "<";
    for(size_t i = 0; i < objective.length(); i++) {
        cout << "-";
    }
    cout << ">" << endl;
}

int main(int argc, const char** argv)
{
    if(argc < 2) {
        cout << argv[0] << " <string>" << endl;
        return 0;
    }

    string objective = string(argv[1]);
    vector<char> chars_used = vector<char>();
    int attempts = 0;
    int max_attempts = 15;
    int win = 0;


    for(string input; getline(cin, input); score(objective, chars_used, attempts, max_attempts)) {
        if(input == objective) {
            win = 1;
            break;
        }

        if(input.length() == 1) {
            char& input_char = input.at(0);

            if(find(chars_used.begin(), chars_used.end(), input_char) != chars_used.end()) {
                continue;
            }

            chars_used.push_back(input_char);

            if(objective.find(input_char) == string::npos) {
                attempts++;

                if(attempts >= max_attempts) {
                    break;
                }

                continue;
            }

            if(create_remain_string(objective, chars_used) == objective) {
                win = 1;
                break;
            }
        }
    }

    score(objective, chars_used, attempts, max_attempts);

    if(win) {
        cout << "Winnn!!!" << endl;
    } else {
        cout << "Faill!!!" << endl;
    }

    return 0;
}