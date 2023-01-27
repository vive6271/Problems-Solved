#include <string>
#include "TrieNode.h"

class Trie{
  TrieNode *root;

public:
  Trie(){
    root = new TrieNode('\0');
  }
private:
  void insertWord(TrieNode *root, string word){
    //Base Case
    if(word.size() == 0){
      root -> isTerminal = true;
      return;
    }

    //Small Calculation
    int index = word[0] - 'a';
    TrieNode *child;
    if(root -> children[index] != NULL){
      child = root -> children[index];
    }else{
      child = new TrieNode(word[0]);
      root -> children[index] = child;
    }
    //Recursive Call
    insertWord(child, word.substr(1));
  }

  bool searchWord(TrieNode *root, string word){
    if(root == NULL){
      return false;
    }
    if(word.size() == 0){
      return root -> isTerminal;
    }
    int index = word[0] - 'a';
    return searchWord(root -> children[index], word.substr(1));
  }

  void removeWord(TrieNode *root, string word){
    //Base Case
    if(word.size() == 0){
      root -> isTerminal = false;
      return;
    }

    //Small Calculation
    TrieNode *child;
    int index = word[0] - 'a';
    if(root -> children[index] != NULL){
      child = root -> children[index];
    }else{
      //Word Not Found
      return;
    }
    removeWord(child, word.substr(1));

    //Remove child Node if it is Useless
    if(child -> isTerminal == false){
      for(int i = 0; i < 26; i++){
        if(child -> children[i] != NULL){
          return;
        }
      }
      delete child;
      root -> children[index] = NULL;
    }
  }
public:
  void insertWord(string word){
    insertWord(root,word);
  }

  bool searchWord(string word){
    return searchWord(root,word);
  }

  void removeWord(string word){
    removeWord(root,word);
  }
};
