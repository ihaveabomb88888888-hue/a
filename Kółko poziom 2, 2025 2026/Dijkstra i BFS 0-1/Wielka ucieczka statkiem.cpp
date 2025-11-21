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
    ll n, m, w1, w2, c;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graf1(n + 1), graf2(n + 1);
    for (ll i = 0; i < m; i++) {
        cin >> w1 >> w2 >> c;
        graf1[w1].push_back({w2, c});
        graf2[w2].push_back({w1, c});
    }

    // dijkstra z 1
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<pair<ll, ll>> dist1(n + 1, {1e18, -1});
    dist1[1] = {0, -1};
    pq.push({0, {1, -1}});

    while (!pq.empty()) {
        ll dl = pq.top().fi;
        ll wi = pq.top().se.fi;
        ll skad = pq.top().se.se;
        pq.pop();
        if (dl > dist1[wi].fi) continue;
        dist1[wi].fi = dl;
        dist1[wi].se = skad;
        for (pair<ll, ll> p : graf1[wi]) {
            ll waga = p.se;
            ll i = p.fi;
            if (dl + waga < dist1[i].fi) {
                dist1[i].fi = dl + waga;
                pq.push({dist1[i].fi, {i, wi}});
            }
        }
    }
    vector<ll> cokol(n + 1, -1);
    ll ak = n;
    cokol[n] = -2;
    while (ak != -1) {
        if (dist1[ak].se != -1) cokol[dist1[ak].se] = ak;
        ak = dist1[ak].se;
    }

    // dijkstra z n
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq2;
    vector<ll> distn(n + 1, 1e18);
    distn[n] = 0;
    pq2.push({0, n});

    while (!pq2.empty()) {
        ll dl = pq2.top().first;
        ll wi = pq2.top().second;
        pq2.pop();
        if (dl > distn[wi]) continue;
        distn[wi] = dl;
        for (pair<ll, ll> p : graf2[wi]) {
            ll waga = p.second;
            ll i = p.first;
            if (dl + waga < distn[i]) {
                distn[i] = dl + waga;
                pq2.push({distn[i], i});
            }
        }
    }

    // solve
    ll wyn = 1e18;
    for (ll i = 1; i <= n; i++) {
        if (cokol[i] == -1) wyn = min(wyn, dist1[i].fi + distn[i]);
        else {
            for (pair<ll, ll> p : graf1[i]) {
                ll v = p.fi, c = p.se;
                if (v != cokol[i]) {
                    wyn = min(wyn, dist1[i].fi + c + distn[v]);
                }
            }
        }
    }
    if (wyn == 1e18) cout << -1;
    else cout << wyn;
}

