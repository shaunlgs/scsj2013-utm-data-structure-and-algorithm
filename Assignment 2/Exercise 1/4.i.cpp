// Program 2.5
#include <iostream>
using namespace std;

void printIntegers(int n);

int main()
{
    int number;
    cout<<"\nEnter an integer value :";
    cin >> number;
    printIntegers(number);
    return 0;
}
void printIntegers (int nom)
{
    if (nom >= 1)
        cout << "\Value : " << nom<<endl;
    printIntegers (nom-2);
}
