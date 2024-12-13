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
	vector<string> As, Bs;

	int asta = 0, astb = 0;
	for (char c : a) asta += (c == '*');
	for (char c : b) astb += (c == '*');

	for (int i = 0; i < (1 << asta); i++) {
		string ai = a;
		int k = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] == '*') {
				ai[j] = (i & (1 << k++) ? '1' : '0');
			}
		}
		As.push_back(ai);
	}
	for (int i = 0; i < (1 << astb); i++) {
		string bi = b;
		int k = 0;
		for (int j = 0; j < b.size(); j++) {
			if (b[j] == '*') {
				bi[j] = (i & (1 << k++) ? '1' : '0');
			}
		}
		Bs.push_back(bi);
	}

	vector<int> p2 = {1};
	for (int i = 0; i < 20; i++) {
		p2.push_back(p2.back() << 1);
	}

	for (string& bi : Bs) {
        int bint = 0;
        for (int i = 0; i < bi.size(); i++) {
			bint += (bi[bi.size() - 1 - i] == '1') * p2[i];
        }

		vector<int> p(501, 1);
		for (int i = 1; i < 500; i++) {
			p[i] = (p[i-1] << 1) % bint;
		}

		for (string& ai : As) {
			int res = 0;
			for (int i = 0; i < ai.size(); i++) {
				if (ai[ai.size() - 1 - i] == '1') {
					res += p[i];
					res %= bint;
				}
			}
			
			if (!res) return cout << ai << endl, 0;
		}
	}

    
    return(0);
}
