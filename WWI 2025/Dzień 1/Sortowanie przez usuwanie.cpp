#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
int main() {
    int n, k, m, sr = -1, a, za;
    cin >> n >> k >> m;
    vector<int> pier, dru;
    unordered_set<int> ok;
    for (int i = 0; i < m; i++) {
        cin >> a;
        ok.insert(a);
    }
    if ((n - m) % (k - 1) != 0) {
        cout << "NIE";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (ok.find(i) == ok.end()) {
            if (sr != -1) {
                dru.pb(i);
            }
            else {
                pier.pb(i);
            }
        }
        else {
            if (sr == -1 and pier.size() >= k / 2) {
                sr = i;
            }
        }
    }
    if (dru.size() < k / 2) {
        cout << "NIE";
        return 0;
    }
    cout << "TAK" << endl;
    cout << (n - m) / (k - 1) << endl;
    if (pier.size() < dru.size()) {
        swap(pier, dru);
    }
    vector<int> ruch;
    while (pier.size() - dru.size() >= k - 1) {
        for (int i = pier.size() - k; i < pier.size(); i++) {
            ruch.pb(pier[i]);
            if (pier.size() - 1 - k / 2 == i) {
                za = pier[i];
            }
        }
        sort(ruch.begin(), ruch.end());
        for (int i = 0; i < k; i++) {
            cout << ruch[i] << " ";
            pier.pop_back();
        }
        ruch = {};
        cout << endl;
        pier.pb(za);
    }
    if (pier.size() > dru.size()) {
        int x = (k - 1 + pier.size() - dru.size()) / 2;
        for (int i = pier.size() - 1; i > pier.size() - x - 2; i--) {
            ruch.pb(pier[i]);
        }
        for (int i = dru.size() - 1; i > dru.size() - k + x; i--) {
            ruch.pb(dru[i]);
        }
        sort(ruch.begin(), ruch.end());
        for (int i = 0; i < k; i++) {
            cout << ruch[i] << " ";
            if (i == k / 2) {
                za = ruch[i];
            }
        }
        for (int i = 0; i < k; i++) {
            if (i < x + 1) pier.pop_back();
            else dru.pop_back();
        }
        ruch = {};
        pier.pb(za);
        cout << endl;
    }
    while (pier.size() > 0) {
        for (int i = pier.size() - k / 2; i < pier.size(); i++) {
            ruch.pb(pier[i]);
        }
        ruch.pb(sr);
        for (int i = dru.size() - k / 2; i < dru.size(); i++) {
            ruch.pb(dru[i]);
        }
        sort(ruch.begin(), ruch.end());
        for (int i = 0; i < k; i++) {
            cout << ruch[i] << " ";
            if (i < k / 2) {
                pier.pop_back();
            }
            else if (i > k / 2) {
                dru.pop_back();
            }
        }
        cout << endl;
        ruch = {};
    }
}
