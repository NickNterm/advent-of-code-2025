#include <bits/stdc++.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>

using namespace std;

typedef long long ll;

int main() {
  ll num1;
  ll num2;
  int setNum1 = 1;
  ll p1 = 0;
  ll p2 = 0;
  string num;
  while (1) {
    char c;
    scanf("%c", &c);
    if (c == '!') {
      break;
    } else if (c == '-') {
      num1 = stoll(num);
      setNum1 = 0;
      num = "";
    } else if (c == ',') {
      setNum1 = 1;
      num2 = stoll(num);
      num = "";
      for (ll i = num1; i <= num2; i++) {
        int len = to_string(i).length();
        string value = to_string(i);
        set<ll> p2sol = {};

        for (int j = 1; j < len; j++) {
          if (len % j == 0) {
            string base = value.substr(0, j);
            int valid = 1;
            for (int k = j; k < len; k += j) {
              if (value.substr(k, j) != base) {
                valid = 0;
                break;
              }
            }
            if (valid) {
              if (!p2sol.count(i)) {
                p2 += i;
                p2sol.insert(i);
              }
            }
          }
        }
        if (len % 2 == 0) {
          int works = 1;
          string value = to_string(i);
          for (int j = 0; j < (len / 2); j++) {
            if (value[j] != value[j + (len / 2)]) {
              works = 0;
            }
          }
          if (works) {
            p1 += i;
          }
        }
      }
    } else {
      num += c;
    }
  }
  printf("part1 = %lld\n", p1);
  printf("part2 = %lld\n", p2);
}
