#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int wie, n, duzo = 1e9;
vector<int> forty;
vector<vector<int>> grid, odl;
vector<ll> lazy, tree, zasiegl, zasiegp;

// drzewo przedzial-przedzial
ll tree_size() {
    ll wynik = 1;
    while (wynik < n * n + 5) wynik *= 2;
    return wynik * 2;
}
void push(ll i) {
    if (i >= wie) return;
    tree[i] += lazy[i];
    if (i < wie / 2) {
        lazy[i * 2] += lazy[i];
        lazy[i * 2 + 1] += lazy[i];
    }
    lazy[i] = 0;
}
void update(ll i, ll l, ll p, ll war) {
    push(i);
    if (zasiegl[i] == l and zasiegp[i] == p) {
        tree[i] += war;
        if (i < wie / 2) {
            lazy[i * 2] += war;
            lazy[i * 2 + 1] += war;
        }
    }
    else {
        if (l <= (zasiegl[i] + zasiegp[i]) / 2) {
            update(i * 2, l, min(p, zasiegp[i * 2]), war);
        }
        if (p > (zasiegl[i] + zasiegp[i]) / 2) {
            update(i * 2 + 1, max(zasiegl[i * 2 + 1], l), p, war);
        }
        push(i * 2);
        push(i * 2 + 1);
        tree[i] = max(tree[i * 2 + 1], tree[i * 2]);
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
            wyn = max(query(i * 2, l, min(p, zasiegp[i * 2])), wyn);
        }
        if (p > (zasiegl[i] + zasiegp[i]) / 2) {
            wyn = max(query(i * 2 + 1, max(zasiegl[i * 2 + 1], l), p), wyn);
        }
        return wyn;
    }
}

// forty
void dodaj_fort(int x, int y) {
    grid[x][y] = 2;
    int dl = odl[x][y], fdl = forty[dl] + dl;
    if (dl == fdl) update(1, dl, dl, dl - 1);
    update(1, 0, dl, 1);
    forty[dl]++;
}
void usun_fort(int x, int y) {
    grid[x][y] = 1;
    int dl = odl[x][y], fdl = forty[dl] + dl - 1;
    forty[dl]--;
    if (dl == fdl) update(1, dl, dl, -dl + 1);
    update(1, 0, dl, -1);
}
int odpowiedz() {
    return query(1, 0, n * n + 4);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // wczytywanie
    int x, y, z;
    cin >> n >> z;
    grid.resize(n + 2, vector<int>(n + 2, 0));
    odl.resize(n + 2, vector<int>(n + 2, 1e9));
    string s;
    vector<pair<int, int>> f;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] != '#') grid[i][j] = 1;
            if (s[j - 1] == 'F') {
                f.pb({i, j});
                grid[i][j] = 2;
            }
        }
    }

    // bfs
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {1, 1}});
    while (!q.empty()) {
        int dl = q.front().fi, i = q.front().se.fi, j = q.front().se.se;
        q.pop();
        if (odl[i][j] != 1e9) continue;
        odl[i][j] = dl;
        if (grid[i - 1][j] != 0) q.push({dl + 1, {i - 1, j}});
        if (grid[i][j - 1] != 0) q.push({dl + 1, {i, j - 1}});
        if (grid[i + 1][j] != 0) q.push({dl + 1, {i + 1, j}});
        if (grid[i][j + 1] != 0) q.push({dl + 1, {i, j + 1}});
    }

    // przygotowanie drzewa
    wie = tree_size();
    tree.resize(wie);
    lazy.resize(wie);
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
        lazy[i] = 0;
        tree[i] = 0;
    }

    // forty z wejœcia
    forty.resize(n * n + 1, 0);
    for (pair<int, int> p : f) dodaj_fort(p.fi, p.se);
    cout << odpowiedz() << endl;

    // slove
    while (z--) {
        cin >> x >> y;
        if (grid[x][y] == 1) dodaj_fort(x, y);
        else usun_fort(x, y);
        cout << odpowiedz() << endl;
    }
}

