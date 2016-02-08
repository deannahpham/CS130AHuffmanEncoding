#include "HuffmanEncoding.h"
#include <iostream>
#include <fstream>
#include <string>
//#include "MinHeap.cpp"

using namespace std;

HuffmanEncoding::HuffmanEncoding(string fileName){

	//initialize the frequency array 
	for(int i = 0; i < 29; i++){
		frequency[i] = 0;
	}

	//get the inputs from a file 
	extractFromFile(fileName);
	encodedTrie = new Trie();

}

void HuffmanEncoding::encodeFile(){
	MinHeap* heap = new MinHeap(); 
	for(int i = 0; i < 29; i++){
		if(frequency[i] == 0)
			continue; 
		Trie* t = new Trie();
		t->c = intToChar(i);
		t->frequency = frequency[i];
		heap->add(t);
	}
	heap->print();

	Trie* newTrie = new Trie();

	while(heap->getSize() > 1){
		Trie* left = heap->poll();
		Trie* right = heap->poll();
 
		newTrie->left = left;
		newTrie->right = right;

		newTrie->c = 'I';
		newTrie->frequency = left->frequency + right->frequency;

		heap->add(newTrie);
		heap->print();

	}
	encodedTrie = newTrie;
}

void HuffmanEncoding::printArray(){
	for(int i = 0; i < 29; i++){
		char c = intToChar(i);
		if(c == '\n')
			cout << "(" << "\\n";
		else{
			cout << "(" << c;
		}

		cout << "," << frequency[i] << ")" << ";";
	}
	cout << endl;
}



//PRIVATE METHODS 
void HuffmanEncoding::extractFromFile(string fileName){
	string line;
	ifstream myfile (fileName.c_str() );

	if (myfile.is_open()){
  		while ( getline (myfile,line)){
    		cout << line << '\n';

	  		for(int i = 0; i < line.size(); i++)
  				addChar(line.at(i));
  			addChar('\n');
  		}
   
    	myfile.close();
	}

	else cout << "Unable to open file"; 	
}


void HuffmanEncoding::addChar(char c){
	frequency[charToInt(c)]++;
}


int HuffmanEncoding::charToInt(char c){
	if(c == '.')
		return 26;
	else if(c == ' ')
		return 27;
	else if(c == '\n')
		return 28; 
	else
		return (int)c - 97; 

}

char HuffmanEncoding::intToChar(int n){
	//check to make sure input is between 0 and 28
	if(n < 0 || n > 28)
		return (char)7;
	
	if(n == 26)
		return '.';
	else if(n == 27)
		return ' ';
	else if (n == 28)
		return '\n';
	else
		return (char)(n+97);

}
