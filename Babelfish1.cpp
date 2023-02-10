using namespace std;
#include <iostream>
#include <map>
#include <iterator>
#include <vector>

int main () {
    map<string, string> hash_map;
    string temp;
    int charPos;
    string word1;
    string word2;
    vector<string> words;
    
    while (getline(cin, temp)) {
        if (temp.empty()) break;
        for (int i = 0; i < temp.length(); i++) {
            if (temp.at(i) == ' ') {
                charPos = i;
            }
        }
        word1 = temp.substr(0,charPos);
        word2 = temp.substr(charPos+1);
        hash_map[word2] = word1;
    }

    while (cin >> temp) {
        if (hash_map.count(temp) == 0) {
            cout << "eh" << endl;
        }
        else {
            cout << hash_map.at(temp) << endl;
        }
    }
    return 0;
}  