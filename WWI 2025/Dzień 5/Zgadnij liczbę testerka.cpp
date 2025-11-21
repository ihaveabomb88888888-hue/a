//#include "zgalib.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fi first
#define se second
vector<int> permutacja;
int odpowiedz(int x) {
    if (x == permutacja.back()) {
        return 1;
    }
    else {
        return 0;
    }
}
unsigned zapytaj(int i, int j) {
    return unsigned(permutacja[i] & (1 << j));
}
unsigned init() {
    unsigned x = permutacja.size();
    return x;
}
int rozwiaz() {
    int n = int(init());
    int li = 0, wynik = 0;
    vector<int> wszyst(n), wszystind(n - 1);
    for (int i = 0; i < n; i++) {
        wszyst[i] = i + 1;
        if (i != n - 1) wszystind[i] = i;
    }
    while (wszyst.size() > 1) {
        vector<int> zerawsz, jedwsz, jedper, zeraper;
        for (int i : wszystind) {
            int czy = int(zapytaj(i, li));
            if (czy) jedper.pb(i);
            else zeraper.pb(i);
        }
        for (int i : wszyst) {
            if (i & (1 << li)) jedwsz.pb(i);
            else zerawsz.pb(i);
        }
        if (jedper.size() != jedwsz.size()) {
            wynik += (1 << li);
            wszyst = jedwsz;
            wszystind = jedper;
        }
        else {
            wszyst = zerawsz;
            wszystind = zeraper;
        }
        li++;
    }
    return odpowiedz(wszyst[0]);
}
int main() {
    bool zl = 0;
    for (int i = 1; i < 10000; i++) {
        permutacja.pb(0);
        for (int j = 0; j < i; j++) {
            for (int k = 1; k <= i; k++) {
                permutacja[k - 1] = (j + k) % i + 1;
            }
            if (!rozwiaz()) {
                cout << "wywala sie na " << i << " z przesunieciem o " << j << endl;
                zl = 1;
                break;
            }
        }
        if (i % 500 == 0) cout << "przeszlo do " << i << endl;
        if (zl == 1) break;
    }
    cout << "koniec" << endl;
}


