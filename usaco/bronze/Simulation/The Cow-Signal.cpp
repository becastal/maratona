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
	setIO("cowsignal");

	int n, m, k; cin >> n >> m >> k;
	vector<string> v(n);
	for (auto& i : v) {
		cin >> i;
		string j = "";
		for (char c : i) {
			for (int ii = 0; ii < k; ii++) {
				j.push_back(c);
			}
		}

		for (int ii = 0; ii < k; ii++) {
			cout << j << endl;
		}
	}


    return(0);
}
