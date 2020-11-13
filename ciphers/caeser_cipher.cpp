/*
* Caeser Cipher
* The Caesar Cipher technique is one of the earliest and simplest method of encryption technique. 
* It’s simply a type of substitution cipher, i.e., each letter of a given text is replaced by a 
* letter some fixed number of positions down the alphabet.
*
* Code by @Anvikshajain
*/
#include <iostream> 
using namespace std; 

//encrypts text with the shift of s
string encrypt(string text, int s) 
{ 
	string result = "";
    int l=text.length();
    char ch;
	for (int i=0;i<l;i++) 
	{ 
	    ch=text[i];
	    //ignoring space
	    if(ch!=' ')
	    {
	        //encrypting upper case
		    if (isupper(ch)) 
    			result += char(int(ch+s-65)%26 +65); 

            //encrypting lower case
	        else
		        result += char(int(ch+s-97)%26 +97); 
	    }
	    else
	        //adding space
	        result=result+ch;
	} 
	return result; 
} 

//decrypts text with the shift of s
string decrypt(string text, int s) 
{ 
	string result = "";
    int l=text.length();
    char ch;
	for (int i=0;i<l;i++) 
	{ 
	    ch=text[i];
	    //ignoring space
	    if(ch!=' ')
	    {
	        //for upper case character
		    if (isupper(ch)) 
			    result += char(int(ch-s-65)%26 +65); 

            //for lower case character
	        else
		        result += char(int(ch-s-97)%26 +97); 
	    }
	    else
	        //adding space
	        result=result+ch;
	} 
	return result; 
} 

//main code
int main() 
{ 
	string text="Caeser Cipher"; 
	int s = 4; 
	cout << "Text : " << text; 
	cout << "\nShift: " << s; 
	string cipher=encrypt(text,s);
	cout << "\nCipher: " << cipher; 
	cout << "\nDecrypt: "<< decrypt(cipher,s);
	return 0; 
} 
