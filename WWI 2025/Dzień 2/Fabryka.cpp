#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
vector<pair<int, int>> trie;
void upd(ll co, int wi, int gl) {
    ll j = 1;
    //cout << co << " " << wi << " " << gl << " " << ((j<<(59 - gl))&co) << endl;
    if (gl > 59) {
        return;
    }
    if ((j << (59 - gl)) & co) {
        if (trie[wi].fi != -1) upd(co, trie[wi].fi, gl + 1);
        else {
            //cout << "ustawiamy " << trie.size() << " jako 1 o gl " << gl << endl;
            trie.pb({-1, -1});
            trie[wi].fi = trie.size() - 1;
            upd(co, trie.size() - 1, gl + 1);
        }
    }
    else {
        if (trie[wi].se != -1) upd(co, trie[wi].se, gl + 1);
        else {
            //cout << "ustawiamy " << trie.size() << " jako 0 o gl " << gl << endl;
            trie.pb({-1, -1});
            trie[wi].se = trie.size() - 1;
            upd(co, trie.size() - 1, gl + 1);
        }
    }
}
ll max_xor(ll co, int wi, int gl, ll akwyn) {
    ll j = 1;
    if (gl > 59) {
        return akwyn;
    }
    if ((j << (59 - gl)) & co) {
        if (trie[wi].se != -1) {
            return max_xor(co, trie[wi].se, gl + 1, akwyn + (j << (59 - gl)));
        }
        else {
            return max_xor(co, trie[wi].fi, gl + 1, akwyn);
        }
    }
    else {
        if (trie[wi].fi != -1) {
            return max_xor(co, trie[wi].fi, gl + 1, akwyn + (j << (59 - gl)));
        }
        else {
            return max_xor(co, trie[wi].se, gl + 1, akwyn);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, wynik = 0;
    cin >> n;
    vector<ll> arr(n + 1), pre(n + 1, 0);
    trie.pb({-1, -1});
    upd(0, 0, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        pre[i] = pre[i-1]^arr[i];
        upd(pre[i], 0, 0);
        wynik = max(wynik, max_xor(pre[i], 0, 0, 0));
    }
    cout << wynik;
}
