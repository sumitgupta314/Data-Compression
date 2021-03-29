#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "TokenObject.h"
#include "HashTable.h"
//compile command: g++ TokenObject.cpp HashTable.cpp main.cpp -Wall -Wuninitialized -o a.out
//Reference1: https://stackoverflow.com/questions/18324189/detect-new-line-c-fstream

using namespace std;

void sortDecending(vector<TokenObject>& v);

int main() {

	ifstream inFS;
	string inputFileName;

	cout << "Enter the name of the file you want compressed (add .txt at the end for text file): ";
	cin >> inputFileName;

	inFS.open(inputFileName);
	if (!inFS.is_open()) {
		cout << "Could not open " << inputFileName << endl;
		exit(1);
	}

	vector<TokenObject> wordsList;

	string currWord;
	bool wordFound = false;
	while (inFS >> currWord) {
		wordFound = false;
		if (!inFS.fail()) {
			cout << currWord << endl;
			for (unsigned int i = 0; i < wordsList.size(); ++i) {
				if (wordsList.at(i).getWord() == currWord) {
					wordsList.at(i).addNewAppearance();
					wordFound = true;
				}
			}
			if (!wordFound) {
				wordsList.push_back(TokenObject(currWord));
			}
		}
	}

	inFS.close();

	sortDecending(wordsList);

	//assign unique code to each TokenObject
	int count = 1;
	for (unsigned int i = 0; i < wordsList.size(); ++i) {
		wordsList.at(i).setCode(count);
		count++;
	}

	//decoder hashtable
	HashTable decoder(wordsList.size());
	for (unsigned int i = 0; i < wordsList.size(); ++i) {
		decoder.decode_put(wordsList.at(i));
	}

	//encoder hashtable
	HashTable encoder(wordsList.size());
	for (unsigned int i = 0; i < wordsList.size(); ++i) {
		encoder.encode_put(wordsList.at(i));
	}

	//write to decoderMappingFile with decoder hashtable
	ofstream outFS;
	string outputdecoderFile = "decoderMappingFile.txt";
	outFS.open(outputdecoderFile);
	if (!outFS.is_open()) {
		cout << "Error opening " << outputdecoderFile << endl;
		exit(1);
	}
	/*for (unsigned int i = 0; i < wordsList.size(); ++i) {
		outFS << "code: " << wordsList.at(i).getCode() << ", token: " << wordsList.at(i).getWord() 
			  << " _____________________frequency: " << wordsList.at(i).getFrequency() << endl;
	}*/
	for (int i = 1; i <= decoder.getSize(); ++i) {
		outFS << "code: " << decoder.decode_access(i).getCode() /*wordsList.at(i).getCode()*/
			<< ", token: " << decoder.decode_access(i).getWord() /*wordsList.at(i).getWord()*/
			<< " _____________________frequency: " << decoder.decode_access(i).getFrequency() /*wordsList.at(i).getFrequency()*/
			<< endl;
	}
	outFS.close();

	//open inputfile
	inFS.open(inputFileName);
	if (!inFS.is_open()) {
		cout << "Could not open " << inputFileName << endl;
		exit(1);
	}

	//open output compressed file
	string outputCompressedFile = "Compressed_file.txt";
	outFS.open(outputCompressedFile);
	if (!outFS.is_open()) {
		cout << "Error opening " << outputCompressedFile << endl;
		exit(1);
	}

	//write to output compressed file
	//used Reference1 to learn how to read new line from input text file
	string line;
	while (getline(inFS, line)) {
		string currentWord;
		stringstream ls(line);
		while (ls >> currentWord) {
			outFS << encoder.encode_access(currentWord).getCode() << " ";
		}
		outFS << "\n";
	}

	//while (inFS >> currentWord) {
	//	if (!inFS.fail()) {
	//		outFS << encoder.encode_access(currentWord).getCode() << " ";
	//		//outFS a newline everytime there is a new line in text file
	//	}
	//}

	inFS.close();
	outFS.close();

}

void sortDecending(vector<TokenObject>& v) {
	//insertion sort in decending order
	int j;
	for (unsigned int i = 1; i < v.size(); ++i) {
		j = i;
		while (j > 0 && v.at(j).getFrequency() > v.at(j - 1).getFrequency()) {
			TokenObject temp = v.at(j - 1);
			v.at(j - 1) = v.at(j);
			v.at(j) = temp;
			j--;
		}
	}
}