// Program 6.4
#include <iostream>
#include <conio.h>
using namespace std;

int SequenceSearch(int search_key, int array[], int array_size)
{
	int p;
	cout << "int p;" << endl;
	int index = -1; // -1 means record is not found
	cout << "int index = -1;" << endl;
	
	for(p=0; p<array_size; p++)
	{
		cout << "Enter for loop" << endl;
		if(search_key == array[p])
		{
			cout << "Enter if" << endl;
			index = p; // assign current array index
			break; // terminate searching
		} // end if
	} // end for
	return index; // return location of value
} // end function

int main()
{
	int arrayExample[] = {49, 21, 34, 35, 40, 7, 15, 26, 12, 4};
	cout << "-------------------------------------" << endl;
	cout << "Sequence search for 49" << endl;
	SequenceSearch(49, arrayExample, 10);
	cout << "-------------------------------------" << endl;
	cout << "Sequence search for 4" << endl;
	SequenceSearch(4, arrayExample, 10);
	cout << "-------------------------------------" << endl;
	cout << "Sequence search for 37" << endl;
	SequenceSearch(37, arrayExample, 10);
	
	getch();
	return 0;
}
