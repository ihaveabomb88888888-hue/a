#include <bits/stdc++.h>
using namespace std;
#define ll long long

int st = 1e7;
vector<int> p(st + 1, 0), pre_sum(st + 1, 0);


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; i <= st; i++) {
        if (p[i] == 0) {
            for (int j = i; j <= st; j += i) {
                p[j]++;
            }
        }
    }
    for (int i = 2; i <= st; i++) {
        pre_sum[i] = pre_sum[i - 1] + p[i];
    }
    ll q, n;
    cin >> q;
    while (q--) {
        cin >> n;
        cout << pre_sum[n] << "\n";
    }
}
