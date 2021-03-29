#include "TokenObject.h"

TokenObject::TokenObject(const string& w)
	:word(w), frequency(1) {

}
void TokenObject::addNewAppearance()
{
	frequency += 1;
};

string& TokenObject::getWord() {
	return word;
}

int TokenObject::getFrequency() {
	return frequency;
}

void TokenObject::setFrequency(int freq) {
	frequency = freq;
}

void TokenObject::setCode(int c) {
	code = c;
}

int TokenObject::getCode() {
	return code;
}