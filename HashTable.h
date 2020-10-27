//------------------------------------------
//              class HashTable
//------------------------------------------
// A Hash Table using external chaining
//------------------------------------------

#include "LList.h"
#include "dataPair.h"
#include <string>
#include <iostream>
using namespace std;

//chosen based on the fact that the given txt file is 1104 words long
//and the prime number greater and closest to 1.3 times this is 1439
const int HASH_TABLE_SIZE = 1439;

class HashTable {
public:
	HashTable();
	//inserts new word
	void insert(string input);
	//prints the hash table sorted alphabetically
	void printSorted();
private:
	LList hashTable[HASH_TABLE_SIZE];
	//does selection sort on the table
	void selectionSort(dataPair sortedWords[], int numElements);
	//hashes a given input
	int hashInput(string input);
	int numElements;
};