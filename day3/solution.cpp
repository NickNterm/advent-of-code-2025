#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;
typedef long long ll;

map<pair<int, int>, ll> mem = {};
map<pair<int, int>, ll> mem2 = {};
ll dp2(string battery, int i, int used) {
  if (i == battery.length() && used == 2) {
    return 0;
  }
  if (i == battery.length()) {
    return -100;
  }
  pair<int, int> p = {i, used};
  if (mem2.find(p) != mem2.end()) {
    return mem2[p];
  }
  ll res = dp2(battery, i + 1, used);
  if (used < 2) {
    string v;
    v += battery[i];
    ll value = atoi(v.c_str()) * pow((ll)10, 1 - used);
    // printf("VALUE I %lld\n", value);
    res = max(res, value + dp2(battery, i + 1, used + 1));
  }
  mem2[p] = res;
  return res;
}

ll dp(string battery, int i, int used) {
  if (i == battery.length() && used == 12) {
    return 0;
  }
  if (i == battery.length()) {
    return -pow(10, 12);
  }
  pair<int, int> p = {i, used};
  if (mem.find(p) != mem.end()) {
    return mem[p];
  }
  ll res = dp(battery, i + 1, used);
  if (used < 12) {
    string v;
    v += battery[i];
    ll value = atoi(v.c_str()) * pow((ll)10, 11 - used);
    res = max(res, value + dp(battery, i + 1, used + 1));
  }
  mem[p] = res;
  return res;
}

int main() {
  string battery;
  char c;
  ll p1 = 0;
  ll p2 = 0;
  while (1) {
    if (scanf("%c", &c) == EOF) {
      printf("Output p1 %lld\n", p1);
      printf("Output p2 %lld\n", p2);
      break;
    }
    if (c == '\n') {
      // printf("p2 %lld\n", dptest);
      mem = {};
      ll t = dp(battery, 0, 0);
      p2 += t;
      mem2 = {};
      ll dptest = dp2(battery, 0, 0);
      p1 += dptest;
      battery = "";
    } else {
      battery += c;
    }
  }
}
