#include<iostream>
#include<string>
using namespace std;

int lcsHelper(string s, string t, int **output){
  int m = s.size(), n = t.size();
  if(s.size() == 0 || t.size() == 0){
    return 0;
  }

  if(output[m][n] != -1){
    return output[m][n];
  }
  //Recursive Call
  int ans;
  if(s[0] == t[0]){
    ans = 1 + lcsHelper(s.substr(1), t.substr(1), output);
  }else{
    int a = lcsHelper(s.substr(1), t, output);
    int b = lcsHelper(s, t.substr(1), output);
    int c = lcsHelper(s.substr(1), t.substr(1), output);
    ans = max(a, max(b,c));
  }
  output[m][n] = ans;
  return ans;
}

int lcsMemo(string s, string t){
  int m = s.size(), n = t.size();
  int **output = new int*[m+1];
  for(int i = 0; i <= m; i++){
    output[i] = new int[n+1];
    for(int j = 0; j <= n; j++){
      output[i][j] = -1;
    }
  }
  int ans = lcsHelper(s, t, output);
  for(int i = 0; i <= m; i++){
    delete [] output[i];
  }
  delete [] output;
  return ans;
}

int main(){
  string s1, s2;
  cin >> s1 >> s2;
  cout << lcsMemo(s1,s2) << endl;
  return 0;
}
