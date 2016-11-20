#include <iostream>
#include <conio.h>
using namespace std;

class Record
{
	int k;
	public:
		Record(int k){
			this->k = k;
		}
		int getK(){
			return this->k;
		}
};

int sequenceSearch(int key, Record array[], int array_size)
{
	int index = -1;
	for(int i=0; i<array_size; i++)
	{
		if(array[i].getK() == key)
		{
			index = i;
			break;
		}
	}
	return index;
}

int improvedSequenceSearch(int key, Record array[], int array_size)
{
	int index = -1;
	for(int i=0; i<array_size; i++)
	{
		if(key < array[i].getK())
		{
			break;
		}
		else if(array[i].getK() == key)
		{
			index = i;
			break;
		}
	}
	return index;
}

int main()
{
	cout << "a.----------------------------------------------" << endl;
	Record recordArray[] = {49, 21, 34, 35, 40, 7, 15, 26, 12, 4};
	cout << "49 found at index " << sequenceSearch(49, recordArray, 10) << endl;
	cout << "4 found at index " << sequenceSearch(4, recordArray, 10) << endl;
	cout << "37 found at index " << sequenceSearch(37, recordArray, 10) << endl;
	
	cout << "b.----------------------------------------------" << endl;
	Record recordArray2[] = {4, 7, 12, 15, 21, 26, 34, 35, 40, 49};
	cout << "49 found at index " << improvedSequenceSearch(49, recordArray2, 10) << endl;
	cout << "4 found at index " << improvedSequenceSearch(4, recordArray2, 10) << endl;
	cout << "37 found at index " << improvedSequenceSearch(37, recordArray2, 10) << endl;
	
	getch();
	return 0;
}
