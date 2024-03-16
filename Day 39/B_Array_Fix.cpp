#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef long long ll;

class Solution {
public:
    void solve() {
        int t;
        cin >> t;
        while (t--) {
            ll n;
            cin >> n;
            vector<ll> a(n);
            for (ll i = 0; i < n; i++) cin >> a[i];
            bool possible = true;
            stack<ll> arr;
            arr.push(a[n - 1]);
            for (ll i = n - 2; i >= 0; i--) {
                if (a[i] <= arr.top()) {
                    arr.push(a[i]);
                    continue;
                }
                if (a[i] > 9) {
                    ll k = a[i];
                    ll cnt = 0;
                    while (cnt < 2) {
                        if (cnt == 0) {
                            ll b = k % 10;
                            arr.push(b);
                            k = k / 10;
                            cnt += 1;
                        }
                        if (cnt == 1) {
                            arr.push(k);
                            cnt += 1;
                        }
                    }
                } else {
                    arr.push(a[i]);
                }
            }
            ll prev = arr.top();
            arr.pop();
            while (!arr.empty()) {
                ll p = arr.top();
                arr.pop();
                if (prev > p) {
                    possible = false;
                    break;
                }
                prev = p;
            }
            if (possible) cout << "YES\n";
            else cout << "NO\n";
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution solution;
    solution.solve();

    return 0;
}
