#ifndef MINHEAP_H
#define MINHEAP_H

struct Trie{
	char c;
	int frequency;
	Trie* left;
	Trie* right;
};


class MinHeap{
public: 
	MinHeap(); //constructor
	MinHeap(Trie** array, int size);
	bool add(Trie* t); // add node N to heap
	Trie* peek(); //returns root but does not remove it
	Trie* poll(); // return and remove root
	void print(); //print heap
	int getSize();

private:
	int getMin(int left, int right);
	void makeHeap(); 
	void percolateDown(int pos);

	Trie** heap; //root of heap
	int nextAdd; //keep track of the next index of where we want to add 

};

#endif