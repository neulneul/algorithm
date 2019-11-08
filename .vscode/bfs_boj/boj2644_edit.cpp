#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graph{
public:
    int N;
    vector<vector<int > > adj;

    Graph(): N(0){}
    Graph(int n): N(n){
        adj.resize(N);
    }

    void addEdge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    void sortList(){
        for(int i = 0; i < N; i++){
            sort(adj[i].begin(), adj[i].end());
        }
    }

    int bfs(int num1, int num2){
        vector<bool> visited(N, false);
        queue<int> Q;
        Q.push(num1);
        visited[num1] = true;

        int level = 0;
        int ans = -1;
        while(!Q.empty()){
            int qSize = Q.size();
            for(int i = 0; i < qSize; i++){
                int curr = Q.front();
                if(curr == num2) ans = level;
                Q.pop();
                for(int next: adj[curr]){
                    if(!visited[next]){
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            }
            level++;
        }
        
        return ans;

    }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(nullptr);

    int n, a, b, m;
    cin >> n; // 정점 개수
    cin >> a >> b;
    cin >> m; // 간선 개수

    Graph G(n);

    while(m--){//간선 m개 입력
        int i, j;
        cin >> i >> j;
        G.addEdge(i-1, j-1);
    }

    int ans = G.bfs(a-1, b-1);
    cout << ans;
    
    return 0;
}