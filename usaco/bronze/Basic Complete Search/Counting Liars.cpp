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
	setIO("");

	int n; cin >> n;
	vector<pair<char, int>> a(n);
	for (auto& [tp, pos] : a) {
		cin >> tp >> pos;
	}

	int res = INF;
	for (auto [tp, pos] : a) {
		int agr = 0;
		for (auto [tp_, pos_] : a) {
			agr += (tp_ == 'L' and  pos > pos_) or (tp_ == 'G' and  pos < pos_);
		}
		res = min(res, agr);
	}
	cout << res << endl;

    return(0);
}
