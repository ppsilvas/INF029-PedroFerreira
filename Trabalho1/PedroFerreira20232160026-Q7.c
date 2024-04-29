// gcc PedroFerreira20232160026-Q7.c -o JogoVelha ./JogoVelha
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX 5
#define tam 3

void imprimirJogo();
bool jogadas(char matriz[][tam], char linha, char coluna, int contador);
int valoresLinha(char l);
int valoresColunas(char c);
int vitorioso();

int main(){
  char matriz[tam][tam];
  char linha, coluna;
  char linhas[tam] = {'A','B','C'}, colunas[tam]={'1','2','3'};
  int contador = 0;
  int resultado;
  int jogador;
  int valido = false;

  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      matriz[i][j] = ' ';
    }
  }

  imprimirJogo(matriz, colunas, linhas);

  for(contador = 0; contador<9; contador++, valido=false){
    while(valido == false){
      if(contador%2==0){
        jogador = 1;
        printf("Jogador %d informe a linha: ", jogador);
        scanf("%c",&linha);
        getchar();
        printf("Jogador %d informe a coluna: ", jogador);
        scanf("%c",&coluna);
        getchar();
        valido = jogadas(matriz, linha, coluna, jogador);
      }else{
        jogador = 2;
        printf("Jogador %d informe a linha: ", jogador);
        scanf("%c",&linha);
        getchar();
        printf("Jogador %d informe a coluna: ", jogador);
        scanf("%c",&coluna);
        getchar();
        valido = jogadas(matriz, linha, coluna, jogador);
      }
    }
    imprimirJogo(matriz, colunas, linhas);
    resultado = vitorioso(matriz);
    if (resultado == 1){
      if(contador%2==0){
        printf("Jogador 1 venceu!");
        break;
      }else{
        printf("Jogador 2 venceu!");
        break;
      }
    }
    if(contador>6){
      printf("Deu velha!\n");
      break;
    }
  }
  return EXIT_SUCCESS;
}

void imprimirJogo(char matriz[][tam], char * colunas, char * linhas){
  for(int i = 0; i<3;i++){
    printf("  %c ", colunas[i]);
  }
  printf("\n");
  for(int i=0; i<tam; i++){
    printf("%c ",linhas[i]);
    for(int j=0; j<tam; j++){
      printf("[%c]",matriz[i][j]);
    }
    printf("\n");
  }
}

bool jogadas(char matriz[][tam], char linha, char coluna, int jogador){
  int l, c;
  l = valoresLinha(linha);
  c = valoresColunas(coluna);
  if(l==4||c==4){
    printf("Posicao invalida!");
    return false;
  }
  if(jogador==1){
    if(matriz[l][c]==' '){
      matriz[l][c]='X';
      return true;
    }else{
      printf("Posicao ja ocupada!");
    }
  }else{
    if(matriz[l][c]==' '){
      matriz[l][c]='0';
      return true;
    }else{
      printf("Posicao ja ocupada!");
    }
  }

  return false;
}

int valoresLinha(char l){
  switch(l){
    case 'a':
    case 'A':
      return 0;
      break;
    case 'b':
    case 'B':
      return  1;
      break;
    case 'c':
    case 'C':
      return 2;
      break;
    default:
      return 4;
      break;
  }
}

int valoresColunas(char c){
  switch(c){
    case '1':
      return 0;
      break;
    case '2':
      return 1;
      break;
    case '3':
      return 2;
      break;
    default:
      return 4;
      break;
  }
}

int vitorioso(char matriz[][tam]){
  if((matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != ' ')||
     (matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != ' ')||
     (matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != ' ')||
     (matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != ' ')||
     (matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != ' ')||
     (matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != ' ')||
     (matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != ' ')||
     (matriz[2][0] == matriz[1][1] && matriz[2][0] == matriz[0][2] && matriz[2][0] != ' ')){
    return 1;
  }
  return 0;
}
