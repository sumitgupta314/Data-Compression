#ifndef _HashTable_h_
#define _HashTable_h_

#include "TokenObject.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable {

private:
	list<TokenObject>* hashTable;
	int size;

public:
	HashTable(int s);
	void decode_put(TokenObject& obj);
	void encode_put(TokenObject& obj);
	TokenObject decode_access(int code);
	TokenObject encode_access(string word);
	int getSize();

private:
	int computeHash(TokenObject& obj);
	int computeHash(string& word);
};

#endif
