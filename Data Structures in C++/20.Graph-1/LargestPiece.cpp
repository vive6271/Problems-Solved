/*
Q. Largest Piece

It's Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . 
But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which 
consist of only '1's, and all '1's share an edge with each other on the cake. 
Given the size of cake N and the cake, can you find the count of '1's in the biggest piece of '1's for Gary ?


Sample Input 1:
2
1 1
0 1

Sample Output 1:
3

*/


#include <iostream>
#include <vector>
using namespace std;

int dfsTraversal(vector<vector<int>> &cake, int i, int j, int n, vector<vector<bool>> &visited){
    visited[i][j] = true;
    int count = 0;
    int arr[][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    for(int k = 0; k < 4; k++){
        int a = i + arr[k][0];
        int b = j + arr[k][1];
        if((a >= 0 && a < n) && (b >= 0 && b < n) && (cake[a][b] == 1) && !visited[a][b]){
            count += dfsTraversal(cake, a, b, n, visited);
        }
    }
    return 1+count;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n) {
    // Write your code here
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int maxPiece = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                maxPiece = max(maxPiece, dfsTraversal(cake, i, j, n, visited));
            }
        }
    }
    return maxPiece;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> cake(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }
    cout << getBiggestPieceSize(cake, n);
    return 0;
}
