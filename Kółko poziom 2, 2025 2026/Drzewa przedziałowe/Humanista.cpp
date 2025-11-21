#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define pb push_back
#define fi first
#define se second
int n, wie;
vector<int> tree;
int tree_size() {
    int wynik = 1;
    while (wynik < n) wynik *= 2;
    return wynik * 2;
}
void update(int ind, int val) {
    ind += wie / 2;
    tree[ind] = val;
    ind /= 2;
    while (ind > 0) {
        tree[ind] = tree[ind * 2] ^ tree[ind * 2 + 1];
        ind /= 2;
    }
}
int query(int left, int right) {
    left += wie / 2;
    right += wie / 2;
    int res = 0;
    while (left <= right) {
        if (right % 2 == 0) res ^= tree[right--];
        if (left % 2 == 1) res ^= tree[left++];
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
    int q, a, b;
    cin >> n >> q;
    wie = tree_size();
    tree.resize(wie);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    while (q--) {
        cin >> co >> a >> b;
        a--;
        b--;
        if (co[0] == 'c') {
            cout << query(a, b) << endl;
        }
        else {
            swap(arr[a], arr[b]);
            update(a, arr[a]);
            update(b, arr[b]);
        }
    }
}

