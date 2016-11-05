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
            //compare adjacent list based on the book's price
            if (data[x].getPrice()> data[x+1].getPrice())
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
    cout << "\nThe list after sort based on the price -> \n";
    for (int j=0;j<size;j++)
        myBook[j].print();
    return 0;
}// end main()


/*
What is the price of the book: 15.00
What is the year of the book: 2500
What is the author of the book: shaun ling
What is the title of the book: book of narnia

What is the price of the book: 250.00
What is the year of the book: 2012
What is the author of the book: Suhadah
What is the title of the book: Book of magic

What is the price of the book: 12.00
What is the year of the book: 2015
What is the author of the book: Bahrim
What is the title of the book: Book of wisdom

What is the price of the book: 30.00
What is the year of the book: 2014
What is the author of the book: Ali
What is the title of the book: Book of cooking

What is the price of the book: 50.00
What is the year of the book: 2016
What is the author of the book: Abu
What is the title of the book: Book of C++

What is the price of the book: 150.00
What is the year of the book: 2014
What is the author of the book: Maalini
What is the title of the book: Book of classes

Book price: 15.00
Book year: 2500
Book author: shaun ling
Book title: book of narnia

Book price: 250.00
Book year: 2012
Book author: Suhadah
Book title: Book of magic

Book price: 12.00
Book year: 2015
Book author: Bahrim
Book title: Book of wisdom

Book price: 30.00
Book year: 2014
Book author: Ali
Book title: Book of cooking

Book price: 50.00
Book year: 2016
Book author: Abu
Book title: Book of C++

Book price: 150.00
Book year: 2014
Book author: Maalini
Book title: Book of classes

The list after sort based on the price ->
Book price: 12.00
Book year: 2015
Book author: Bahrim
Book title: Book of wisdom

Book price: 15.00
Book year: 2500
Book author: shaun ling
Book title: book of narnia

Book price: 30.00
Book year: 2014
Book author: Ali
Book title: Book of cooking

Book price: 50.00
Book year: 2016
Book author: Abu
Book title: Book of C++

Book price: 150.00
Book year: 2014
Book author: Maalini
Book title: Book of classes

Book price: 250.00
Book year: 2012
Book author: Suhadah
Book title: Book of magic
*/
