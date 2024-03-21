#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define M 1000000007

int main(){
    //#ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    //#endif
    
    fastio;

    ll n, m; cin>>n>>m;
    vector<ll> a(n+1);
    for(ll i=1; i<=n; i++) cin>>a[i];

    vector<vector<ll>> dp(n+1, vector<ll> (m+1, 0));
    if (a[1] == 0) for(ll j=1; j<=m; j++) dp[1][j] = 1;
    else dp[1][a[1]] = 1;

    for (ll i=2; i<=n; i++){
        if (a[i] == 0){
            for(ll j=1; j<=m; j++){
                dp[i][j] = ((dp[i-1][j] + ((j>1)?dp[i-1][j-1]:0))%M + ((j<m)?dp[i-1][j+1]:0))%M;
            }
        }else{
            ll j = a[i];
            dp[i][j] = ((dp[i-1][j] + ((j>1)?dp[i-1][j-1]:0))%M + ((j<m)?dp[i-1][j+1]:0))%M;
        }
    }

    ll ans = 0;
    for(ll j=1; j<=m; j++) ans = (ans + dp[n][j])%M;
    cout<<ans;

    return 0;
}