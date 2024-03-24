#include<bits/stdc++.h>
using namespace std;

void printPath(int i, vector<int> &parent){
    if (parent[i] == i)
        cout<<i<<"->";
    else{
        printPath(parent[i], parent);
        cout<<i<<"->";
    }
}

void print(vector<int> &distance, vector<int> &parent){
    cout<<"Vertex\tDistance\tPath\n";
    for(int i=0; i<distance.size(); i++){
        if(parent[i] != -1){
            cout<<i<<"\t"<<distance[i]<<"\t\t";
            printPath(i, parent);
            cout<<"end\n";
        }
    }
}

void dijkstra(vector<vector<pair<int, int> > > &graph, int s, int n){
    vector<int> distance(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    distance[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    pq.push({0, s});
    parent[s] = s;

    while(!pq.empty()){
        pair<int, int> p = pq.top(); pq.pop();
        int u = p.second;
        if (distance[u] == p.first){
            for(int i = 0; i<graph[u].size(); i++){
                int v = graph[u][i].second;
                int w = graph[u][i].first;
                if (distance[v] > (distance[u] + w)){
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }
    }

    print(distance, parent);
}

int main(){
    bool directed;
    char c; cout<<"Is the graph directed (y/n) ?: "; cin>>c;
    directed = ((c == 'y' || c == 'Y'))?true:false;

    int m, n;
    cout<<"Number of vertices: "; cin>>n;
    cout<<"Number of edges: "; cin>>m;

    vector<vector<pair<int, int> > > graph(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cout<<"Enter vertces and edge weight of Edge "<<i+1<<" : ";
        cin>>u>>v>>w;
        graph[u].push_back({w, v});
        if (!directed) graph[v].push_back({w, u});
    }

    int s; cout<<"Enter source node: "; cin>>s; 
    dijkstra(graph, s, n);
}

/*
n
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