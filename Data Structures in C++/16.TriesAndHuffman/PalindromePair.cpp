/*
Q. Palindrome Pair

Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.

Sample Input 1 :
4
abc def ghi cba

Sample Output 1 :
true

Explanation of Sample Input 1:
"abc" and "cba" forms a palindrome

Sample Input 2 :
2
abc def

Sample Output 2 :
false

Explanation of Sample Input 2:
Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'

*/
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    string findString(TrieNode *root){
        for(int i = 0; i < 26; i++){
            if(root -> children[i] != NULL){
                return root -> children[i] -> data + findString(root -> children[i]);
            }
        }
        return "";
    }

    bool checkPalindrome(TrieNode *root, string str){
        if(str.size() == 0){
            string s = findString(root);
            if(s != reverseWord(s)){
                return false;
            }
            return true;
        }
        int index = str[0] - 'a';
        if(root -> children[index] != NULL){
            return checkPalindrome(root -> children[index], str.substr(1));
        }else if(str == reverseWord(str)){
            return true;
        }
        return false;
    }
    string reverseWord(string str){
        string ans = str;
        int start = 0, end = ans.size()-1;
        while(start < end){
            char tmp = ans[start];
            ans[start] = ans[end];
            ans[end] = tmp;
            start++;
            end--;
        }
        return ans;
    }
    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i = 0; i < words.size(); i++){
            add(words[i]);
            string findWord = reverseWord(words[i]);
            if(checkPalindrome(root, findWord)){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
