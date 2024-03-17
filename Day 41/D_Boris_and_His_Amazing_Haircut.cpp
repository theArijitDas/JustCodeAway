#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

int main()
{
    // #ifndef ONLINE_JUDGE
    //	freopen("in.txt", "r", stdin);
    //	freopen("out.txt", "w", stdout);
    // #endif

    fastio;

    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);
        bool flag = true;
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
        {
            cin >> b[i];
            if (a[i] < b[i])
                flag = false;
        }

        ll k;
        cin >> k;
        map<ll, ll> r;
        for (ll i = 0; i < k; i++)
        {
            ll x;
            cin >> x;
            r[x] += 1;
        }

        if (flag == false)
        {
            cout << "NO\n";
            continue;
        }

        stack<ll> st;
        map<ll, ll> mp;
        ll i = 0;
        while (i < n)
        {
            while (!st.empty() && st.top() < b[i])
            {
                mp[st.top()] += 1;
                st.pop();
            }

            if ((st.empty() || st.top() > b[i]) && a[i] > b[i])
                st.push(b[i]);

            i += 1;
        }
        while (!st.empty())
        {
            mp[st.top()] += 1;
            st.pop();
        }

        for (auto it : mp)
        {
            if (it.second > r[it.first])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}