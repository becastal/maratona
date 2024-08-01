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

bool vog(char c) {
	if (c >= 'A' and c <= 'Z') c += ('a' - 'A');

	return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

int main()
{
    _;

	string ns; getline(cin, ns);
	int n = stoi(ns);
	for (int i = 0; i < n; i++) {
		string f; getline(cin, f);
		stringstream ss(f);

		string s;
		int cont = 0, res = 1;
		while (ss >> s) {
			cont++;
			if (s.size() == 1) continue;
			if (s.size() > 5) {
				//cout << s << ' ' << (vog(s[0]) and vog(s.back())) << endl;
				res &= (vog(s[0]) and vog(s.back()));
			}
			else {
				//cout << s << ' ' << (!vog(s[0]) and vog(s.back())) << endl;
				res &= (!vog(s[0]) and vog(s.back()));
			}
		}
		cout << (res ? "SIM" : "NAO") << endl;
	}
    
    return(0);
}
