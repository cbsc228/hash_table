//------------------------------------------
//              class LList
//------------------------------------------
// A singly Linked List used as the chain for
// a hash table
//------------------------------------------
#include "node.h"

class LList {
	friend class HashTable;
public:
	LList();
	//insert a new word into the list
	void insert(string input);
private:
	//start of the linked list
	node * head;
};