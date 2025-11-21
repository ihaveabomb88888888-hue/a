#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fi first
#define se second
using namespace std;
vector<pair<ll, ll>> trie;
void dodaj(ll co, ll wi, ll gl) {
    ll j = 1;
    if (gl > 31) {
        return;
    }
    if ((j << (31 - gl)) & co) {
        //cout << co << " " << gl << " 1 idzie do " << trie[wi].fi << " / " << trie.size() << endl;
        if (trie[wi].fi != -1) dodaj(co, trie[wi].fi, gl + 1);
        else {
            trie.pb({-1, -1});
            trie[wi].fi = trie.size() - 1;
            dodaj(co, trie.size() - 1, gl + 1);
        }
    }
    else {
        //cout << co << " " << gl << " 0 idzie do " << trie[wi].se << " / " << trie.size() << endl;
        if (trie[wi].se != -1) dodaj(co, trie[wi].se, gl + 1);
        else {
            trie.pb({-1, -1});
            trie[wi].se = trie.size() - 1;
            dodaj(co, trie.size() - 1, gl + 1);
        }
    }
}
ll usun(ll co, ll wi, ll gl) {
    ll j = 1;
    if (gl > 31) return 0;
    if ((j << (31 - gl)) & co) {
        if (usun(co, trie[wi].fi, gl + 1) == 0) {
            //cout << co << " usuwamy " << trie[wi].fi << endl;
            trie[wi].fi = -1;
            return (trie[wi].se != -1);
        }
        else return 1;
    }
    else {
        if (usun(co, trie[wi].se, gl + 1) == 0) {
            //cout << co << " usuwamy " << trie[wi].fi << endl;
            trie[wi].se = -1;
            return (trie[wi].fi != -1);
        }
        else return 1;
    }

}
ll min_xor(ll co, ll wi, ll gl, ll akwyn) {
    ll j = 1;
    if (gl > 31) {
        return akwyn;
    }
    if (!((j << (31 - gl)) & co)) {
        if (trie[wi].se != -1) {
            return min_xor(co, trie[wi].se, gl + 1, akwyn);
        }
        else {
            return min_xor(co, trie[wi].fi, gl + 1, akwyn + (j << (31 - gl)));
        }
    }
    else {
        if (trie[wi].fi != -1) {
            return min_xor(co, trie[wi].fi, gl + 1, akwyn);
        }
        else {
            return min_xor(co, trie[wi].se, gl + 1, akwyn + (j << (31 - gl)));
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll q, co, x;
    cin >> q;
    trie.pb({-1, -1});
    set<ll> czy;
    while (q--) {
        cin >> co >> x;
        if (co == 0) {
            dodaj(x, 0, 0);
            czy.insert(x);
        }
        else if (co == 1) {
            if (czy.find(x) != czy.end()) {
                czy.erase(x);
                usun(x, 0, 0);
            }
        }
        else {
            cout << min_xor(x, 0, 0, 0) << endl;
        }
    }
}
