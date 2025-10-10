#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int solve() {
    int n, m; cin >> n >> m;
	int tam = ceil(sqrt(n));

    vector<int> A(n);
    for (int& i : A) cin >> i;

    vector<int> bl(n), prox(n), cont(n), ult(n);
    for (int i = 0; i < n; i++) bl[i] = i / tam;


    for (int b = 0; b <= (n - 1) / tam; ++b) {
        int l = b * tam;
        int r = min(n - 1, l + tam - 1);
        for (int i = r; i >= l; --i) {
            int j = i + A[i];
            if (j >= n) {
                prox[i] = n; cont[i] = 1; ult[i] = i;
            } else if (bl[j] != bl[i]) {
                prox[i] = j; cont[i] = 1; ult[i] = i;
            } else {
                prox[i] = prox[j]; cont[i] = cont[j] + 1; ult[i] = ult[j];
            }
        }
    }

    while (m--) {
        int t; cin >> t;
        if (t == 0) {
            int a, b; cin >> a >> b; a--;
            A[a] = b;
			int l = bl[a] * tam, r = min(n - 1, l + tam - 1);
			for (int i = r; i >= l; --i) {
				int j = i + A[i];
				if (j >= n) {
					prox[i] = n;
					cont[i] = 1;
					ult[i] = i;
				} else if (bl[j] != bl[i]) {
					prox[i] = j;
					cont[i] = 1;
					ult[i] = i;
				} else {
					prox[i] = prox[j];
					cont[i] = cont[j] + 1;
					ult[i] = ult[j];
				}
        }
        } else {
            int x; cin >> x; x--;
            int res = 0, resp = x;
            while (x < n) {
                res += cont[x];
                resp = ult[x];
                if (prox[x] >= n) break;
                x = prox[x];
            }
            cout << (resp + 1) << ' ' << res << endl;
        }
    }

	return(0);
}

int main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

