#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define ll long long int
int bit[MAX];

class Event{
public:
  int left;
  int right;
  ll value;
  int index;
};

class Element{
public:
  int value;
  int index;
};

bool compare(Element e1, Element e2){
  return e1.value > e2.value;
}

bool compare2(Event e1, Event e2){
  if(e1.value == e2.value){
    return (e1.left > e2.left);
  }
  return (e1.value > e2.value);
}

void update(int index, int n){
  for(; index <= n; index += (index&(-index))){
    bit[index]++;
  }
}

int value(int index){
  int count = 0;
  for(; index > 0; index -= (index&(-index))){
    count += bit[index];
  }
  return count;
}

int main(){
  int n, q;
  cin >> n;
  Element *arr = new Element[n+1]();
  for(int i = 1; i <= n; i++){
    cin >> arr[i].value;
    arr[i].index = i;
  }
  sort(arr+1, arr+n+1, compare);
  cin >> q;
  Event *query = new Event[q+1];
  for(int i = 0; i < q; i++){
    cin >> query[i].left >> query[i].right >> query[i].value;
    query[i].index = i;
  }
  sort(query, query+q, compare2);
  int *ans = new int[q+1]();
  int z = 1;
  for(int i = 0; i < q; i++){
    while(z <= n && query[i].value < arr[z].value){
      update(arr[z].index, n);
      z++;
    }
    ans[query[i].index] = value(query[i].right) - value(query[i].left-1);
  }
  for(int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
  delete [] arr;
  delete [] query;
  delete [] ans;
  return 0;
}
