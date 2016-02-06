// MinHeap implementation
#include "MinHeap.h"
#include <cstddef>
#include <iostream>

using namespace std;

MinHeap::MinHeap() {
	
	heap = new Trie* [33];
	nextAdd = 1; 
}

bool MinHeap::add(Trie* t) {

	heap[nextAdd]=t;
	
	int parent = nextAdd/2;
	int child = nextAdd;

	while(parent != 0){
		if( heap[child]->frequency < heap[parent]->frequency){
			Trie* temp = heap[child];
			heap[child] = heap[parent];
			heap[parent] = temp; 
		}
		else break; 
		child = child/2;
		parent = parent/2; 
	}

	nextAdd++;

	return true;
}

Trie* MinHeap::peek(){

	return NULL;
}

Trie* MinHeap::poll(){
	
	return NULL;
}

void MinHeap::print(){

	for(int i = 1; i< nextAdd; i++){
		cout << heap[i]->c << ","<< heap[i]-> frequency<<endl;
	}

}

