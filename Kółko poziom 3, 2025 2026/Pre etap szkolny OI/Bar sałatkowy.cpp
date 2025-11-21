#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
#define pb push_back
#define fi first
#define se second
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, nas, bil = 0;
    string bar;
    cin >> n;
    cin >> bar;
    vector<int> pre(n + 1), arr(n + 1, 0), dp(n + 1);
    for (int i = 0; i < n; i++) arr[i] = (bar[i] == 'p') - (bar[i] == 'j');
    for (int i = 0; i <= n; i++) {
        pre[i] = bil;
        bil += arr[i];
    }
    unordered_map<int, int> m;
    int kon = n, wyn = 0;
    m[pre[n]] = n;
    for (int i = 0; i <= n; i++) dp[i] = i;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] != -1) {
            if (m.find(pre[i]) != m.end()) {
                nas = m[pre[i]];
                if (pre[dp[nas]] >= pre[kon]) kon = dp[nas];
            }
            dp[i] = kon;
            wyn = max(wyn, kon - i);
        }
        else kon = i;
        m[pre[i]] = i;
    }
    cout << wyn;
}

