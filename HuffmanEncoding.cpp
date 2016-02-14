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
	encodeFile();
	outputToFile(fileName);

}

void HuffmanEncoding::encodeFile(){
	Trie** array = new Trie*[30];
	int size = 1; 
	for(int i = 0; i < 29; i++){
		if(frequency[i] == 0)
			continue; 
		Trie* t = new Trie();
		t->c = intToChar(i);
		t->frequency = frequency[i];
		t->left = NULL;
		t->right = NULL;
		array[size] = t; 
		size++;
		//heap->add(t);
	}	

	MinHeap* heap = new MinHeap(array, size); 

	heap->print();
	cout << endl;


	Trie* newTrie;

	while(heap->getSize() > 1){
		newTrie = new Trie();

		Trie* right = heap->poll();
		Trie* left = heap->poll();
 
		newTrie->left = left;
		newTrie->right = right;

		newTrie->c = 'I';
		newTrie->frequency = left->frequency + right->frequency;

		heap->add(newTrie);
		heap->print();

	}
	encodedTrie = newTrie;

	makeEncodedValuesArray(encodedTrie, ""); 
}

void HuffmanEncoding::decodeFromFile(string fileName){
	string line; 
	ifstream infile(fileName.c_str());
	ofstream outfile ("decoded.txt");

	if (infile.is_open()){
  		while ( getline (infile,line)){
    		cout << line << '\n';

    		decodeIntoFile(outfile, line);
	  		
  			addChar('\n');
  		}
   
    	infile.close();
	}

	else cout << "Unable to open file";

	outfile.close();

}

void HuffmanEncoding::decodeIntoFile(ofstream& file, string line){
	Trie* traverse = encodedTrie; 

	for(int i = 0; i < (int)line.size(); i++){
		char c = line.at(i); 
		if(c == '1'){
			traverse = traverse->left;
			if(traverse->left == NULL){
				file << traverse->c;
				traverse = encodedTrie; 
			}
			
		}
		else if(c == '0'){
			traverse = traverse->right; 
			if(traverse->right == NULL){
				file << traverse->c;
				traverse = encodedTrie; 
			}
		}
	}
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

	  		for(int i = 0; i < (int)line.size(); i++)
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

void HuffmanEncoding::makeEncodedValuesArray(Trie* current, string str){
	if(current->left == NULL && current->right == NULL){
		encodedValues[charToInt(current->c)] = str; 
		cout << "added " << current->c << " with string " << str << endl;

		return;
	}	
	//cout << "calling left with string: " << str << " " << current->c << endl;
	makeEncodedValuesArray(current->left, str+"1");

	//cout << "calling right with string: " << str << endl;
	makeEncodedValuesArray(current->right, str+"0");
}

string HuffmanEncoding::getEncodedValue(char c){
	return encodedValues[charToInt(c)];
}

void HuffmanEncoding::outputToFile(string inputFile){
	ofstream myfile ("output.txt");
	string line;
	ifstream inFile (inputFile);
	if (inFile.is_open()){
		while ( getline (inFile,line) ){
			cout << line << endl;
			for(int i = 0; i < (int)line.size(); i++){
				string val = getEncodedValue(line.at(i));
  				myfile << val;
  			}
		}
		myfile.close();
	}
    
  	else cout << "Unable to open file";
}

void HuffmanEncoding::printTrie(Trie* current){
	if(current == NULL)
		return;
	cout << current->c << " " << current->frequency << endl;
	printTrie(current->left);
	printTrie(current->right);
}

