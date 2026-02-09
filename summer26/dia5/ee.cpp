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

	// P[i] = {max power of type0 enemy it can beat, max power of type1 enemy it can beat}
	vector<array<int, 2>> P(N);

	for (int i = 0; i < N; i++) {
		int p, s; cin >> p >> s;
		if (s == 0) P[i] = {2 * p, p};     // light: vs light gets x2, vs dark normal
		else        P[i] = {p, 2 * p};     // dark : vs light normal, vs dark gets x2
	}

	vector<int> A, B; // enemy type0, enemy type1
	for (int i = 0; i < N; i++) {
		int q, t; cin >> q >> t;
		if (t == 0) A.push_back(q);
		else        B.push_back(q);
	}

	sort(rall(A));
	sort(rall(B));

	// sweep A (enemy type0) using cap0, pick minimal cap1 among eligible
	sort(all(P), [&](auto &x, auto &y){
		return x[0] > y[0]; // cap0 descending
	});

	vector<int> foi(N, 0);
	priority_queue<array<int, 2>> pq; // {-cap1, id} -> top = smallest cap1

	int ptr = 0;
	for (int q : A) {
		while (ptr < N && P[ptr][0] >= q) {
			pq.push({-P[ptr][1], ptr});
			ptr++;
		}
		if (pq.empty()) return cout << "NO" << endl, 0;
		auto [negcap1, id] = pq.top(); pq.pop();
		foi[id] = 1;
	}

	// remaining monsters -> multiset of cap1
	multiset<int> st;
	for (int i = 0; i < N; i++) {
		if (!foi[i]) st.insert(P[i][1]);
	}

	// sweep B (enemy type1) using cap1, pick smallest cap1 >= q
	for (int q : B) {
		auto it = st.lower_bound(q);
		if (it == st.end()) return cout << "NO" << endl, 0;
		st.erase(it);
	}

	cout << "YES" << endl;
	return 0;
}

signed main() {
	_;
	int t = 1; cin >> t;
	while (t--) solve();
	return 0;
}
