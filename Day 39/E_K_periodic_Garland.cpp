#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll n, k;
string s;
vector<ll> pref;
vector<vector<ll>> dp;

ll solve(ll i, ll b){
    if (dp[i][b] != -1)
        return dp[i][b];
    
    if (b == 1){
        ll cost1 = pref[i-1];
        ll cost2 = i >= k ? (pref[i-1] - pref[i-k] + solve(i-k, 1)) : LLONG_MAX;
        return dp[i][b] = min(cost1, cost2) + (s[i] == '0');
    }else{
        return dp[i][b] = min(solve(i-1, 0), solve(i-1, 1)) + (s[i] == '1');
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
        cin>>n>>k;
        cin>>s;

        pref.assign(n, 0);
        dp.assign(n, vector<ll> (2, -1));

        pref[0] = (s[0] == '1');
        for(ll i=1; i<n; i++){
            pref[i] = pref[i-1] + (s[i] == '1');
        }

        dp[0][0] = dp[0][1] = 0;
        cout<<min(solve(n-1, 0), solve(n-1, 1))<<endl;
    }

    return 0;
}