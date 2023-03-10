/*
Q. Auto complete

Given n number of words and an incomplete word w. You need to auto-complete that word w.
That means, find and print all the possible words which can be formed using the incomplete word w.

Note : Order of words does not matter.

Sample Input 1 :
7
do dont no not note notes den
no

Sample Output 1 :
no
not
note
notes

Sample Input 2 :
7
do dont no not note notes den
de

Sample Output 2 :
den

Sample Input 3 :
7
do dont no not note notes den
nom

Sample Output 3 :
(Empty) There is no word which starts with "nom
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }

    void autoCompletePrint(TrieNode *root, string word){
      if(root -> isTerminal){
        cout << word << endl;
      }
      for(int i = 0; i < 26; i++){
        TrieNode *child = root -> children[i];
        if(child != NULL){
          autoCompletePrint(child, word + child -> data);
        }
      }
    } 
    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i = 0; i < input.size(); i++){
          insertWord(input[i]);
        }
        TrieNode *newRoot = root;
        int n = pattern.size();
        for(int i = 0; i < n; i++){
          int index = pattern[i] - 'a';
          newRoot = newRoot -> children[index];
          if(newRoot == NULL){
            return;
          }
        }
        autoCompletePrint(newRoot,pattern);
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}
