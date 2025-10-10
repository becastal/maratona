#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

struct grupo {
	int tam, k;
	vector<int> L, R;

	grupo(vector<int> A) : tam(1), L(A), R(A), k((int)A.size()) {};

	bool operator<(const grupo& B) const{
		for (int i = 0; i < k; i++) {
			if (R[i] > B.L[i]) return false;
		}
		return true;
	}

	void merge(const grupo& B) {
		tam += B.tam;
		for (int i = 0; i < k; i++) {
			L[i] = min(L[i], B.L[i]);
			R[i] = max(R[i], B.R[i]);
		}
	}
};

int solve() {
	int n, k; cin >> n >> k;

	set<grupo> S;
	for (int i = 0; i < n; i++) {
		vector<int> A(k); 
		for (int& i : A) cin >> i;

		grupo Ga(A);
		auto l = S.lower_bound(Ga), r = S.upper_bound(Ga);
		while (l != r) {
			Ga.merge(*l);
			l = S.erase(l);
		}
		S.insert(l, Ga);
		cout << S.rbegin()->tam << endl;
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
