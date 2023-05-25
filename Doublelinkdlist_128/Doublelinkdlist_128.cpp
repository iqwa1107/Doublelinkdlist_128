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
	bool deleteNode(int rollNo);
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
		newnode ->prev = NULL; //step 5
		START = newnode;//step 6
		return;
	}

	/*insert a node batween tow nodes in the list*/
	node* current = START; // stap 1.a
	node* previous = NULL; // stap 1.b
	while (current->next !=NULL && current->next->noMhs < nim) // step 1.c
	{
		previous = current; //1.d
		current = current->next; //1.e

	}

	if (current->next != NULL && nim == current -> noMhs) 
	{
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	newnode->next = current; // steep 4
	newnode->prev = current; // step 5
	if (current->next != NULL)
		current->next->prev = newnode; //step6
	current->next = newnode; //step 7

}

bool DoubleLinkedList :: search(int rollNo, node** preivious, node** curreent){
	*preivious = START; //srep 1.a
	*curreent = START; // step 1.2
	while (curreent != NULL && rollNo != (*curreent)->noMhs)
	{
		*preivious = *curreent; //step 1/d
		*curreent = (*curreent); //step 1/e
	}
	return(*curreent != NULL);
}

bool DoubleLinkedList::deleteNode(int rollNo) {
	node* previous, * current;
	previous = current = NULL;
	if (search (rollNo, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous; // step 2
	if (previous != NULL)
		previous->next = previous; // step 3
	else
		START = current->next;

	delete current; // step 4
	return true;
}

bool DoubleLinkedList::listEmpty(){
	return (START == NULL);
	}

void DoubleLinkedList::traverse() {
	
	{
		if (listEmpty())
			cout << "\nList is empty" << endl;
		else
		{
			cout << "nRecord in ascending order of roll number area:" << endl;
			node* currentnode = START;
			while (currentnode !=NULL)
			{
				cout << currentnode->noMhs << " " << currentnode->name << endl;
				currentnode = currentnode->next;
			}
		}
	}
}
 
void DoubleLinkedList::revtraverse() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;
	}
	else {
		cout << "\nRecords in descending order of roll number are:" << endl;
		node* currentnode = START;
		while (currentnode->next != NULL)
			currentnode = currentnode->next;

		while (currentnode != NULL) {
			cout << currentnode->noMhs << " " << currentnode->name << endl;
			currentnode = currentnode->prev;
		}
	}
}

void DoubleLinkedList::hapus() {
	if (listEmpty()) {
		cout << "\nList is empty" << endl;

	}
	cout << "\nEnter the roll number of the student whose record is to be deleted: ";
	int rollNo;
	cin >> rollNo;
	cout << endl;
	if (DoubleLinkedList::deleteNode(rollNo) == false)
		cout << "Record not found" << endl;
	else
		cout << "Record with roll number" << rollNo << "deleted" << endl;
}

void DoubleLinkedList::searchData() {
	if (listEmpty() == true) {
		cout << "\nList is Empty" << endl;

	}
	node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search:";
	int num;
	cin >> num;
	if (DoubleLinkedList::search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number:" << curr->noMhs << endl;
		cout << "\nName: " << curr->name << endl;
	}
}

int main() {
	DoubleLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. add a record to the list" << endl;
			cout << "2. delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. Search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "/nEnter your choice (1-6):";
			char ch;
			cin >> ch;

			switch (ch) {
			case '1':
				obj.addNode();
				break;
			case '2':
				obj.hapus();
				break;
			case '3':
				obj.traverse();
				break;
			case '4':
				obj.revtraverse();
				break;
			case '5':
				obj.searchData();
				break;
			case '6':
				return 0;
			default:
				cout << "\nInvalid option" << endl;
				break;
			}
		}