#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
int n;
vector<vector<int>> graf;
vector<int> najdl(unordered_set<int>& usun) {
    vector<int> dp(n + 1, 1), skad(n + 1, -1);
    int mw = -1, m = 0;
    for (int i = 1; i <= n; i++) {
        if (usun.find(i) != usun.end()) continue;
        for (int w : graf[i]) {
            if (usun.find(w) != usun.end()) continue;
            if (dp[i] < dp[w] + 1) {
                dp[i] = dp[w] + 1;
                skad[i] = w;
            }
        }
        if (dp[i] > m) {
            m = dp[i];
            mw = i;
        }
    }
    vector<int> wyn;
    int ak = mw;
    while (ak != -1) {
        wyn.pb(ak);
        ak = skad[ak];
    }
    reverse(wyn.begin(), wyn.end());
    return wyn;
}
int solve(int k, unordered_set<int> usun) {
    vector<int> naj = najdl(usun);
    int wynik = naj.size();
    if (k == 0) return wynik;
    for (int i : naj) {
        usun.insert(i);
        wynik = min(wynik, solve(k - 1, usun));
        usun.erase(i);
    }
    return wynik;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, k, x, y;
    cin >> n >> m >> k;
    graf.resize(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graf[y].pb(x);
    }
    cout << solve(k, {});
}
