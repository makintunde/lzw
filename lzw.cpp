#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define Inf 2147483647
#define LL long long
#define N 1000000

#define F(i, a) for( int i = (0); i < (a); i++ )
#define Fs(i, sz) for( size_t i = 0; i < sz.size (); i++ )
#define Fe(i, x) for(typeof (x.begin()) i = x.begin(); i != x.end (); i++)
#define coutf(a, b, c) for( int i = a; i <= (b); i++ ) cout << c[i] << " "; cout << endl
#define coutff(a, b, c, d) for( int i = a; i <= (b); i++ ) cout << c[i] << ", " << d[i] << " "; cout << endl
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())

using namespace std;

// Implementation of LZW Encoding.
int main() {
  int n, m, k=0, l=1, p, i;
  string x, sub;
  vector<string> d;
  vector<string> s;
  vector<int> c;
  vector<string>::iterator it1, it2;

  cin >> x;
  cin >> m;
  n = x.size();

  for (i=0; i<m; ++i) { 
    string next;
    cin >> next;
    s.push_back(next);
    d.push_back(next);
  }

  // Iterate through string x.
  while (k+l<n) {
    // Find longest substring of x starting at index k in d.
    sub = x.substr(k,l);
    it1 = find(d.begin(), d.end(), sub);
    while (it1 != d.end()) {
      it2 = it1;
      if (k+l==n) break;
      l++;
      sub = x.substr(k,l);
      it1 = find(d.begin(), d.end(), sub);
    }
    p = distance(d.begin(), it2);
    c.push_back(p);
    if (k+l<n) {
      d.push_back(sub);
      k += l-1;
      l=1;
    }
  }
  
  cout << "c: ";
  for (i=0; i<c.size(); ++i) cout << c[i] << " ";
  cout << endl << "d: ";
  for (i=0; i<d.size(); ++i) cout << d[i] << " ";
  cout << endl;
}
