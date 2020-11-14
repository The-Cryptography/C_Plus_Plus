/*
* Playfair cipher
* Base 64 is an encoding scheme that converts binary data into text format so that encoded 
* textual data can be easily transported over network un-corrupted and without any data loss.
*
* Code by @Anvikshajain
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char KEY[64] =  { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q','R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b','c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q','r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6','7', '8', '9', '+', '/' };

string toBinary(char chr) {

  int deci = (int) chr;
  string binary = "";

  while (deci > 0) {

    binary.insert(0, to_string(deci % 2));
    deci /= 2;

  }

  while (static_cast<int>(binary.size()) < 8) {

    binary.insert(0, "0");

  }

  return binary;

}
int fromBinary(string binary) {

  int num = 0;
  int base = 1;
  string bin = binary;

  while (static_cast<int>(bin.size()) > 0) {

    string last = bin.substr(static_cast<int>(bin.size()) - 1);
    if (last.compare("1") == 0)
      num += base;

    bin.pop_back();
    base *= 2;

  }

  return num;

}
string toBinaryString(string str) {

  string binary = "";
  for (int i = 0; i < static_cast<int>(str.size()); i++) {

    char chr = str.at(i);
    binary.append(toBinary(chr));

  }

  return binary;

}
vector<string> splitBinary(string binary) {

  vector<string> split;

  for (int i = 0; i < static_cast<int>(binary.size()) / 6; i++) {

    split.push_back(binary.substr(i * 6, 6));

  }

  if (static_cast<int>(binary.size()) % 6 != 0) {

    string extra = binary.substr(static_cast<int>(binary.size()) - static_cast<int>(binary.size()) % 6);

    while (static_cast<int>(extra.size()) < 6) {

      extra.append("0");

    }

    split.push_back(extra);

  }

  while (static_cast<int>(split.size()) % 4 != 0) {

    split.push_back("-1");

  }

  return split;

}
string encode(vector<string> splitBinary) {

  string encode = "";

  for (int i = 0; i < static_cast<int>(splitBinary.size()); i++) {

    if (splitBinary[i].compare("-1") != 0) {

      int chr = fromBinary(splitBinary[i]);
      string chr2 (1, KEY[chr]);
      encode.append(chr2);

    } else
      encode.append("=");

  }

  return encode;

}

int main() {

  string binary = toBinaryString("Rishabh Patel");
  vector<string> split = splitBinary(binary);
  cout << encode(split) << endl;

  return 0;

}
