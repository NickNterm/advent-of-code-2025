
#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int main() {
  int zerosp1 = 0;
  int zerosp2 = 0;
  int indicator = 50;
  char input[256];
  while (scanf("%255s", input) != EOF) {
    char type = input[0];
    size_t len = strlen(input);

    if (len > 0) {
      memmove(input, input + 1, len);
    }
    int val = atoi(input);

    if (type == 'L') {
      bool wasInZero = indicator == 0;
      indicator -= val;
      if (indicator < 0) {
        zerosp2 += abs(indicator / 100) + 1;
        if (wasInZero) {
          zerosp2--;
        }
        indicator = (indicator % 100 + 100) % 100;

        if (indicator == 0) {
          zerosp2--;
        }
      }
    } else {
      indicator += val;
      zerosp2 += indicator / 100;
      indicator = indicator % 100;
      if (indicator == 0) {
        zerosp2--;
      }
    }
    if (indicator == 0) {
      zerosp1++;
      zerosp2++;
    }
  }
  printf("output is %d\n", zerosp1);
  printf("output is %d\n", zerosp2);
}
