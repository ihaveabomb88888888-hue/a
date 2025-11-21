#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
const ll mod = 1000000007;
ll solve(vector<ll>& ile) {
    ll n = ile.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(21, 0));
    for (ll i = 0; i <= ile[0]; i++) dp[0][i] = 1;
    ll wyn = 0;
    for (ll i = 1; i <= n; i++) {
        ll pre = 0;
        for (ll j = 0; j < ile[i - 1]; j++) {
            pre += dp[i - 1][j];
            pre %= mod;
            dp[i][j] = dp[i - 1][ile[i - 1]];
        }
        dp[i][ile[i - 1]] += pre + dp[i - 1][ile[i - 1]];
        dp[i][ile[i - 1]] %= mod;
    }
    for (ll i = 0; i <= 20; i++) {
        wyn += dp[n][i];
        wyn %= mod;
    }
    return wyn;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, a;
    cin >> n;
    vector<ll> p(1e6 + 1, 1);
    p[0] = p[1] = 1;
    for (ll i = 2; i <= 1e6; i++) {
        if (p[i] == 1) {
            for (ll j = i * i; j <= 1e6; j += i) {
                if (p[j] == 1) p[j] = i;
            }
        }
    }
    unordered_map<ll, vector<pair<ll, ll>>> prz;
    unordered_map<ll, ll> rozklad;
    for (ll i = 0; i < n; i++) {
        cin >> a;
        rozklad.clear();
        while (p[a] > 1) {
            rozklad[p[a]]++;
            a /= p[a];
        }
        if(a > 1) rozklad[a]++;
        for (auto it : rozklad) {
            prz[it.fi].pb({i, it.se});
        }
    }
    vector<pair<ll, ll>> v1;
    vector<ll> v2;
    ll wyn = 1;
    for (auto it : prz) {
        v1 = it.se;
        v2 = {v1[0].se};
        ll pocz = v1[0].fi;
        for (ll i = 1; i < v1.size(); i++) {
            if (v1[i - 1].fi + 1 != v1[i].fi) {
                //cout << "przedzial " << it.fi << " --> " << pocz << " " << v1[i - 1].fi << endl;
                if (pocz != 0) {
                    reverse(v2.begin(), v2.end());
                    v2.pb(0);
                    reverse(v2.begin(), v2.end());
                }
                v2.pb(0);
                wyn *= solve(v2);
                wyn %= mod;
                v2 = {v1[i].se};
                pocz = v1[i].fi;
            }
            else {
                v2.pb(v1[i].se);
            }
        }
        //cout << "przedzial " << it.fi << " --> " << pocz << " " << v1[v1.size() - 1].fi << endl;
        if (pocz != 0) {
            reverse(v2.begin(), v2.end());
            v2.pb(0);
            reverse(v2.begin(), v2.end());
        }
        if (v1[v1.size() - 1].fi != n - 1) v2.pb(0);
        /*for (ll i = 0; i < v2.size(); i++) {
            cout << v2[i] << " ";
        }
        cout << endl;
        cout << solve(v2) << endl;*/
        wyn *= solve(v2);
        wyn %= mod;
        v2.clear();
    }
    cout << wyn << endl;
}

