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

	int n, a;
	while (cin >> n >> a) {
		cin.ignore();

		map<string, int> M;
		for (int i = 0; i < n; i++) {
			string s; getline(cin, s);
			stringstream ss(s);
		
			string si;
			string agr = "";
			while (ss >> si) {
				agr.push_back(si[0]);
			}

			agr += to_string(a);
			M[agr]++;
		}

		int res = 0;
		for (auto [a, b] : M) {
			res += b-1;
		}
		cout << res << endl;
	}
    
    return(0);
}
