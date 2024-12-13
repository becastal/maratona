#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

    //vector<ll> res(15, LINF);
    //ll pot[15];
    //pot[0] = 1, pot[1] = 10;
    //for (int i = 2; i < 15; i++) {
    //    pot[i] = pot[i-1] * 10;
    //}

    //for (int i = 0; i < 15; i++) {
    //    for (int j = 0; j < (1 << i); j++) {
    //        ll agr = 0;
    //        for (int k = 0; k < i; k++) {
    //            if (j & (1 << k)) {
    //                agr += 3LL * pot[k];
    //            } else {
    //                agr += 6LL * pot[k];
    //            }
    //        }

    //        if (agr % 66 == 0) {
    //            res[i] = min(res[i], agr);
    //        }
    //    }
    //}

    //for (ll i : res) cout << i << endl;
	vector<int> v = {-1, -1, 66, -1, 3366};

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
		if (n <= 4) {
			cout << v[n] << endl;
		} else {
			cout << string(n - 4, '3') + (n & 1 ? "6366" : "3366") << endl;
		}
    }

    return(0);
}

