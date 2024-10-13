#include <iostream>
#include <map>
#include <string>
using namespace std;

namespace atbash {
    map<char, char> atbash_map = {
        {'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'}, {'e', 'v'}, {'f', 'u'}, {'g', 't'}, {'h', 's'}, {'i', 'r'}, {'j', 'q'}, {'k', 'p'}, {'l', 'o'}, {'m', 'n'},
        {'n', 'm'}, {'o', 'l'}, {'p', 'k'}, {'q', 'j'}, {'r', 'i'}, {'s', 'h'}, {'t', 'g'}, {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'}, {'y', 'b'}, {'z', 'a'},
        {'A', 'Z'}, {'B', 'Y'}, {'C', 'X'}, {'D', 'W'}, {'E', 'V'}, {'F', 'U'}, {'G', 'T'}, {'H', 'S'}, {'I', 'R'}, {'J', 'Q'}, {'K', 'P'}, {'L', 'O'}, {'M', 'N'},
        {'N', 'M'}, {'O', 'L'}, {'P', 'K'}, {'Q', 'J'}, {'R', 'I'}, {'S', 'H'}, {'T', 'G'}, {'U', 'F'}, {'V', 'E'}, {'W', 'D'}, {'X', 'C'}, {'Y', 'B'}, {'Z', 'A'}
    };

    string encrypt(const string& input) {
        string result;
        for (char ch : input) {
            if (atbash_map.find(ch) != atbash_map.end()) {
                result += atbash_map[ch];
            }
            else {
                result += ch; 
            }
        }
        return result;
    }
}

int main() {
    string input;
    getline(cin, input);
    string encrypted = atbash::encrypt(input);
    cout << encrypted << endl;

    return 0;
}