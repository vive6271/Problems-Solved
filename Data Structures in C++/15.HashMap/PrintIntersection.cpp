/*
Q. Print Intersection

You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. 
You need to print their intersection; An intersection for this problem can be defined when 
both the arrays/lists contain a particular value or to put it in other words, when there is 
a common value that exists in both the arrays/lists.


Note :
Input arrays/lists can contain duplicate elements.
The intersection elements printed would be in the order they appear in the second array/list (ARR2).

Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 

Sample Output 1 :
2
3 
4

Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2

Sample Output 2 :
1 
2 
2
*/

#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    unordered_map<int, int> map1;
    for(int i = 0; i < n; i++){
      if(map1.count(arr1[i]) > 0){
        map1[arr1[i]]++;
        continue;
      }
      map1[arr1[i]] = 1;
    }
    for(int i = 0; i < m; i++){
      if(map1.count(arr2[i]) == 0){
        continue;
      }else if(map1[arr2[i]] > 0){
        cout << arr2[i] << endl;
        map1[arr2[i]]--;
      }
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}
