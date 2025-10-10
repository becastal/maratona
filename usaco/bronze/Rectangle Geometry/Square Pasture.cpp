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
	setIO("square");

	set<int> X, Y;
	for (int i = 0, x, y; i < 4; i++) {
		cin >> x >> y;
		X.insert(x);
		Y.insert(y);
	}

	int l = max((*X.rbegin() - *X.begin()), (*Y.rbegin() - *Y.begin()));
	cout << l * l << endl;

    return(0);
}
