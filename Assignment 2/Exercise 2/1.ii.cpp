#include <iostream>
using namespace std;

// Program 2.8
int function_03(int n)
{
    int total=0;
    if(n == 0)
        return 0;
    cout << n << " ";

    return n + function_03(n-1);
}

int main()
{
    cout << function_03(5) << endl;
    return 0;
}
