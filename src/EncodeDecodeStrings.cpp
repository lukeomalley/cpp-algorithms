#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

/**
 * Design an algorithm to encode a list of strings to a string. The encoded
 * string is then sent over the network and is decoded back to the original list
 * of strings.
 *
 * Implement encode and decode
 */
class Solution {
public:
  string encode(vector<string> input) {
    string encoded;

    for (auto word : input) {
      encoded.append(to_string(word.length()));
      encoded.append(word);
    }

    return encoded;
  }

  vector<string> decode(string encoded) {
    vector<string> decoded;

    while (encoded.size()) {
      // Parse and consume the integer length
      int wordLength = encoded[0] - '0';
      encoded.erase(0, 1);

      // Parse and consume the the word
      decoded.push_back(encoded.substr(0, wordLength));
      encoded.erase(0, wordLength);
    }

    return decoded;
  }
};

int main() {
  vector<string> input = {"test", "string"};
  cout << "Input: ";
  for (auto str : input) {
    cout << str << " ";
  }
  cout << endl;

  Solution sol;

  auto encoded = sol.encode(input);
  cout << "Encoded: " << encoded << endl;

  cout << "Decoded: ";
  for (auto str : sol.decode(encoded)) {
    cout << str << " ";
  }

  cout << endl;

  return 0;
}
