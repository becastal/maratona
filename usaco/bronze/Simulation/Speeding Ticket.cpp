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
	setIO("speeding");

	int n, m; cin >> n >> m;
	vector<tuple<int, int, int>> ev;
	vector<int> A(101), B(101);

	for (int i = 0, agr = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		ev.emplace_back(agr, 1, b);
		for (int j = 0; j < a; j++) {
			A[agr + j] = b;
		}
		agr += a;
	}

	for (int i = 0, agr = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		ev.emplace_back(agr, 1, b);
		for (int j = 0; j < a; j++) {
			B[agr + j] = b;
		}
		agr += a;
	}

	int res = 0;
	for (int i = 0; i <= 100; i++) {
		res = max(res, B[i] - A[i]);
	}
	cout << res << endl;

    return(0);
}
