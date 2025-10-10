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

	string s, res = ""; cin >> s;

	for (char c : s) {
		if (c == 'A') {
			int cont = 0;
			while (res.size() and res.back() == 'W') {
				res.pop_back();	
				cont++;
			}
			
			res.push_back('A');
			for (int i = 0; i < cont; i++) {
				res.push_back('C');
			}
		}
		else res.push_back(c);
	}
	cout << res << endl;
    
    return(0);
}
