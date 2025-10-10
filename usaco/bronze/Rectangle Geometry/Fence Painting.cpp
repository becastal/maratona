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
	setIO("paint");

	int a, b; cin >> a >> b;
	int c, d; cin >> c >> d;

	set<int> s;
	for (int i = a; i < b; i++) {
		s.insert(i);
	}
	for (int i = c; i < d; i++) {
		s.insert(i);
	}

	cout << s.size() << endl;

    return(0);
}
