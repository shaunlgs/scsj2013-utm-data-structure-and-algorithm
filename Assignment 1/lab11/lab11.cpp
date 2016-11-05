#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class Flight
{
    private:
        string destination;
        int no_Passengger;
        int Capasity;
        string status;
        float ticketPrice;
        float totalPayment;
    public:
        Flight();
        Flight(string, int, float, int);
        void book(int, char*);
        void cancel(int);
        void checkDetail();
};

Flight::Flight()
{
    this->destination = "Kuala Lumpur";
    this->Capasity = 100;
    this->ticketPrice = 200.00;
    this->no_Passengger = 0;
    this->totalPayment = 0.00;
    this->status = "Active";
}

Flight::Flight(string destination, int Capasity, float ticketPrice, int no_Passengger)
{
    this->destination = destination;
    this->Capasity = Capasity;
    this->ticketPrice = ticketPrice;
    this->no_Passengger = no_Passengger;
    // assuming its all non-senior citizen
    this->totalPayment = no_Passengger * ticketPrice;
    this->status = "Active";
}

void Flight::book(int numPassenger, char* type)
{
    int numOfCurrentPassenger = this->no_Passengger;
    for(int i=0; i<numPassenger; i++)
    {
        numOfCurrentPassenger += 1;
        if(numOfCurrentPassenger > this->Capasity)
        {
            cout << "Flight capasity is full" << endl;
            return;
        }
        else
        {
            this->no_Passengger = numOfCurrentPassenger;
        }
        // if he/she is a senior citizen, charge half price
        if(strcmp(type, "senior citizen") == 0)
        {
            this->totalPayment += this->ticketPrice * 0.5;
        }
        else
        {
            this->totalPayment += this->ticketPrice;
        }
    }
}

void Flight::cancel(int numPassenger)
{
    this->no_Passengger -= numPassenger;
    this->totalPayment -= numPassenger * this->ticketPrice * 0.5;
}

void Flight::checkDetail()
{
    cout << "Destination: " << destination << endl;
    cout << "Number of passenger: " << no_Passengger << endl;
    cout << "Capasity: " << Capasity << endl;
    cout << "Status: " << status << endl;
    cout << "Ticket Price: " << setprecision(2) << fixed << ticketPrice << endl;
    cout << "Total Payment: " << setprecision(2) << fixed << totalPayment << endl;
    cout << endl;
}

int main()
{
    // Program 2.30
    Flight Flight1_1("Kuching", 150, 120.00, 50);
    Flight Flight2_1();
    Flight1_1.book(20, "senior citizen");
    Flight1_1.cancel(2);
    Flight1_1.checkDetail();

    // Program 2.31
    Flight* Flight1;
    // (i) Declare memory for Flight1 dynamically
    Flight1 = new Flight();
    // (ii) Implement all operation in Flight class using the pointer
    Flight1->book(10, "senior citizen");
    Flight1->cancel(2);
    Flight1->checkDetail();
    // (iii) Delete the memory pointer by Flight1
    delete Flight1;

    return 0;
}
