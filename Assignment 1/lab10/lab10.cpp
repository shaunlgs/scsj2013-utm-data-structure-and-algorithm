#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
using namespace std;

class Inventory
{
	private:
		char itemName[100];
		char itemKod[100];
		float itemPrice;
		int qttyInStock;
		float totalEarned;
	public:

	    Inventory()
	    {
	    }

		void getData(char* name, char* code, float price, int quantity, float earning)
		{
		    strcpy(itemName, name);
			strcpy(itemKod, code);
			itemPrice = price;
			qttyInStock = quantity;
			totalEarned = earning;
		}

		void buy(int quantity)
		{
			qttyInStock -= quantity;
			totalEarned += quantity * itemPrice;
		};
		void addStock(int quantity)
		{
			qttyInStock += quantity;
		};
		void discountPrice(float newPrice)
		{
			itemPrice = newPrice;
		};
		void printDetail()
		{
			cout << "Item Name: " << itemName << endl;
			cout << "Item Code: " << itemKod << endl;
			cout << "Item Price: " << setprecision(2) << fixed << itemPrice << endl;
			cout << "Stock Quantity: " << setprecision(2) << fixed << qttyInStock << endl;
			cout << "Total Earned: " << totalEarned << endl;
			cout << endl;
		};

		~Inventory()
		{


		}
};

int main()
{
    Inventory inventoryArray[3];
    ifstream inData;
    inData.open("inventoryData.txt");

    for(int i=0; i<3; i++)
    {
        char tempName[50];
        char tempCode[50];
        float tempPrice;
        int tempStock;
        float tempTotal;

        inData.getline(tempName, 50, '\n');
        inData.getline(tempCode, 50, '\n');
        inData >> tempPrice;
        inData.ignore();
        inData >> tempStock;
        inData.ignore();
        inData >> tempTotal;
        inData.ignore();
        inData.ignore();
        inventoryArray[i].getData(tempName, tempCode, tempPrice, tempStock, tempTotal);
    }

    for(int i=0; i<3; i++)
    {
        inventoryArray[i].printDetail();
    }
    return 0;
}
