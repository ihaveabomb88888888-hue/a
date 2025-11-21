#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
ll bin(vector<ll>& v, ll x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin();
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, u, kt = 0, l, r, v, p;
    cin >> n >> m >> u;
    ll pier = sqrt(n);
    vector<ll> arr(n), doktr(n);
    vector<vector<ll>> prze(n / pier + 2);
    vector<pair<ll, ll>> zas(n / pier + 2);
    zas[0].fi = 0;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        if (i % pier == 0 and i != 0) {
            zas[kt].se = i - 1;
            kt++;
            zas[kt].fi = i;
        }
        prze[kt].pb(arr[i]);
        doktr[i] = kt;
    }
    zas[kt].se = n - 1;
    for (ll i = 0; i < prze.size(); i++) sort(prze[i].begin(), prze[i].end());

    while (m--) {
        cin >> l >> r >> v >> p;
        l--;
        r--;
        p--;
        ll lprz = doktr[l], pprz = doktr[r], k = 0;
        if (lprz == pprz) {
            for (ll i = l; i <= r; i++) if (arr[i] < v) k++;
        }
        else {
            ll lz = zas[lprz].se;
            ll pz = zas[pprz].fi;
            for (ll i = l; i <= lz; i++) if (arr[i] < v) k++;
            for (ll i = pz; i <= r; i++) if (arr[i] < v) k++;
            for (ll i = lprz + 1; i < pprz; i++) k += bin(prze[i], v);
        }

        ll prz = doktr[p];
        arr[p] = u * k / (r - l + 1);
        ll lp = zas[prz].fi, pp = zas[prz].se;
        prze[prz].clear();
        for (ll i = lp; i <= pp; i++) {
            prze[prz].pb(arr[i]);
        }
        sort(prze[prz].begin(), prze[prz].end());
    }
    for (ll i : arr) cout << i << endl;
}
