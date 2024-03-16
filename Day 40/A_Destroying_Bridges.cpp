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
        ll n, k; cin>>n>>k;
        cout<<(k>=(n-1)?1ll:n)<<"\n";
    }

    return 0;
}