#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

vector<vector<pair<ll, ll>>> graph;
vector<ll> d, vis;

bool solve(int i){
    d[i] = 0;
    queue<ll> q;
    q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 1;
        for(auto neighbour: graph[u]){
            ll v = neighbour.first;
            ll w = neighbour.second;
            if (vis[v] == 0){
                d[v] = d[u] + w;
                q.push(v);
            }else if (d[v] != d[u] + w){
                return false;
            }
        }
    }return true;
}

int main(){
    //#ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    //#endif
    
    fastio;

    ll t; cin>>t;
    while(t--){
        ll n, m; cin>>n>>m;
        graph.clear();
        graph.resize(n+1);
        for(ll i=0; i<m; i++){
            ll x, y, w;
            cin>>x>>y>>w;
            graph[x].push_back({y, w});
            graph[y].push_back({x, -w});
        }

        bool flag = true;
        d.assign(n+1, LLONG_MAX), vis.assign(n+1, 0);
        for (ll i=1; i<n+1; i++){
            if(vis[i] == 0 && solve(i) == false){
                flag = false;
                break;
            }
        }
        if (flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

    return 0;
}