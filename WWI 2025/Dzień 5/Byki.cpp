#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int maxn = 100001;
int li = 0;
vector<ll> ojc(maxn + 1), gl(maxn + 1, -1), od(maxn + 1, -1), pre(maxn + 1), co(maxn + 1);
vector<vector<ll>> dzie(maxn + 1), skoki(19, vector<ll>(maxn + 1, 0)), graf(maxn + 1);
void dfs(int w) {
    pre[w] = li;
    co[li] = w;
    li++;
    for (int i : dzie[w]) {
        dfs(i);
    }
}
ll lca(ll a, ll b) {
    if (gl[a] < gl[b]) {
        swap(a, b);
    }
    ll ile = gl[a] - gl[b];
    for (int i = 18; i >= 0; i--) {
        ll pot = 1 << i;
        if (pot <= ile) {
            ile -= pot;
            a = skoki[i][a];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 18; i >= 0; i--) {
        if (skoki[i][a] != skoki[i][b]) {
            a = skoki[i][a];
            b = skoki[i][b];
        }
    }
    return skoki[0][a];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll w1, w2, q, a, b, ile, pot, c, n;
    cin >> n;
    unordered_map<ll, ll> odl;
    for (int i = 0; i < n - 1; i++) {
        cin >> w1 >> w2 >> c;
        graf[w1].push_back(w2);
        graf[w2].push_back(w1);
        odl[min(w1, w2) * 500001 + max(w1, w2)] = c;
    }
    ll li = 1;
    vector<ll> wa = {1}, nwa;
    gl[1] = 0;
    od[1] = 0;
    while (wa.size() > 0) {
        for (ll i : wa) {
            for (ll j : graf[i]) {
                if (gl[j] == -1) {
                    gl[j] = li;
                    od[j] = od[i] + odl[min(i, j) * 500001 + max(i, j)];
                    nwa.push_back(j);
                    ojc[j] = i;
                    dzie[i].push_back(j);
                    skoki[0][j] = i;
                }
            }
        }
        wa = nwa;
        nwa = {};
        li++;
    }
    for (int i = 1; i < 19; i++) {
        for (int j = 1; j <= n; j++) {
            skoki[i][j] = skoki[i - 1][skoki[i - 1][j]];
        }
    }
    dfs(1);
    // ------------------------------------------------------- //
    int z;
    ll wynik = 0;
    cin >> z;
    set<int> miasta;
    set<int> miasta_uj;
    while (z--) {
        cin >> a;
        int wyw = 0;
        if (miasta.find(pre[a]) != miasta.end()) {
            miasta.erase(pre[a]);
            miasta_uj.erase(-pre[a]);
            wyw = 1;
            if (miasta.size() == 0) {
                cout << 0 << endl;
                continue;
            }
        }
        if (miasta.size() == 0) {
            miasta.insert(pre[a]);
            miasta_uj.insert(-pre[a]);
            cout << 0 << endl;
            continue;
        }
        int przed = -1, po = -1;
        ll koszt = 0;
        if (miasta.upper_bound(pre[a]) != miasta.end()) {
            po = co[*(miasta.upper_bound(pre[a]))];
        }
        if (miasta_uj.upper_bound(-pre[a]) != miasta_uj.end()) {
            przed = co[-(*(miasta_uj.upper_bound(-pre[a])))];
        }
        int ak = lca(co[(*miasta.begin())], co[(*miasta.rbegin())]);
        //cout << ak << " " << przed << " " << po << endl;
        if (lca(ak, a) != ak) koszt = od[a] + od[ak] - 2 * od[lca(ak, a)];
        else if (lca(ak, a) == a) koszt = od[ak] - od[a];
        else if (po == -1 or lca(po, a) != a) {
            if (po == -1 and przed == -1) po = -1;
            else if (po == -1) koszt = od[a] - od[lca(przed, a)];
            else if (przed == -1) koszt = od[a] - od[lca(po, a)];
            else koszt = min(od[a] - od[lca(po, a)], od[a] - od[lca(przed, a)]);
        }
        //cout << wyw << " " << koszt << endl;
        if (wyw == 0) {
            miasta.insert(pre[a]);
            miasta_uj.insert(-pre[a]);
            wynik += koszt;
            cout << wynik << endl;
        }
        else {
            wynik -= koszt;
            cout << wynik << endl;
        }
    }
}
