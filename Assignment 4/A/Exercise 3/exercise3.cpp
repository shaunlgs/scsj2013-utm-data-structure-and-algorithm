// Program 6.5
#include <iostream>
#include <conio.h>
using namespace std;

int binary_search(int search_key, int array_size, const int array[])
{
	bool found = false;
	int index = -1; // -1 means record not found
	int MIDDLE,
	LEFT = 0,
	RIGHT = array_size - 1;

	while((LEFT <= RIGHT) && (!found))
	{
		MIDDLE = (LEFT + RIGHT) / 2;
		cout << "LEFT: " << LEFT << " ";
		cout << "RIGHT: " << RIGHT << " ";
		cout << "MIDDLE: " << MIDDLE << endl;
		cout << "Check if " << array[MIDDLE] << " matches search key " << search_key << endl;
		// Get middle index
		if(array[MIDDLE] == search_key)
		{
			index = MIDDLE;
			found = true;
		}
		else if(array[MIDDLE] > search_key)
			RIGHT = MIDDLE - 1; // search is focused on the left side of list
		else
			LEFT = MIDDLE + 1; // search is focused on the right side of the list
	} // end while
	return index;
} // end function

int main()
{
	int arrayExample[] = {4,7,12,15,21,26,34,35,37,40};
	// b(i)
	binary_search(4, 10, arrayExample);
	cout << endl << endl;
	// b(ii)
	binary_search(37, 10, arrayExample);
	cout << endl << endl;

	getch();
	return 0;
}
