#include <iostream>
#include "LList.h"

LList::LList()
{
	head = NULL;
} //constructor

void LList::insert(string input){
	if(head == NULL){
		//head is empty case
		node* newNode = new node(input);
		head = newNode;
		(head->count) += 1;
	}
	else if(head->word == input){
		(head->count) += 1;
	}
	else{
		//list not empty case
		node * currentNode = head;
		bool traverseFlag = true;
		while(traverseFlag){
			if(currentNode->next != NULL && currentNode->word == input)
				currentNode = currentNode->next;
			else
				traverseFlag = false;
		}
		if(currentNode->word == input){
			//word already in linked list
			(currentNode->count) += 1;
		}
		else if(currentNode->next == NULL){
			//word not currently in linked list
			node* newNode = new node(input);
			currentNode->next = newNode;
			((currentNode->next)->count) += 1;
		}
	}
}//insert