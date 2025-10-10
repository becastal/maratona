#include <bits/stdc++.h>
#define f first
#define s second
//#define _ ios_base::sync_with_stdio(0);cin.tie(0);
//#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

void solve(int n) {
	int k; cin >> k;

	auto query = [](int l, int r) {
		cout << "? " << l << ' ' << r << endl;
		int x; cin >> x;
		return x;
	};

	int l = 1, r = n;
	while (l < r) {
		int m = l + r >> 1;
		int uns = query(1, m);
		//cout << l << ' ' << r << endl;

		int zeros = m - uns;
		if (zeros >= k) {
			r = m;
		} else {
			l = m + 1;
			//k -= zeros;
		}
	}

	cout << "! " << l << endl;
}

int main()
{
    //_;

   	int n, t; cin >> n >> t; 
	while (t--) {
		solve(n);
	}

    return(0);
}
