#include "dataPair.h"

dataPair::dataPair()
{
	word = "";
	count = 0;
}

void dataPair::newdataPair(string newWord, int newCount){
	word = newWord;
	count = newCount;
} //newdataPair

void dataPair::printDataPair(){
	int length = word.length();
	cout << word << setw(15 - length) << count << endl;
} //printDataPair