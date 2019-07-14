#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<locale.h>
#include<stdbool.h>
#define MAX 5

void imprime_vetor(int *vetor,int inicio,int fim);
void imprime_vetor_por_tamanho(int *vetor,int tam);
void preenche_aleatoriamente(int *vetor5,int tam);
void preenche_decrescente(int *vetor3,int tam);
void preenche_crescente(int *vetor,int tam);
void selection_sort(int *vetor,int size,int *trocas ,int *comparacoes);
void insertion_sort(int *vetor,int size,int *trocas ,int *comparacoes);
void shell_sort(int *vetor,int size,int *trocas,int *comparacoes);
void bubble_sort(int *vetor,int size,int *trocas,int *comparacoes);
void hadix_sort (int *vetor,int size,int *trocas,int *comparacoes);
void quick_sort(int *vetor,int inicio,int fim);
void heap_sort(int *vetor,int tam,int *vet_aux);
void merge_sort(int *vetor,int inicio,int fim);

//Criado para ordenação de palavras
//Estruturas
struct potes_de_palavras;
struct lista_de_palavras;
struct palavra;

//Funções para hadix sort com palavras
bool cria_palavras(struct lista_de_palavras *lista);
bool le_palavra(struct palavra *p);
bool valida_palavra(char *word);
bool verifica_letra(char letra);
struct lista_de_palavras *cria_lista();
void remove_divergencias(struct potes_de_palavras *p);
void zeraPotes(struct potes_de_palavras *p);
void retiraDosPotes(struct potes_de_palavras *potes,struct lista_de_palavras *l);
void imprime_palavras(struct lista_de_palavras *palavras_digitadas);
void preenche_potes(struct potes_de_palavras *potes);
void hadix_palavras(struct lista_de_palavras *lista,struct potes_de_palavras *potes);
int maiorPalavra(struct lista_de_palavras *l);
int ColocarQualPote(struct palavra *p,int posicao);
void preenche_potes(struct potes_de_palavras *potes);
