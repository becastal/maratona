#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int N; cin >> N;

	vector<array<int, 2>> V(N);
	for (int i = 0, a, b; i < N; i++) {
		cin >> a >> b;
		if (b) {
			V[i] = {a, 2 * a};
		} else {
			V[i] = {2 * a, a};
		}
	}

	vector<int> A, B;
	vector<array<int, 2>> Eu(N);
	for (auto& [a, b] : Eu) {
		cin >> a >> b;
		if (b) {
			B.push_back(a);
		} else {
			A.push_back(a);
		}
	}
	sort(rall(A));
	sort(rall(B));

	vector<int> O(N);
	iota(all(O), 0);
	sort(all(O), [&](int a, int b) {
		return V[a][0] > V[b][0];
	});

	vector<int> foi(N);

	priority_queue<array<int, 2>> pq;
	int p = 0;
	for (int i : A) {
		while (p < N and V[O[p]][0] >= i) {
			pq.push({-V[O[p]][1], O[p++]});
		}
		if (pq.empty()) return cout << "NO" << endl, 0;
		auto [cap, j] = pq.top(); pq.pop();
		foi[j] = 1;
	}

	set<array<int, 2>> S;
	for (int i = 0; i < N; i++) if (!foi[i]) {
		S.insert({V[i][1], i});
	}

	for (int i : B) {
		auto it = S.lower_bound({i, -1});
		if (it == S.end()) return cout << "NO" << endl, 0;
		S.erase(it);
	}
	cout << "YES" << endl;

	return(0);
}

signed main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
    
    return(0);
}

