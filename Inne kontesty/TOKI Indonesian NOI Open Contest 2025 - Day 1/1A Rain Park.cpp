#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, w1, w2, c, z;
    cin >> n >> m;
    vector<vector<pair<pair<ll, ll>, ll>>> graf(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> w1 >> w2 >> c >> z;
        graf[w1].pb({{w2, c}, z});
        graf[w2].pb({{w1, c}, z});
    }
    ll t;
    cin >> t;
    vector<pair<ll, ll>> prognozy(t);
    for (int i = 0; i < t; i++) {
        cin >> c;
        prognozy[i] = {c, i};
    }
    sort(prognozy.begin(), prognozy.end());
    // dijkstra od n - jak szybko z i do n kiedy pada
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> distn(n + 1, 1e18);
    distn[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        ll dl = pq.top().fi, wi = pq.top().se;
        pq.pop();
        if (dl > distn[wi]) continue;
        distn[wi] = dl;
        for (pair<pair<ll, ll>, ll> p : graf[wi]) {
            ll waga = p.fi.se, i = p.fi.fi, z = p.se;
            if (z == 1) continue;
            if (dl + waga < distn[i]) {
                distn[i] = dl + waga;
                pq.push({distn[i], i});
            }
        }
    }
    // dijkstra od 1 - jak szybko z 1 do i bez padania
    vector<ll> dist1(n + 1, 1e18);
    dist1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll dl = pq.top().fi, wi = pq.top().se;
        pq.pop();
        if (dl > dist1[wi]) continue;
        dist1[wi] = dl;
        for (pair<pair<ll, ll>, ll> p : graf[wi]) {
            ll waga = p.fi.se, i = p.fi.fi, z = p.se;
            if (dl + waga < dist1[i]) {
                dist1[i] = dl + waga;
                pq.push({dist1[i], i});
            }
        }
    }
    vector<pair<ll, ll>> poten;
    for (int i = 0; i < n; i++) {
        if (distn[i + 1] != 1e18 and dist1[i + 1] != 1e18) {
            poten.pb({dist1[i + 1], distn[i + 1]});
        }
    }
    sort(poten.begin(), poten.end());
    vector<ll> wynik(t);
    ll wpr = 0, wpo = 0, mini = 1e18;
    while (wpr < prognozy.size()) {
        while (wpo < poten.size() and poten[wpo].fi <= prognozy[wpr].fi) {
            mini = min(mini, poten[wpo].fi + poten[wpo].se);
            wpo++;
        }
        if (mini == 1e18) wynik[prognozy[wpr].se] = -1;
        else wynik[prognozy[wpr].se] = mini;
        wpr++;
    }
    for (int i = 0; i < t; i++) {
        cout << wynik[i] << endl;
    }
    return 0;
}
