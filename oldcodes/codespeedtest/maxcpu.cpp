#include <iostream>
using namespace std;

long long int doloop(long long int n)
{
    cout << n;
    long long int k = n * 5 * 5 * 5 * 5;
    doloop(k);
    return 0;
}

int main()
{
    // no se como XD ademas es C++
    long long int n = 5 * 5 * 5 * 5;
    doloop(n);
    return 0;
}