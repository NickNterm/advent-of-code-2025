#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  vector<pair<ll, ll>> v;
  set<ll> ids;
  ll p1 = 0;
  ll p2 = 0;
  while (1) {
    string line;
    cin >> line;
    if (line == "test") {
      break;
    }

    auto pos = line.find('-');
    string num1 = line.substr(0, pos);
    line.erase(0, pos + 1);
    v.push_back({atoll(num1.c_str()), atoll(line.c_str())});
  }
  sort(v.begin(), v.end(),
       [](pair<ll, ll> a, pair<ll, ll> b) { return a.first < b.first; });
  //   for (pair<ll, ll> p : v) {
  //     printf("PAIR %lld %lld\n", p.first, p.second);
  //   }
  int i = 0;
  while (1) {
    if (i + 1 == v.size()) {
      break;
    }
    pair<ll, ll> a = v[i];
    pair<ll, ll> b = v[i + 1];
    if (a.second >= b.first && a.second <= b.second) {
      v[i] = {a.first, b.second};
      v.erase(v.begin() + i + 1);
    } else if (a.second > b.first && a.second > b.second) {
      v.erase(v.begin() + i + 1);
    } else {
      i++;
    }
  }

  for (pair<ll, ll> p : v) {
    p2 += p.second - p.first + 1;
  }
  while (1) {
    ll n;
    scanf("%lld", &n);
    if (n == -1) {
      break;
    }
    for (pair<ll, ll> p : v) {
      if (p.first <= n && p.second >= n) {
        p1++;
        break;
      }
    }
  }
  printf("Output p1 %lld\n", p1);
  printf("Output p2 %lld\n", p2);
}
