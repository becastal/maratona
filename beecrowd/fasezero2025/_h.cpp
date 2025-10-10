#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_withstdio(0);cin.tie(0);
#define endl '\n'

#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MAX = 1000000;
vector<string> nb(MAX + 1);
vector<bool> PAL(MAX + 1);

bool pal(string s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

string conv(ll num) {
    if (num == 0) return "0";
    string aux = "";
    while (num > 0) {
        aux += num % 2 + '0';
        num /= 2;
    }
    reverse(aux.begin(), aux.end());
    return aux;
}

bool maior(ll num){
  string aux = "";
    while (num > MAX) {
        int r = num % 2;
        aux += (r + '0');
        num /= 2;
    }
    reverse(aux.begin(), aux.end());

    if(pal(aux+nb[num])) return 1;
    else return 0;
}

int main() {
    ;

    for (int i = 0; i <= MAX; i++) {
        nb[i] = conv(i);
        PAL[i] = pal(nb[i]);
    }

    ll n; cin >> n;


    if(n <= MAX){

      for(ll i = n; i >= 0; i--){
        if(PAL[i] == true){
          cout << i << endl;
          cout<<nb[i]<<endl;
          break;
        }
      }
    }

    else{
      for(ll i = n; i >= 0; i--){
        if(i > MAX){
          bool r = maior(i);
          if(r){
            cout << i << endl;
            break;
          }
       }
      }
    }



    return 0;
}
