#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<unordered_set<ll>> parents(n+1);
        for (ll i = 0; i < m; ++i) {
            ll u, v, c;
            cin >> u >> v >> c;
            c += n;
            parents[u].insert(c);
            parents[v].insert(c);
        }

        unordered_map<ll, vector<ll>> graph;
        for (ll i = 1; i <= n; ++i) {
            for (ll p : parents[i]) {
                graph[i].push_back(p);
                graph[p].push_back(i);
            }
        }

        ll s, d;
        cin >> s >> d;

        queue<ll> q;
        q.push(s);
        unordered_map<ll, ll> distance;
        for (auto& node : graph) {
            distance[node.first] = LLONG_MAX;
        }
        distance[s] = 0;

        while (!q.empty()) {
            ll u = q.front(); q.pop();
            if (u == d) break;
            for (auto v : graph[u]) {
                if (distance[v] == LLONG_MAX) {
                    distance[v] = 1 + distance[u];
                    q.push(v);
                }
            }
        }

        cout << distance[d]/2 << "\n";
    }

    return 0;
}