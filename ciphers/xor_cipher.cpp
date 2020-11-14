/*
* Xor cipher
* XOR Encryption is an encryption method used to encrypt data and is hard to crack 
* by brute-force method, i.e generating random encryption keys to match with the correct one. 
* 
* Code by @Anvikshajain
*/
#include <iostream>

using namespace std;

string encryptDecrypt(string toEncrypt) {
    char key = 'K'; //Any char will work
    string output = toEncrypt;
    int len=toEncrypt.size();
    for (int i = 0; i < len; i++)
        output[i] = toEncrypt[i] ^ key;
    
    return output;
}

int main(int argc, const char * argv[])
{
    string encrypted = encryptDecrypt("crack any cipher");
    cout << "Encrypted:" << encrypted << "\n";
    
    string decrypted = encryptDecrypt(encrypted);
    cout << "Decrypted:" << decrypted << "\n";
    
    return 0;
}
