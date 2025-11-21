#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
ll n;
vector<vector<pair<ll, ll>>> dzie;
vector<pair<ll, ll>> ojc;
vector<ll> wie, liscie, wyndol, wyn;
void dfs_wstepny(ll w) {
    if (dzie[w].size() == 0) liscie[w] = 1;
    for (pair<ll, ll> p : dzie[w]) {
        dfs_wstepny(p.fi);
        liscie[w] += liscie[p.fi];
        wyndol[w] += wyndol[p.fi] + p.se * liscie[p.fi];
    }
}
void dfs(ll w) {
    if (w != 1) wyn[w] = wyndol[w] + (wyn[ojc[w].fi] - liscie[w] * ojc[w].se - wyndol[w]) + (liscie[1] - liscie[w]) * 3;
    for (pair<ll, ll> p : dzie[w]) {
        dfs(p.fi);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    ll m, w;
    cin >> n;
    string s;
    ojc.resize(n + 1);
    dzie.resize(n + 1);
    wie.resize(n + 1);
    liscie.resize(n + 1);
    wyndol.resize(n + 1);
    wyn.resize(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> s >> m;
        wie[i] = s.size() + 1;
        for (ll j = 0; j < m; j++) {
            cin >> w;
            dzie[i].pb({w, -1});
            ojc[w] = {i, -1};
        }
        liscie[i] = 0;
        wyndol[i] = 0;
    }
    ojc[1] = {0, -1};
    for (ll i = 1; i <= n; i++) {
        ojc[i].se = wie[i];
        for (ll j = 0; j < dzie[i].size(); j++) {
            dzie[i][j].se = wie[dzie[i][j].fi];
        }
    }
    dfs_wstepny(1);
    wyn[1] = wyndol[1];
    dfs(1);
    w = wyn[1];
    for (ll i = 1; i <= n; i++) w = min(w, wyn[i]);
    cout << w - liscie[1];
}

