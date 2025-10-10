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
    int n, k; cin >> n >> k;

    vector<int> nums(n);
    for (auto& ni : nums)
        cin >> ni;

    for (int i = 0; i < k; i++)
    {
        int ki; cin >> ki;
        int l = 0, r = n - 1;
        cout << (*lower_bound(nums.begin(), nums.end(), ki) == ki ? "YES" : "NO") << endl;
    }


    return(0);
}
