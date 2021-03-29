#include "HashTable.h"

HashTable::HashTable(int s) {
	size = s;
	hashTable = new list<TokenObject>[size];
}

void HashTable::decode_put(TokenObject& obj) {
	int bucket = computeHash(obj);
	
	if (hashTable[bucket].empty()) {
		hashTable[bucket].push_back(obj);
	}
	else {
		cout << "Error: hashTable[bucket] not empty" << endl;
		exit(1);
	}
}

void HashTable::encode_put(TokenObject& obj) {
	int bucket = computeHash(obj.getWord());
	hashTable[bucket].push_back(obj);

}

TokenObject HashTable::decode_access(int code) {
	return *hashTable[code % size].begin();
}

TokenObject HashTable::encode_access(string word) {
	int bucket = computeHash(word);
	list<TokenObject>::iterator it;
	for (it = hashTable[bucket].begin(); it != hashTable[bucket].end(); it++) {
		if (it->getWord() == word) {
			return *it;
		}
	}
	cout << "Error: encode_access couldn't return TokenObject for string: \"" << word << "\"" << endl;
	exit(1);
}

int HashTable::getSize() {
	return size;
}

int HashTable::computeHash(TokenObject& obj) {
	return obj.getCode() % size;
}

int HashTable::computeHash(string& word) {
	int hashValue = 0;
	for (unsigned int i = 0; i < word.size(); ++i) {
		hashValue += int(word.at(i)) * (i + 1);
	}

	return (hashValue % size);
}