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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAX = 2 * 1e5 + 10;

int main()
{
    _;
    
    int n, p; cin >> n >> p;
    ordered_multiset<int> ms;
    
	// merge sort tambem resolve;
    for (int i = 0; i < n; i++) {
        int vi; cin >> vi; vi /= p;

        cout << ms.size() - ms.order_of_key({vi + 1, 0}) << ' ';
        ms.insert({vi, i});
    }

    cout << endl;

    return 0;
}

