#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define pb push_back
#define fi first
#define se second
int m, n, mod = 1e9 + 9;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, ak;
    cin >> n >> m;
    set<int> zera;
    vector<int> bilans(n + 1, 0), wynik;
    vector<vector<int>> grafout(n + 1);

    // wczytywanie
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        grafout[a].push_back(b);
        bilans[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (bilans[i] == 0) {
            zera.insert(i);
        }
    }
    while (!zera.empty()) {
        ak = *zera.begin();
        wynik.push_back(ak);
        zera.erase(ak);
        for(int i : grafout[ak]) {
            bilans[i]--;
            if (bilans[i] == 0) {
                zera.insert(i);
            }
        }
    }
    if (wynik.size() == n) {
        cout << "TAK" << endl;
        for (int i : wynik) {
            cout << i << " ";
        }
    }
    else {
        cout << "NIE";
    }
}

