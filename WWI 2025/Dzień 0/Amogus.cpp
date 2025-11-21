#include "amolib.h"
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, k;
int main() {
    Zacznij(n, k);
    int ak = 1, li = 1, odp = Pytaj(1);
    while (odp == k and ak <= n) {
        odp = Pytaj(ak);
        if (odp != k) {
            break;
        }
        ak += li;
        li++;
    }
    if (odp > k and ak == 1) {
        Odpowiedz(n);
        return 0;
    }
    if (odp > k and ak == 2) {
        Odpowiedz(1);
        return 0;
    }
    while (odp < k) {
        ak++;
        odp = Pytaj(ak);
    }
    Odpowiedz(ak);
}


