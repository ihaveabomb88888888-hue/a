#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int n;
vector<vector<pair<int, int>>> graf;
vector<int> grupa, wiel;
vector<int> arr;
int gr(int a) {
    if (grupa[a] == a) return a;
    int wynik = gr(grupa[a]);
    grupa[a] = wynik;
    return wynik;
}
void uni(int a, int b) {
    a = gr(a);
    b = gr(b);
    if (a == b) return;
    if (wiel[a] < wiel[b]) swap(a, b);
    grupa[b] = a;
    wiel[a] += wiel[b];
}
bool solve(int ile) {
    for (int i = 1; i <= n; i++) {
        grupa[i] = i;
        wiel[i] = 1;
    }
    for (int u = 1; u <= n; u++) {
        for (pair<int, int> p : graf[u]) {
            int v = p.fi, w = p.se;
            if (w >= ile) {
                uni(u, v);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (gr(i) != gr(arr[i])) return 0;
    return 1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    int m, s = 1, u, v, w;
    cin >> n >> m;
    graf.resize(n + 1);
    grupa.resize(n + 1);
    wiel.resize(n + 1);
    arr.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] != arr[i - 1] + 1) s = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graf[u].pb({v, w});
        graf[v].pb({u, w});
    }
    if (s == 1) {
        cout << -1;
        return 0;
    }

    int pocz = 0, kon = 1e9, sr;
    while (pocz < kon) {
        sr = (pocz + kon) / 2 + (pocz + kon) % 2;
        if (solve(sr)) pocz = sr;
        else kon = sr - 1;
    }
    cout << pocz;
}
