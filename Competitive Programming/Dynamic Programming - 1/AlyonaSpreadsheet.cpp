#include<bits/stdc++.h>
using namespace std;

int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    int *input1 = new int[m];
    int *input2 = new int[m];
    int *dp1 = new int[m];
    int *dp2 = new int[m];
    int *output = new int[n];

    for(int i = 0; i < n; i++){
      int minVal = i;
      for(int j = 0; j < m; j++){
        cin >> input1[j];
        dp1[j] = i;
        if(i == 0){
          continue;
        }
        if(input1[j] >= input2[j]){
          dp1[j] = dp2[j];
        }
        minVal = min(minVal,dp1[j]);
      }
      output[i] = minVal;

      //Swap arr
      int *tmp = input1;
      input1 = input2;
      input2 = tmp;

      //Swap DP
      tmp = dp1;
      dp1 = dp2;
      dp2 = tmp;
    }

    delete [] input1;
    delete [] input2;
    delete [] dp1;
    delete [] dp2;

    int q;
    cin >> q;
    while(q--){
      int a, b;
      cin >> a >> b;
      if(output[b-1] <= a-1){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }
    delete [] output;
  }
  return 0;
}
