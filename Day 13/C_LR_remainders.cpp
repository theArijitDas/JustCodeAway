#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

class Solution {
public:
    void solve() {
        ll t;
        cin >> t;
        while (t--) {
            ll n, m;
            cin >> n >> m;
            vll a(n);

            for (ll i = 0; i < n; i++) {
                cin >> a[i];
            }

            ll l = 0;
            ll r = n - 1;
            ll rem = 1;
            string commands;
            cin >> commands;

            for (ll i = 0; i < n - 1; i++) {
                if (commands[i] == 'L')
                    l++;
                else
                    r--;
            }
            vll ans;
            ll curr = a[r];
            for (ll i = n - 2; i >= -1; i--) {
                curr = curr % m;
                ans.push_back(curr);
                if (commands[i] == 'L') {
                    l--;
                    curr = (curr * a[l] % m) % m;
                } else {
                    r++;
                    curr = (curr * a[r] % m) % m;
                }
            }

            reverse(ans.begin(), ans.end());
            for (auto it : ans)
                cout << it << " ";
            cout << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin.exceptions(ios::badbit | ios::failbit);

    Solution solution;
    solution.solve();

    return 0;
}
