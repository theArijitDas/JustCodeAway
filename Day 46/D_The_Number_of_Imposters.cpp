#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main(){
    fastio;

    int t; cin>>t;
    while(t--){
        ll n, m; cin>>n>>m;
        vector<vector<pair<string, ll>>> graph(n+1);
        while(m--){
            string s; ll x, y;
            cin>>x>>y>>s;
            graph[x].push_back({s, y});
            graph[y].push_back({s, x});
        }

        vector<ll> color(n+1, -1);
        ll ans = 0;
        bool possible = true;

        for(ll i=1; i<=n; i++){
            if (color[i] == -1){
                color[i] = 0;
                ll grp0=0, grp1=0;
                queue<ll> q;
                q.push(i);
                while(!q.empty()){
                    ll u = q.front(); q.pop();
                    if (color[u] == 0) grp0++;
                    else grp1++;

                    for(auto p: graph[u]){
                        ll v; string type;
                        tie(type, v) = p;
                        if (color[v] == -1){
                            if (type == "imposter") color[v] = 1 - color[u];
                            else color[v] = color[u];
                            q.push(v);
                        }else if ((type == "imposter" && color[u] == color[v])
                                ||(type == "crewmate" && color[u] != color[v])){
                                        possible = false;
                                        break;
                        }
                    }
                    if (!possible) break;
                }
                if (!possible) break;
                ans += max(grp0, grp1);
            }
        }
        if (!possible) cout<<-1<<"\n";
        else cout<<ans<<"\n";
    }
    return 0;
}