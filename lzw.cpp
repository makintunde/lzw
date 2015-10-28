#include <bits/stdc++.h>

using namespace std;

void encode(string x) {
  int n, m, k=0, l=1, p, i;
  string sub;
  vector<string> d;
  vector<string> s;
  vector<int> c;
  vector<string>::iterator it1, it2;

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

void decode(string[] d, int[] c) {

} 

// Implementation of LZW Encoding.
int main() {
  string s;
  cin >> s;
  encode(s);

}
