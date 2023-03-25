#include <stdio.h>

int main() {
  char converte(int l);
  char coluna;
  int linha;
  scanf("%c%d", &coluna, &linha);
  coluna = coluna - 0;
  if ((linha + 2) <= 8) {
    if ((coluna - 1) >= 65) {
      printf("%c %d\n", converte(coluna - 1), linha + 2);
    }
    if ((coluna + 1) <= 72) {
      printf("%c %d\n", converte(coluna + 1), linha + 2);
    }
  }
  if ((coluna + 2) <= 72) {
    if ((linha + 1) <= 8) {
      printf("%c %d\n", converte(coluna + 2), linha + 1);
    }
    if ((linha - 1) >= 1) {
      printf("%c %d\n", converte(coluna + 2), linha - 1);
    }
  }
  if ((linha - 2) >= 1) {
    if ((coluna + 1) <= 72) {
      printf("%c %d\n", converte(coluna + 1), linha - 2);
    }
    if ((coluna - 1) >= 65) {
      printf("%c %d\n", converte(coluna - 1), linha - 2);
    }
  }
  if ((coluna - 2) >= 65) {
    if ((linha - 1) >= 1) {
      printf("%c %d\n", converte(coluna - 2), linha - 1);
    }
    if ((linha + 1) <= 8) {
      printf("%c %d\n", converte(coluna - 2), linha + 1);
    }
  }
  return 0;
}
char converte(int l) {
  if (l == 65) {
    return 'A';
  } else if (l == 66) {
    return 'B';
  } else if (l == 67) {
    return 'C';
  } else if (l == 68) {
    return 'D';
  } else if (l == 69) {
    return 'E';
  } else if (l == 70) {
    return 'F';
  } else if (l == 71) {
    return 'G';
  } else if (l == 72) {
    return 'H';
  }
  return '-';
}
