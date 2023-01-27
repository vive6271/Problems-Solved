/*
Q. Sum of Two Arrays

Two random integer arrays/lists have been given as ARR1 and ARR2 of size N and M respectively. 
Both the arrays/lists contain numbers from 0 to 9(i.e. single digit integer is present at every index). 
The idea here is to represent each array/list as an integer in itself of digits N and M.

You need to find the sum of both the input arrays/list treating them as two integers and put the result 
in another array/list i.e. output array/list will also contain only single digit at every index.

Note:
The sizes N and M can be different. 

Output array/list(of all 0s) has been provided as a function argument. Its size will always be one more 
than the size of the bigger array/list. Place 0 at the 0th index if there is no carry. 

No need to print the elements of the output array/list.

Using the function "sumOfTwoArrays", write the solution to the problem and store the answer inside this 
output array/list. The main code will handle the printing of the output on its own.


Sample Input 1:
1
3
6 2 4
3
7 5 6

Sample Output 1:
1 3 8 0

Sample Input 2:
2
3
8 5 2
2
1 3
4
9 7 6 1
3
4 5 9

Sample Output 2:
0 8 6 5
1 0 2 2 0 
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int n){
  for(int k = 0; k < n; k++){
    cout << arr[k] << " ";
  }
  cout << endl;
}

void sumArray(int arr1[], int n, int arr2[], int m, int arrSum[]) {
  int sumNum = 0;
  int carry = 0;
  if(n > m){
    sumNum = n + 1;
  }else{
    sumNum = m + 1;
  }
  int a = n-1;
  int b = m-1;
  int o = sumNum-1;
  int sum = 0;
  while(o >= 0 && a >= 0 && b >= 0){
    sum = arr1[a] + arr2[b] + carry;
    arrSum[o] = sum % 10;
    carry = sum / 10;
    a--;
    b--;
    o--;
  }
  while(o >= 0 && a >= 0){
    sum = arr1[a] + carry;
    arrSum[o] = sum % 10;
    carry = sum / 10;
    a--;
    o--;
  }
  while(o >= 0 && b >= 0){
    sum = arr2[b] + carry;
    arrSum[o] = sum % 10;
    carry = sum / 10;
    b--;
    o--;
  }
  arrSum[0] = carry;
  printArray(arrSum, sumNum);
}

int main(){
  int n, m;

  cin >> n;
  int arr1[100];
  for(int i = 0; i < n; i++){
    cin >> arr1[i];
  }

  cin >> m;
  int arr2[100];
  for(int j = 0; j < m; j++){
    cin >> arr2[j];
  }

  int arrSum[100];

  sumArray( arr1, n, arr2, m, arrSum);
}
