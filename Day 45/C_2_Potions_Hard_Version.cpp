#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main(){

    fastio;

    ll n; cin>>n;
    vector<ll> v(n);
    for(ll i=0; i<n; i++) cin>>v[i];

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll health = 0, cnt =0;

    for(ll i=0; i<n; i++){
        health += v[i];
        cnt++;
        pq.push(v[i]);

        if (health < 0){
            cnt--;
            ll x = pq.top(); pq.pop();
            health -= x;
        }
    }
    cout<<cnt; 
}