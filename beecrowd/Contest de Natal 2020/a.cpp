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

	vector<vector<ll>> C(51, vector<ll>(51, 0));
	for (int i = 0; i <= 50; i++) {
		C[i][0] = C[i][i] = 1;
	}

	for (int i = 1; i <= 50; i++) {
		for (int j = 1; j <= 50; j++) {
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}

	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k, x; cin >> n >> k >> x;

		double p = x / 100.0;
		cout << "A chance de Basy acertar o numero no dia " << t << " eh ";
		cout << fixed << setprecision(2) << C[n][k] * pow(p, k) * pow(1-p, n-k) * 100.0 << "%" << endl;
	}
    
    return(0);
}
