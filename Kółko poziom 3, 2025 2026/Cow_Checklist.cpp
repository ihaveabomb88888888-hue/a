#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll odl(pair<int, int> a, pair<int, int> b) {
    return (a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int ilekusi, ilewitkow;
    cin >> ilekusi >> ilewitkow;
    vector<pair<int, int>> kusie(ilekusi + 1), witki(ilewitkow + 1);
    for (int i = 1; i <= ilekusi; i++) cin >> kusie[i].fi >> kusie[i].se;
    for (int i = 1; i <= ilewitkow; i++) cin >> witki[i].fi >> witki[i].se;
    vector<vector<vector<ll>>> dp(ilekusi + 1, vector<vector<ll>>(ilewitkow + 1, vector<ll>(2, 1e9)));
    dp[1][0][0] = 0;
    dp[1][1][1] = odl(kusie[1], witki[1]);
    for (int i = 2; i <= ilewitkow; i++) {
        dp[1][i][1] = dp[1][i - 1][1] + odl(witki[i], witki[i - 1]);
    }
    for (int i = 2; i <= ilekusi; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + odl(kusie[i], kusie[i - 1]);
    }
    for (int i = 2; i <= ilekusi; i++) {
        for (int j = 1; j <= ilewitkow; j++) {
            dp[i][j][0] = min(dp[i - 1][j][1] + odl(witki[j], kusie[i]), dp[i - 1][j][0] + odl(kusie[i - 1], kusie[i]));
            dp[i][j][1] = min(dp[i][j - 1][1] + odl(witki[j], witki[j - 1]), dp[i][j - 1][0] + odl(witki[j], kusie[i]));
        }
    }
    cout << dp[ilekusi][ilewitkow][0];
}
