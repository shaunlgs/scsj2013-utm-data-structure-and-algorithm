#include <iostream>
#include <string.h>
using namespace std;

class month
{
    public:
        int key;
        char monthName[20];
};

int Binary_Search(int search_key, month arrayA[], int array_size)
{
    bool found = false;
    int MIDDLE, LEFT = 0, RIGHT = array_size - 1;
    int i = -1;
    cout << "LEFT\tRIGHT\tMIDDLE\ti\tFOUND" << endl;
    while((LEFT <=RIGHT) && (!found))
    {
        MIDDLE = (LEFT + RIGHT) / 2;
        cout << LEFT << "\t" << RIGHT << "\t" << MIDDLE << "\t";
        if(arrayA[MIDDLE].key == search_key)
        {
            i = MIDDLE;
            found = true;
            cout << i << "\t" << found << endl;
        }
        else if (arrayA[MIDDLE].key < search_key)
        {
            RIGHT = MIDDLE - 1; // search is focused on the left side of list
            cout << i << "\t" << found << endl;
        }
        else
        {
            LEFT = MIDDLE + 1; // search is focused on the right side of the list
            cout << i << "\t" << found << endl;
        }
    } // end while
    return i;
} // end function

int main()
{
    month arrayA[7];

    arrayA[0].key = 12;
    strcpy(arrayA[0].monthName, "December");
    arrayA[1].key = 10;
    strcpy(arrayA[0].monthName, "October");
    arrayA[2].key = 8;
    strcpy(arrayA[0].monthName, "August");
    arrayA[3].key = 7;
    strcpy(arrayA[0].monthName, "July");
    arrayA[4].key = 5;
    strcpy(arrayA[0].monthName, "May");
    arrayA[5].key = 4;
    strcpy(arrayA[0].monthName, "April");
    arrayA[6].key = 2;
    strcpy(arrayA[0].monthName, "February");

    Binary_Search(12, arrayA, 7);

    return 0;
}

/*output
LEFT    RIGHT   MIDDLE  i       FOUND
0       6       3       -1      0
0       2       1       -1      0
0       0       0       0       1

*/
