#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;
#define int ll

int solve() {
	int n, k; cin >> n >> k;
	vector<array<int, 3>> Q(k);
	for (auto& [l, r, x] : Q) {
		cin >> l >> r >> x; l--, r--;
	}

	vector<int> R(k, 1);

	// reuse buffers (avoid realloc 60x)
	vector<int> F(n + 1), X(n + 1), P(n + 1);
	vector<int> nxt(n + 1), prv(n), ord(n);
	vector<int> ord2id;
	vector<int> R_(k);

	auto calc = [&](int b) {
		// reset diffs
		fill(all(F), 0);
		fill(all(X), 0);

		// Type-1: bit = 1  => force ones on [l,r]
		for (int i = 0; i < k; i++) if ((Q[i][2] >> b) & 1) {
			auto [l, r, x] = Q[i];
			F[l] += 1; F[r + 1] -= 1;
			X[l] ^= i; X[r + 1] ^= i; // XOR works: when F[pos]==1 it gives the unique id
		}

		for (int i = 1; i <= n; i++) {
			F[i] += F[i - 1];
			X[i] ^= X[i - 1];
		}

		// P = prefix count of positions with F[pos] > 0  (forced 1s)
		P[0] = 0;
		for (int i = 0; i < n; i++) {
			P[i + 1] = P[i] + (F[i] > 0);
		}

		// nxt[pos] = first index >= pos with F[idx]==1 (unique cover), or n
		nxt[n] = n;
		for (int i = n - 1; i >= 0; i--) {
			nxt[i] = (F[i] == 1 ? i : nxt[i + 1]);
		}
		// prv[pos] = last index <= pos with F[idx]==1, or -1
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (F[i] == 1) last = i;
			prv[i] = last;
		}

		// build "block order" of unique IDs along the array, SKIPPING non-unique positions
		// IMPORTANT: do NOT reset lastId when F[i]!=1 (this is the "skip zeros" idea)
		ord2id.clear();
		ord2id.reserve(n);

		int lastId = -1;
		for (int i = 0; i < n; i++) {
			if (F[i] == 1) {
				int id = X[i]; // valid id because coverage count == 1
				if (id != lastId) {
					ord2id.push_back(id);
					lastId = id;
				}
				ord[i] = (int)ord2id.size(); // 1-based block index
			} else {
				ord[i] = 0;
			}
		}

		// find violated Type-2 constraints (bit=0) and intersect candidate BLOCK intervals
		int f0 = 0, x0 = 0;
		int m = (int)ord2id.size();
		int interL = 1, interR = m;
		bool canType1 = true;

		for (int i = 0; i < k; i++) if (((Q[i][2] >> b) & 1) == 0) {
			auto [l, r, x] = Q[i];
			int len = r - l + 1;

			// violated iff all positions in [l,r] are forced-1 (F>0)
			if (P[r + 1] - P[l] == len) {
				f0++;
				x0 ^= i;

				// candidate Type-1 removals: unique-covered positions inside [l,r]
				int p = nxt[l];
				int q = prv[r];

				if (p > r || q < l) {
					// no F==1 inside => removing a Type-1 never frees a position here
					canType1 = false;
				} else {
					interL = max(interL, (int)ord[p]);
					interR = min(interR, (int)ord[q]);
				}
			}
		}

		if (!f0) return; // already satisfiable for this bit -> everyone good for this bit

		// build R_ (good constraints for this bit)
		fill(all(R_), 0);

		// Type-2 removals
		if (f0 == 1) {
			R_[x0] = 1; // removing the single violated Type-2 fixes it
		}

		// Type-1 removals: constraints whose block is in intersection of all violated segments
		if (canType1 && interL <= interR) {
			for (int blk = interL; blk <= interR; blk++) {
				int id = ord2id[blk - 1];
				R_[id] = 1;
			}
		}

		// AND into global answer
		for (int i = 0; i < k; i++) {
			R[i] &= R_[i];
		}
	};

	for (int i = 0; i < 60; i++) calc(i);

	for (int i = 0; i < k; i++) cout << R[i];
	cout << endl;

	return 0;
}

signed main() {
	_;
	int t = 1; //cin >> t;
	while (t--) solve();
	return 0;
}
