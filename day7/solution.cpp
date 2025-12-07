#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  int width = 0;
  set<int> beamPos = {};
  ll p1 = 0;
  while (1) {
    char c;
    scanf("%c", &c);
    if (c == '\n') {
      break;
    } else if (c == '.') {
      width++;
    } else {
      beamPos.insert(width);
      width++;
    }
  }

  while (1) {
    for (int i = 0; i < width; i++) {
      char c;
      scanf("%c", &c);
      if (c == '^') {
        if (beamPos.find(i) != beamPos.end()) {
          p1++;
          beamPos.erase(i);
          beamPos.insert(i - 1);
          beamPos.insert(i + 1);
        }
      }
    }
    char c;
    scanf("%c", &c);
    if (c == '!') {
      break;
    }
  }
  //  for (int i = 0; i < width; i++) {
  //    printf("Beams %d\n", beamPos.find(i) != beamPos.end());
  //  }

  printf("Output is %lld\n", p1);
}
