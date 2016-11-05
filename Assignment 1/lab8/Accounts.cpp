// implementation file
// Fuke baneL Accounts.cpp
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include "Accounts.h"
using namespace std;

Account::Account()
{
					strcpy(accountName, "");
					strcpy(accountNumber, "");
                  strcpy(accountName,"Maybank personal account");
                  strcpy(accountNumber,"ABC123");
                  accountType = 1;
                  accountBalance = 0.00;
}

Account::Account(float amount)
{
					strcpy(accountName, "");
					strcpy(accountNumber, "");
                  strcpy(accountName,"Maybank personal account");
                  strcpy(accountNumber,"ABC123");
                  accountType = 1;
                     accountBalance = amount;
}

Account::Account(char* temp1, char* temp2, int temp3, float temp4)
{
	
					strcpy(accountName, "");
					strcpy(accountNumber, "");
                  strcpy(accountName,temp1);
                  strcpy(accountNumber,temp2);
                  accountType = temp3;
                  accountBalance = temp4;
}

float Account::getBalance()
{
                     return accountBalance;
}

void Account::withdraw()
{
                   if(accountBalance <= 0)
                   {
                                     cout << "Cannot withdraw" << endl;
                   }
}

void Account::deposit(float amount)
{
     accountBalance += amount;
}

void Account::printDetail()
{
     cout << "Account Name: " << accountName << endl;
     cout << "Account Number: " << accountNumber << endl;
     cout << "Account Type: " << accountType << endl;
     cout << "Account Balance: " << fixed << showpoint << setprecision(2) << accountBalance << endl;
     cout << endl;
}
