#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second

ll maxn = 1000001;
vector<ll> wiel(maxn, 1), unionfind(maxn), grupy(9, -1), visited(9, 0), kt(9, 0);
vector<vector<int>> graf;

int dfs(int j) {
    int sum = 1;
    visited[j] = 1;
    for (int i : graf[j]) {
        if (grupy[i] != -1 && visited[i] == 0) {
            sum += dfs(i);
        }
    }
    return sum;
}

int gr(int a) {
    int aka = a;
    vector<int> bylo;
    while (unionfind[aka] != aka) {
        bylo.push_back(aka);
        aka = unionfind[aka];
    }
    while (!bylo.empty()) {
        unionfind[bylo.back()] = aka;
        bylo.pop_back();
    }
    return aka;
}

void uni(int a, int b) {
    int akb = gr(a), aka = gr(b);
    if (aka == akb) return;
    if (wiel[aka] > wiel[akb]) {
        unionfind[akb] = aka;
        wiel[aka] += wiel[akb];
    } else {
        unionfind[aka] = akb;
        wiel[akb] += wiel[aka];
    }
}

int main() {
    graf = {
        {},             // 0
        {2, 8},         // 1
        {1, 3, 4, 8},   // 2
        {2, 4},         // 3
        {2, 3, 5, 6},   // 4
        {4, 6},         // 5
        {4, 5, 7, 8},   // 6
        {6, 8},         // 7
        {1, 2, 6, 7}    // 8
    };

    ll n, m, k, x, y, ak, wynik = -1;
    cin >> n >> m;
    cin >> k;

    unordered_map<ll, ll> wierz;
    unordered_map<ll, ll> ileobok;
    unordered_map<ll, ll> obok;

    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        wierz[maxn * x + y] = i;
        unionfind[i] = i;
        for (int j = 1; j < 9; j++) {
            if (j > 0 && j < 4) ak = (x - 2 + j) * maxn + y + 1;
            else if (j == 4) ak = (x + 1) * maxn + y;
            else if (j < 8) ak = (x + 6 - j) * maxn + y - 1;
            else ak = (x - 1) * maxn + y;
            if (wierz.find(ak) != wierz.end()) {
                grupy[j] = gr(wierz[ak]);
                ileobok[grupy[j]]++;
                obok[grupy[j]] = j;
                kt[j] = wierz[ak];
            }
        }
        for (auto &p : obok) {
            fill(visited.begin(), visited.end(), 0);
            int ile = dfs(p.second);
            if (wynik == -1 && ile != ileobok[p.first]) {
                wynik = i + 1;
            }
        }
        for (int j = 1; j < 9; j++) {
            if (grupy[j] != -1) {
                uni(kt[j], i);
                ileobok.erase(grupy[j]);
                obok.erase(grupy[j]);
            }
            kt[j] = 0;
            visited[j] = 0;
            grupy[j] = -1;
        }
    }

    cout << wynik << "\n";
    return 0;
}
