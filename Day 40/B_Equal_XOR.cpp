#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main()
{
    fastio;
    ll t; cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        ll x;
        map<ll, ll> mp1, mp2;
        for(ll i=0; i<n; i++){
            cin>>x;
            mp1[x]++;
        }
        for(ll i=0; i<n; i++){
            cin>>x;
            mp2[x]++;
        }

        vector<ll> ans1, ans2;
        for(auto it: mp1){
            if (it.second == 2){
                ans1.push_back(it.first);
                ans1.push_back(it.first);
            }
        }
        for(auto it: mp2){
            if (it.second == 2){
                ans2.push_back(it.first);
                ans2.push_back(it.first);
            }
        }

        ll rem = 2*k - ans1.size();
        for (auto it: mp1){
            if (rem <= 0)
                break;
            if (it.second == 1){
                ans1.push_back(it.first);
                ans2.push_back(it.first);
                rem -= 1;
            }
        }

        for(ll i=0; i < 2*k; i++){
            cout<<ans1[i]<<" ";
        }cout<<"\n";
        for(ll i=0; i < 2*k; i++){
            cout<<ans2[i]<<" ";
        }cout<<"\n";
    }
}