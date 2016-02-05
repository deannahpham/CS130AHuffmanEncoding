// Main code here

#include <iostream>
#include <fstream>
#include <string>
#include "HuffmanEncoding.h"

using namespace std; 

int main(int argc, char** argv){
	//cout << "STUB" << endl;
	HuffmanEncoding encode("input.txt");
	encode.printArray();
}