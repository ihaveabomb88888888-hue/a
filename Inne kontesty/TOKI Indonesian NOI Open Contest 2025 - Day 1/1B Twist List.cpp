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
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> stare(1, vector<ll>(n));
    for (int i = 0; i < n; i++) cin >> stare[0][i];
    vector<vector<ll>> nowel, nowep;
    vector<ll> v, lp;
    while (k--) {
        for (int i = 0; i < stare.size(); i++) {
            v.clear();
            for (int j = 0; j < n; j++) {
                v.pb(stare[i][j]);
                v.pb(stare[i][j]);
            }
            lp.clear();
            for (int j = 0; j < n; j++) {
                lp.pb(v[j]);
            }
            nowel.pb(lp);
            lp.clear();
            for (int j = n; j < 2 * n; j++) {
                lp.pb(v[j]);
            }
            nowep.pb(lp);
        }
        ll w = 0;
        while (w < nowep.size() and nowel.size() < 200000) {
            nowel.pb(nowep[w]);
            w++;
        }
        nowep = {};
        swap(nowel, stare);
        nowel = {};
    }
    ll s;
    for (int i = 0; i < stare.size(); i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            s += stare[i][j];
        }
        cout << s << endl;
    }
}

