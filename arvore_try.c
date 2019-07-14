#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<locale.h>
typedef struct fim{
	int fim;
}no_fim;
typedef struct nos{
	char letras;
	int pos;
	no_fim fim[26];
	struct nos *no_filhos[26];
}no;

typedef struct raiz{
	no *filho;
}elem_raiz;

int posicao(char letra){
	int i;
	char vetor[26]={"abcdefghijklmnopqrstuvwxyz"};
	for(i=0;i<26;i++){
		if(letra==vetor[i]){
			return i;
		}
	}
}
insereRestante(no *FilhoParaInserir,char *palavra,int pos){
	int i;
	if(pos>=strlen(palavra)){
		return;
	}
	int posInserir = posicao(palavra[pos]);
	no *filho=(no*)malloc(sizeof(no));
	if(filho != NULL){
		for(i=0;i<26;i++){
			filho->no_filhos[i]=NULL;
		}
	}
	if(pos>=strlen(palavra)){
		return;
	}
	if(filho != NULL){
		filho->letras=palavra[pos];
		filho->pos=posInserir;
		FilhoParaInserir->no_filhos[posInserir]=filho;
		if(pos+1>=strlen(palavra)){
			FilhoParaInserir->fim[posInserir].fim=1;
			return;
		}
		insereRestante(FilhoParaInserir->no_filhos[posInserir],palavra,pos+=1);
	}
	return;
}
insere_na_arvore(no *primeiroFilho,char *palavra,int posInicio){
	int i;
	if(posInicio>=strlen(palavra)){
		return;
	}
	int pos = posicao(palavra[posInicio]);
	if(primeiroFilho->no_filhos[pos] == NULL){
		if(primeiroFilho->letras=='-'){
			if(posInicio>=strlen(palavra)){
				return;
			}
			no *filho=(no*)malloc(sizeof(no));
			if(filho != NULL){
				for(i=0;i<26;i++){
					filho->no_filhos[i]=NULL;
				}
			}
			if(filho != NULL){
				filho->letras=palavra[0];
				filho->pos=pos;
				primeiroFilho->no_filhos[pos]=filho;
				if(posInicio+1>=strlen(palavra)){
					filho->fim[pos].fim=1;
					return;
				}
				insereRestante(filho,palavra,1);
				return;
			}
		}else{
			insereRestante(primeiroFilho,palavra,posInicio);
			return;
		}
	}
	
	if(posInicio+1>=strlen(palavra)){
		primeiroFilho->fim[pos].fim=1;
		return;
	}
	insere_na_arvore(primeiroFilho->no_filhos[pos],palavra,posInicio+=1);
	return;
}
inserir_palavra(elem_raiz *r){
	char word[100];
	if(r->filho == NULL){
		printf("Não é possível inserir.\n");
		return;
	}
	printf("Digite a palavra.\n");
	fflush(stdin);
	gets(word);	
	strcpy(word,strlwr(word));
	insere_na_arvore(r->filho,word,0);
	return;
}
busca_palavra(char *palavra,no *n,int inicio){
	int i;
	int pos=posicao(palavra[inicio]);
	if(n->no_filhos[pos] == NULL){
		printf("Palavra não encotrada.\n");
		return;
	}
	if(inicio+1>=strlen(palavra)){
		if(n->fim[pos].fim==1){
			printf("%s\n",palavra);
			printf("Palvra encontrada.\n");
			return;
		}
		printf("Palavra não encontrada.\n");
		return;
	}
	busca_palavra(palavra,n->no_filhos[pos],inicio+=1);
}
imprime_arvore_trie(no *n){
	int i;
	if(n == NULL){
		return;
	}
	printf("%c",n->letras);
	if(n->fim[0].fim==1){
		printf("\n");
	}
	for(i=0;i<26;i++){
		imprime_arvore_trie(n->no_filhos[i]);	
	}
	printf("\n");
	return;
}
int main(){
	char palavra[100];
	setlocale(LC_ALL,"portuguese");
	int op;
	int i;
	elem_raiz *r;
	r=(elem_raiz*) malloc (sizeof(elem_raiz));
	no *novo=(no*) malloc (sizeof(no));
	if(novo != NULL){
		for(i=0;i<26;i++){
			novo->no_filhos[i]=NULL;
		}
	}
	novo->letras='-';
	r->filho=novo;
	printf("Bem vindo.\n");
	printf("Vamos iniciar.\n");
	do{
		printf("O que deseja fazer ?.\n");
		printf("1 - Para inserir uma palavra.\n");
		printf("2 - Para imprimir a árvore.\n");
		printf("3 - Para saber se há uma palavra na árvore.\n");
		printf("0 - Para sair.\n");
		fflush(stdin);
		scanf("%d",&op);
		switch(op){
			case 0:
				printf("Até a próxima!\n");
				exit;
			break;
			case 1:
				inserir_palavra(r);
			break;
			case 2:
				for(i=0;i<26;i++){
					imprime_arvore_trie(r->filho->no_filhos[i]);	
				}
			break;
			case 3:
				printf("Digite a palavra que você deseja buscar.\n");
				fflush(stdin);
				gets(palavra);
				busca_palavra(palavra,r->filho,0);
			break;
			default:
				printf("Opção Inválida.\n");
			break;
		}		
	}
	while(op!=0);
}
