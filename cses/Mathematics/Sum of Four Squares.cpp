#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll; 
using namespace std;
const int MAX = 1e7+10;
array<int, 2> L[MAX];

int solve() {
    int x; cin >> x;

    int ni = (int)floor(sqrt(x));
    for (int i = 0; i <= ni; ++i) {
        int ri = x - i*i;
        if (ri < 0) break;
        int nj = (int)floor(sqrt(ri));

        for (int j = i; j <= nj; ++j) {
            int rj = ri - j*j;
            if (rj < 0 || rj >= MAX) continue;
            if (L[rj][0] != -1) {
                auto [i_, j_] = L[rj];
                cout << i << ' ' << j << ' ' << i_ << ' ' << j_ << endl;
                return 0;
            }
        }
    }
    return 0;
}

int main() {
    _;

    for (int s = 0; s < MAX; ++s) L[s] = {-1, -1};

    for (int i = 0; 1LL*i*i < MAX; ++i) {
        int i2 = i*i;
        for (int j = i; ; ++j) {
            long long s = 1LL*i2 + 1LL*j*j;
            if (s >= MAX) break;
            if (L[s][0] == -1) L[s] = {i, j};
        }
    }

    int t = 1; cin >> t;
    while (t--) {
		solve();
	}
    return(0);
}

