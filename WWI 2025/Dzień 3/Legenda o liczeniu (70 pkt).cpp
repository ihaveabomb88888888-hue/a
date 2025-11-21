#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
l n, wie;

int tree_size() {
    int wynik = 1;
    while (wynik < n) wynik *= 2;
    return wynik * 2;
}
void update(vector<int>& tree, int index, int value) {
    index += wie / 2;
    tree[index] = value;
    while (index > 1) {
        index /= 2;
        tree[index] = tree[2 * index] + tree[2 * index + 1];
    }
}
int query(const vector<int>& tree, int left, int right) {
    left += wie / 2;
    right += wie / 2;
    int res = 0;
    while (left <= right) {
        if (left % 2 == 1) res += tree[left++];
        if (right % 2 == 0) res += tree[right--];
        left /= 2;
        right /= 2;
    }
    return res;
}
void update_fen(vector<int>& tree, int index, int value) {
    while (index < n + 1) {
        tree[index] += value;
        index += index & -index;
    }
}
ll query_fen(const vector<int>& tree, int index) {
    ll sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & -index;
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> n;
    unordered_map<int, int> co;
    vector<int> per1(n), per2(n), org(n), ind1(n), ind2(n);
    for (int i = 0; i < n; i++) {
        cin >> org[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> per1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> per2[i];
    }
    if (org == per2) {
        swap(per1, per2);
    }
    else if (per1 == per2) {
        swap(per2, org);
    }
    // ----------------------------------------------------- //
    for (int i = 0; i < n; i++) {
        a = org[i];
        co[a] = i;
        org[i] = i;
    }
    for (int i = 0; i < n; i++) {
        a = per1[i];
        per1[i] = co[a];
        ind1[co[a]] = i;
    }
    for (int i = 0; i < n; i++) {
        a = per2[i];
        per2[i] = co[a];
        ind2[co[a]] = i;
    }
    ll wynik = 0;
    if (n <= 1000) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ind1[j] < ind1[i] and ind2[j] < ind2[i]) {
                    wynik++;
                }
            }
        }
        cout << wynik << endl;
    }
    else if (org == per1) {
        wie = tree_size();
        vector<int> tree(wie, 0);
        for (int i = 0; i < n; i++) {
            wynik += query(tree, 0, per2[i]);
            update(tree, per2[i], 1);
        }
        cout << wynik << endl;
    }
    else {
        int pier = sqrt(n) / 2, li = -1;
        vector<pair<int, int>> zasieg;
        vector<int> doczego(n);
        for (int i = 0; i < n; i++) {
            if (i % pier == 0) {
                zasieg.pb({i, min(n, i + pier - 1)});
                li++;
            }
            doczego[i] = li;
        }
        vector<vector<int>> fen_trees(zasieg.size(), vector<int>(n + 1, 0));
        ll wyn = 0;
        for (int i = 0; i < n; i++) {
            li = 0;
            while (li < doczego[per2[i]]) {
                wyn += query_fen(fen_trees[li], ind1[per2[i]] + 1);
                li++;
            }
            for (int j = zasieg[li].fi; j < per2[i]; j++) {
                if (ind1[j] < ind1[per2[i]] and ind2[j] < ind2[per2[i]]) {
                    wyn++;
                }
            }
            update_fen(fen_trees[li], ind1[per2[i]] + 1, 1);
        }
        cout << wyn << endl;
    }
}
/*
6
0 1 2 3 4 5
1 3 4 0 2 5
4 2 5 0 1 3*/
