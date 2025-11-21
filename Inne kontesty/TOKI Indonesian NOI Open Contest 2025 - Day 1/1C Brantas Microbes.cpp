#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int licznik = 1;
    cout << "QUERY" << endl;
    unordered_map<int, vector<pair<int, int>>> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << licznik << " ";
            m[licznik].pb({i, j});
            licznik++;
            licznik = (licznik - 1) % 36 + 1;
        }
        cout << endl;
    }
    int x, s;
    cin >> s >> x;
    set<pair<int, int>> nowe;
    for (pair<int, int> p : m[s]) {
        nowe.insert(p);
    }
    m.clear();
    cout << "QUERY" << endl;
    licznik = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nowe.find({i, j}) != nowe.end()) {
                cout << licznik << " ";
                m[licznik].pb({i, j});
                licznik++;
                licznik = (licznik - 1) % 36 + 1;
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cin >> s >> x;
    nowe.clear();
    for (pair<int, int> p : m[s]) {
        nowe.insert(p);
    }
    m.clear();
    cout << "QUERY" << endl;
    licznik = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nowe.find({i, j}) != nowe.end()) {
                cout << licznik << " ";
                m[licznik].pb({i, j});
                licznik++;
                licznik = (licznik - 1) % 36 + 1;
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    cin >> s >> x;
    cout << "ANSWER" << endl;
    cout << m[s][0].fi + 1 << " " << m[s][0].se + 1 << endl;
}

