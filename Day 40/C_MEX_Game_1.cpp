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
        map<ll, ll> mp;
        ll x;
        for(ll i=0; i<n; i++){
            cin>>x;
            mp[x] += 1;
        }
        ll one = n;
        set<ll> ans;
        for(auto it: mp){
            if (it.second >= 2)
                ans.insert(it.first);
            else
                one = min(one, it.first);
        }
        if (one < n)
            ans.insert(one);
        
        ll MEX = 0;
        for(auto it : ans)
            if (it == MEX) MEX+=1;
        
        cout<<MEX<<endl;
    }

    return 0;
}