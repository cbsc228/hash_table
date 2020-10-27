#include "HashTable.h"
using namespace std;
//----------------------------------------------------
//	           constructor
//----------------------------------------------------
HashTable::HashTable(){
	numElements = 0;
} //constructor

void HashTable::insert(string input){
	int hashValue = hashInput(input);
	
	hashTable[hashValue].insert(input);
} //insert

int HashTable::hashInput(string input){
	int hashValue = 0;
	
	//gets the numerical value of each character and mods by the size of the hash table
	for(int i = 0; i < input.length(); i++)
		hashValue += static_cast<int>(input[i]);
	
	hashValue = hashValue % HASH_TABLE_SIZE;
	
	return hashValue;
} //hashInput


void HashTable::selectionSort(dataPair sortedWords[], int numElements){
	int minElement;
	dataPair tempSwap;
	for(int i = 0; i < numElements - 1; i ++){
		minElement = i;
		for(int j = i+1; j < numElements; j++){
			if(sortedWords[j].word < sortedWords[minElement].word)
				minElement = j;
		}
		tempSwap = sortedWords[minElement];
		sortedWords[minElement] = sortedWords[i];
		sortedWords[i] = tempSwap;
	}
} //selectionSort

void HashTable::printSorted(){
	//figures out how many unique elements there are
	for(int i = 0; i < HASH_TABLE_SIZE; i++){
		node *currentNode = hashTable[i].head;
		while(currentNode != NULL){
			numElements += 1;
			currentNode = currentNode->next;
			
		}
	}
	dataPair sortedWords[numElements];
	int index = 0;
	//copies the data from the hash table into a 2-D array
	for(int i = 0; i < HASH_TABLE_SIZE; i++){
		node *currentNode = hashTable[i].head;
		while(currentNode != NULL){
			if(currentNode->word != " ")
			sortedWords[index].newdataPair(currentNode->word, currentNode->count);
			
			currentNode = currentNode->next;
			index += 1;
		}
	}
	//sorts the copied data
	selectionSort(sortedWords, numElements);

	//prints the sorted data
	for(int i = 0; i < numElements; i++){
		sortedWords[i].printDataPair();
	}
} //printSorted