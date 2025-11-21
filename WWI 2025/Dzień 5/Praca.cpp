#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int n, wie;

int tree_size() {
    int wynik = 1;
    while (wynik < n) wynik *= 2;
    return wynik * 2;
}
void update(vector<pair<ll,ll>>& tree, int index, ll value) {
    index += wie / 2;
    tree[index] = {value, index - wie / 2};
    while (index > 1) {
        index /= 2;
        tree[index] = min(tree[index * 2], tree[index * 2 + 1]);
    }
}
pair<ll,ll> query(const vector<pair<ll,ll>>& tree, int left, int right) {
    left += wie / 2;
    right += wie / 2;
    pair<ll, ll> res = tree[left];
    while (right > left + 1) {
        if (left % 2 == 1) res = min(res, tree[left++]);
        if (right % 2 == 0) res = min(res, tree[right--]);
        left /= 2;
        right /= 2;
        res = min(res, tree[left]);
        res = min(res, tree[right]);
        //cout << left << " " << right << endl;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll z, wynik = 0, l, r;
    cin >> n;
    wie = tree_size();
    vector<pair<ll, ll>> tree(wie);
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        update(tree, i, arr[i]);
    }
    cin >> z;
    while (z--) {
        cin >> l >> r;
        if (r - l + 1 < 31) {
            ll wynik = 1e18;
            for (int i = l; i < r; i++) {
                for (int j = l - 1; j < i; j++) {
                    wynik = min(wynik, arr[i] | arr[j]);
                }
            }
            cout << wynik << endl;
        }
        else {
            vector<ll> min_or = {}, deleted = {};
            for (int x = 0; x < 31; x++) {
                pair<ll, ll> p = query(tree, l - 1, r - 1);
                min_or.pb(p.fi);
                update(tree, p.se, 1e18);
                deleted.pb(p.se);
            }
            ll wynik = 1e18;
            for (int i = 1; i < 31; i++) {
                for (int j = 0; j < i; j++) {
                    wynik = min(wynik, min_or[i] | min_or[j]);
                }
            }
            for (int i : deleted) {
                update(tree, i, arr[i]);
            }
            cout << wynik << endl;
        }
    }
}



