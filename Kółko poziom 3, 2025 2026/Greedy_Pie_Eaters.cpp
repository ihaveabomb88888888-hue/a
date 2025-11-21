#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("pieaters.in", "r", stdin);
    freopen("pieaters.out", "w", stdout);
    int n, l, r, w, m;
    cin >> n >> m;
    vector<vector<vector<int>>> naj(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)), krowy(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        cin >> w >> l >> r;
        l--;
        r--;
        if (l == r) dp[l][r] = w;
        krowy[l][r] = w;
    }
    for (int dl = 1; dl < n; dl++) {
        for (int pocz = 0; pocz < n - dl; pocz++) {
            int kon = pocz + dl;
            naj[pocz][kon][pocz] = max(naj[pocz][kon - 1][pocz], krowy[pocz][kon]);
            naj[pocz][kon][kon] = max(naj[pocz + 1][kon][kon], krowy[pocz][kon]);
            for (int i = pocz + 1; i < kon; i++) {
                naj[pocz][kon][i] = max(naj[pocz][kon - 1][i], max(naj[pocz + 1][kon][i], krowy[pocz][kon]));
            }
        }
    }
    for (int dl = 1; dl < n; dl++) {
        for (int pocz = 0; pocz < n - dl; pocz++) {
            int kon = pocz + dl;
            dp[pocz][kon] = naj[pocz][kon][pocz] + dp[pocz + 1][kon];
            for (int i = pocz + 1; i <= kon; i++) {
                dp[pocz][kon] = max(dp[pocz][kon], dp[pocz][i - 1] + dp[i][kon]);
                dp[pocz][kon] = max(dp[pocz][kon], naj[pocz][kon][i] + dp[pocz][i - 1] + dp[i + 1][kon]);
            }
        }
    }
    cout << dp[0][n - 1];
}

