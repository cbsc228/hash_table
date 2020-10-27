//------------------------------------------
//              class dataPair
//------------------------------------------
// Describes a pair of string to an int
//------------------------------------------
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class dataPair {
	friend class HashTable;
public:
	//default constructor
	dataPair(); 
	//makes a new data pair
	void newdataPair(string newWord, int newCount);
	//prints an existing data pair
	void printDataPair();
private:
	string word;
	int count;
};