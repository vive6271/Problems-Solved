#include<iostream>
using namespace std;
int mod =  1000000000+7;

/* // Brute Force
int numCode(int *arr, int size){
  if(size == 0 || size == 1){
    return 1;
  }

  int output = 0;
  if(arr[size-1] != 0){
    output += numCode(arr,size-1,find) % mod;
  }
  if((arr[size-2] * 10) + arr[size-1] <= 26 && arr[size-2] != 0){
    output += numCode(arr,size-2,find) %mod;
    output %= mod;
  }
  return output;
}

// Memoization

int numCode(int *arr, int size, int *find){
  if(size == 0 || size == 1){
    return 1;
  }
  if(find[size] != -1){
    return find[size];
  }
  int output = 0;
  if(arr[size-1] != 0){
    output += numCode(arr,size-1,find) % mod;
  }
  if((arr[size-2] * 10) + arr[size-1] <= 26 && arr[size-2] != 0){
    output += numCode(arr,size-2,find) %mod;
    output %= mod;
  }
  find[size] = output;
  return output;
}

int numCode(int *arr, int size){
  int *find = new int[size+1];
  for(int i = 0; i <= size; i++){
    find[i] = -1;
  }
  int ans = numCode(arr,size,find);
  delete [] find;
  return ans;
}
*/

int numCode(int *arr, int size){
  int *find = new int[size+1];

  find[0] = 1;
  find[1] = 1;
  for(int i = 2; i <= size; i++){
    int output = 0;
    if(arr[i-1] != 0){
      output += find[i-1] % mod;
    }
    if((arr[i-2] * 10) + arr[i-1] <= 26 && arr[i-2] != 0){
      output += find[i-2] %mod;
      output %= mod;
    }
    find[i] = output;
  }
  int ans = find[size];
  delete [] find;
  return ans;
}
int main(){
  int t;
  cin >> t;
  while(t--){
    string str;
    cin >> str;
    int *arr = new int[str.length()];
    int i;
    for(i = 0; i < str.length(); i++){
      arr[i] = str[i] - '0';
    }
    cout << numCode(arr,i) << endl;
    delete [] arr;
  }
  return 0;
}
