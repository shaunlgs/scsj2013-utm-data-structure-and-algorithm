// Program 2.7
#include <iostream>
using namespace std;

int Calc(int n)
{
    if (n < 0)
        return n;
    else
        return Calc(n-1)* Calc(n-2);
}

int main()
{
    cout << Calc(5) << endl;
    return 0;
}
