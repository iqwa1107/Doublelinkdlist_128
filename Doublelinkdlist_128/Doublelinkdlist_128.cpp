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

