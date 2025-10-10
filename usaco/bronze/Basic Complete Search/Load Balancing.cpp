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
	setIO("balancing");

	int n, b; cin >> n >> b;

	vector<pair<int, int>> A(n);

	vector<int> X, Y;
	for (auto& [x, y] : A) {
		cin >> x >> y;
		X.push_back(x + 1), X.push_back(x - 1); 
		Y.push_back(y + 1), Y.push_back(y - 1); 
	}

	sort(X.begin(), X.end()); X.erase(unique(X.begin(), X.end()), X.end());
	sort(Y.begin(), Y.end()); Y.erase(unique(Y.begin(), Y.end()), Y.end());

	int res = n;
	for (int x_ : X) {
		for (int y_ : Y) {
			vector<vector<int>> cont(2, vector<int>(2, 0));
			for (auto [x, y] : A) {
				cont[x > x_][y > y_]++;
			}

			res = min(res, max({cont[0][0], cont[0][1], cont[1][0], cont[1][1]}));
		}
	}
	cout << res << endl;

    return(0);
}
