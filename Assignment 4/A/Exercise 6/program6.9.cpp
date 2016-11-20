// Program 6.9
#include <iostream>
#include <iomanip>
using namespace std;

int binary_search(int search_key, int array_size, const int array[])
{
    bool found = false;
    int index = -1; // -1 means record not found
    int MIDDLE,
    LEFT = 0,
    RIGHT = array_size - 1;
    int iteration = 0;
    int numComparisons = 0;
    cout << setw(7) << "Iteration" << setw(7) << "LEFT" << setw(7) << "RIGHT" << setw(7) << "MIDDLE" << setw(13) << "array[MIDDLE]" << setw(10) << "index" << setw(15) << "Number of comparisons" << endl;
    while((LEFT <= RIGHT) && (!found))
    {
        cout << setw(7) << iteration;
        MIDDLE = (LEFT + RIGHT) / 2; // Get middle index
        cout << setw(7) << LEFT << setw(7) << RIGHT << setw(7) << MIDDLE;
        cout << setw(13) << array[MIDDLE];
        if(array[MIDDLE] == search_key)
        {
            index = MIDDLE;
            found = true;
            numComparisons += 1;
            cout << setw(10) << index;
            cout << setw(15) << numComparisons << endl;
        }
        else if (array[MIDDLE] > search_key)
        {
            numComparisons += 1;
            RIGHT = MIDDLE - 1; // search is focused on the left side of the list
            cout << setw(10) << index;
            cout << setw(15) << numComparisons << endl;
        }
        else
        {
            numComparisons += 1;
            LEFT = MIDDLE + 1; // search is focused on the right side of the list
            cout << setw(10) << index;
            cout << setw(15) << numComparisons << endl;
        }
    } // end while
    return index;
} // end function

int main()
{
    int DATA[] = {4, 8, 19, 25, 34, 39, 45, 48, 66, 75, 89, 95};

    binary_search(45, 12, DATA);
    cout << endl;
    binary_search(22, 12, DATA);
    cout << endl;

    return 0;
}

/* output
Iteration   LEFT  RIGHT MIDDLEarray[MIDDLE]     indexNumber of comparisons
      0      0     11      5           39        -1              1
      0      6     11      8           66        -1              2
      0      6      7      6           45         6              3

Iteration   LEFT  RIGHT MIDDLEarray[MIDDLE]     indexNumber of comparisons
      0      0     11      5           39        -1              1
      0      0      4      2           19        -1              2
      0      3      4      3           25        -1              3
*/
