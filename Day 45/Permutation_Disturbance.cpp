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
        ll n; cin>>n;
        vector<ll> v(n);
        for(ll i=0; i<n; i++) cin>>v[i];

        ll ans = 0;
        for(ll i=0; i<n; i++){
            if (i+1 == v[i]){
                ans++;
                i++;
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}