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

int solve() {
	int a, b, c, d; cin >> a >> b >> c >> d;

	bitset<101> A, B;
	for (int i = a; i <= b; i++) {
		A[i] = 1;
	}
	for (int i = c; i <= d; i++) {
		B[i] = 1;
	}
	if (B.count() > A.count()) swap(A, B), swap(a, c), swap(b, d);
	auto C = A & B;
	dbg(A.to_string());
	dbg(B.to_string());

	if (!C.count()) {
		cout << 1 << endl;
	} else {
		cout << C.count() + 1 - (a == c) - (b == d) << endl;
	}

	return 0;
}

int main()
{
    _;

	int t; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
