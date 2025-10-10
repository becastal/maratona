#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
using namespace std;

int testa() {
	int n; cin >> n;
	vector<int> A(n), P(n), S(n), F(n+1, 0);
	for (int& i : A) cin >> i;

	for (int i = 0; i < n; i++) {
		P[i] = max((i ? P[i-1] : INT_MIN), A[i]);
	}
	for (int i = n-1; i >= 0; i--) {
		S[i] = min((i+1 < n ? P[i+1] : INT_MAX), A[i]);
	}

	for (int i : P) F[i]++;
	for (int i : S) F[i]++;

	cout << "P: "; for (int i : P) cout << i << ' '; cout << endl;
	cout << "S: "; for (int i : S) cout << i << ' '; cout << endl;

	for (int i = 1; i <= n; i++) cout << F[i] << " \n"[i==n];

	return 0;
}

vector<int> calcF(vector<int>& A) {
	int n = (int)A.size();
	vector<int> P(n), S(n), F(n+1, 0);

	for (int i = 0; i < n; i++) {
		P[i] = max((i ? P[i-1] : INT_MIN), A[i]);
	}
	for (int i = n-1; i >= 0; i--) {
		S[i] = min((i+1 < n ? P[i+1] : INT_MAX), A[i]);
	}

	for (int i : P) F[i]++;
	for (int i : S) F[i]++;
	F.erase(F.begin());

	return F;
}

int solve() {
	int n; cin >> n;
	vector<int> F(n);
	for (int& i : F) cin >> i;

	vector<array<int, 2>> B;
	for (int i = 0; i < n; i++) if (F[i]) {
		B.push_back({i+1, F[i]});
	}

	vector<int> A;
	for (int i = 0; i < (int)B.size(); ) {
		auto [a, fa] = B[i];

		if (fa & 1) {
			if (i + 1 >= n) return cout << -1 << endl, 0;
			auto [b, fb] = B[i+1];

			if ((fb & 1 ^ 1) or fb < fa) return cout << -1 << endl, 0;
			
			A.insert(A.end(), fa / 2, a);
			// agora sobra (1, fb)
			// da sempre pra fazer [2, 2, 2, 1] pra (1, 7)
			int m = (1 + fb) / 2;
			A.insert(A.end(), m - 1, b);
			A.insert(A.end(), 1, a);
			i += 2;
		} else {
			A.insert(A.end(), fa / 2, a);
			i++;
		}
	}

	assert(calcF(A) == F);
	for (int i : A) cout << i << ' '; cout << endl;

	return(0);
}

int main()
{
    _;

	int t = 1; cin >> t;
	while (t--) {
		//testa();
		solve();
	}
    
    return(0);
}

