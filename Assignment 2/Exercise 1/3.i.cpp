#include <iostream>
using namespace std;

// Program 2.3
void function_01(int n)
{
    cout << "Calling function_01\n";
    if (n < 5)
        function_01(n - 1);
}

// Program 2.4
void function_02(int n)
{
    if (n > 1)
        function_02(n - 2);
    cout << n << " ";
}

void function_01_corrected(int n)
{
    cout << "Calling function_01_corrected\n";
    if (n == 0)
        return;
    if (n < 5)
        function_01_corrected(n - 1);
}

int main()
{
    //function_01(3);
    function_02(3);
    function_01_corrected(3);
    return 0;
}
