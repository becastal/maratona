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

int main()
{
    _;

	vector<string> M(8);
	for (auto& s : M) cin >> s;

	int res = 0;

	auto f = [&](auto f, int lin, vector<int> col, vector<int> pri, vector<int> sec) {
		if (lin == 8) {
			res++;
			return;
		}

		for (int i = 0; i < 8; i++) {
			if (M[lin][i] == '*' or col[i] or pri[lin - i + 8] or sec[lin + i]) continue;

			col[i] = pri[lin - i + 8] = sec[lin + i] = 1;
			f(f, lin + 1, col, pri, sec);
			col[i] = pri[lin - i + 8] = sec[lin + i] = 0;
		}
	};

	f(f, 0, vector<int>(20, 0), vector<int>(20, 0), vector<int>(20, 0));
	cout << res << endl;
    
    return(0);
}
