#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
int akt = 59;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
    int n, wyn = 0, a;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(akt + 1, -1));
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int ind = i, ak = arr[i];
        dp[i][arr[i]] = i;
        while (dp[ind - 1][ak] != -1) {
            dp[i][ak + 1] = dp[ind - 1][ak];
            ind = dp[i][ak + 1];
            ak++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < akt; j++) {
            if (dp[i][j] != -1 and j > wyn) wyn = j;
        }
    }
    cout << wyn;
}
