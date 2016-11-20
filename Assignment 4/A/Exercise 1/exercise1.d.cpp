// Program 6.4
#include <iostream>
#include <conio.h>
using namespace std;

int ImprovedSequenceSearch(int search_key, int array[], int array_size)
{
	int p;
	cout << "int p;" << endl;
	int index = -1; // -1 means record is not found
	cout << "int index = -1;" << endl;
	
	for(p=0; p<array_size; p++)
	{
		cout << "Entering for loop" << endl;
		if(search_key < array[p])
		{
			cout << "Not in the list" << endl;
			break; // loop repetition terminated when the value of search key is smaller than the current array element
		}
		else if(search_key == array[p])
		{
			index = p; // assign current array index
			cout << "Found" << endl;
			break; // terminate searching
		} // end if
	} // end for
	return index; // return location of value
} // end function

int main()
{
	int arrayExample[] = {4, 7, 12, 15, 21, 26, 34, 35, 40, 49};
	cout << "-------------------------------------" << endl;
	cout << "Sequence search for 49" << endl;
	ImprovedSequenceSearch(49, arrayExample, 10);
	cout << "-------------------------------------" << endl;
	cout << "Sequence search for 4" << endl;
	ImprovedSequenceSearch(4, arrayExample, 10);
	cout << "-------------------------------------" << endl;
	cout << "Sequence search for 37" << endl;
	ImprovedSequenceSearch(37, arrayExample, 10);
	
	getch();
	return 0;
}
