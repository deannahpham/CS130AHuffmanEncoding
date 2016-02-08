#ifndef HUFFMANENCODING_H
#define HUFFMANENCODING_H

#include <string>
#include "MinHeap.h"

using namespace std; 

class HuffmanEncoding{
public:
	HuffmanEncoding(string fileName);

	void encodeFile();

	void printArray();

private: 
	//PRIVATE METHODS
	void addChar(char c); //Increments the frequency of character c
	void extractFromFile(string fileName); //Given a file, extracts all characters and adds it to frequency
	int charToInt(char c); //turns a character into it's integer position in the array
	char intToChar(int n); //turns an integer to the character corresponding to it
	
	//PRIVATE VARIABLES
	
	//Includes the frequency of each character 
	//positions 0-25 will be a-z
	//position 26 will be '.'
	//position 27 will be ' '
	//positions 28 will be '\n'
	int frequency[29]; 
	Trie* encodedTrie; 

};



#endif