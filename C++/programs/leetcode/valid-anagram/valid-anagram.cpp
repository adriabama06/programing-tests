#include <iostream>

#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        int s_size = 0;
        int t_size = 0;

        for (size_t i = 0; i < s.length(); i++)
        {
            char s_char = s.at(i);
            char t_char = t.at(i);

            /* // Convert to lowercase
            if(char >= 65 && char <= 92)
            {
	            char = char + 32;
            }
            */

            s_size += s_char >= 65 && s_char <= 92 ? s_char + 32 : s_char;
            t_size += t_char >= 65 && t_char <= 92 ? t_char + 32 : t_char;
        }
        
        if(s_size != t_size) {
            return false;
        }

        return true;
    }
};

int main()
{
    string s, t;

    getline(cin, s);
    getline(cin, t);

    bool isAnagram = Solution().isAnagram(s, t);

    cout << s << " is anagram to " << t << " ? -> " << (isAnagram ? "true" : "false") << endl;
}