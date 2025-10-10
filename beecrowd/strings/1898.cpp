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

	string a, b; cin >> a >> b;
	string cpf = "", ai = "", bi = "";

	int para = -1000;
	for (char c : a) {
		if (c >= '0' and c <= '9' and para != 2) {
			if (cpf.size() < 11) {
				cpf.push_back(c);
			} else {
				ai.push_back(c);
			}
			para++;
		} else if (c == '.') {
			ai.push_back(c);
			para = 0;
		}
	}
	
	para = -1000;
	for (char c : b) {
		if (c >= '0' and c <= '9' and para != 2) {
			bi.push_back(c);
			para++;
		} else if (c == '.') {
			bi.push_back(c);
			para = 0;
		}
	}

	cout << "cpf " << cpf << endl;
	cout << fixed << setprecision(2) << stold(ai) + stold(bi) << endl;
    
    return(0);
}
