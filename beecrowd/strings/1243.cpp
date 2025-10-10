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

	auto ok = [](string s, int& cont) {
		int n = (int)s.size();
		if (n == 0) return 0;

		for (int i = 0; i < n; i++) {
			if (i == n-1 and s[i] == '.') continue;
			if (!isalpha(s[i])) return 0;
		}

		cont = s.back() == '.' ? n-1 : n;
		return 1;
	};

	while (getline(cin, s)) {
		stringstream ss(s);

		int soma = 0, tam = 0;
		string si;
		while (ss >> si) {
			int a = 0;
			if (ok(si, a)) {
				soma += a;
				tam++;
			}
		}

		int med = (!tam ? 0 : soma / tam);

		if (med <= 3) {
			cout << 250 << endl;
		} else if (med <= 5) {
			cout << 500 << endl;
		} else {
			cout << 1000 << endl;
		}
	}
    
    return(0);
}
