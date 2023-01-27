#include<iostream>
using namespace std;

int main() {

  //---------Array_Of_Size [5][4] ----------------//
  int **p = new int*[5];
  for(int i = 0; i < 5; i++){
    p[i] = new int[4];
    for(int j = 0; j < 4; j++){
      cin >> p[i][j];
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 4; j++){
      cout << p[i][j] << " ";
    }
    cout << endl;
    delete [] p[i];
  }
  delete [] p;

  //---------Array_Of_Size [5][4] ----------------//

  //---------Array_Of_Variable_Size ----------------//
  int m,n;
  cout << "Enter Size of Row and Column : ";
  cin >> m >> n;
  int **q = new int*[m];
  for(int i = 0; i < m; i++){
    q[i] = new int[n];
    for(int j = 0; j < n; j++){
      cin >> q[i][j];
    }
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      cout << q[i][j] << " ";
    }
    cout << endl;
    delete [] q[i];
  }
  delete [] q;
  return 0;
}
