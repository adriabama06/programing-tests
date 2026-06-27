#include <iostream>
#include <cstring>

using namespace std;

char* sometest(char* toadd)
{
    char* base = "Hello ";
    const int d = strlen(base)+strlen(toadd)+1;
    char added[d];

    cout << strlen(base) << " - base" << endl;
    cout << strlen(toadd) << " - toadd" << endl;
    for(int i = 0; i < strlen(base); i++)
    {
        added[i] = base[i];
    }
    for(int i = 0; i < strlen(toadd); i++)
    {
        added[i] = toadd[i];
    }
    cout << strlen(added) << " - added" << endl;
    return added;
}
int main()
{
    char* text = "adri";
    cout << "char* join:" << endl;
    cout << sometest(text) << "." << endl; // 9 really is 8 + 1 -> '\0'
    return 0;
}