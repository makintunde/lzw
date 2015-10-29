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

void decode(vector<string> &d, vector<int> &c) {
  cout << endl;
  int i=0;
  int code=c[i], old, n=d.size();
  cout << d[code];
  old = code;
  i++;
  while (i<n) {
    code = c[i];
    if (code<n) {
      cout << d[code];
      string oldt = d[old];
      string kstr = d[code];
      char k = kstr[0];
      string tmp = "";
      tmp += k;
      tmp += oldt;
      d.push_back(tmp);
      cout << "tmp: " << tmp << endl;
      old = code;
    } else {
      string oldt = d[old];
      char k = oldt[0];
      cout << (oldt+k);
      old = code;
    }
    i++;
  }
  cout << endl;
} 

// Implementation of LZW Encoding.
int main() {
  //string s;
  //cin >> s;
  //encode(s);

  vector<string> d;
  vector<int> c;
  int m, n;
  cin >> m >> n;
  for (int i=0; i<m; ++i) {
    string next;
    cin >> next;
    d.push_back(next);
  }
  for (int i=0; i<n; ++i) {
    int next;
    cin >> next;
    c.push_back(next);
  }
  decode(d, c);
  
}
