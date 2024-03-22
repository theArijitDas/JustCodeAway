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
        vector<ll> v(n+1);
        for(ll i=1; i<=n; i++) cin>>v[i];
        sort(v.begin()+1, v.end());
        // ll idx = ceil((float)n/2);
        ll idx = n/2 + n%2;
        ll med = v[idx];
        ll ans = 0;
        for(ll i=idx; i<=n; i++){
            if (v[i] == med) ans++;
            else break;
        }
        cout<<ans<<endl;
    }

    return 0;
}