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

int solve() {
	int n, m; cin >> n >> m;
	int N = n*m;

	vector<int> A(N);
	for (int& i : A) cin >> i;

	int s = accumulate(all(A), 0);
	int b = 1 + (s % N != 0);

	int chao = s / N, teto = (s + N - 1) / N;
	int abaixo = 0, acima = 0;

	for (int i : A) {
		if (i < chao) abaixo += (chao - i);	
		if (b == 2 and i >= teto) acima++;
	}

	int a = 10 * (abaixo + (b == 1 ? 0 : max(0, s % N - acima)));
	cout << a << ' ' << b << endl;

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
