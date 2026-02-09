#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

struct E {
	ll s;
	vector<int> f;
	E() {
		f = vector<int>(55);
	}
	bool operator<(const E& b) const {
		return s < b.s;
	}
};

int solve() {
	int n, k, x; cin >> n >> k >> x;
	vector<int> A(n);
	for (int& i : A) {
		cin >> i;
	}
	sort(rall(A));

	vector<ll> D(n-1);
	for (int i = 0; i < n-1; i++) {
		D[i] = A[i] - A[i+1];
	}

	priority_queue<E> pq;
	set<vector<int>> vis;

	E in;
	in.s = 1LL * k * A[0];
	for (int i = 0; i < 50; i++) {
		in.f[i] = 0;
	}

	pq.push(in);
	vis.insert(in.f);

	vector<ll> R(x);
	for (int i = 0; i < x; i++) {
		E a = pq.top(); pq.pop();
		R[i] = a.s;

		for (int j = 0; j < n-1; j++) {
			if (j == 0) {
				if (a.f[0] >= k) continue;
			} else {
				if (a.f[j-1] <= a.f[j]) continue;
			}
			E b = a;
			b.f[j]++;
			b.s -= D[j];
			if (vis.count(b.f)) continue;
			vis.insert(b.f);
			pq.push(b);
		}
	}

	for (int i = 0; i < x; i++) {
		cout << R[i] << endl;
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

