#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 100003
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
        ll num4 = 0, num6 = 0;
        ll ans = 0;
        ll x;
        for(ll i=0; i<n; i++){
            cin>>x;
            if (x == 4) num4++;
            else if (x == 6) num6++;
            else if (x == 2){
                ans+=num6;
            }
        }

        ans += num4 * (num4 - 1) / 2;
        cout<<ans<<"\n";
    }

    return 0;
}