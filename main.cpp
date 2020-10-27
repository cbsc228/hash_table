#include <iostream>
#include <fstream>
#include <string>
#include "HashTable.h"


using namespace std;

void getFileName(string &fileName){
	//gets a file name from the user
	cout << "Please enter the file to hash: ";
	cin >> fileName;
	cout << endl;
}

//returns true if given char is not punctuation based on ASCII encoding
bool punctTest(char testChar){
	//tests if a char is a letter based on ASCII encoding
	int charNum = static_cast<int>(testChar);
	if(65 <= charNum && charNum <= 90)
		return true;
	if(97 <= charNum && charNum <= 122)
		return true;
	if(48 <= charNum && charNum <= 57)
		return true;
}

string removePunctuation(string input){
	//replaces punctuation with spaces
	for(int i = 0; i < input.length(); i++){
		if(!punctTest(input[i]))
			input[i] = ' ';
	}
	return input;
}

void readFile(HashTable &wordTable){
	string fileName;
	string inputString;
	getFileName(fileName);
	ifstream inFile;
	inFile.open(fileName);
	if(inFile.fail()){
		cout << "ERROR: Could not open file: " << fileName << endl;
		return;
	}
	//continually reads in input while it exists
	while(inFile >> inputString){
		//gets the provided string with spaces in place of punctuations
		inputString = removePunctuation(inputString);
		string wordToInsert = "";
		int charIndex = 0;
		//separates words based on spaces from removal of punctuation for insertion
		while(punctTest(inputString[charIndex]) && inputString[charIndex] != ' '){
			wordToInsert += inputString[charIndex];
			charIndex += 1;
		}
		//inserts new word into hash table
		if(wordToInsert != "")
			wordTable.insert(wordToInsert);
	}
}

int main(){
	//start of the program
	HashTable wordTable;
	readFile(wordTable);
	wordTable.printSorted();
	return 0;
}