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

	map<int, int> M;
	stack<int> S;
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;

		if (s == "PUSH") {
			int n; cin >> n;
			M[n]++;
			S.push(n);
		} else if (s == "MIN") {
			if (S.empty()) cout << "EMPTY" << endl;
			else {
				cout << M.begin()->f << endl;
			}
		} else if (s == "POP") {
			if (S.empty()) cout << "EMPTY" << endl;
			else {
				if (--M[S.top()] == 0) {
					M.erase(S.top());	
				};
				S.pop();
			}
		}
	}
    
    return(0);
}
