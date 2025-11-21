#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int wie, n, duzo = 1e9;
const int mod = 998244353;
vector<ll> lazymn, lazydo, tree, zasiegl, zasiegp;

ll tree_size() {
    ll wynik = 1;
    while (wynik < n + 1) wynik *= 2;
    return wynik * 2;
}
void push(ll i) {
    if (i >= wie) return;
    ll b = lazymn[i];
    ll c = lazydo[i];
    tree[i] *= b % mod;
    tree[i] %= mod;
    tree[i] += c * (zasiegp[i + 1] - zasiegl[i + 1] + 1) % mod;
    tree[i] %= mod;
    if (i < wie / 2) {
        lazymn[i * 2] *= b;
        lazymn[i * 2] %= mod;
        lazydo[i * 2] *= b;
        lazydo[i * 2] %= mod;
        lazydo[i * 2] += c;
        lazydo[i * 2] %= mod;

        lazymn[i * 2 + 1] *= b;
        lazymn[i * 2 + 1] %= mod;
        lazydo[i * 2 + 1] *= b;
        lazydo[i * 2 + 1] %= mod;
        lazydo[i * 2 + 1] += c;
        lazydo[i * 2 + 1] %= mod;
    }
    lazymn[i] = 1;
    lazydo[i] = 0;
}
void update(ll i, ll l, ll p, ll b, ll c) {
    push(i);
    if (zasiegl[i] == l and zasiegp[i] == p) {
        tree[i] *= b % mod;
        tree[i] %= mod;
        tree[i] += c * (zasiegp[i + 1] - zasiegl[i + 1] + 1) % mod;
        tree[i] %= mod;
        if (i < wie / 2) {
            lazymn[i * 2] *= b;
            lazymn[i * 2] %= mod;
            lazydo[i * 2] *= b;
            lazydo[i * 2] %= mod;
            lazydo[i * 2] += c;
            lazydo[i * 2] %= mod;

            lazymn[i * 2 + 1] *= b;
            lazymn[i * 2 + 1] %= mod;
            lazydo[i * 2 + 1] *= b;
            lazydo[i * 2 + 1] %= mod;
            lazydo[i * 2 + 1] += c;
            lazydo[i * 2 + 1] %= mod;
        }
    }
    else {
        if (l <= (zasiegl[i] + zasiegp[i]) / 2) {
            update(i * 2, l, min(p, zasiegp[i * 2]), b, c);
        }
        if (p > (zasiegl[i] + zasiegp[i]) / 2) {
            update(i * 2 + 1, max(zasiegl[i * 2 + 1], l), p, b, c);
        }
        push(i * 2);
        push(i * 2 + 1);
        tree[i] = tree[i * 2 + 1] + tree[i * 2];
    }
}
ll query(ll i, ll l, ll p) {
    push(i);
    if (zasiegl[i] == l and zasiegp[i] == p) {
        return tree[i];
    }
    else {
        ll wyn = 0;
        if (l <= (zasiegl[i] + zasiegp[i]) / 2) {
            wyn += query(i * 2, l, min(p, zasiegp[i * 2]));
            wyn %= mod;
        }
        if (p > (zasiegl[i] + zasiegp[i]) / 2) {
            wyn += query(i * 2 + 1, max(zasiegl[i * 2 + 1], l), p);
            wyn %= mod;
        }
        return wyn % mod;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q, a;
    cin >> n >> q;
    // przygotowanie drzewa
    wie = tree_size();
    tree.resize(wie);
    lazymn.resize(wie);
    lazydo.resize(wie);
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
        lazydo[i] = 0;
        lazymn[i] = 1;
        tree[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        cin >> a;
        update(1, i, i, 0, a);
    }
    int co, l, r, b, c;
    while (q--) {
        cin >> co >> l >> r;
        r--;
        if (co == 1) {
            cout << query(1, l, r) << endl;
        }
        else {
            cin >> b >> c;
            update(1, l, r, b, c);
        }
    }
}

