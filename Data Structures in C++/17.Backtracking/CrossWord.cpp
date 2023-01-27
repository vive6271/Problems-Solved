/*
Q. Crossword Problem

Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. 
Now, you are also provided with a word list that needs to placed accurately in the grid. 
Cells marked with '-' are to be filled with word list.

For example, The following is an example for the input crossword grid and the word list.

+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------

CALIFORNIA;NIGERIA;CANADA;TELAVIV

Output for the given input should be:

+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

Note: We have provided such test cases that there is only one solution for the given input.

Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------

CALIFORNIA;NIGERIA;CANADA;TELAVIV

Sample Output 1:

+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

*/

#include<bits/stdc++.h>
using namespace std;
#define N 10

int isValidVertical(char cross[N][N], int row, int col, string checkWord){
    int count = 0;
    for(int i = row; i < N; i++){
        if(cross[i][col] == '-' || cross[i][col] == checkWord[count]){
            count++;
        }else{
            break;
        }
    }
    return count;
}

int isValidHorizontal(char cross[N][N], int row, int col, string checkWord){
    int count = 0;
    for(int j = col; j < N; j++){
        if(cross[row][j] == '-' || cross[row][j] == checkWord[count]){
            count++;
        }else{
            break;
        }
    }
    return count;
}

void setVertical(char cross[N][N], int row, int col, string insertWord, bool track[]){
    int index = 0;
    for(int i = row; i < row + insertWord.length(); i++){
        if(cross[i][col] == '-'){
            cross[i][col] = insertWord[index];
            track[index] = true;
        }
        index++;
    }

}

void resetVertical(char cross[N][N], int row, int col, string removeWord, bool track[]){
    int index = 0;
    for(int i = row; i < row + removeWord.length(); i++){
        if(track[index] == true){
            cross[i][col] = '-';
            track[index] = false;
        }
        index++;
    }
}

void setHorizontal(char cross[N][N], int row, int col, string insertWord, bool track[]){
  int index = 0;
    for(int j = col; j < col + insertWord.length(); j++){
        if(cross[row][j] == '-'){
            cross[row][j] = insertWord[index];
            track[index] = true;
        }
        index++;
    }
}

void resetHorizontal(char cross[N][N], int row, int col, string removeWord, bool track[]){
    int index = 0;
    for(int j = col; j < col + removeWord.length(); j++){
        if(track[index] == true){
            cross[row][j] = '-';
            track[index] = false;
        }
        index++;
    }
}

bool crossWord(char cross[N][N], string word[], int wordSize, int index){
    if(index == wordSize){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cout << cross[i][j];
            }
            cout << endl;
        }
        return true;
    }

    string checkWord = word[index];
    int wordLength = checkWord.length();

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(cross[i][j] == '-' || cross[i][j] == checkWord[0]){
                if(isValidVertical(cross, i, j, checkWord) == wordLength){
                    bool track[wordLength];
                    setVertical(cross, i, j, checkWord, track);
                    if(crossWord(cross, word, wordSize, index+1)){
                        return true;
                    }
                    resetVertical(cross, i, j, checkWord, track);
                }

                if(isValidHorizontal(cross, i, j, checkWord) == wordLength){
                    bool track[wordLength];
                    setHorizontal(cross, i, j, checkWord, track);
                    if(crossWord(cross, word, wordSize, index+1)){
                        return true;
                    }
                    resetHorizontal(cross, i, j, checkWord, track);
                }
            }
        }
    }
    return false;
}

int main(){
  char cross[N][N];
  for(int i = 0; i < N; i++){
    char ch[N+1];
    cin.getline(ch,N+1);
    for(int j = 0; ch[j] != '\0'; j++){
      cross[i][j] = ch[j];
    }
  }

  string word[6], input;
  int numWord = 0;
  cin >> input;
  for(int i = 0; i < input.length(); i++){
    if(input[i] == ';'){
      numWord++;
      continue;
    }
    word[numWord] += input[i];
  }
  crossWord(cross, word, numWord+1, 0);
  return 0;
}
