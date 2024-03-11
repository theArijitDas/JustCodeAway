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
        ll n, m, k; cin>>n>>m>>k;
        vector<ll> b(n), c(m);
        for (ll i=0; i<n; i++) cin>>b[i];
        for (ll i=0; i<m; i++) cin>>c[i];

        ll count = 0;
        for (ll i = 0; i<n; i++){
            for (ll j = 0; j<m; j++){
                if (b[i] + c[j] <= k){
                    count += 1;
                }
            }
        }
        cout<<count<<endl;
    }

    return 0;
}