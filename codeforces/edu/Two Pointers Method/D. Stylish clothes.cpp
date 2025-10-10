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
	int na; cin >> na;
	vector<int> A(na);
	for (int& i : A) cin >> i;
	sort(A.begin(), A.end());

	int nb; cin >> nb;
	vector<int> B(nb);
	for (int& i : B) cin >> i;
	sort(B.begin(), B.end());

	int nc; cin >> nc;
	vector<int> C(nc);
	for (int& i : C) cin >> i;
	sort(C.begin(), C.end());

	int nd; cin >> nd;
	vector<int> D(nd);
	for (int& i : D) cin >> i;
	sort(D.begin(), D.end());

	int a = 0, b = 0, c = 0, d = 0, melhor = INF;
	int a_ = 0, b_ = 0, c_ = 0, d_ = 0;

	while (a < na and b < nb and c < nc and d < nd) {
		int l = min({A[a], B[b], C[c], D[d]});
		int r = max({A[a], B[b], C[c], D[d]});

		if (melhor > r - l) {
			melhor = r - l;
			a_ = A[a];
			b_ = B[b];
			c_ = C[c];
			d_ = D[d];
		}

		if (l == A[a]) a++;
		else if (l == B[b]) b++;
		else if (l == C[c]) c++;
		else if (l == D[d]) d++;
	}
	
	cout << a_ << ' ' << b_ << ' ' << c_ << ' ' << d_ << endl;

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
