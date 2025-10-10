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

void setIO(string nome) {
	if (nome == "") return;
	freopen((nome + ".in").c_str(), "r", stdin);
	freopen((nome + ".out").c_str(), "w", stdout);
}

int main()
{
    _;
	setIO("lineup");

	vector<string> A = {
		"Bessie",
		"Buttercup",
		"Belinda",
		"Beatrice",
		"Bella",
		"Blue",
		"Betsy",
		"Sue"
	};
	sort(A.begin(), A.end());

	int n; cin >> n;
	vector<pair<string, string>> cond;

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b >> b >> b >> b >> b;
		cond.emplace_back(a, b);
	}


	do {
		set<pair<string, string>> s;
		for (int i = 1; i < A.size()-1; i++) {
			s.emplace(A[i], A[i-1]);
			s.emplace(A[i-1], A[i]);
			s.emplace(A[i], A[i+1]);
			s.emplace(A[i+1], A[i]);
		}

		int ok = 1;
		for (auto i : cond) {
			ok &= s.count(i);
		}

		if (ok) {
			for (auto i : A) cout << i << endl;
			return 0;
		}
		
	} while (next_permutation(A.begin(), A.end()));
	assert(0);

    return(0);
}
