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

	vector<int> a(3);
   	for (int& i : a) cin >> i; 
	sort(a.begin(), a.end());

	do {
		if (a[0] * a[1] == a[2]) return cout << "Yes" << endl, 0;
	} while(next_permutation(a.begin(), a.end()));
	cout << "No" << endl;

    return(0);
}
