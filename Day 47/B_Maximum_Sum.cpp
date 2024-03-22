#include<bits/stdc++.h>
using namespace std;

#define M 1000000007

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

ll f(ll a){
    return (a + M) % M;
}

ll binPow(ll base, ll exponent) {
    ll result = 1;
    base %= M;

    while (exponent > 0) {
        // If exponent is odd, multiply base with result
        if (exponent & 1) {
            result = (result * base) % M;
        }

        // exponent must be even now
        exponent = exponent >> 1; // equivalent to exponent /= 2
        base = (base * base) % M;
    }
    return result;
}

int main(){
    //#ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    //#endif
    
    fastio;

    ll t; cin>>t;
    while(t--){
        ll n, k; cin>>n>>k;
        vector<ll> v(n);
        for(ll i=0; i<n; i++) cin>>v[i];

        ll max_sum=0, temp=0;

        for(auto x : v){
            temp += x;
            max_sum = max(max_sum, temp);
            temp = max(temp, 0ll);
        }

        ll total_sum = 0;
        for(auto x : v) total_sum = f(f(total_sum) + x);

        ll left_sum = f(f(total_sum) - f(max_sum));

        ll ans = f(left_sum + f(f(binPow(2, k))) * f(max_sum));
        cout<<ans<<"\n";
    }

    return 0;
}