#include <stdio.h>
#include <string.h>

int determine_resultado(char escolha1[], char escolha2[]) {
  char dict[5][8] = {
      {"pedra\0"}, {"papel\0"}, {"tesoura\0"}, {"lagarto\0"}, {"Spock\0"}};

  if (!strcmp(escolha1, escolha2))
    return 0; // Empate
  else if ((!strcmp(escolha1, dict[2]) && !strcmp(escolha2, dict[1])) ||
           (!strcmp(escolha1, dict[1]) && !strcmp(escolha2, dict[0])) ||
           (!strcmp(escolha1, dict[0]) && !strcmp(escolha2, dict[3])) ||
           (!strcmp(escolha1, dict[3]) && !strcmp(escolha2, dict[4])) ||
           (!strcmp(escolha1, dict[4]) && !strcmp(escolha2, dict[2])) ||
           (!strcmp(escolha1, dict[2]) && !strcmp(escolha2, dict[3])) ||
           (!strcmp(escolha1, dict[3]) && !strcmp(escolha2, dict[1])) ||
           (!strcmp(escolha1, dict[1]) && !strcmp(escolha2, dict[4])) ||
           (!strcmp(escolha1, dict[4]) && !strcmp(escolha2, dict[0])) ||
           (!strcmp(escolha1, dict[0]) && !strcmp(escolha2, dict[2])))
    return 1; // Sheldon venceu
  else
    return 2; // Raj venceu
}

int main() {
  char escolha1[8], escolha2[8];
  scanf("%s %s", escolha1, escolha2);

  int resultado = determine_resultado(escolha1, escolha2);

  if (resultado == 0)
    printf("De novo!\n");
  else if (resultado == 1)
    printf("Bazinga!\n");
  else
    printf("Raj trapaceou!\n");

  return 0;
}
