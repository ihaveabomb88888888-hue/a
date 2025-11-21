#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    int n, m, k, c;
    string s;
    cin >> n >> m >> k;
    cin >> s;

    // dist
    vector<vector<ll>> dist(m + 1, vector<ll>(m + 1, 1e18));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            dist[i][j] = c;
        }
    }
    for (int i = 0; i < m; i++) {
        dist[i][i] = 0;
    }
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // solve
    vector<ll> dp(n + 1, 1e18);
    vector<vector<ll>> calosc(n + 1, vector<ll>(m, 0)), wynik(n + 1, vector<ll>(m, 0));
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            calosc[i][j] = calosc[i - 1][j] + dist[s[i - 1] - 'a'][j];

            if (i - k >= 0) {
                dp[i] = min(dp[i], calosc[i][j] + wynik[i - k][j]);
            }
        }
        for (int j = 0; j < m; j++) {
            if (i - k >= 0) {
                wynik[i][j] = min(wynik[i - 1][j], dp[i] - calosc[i][j]);
            }
        }
    }
    cout << dp[n];
}
