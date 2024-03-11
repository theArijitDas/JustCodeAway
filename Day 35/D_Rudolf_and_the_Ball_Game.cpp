#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> players(n + 1, 0);
        players[x] = 1;

        for (int i = 0; i < m; ++i) {
            int r;
            char c;
            cin >> r >> c;

            vector<int> new_players(n + 1, 0);

            for (int j = 1; j <= n; ++j) {
                if (players[j] == 1) {
                    int dest_clockwise = (j + r - 1) % n + 1;
                    int dest_counterclockwise = (j - r + n - 1) % n + 1;

                    if (c == '0' || c == '?') {
                        new_players[dest_clockwise] = 1;
                    }
                    if (c == '1' || c == '?') {
                        new_players[dest_counterclockwise] = 1;
                    }
                }
            }

            players = new_players;
        }

        vector<int> possible_players;
        for (int i = 1; i <= n; ++i) {
            if (players[i] == 1) {
                possible_players.push_back(i);
            }
        }

        cout << possible_players.size() << endl;
        for (int player : possible_players) {
            cout << player << " ";
        }
        cout << endl;
    }

    return 0;
}