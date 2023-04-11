#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destruir(int ***campo, int linha);
void destruir(int ***campo, int linha) {
  if (*campo != NULL) {
    for (int i = 0; i < linha; i++) {
      free((*campo)[i]);
    }
    free(*campo);
    *campo = NULL;
  }
}

int main() {
  int linha, coluna;
  char c;
  int i, j, k, bombas, teste[2];
  scanf("%d %c%d%d", &linha,&c,&coluna, &bombas);
  if (bombas < 0) {
    printf("-1");
    return 0;
  }
  int **campo = (int **)calloc(linha, sizeof(int *));
  for (i = 0; i < linha; i++) {
    campo[i] = (int *)calloc(coluna, sizeof(int));
    for (j = 0; j < coluna; j++) {
      campo[i][j] = 0;
    }
  }
  struct bomba {
    int x;
    int y;
    int r;
  };
  struct bomba valor;
  for (i = 0; i < bombas; i++) {
    scanf("%d%d%d", &valor.x, &valor.y, &valor.r);
    if (valor.x > (linha - 1) || valor.x < 0 || valor.y > (coluna - 1) ||
        valor.y < 0) {
      printf("-1");
      return 0;
    }
    for (j = 0; j < (2 * valor.r + 1); j++) {
      for (k = 0; k < (2 * valor.r + 1); k++) {
        if (((valor.x - valor.r + j) >= 0 && (valor.y - valor.r + k) >= 0) &&
            ((valor.x - valor.r + j) <= (linha - 1) &&
             (valor.y - valor.r + k) <= (coluna - 1))) {
          campo[valor.x - valor.r + j][valor.y - valor.r + k] = 1;
        }
      }
    }
  }
  scanf("%d%d", &teste[0], &teste[1]);
  if (teste[0] > (linha - 1) || teste[0] < 0 || teste[1] > (coluna - 1) ||
      teste[1] < 0) {
    printf("-1");
    return 0;
  } else {
    if (campo[teste[0]][teste[1]] == 0) {
      printf("Seguro");
    } else {
      printf("Perigoso");
    }
  }
  destruir(&campo, linha);
  return 0;
}