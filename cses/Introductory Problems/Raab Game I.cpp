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
	int n, a, b; cin >> n >> a >> b;
	if (a + b > n or !((a and b) or (!a and !b))) return cout << "NO" << endl, 0;

	vector<int> A(n), B(n);
	iota(A.begin(), A.end(), 1);

	for (int i = 0; i < n - (a + b); i++) {
		B[i] = (i + 1);
	}
	
	deque<int> d;
	for (int i = n - (a + b); i < n; i++) {
		d.push_back(i + 1);
	}

	for (int i = 0; i < b; i++) {
		d.push_front(d.back());
		d.pop_back();
	}

	for (int i = n - (a + b); i < n; i++) {
		B[i] = d.front();
		d.pop_front();
	}

	vector<int> v(2, 0);
	for (int i = 0; i < n; i++) {
		if (A[i] == B[i]) continue;
		v[A[i] < B[i]]++;
	}
	assert(v[0] == a and v[1] == b);

	cout << "YES" << endl;
	for (int i : A) cout << i << ' '; cout << endl;
	for (int i : B) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

//	int n; cin >> n;
//	vector<int> A(n), B(n);
//	iota(A.begin(), A.end(), 1);
//	iota(B.begin(), B.end(), 1);
//
//	do {
//		do {
//			vector<int> v(2, 0);
//			for (int i = 0; i < n; i++) {
//				if (A[i] == B[i]) continue;
//				v[A[i] < B[i]]++;
//			}
//
//			cout << v[0] << ' ' << v[1] << endl;
//			for (int i : A) cout << i << ' '; cout << endl;
//			for (int i : B) cout << i << ' '; cout << endl;
//
//		} while (next_permutation(B.begin(), B.end()));
//	} while (next_permutation(A.begin(), A.end()));

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}
