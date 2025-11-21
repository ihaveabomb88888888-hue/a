#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define fi first
#define se second
#define pb push_back
const int maxn = 500001; // 1e5 * 5 + 1

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, w1, w2, c;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> graf(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> w1 >> w2 >> c;
        graf[w1].push_back({w2, c});
    }
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    vector<pair<ll, ll>> dist(n + 1, {1e18, -1});
    dist[1] = {0, -1};
    pq.push({0, {1, -1}});

    while (!pq.empty()) {
        ll dl = pq.top().fi;
        ll wi = pq.top().se.fi;
        ll skad = pq.top().se.se;
        pq.pop();
        if (dl > dist[wi].fi) continue;
        dist[wi].fi = dl;
        dist[wi].se = skad;
        for (pair<ll, ll> p : graf[wi]) {
            ll waga = p.se;
            ll i = p.fi;
            if (dl + waga < dist[i].fi) {
                dist[i].fi = dl + waga;
                pq.push({dist[i].fi, {i, wi}});
            }
        }
    }
    vector<ll> wyn;
    ll ak = n;
    while (ak != -1) {
        wyn.pb(ak);
        ak = dist[ak].se;
    }
    reverse(wyn.begin(), wyn.end());
    cout << dist[n].fi << " " << wyn.size() << endl;
    for (int i : wyn) cout << i << " ";

    return 0;
}
