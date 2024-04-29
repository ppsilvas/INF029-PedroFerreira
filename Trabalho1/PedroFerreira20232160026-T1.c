// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Pedro Paulo Silva Santana Ferreira
//  email: ppsilvasantana@gmail.com || 20232160026@ifba.edu.br
//  Matrícula:20232160026
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################
// gcc PedroFerreira20232160026.c corretor.c -o T1
#include <stdio.h>
#include "PedroFerreira20232160026.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <math.h>

#define base 10

int anoBissexto();
void converteAcentos();
int diaPorMes();
int convertDias();

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i; 

  for (i = 0; data[i] != '/'; i++){
    sDia[i] = data[i];	
  }
  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sDia[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }  


  int j = i + 1; //anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++){
    sMes[i] = data[j];
    i++;
  }

  if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
    sMes[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }


  j = j + 1; //anda 1 cada para pular a barra
  i = 0;

  for(; data[j] != '\0'; j++){
    sAno[i] = data[j];
    i++;
  }

  if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';  // coloca o barra zero no final
  }else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

  dq.valido = 1;

  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;
  DataQuebrada dataQuebrada;
  //quebrar a string data em strings sDia, sMes, sAno
  dataQuebrada = quebraData(data);

  //DataQuebrada dataQuebrada = quebraData(data);
  //if (dataQuebrada.valido == 0) return 0;
  if (dataQuebrada.valido == 0 ) {
    return 0;
  }else{
    if(anoBissexto(dataQuebrada)==1){
      switch(dataQuebrada.iMes){
        case 1:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 2:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>29) datavalida=0;
          break;
        case 3:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 4:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 5:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 6:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 7:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 8:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 9:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 10:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 11:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 12:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        default:
          return 0;
          break;
      }
    }else{
      switch(dataQuebrada.iMes){
        case 1:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 2:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>28) datavalida=0;
          break;
        case 3:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 4:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 5:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 6:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 7:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 8:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 9:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 10:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        case 11:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>30) datavalida=0;
          break;
        case 12:
          if(dataQuebrada.iDia<1 || dataQuebrada.iDia>31) datavalida=0;
          break;
        default:
          return 0;
          break;
      }
    }
  }
  //printf("%s\n", data);

  if (datavalida == 1){
    //printf("Data Valida ");
    return 1;
  }
  else{
    //printf("Data invalida ");
    return 0;
  }
}
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  //calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  DataQuebrada inicio = quebraData(datainicial);
  DataQuebrada fim = quebraData(datafinal);
  int qtdDias=0, qtdMeses=0, qtdAnos=0, totalDias;
  int resto=0;

  int bissextoInicio = anoBissexto(inicio), bissextoFim = anoBissexto(fim); 

  if (q1(datainicial) == 0){
    dma.retorno = 2;
    return dma;
  }else if (q1(datafinal) == 0){
    dma.retorno = 3;
    return dma;
  }else{
    //verifique se a data final não é menor que a data inicial
    if(inicio.iAno > fim.iAno){
      dma.retorno = 4;
      return dma;
    }else if(inicio.iAno == fim.iAno && inicio.iMes > fim.iMes){
      dma.retorno = 4;
      return dma;
    }else if(inicio.iAno == fim.iAno && inicio.iMes == fim.iMes && inicio.iDia > fim.iDia){
      dma.retorno = 4;
      return dma;
    }else{
      //calcule a distancia entre as datas
      qtdDias = fim.iDia - inicio.iDia;
      qtdMeses = fim.iMes - inicio.iMes;
      qtdAnos = fim.iAno - inicio.iAno;

      if(qtdAnos<=0){
        if(qtdMeses>0){
          if(qtdDias<0){
            qtdMeses =0;
            qtdDias = diaPorMes(inicio.iMes,bissextoFim)-inicio.iDia+fim.iDia;
          }
        }else{
          if(qtdDias<0){
            qtdDias = diaPorMes(inicio.iMes,bissextoFim)-inicio.iDia+fim.iDia;
          }
        }
      }else{
        if(qtdMeses>0){
          if(qtdDias<0){
            qtdMeses =0;
            qtdDias = diaPorMes(inicio.iMes,bissextoFim)-inicio.iDia+fim.iDia;
          }
        }else{
          if(qtdDias<0){
            totalDias = convertDias(bissextoFim, inicio, fim);
            resto = qtdAnos;
            if(totalDias%365!=0){
              qtdAnos = (totalDias/365)-1;
            }
            resto = (resto - qtdAnos)*365;
            if(resto%30!=0){
              qtdMeses = (resto/30)-1;
            }
            resto = (resto/30)-qtdMeses;
            qtdDias = resto*30;
          }
        }
      }
    }
    dma.qtdAnos = qtdAnos;
    dma.qtdMeses = qtdMeses;
    dma.qtdDias = qtdDias;
    //se tudo der certo
    dma.retorno = 1;
    return dma;

  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
int qtdOcorrencias = 0;
char aux[100];
char caractere;
//qtdOcorrencias = 1;
if(isCaseSensitive == 1){
  for(int i=0; texto[i]!='\0'; i++){
    if(texto[i] == c){
      qtdOcorrencias +=1;
    }
  }
}else if(isCaseSensitive!=1){
  for(int j=0; texto[j]!='\0'; j++){
    if(texto[j]>='A'  && texto[j]<='Z'){
      aux[j] = texto[j]; 
    }else if(texto[j]>='a'  && texto[j]<='z'){
      aux[j] = texto[j]-32;
    }else{
      aux[j] = texto[j];
    }
    if(texto[j+1]=='\0')
      aux[j+1]='\0';
  }

  if(c>='A'  && c<='Z'){
    caractere = c; 
  }else if(c>='a'  && c<='z'){
    caractere = c-32;
  }else{
    caractere = c;
  }

  for(int a=0; aux[a]!='\0'; a++){
    if(aux[a] == caractere){
      qtdOcorrencias +=1;
    }
  }
}else{
  qtdOcorrencias=0;
}

  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  wchar_t conversor[250];
  int ln = strlen(strTexto);
  int tam = ln+1;
  char aux[tam];
  strcpy(aux, strTexto);

  converteAcentos(conversor, aux, tam);

  int qtdOcorrencias = 0;
  int cont = 0;
  int i=0, j=0, k=0, l=0;

  for(i=0; conversor[i]!='\0'; i++){
    if(conversor[i]==strBusca[0]){
      for(j=i, l = 0; strBusca[l]!='\0'; j++, l++){
        if(conversor[j]==strBusca[l]){
          cont++;
        }else{
          do{
            cont -- ;
            j--;
          }while(j>i);
          break;
        }
      }
      if(j!=i){
        posicoes[k]=i+1;
        k++;
        posicoes[k]=j;
        k++;
        qtdOcorrencias++;
        i+=1;
      }
    }
  }

  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int aux = num;
  int cont = 0;
  int inverte = 0;
  int i,j;
  int expoente=1;

  while(aux>0){
    aux = aux/10;
    cont++;
  }

  int guarda[cont];

  for(i=0; i<cont; i++){
    guarda[i] = num%10;
    num=num/10;
  }

  for(i=0; i < cont; i++){
    for(j=i; j<cont-1; j++){
      expoente*=10;
    }
    inverte += guarda[i]*expoente;
    expoente=1;
  }

  num = inverte;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias=0;
  int cont1=0, cont2=0, cont3=0;
  int aux = numerobusca;
  int expoente=1;
  int help=0;
  while(aux>0){
    aux=aux/10;
    cont1++;
  }

  for(int i=0; i<cont1; i++){
    expoente*=10;
  }
  aux = numerobase;

  while(aux>0){
    aux = aux/10;
    cont2++;
  }
  aux = numerobase;

  while(aux>0){
    aux = aux/expoente;
    cont3++;
  }
  aux = numerobase;
  if(cont2%2==0){
    for(int i=0; i<cont3; i++){
      help = aux%expoente;
      aux = aux/expoente;
      if(help == numerobusca){
        qtdOcorrencias++;
      }
    }
  }else{
    for(int i=0; i<cont2; i++){
      help = aux%expoente;
      aux = aux/10;
      if(help == numerobusca){
        qtdOcorrencias++;
      }
    }
  }

  return qtdOcorrencias;
}

//Funções extras

int anoBissexto(DataQuebrada data){
    if(data.iAno%4==0){
      if(data.iAno%100!=0){
        return 1;
      }else if(data.iAno%400==0){
        return 1;
      }
    }
      return 0;
}

void converteAcentos (wchar_t *conversor, char *palavra, int tamanho){

  if(setlocale(LC_ALL,"")==NULL){
     printf("setlocale failed. \n"); 
  }
  mbstowcs(conversor, palavra, tamanho);

  for(int i=0; conversor[i]!='\0';i++){
    if(conversor[i] == L'á' || conversor[i] == L'à' || conversor[i] == L'ã' || conversor[i] == L'â' ||conversor[i] == L'ä'){
      conversor[i] = 'a';
    }else if(conversor[i] == L'Á' || conversor[i] == L'À' || conversor[i] == L'Ã' || conversor[i] == L'Â' || conversor[i] == L'Ä'){
      conversor[i] = 'A';
    }else if(conversor[i] == L'é' || conversor[i] == L'è' || conversor[i] == L'ê' || conversor[i] == L'ë'){
      conversor[i] = 'e';
    }else if(conversor[i] == L'É' || conversor[i] == L'È' || conversor[i] == L'Ê' || conversor[i] == L'Ë'){
      conversor[i] = 'E';
    }else if(conversor[i] == L'í' || conversor[i] == L'ì' || conversor[i] == L'î' || conversor[i] == L'ï'){
      conversor[i] = 'i';
    }else if(conversor[i] == L'Í' || conversor[i] == L'Ì' || conversor[i] == L'Î' || conversor[i] == L'Ï'){
      conversor[i] = 'I';
    }else if(conversor[i] == L'ó' || conversor[i] == L'ò' || conversor[i] == L'õ' || conversor[i] == L'ô' || conversor[i] == L'ö'){
      conversor[i] = 'o';
    }else if(conversor[i] == L'Ó' || conversor[i] == L'Ò' || conversor[i] == L'Õ' || conversor[i] == L'Ô' || conversor[i] == L'Ö'){
      conversor[i] = 'O';
    }else if(conversor[i] == L'ú' || conversor[i] == L'ù' || conversor[i] == L'û' || conversor[i] == L'ü'){
      conversor[i] = 'u';
    }else if(conversor[i] == L'Ú' || conversor[i] == L'Ù' || conversor[i] == L'Û' || conversor[i] == L'Ü'){
      conversor[i] = 'U';
    }
  }
}

int diaPorMes(int mes, int bissexto){
  int dias;

  switch(mes){
    case 1: dias = 31; break;
    case 2: 
      if(bissexto == 1){
        dias=29;
      }else{
        dias=28;
      }
      break;
    case 3: dias = 31; break;
    case 4: dias = 30; break;
    case 5: dias = 31; break;
    case 6: dias = 30; break;
    case 7: dias = 31; break;
    case 8: dias = 31; break;
    case 9: dias = 30; break;
    case 10: dias = 31; break;
    case 11: dias = 30; break;
    case 12: dias = 31;break;
    default:
      break;
  }

  return dias;
}

int convertDias(int bissexto, DataQuebrada inicio, DataQuebrada fim){
  int qtddias=0;
  int dia, mes, ano;
  int diames=0, diaano=0;

  dia = fim.iDia-inicio.iDia;
  mes = fim.iMes-inicio.iMes;
  ano = fim.iAno-inicio.iAno;

  if(dia<0){
    if(bissexto==1){
      diaano = ano*366;
      for(int i=0; i!=mes; i++){
        diames+= diaPorMes(inicio.iMes+i,bissexto);
      }
      qtddias = diaano+diames+dia;
    }else{
      qtddias = ano*365;
    }
  }
  return qtddias;
}