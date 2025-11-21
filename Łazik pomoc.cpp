#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
ll nwd(ll a, ll b) {
    if (a == 0) {
        return b;
    }
    return nwd(b%a, a);
}
bool czy(int n, int m, int d, int p) {
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int il = 1, nic = 1;
    pair<int, int> ak = {0, 0};
    vis[0][0] = 1;
    while (ak.fi != 0 or ak.se != 0 or nic != 0) {
        nic = 0;
        for (int i = 0; i < d; i++) {
            ak.se++;
            ak.se %= n;
            if (!vis[ak.fi][ak.se]) {
                vis[ak.fi][ak.se] = 1;
                il++;
            }
        }
        for (int i = 0; i < p; i++) {
            ak.fi++;
            ak.fi %= m;
            if (!vis[ak.fi][ak.se]) {
                vis[ak.fi][ak.se] = 1;
                il++;
            }
        }
    }
    if (il == n * m) return 1;
    return 0;
}
string solve(int n, int m) {
    int d = -1, p = -1;
    for (int i = 2; i < 1000; i++) {
        if (czy(n, m, i - 1, 1)) {
            d = i - 1;
            p = 1;
            break;
        }
        for (int j = 1; j < i; j++) {
            if (czy(n, m, j, i - j)) {
                d = j;
                p = i - j;
                break;
            }
        }
        if (p != -1) break;
    }
    string wyn = "";
    for (int i = 0; i < d; i++) wyn += 'D';
    for (int i = 0; i < p; i++) wyn += 'P';
    return wyn;
}
bool czydp(string s) {
    if (s.size() == 2) return 0;
    if (s[1] != s[s.size() - 2]) return 1;
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 2; i < 1000; i++) {
        for (int j = 2; j < 1000; j++) {
            string s = solve(i, j);
            if (s.size() != nwd(i, j) and nwd(i, j) != 1) {
                cout << i << " " << j << endl;
                cout << s.size() << " " << nwd(i, j) << endl;
                cout << s << endl;
                cout << endl;
            }
        }
    }
    cout << "konic" << endl;
}
