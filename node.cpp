#include <iostream>
#include "node.h"

node::node() {
	next = NULL;
	count = 0;
} // constructor (default)

node::node(string newWord) {
	word = newWord;
	count = 0;
	next = NULL;
} // overloaded constructor