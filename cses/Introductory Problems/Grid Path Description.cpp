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

const int n = 7;
string S;
int vis[n][n];

int f(int cont, int ui, int uj) {
	if (cont == n*n-1) return int(ui == n-1 and uj == 0);
	if (ui == n-1 and uj == 0) return 0;

	int U = ui and !vis[ui-1][uj],
		D = ui + 1 < n and !vis[ui+1][uj],
		L = uj and !vis[ui][uj-1],
		R = uj + 1 < n and !vis[ui][uj+1];

	if (!U and !D and (L and R)) return 0;
	if (!L and !R and (U and D)) return 0;

	int agr = 0;

	auto calc = [&agr, cont](int i, int j) {
		vis[i][j] = 1;
		agr += f(cont + 1, i, j);
		vis[i][j] = 0;
	};

	if ((S[cont] == '?' or S[cont] == 'U') and U) calc(ui-1, uj);
	if ((S[cont] == '?' or S[cont] == 'D') and D) calc(ui+1, uj);
	if ((S[cont] == '?' or S[cont] == 'L') and L) calc(ui, uj-1);
	if ((S[cont] == '?' or S[cont] == 'R') and R) calc(ui, uj+1);

	return agr;
}

int solve() {
	cin >> S;
	vis[0][0] = 1;

	cout << f(0, 0, 0) << endl;

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
