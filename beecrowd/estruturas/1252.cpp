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

	int n, m; 
	while (cin >> n >> m and n) {
		vector<int> v(n);
		for (int& i : v) cin >> i;

		sort(v.begin(), v.end(), [&](int a, int b) {
			int am = a % m, bm = b % m;
			if (am == bm) {
				bool aOdd = (abs(a) % 2 == 1);
				bool bOdd = (abs(b) % 2 == 1);
				if (aOdd != bOdd) {
					return aOdd;
				} else {
					if (aOdd) {
						return a > b;
					} else {
						return a < b;
					}
				}
			}
			return am < bm;
		});

		cout << n << ' ' << m << endl;
		for (auto i : v) {
			cout << i << endl;
		}
	}
	cout << 0 << ' ' << 0 << endl;
    
    return(0);
}
