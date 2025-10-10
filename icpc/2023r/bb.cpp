#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int inv(vector<int> a) {
    vector<int> tails;          // tails[k] = minimum possible tail of an inc. subseq of length k+1 in -a
    tails.reserve(a.size());
    for (int x : a) {
        int y = -x;             // decreasing in a  <=> increasing in -a
        auto it = lower_bound(tails.begin(), tails.end(), y); // strict LIS on y
        if (it == tails.end()) tails.push_back(y);
        else *it = y;
    }
    return static_cast<int>(tails.size()); // = length of LDS in 'a'
}

int solve() {
	int n; cin >> n;

	vector<int> P(n);
	iota(all(P), 1);

	queue<vector<int>> Q;
	Q.push(P);

	map<vector<int>, int> D;
	D[P] = 0;

	while (Q.size()) {
		auto U = Q.front();	Q.pop();

		for (int i = 0; i < (1 << n); i++) {
			vector<int> A, B;	
			string S = "";
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) A.push_back(U[j]), S.push_back('1');	
				else B.push_back(U[j]), S.push_back('0');
			}

			do {
				vector<int> V;
				for (int j = 0, a = 0, b = 0; j < n; j++) {
					if (S[j] == '1') V.push_back(A[a++]);
					else V.push_back(B[b++]);
				}

				if (D.count(V)) continue;
				D[V] = D[U] + 1;
				Q.push(V);
			} while (next_permutation(all(S)));
		}
	}

	vector<vector<int>> A;
	for (auto [V, d] : D) {
		A.push_back(V);
	}

	sort(all(A), [&](vector<int> a, vector<int> b) {
		if (D[a] != D[b]) return D[a] < D[b];
		return a < b;
	});

	for (auto a : A) {
		for (int i : a) cout << i << ' '; cout << "| " << D[a] << " | " << inv(a) << endl;
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

