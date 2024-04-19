#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *increment_one(char *c, int l, int r) {
  char *copy = malloc(10000 * sizeof(char));
  bool flag = false;
  strncpy(copy, c, r + 1);

  for (int i = r; i >= l; i--) {
    if (c[i] == '9') {
      if (i == l) {
        copy[i] = '0';
        char *result = malloc((r + 3) * sizeof(char));

        result[0] = '1';

        for (int j = 0; j <= r; j++) {
          result[j + 1] = copy[j];
          if (j == r) result[j + 2] = '\0';
        }

        return result;
      }
      flag = true;
      copy[i] = '0';
      continue;
    }
    copy[i] = c[i] + 1;
    break;
  }
  return copy;
}

int main() {
  int size;
  scanf("%d", &size);

  char str[10000];

  for (int i = 0; i < size; i++) {
    char x;
    scanf(" %c", &x);
    str[i] = x;
  }

  str[size] = '\0';

  for (int i = 0; i <= size / 2; i++) {
    bool flag = true;
    char a[10000];
    strncpy(a, str, i + 1);
    char *p = increment_one(str, 0, i);
    int len = strlen(a);

    for (int j = i + 1; j < size; j += len) {
      len = strlen(p);
      char b[10000];
      strncpy(b, str + j, len);
      b[len] = '\0';

      if (strcmp(p, b)) {
        flag = false;
        break;
      } else {
        p = increment_one(b, 0, len - 1);
      }
    }

    if (flag) {
      printf("%s\n", a);
      return 0;
    }
  }

  printf("%s\n", str);

  return 0;
}
