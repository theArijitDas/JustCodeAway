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
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i=0; i<n; i++) cin>>v[i];

        vector<ll> pref(n);
        pref[0] = v[0];
        for(ll i=1; i<n; i++) pref[i] = pref[i-1]+v[i];

        ll ans = 2*pref[0];
        for(ll i=1; i<n; i++) ans = max(ans, pref[i-1] + 2*v[i]);
        cout<<ans<<"\n";       
    }
    return 0;
}