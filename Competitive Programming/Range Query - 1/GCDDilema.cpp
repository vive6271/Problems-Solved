#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
const int M = 44444;
int T[N][15], in[N], n;
int res[N];

void built(){
  for (int i = 1; i <= n; i++){
    T[i][0] = in[i];
  }
  for (int j = 1; (1 << j) <= n; j++){
    for (int i = 1; i + (1 << j) - 1 <= n; i++){
      T[i][j] = __gcd(T[i][j - 1], T[i + (1 << (j - 1))][j - 1]);
    }
  }
}


int query(int x, int y){
  int k = log2(y - x + 1);
  return __gcd(T[x][k], T[y - (1 << k) + 1][k]);
}

vector<int> table[(1 << 16) + 10];
vector<int> cnt[(1 << 16) + 10];
int sz[(1 << 16) + 10];

void Insert(int y, int c){
  int x = y;
  for (int i = 0; i < sz[x]; i++){
    if (table[x][i] == y){
      cnt[x][i] += c;
      return;
    }
  }
  table[x].push_back(0);
  cnt[x].push_back(0);
  table[x][sz[x]] = y;
  cnt[x][sz[x]] = c;
  sz[x]++;
}


int Query(int y){
  int x = y;
  for (int i = 0; i < sz[x]; i++){
    if (table[x][i] == y){
      return cnt[x][i];
    }
  }
  return 0;
}


int main(){
  cin >> n;
  for (int i = 0; i < n; i++){
     cin >> in[i + 1];
  }
  built();
  for (int i = 1; i <= n; i++){
    int ed = i;
    while (ed <= n){
      int low = ed, high = n, r = ed;
      int g = query(i, ed);
      while (low <= high){
        int mid = low + high >> 1;
        if (query(i, mid) == g){
          r = mid;
          low = mid + 1;
        }else{
          high = mid - 1;
        }
      }
      Insert(g, r - ed + 1);
      ed = r + 1;
    }
  }
  int qr;
  cin >> qr;
  for (int i = 0; i < qr; i++){
    int x;
    cin >> x;
    res[i] = Query(x);
    cout << res[i] << endl;
  }
  return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

const int LIM = 100003;
int A[LIM], N;
map<int, long long> countg[2], finalc; // final[i] stores the countg of subarrays with gcd = i
map<int, long long>::iterator it;

void precompute() {
  countg[0][A[0]] = 1;
  finalc[A[0]] = 1LL;
  int g, curr, prev;
  for(int i = 1; i < N; i++) {
    curr = i & 1, prev = curr ^ 1;
    countg[curr].clear();
    countg[curr][A[i]] = 1LL;    // 1 for the subarray containing only A[i], rest will come from taking gcd with those till A[i - 1] in countg[prev]
    for(it = countg[prev].begin(); it != countg[prev].end(); it++) {
      g = __gcd(it->first, A[i]);
      countg[curr][g] += it->second;   // every subarray giving it->first till A[i - 1] will give g with A[i]
    }
    for(it = countg[curr].begin(); it != countg[curr].end(); it++) finalc[it->first] += it->second;
  }
}

int main() {

  cin >> N;
  for(int i = 0; i < N; i++) cin >> A[i];
  precompute();
  int Q, x;
  long long ans;
  cin >> Q;
  while(Q--) {
    cin >> x;
    ans = finalc[x];
    cout << ans << "\n";
  }

  return 0;
}
*/
