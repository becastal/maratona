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
	setIO("circlecross");

	string s; cin >> s;

	vector<vector<int>> a(26);
	for (int i = 0; i < 52; i++) {
		a[s[i]-'A'].push_back(i);
	}

	int res = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			res += a[i][0] < a[j][0] and a[i][1] < a[j][1] and a[i][1] > a[j][0];	
		}
	}
	cout << res << endl;

    return(0);
}
