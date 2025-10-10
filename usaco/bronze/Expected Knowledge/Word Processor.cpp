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
	setIO("word");

	int n, k; cin >> n >> k;

	for (int i = 0, ki = 0; i < n; i++) {
		string s; cin >> s;

		if (ki + s.size() > k) {
			cout << endl;
			cout << s;
			ki = s.size();
		} else {
			cout << (ki ? " " : "") << s;
			ki += s.size();
		}
	}
	cout << endl;

    return(0);
}
