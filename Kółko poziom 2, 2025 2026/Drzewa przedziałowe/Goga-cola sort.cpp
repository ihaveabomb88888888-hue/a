#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define pb push_back
#define fi first
#define se second
ll n, wie;
vector<ll> tree;
ll tree_size() {
    ll wynik = 1;
    while (wynik < n) wynik *= 2;
    return wynik * 2;
}
void update(ll ind, ll val) {
    ind += wie / 2;
    tree[ind] += val;
    ind /= 2;
    while (ind > 0) {
        tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
        ind /= 2;
    }
}
ll query(ll left, ll right) {
    left += wie / 2;
    right += wie / 2;
    ll res = 0;
    while (left <= right) {
        if (right % 2 == 0) res += tree[right--];
        if (left % 2 == 1) res += tree[left++];
        left /= 2;
        right /= 2;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string co;
    ll q, a, b;
    cin >> n;
    wie = tree_size();
    tree.resize(wie);
    vector<ll> arr(n), arr2(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    sort(arr2.begin(), arr2.end());
    unordered_map<ll, ll> m;
    for (ll i = 0; i < n; i++) m[arr2[i]] = i;
    for (ll i = 0; i < n; i++) arr[i] = m[arr[i]];
    ll wyn = 0;
    for (ll i = 0; i < n; i++) {
        update(arr[i], 1);
        wyn += query(arr[i] + 1, n - 1);
    }
    cout << wyn;
}


