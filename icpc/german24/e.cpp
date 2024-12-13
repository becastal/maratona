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

int main()
{
    _;

	string s; cin >> s;
	int n = (int)s.size();

	function<void(int, string)> f = [&] (int i, string si) {
		if (i >= n) {
			cout << si << endl;
			return;
		}

		if (i < n - 1 and s[i] == 'S' and s[i+1] == 'S') {
			f(i + 2, si + "B");
		}

		si.push_back(tolower(s[i]));
		f(i+1, si);
	};

	f(0, "");
    
    return(0);
}
