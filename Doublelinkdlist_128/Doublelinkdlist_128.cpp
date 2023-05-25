#include <iostream>
#include <string>
using namespace std;
class node
{
public:
	int noMhs;
	string name;
	node* next;
	node* prev;
};

class DoubleLinkedList {

private:
	node* START;

public:
	DoubleLinkedList();
	void addNode();
	bool search(int rollNo, node** preivious, node** curreent);
	bool listEmpty();
	void traverse();
	void revtraverse();
	void hapus();
	void searchData();
};

DoubleLinkedList::DoubleLinkedList() {
	START = NULL;
}

void DoubleLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the roll name of the student: ";
	cin >> nm;
	node* newnode = new node(); //step 1
	newnode->noMhs = nim; //step 2
	newnode->name = nm; // step 2

	/*insert a node in yhe beginning of a doubly - linked list*/

	if (START == NULL || nim <= START->noMhs)
	{
		if (START != NULL && nim <= START->noMhs) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next = START; //step 3 
		if (START != NULL)
			START->prev = newnode; //step 4
		newnode ->prev = NULL; //step 4


	}


}
