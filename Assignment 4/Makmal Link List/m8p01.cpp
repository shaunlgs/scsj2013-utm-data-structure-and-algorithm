//Aturcara m 8 p01 - baca data dari fail
//Aturcara Senarai implementasi tatasusunan
//Nama Fail : m6p01.txt
#include <stdio.h>
#include <conio.h>
#include <iostream>
#define LIST_SIZE 5
#include <assert.h>
#include <stdlib.h>
using namespace std;
typedef int ELEM1;
class list
{
    private:
       int msize;
       int bil;
       int curr;
       ELEM1 * listarray;
    public:
       list(const int=LIST_SIZE);
       ~list();
       void clear();
       void insert(const ELEM1&);
       void append(const ELEM1&);
       void display();
       ELEM1 remove();
       void setFirst();
       void prev();
       void next();
       int length();
       void setPos(const int);
       void setValue(const ELEM1&);
       ELEM1 currValue();
       bool isEmpty();
       bool isInList();
       bool find(const ELEM1&);
};

list::list(const int sz)
{
   msize=sz;
   bil=curr=0;
   listarray=new ELEM1[sz];
}

list::~list()
{	delete[] listarray;	}

void list::clear()
{	bil=curr=0;	}

//Insert ELEM at current position
void  list::insert(const ELEM1& item)
{
	assert((bil<msize) && (curr>=0) && (curr<=bil));
	while(listarray[curr]<=item)
   		{ curr++; }
	for(int i=bil;i>=curr;i--)
	listarray[i+1]=listarray[i];
   listarray[curr]=item;
   bil++;
}

void list::append(const ELEM1& item)
{
   assert(bil<msize);
   cout<<"Nilai :"<<bil++;
   getch();
   listarray[bil++]=item;
}

ELEM1 list::remove()
{
int x;
cout<<"\n\nMasukkan Elemen ke berapa mahu dibuang\t";
cin>>x;
assert(!isEmpty() && isInList());
ELEM1 temp=listarray[x-1];
for(int i=x-1;i<bil;i++)
listarray[i]=listarray[i+1];
bil--;
return temp;
}

void list::display()
{
for(int x=0;x<bil;x++)
cout<<listarray[x]<<"\n";
}

void list::setFirst() {curr=0;}
void list::prev() {curr;}
void list::next() { curr++; }
int list::length(){return bil; }
void list::setPos(const int pos)
{ curr=pos; }

void list::setValue(const ELEM1& val)
{
assert(isInList());
//return listarray[curr];
}

ELEM1 list::currValue()
{
assert(isInList());
return listarray[curr];
}

bool list::isEmpty()
{
	return bil==0;
}

bool list::isInList()
{
return (curr >=0) && (curr<bil);
}

bool list::find(const ELEM1& val)
{
   while(isInList()){
   if(currValue()==val)
   return true;
   else next();
   return false;}
}

int main()
{
    list L;
    int d,temp=0;
    FILE *MyFile;
    cout<<"\n\nLatihan Makmal Senarai -Fail\n";
    MyFile = fopen("m6p01.txt","r");
    cout<<"\n\nData Sebelum Penghapusan Dilakukan:\n";
    fscanf(MyFile,"%d",&temp);
    L.insert(temp);
    fscanf(MyFile,"%d",&temp);
    L.insert(temp);
    fscanf(MyFile,"%d",&temp);
    L.insert(temp);
	fscanf(MyFile,"%d",&temp);
    L.insert(temp);
    fclose(MyFile);
    L.display();
    cout<<"Data Yang Telah Dibuang  :"<<L.remove()<<"\n"<<"Data Yang Tinggal  :"<<"\n";
    L.display();
      getch();
}

/* output


Latihan Makmal Senarai -Fail


Data Sebelum Penghapusan Dilakukan:
10
20
30
40


Masukkan Elemen ke berapa mahu dibuang  2
Data Yang Telah Dibuang  :20
Data Yang Tinggal  :
10
30
40

*/
