#include <iostream>
#include <string>
using namespace std;

// Program 2.11a
class Car
{
    private:
        string brand;
        double price;
        int CC;
    public:
        Car() {
            brand = "none";
            price = 0;
            CC = 0;
        }

        Car(string cb, double cp, int cc)
        {
            brand = cb;
            price = cp;
            CC = cc;
        }

        string getBrand() {
            return brand;
        }

        double getPrice() {
            return price;
        }

        void print() {
            cout << "The brand of the car is : " << brand << endl;
            cout << "The price of the car is : " << price << endl;
            cout << "The CC of the car is : " << CC << endl;
            cout << endl;
        }
};

void fillData(Car cars[]); // non-member function
Car cheapest(Car cars[]); // non-member function

// Program 2.11b
// a. This function prompts the user for the car brand, car price, and car CC information
// respectively of 6 cars and the information are stored in the object.
void fillData(Car cars[])
{
    string cb;
    double cp;
    int cc;

    int i=0;

    for(int i=0; i<6; i++)
    {
        cout << "Please enter car brand for car no " << (i+1) << ": ";
        getline(cin, cb);

        cout << "Please enter car price for car no " << (i+1) << ": ";
        cin >> cp;
        cin.ignore();

        cout << "Please enter car CC for car no " << (i+1) << ": ";
        cin >> cc;
        cin.ignore();

        Car car(cb, cp, cc);
        cars[i] = car;
        cout << endl;
    }
}

Car cheapest(Car cars[])
{
    // get the number of cars
    int numCars = sizeof(cars)/sizeof(cars[0]);

    float cheapest = cars[0].getPrice();
    Car cheapestCar = cars[0];
    for(int i=0; i<numCars; i++)
    {
        if(cars[i].getPrice() < cheapest)
        {
            cheapestCar = cars[i];
            cheapest = cars[i].getPrice();
        }
    }
    return cheapestCar;
}

int main()
{
    Car cars[6];
    Car* p;

    p = cars;
    *(p) = Car("Honda", 123000.00, 2500);
    *(p+1) = Car("Mitsubishi Evolution", 250000.00, 2000);
    *(p+2) = Car("Proton Saga", 60000.00, 1800);
    *(p+3) = Car("Proton Wira", 45000.00, 1300);
    *(p+4) = Car("Toyota VIOS", 85000.80, 2000);
    *(p+5) = Car("BMW", 500000.00, 3500);

    int index;
    cout << "Please enter an index between 1 to 6: ";
    cin >> index;

    (p+index-1)->print();
}
