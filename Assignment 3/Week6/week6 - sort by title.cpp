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

main ( )
{
    book myBook[size];
    for (int j=0;j<size;j++)
        myBook[j].getData();
    for (int j=0;j<size;j++)
        myBook[j].print();
    // sort the array using bubble sort
    BubbleSort(myBook,size) ;
    cout << "\nThe list after sort based on the title -> \n";
    for (int j=0;j<size;j++)
        myBook[j].print();
    return 0;
}// end main()

/* OUTPUT
What is the price of the book: 200.00
What is the year of the book: 2015
What is the author of the book: JK Rowling
What is the title of the book: Harry potter

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
What is the author of the book: Levvy
What is the title of the book: Sorting algorithms

What is the price of the book: 20.00
What is the year of the book: 2014
What is the author of the book: Shaun
What is the title of the book: Algorithm made simple

What is the price of the book: 150.00
What is the year of the book: 2015
What is the author of the book: Suhadah
What is the title of the book: Algorithm visualization

Book price: 200.00
Book year: 2015
Book author: JK Rowling
Book title: Harry potter

Book price: 140.00
Book year: 2016
Book author: CS Lewis
Book title: Thunderbolt

Book price: 12.00
Book year: 2014
Book author: Pewter
Book title: The programming of c++

Book price: 300.00
Book year: 2015
Book author: Levvy
Book title: Sorting algorithms

Book price: 20.00
Book year: 2014
Book author: Shaun
Book title: Algorithm made simple

Book price: 150.00
Book year: 2015
Book author: Suhadah
Book title: Algorithm visualization


The list after sort based on the title ->
Book price: 20.00
Book year: 2014
Book author: Shaun
Book title: Algorithm made simple

Book price: 150.00
Book year: 2015
Book author: Suhadah
Book title: Algorithm visualization

Book price: 200.00
Book year: 2015
Book author: JK Rowling
Book title: Harry potter

Book price: 300.00
Book year: 2015
Book author: Levvy
Book title: Sorting algorithms

Book price: 12.00
Book year: 2014
Book author: Pewter
Book title: The programming of c++

Book price: 140.00
Book year: 2016
Book author: CS Lewis
Book title: Thunderbolt
*/
