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

	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		
		string si;
		int pri = 1;
		while (ss >> si) {
			if (!pri) cout << ' ';
			for (int i = 0; i < si.size(); i++) {
				if (i and si[i] == 'C' and (i == si.size()-1 or !isalpha(si[i+1]))) cout << "-se";
				else cout << si[i];
			}
			pri = 0;
		}
		cout << endl;
	}
    
    return(0);
}
