// Application file
// lab8.cpp
#include <iostream>
#include <conio.h>
#include <fstream>
#include "Accounts.h"
using namespace std;

int main()
{
    Account account1;
    Account account2(1000.00);
    
    cout << "Two objects" << endl;
    cout << "-------------------------" << endl;

    account1.printDetail();
    account2.printDetail();
    
    Account accountArray[10];
    
    fstream inData;
    inData.open("accountData.txt", ios::in);
    
    char name[50];
    char number[50];
    int type;
    float balance;
    
    for(int i=0; i<10; i++)
    {
		inData.getline(name, 40);
		inData >> number;
		inData >> type;
		inData >> balance;
		inData.ignore();
		inData.ignore();
		Account accountArrayTemp(name, number, type, balance);
		accountArray[i] = accountArrayTemp;
	}
	
    cout << "Ten objects of array" << endl;
	cout << "-------------------------" << endl;
    
	for(int i=0; i<10; i++)
	{
		accountArray[i].printDetail();
	}
    
    inData.close();

	getch();
    return 0;
}
