//------------------------------------------
//              class node
//------------------------------------------
// Describes a node in a unique-customerNumber Linked List
//------------------------------------------
#include <string>
using namespace std;

class node {
	friend class LList;
	friend class HashTable;
public:
	//default constructor
	node(); 
	//overloaded constructor
	node(string newWord); 
private:
	//number of times the word appears
	int count;
	//the given word
	string word;
	//points to next node in the chain
	node * next;			
};