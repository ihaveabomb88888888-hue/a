#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> graf;
int n;
int bfs(int korz) {
    vector<int>tab(n+1);
    queue<pair<int, int>> q;
    q.push({korz, 0});
    ll wynik = 0;
    while (q.size() > 0) {
        pair<int, int> para = q.front();
        q.pop();
        if (tab[para.first]) {
            continue;
        }
        else {
            tab[para.first] = 1;
            wynik += para.second;
            for (int j : graf[para.first]) {
                q.push({j, para.second + 1});
            }
        }
    }
    for(int i = 1; i <= n; i++) if(!tab[i]) return 1e9;
    return wynik + n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ile, szef, wynik = 1e9;
    cin >> n;
    graf.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ile;
        for (int j = 1; j <= ile; j++) {
            cin >> szef;
            graf[szef].push_back(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        wynik = min(wynik, bfs(i));
    }
    cout << wynik;
}

