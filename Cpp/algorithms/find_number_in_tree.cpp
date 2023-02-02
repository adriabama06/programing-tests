/*
LINE 1:       [1]
LINE 2:     [2, 3]
LINE 3:   [4, 5, 6]
LINE 4: [7, 8, 9, 10]
...

Work find line where can i find "OBJECTIVE"
*/
const unsigned int OBJECTIVE = 2023;


#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned int index = 1;
    unsigned int last_element_in_list = 1;

    for(; true; index++)
    {
        vector<unsigned int> list = vector<unsigned int>();

        for(unsigned int elements = 0; elements < index; elements++)
        {
            list.push_back(elements + last_element_in_list);
        }

        // if(find(list.begin(), list.end(), OBJECTIVE) != list.end()) break;

        bool leave = false;
        for(unsigned int i = 0; i < list.size(); i++) {
            if(list.at(i) >= OBJECTIVE)
            {
                leave = true;
                break;
            }
        }
        if(leave) break;

        last_element_in_list = list.at(list.size() - 1) + 1;
    }

    cout << "Line: " << index << endl;

    return 0;
}