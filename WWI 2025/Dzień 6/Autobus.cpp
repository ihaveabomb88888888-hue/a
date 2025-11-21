#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    set<ll> aut;
    vector<ll> bilety(n + 1), pre(k + 1), dp(1 << n, 0);
    dp[0] = 0;
    aut.insert(0);
    aut.insert(1e18);
    for (int i = 1; i <= n; i++) {
        cin >> bilety[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
        aut.insert(pre[i]);
    }
    for (int i = 1; i < (1 << n); i++) {
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) {
                //cout << "patrzymy na dp " << (i ^ (1 << bit)) << " aby zmaksymalizowac " << i << " bit to " << bit << " bilet " << bilety[bit + 1] << " " << dp[i ^ (1 << bit)] << endl;
                auto it = aut.upper_bound(bilety[bit + 1] + dp[i ^ (1 << bit)]);
                if (it != aut.end() and it != aut.begin()) {
                    it--;
                    //cout << "potecjalny wynik to " << *it << endl;
                    dp[i] = max(dp[i], *it);
                }
            }
        }
    }
    ll wynik = -1, pot;
    for (int i = 0; i < (1 << n); i++) {
        if (dp[i] == pre[k]) {
            pot = 0;
            for (int bit = 0; bit < n; bit++) {
                if (!(i & (1 << bit))) {
                    pot += bilety[bit + 1];
                }
            }
            wynik = max(wynik, pot);
        }
    }
    if (wynik != -1) cout << wynik;
    else cout << "spacer, odpoczynek, dobry sen, swieza glowa" << endl;
}
