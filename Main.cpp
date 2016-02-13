// Main code here

#include <iostream>
#include <fstream>
#include <string>
#include "HuffmanEncoding.h"
#include "MinHeap.h"

using namespace std; 

int main(int argc, char** argv){
	


	//cout << "STUB" << endl;
	HuffmanEncoding encode("input.txt");
	//encode.printArray();
	//encode.encodeFile();

	/*MinHeap *minHeap = new MinHeap();

	Trie* t1 = new Trie();
	t1->left = NULL; t1->right = NULL; 
	t1->frequency =3 ; t1->c = 'a';

	minHeap->add(t1);

	t1 = new Trie();
	t1->left = NULL; t1->right = NULL; 
	t1->frequency = 8 ; t1->c = 'b';
	minHeap->add(t1);

	t1 = new Trie();
	t1->left = NULL; t1->right = NULL; 
	t1->frequency = 2 ; t1->c = 'c';
	minHeap->add(t1);

	t1 = new Trie();
	t1->left = NULL; t1->right = NULL; 
	t1->frequency = 1 ; t1->c = 'd';
	minHeap->add(t1);

	t1 = new Trie();
	t1->left = NULL; t1->right = NULL; 
	t1->frequency = 5 ; t1->c = 'e';
	minHeap->add(t1);

	minHeap->print();

	t1 = minHeap->poll();
	cout << "just removed: " << t1->c << "," << t1->frequency << endl;
	minHeap->print();*/

}

/**
struct Trie{
	char c;
	int frequency;
	Trie* left;
	Trie* right;
};
*/