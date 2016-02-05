// Main code here

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main(int argc, char** argv){
	//cout << "STUB" << endl;
	string line;
	ifstream myfile ("input.txt");

	if (myfile.is_open()){
  		while ( getline (myfile,line))
    		cout << line << '\n';
   
    	myfile.close();
	}

	else cout << "Unable to open file"; 	


	return 0; 
}