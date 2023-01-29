#include<bits/stdc++.h>
using namespace std;

int bit[30001];
int last[1000001];
int arr[30001];

class Event{
public:
  int first, second, index;
}query[200000];

bool compare(Event e1, Event e2){
  return e1.second < e2.second;
}

void update(int index, int value, int n, int *bit){
  for(; index <= n; index += (index&(-index))){
    bit[index] += value;
  }
}

int value(int index, int *bit){
  int count = 0;
  for(; index > 0; index -= (index&(-index))){
    count += bit[index];
  }
  return count;
}

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }

  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    cin >> query[i].first >> query[i].second;
    query[i].index = i;
  }
  int ans[q];
  sort(query, query+q, compare);
  memset(last, -1, sizeof(last));
  int total = 0, k = 0;
  for(int i = 1; i <= n; i++){
    if(last[arr[i]] != -1){
      update(last[arr[i]], -1, n, bit);
    }else{
      total++;
    }
    update(i, 1, n, bit);
    last[arr[i]] = i;
    while(k < q && query[k].second == i){
      ans[query[k].index] = total - value(query[k].first-1, bit);
      k++;
    }
  }
  for(int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
  return 0;
}
