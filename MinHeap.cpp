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
		else{
			break;
		} 
		child = child/2;
		parent = parent/2; 
	}

	nextAdd++;

	return true;
}

Trie* MinHeap::peek(){

	return heap[1];
}

Trie* MinHeap::poll(){
	
	Trie* result = heap[1];
	int pos = 1; 
	heap[1] = heap[nextAdd-1];
	nextAdd--;

	while(pos*2 < nextAdd){
		int min = getMin(pos*2, pos*2+1);
		if(heap[min]->frequency < heap[pos]->frequency){
			Trie* temp = heap[min];
			heap[min] = heap[pos];
			heap[pos] = temp; 
		}
		else{ 
			break;
		} 
		
		pos = min; 
	}

	return result;
}

int MinHeap::getMin(int left, int right){
	if(left >= nextAdd){
		return -1;
	}
	if(right >= nextAdd){
		return left; 
	}
	return (heap[left]->frequency < heap[right]->frequency)?  left : right;
}

void MinHeap::print(){

	for(int i = 1; i< nextAdd; i++){
		if(heap[i]->c == '\n'){
			cout << "\\n";
		}
		else{
			cout << heap[i]->c;
		}
		cout << ","<< heap[i]-> frequency<<endl;
	}

}

int MinHeap::getSize(){
	return nextAdd-1; 
}

