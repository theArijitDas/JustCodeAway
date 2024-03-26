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

    int n, x; cin>>n>>x;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin>>coins[i];

    vector<int> dp(x+1);
    dp[0] = 1;
    for(int i = 1; i<=x; i++){
        for(auto c : coins){
            dp[i] = (dp[i] + ((i>=c)?dp[i-c]:0)) % M;
        }
    }
    cout<<(dp[x])%M;

    return 0;
}