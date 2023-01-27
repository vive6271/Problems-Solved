#include <iostream>
using namespace std;
#include "Trie.h"

int main(){
  Trie t;
  t.insertWord("and");
  t.insertWord("are");
  t.insertWord("dot");

  cout << (t.searchWord("and") ? "true" : "false" )<< endl;
  t.removeWord("and");
  cout << (t.searchWord("and") ? "true" : "false" )<< endl;
  return 0;
}
