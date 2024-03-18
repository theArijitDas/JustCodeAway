#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

struct compare{
    bool operator()(Edge a, Edge b){
        return a.w > b.w;
    }
};

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

void primsMST(vector<vector<pair<int, int> > > graph){
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<Edge> MST;

    priority_queue<Edge, vector<Edge>, compare> pq;
    int s_parent = (graph[0].size() > 0)?0:1;
    if (graph[0].size() > 0)
        pq.push({s_parent, 0, 0});
    else
        pq.push({s_parent, 1, 0});

    while(!pq.empty()){
        Edge e = pq.top(); pq.pop();

        if (!visited[e.v]){
            visited[e.v] = true;
            if(e.v!=s_parent) MST.push_back(e);
            for(int i=0; i<graph[e.v].size(); i++){
                if (!visited[graph[e.v][i].first])
                    pq.push({e.v, graph[e.v][i].first, graph[e.v][i].second});
            }
        }
    }

    printMST(MST);
}

int main(){
    bool directed;
    char c; cout<<"Is the graph directed (y/n) ?: "; cin>>c;
    directed = ((c == 'y' || c == 'Y'))?true:false;

    int m, n;
    cout<<"Number of vertices : "; cin>>n;
    cout<<"Number of edges: "; cin>>m;

    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cout<<"Enter vertives (u-v)/(u->v) and edge weights (u, v, w) : ";
        cin>>u>>v>>w;
        graph[u].push_back({v, w});
        if (!directed) graph[v].push_back({u, w});
    }

    primsMST(graph);
}
/*
n
7 9
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