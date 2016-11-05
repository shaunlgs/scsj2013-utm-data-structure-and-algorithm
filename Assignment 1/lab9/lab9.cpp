#include <iostream>
#include <fstream>
#include <conio.h>
using namespace std;

int main()
{
	char answer [ ] = "BACDACBDABBACADAABACABCDA";
	
	fstream inData;
	inData.open("data.txt", ios::in);
	
	char tempAnswer[25];
	// to accomodate 20 students
	int tempMatrix[20];
	int score[20];
	int studentIndex = 0;
	char grade;
	
	while(!inData.eof())
	{
		inData >> tempMatrix[studentIndex];
		inData >> tempAnswer;
		score[studentIndex] = 0;
		for(int i=0; i<25; i++)
		{
			if(tempAnswer[i] != answer[i])
			{
				score[studentIndex] -= 1;
			}
			else
			{
				score[studentIndex] += 4;
			}
		}
		studentIndex += 1;
	}
	
	for(int i=0; i<studentIndex; i++)
	{
		if(score[i] >= 75 && score[i] <= 100)
		{
			grade = 'A';
		}
		else if(score[i] >= 65 && score[i] <= 74)
		{
			grade = 'B';
		}
		else if(score[i] >= 55 && score[i] <= 64)
		{
			grade = 'C';
		}
		else if(score[i] >= 45 && score[i] <= 54)
		{
			grade = 'D';
		}
		else if(score[i] >= 0 && score[i] <= 44)
		{
			grade = 'E';
		}
		cout << tempMatrix[i] << ": " << grade << endl;
	}
	
	inData.close();
	getch();
	
	return 0;
}
