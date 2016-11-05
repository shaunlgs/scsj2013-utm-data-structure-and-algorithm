// header file
// File name: Accounts.h
#include <iostream>
using namespace std;

class Account
{
      public:
             Account();
             Account(float);
             Account(char[], char[], int, float);
             float getBalance();
             void withdraw();
             void deposit(float);
             void printDetail();
      private:
              char accountName[50];
              char accountNumber[10];
              int accountType;
              float accountBalance;
};
