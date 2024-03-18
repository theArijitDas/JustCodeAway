#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

bool cmp(Edge a, Edge b){
    return (a.w < b.w);
}

void printMST(vector<Edge> MST){
    int cost = 0;
    cout<<"  Edges  \tWeight\n";
    for(int i=0; i<MST.size(); i++){
        Edge e = MST[i];
        cost += e.w;
        cout<<e.u<<"\t"<<e.v<<"\t"<<e.w<<"\n";
    }
    cout<<"Total cost: "<<cost;
}

struct DSU{
    vector<int> parent, rank;

    void make_set(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=0; i<=n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find_set(int x){
        if (parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }

    void union_set(int x, int y){
        int px = find_set(x);
        int py = find_set(y);

        if (px == py)
            return;
        
        if (rank[px] == rank[py]){
            parent[py] = px;
            rank[px]++;
            return;
        }
        else if (rank[px] > rank[py]){
            parent[py] = px;
            return;
        }else{
            parent[px] = py;
            return;
        }
    }
};

void krushkalMST(vector<Edge> graph, int n){
    sort(graph.begin(), graph.end(), cmp);
    DSU dsu;
    dsu.make_set(n);
    
    vector<Edge> MST;
    for(int i=0; i<graph.size(); i++){
        Edge e = graph[i];
        if (dsu.find_set(e.u) != dsu.find_set(e.v)){
            dsu.union_set(e.u, e.v);
            MST.push_back(e);
        }
    }

    printMST(MST);
}

int main(){
    int m, n;
    cout<<"Number of vertices : "; cin>>n;
    cout<<"Number of edges: "; cin>>m;

    vector<Edge> graph;
    for(int i=0; i<m; i++){
        int u, v, w;
        cout<<"Enter vertives (u-v)/(u->v) and edge weights (u, v, w) for edge "<<i+1<<" : ";
        cin>>u>>v>>w;
        graph.push_back({u, v, w});
    }

    krushkalMST(graph, n);
}

/*
7
9
1 2 5
1 4 1
4 5 3
2 5 6
2 3 1
3 7 1
3 6 2
5 6 7
6 7 5
*/