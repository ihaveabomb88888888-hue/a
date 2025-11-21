#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define st first
#define nd second
#define pb push_back
#define lld long double


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int>> graf(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        graf[a].pb(b);
        graf[b].pb(a);
    }
    queue<int> q;
    vector<int> odl(n + 1, -1);
    q.push(1);
    odl[1] = 0;
    while (!q.empty()) {
        int w = q.front();
        q.pop();
        for (int i : graf[w]) {
            if (odl[i] == -1) {
                odl[i] = odl[w] + 1;
                q.push(i);
            }
        }
    }
}
