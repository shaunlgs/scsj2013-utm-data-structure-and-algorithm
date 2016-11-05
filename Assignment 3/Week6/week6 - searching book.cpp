#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

const int size = 6;

class book
{
    private:
        // data members should be private
        float price;
        int year;
        char author[20], title[25];
    public:
        void getData();
        void print( );
        char * getTitle() {return title;}
        float getPrice() { return price;}
}; // end book declaration

void book::getData()
{
    float price;
    int year;
    char author[20];
    char title[25];
    cout << "What is the price of the book: ";
    cin >> price;
    cin.ignore();
    cout << "What is the year of the book: ";
    cin >> year;
    cin.ignore();
    cout << "What is the author of the book: ";
    cin.getline(author, 20, '\n');
    cout << "What is the title of the book: ";
    cin.getline(title, 25, '\n');
    cout << endl;
    this->price = price;
    this->year = year;
    strcpy(this->author, author);
    strcpy(this->title, title);
}

void book::print()
{
    cout << "Book price: " << setprecision(2) << fixed << this->price << endl;
    cout << "Book year: " << this->year << endl;
    cout << "Book author: " << this->author << endl;
    cout << "Book title: " << this->title << endl;
    cout << endl;
}

void BubbleSort(book data[],int listSize)
{
    int x ;
    book tempValue;
    for ( int pass =1;pass < listSize; pass++ )
    {
        for ( int x = 0; x < listSize - pass; x++)
        {
            //compare adjacent list based on the book's title
            if ((strcmp(data[x].getTitle(),data[x+1].getTitle()))>0)
            // swap if the data is not in the right order
            {
                tempValue = data[x];
                data[x] = data[x+1];
                data[x+1] = tempValue;
            }// end if
        } // end for loop (internal)
    } // end for loop (external)
} // end BubbleSort() function

int SortedSeqSearch (book array[ ], int array_size, char search_key[])
{
    int p;
    int index = -1; //-1 means record not found yet
    for ( p = 0; p < array_size; p++ )
    {
        if ((strcmp(search_key,array [p].getTitle())) < 0 )
            break; // loop repetition terminated when the value of
        // search key is smaller than the current array element
        else if ((strcmp(search_key, array [p].getTitle())) == 0)
        { index = p; // found at current array index
            break; // stop searching
        } // end else-if
    }//end for
    return index;
} //end SortedSeqSearch() function

main ( )
{
    book myBook[size];
    for (int j=0;j<size;j++)
        myBook[j].getData();
    // sort the array using bubble sort
    char search_key[25];
    BubbleSort(myBook,size) ;
    cout << "\nPlease insert the book¡¯s title to be searched...";
    cin.getline(search_key,25);
    // search the book
    if (SortedSeqSearch (myBook, size, search_key)== -1)
        cout << "\n Sorry the book is not found.";
    else
        cout << "\n Yes, we have the book in our stock.";
    return 0;
}// end main()

/* output
What is the price of the book: 200.00
What is the year of the book: 2015
What is the author of the book: JK Rowling
What is the title of the book: Harry Potter

What is the price of the book: 140.00
What is the year of the book: 2016
What is the author of the book: CS Lewis
What is the title of the book: Thunderbolt

What is the price of the book: 12.00
What is the year of the book: 2014
What is the author of the book: Pewter
What is the title of the book: The programming of c++

What is the price of the book: 300.00
What is the year of the book: 2015
What is the author of the book: Levy
What is the title of the book: Sorting algorithms

What is the price of the book: 20.00
What is the year of the book: 2014
What is the author of the book: Shaun
What is the title of the book: Algorithm made simple

What is the price of the book: 150.00
What is the year of the book: 2015
What is the author of the book: Suhadah
What is the title of the book: Algorithm visualization


Please insert the book¡¯s title to be searched...Algorithm made simple

 Yes, we have the book in our stock.
*/
