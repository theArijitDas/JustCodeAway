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

    // n, x = map(int, next(I).strip().split())
    // arr = list(map(int, next(I).strip().split()))
    // dp = [float("inf") for _ in range(x+1)]
    // for i in range(n+1): dp[0] = 0
        
    // for k in range(1, x+1):
    //     for i in range(n):
    //         if k - arr[i] >= 0:
    //             dp[k] = min(dp[k], dp[k - arr[i]] + 1)

    // dp[x] = -1 if (dp[x] == float("inf")) else dp[x]
    // output(str(dp[x]))

    ll n, x; cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0; i<n; i++) cin>>a[i];

    vector<ll> dp(x+1, INT_MAX);
    dp[0] = 0;
    for (ll k=1; k<=x; k++){
        for (ll i=0; i<n; i++){
            if (k-a[i] >= 0) dp[k] = min(dp[k], dp[k - a[i]] + 1);
        }
    }
    cout<<((dp[x] != INT_MAX)?dp[x]:-1);

    return 0;
}