/*
Q. Print Subset Sum to K

Given an array A and an integer K, print all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:
3 3
5 1
*/

#include<iostream>
using namespace std;

void helperSubsetSum(int input[], int startIndex, int size, int output[], int oSize, int k){
    if(startIndex == size){
        if(k == 0){
            for(int i = 0; i < oSize; i++){
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    int smallOuput[1000];
    helperSubsetSum(input, startIndex+1, size, output, oSize, k);
    if( k > 0){
        int i;
        for(i = 0; i < oSize; i++){
            smallOuput[i] = output[i];
        }
        smallOuput[i] = input[startIndex];
        helperSubsetSum(input, startIndex+1, size, smallOuput, oSize+1, (k - input[startIndex]));
    }
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output[1000];
    helperSubsetSum(input, 0, size, output, 0, k);
}

int main(){
  int input[1000], length, k;
  cin >> length;
  for(int i = 0; i < length; i++){
    cin >> input[i];
  }
  cin >> k;
  printSubsetSumToK(input,length,k);
  return 0;
}
