#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

const int MAX = 1e5+10;
int C[MAX];

int solve() {
	int n; cin >> n;

	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}

	int q; cin >> q;
	vector<array<int, 3>> Q(q);
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r; l--, r--;
		Q[i] = {l, r, i};
	}

	int bl = max(1.0, double(n) / sqrt(n));	
	sort(all(Q), [&](auto& a, auto& b){
		if (a[0] / bl != b[0] / bl) return a[0] < b[0];
		if ((a[0] / bl) & 1) return a[1] > b[1];
	return a[1] < b[1];
	});

	int res = 0;
	auto add = [&](int a) {
		res += C[a]++ & 1;	
	};
	auto rem = [&](int a) {
		res -= --C[a] & 1;	
	};

	vector<int> R(q);
	int l = 0, r = -1;
	for (auto [a, b, id] : Q) {
		while (r < b) add(A[++r]);
		while (l > a) add(A[--l]);
		while (l < a) rem(A[l++]);
		while (r > b) rem(A[r--]);
		R[id] = res;
	}

	for (int i : R) {
		cout << i << endl;
	}


	return(0);
}

signed main()
{
    _;

	int t = 1; //cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

