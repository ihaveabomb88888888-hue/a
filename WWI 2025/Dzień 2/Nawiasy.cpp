#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int wie, n;
int tree_size() {
    int wynik = 1;
    while (wynik < n) wynik *= 2;
    return wynik * 2;
}
void update(vector<ll>& tree, int index, ll value) {
    index += wie / 2;
    tree[index] = value;
    while (index > 1) {
        index /= 2;
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }
}
ll query(const vector<ll>& tree, int left, int right) {
    left += wie / 2;
    right += wie / 2;
    ll res = 1e18;
    while (left <= right) {
        if (left % 2 == 1) res = min(res, tree[left++]);
        if (right % 2 == 0) res = min(tree[right--], res);
        left /= 2;
        right /= 2;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    wie = tree_size();
    ll wynik = 0;
    vector<int> nawiasy(n);
    vector<ll> pre(n), tree(wie);
    for (int i = 0; i < n; i++) {
        cin >> nawiasy[i];
        if (i == 0) pre[i] = nawiasy[i];
        else if (i % 2 == 0) pre[i] = nawiasy[i] + pre[i - 1];
        else pre[i] = pre[i - 1] - nawiasy[i];
        update(tree, i, pre[i]);
    }
    for (int i = 0; i < n; i += 2) {
        for (int j = i + 1; j < n; j += 2) {
            ll mini = 1e18, zmiana = pre[i] - nawiasy[i], kon = nawiasy[j] - zmiana, conaj = 1;
            if (i + 1 <= j - 1) mini = query(tree, i + 1, j - 1);
            if (mini - pre[i] < 0) conaj = pre[i] - mini;
            if (conaj > nawiasy[i]) break;
            ll pocz1 = 0;
            ll kon1 = nawiasy[i] - conaj;
            ll pocz2 = pre[j] - zmiana;
            ll kon2 = pocz2 + nawiasy[j] - 1;
            if (pocz2 < pocz1) {
                swap(pocz1, pocz2);
                swap(kon1, kon2);
            }
            ll zero = 0;
            wynik += max(zero, min(kon1, kon2) - pocz2 + 1);
        }
    }
    cout << wynik << endl;
}

