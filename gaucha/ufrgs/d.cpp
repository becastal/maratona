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

int d, a, b, c;

int op(int i, int j, int tp) {
	if (tp == 0) return i + j;
	if (tp == 1) return i - j;
	if (tp == 2) return i * j;
	if (tp == 3 and j != 0) return i / j;
	return 0;
}

bool da(int tot=0, int i=0) {
	// para cada permutacao de abc, checar 1 (op) 2 (op) 3 == d;
	// ou seja, 6 * 4 * 4 * 1e6 eh pra passar
	// submit failed?
	vector<int> v = {a, b, c};
	int dp[6][4][4];
	int dpi[6][4];
	int dpj[6][4];

	int k = 0;
	do {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				dp[k][i][j] = op(op(v[0], v[1], i), v[2], j);
			}
			dpi[k][i] = op(v[0], v[1], i);
			dpj[k][i] = op(v[1], v[0], i);
		}
		k++;
	} while (next_permutation(v.begin(), v.end()));

	int res = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				res |= (dp[i][j][k] == d);
			}
			res |= (dpi[i][j] == d);
			res |= (dpj[i][j] == d);
		}
	}

	return res;
}

int main()
{
    _;

	cin >> d;
	for (a = 1; a <= 100; a++) {
		for (b = 1; b <= 100; b++) {
			for (c = 1; c <= 100; c++) {
				if (a == b or a == c or a == d or b == c or b == c or c == d) continue;
				if (da()) continue;
				
				return cout << a << ' ' << b << ' ' << c << endl, 0;
			}
		}
	}
    
    return(0);
}
