#ifndef _TokenObject_h_
#define _TokenObject_h_

#include <iostream>

using namespace std;

class TokenObject
{
private:
	string word;
	int frequency = 0;
	int code;
public:
	TokenObject(const string& w);
	void addNewAppearance();
	string& getWord();
	int getFrequency();
	void setFrequency(int freq);
	void setCode(int c);
	int getCode();
};

#endif
