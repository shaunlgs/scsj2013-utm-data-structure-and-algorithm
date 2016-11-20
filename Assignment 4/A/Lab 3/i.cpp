// Program 6.3
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
using namespace std;

class Person
{
    public:
        int key;
        char name[30];
        char uta[30];
    public:
        Person()
        {
            Person(0, "", "");
        }
        Person(int key, char name[], char uta[])
        {
            this->key = key;
            strcpy(this->name, name);
            strcpy(this->uta, uta);
        }
};

/***************Function prototypes***************/
void display_array(Person list[], int size, char title[]);
void IsihanCepat(Person list[], int awal, int akhir);
int PmBahagi(Person T[], int awal, int akhir);
int Carian(int key, Person list[], int size);
int binary_search(int key, Person list[], int size);
void pause();
/************************************************/
const int COUNT = 14; // number of array elements. Global constant
int main(void)
{
    // array T, object Person
    Person T[COUNT] = {
        Person(21, "Utada", "ichi"),
        Person(61, "Hikaru", "ni"),
        Person(11, "Ito", "san"),
        Person(31, "Yuna", "shi"),
        Person(79, "Hamasaki", "yon"),
        Person(83, "Ayumi", "go"),
        Person(68, "Koda", "roku"),
        Person(78, "Kumi", "Shichi"),
        Person(96, "Namie", "nana"),
        Person(87, "Amuro", "hachi"),
        Person(57, "Otsuka", "ku"),
        Person(88, "Ai", "kyu"),
        Person(69, "Kaoru", "jyuu"),
        Person(49, "Amane", "jyuichi")
    };
    display_array(T, COUNT, "Original Array:");

    /********** SORT *****************/
    cout << "****** SORTING **********\n\n";
    IsihanCepat(T, 0, COUNT-1);
    display_array(T, COUNT, "Sorted Array:");
    //pause();

    /********** Search *****************/
    cout << "****** Searching **********\n\n";
    int key; // search key
    int index; // the array index for the element found from searching process
    cout << "Enter search key: ";
    cin >> key;
    //pause();

    // call the search function here
    //index = Carian(key, T, COUNT);
     index = binary_search(key, T, COUNT);
    cout << "\n\nSearch result:\n";
    cout << "\tIndex element: " << index << endl;
    if(index > -1)
    {
        cout << "\tKey: " << T[index].key << endl;
        cout << "\tName: " << T[index].name << endl;
        cout << "\tTitle: " << T[index].uta << endl;
    }
    else
    {
        cout << "\tRecord not found!!!" << endl;
    }
    pause();
}

/*************************************************************
Function: display_array
Description: Print object Person from array
*************************************************************/
void display_array(Person list[], int size, char title[])
{
    int i;
    cout << title << endl << endl;
    cout << " Key \t  Name \t Title\n";
    cout << "-----\t -------\t------- \n";

    for(i=0; i<size; i++)
        cout << list[i].key << "\t" << list[i].name << "\t\t" << list[i].uta << "\n";
    cout << endl;
}

/*************************************************************
Function: IsihanCepat
Description: Execute Quick Sort Algorithm
*************************************************************/
void IsihanCepat(Person list[], int awal, int akhir)
{
    int potong;

    if(awal<akhir)
    {
        potong = PmBahagi(list, awal, akhir);
        IsihanCepat(list, awal, potong);
        IsihanCepat(list, potong+1, akhir);
    }
}

int PmBahagi(Person T[], int awal, int akhir)
{
    int pivot;
    int ulang, bahagi, drbawah, dratas;
    Person temp;

    pivot = T[awal].key;
    drbawah = awal;
    dratas = akhir;
    ulang = 1;

    while(ulang)
    {
        while(T[dratas].key>pivot)
        {
            // search for values less than pivot from the top of array
            dratas--;
        }
        while(T[drbawah].key<pivot)
        {
            // search for values bigger than pivot from bottom of array
            drbawah++;
        }

        if(drbawah < dratas)
        {
            // swap location of pivot
            temp = T[drbawah];
            T[drbawah] = T[dratas];
            T[dratas] = temp;
        }
        else{
            ulang = 0;
            bahagi = dratas;
        }
    } // end while (ulang)
    return bahagi;
} // end function PmBahagi

/*************************************************************
Function: Carian
Description: Execute Sequential Search Process
Parameters:
    key, which is the search key
    list, which is the array, assume the array list is sorted in ascending order
    size, the number of records in array
Returns:
    If record is found, the record index will be returned.
    Otherwise, if not found, value -1 will be returned.
*************************************************************/
int Carian(int key, Person list[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        if (key == list[i].key) return i; // if record is found
        if (key<list[i].key) return -1;
        // if search key > current record key,
        // no need to continue search on the remaining records
    }
    return -1;
}

/*************************************************************
Function: binary_search
Description: Execute Binary Search Process
Parameters:
    key, which is the search key
    list, which is the array, assume the array list is sorted in ascending order
    size, the number of records in array
Returns:
    If record is found, the record index will be returned.
    Otherwise, if not found, value -1 will be returned.
*************************************************************/
int binary_search(int key, Person list[], int size)
{
    // local variable
    bool found = false;
    int MIDDLE, LEFT = 0, RIGHT = size-1;
    int i = -1;
    /*****COMPLETE THE binary_search() FUNCTION HERE*************/
    while((LEFT <= RIGHT) && i == -1)
    {
        MIDDLE = (LEFT + RIGHT) / 2;
        if(list[MIDDLE].key == key)
        {
            i = MIDDLE;
        }
        else if (list[MIDDLE].key > key)
            RIGHT = MIDDLE - 1;
        else
            LEFT = MIDDLE + 1;
    }
    return i;
}

/*************************************************************
Function: pause
Description: pausing the screen for a while to view output
*************************************************************/
void pause()
{
    cout << "\n\nPress any key....\n";
    getch();
}
