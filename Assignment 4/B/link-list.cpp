#include <iostream>
#include <conio.h>
using namespace std;


class Node {
	public:
		string name;
		int age;
		string occupation;
		Node* next;
};

class List {
	public:
		List(void) { head = NULL; } // constructor
		~List(void);    // destructor
 		bool IsEmpty() { return head == NULL; }
		Node* InsertNode(string, int, string);
		int FindNode(string, int, string);
		int DeleteNode(string, int, string);
		void DisplayList(void);
	private:
		Node* head;
};

Node* List::InsertNode(string name, int age, string occu) {
	int currIndex = 0;
	Node* currNode = head;
	Node* prevNode = NULL;
	while (currNode && name.compare(currNode->name) > 0 )
	{   prevNode = currNode;                currNode = currNode->next;   currIndex++;  }
	Node* newNode = new Node;
	newNode->name = name;
	newNode->age = age;
	newNode->occupation = occu;
	if (currIndex == 0) {   newNode->next = head;   head  = newNode;  }
	else {   newNode->next = prevNode->next;   prevNode->next = newNode;  }
	return newNode;
}

int List::FindNode(string name, int age, string occu) {
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && (currNode->name != name || currNode->age != age || currNode->occupation != occu)) {   currNode = currNode->next;   currIndex++;  }
	if (currNode)
		return currIndex;
	else
		return 0;
}

void List::DisplayList() {
	int num  = 0;
	Node* currNode = head;
	while (currNode != NULL){
            cout << "Name: " << "\t" << currNode->name << endl;
            cout << "Age: " << "\t" << currNode->age << endl;
            cout << "Occupation: " << "\t" << currNode->occupation << endl;
            cout << endl;
            currNode = currNode->next;
            num++;
    }
	cout << "Number of nodes in the list: " << num << endl;
}

int List::DeleteNode(string name, int age, string occu) {
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;
	while (currNode && (currNode->name != name || currNode->age != age || currNode->occupation != occu))
	{
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->next = currNode->next;
			delete currNode;
		}   else {    head  = currNode->next;    delete currNode;   }
		return currIndex;
		}
return 0; }

List::~List()  {
	Node* currNode = head,
	*nextNode = NULL;
	while (currNode != NULL)    {
		nextNode = currNode->next;  // destroy the current node
		delete currNode;
		currNode = nextNode;
	}
	head = NULL;
}

int main(void) {
	List list;
	list.InsertNode("Shaun", 24, "Programmer"); // successful
	list.InsertNode("Shuhadah", 23, "Programmer"); // successful
	list.InsertNode("Ahmad", 24, "Web designer"); // successful
	list.InsertNode("Ali", 27, "Controller"); // successful
	// print all the elements
	list.DisplayList();
	if(list.FindNode("Shaun", 24, "Programmer") > 0)
		cout << "Shaun 24 years old programmer found" << endl;
	else
		cout << "Shaun 24 years old programmer not found" << endl;

	if(list.FindNode("Ali", 26, "Controller") > 0)
		cout << "Ali 26 years old controller found" << endl;
	else
		cout << "Ali 26 years old controller not found" << endl;
	list.DeleteNode("Shaun", 24, "Programmer");
	list.DisplayList();
	getch();
return 0; }
