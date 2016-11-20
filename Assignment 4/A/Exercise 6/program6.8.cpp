#include <iostream>
#include <iomanip>
using namespace std;

// Program 6.8
int SequenceSearch(int search_key, int array[], int array_size)
{
    int pass;
    int index = -1; // -1 means record is not found
    int totalComparisons = 0;
    cout << setw(13) << "Iteration" << setw(13) << "pass" << setw(13) << "array[pass]" << setw(13) << "index" << setw(15) << "Number of comparisons" << endl;
    for(pass=0; pass < array_size; pass++)
    {
        totalComparisons += 1;
        if(search_key == array[pass])
        {
            index = pass; // assign current array index
            cout << setw(13) << pass << setw(13) << pass << setw(13) << array[pass] << setw(13) << index << setw(13) << totalComparisons << endl;
            break; // terminate searching
        } // end if
        cout << setw(13) << pass << setw(13) << pass << setw(13) << array[pass] << setw(13) << index << setw(13) << totalComparisons << endl;
    } // end for
    return index; // return location of value
} // end function

int main()
{
    int DATA[] = {4, 8, 19, 25, 34, 39, 45, 48, 66, 75, 89, 95};

    SequenceSearch(45, DATA, 12);
    cout << endl;
    SequenceSearch(22, DATA, 12);
    cout << endl;

    return 0;
}

/* output
    Iteration         pass  array[pass]        indexNumber of comparisons
            0            0            4           -1            1
            1            1            8           -1            2
            2            2           19           -1            3
            3            3           25           -1            4
            4            4           34           -1            5
            5            5           39           -1            6
            6            6           45            6            7

    Iteration         pass  array[pass]        indexNumber of comparisons
            0            0            4           -1            1
            1            1            8           -1            2
            2            2           19           -1            3
            3            3           25           -1            4
            4            4           34           -1            5
            5            5           39           -1            6
            6            6           45           -1            7
            7            7           48           -1            8
            8            8           66           -1            9
            9            9           75           -1           10
           10           10           89           -1           11
           11           11           95           -1           12
*/
