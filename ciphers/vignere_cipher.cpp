/*
* Vigenere cipher
* Vigenere Cipher is a method of encrypting alphabetic text. It uses a simple form of 
* polyalphabetic substitution. A polyalphabetic cipher is any cipher based on substitution, 
* using multiple substitution alphabets .
*
* Code by @Anvikshajain
*/
#include <iostream>
#include <string>
using namespace std;

class Vigenere
{
      public:
        string key;

            //generating the key matrix
          Vigenere(string key)
          {
              int len=key.size();
              for (int i = 0; i < len; ++i)
              {
                  if (key[i] >= 'A' && key[i] <= 'Z')
                      this->key += key[i];
                  else if (key[i] >= 'a' && key[i] <='z')
                      this->key += key[i] + 'A' - 'a';
              }
          }

            //encrypting text
          string encrypt(string text)
          {
              string out;
              int len=text.length();
              for (int i = 0, j = 0; i < len; ++i)
              {
                  char c = text[i];
                  if (c >= 'a' && c <= 'z')
                      c += 'A' - 'a';
                  else if (c < 'A' || c > 'Z')
                      continue;
                  out += (c + key[j] - 2 * 'A') % 26 + 'A';
                  int k=key.length();
                  j = (j + 1) % k;
              }
              return out;
          }

            //decrypting text
          string decrypt(string text)
          {
              string out;
              int len=text.length();
              for (int i = 0, j = 0; i < len; ++i)
              {
                  char c = text[i];
                  if (c >= 'a' && c <= 'z')
                      c += 'A' - 'a';
                  else if (c < 'A' || c > 'Z')
                      continue;
                  out += (c - key[j] + 26) % 26 + 'A';
                  int k=key.length();
                  j = (j + 1) % k;
              }
              return out;
          }
  };

    //Driver code
int main()
{
    Vigenere cipher("VIGENERECIPHER");
    string original ="Rishabh Patel";
    string encrypted = cipher.encrypt(original);
    string decrypted = cipher.decrypt(encrypted);
    cout << original << endl;
    cout << "Encrypted: " << encrypted << endl;
    cout << "Decrypted: " << decrypted << endl;
}
