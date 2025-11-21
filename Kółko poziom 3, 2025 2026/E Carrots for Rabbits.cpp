#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll wyn = 0;
ll policz(ll war, ll cie) {
    ll reszta = war % cie, dl = war / cie;
    return reszta * (2 * dl + 1) + dl * dl * cie;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    priority_queue<pair<pair<ll, ll>, ll>> pq;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push({{policz(arr[i], 1) - policz(arr[i], 2), 1}, arr[i]});
    }
    ll c = k - n;
    pair<pair<ll, ll>, ll> p;
    while (c--) {
        p = pq.top();
        pq.pop();
        ll zysk = p.fi.fi, cie = p.fi.se, war = p.se;
        cie++;
        pq.push({{policz(war, cie) - policz(war, cie + 1), cie}, war});
        //cout << "ruch " << dl << " " << war << " " << cie << endl;
    }
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        wyn += policz(p.se, p.fi.se);
    }
    cout << wyn;
}


