// Program 2.14
#include <iostream>
using namespace std;

int bil = 0;
class UJI
{
    private:
        int nilai;
    public:
        UJI(int v)
        {
            nilai = v;
            cout << "\nCreating object with value: " << nilai ;
        }
        ~UJI()
        {
            cout << "\nDestroying object with value :" << nilai;
        }
        void change()
        {
            nilai *= nilai;
        }
};
void external()
{
    UJI objek1(10), objek2(5);
    objek1.change();
}

int main()
{
    UJI objek1(3),objek2(7);
    objek2.change();
    external();
    return 0;
}
