/*
* Railfence cipher
* The rail fence cipher (also called a zigzag cipher) is a form of 
* transposition cipher. It derives its name from the way in which it is encoded.
*
* Code by @Anvikshajain
*/

#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 

// function to encrypt a message 
string encryptRailFence(string text, int key) 
{ 
	// create the matrix to cipher plain text 
	// key = rows , length(text) = columns 
	int len=text.length();
	char rail[key][len]; 

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i=0; i < key; i++) 
		for (int j = 0; j < len; j++) 
			rail[i][j] = '\n'; 

	// to find the direction 
	bool dir_down = false; 
	int row = 0, col = 0; 

	for (int i=0; i < len; i++) 
	{ 
		// check the direction of flow 
		// reverse the direction if we've just 
		// filled the top or bottom rail 
		if (row == 0 || row == key-1) 
			dir_down = !dir_down; 

		// fill the corresponding alphabet 
		rail[row][col++] = text[i]; 

		// find the next row using direction flag 
		dir_down?row++ : row--; 
	} 

	//now we can construct the cipher using the rail matrix 
	string result; 
	for (int i=0; i < key; i++) 
		for (int j=0; j < len; j++) 
			if (rail[i][j]!='\n') 
				result.push_back(rail[i][j]); 

	return result; 
} 

// This function receives cipher-text and key 
// and returns the original text after decryption 
string decryptRailFence(string cipher, int key) 
{ 
	// create the matrix to cipher plain text 
	// key = rows , length(text) = columns 
	int len=cipher.length();
	char rail[key][len]; 

	// filling the rail matrix to distinguish filled 
	// spaces from blank ones 
	for (int i=0; i < key; i++) 
		for (int j=0; j < len; j++) 
			rail[i][j] = '\n'; 

	// to find the direction 
	bool dir_down; 

	int row = 0, col = 0; 

	// mark the places with '*' 
	for (int i=0; i < len; i++) 
	{ 
		// check the direction of flow 
		if (row == 0) 
			dir_down = true; 
		if (row == key-1) 
			dir_down = false; 

		// place the marker 
		rail[row][col++] = '*'; 

		// find the next row using direction flag 
		dir_down?row++ : row--; 
	} 

	// now we can construct the fill the rail matrix 
	int index = 0; 
	for (int i=0; i<key; i++) 
		for (int j=0; j<len; j++) 
			if (rail[i][j] == '*' && index<len) 
				rail[i][j] = cipher[index++]; 


	// now read the matrix in zig-zag manner to construct 
	// the resultant text 
	string result; 

	row = 0, col = 0; 
	for (int i=0; i< len; i++) 
	{ 
		// check the direction of flow 
		if (row == 0) 
			dir_down = true; 
		if (row == key-1) 
			dir_down = false; 

		// place the marker 
		if (rail[row][col] != '*') 
			result.push_back(rail[row][col++]); 

		// find the next row using direction flag 
		dir_down?row++: row--; 
	} 
	return result; 
} 

//driver program to check the above functions 
int main() 
{ 
    int no_of_rails=3;  
    string plain_text="Where are you";
    string cipher=encryptRailFence(plain_text,no_of_rails);
	cout << "Encrypted Text : "<<cipher<< endl; 
	

	//Now decryption of the same cipher-text 
	string result=decryptRailFence(cipher,no_of_rails);
	cout << "Decrypted Text : "<<result<< endl; 

	return 0; 
} 
