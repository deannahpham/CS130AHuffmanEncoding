#ifndef HUFFMANENCODING_H
#define HUFFMANENCODING_H

#include <string>

using namespace std; 

class HuffmanEncoding{
public:
	HuffmanEncoding(string fileName);

	void printArray();

private: 
	//PRIVATE METHODS
	void addChar(char c);
	void extractFromFile(string fileName);
	int charToInt(char c);
	char intToChar(int n);
	
	//PRIVATE VARIABLES
	
	//Includes the frequency of each character 
	//positions 0-25 will be a-z
	//position 26 will be '.'
	//position 27 will be ' '
	//positions 28 will be '\n'
	int frequency[29]; 

};



#endif