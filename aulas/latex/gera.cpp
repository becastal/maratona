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

int solve() {

	string s = "abracadabralbertini";
	int n = s.size();
	set<char> S;


	for (int i = 0; i < n; i++) {
		cout << "\\begin{frame}{Set}" << endl;
			cout << "\t\t\\begin{center}" << endl;

				cout << "\t\t\"";
				for (int j = 0; j < n; j++) {
					if (j == i) {
						cout << "\\textcolor{red}{" << s[j] << "}";
						continue;
					}
					cout << s[j];
				}
				cout << "\"\n";
			cout << "\t\t\\end{center}" << endl;

				cout << "\t\\vfill" << endl;
				cout << "\t\\textcolor{blue}{\\texttt{set<char>}: \\{";

				int pri = 1;
				S.insert(s[i]);
				for (char c : S) {
					if (!pri) cout << ", ";
					cout << '\'' << c << '\'';
					pri = 0;
				}
				cout << "\\}}" << endl;
		cout << "\\end{frame}\n" << endl;
	}

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
