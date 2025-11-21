#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
ll n, wie;

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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a;
    cin >> n;
    wie = tree_size();
    unordered_map<int, int> co;
    vector<int> tree(wie);
    vector<int> per1(n), per2(n), org(n);
    for (int i = 0; i < n; i++) {
        cin >> org[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> per1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> per2[i];
    }
    for (int i = 0; i < n; i++) {
        a = org[i];
        co[a] = i;
        org[i] = i;
    }
    for (int i = 0; i < n; i++) {
        a = per1[i];
        per1[i] = co[a];
    }
    for (int i = 0; i < n; i++) {
        a = per2[i];
        per2[i] = co[a];
    }
    ll wynik = 0;
    for (int i = 0; i < n; i++) {
        wynik += query(tree, 0, per2[i]);
        update(tree, per2[i], 1);
    }
    fill(tree.begin(), tree.end(), 0);
    for (int i = 0; i < n; i++) {
        wynik += query(tree, 0, per1[i]);
        update(tree, per1[i], 1);
    }
    fill(tree.begin(), tree.end(), 0);
    for (int i = 0; i < n; i++) {
        a = per1[i];
        co[a] = i;
        per1[i] = i;
    }
    for (int i = 0; i < n; i++) {
        a = per2[i];
        per2[i] = co[a];
    }
    for (int i = 0; i < n; i++) {
        wynik += query(tree, 0, per2[i]);
        update(tree, per2[i], 1);
    }
    wynik -= n * (n - 1) / 2;
    cout << wynik / 2;
}
/*
6
0 1 2 3 4 5
1 3 4 0 2 5
4 2 5 0 1 3*/
