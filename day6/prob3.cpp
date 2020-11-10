
#include <bits/stdc++.h> 
using namespace std; 


int main() 
{ 

    char ch;
    string x;
    fstream fin("input.txt", fstream::in);
    // take input.txt as argurment


// character by character input
while (fin >> noskipws >> ch) {
    //remove all alphbhetic characters
    if(int(ch)>=int('a') and int(ch)<=int('z')){

    }
    else if(int(ch)>=int('A') and int(ch)<=int('Z')){
        
    }
    else{
         x = x + ch;
         //if not aplhabetic character add it to string
    }

}

	
fstream file; //fstream variable file

// opening file "output.txt" 

file.open("output.txt",ios::out); 

// If no file is created, then 
// show the error message. 
if(!file) 
{ 
	cout<<"Error in creating file!!!"; 
	return 0; 
} 

file << x; //write x in output.txt file
 

// closing the file. 
file.close(); 

return 0; 
} 
