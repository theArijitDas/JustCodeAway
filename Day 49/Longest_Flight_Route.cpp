#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll n, m;
vector<vector<ll>> graph;
vector<ll> parent;
vector<ll> dist;
stack<ll> st;
vector<bool> visited;

void topo(ll u){
    visited[u] = true;
    for(auto v : graph[u]){
        if (!visited[v]){
            topo(v);
        }
    }st.push(u);
}

int main(){
    //#ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    //#endif
    
    fastio;
    parent.clear();
    visited.clear();
    graph.clear();

    cin>>n>>m;
    graph.resize(n+1);
    while(m--){
        ll x, y; cin>>x>>y;
        graph[x].push_back(y);
    }
    parent.resize(n+1); for(ll i=1; i<=n; i++) parent[i] = i;
    dist.assign(n+1, LLONG_MIN);
    visited.assign(n+1, false);
    dist[1] = 1;
    topo(1);

    while(!st.empty()){
        ll u = st.top(); st.pop();
        for(auto v : graph[u]){
            if (dist[v] < dist[u] + 1){
                dist[v] = dist[u]+1;
                parent[v] = u;
            }
        }
    }

    if (dist[n] == LLONG_MIN) cout<<"IMPOSSIBLE";
    else{
        cout<<dist[n]<<"\n";

        ll x = n;
        st.push(x);
        while(parent[x] != x){
            st.push(parent[x]);
            x = parent[x];
        }

        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }

    return 0;
}