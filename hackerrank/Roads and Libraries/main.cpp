#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1 << 28;
int connectedNode = 0;
vector<int> *edges;
bool *visited;

void dfs(int start){
  visited[start] = true;
  for(int i = 0; i< edges[start].size(); ++i){
      int child = edges[start][i];
      if(!visited[child]){
          dfs(child);
          ++connectedNode;
      }
  }
}

int main(){
    
    //freopen("in.txt", "r", stdin);
    
    int testCase = 0;
    scanf("%d", &testCase);
    for(int test = 1; test <= testCase; ++test){
        int n = 0, m = 0;
        ll lCost = 0, rCost = 0;
        scanf("%d%d%lld%lld",&n,&m, &lCost, &rCost);
        int u = 0, v = 0;
        
        edges = new vector<int>[n+1];
        visited = new bool[n+1];

        for(int i = 1; i<= m; ++i){
            scanf("%d%d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        
        ll cost = 0;

        for(int i = 0; i<= n; ++i) visited[i] = false;

        for(int i = 1; i<= n; ++i){
            if(!visited[i]){
                connectedNode = 0;
                dfs(i);
                cost += connectedNode * rCost + lCost;
            }
        }

        printf("%lld\n",min(lCost * n, cost));

        delete [] edges;
        delete [] visited;

    }
    return 0;
}