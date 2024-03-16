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
        if (n & 1)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            for(ll i = 0; i*2 < n; i++){
                char c = i + 'A';
                cout<<c<<c;
            }
            cout<<"\n";
        }
    }

    return 0;
}