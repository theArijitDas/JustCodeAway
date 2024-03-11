#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 100003
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll mulMod(ll a, ll b) {
    a *= b;
    a %= M;
    return a;
}
ll addMod(ll a, ll b) {
    long long c = (a + b) % M;
    return c;
}

vector<ll> spf(N, 0);
void init_spf(){
    for(ll i=2; i<N; i++){
        if(spf[i] == 0){
            spf[i] = i;
            for(ll j=i*i; j<N; j+=i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }
}

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
        for(ll i=0; i<n; i++){
            cin>>v[i];
        }
        for(ll i =1; i< n-1; i++){
            ll d = min(v[i]/2, min(v[i-1], v[i+1]));
            v[i-1] -= d;
            v[i] -= 2*d;
            v[i+1] -= d;
        }
        bool flag = true;
        for(ll i=0; i<n; i++){
            if (v[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}