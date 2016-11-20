// Program 2.6
#include <iostream>
using namespace std;

int GCD(int a, int b);

int main()
{
    int first=3, second=8;
    cout<<GCD(first,second)<<endl;
    return 0;
}

int GCD(int a, int b)
{
    if (a % b == 0) // BASE CASE
        return b;
    else // RECURSIVE
        return GCD(b, a%b);
}
