/*
Q. Ways To Make Coin Change

For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. 
You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.

Return 0 if the change isn't possible.

Sample Input 1 :
3
1 2 3
4

Sample Output 1 :
4

Explanation to Sample Input 1 :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2).

Sample Input 2 :
6
1 2 3 4 5 6
250

Sample Output 2 :
13868903
*/

#include <iostream>
using namespace std;

/*
//-----------Brute Force---------------------//

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
  if(value == 0){
	  return 1;
  }
  int a = (value-denominations[0] >= 0) ? countWaysToMakeChange(denominations, numDenominations, value - denominations[0]) : 0;
  int b = (numDenominations > 1) ? countWaysToMakeChange(denominations+1, numDenominations-1, value) : 0;
  return (a+b);
}

/------------Memoization-----------------/

int countWaysToMakeChange(int denominations[], int numDenominations, int index, int value, int **output){
  if(value <= 0){
	  if(value == 0){
		  return 1;
	  }
	  return 0;
  }
  if(index == numDenominations){
	  return 0;
  }
  if(output[value][index] != -1){
	  return output[value][index];
  }
  int a = countWaysToMakeChange(denominations, numDenominations, index, value - denominations[index], output);
  int b = countWaysToMakeChange(denominations, numDenominations, index+1, value, output);
  output[value][index] = (a+b);
  return output[value][index];
}

int countWaysToMakeChange(int denominations[], int numDenominations,int value){
	int **output = new int*[value+1];
	for(int i = 0; i <= value; i++){
		output[i] = new int[numDenominations];
		for(int j = 0; j < numDenominations; j++){
			output[i][j] = -1;
		}
	}
	int ans = countWaysToMakeChange(denominations, numDenominations, 0, value, output);
	for(int i = 0; i <= value; i++){
		delete [] output[i];
	}
	delete [] output;
	return ans;
}
*/

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	//Write your code here
  int **output = new int* [value+1];
  for(int i = 0; i <= value; i++){
    output[i] = new int[numDenominations];
  }
  for(int j = 0; j < numDenominations; j++){
    output[0][j] = 1;
  }

  for(int i = 1; i <= value; i++){
    for(int j = 0; j < numDenominations; j++){
      int a = (i - denominations[j] >= 0) ? output[i - denominations[j]][j] : 0;
      int b = (j >= 1) ? output[i][j-1] : 0;
      output[i][j] = (a+b);
    }
  }
  int ans = output[value][numDenominations-1];
  for(int i = 0; i <= value; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

int main(){

	int numDenominations;
	cin >> numDenominations;
	int *denominations = new int[numDenominations];
	for (int i = 0; i < numDenominations; i++){
		cin >> denominations[i];
	}
	int value;
	cin >> value;
	cout << countWaysToMakeChange(denominations, numDenominations, value);
	delete[] denominations;
}
