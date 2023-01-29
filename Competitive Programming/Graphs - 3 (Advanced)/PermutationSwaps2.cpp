#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int index, bool visited[], vector<int> &data){
    visited[index] = true;
    data.push_back(index);
    for (int i = 0; i < adj[index].size(); i++){
        if (visited[adj[index][i]] == false){
            dfs(adj, adj[index][i], visited, data);
        }
    }
}

bool solve(vector<vector<int>> &adj, int n, vector<int> &pseq, vector<int> &qseq){
    bool visited[n];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++){
        vector<int> data;
        if (visited[i] == false){
            dfs(adj, i, visited, data);
            vector<int> temp1, temp2;
            for (int i = 0; i < data.size(); i++){
                temp1.push_back(pseq[data[i]]);
                temp2.push_back(qseq[data[i]]);
            }
            sort(temp1.begin(), temp1.end());
            sort(temp2.begin(), temp2.end());
            if (temp1 != temp2){
                return false;
            }
        }
    }
    return true;
}


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<int> pseq(n), qseq(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++){
            cin >> pseq[i];
        }
        for (int i = 0; i < n; i++){
            cin >> qseq[i];
        }
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        if (solve(adj, n, pseq, qseq)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
