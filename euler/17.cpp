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

vector<string> s = {
	"",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
};

vector<string> S = {
	"",
	"",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety",
};

string cont(int x) {
	if (x == 1000) return "onethousand";
	if (x <= 19) return s[x];
	if (x < 100) return S[x / 10] + cont(x - 10 * (x / 10));
	return s[x / 100] + "hundredand" + cont(x - 100 * (x / 100));
}

int solve() {
	int res = 0;
	for (int i = 1; i <= 1000; i++) {
		string a = cont(i);
		if (a.size() > 3 and a[a.size() - 3] == 'a' and a[a.size() - 2] == 'n' and a[a.size() - 1] == 'd') {
			a.pop_back();
			a.pop_back();
			a.pop_back();
		}
		cout << a << endl;
		res += a.size();
	}
	cout << res << endl;

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
