#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll n, m, q;
vector<ll> population;
vector<ll> p;
vector<bool> isEdge;
vector<pair<ll, ll>> Edges;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>> pq;

vector<ll> parent;
vector<ll> rnk;

void make_set(){
    parent.resize(n+1);
    rnk.resize(n+1);
    for(ll i=0; i<=n; i++){
        parent[i] = i;
        rnk[i] = 1;
    }
}

ll find_set(ll x){
    if (parent[x] == x) return x;
    return parent[x] = find_set(parent[x]);
}

void union_set(ll x, ll y){
    ll px = find_set(x);
    ll py = find_set(y);
    // cout<<"\nParent of "<<x<<" is "<<px<<"\n";
    // cout<<"\nParent of "<<y<<" is "<<py<<"\n";
    // cout<<"\nUnifying them\n";
    if (px == py) return;
    // if (rnk[px] == rnk[py]){
    //     parent[py] = px;
    //     population[px] += population[py];
    //     rnk[px]++;
    // }
    // if (rnk[px] > rnk[py]){
    //     parent[py] = px;
    //     population[px] += population[py];
    //     // pq.push({population[px], px});
    // }
    // else{
    //     parent[px] = py;
    //     population[py] += population[px];
    //     // pq.push({population[py], py});
    // }

    if (rnk[px] < rnk[py]) swap(px, py);
    parent[py] = px;
    population[px] += population[py];
    if (rnk[px] == rnk[py]) rnk[px] ++;
}

int main(){
    population.clear();
    p.clear();
    Edges.clear();
    isEdge.clear();
    while(!pq.empty()) pq.pop();

    cin>>n>>m>>q;
    isEdge.assign(m+1, true);
    Edges.resize(m+1);

    // Population of each town initially
    p.resize(n+1);
    for(ll i=1; i<=n; i++) cin>>p[i];

    // Roads connected initially
    for(ll i=1; i<=m; i++){
        ll x, y;
        cin>>x>>y;
        Edges[i] = {x, y};
    }

    // Queries
    stack<pair<ll, ll>> queries;
    for(ll i=0; i<q; i++){
        char c; cin>>c;
        if (c == 'D'){
            ll x; cin>>x;
            queries.push({x, -1});
            isEdge[x] = false;
        }else{
            ll x, y; cin>>x>>y;
            queries.push({x, p[x]});
            p[x] = y;
        }
    }
    population.resize(n+1);
    for(ll i=1; i<=n; i++) population[i] = p[i];

    // for(ll i=1; i<=n; i++) pq.push({population[i], i});
    make_set();
    for(ll i=1; i<=m; i++) if (isEdge[i]) union_set(Edges[i].first, Edges[i].second);
    for(ll i=1; i<=n; i++) pq.push({population[i], i});

    // cout<<"\n";for(ll i=1; i<=n; i++) cout<<i<<"<-"<<parent[i]<<"\n";
    // cout<<"\n";for(ll i=1; i<=n; i++) cout<<i<<"<-"<<find_set(i)<<"\n";

    // Process queries in reverse order
    stack<ll> ans;
    while(!queries.empty()){

        ll pop_x, x;
        tie(pop_x, x) = pq.top();
        // cout<<"\n"<<pop_x<<" "<<x<<"\n";
        while(population[x] != pop_x){
            pq.pop();
            tie(pop_x, x) = pq.top();
        }
        ans.push(pop_x);

        ll a, b;
        tie(a, b) = queries.top(); queries.pop();

        if (b == -1){
            // Road destruction type query
            // cout<<"\nJoining "<<Edges[a].first<<" "<<Edges[a].second<<"\n";
            union_set(Edges[a].first, Edges[a].second);
            // cout<<"\nParent of "<<Edges[a].first<<" is "<<parent[Edges[a].first];
            // cout<<"\nParent of "<<Edges[a].second<<" is "<<parent[Edges[a].second]<<"\n";
            pq.push({population[find_set(Edges[a].first)], find_set(Edges[a].first)});
            // cout<<"Case D"<<endl;
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            // cout<<population[find_set(Edges[a].first)]<<" "<<find_set(Edges[a].first)<<endl;
            isEdge[a] = true; // Not necessary, but for thr sake of consistency
        }else{
            // Population update type query
            ll x = a, p_ = b;
            ll px = find_set(x);

            population[px] = population[px] - p[x] + p_;
            pq.push({population[px], px});
            // cout<<"Case P"<<endl;
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            // cout<< a<<" "<< px<< " "<< population[px]<< " "<<b<<endl;
            p[x] = p_;
        }
        // cout<<"\n";for(ll i=1; i<=n; i++) cout<<i<<"<-"<<find_set(i)<<"\n";
    }

    while(!ans.empty()){
        cout<<ans.top()<<"\n";
        ans.pop();
    }
}