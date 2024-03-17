#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)

vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<pair<ll, ll>> B_pos;
ll n, m, num_G;

void dfs(ll x, ll y)
{
    visited[x][y] = true;
    if (grid[x][y] == 'G')
        num_G--;

    // top
    if ((x != 0) && (!visited[x - 1][y]) && (grid[x - 1][y] != '#'))
    {
        dfs(x-1, y);
    }

    // bottom
    if ((x != n - 1) && (!visited[x + 1][y]) && (grid[x + 1][y] != '#'))
    {
        dfs(x+1, y);
    }

    // left
    if ((y != 0) && (!visited[x][y - 1]) && (grid[x][y - 1] != '#'))
    {
        dfs(x, y-1);
    }

    // right
    if ((y != m - 1) && (!visited[x][y + 1]) && (grid[x][y + 1] != '#'))
    {
        dfs(x, y+1);
    }
}

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
        cin >> n >> m;

        grid.clear();
        visited.clear();
        B_pos.clear();

        grid.resize(n, vector<char>(m));
        visited.assign(n, vector<bool>(m, false));
        num_G = 0;

        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if (grid[i][j] == 'B')
                    B_pos.push_back({i, j});
                else if (grid[i][j] == 'G')
                    num_G++;
            }
        }

        // Fortify Bs
        for (auto xy : B_pos)
        {
            ll x = xy.first;
            ll y = xy.second;

            // cout<<x<<" "<<y<<endl;

            // top
            if (x != 0)
                grid[x - 1][y] = '#';

            // bottom
            if (x != n - 1)
                grid[x + 1][y] = '#';

            // left
            if (y != 0)
                grid[x][y - 1] = '#';

            // right
            if (y != m - 1)
                grid[x][y + 1] = '#';
        }

        // for(ll i=0; i<n; i++){
        //     for(ll j=0; j<m; j++){
        //         cout<<grid[i][j]<<" ";
        //     }cout<<endl;
        // }

        // Traverse all possible paths from (n-1, m-1), and subtract from 'num_G' if G is encountered;
        if (grid[n-1][m-1] != '#') dfs(n - 1, m - 1);

        if (num_G == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}