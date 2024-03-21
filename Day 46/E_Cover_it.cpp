#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main(){
    //#ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    //#endif
    
    fastio;

    ll t; cin>>t;
    while(t--){
        ll n, m; cin>>n>>m;
        vector<vector<ll>> graph(n+1);
        ll max_degree = 0, max_node;
        while(m--){
            ll x, y; cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);

            if (graph[x].size() > max_degree){
                max_degree = graph[x].size();
                max_node = x;
            }
            if (graph[y].size() > max_degree){
                max_degree = graph[y].size();
                max_node = y;
            }
        }

        cout<<"Max node : "<<max_node<<endl;

        queue<ll> q;
        q.push(max_node);
        vector<ll> color(n+1, -1);
        color[max_node] = 0;
        ll col0=1, col1=0;
        while(!q.empty()){
            ll u = q.front(); q.pop();
            for(auto v : graph[u]){
                if (color[v] == -1){
                    if (color[u] == 0){
                        color[v] = 1;
                        col1++;
                    }else{
                        color[v] = 0;
                        col0++;
                    }
                    q.push(v);
                }
            }
        }

        if (col0 <= col1){
            cout<<col0<<"\n";
            for(ll i=1; i<=n; i++){
                if (color[i] == 0) cout<<i<<" ";
            }
        }else{
            cout<<col1<<"\n";
            for(ll i=1; i<=n; i++){
                if (color[i] == 1) cout<<i<<" ";
            }
        }cout<<"\n";
        
    }

    return 0;
}