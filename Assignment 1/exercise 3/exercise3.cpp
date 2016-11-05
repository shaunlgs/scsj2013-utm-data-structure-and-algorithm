#include <iostream>
#include <string>
using namespace std;

// Program 2.12a
class Book
{
    // Declaration of 4 data members for class Book
    string bookName, bookAuthor, category;
    float bookPrice;
    public:
        // constructor
        Book() {
            bookName = "xxx";
            bookAuthor = "yyy";
            bookPrice = 0.0;
            category = "CS";
        }
        // member function prototype declaration
        string checkAuthor() {
            return bookAuthor;
        }
        string getCategory() {
            return category;
        }
        void giveDiscount(int);
        void printDetail() // print all info about the book
        {
            cout << bookName << bookAuthor << bookPrice << category;
        }

        // friend function declaration
        friend Book readValue();
}; // end of class declaration

// f.
void Book::giveDiscount(int discount)
{
    if(bookAuthor == "Norbahiah")
    {
        bookPrice *= bookPrice * (1 - discount);
    }
    else
    {
        cout << "No discount given." << endl;
    }
}

// non-member function declarations
void CheckBookInfo(Book[]);

// g.
void CheckBookInfo(Book book[])
{
    int numBooks = sizeof(book) / sizeof(book[0]);
    for(int i=0; i<numBooks; i++)
    {
        if(book[i].getCategory() == "CS")
        {
            book[i].printDetail();
        }
    }
}

// Program 2.12b
Book readValue()
{
    Book aBook;
    string bookName, bookAuthor, category;
    float bookPrice;
    cout << "Please enter the book title " << ": ";
    getline(cin, aBook.bookName);

    cout << "Please enter the name of the author " << ": ";
    getline(cin, aBook.bookAuthor);

    cout << "Please enter the book category " << ": ";
    getline(cin, aBook.category);

    cout << "Please enter the price of the book " << ": ";
    cin >> aBook.bookPrice;
    cin.ignore();

    return aBook;
}

main()
{
    Book myBook[8];
    int discount;
    // e. this is to read in the book title, book author, category, book price of each Book object.
    for(int i=0; i<8; i++)
    {
        myBook[i] = readValue();
    }
    cout << "Enter percentage amount of discount : ";
    cin >> discount;
    // Code to call function giveDiscount() using the array
    for(int i=0; i<8; i++)
        myBook[i].giveDiscount(discount);
    // h.
    // Statement that call function CheckBookInfo(Book[]) - 1e
    CheckBookInfo(myBook);
} // end main()







