#include <iostream>
using namespace std;

void draw_recursion(int n, int frontSpace)
{
    if(n == 1)
    {
        for(int i=0; i<frontSpace; i++)
            cout << " ";
        cout << "#";
    }
    else
    {
       for(int i=0; i<frontSpace; i++)
            cout << " ";
        for(int i=0; i<n; i++)
            cout << "# ";
        cout << endl;

        draw_recursion(n-1, frontSpace+1);

        cout << endl;

        for(int i=0; i<frontSpace; i++)
            cout << " ";
        for(int i=0; i<n; i++)
            cout << "# ";
    }
}

void draw_iterative(int n)
{
    int frontSpace = 1;
    int temp = n;
    while(temp != 0)
    {
       for(int i=0; i<frontSpace; i++)
       {
           cout << " ";
       }
        for(int i=0; i<temp; i++)
        {
            cout << "# ";
        }
        cout << endl;
        frontSpace += 1;
        temp -= 1;
    }
    frontSpace = n - 1;
    temp = 2;
    while(temp <= n)
    {
        for(int i=0; i<frontSpace; i++)
       {
           cout << " ";
       }
        for(int i=0; i<temp; i++)
        {
            cout << "# ";
        }
        cout << endl;
        frontSpace -= 1;
        temp += 1;
    }
}


int main()
{
    int input;
    cout << "Enter the input: ";
    cin >> input;

    draw_recursion(input, 1);
    cout << endl;
    cout << endl;
    draw_iterative(input);


    return 0;
}

/*
For draw_iterative():

1
1

while loop
n
n.(n.(n+1)/2)
n.(n.(n+1)/2).1
n.(n.(n+1)/2)
n.(n.(n+1)/2).1
n.1
n.1
n.1

1
1

while loop
same

Total executions
= 4 + (n*4 + n.(n.(n+1)/2)*4) * 2
= 4 + (4n+4n(n.(n+1)/2))*2
= 4 + (4n+4n(n^2+n)/2)*2
= 4 + (8n+4n(n^2+n))
= 4 + (8n+4n^3+4n^2)
= 4n^3 + 4n^2 + 8n + 4

Time complexity O(n^3)
