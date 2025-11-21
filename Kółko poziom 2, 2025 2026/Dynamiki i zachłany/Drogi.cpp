#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define fi first
#define se second
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    cin >> x;
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1 + (i == 1); j <= n; j++) {
            cin >> x;
            if (!x) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 1000000;
        }
    }
    cout << dp[n][n];
}

