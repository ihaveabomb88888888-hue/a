#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll n, wie;
vector<ll> treeprz, treewyn, zasiegl, zasiegp;
ll tree_size() {
    ll wynik = 1;
    while (wynik < n + 1) wynik *= 2;
    return wynik * 2;
}
void update(ll i, ll l, ll p, ll ile) {
    if (l > p) return;
    if (zasiegl[i] == l and zasiegp[i] == p) {
        treeprz[i] += ile;
        if (treeprz[i] > 0) treewyn[i] = p - l + 1;
        else if (i < wie / 2) treewyn[i] = treewyn[i * 2] + treewyn[i * 2 + 1];
        else treewyn[i] = 0;
    }
    else {
        if (l <= (zasiegl[i] + zasiegp[i]) / 2) update(i * 2, l, min(p, zasiegp[i * 2]), ile);
        if (p > (zasiegl[i] + zasiegp[i]) / 2) update(i * 2 + 1, max(zasiegl[i * 2 + 1], l), p, ile);
        if (treeprz[i] > 0) treewyn[i] = zasiegp[i] - zasiegl[i] + 1;
        else if (i < wie / 2) treewyn[i] = treewyn[i * 2] + treewyn[i * 2 + 1];
        else treewyn[i] = 0;
    }

}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q, a, b;
    cin >> n >> q;
    wie = tree_size();
    treeprz.resize(wie);

    treewyn.resize(wie);

    zasiegl.resize(wie);
    zasiegp.resize(wie);
    for (ll i = wie - 1; i > 0; i--) {
        if (i >= wie / 2) {
            zasiegl[i] = i - wie / 2;
            zasiegp[i] = i - wie / 2;
        }
        else {
            zasiegl[i] = zasiegl[i * 2];
            zasiegp[i] = zasiegp[i * 2 + 1];
        }
        treeprz[i] = 0;

        treewyn[i] = 0;
    }
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        update(1, i, arr[i] - 2, 1);
    }
    cout << n - treewyn[1] << endl;
    q--;
    while (q--) {
        cin >> a >> b;
        a--;
        b--;
        if (a > b) swap(a, b);
        update(1, a, arr[a] - 2, -1);
        update(1, b, arr[b] - 2, -1);
        update(1, b, arr[a] - 2, 1);
        update(1, a, arr[b] - 2, 1);
        cout << n - treewyn[1] << endl;
        swap(arr[a], arr[b]);
    }
}

