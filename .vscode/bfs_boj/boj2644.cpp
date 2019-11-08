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
        while(!Q.empty()){
            int qSize = Q.size();
            for(int i = 0; i < qSize; i++){
                int curr = Q.front();
                if(curr == num2) break;
                Q.pop();
                for(int next: adj[curr]){
                    if(!visited[next]){  
                        visited[next] = true;
                        Q.push(next);
                    }
                }
            level++;
            }
        }
        if(level == 0) return -1;
        else return level;
    }
};

int main(){
    int n, a, b, m;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // 보통 여기까지 두 줄 작성함.
    cin.tie(nullptr);  

    cin >> n;
    cin >> a >> b;
    cin >> m;

    Graph G(n);

    while(m--){
        int i, j;
        cin >> i >> j;
        G.addEdge(i, j);
    }
    G.sortList();
    
    int ans = G.bfs(a, b);//a가 사직점 b가 bfs 탐색 끝

    cout << ans;
    
    return 0;
}