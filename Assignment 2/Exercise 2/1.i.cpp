#include <iostream>
using namespace std;

// Program 2.8
int function_03(int n)
{
    int total=0;
    while (n > 0)
    {
        cout << n << " ";
        total += n;
        n--;
    }
    return total;
}

int main()
{
    cout << function_03(5) << endl;
    return 0;
}
