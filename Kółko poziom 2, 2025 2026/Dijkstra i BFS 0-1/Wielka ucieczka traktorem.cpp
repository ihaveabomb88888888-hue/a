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
    vector<vector<pair<ll, ll>>> graf(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> w1 >> w2 >> c;
        graf[w1].push_back({w2, c});
        graf[w2].push_back({w1, c});
    }
    // dijkstra z 1
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist1(n + 1, 1e18);
    dist1[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll dl = pq.top().first;
        ll wi = pq.top().second;
        pq.pop();
        if (dl > dist1[wi]) continue;
        dist1[wi] = dl;
        for (pair<ll, ll> p : graf[wi]) {
            ll waga = p.second;
            ll i = p.first;
            if (dl + waga < dist1[i]) {
                dist1[i] = dl + waga;
                pq.push({dist1[i], i});
            }
        }
    }
    // dijkstra z n
    vector<ll> distn(n + 1, 1e18);
    distn[n] = 0;
    pq.push({0, n});

    while (!pq.empty()) {
        ll dl = pq.top().first;
        ll wi = pq.top().second;
        pq.pop();
        if (dl > distn[wi]) continue;
        distn[wi] = dl;
        for (pair<ll, ll> p : graf[wi]) {
            ll waga = p.second;
            ll i = p.first;
            if (dl + waga < distn[i]) {
                distn[i] = dl + waga;
                pq.push({distn[i], i});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist1[i] + distn[i] == dist1[n]) cout << i << endl;
    }
}

