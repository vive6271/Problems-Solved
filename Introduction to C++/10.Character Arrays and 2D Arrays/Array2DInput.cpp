#include<iostream>
using namespace std;

int main(){
  int arr[100][100];
  int m,n;

  cout << "Enter value of Row and Col : " ;
  cin >> m >> n;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cin >> arr[i][j];
    }
  }

  cout << "Row Wise Print" << endl;

  for(int a = 0; a < m; a++){
    for(int b = 0; b < n; b++){
      cout << arr[a][b] << " ";
    }
    cout << endl;
  }

  cout << "Column Wise Print" << endl;

  for(int c = 0; c < n; c++){
    for(int d = 0; d < m; d++){
      cout << arr[d][c] << " ";
    }
    cout << endl;
  }
}
