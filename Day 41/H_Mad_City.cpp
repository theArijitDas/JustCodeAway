#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll a, b, n;
vector<vector<ll>> graph;
vector<ll> parent, dist;
vector<bool> visited;

ll entryPoint(ll b){
    if (visited[b]) return b;
    visited[b] = true;
    for(auto v : graph[b]){
        if (v != parent[b]){
            parent[v] = b;
            ll e = entryPoint(v);
            if (e != -1){
                return e;
            }
        }
    }
    return -1;
}

void populateDist(ll x){
    queue<ll> q;
    q.push(x);
    while(!q.empty()){
        x = q.front(); q.pop();
        for (auto v : graph[x]){
            if (dist[v] == -1){
                dist[v] = dist[x] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    //#ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    //#endif
    
    fastio;

    ll t; cin>>t;
    while(t--){
        cin>>n>>a>>b;
        graph.clear();
        graph.resize(n+1);

        for(ll i=0; i<n; i++){
            ll u, v; cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (a == b){
            cout<<"NO\n";
            continue;
        }

        visited.clear();
        visited.assign(n+1, false);
        parent.clear();
        parent.assign(n+1, false);
        parent[b] = b;
        ll e = entryPoint(b);
        // cout<<"b = "<<b<<" entry at "<<e<<endl;
        dist.clear();
        dist.assign(n+1, -1);
        dist[e] = 0;
        populateDist(e);

        if (dist[a] > dist[b]){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }

    }

    return 0;
}