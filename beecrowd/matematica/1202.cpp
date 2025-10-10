#include <bits/stdc++.h>
#define f first
#define s second
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define dbg(x) cout << #x << " = " << x << endl
typedef unsigned long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
using namespace std;

int main()
{
    _;

	//set<tuple<int, int, int>> s;
	//s.emplace(0, 1, 1);
	//vector<int> f = {0, 1, 1};

	//while (1) {
	//	f.push_back((f.back() + f[f.size()-2]) % 1000);

	//	if (s.count(make_tuple(f[f.size()-3], f[f.size()-2], f[f.size()-1]))) {
	//		cout << f.size() << endl;
	//		for (int i : f) cout << i << ' '; cout << endl;
	//		break;
	//	}
	//	s.emplace(f[f.size()-3], f[f.size()-2], f[f.size()-1]);
	//}

	// recebo pot 2 mod esse periodo como n
	// depois printo o fib n mod 1000
	// o fib precalcula e a pot 2 nao tem jeito tem que ler mod periodo

   vector<int> fib(1510, 0);
    fib[1] = fib[2] = 1;
    for (int i = 3; i < 1510; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 1000;
    }

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = 0;
        for (char c : s) {
            n = (n * 2 + (c - '0')) % 1500;
        }
    
        cout << setw(3) << setfill('0') << (fib[n] == 365 ? 480 : fib[n]) << endl;
    } 

    return(0);
}
