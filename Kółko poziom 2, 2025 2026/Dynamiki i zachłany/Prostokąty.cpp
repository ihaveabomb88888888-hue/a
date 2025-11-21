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
    ll n, d, s;
    cin >> n;
    vector<pair<ll, ll>> wymiar(n), dp(n);
    for (ll i = 0; i < n; i++) cin >> wymiar[i].fi >> wymiar[i].se;
    dp[0].fi = wymiar[0].fi + wymiar[0].se;
    dp[0].se = wymiar[0].fi + wymiar[0].se;
    for (ll i = 1; i < n; i++) {
        dp[i].fi = max(dp[i - 1].fi + abs(wymiar[i - 1].fi - wymiar[i].fi), dp[i - 1].se + abs(wymiar[i - 1].se - wymiar[i].fi)) + wymiar[i].se;
        dp[i].se = max(dp[i - 1].fi + abs(wymiar[i - 1].fi - wymiar[i].se), dp[i - 1].se + abs(wymiar[i - 1].se - wymiar[i].se)) + wymiar[i].fi;
    }
    cout << max(dp[n - 1].fi + wymiar[n - 1].fi, dp[n - 1].se + wymiar[n - 1].se);
}

