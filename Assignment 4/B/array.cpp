#include <iostream>
using namespace std;

class data
{
    public:
        string name;
        int age;
        string occupation;
};

void printDetails(data obj)
{
    cout << "Name: " << obj.name << endl;
    cout << "Age: " << obj.age << endl;
    cout << "Occupation: " << obj.occupation << endl;
    cout << endl;
}

int main()
{
    data arrayData[4];

    // store data
    arrayData[0].name = "Shaun";
    arrayData[0].age = 24;
    arrayData[0].occupation = "Programmer";
    arrayData[1].name = "Shuhadah";
    arrayData[1].age = 23;
    arrayData[1].occupation = "Programmer";
    arrayData[2].name = "Ahmad";
    arrayData[2].age = 24;
    arrayData[2].occupation = "Web designer";
    arrayData[3].name = "Ali";
    arrayData[3].age = 27;
    arrayData[3].occupation = "Controller";

    // print all the elements
    for(int i=0; i<4; i++)
    {
        printDetails(arrayData[i]);
    }

    return 0;
}
