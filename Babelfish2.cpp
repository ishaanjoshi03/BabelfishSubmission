using namespace std;
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <stdlib.h>
#include <time.h>

int getPosition(double seed, string word) {
    hash<string> hash_obj;
    int x = hash_obj(word);
    srand(seed+x);
    return random() % 10000;
}

int main () {
    vector<pair<string,string>> hash_map[10000];
    string temp;
    int charPos;
    int arrayPos;
    int hashNum;
    string word1;
    string word2;
    bool inCurrent = false;
    vector<string> words;
    vector<pair<string,string>> current;
    double seed = time(NULL)*1000;
    
    while (getline(cin, temp)) {
        if (temp.empty()) break;
        for (int i = 0; i < temp.length(); i++) {
            if (temp.at(i) == ' ') {
                charPos = i;
            }
        }
        word1 = temp.substr(0,charPos);
        word2 = temp.substr(charPos+1);
        pair<string, string> pairToInsert(word2,word1);
        arrayPos = getPosition(seed, word2);
        hash_map[arrayPos].push_back(pairToInsert);
    }

    while (cin >> temp) {
        arrayPos = getPosition(seed, temp);
        current = hash_map[arrayPos];
        for (auto itr = current.begin(); itr != current.end(); itr++) {
            if (itr->first == temp) {
                cout << itr->second << endl;
                inCurrent = true;
            }
        }
        if (!inCurrent) {
            cout << "eh" << endl;
        }
        inCurrent = false;
    }
    return 0;
}  