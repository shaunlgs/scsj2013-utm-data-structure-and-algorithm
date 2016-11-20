#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPalindrome(string word)
{
    int length = word.length();
    if(length <= 1)
    {
        return true;
    }
    if(word[0] != word[length-1])
    {
        return false;
    }
    return isPalindrome(word.substr(1,length-2));
}

int main()
{
    fstream inData;
    inData.open("palindrome.txt", ios::in);

    string word;
    int total = 0;

    while(!inData.eof())
    {
        getline(inData, word, '\n');
        if(isPalindrome(word))
        {
            cout << word << " is a palindrome." << endl;
            total += 1;
        }
    }

    cout << "There are " << total << " palindrome(s)." << endl;
    return 0;
}
