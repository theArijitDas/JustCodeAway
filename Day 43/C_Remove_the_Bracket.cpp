#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll n, s;
vector<ll> a;
map<vector<ll>, ll> dp;

ll min4(ll a, ll b, ll c, ll d){
    return min({a,b,c,d});
}

ll solve(ll i, ll j, ll x){
    if (i < 1){
        return 0;
    }
    
    if (dp.find({i, j, x}) != dp.end())
        return dp[{i, j, x}];
    
    ll y;
    if (i == 1) y = a[1];
    else if (j == 0){
        // Max value
        if (a[i] <= s) y = a[i];
        else y = max(a[i] - s, s);
    }else{
        // Min value
        if (a[i] <= s) y = 0;
        else y = min(a[i]-s, s);
    }

    dp[{i, j, x}] = (x * y) + min(solve(i-1, 0, a[i] - y), solve(i-1, 1, a[i] - y));
    
    return dp[{i, j, x}];
}

int main(){
    fastio;

    ll t; cin>>t;
    while(t--){
        cin>>n>>s;
        a.clear();
        a.resize(n+1);

        for(ll i=1; i<=n; i++) cin>>a[i];

        dp.clear();

        ll ans = min4(solve(n-1, 0, a[n]), solve(n-1, 1, a[n]), 
                    solve(n-1, 2, a[n]), solve(n-1, 3, a[n]));
        cout<<ans<<"\n";
    }

    return 0;
}