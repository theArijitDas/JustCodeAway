#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll n, q;
    cin>>n>>q;
    string s; cin>>s;

    vector<string> patterns = {"abc", "cab", "bca", "cba", "acb", "bac"};
    vector<vector<ll>> dp(n, vector<ll> (6, -1));

    for(ll p=0; p<6; p++){
        for(ll i=0; i<n; i++){
            if (i==0) dp[i][p] = (s[i] != patterns[p][i%3]);
            else dp[i][p] = dp[i-1][p] + (s[i] != patterns[p][i%3]);
        }
    }

    // for(ll p=0; p<6; p++){
    //     cout<<patterns[p]<<" : ";
    //     for(ll i=0; i<n; i++){
    //         cout<<dp[i][p]<<" ";
    //     }cout<<endl;
    // }

    ll l, r;
    while(q--){
        cin>>l>>r;
        l--; r--;
        if (l>0) cout<<-max({(dp[l-1][0] - dp[r][0]), (dp[l-1][1] - dp[r][1]), (dp[l-1][2] - dp[r][2]),
                            (dp[l-1][3] - dp[r][3]), (dp[l-1][4] - dp[r][4]), (dp[l-1][5] - dp[r][5])})<<"\n";
        else cout<<min({dp[r][0], dp[r][1], dp[r][2],
                        dp[r][3], dp[r][4], dp[r][5]})<<"\n";
    }
}