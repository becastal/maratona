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

	int n, x; cin >> n >> x;	
	vector<string> v(n);
	for (string& si : v)
		cin >> si;

	function<int(string, string)> dist = [&] (string a, string b) {
		int d = 0;
		for (int i = 0; i < (int) a.size(); i++)
			d += (a[i] != b[i]);

		return d;
	};

	int pri, sol = false;
	function<void(int, int, vector<int>)> f = [&] (int i, int j, vector<int> vi) {
		if (sol) return;
		if (i == n)
		{
			vector<int> res(n);
			for (int i = 0; i < n; i++)
				res[vi[i] - 1] = i;
			
			if (dist(v[res.back()], v[pri]) > x) return;

			sol = true;
			for (int i : res)
				cout << v[i] << " -> ";
			cout << v[pri] << endl;
			return;
		}

		for (int k = 0; k < n; k++)
			if (k != j and !vi[k] and dist(v[j], v[k]) <= x) {
				auto vii = vi;
				vii[k] = i + 1;
				f(i + 1, k, vii);
			}
 	};

	for (pri = 0; pri < n; pri++) {
		if (sol) break;
		
		vector<int> vi(n, 0);
		vi[pri] = 1;
		f(1, pri, vi);
	}
    
	if (!sol) cout << "impossivel" << endl;

    return(0);
}
