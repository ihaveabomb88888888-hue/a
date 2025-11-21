#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll n, m;
vector<vector<ll>> graf;
vector<ll> wys, vis;
void dfs(ll w, ll il) {
    if (wys[w] > il or vis[w] == 1) return;
    vis[w] = 1;
    for (ll i : graf[w]) dfs(i, il);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ll a, b;
    graf.resize(n + 1);
    vis.resize(n + 1);
    wys.resize(n + 1);
    for (ll i = 1; i <= n; i++) cin >> wys[i];
    for (ll i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    ll pocz = 0, kon = 1e12, sr;
    while (pocz < kon) {
        sr = (pocz + kon) / 2;
        for (ll i = 1; i <= n; i++) vis[i] = 0;
        dfs(1, sr);
        if (vis[n]) {
            kon = sr;
        }
        else {
            pocz = sr + 1;
        }
    }
    cout << pocz << endl;
}
