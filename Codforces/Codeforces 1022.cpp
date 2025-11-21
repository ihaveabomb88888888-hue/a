#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, n;
    cin >> q;
    vector<ll> v, s;
    unordered_map<ll, int> m;
    unordered_map<int, vector<int>> gdzie;
    while (q--) {
        cin >> n;
        vector<ll> sur(n);
        for (int i = 0; i < n; i++) {
            cin >> sur[i];
        }
        vector<ll> v;
        v.reserve(n);
        v.push_back(sur[0]);
        for (int i = 1; i < n; i++)
            if (sur[i] != sur[i-1])
                v.push_back(sur[i]);
        n = v.size();
        vector<ll> s = v;
        sort(s.begin(), s.end());
        unordered_map<ll,int> m;
        for (int i = 0; i < n; i++) {
            m[s[i]] = i;
        }
        vector<vector<int>> gdzie(n);
        for (int i = 0; i < n; i++) {
            int id = m[v[i]];
            gdzie[id].push_back(i);
        }
        vector<int> czy(n, 0);
        int klony = 0;
        for (int val = n - 1; val >= 0; val--) {
            for (int pos : gdzie[val]) {
                if (!czy[pos]) {
                    klony++;
                    czy[pos] = 1;
                }
                if (pos > 0) czy[pos - 1] = 1;
                if (pos + 1 < n) czy[pos + 1] = 1;
            }
        }

        cout << klony << "\n";
    }
}
