// Paulo Cezar, Maratona 2017, Laboratório de biotecnologia
#include <bits/stdc++.h>

using namespace std;

// FFT courtesy of http://e-maxx.ru/algo/fft_multiply
const double PI = acos(0) * 2;

struct complex_t {
  double a {0.0}, b {0.0};
  complex_t() {}
  complex_t(double na, double nb) : a{na}, b{nb} {}
  const complex_t operator+(const complex_t &c) const {
    return complex_t(a + c.a, b + c.b);
  }
  const complex_t operator-(const complex_t &c) const {
    return complex_t(a - c.a, b - c.b);
  }
  const complex_t operator*(const complex_t &c) const {
    return complex_t(a*c.a - b*c.b, a*c.b + b*c.a);
  }
};

const int MAX_SUM = 1 << 22;
using base = complex_t;

int rev[MAX_SUM << 1];
base wlen_pw[MAX_SUM << 1];

void fft(base a[], int n, bool invert) {
  for (int i = 0; i < n; ++i)
    if (i < rev[i])
      swap(a[i], a[rev[i]]);

  for (int len = 2; len <= n; len <<= 1) {
    double ang = 2 * PI / len * (invert ? -1 : +1);
    int len2 = len>>1;

    base wlen(cos(ang), sin(ang));
    wlen_pw[0] = base(1, 0);
    for (int i = 1; i < len2; ++i)
      wlen_pw[i] = wlen_pw[i-1] * wlen;

    for (int i = 0; i < n; i += len) {
      base t,
        *pu = a+i,
        *pv = a+i+len2,
        *pu_end = a+i+len2,
        *pw = wlen_pw;
      while (pu != pu_end) {
        t = *pv * *pw;
        *pv = *pu - t;
        *pu = *pu + t;

        ++pu, ++pv, ++pw;
      }
    }
  }

  if (invert)
    for (int i = 0; i < n; ++i) {
      a[i].a /= n;
      a[i].b /= n;
    }
}

void calc_rev(int n, int log_n) {
  for (int i = 0; i < n; ++i) {
    rev[i] = 0;
    for (int j = 0; j < log_n; ++j)
      if (i & (1<<j))
        rev[i] |= 1 << (log_n-1-j);
  }
}

base P[MAX_SUM << 1], Q[MAX_SUM << 1];
array<int, (MAX_SUM << 1)> C;

const int MAXN = 100000;

int f(char c) {
  return (c - 'a' + 1);
}

array<int, MAXN> sums;

int main(int argc, char* argv[]) {

  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;

  int n = s.size();
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += f(s[i]);
    sums[i] = sum;
  }

  for (int i = 0; i < n; ++i) P[sums[i]] = complex_t(1.0, 0.0);

  Q[sum] = complex_t(1.0, 0.0);
  for (int i = 0; i < (n-1); ++i) Q[sum - sums[i]] = complex_t(1.0, 0.0);

  n = 1; int log_n = 0;
  while (n <= sum) { n <<= 1; log_n++; }
  n <<= 1; log_n++;

  calc_rev(n, log_n);

  fft(P, n, false), fft(Q, n, false);
  for (int i = 0; i < n; ++i)
    P[i] = P[i] * Q[i];
  fft(P, n, true);

  for (int i = 0; i < n; ++i)
    C[i] = int(P[i].a + 0.5);

  int res = 0;
  for (int submass = sum+1; submass <= 2*sum; ++submass) {
    if (C[submass]) res++;
	cout << submass << endl;
  }

  cout << res << "\n";

  return 0;
}
