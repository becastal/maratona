#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;
 
int main() {
	_;

	int n; cin >> n;
	string s; cin >> s;
	vector<int> cont(26, 0);

	for (char c : s) cont[c-'a']++;

	vector<char> res(n, '?');
	for (int i = 0, l = 0; i < 26; i++) {
		for (int j = 0; j < cont[i]; j++) {
			res[l++] = char('a'+i);
		}
	}
	for (char c : res) cout << c; cout << endl;
	
//	int c = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (j == i) {
//				c++;
//				continue;
//			}
//			string si = "";
//			for (int l = i; l <= j; l++) {
//				si.push_back(res[l]);
//			}
//
//			int ok = 1;
//			for (int l = 0, r = (int)si.size()-1; l <= r and ok; l++, r--) {
//				ok &= si[l] == si[r];
//			}
//			c += ok;
//		}
//	}
//	cout << c << endl;
 
 	return 0;
}
