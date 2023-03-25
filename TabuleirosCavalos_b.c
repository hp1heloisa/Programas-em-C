#include <stdio.h>
#include <stdlib.h>

void destruir(int ***pos, int n);
void destruir(int ***pos, int n) {
  if (*pos != NULL) {
    for (int i = 0; i < n; i++) {
      free((*pos)[i]);
    }
    free(*pos);
    *pos = NULL;
  }
}

int main() {
  int n, i, j;
  char coluna;
  scanf("%d", &n);
  int **pos = (int **)calloc(n, sizeof(int *));
  for (i = 0; i < n; i++) {
    pos[i] = (int *)calloc(2, sizeof(int));
    scanf(" %c%d", &coluna, &pos[i][1]);
    pos[i][0] = coluna + 0;
  }
  for (i = 0; i < n; i++) {
    for (j = n - 1; j > i; j--) {
      if (((pos[i][1] + 2) <= 8) && ((pos[i][1] + 2) == pos[j][1])) {
        if (((pos[i][0] - 1) >= 65) && ((pos[i][0] - 1) == pos[j][0])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
        if (((pos[i][0] + 1) <= 72) && ((pos[i][0] + 1) == pos[j][0])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
      }
      if (((pos[i][0] + 2) <= 72) && ((pos[i][0] + 2) == pos[j][0])) {
        if (((pos[i][1] + 1) <= 8) && ((pos[i][1] + 1) == pos[j][1])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
        if (((pos[i][1] - 1) >= 1) && ((pos[i][1] - 1) == pos[j][1])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
      }
      if (((pos[i][1] - 2) >= 1) && ((pos[i][1] - 2) == pos[j][1])) {
        if (((pos[i][0] + 1) <= 72) && ((pos[i][0] + 1) == pos[j][0])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
        if (((pos[i][0] - 1) >= 65) && ((pos[i][0] - 1) == pos[j][0])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
      }
      if (((pos[i][0] - 2) >= 65) && ((pos[i][0] - 2) == pos[j][0])) {
        if (((pos[i][1] - 1) >= 1) && ((pos[i][1] - 1) == pos[j][1])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
        if (((pos[i][1] + 1) <= 8) && ((pos[i][1] + 1) == pos[j][1])) {
          printf("Os cavalos estao em guerra!");
          destruir(&pos, n);
          return 0;
        }
      }
    }
  }
  if (n >= 0) {
    printf("Paz no reino!");
  }
  destruir(&pos, n);
  return 0;
}