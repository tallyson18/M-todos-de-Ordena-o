#include "metodos-de-ordenacao.h"
//Função para preencher um vetor em ordem crescente
void preenche_crescente(int *vetor,int tam){
	int i;
	for(i=0;i<tam;i++){
		vetor[i]=i;
	}
}
//Função para preencher um vetor em ordem decrescente
void preenche_decrescente(int *vetor3,int tam){
	int i,j=0;
	for(i=tam-1;i>=0;i--){
		vetor3[j]=i;
		j++;
	}
}
//Função para preencher um vetor em aleatoriamente
void preenche_aleatoriamente(int *vetor5,int tam){
	int i,j;
	for(i=0;i<tam;i++){
		j=rand()%tam;
		vetor5[i]=j;
	}
}

//Função para imprimir um vetor
void imprime_vetor(int *vetor,int inicio,int fim){
	int i;
	for(i=inicio;i<fim;i++){
		printf("%d,",vetor[i]);
	}
	printf("\n\n");
}
//Função para imprimir um vetor com base no tamanho
void imprime_vetor_por_tamanho(int *vetor,int tam){
	int i;
	for(i=0;i<tam;i++){
		printf("%d,",vetor[i]);
	}
	printf("\n\n");
}

//Algotirmo de seleção
void selection_sort(int *vetor,int size,int *trocas,int *comparacoes){
	int i,j,menor;
	for(i=0;i<size;i++){
		menor=vetor[i];
		for(j=i+1;j<size;j++){
			if(vetor[j]<menor){
				vetor[i]=vetor[j];
				vetor[j]=menor;
				menor=vetor[i];
				*trocas+=1;
			}
			*comparacoes+=1;
		}
	}
}

//Algotirmo de inserção
void insertion_sort(int *vetor,int size,int *trocas,int *comparacoes){
	int i,j,aux;
	for(i=0;i<size-1;i++){
		j=i;
		while(j>=0){
			*comparacoes+=1;
			if(vetor[j+1]<vetor[j]){
				aux=vetor[j];
				vetor[j]=vetor[j+1];
				vetor[j+1]=aux;
				*trocas+=1;
			}else{
				break;
			}
			j--;
		}
	}
	
}

//Algotirmo Shell
void shell_sort(int *vetor,int size,int *trocas,int *comparacoes){
	int k,i,aux;
	k=0;
	if(size>4){
		while(k<size-1){
			k+=3*k+1;
		}
	}else{
		k=1;
	}
	while(k>0){
		for(i=0;i<size;i++){
			if(k==1){
				insertion_sort(vetor,size,trocas,comparacoes);
				return;
			}else {
				if(i+k<size){
					if(vetor[i+k]<vetor[i]){
						*comparacoes+=1;
						aux=vetor[i];
						vetor[i]=vetor[i+k];
						vetor[i+k]=aux;
						*trocas+=1;
					}
					*comparacoes+=1;
				}else{
					break;
				}
			}
		}
		k=(k-1)/3;
	}
}

//Algotirmo de Bolha
void bubble_sort(int *vetor,int size,int *trocas,int *comparacoes){
	int i,size_aux=size-1,aux,quatidade_de_trocas=0,j;
	for(j=0;j<size_aux;size_aux--){
		quatidade_de_trocas=0;
		for(i=0;i<size_aux;i++){
			*comparacoes+=1;
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
				vetor[i]=vetor[i+1];
				vetor[i+1]=aux;
				*trocas+=1;
				quatidade_de_trocas++;
			}
		}
		if(quatidade_de_trocas==0){
			return;
		}
	}
}



//Estrutura de um pote para numeros
typedef struct pote{
	int numero;
	int total;
	int vetor[MAX];
}pote;

//Algotirmo Hadix aplcicado a ordenação de vetor de números
void hadix_sort (int *vetor,int size,int *trocas,int *comparacoes){
	pote potes[10];
	int i,quantidadeDigitos=0,dividendo=1,retorno=size;
	int parametro=1,qualPote;
	for(i=0;i<10;i++){
		potes[i].numero=i;
		potes[i].total=0;
	}
	while(retorno>=1){
		retorno=retorno/dividendo;
		dividendo*=10;
		quantidadeDigitos++;
	}
	while(parametro-1<=quantidadeDigitos){
		for(i=0;i<size;i++){
			qualPote=retornaDigito(vetor[i],parametro);
			insereNoPote(potes,vetor[i],qualPote);
		}
		ordenaPote(potes,vetor);
		parametro++;
	}
}

//Ordenar um pote númérico
int ordenaPote(pote *p,int *vetor){
	int i,j=0,k=0;
	for(i=0;i<10;i++){
		k=0;
		while(p[i].total>0){
			vetor[j]=p[i].vetor[k];
			p[i].total-=1;
			j++;
			k++;
		}
	}
}

//Retorna qual pote deve ser inserido os elementos
insereNoPote(pote *p,int num,int qualPote){
	p[qualPote].vetor[p[qualPote].total]=num;
	p[qualPote].total+=1;
}

//Retorna o dígito que está sendo analisado com base na interação
int retornaDigito(int numero, int digito){
	int i;
	int retorno = 0;
	int mod = 1;
	int dividendo = 1;
	for(i = 1 ; i<=digito ; i++){
		mod = mod*10;
	}
	dividendo = mod/10;
	retorno = numero%mod;
	retorno = retorno / dividendo;
	return retorno;
}


//Algotirmo Hadix para palavras

//Estrutura de uma palavra
typedef struct palavra{
	struct palavra *atras;
	char palavra[];
}palavra;

//Estrutura de uma lista de palavras
typedef struct lista_de_palavras{
	palavra *primeiro;
	palavra *ultimo;
}lista_de_palavras;

//Estrutura dos potes de palavras
typedef struct potes_de_palavras{
	char letra;
	int total;
	lista_de_palavras *palavras; 
}potes_de_palavras;

//Verificar se letra é permitida
bool verifica_letra(char letra){
	int i;
	for(i=61;i<123;i++){
		if(letra==i){
			return true;
		}
	}
	return false;
}

//Verificar se todos os caracteres de uma palavra estão de acordo com o permitido
bool valida_palavra(char *word){
	int i;
	for(i=0;i<strlen(word);i++){
		if(!verifica_letra(word[i])){
			return false;
		}
	}
	return true;
}

//Fazendo leitura e Inserção ou Não de palavra na lista
bool le_palavra(palavra *p){
	char word[100];
	bool ret;
	if(p!=NULL){
		do{
			printf("Digite a palavra.\n");
			fflush(stdin);
			gets(word);
			
			//Realizando a conversão de caracteres maiúsculos em minúsculos
			strcpy(word,strlwr(word));
			
			//Valiando a palavra antes de inseri-la na lista
			if(!valida_palavra(word)){
				printf("Digite uma palavra válida.\n");
				ret=false;
			}else{
				//Inserindo palavra na estrutura dela
				strcpy(p->palavra,word);
				ret=true;
			}
		}
		while(ret==false);
	}
	return ret;
}
//Criando uma palavra
bool cria_palavras(lista_de_palavras *lista){
	
	palavra *p = (palavra *) malloc(sizeof(palavra));
	
	if(p==NULL){
		
		printf("Não foi possível inserir outra palavra.\n");
		return false;
	}
	if(!le_palavra(p)){
		
		printf("Palavra inválida.\n");
		return false;
	}
	//Inserindo palavra na lista caso esta seja permitida
	if(lista->primeiro==NULL){
		lista->primeiro=p;
		lista->ultimo=p;
	}else{
		lista->ultimo->atras=p;
		lista->ultimo=p;
	}
}

//Criando uma lista de palavras
lista_de_palavras *cria_lista(){
	lista_de_palavras *l=(lista_de_palavras*) malloc (sizeof(lista_de_palavras));
	if(l!=NULL){
		l->primeiro=NULL;
		l->ultimo=NULL;
		return l;
	}
	printf("Não foi possível criar a lista para armazenar palavras.\n");
	return NULL;
}

//Retirar informações de endereço de variáveis que estão em outros potes no ultimo elemento da lista
void remove_divergencias(potes_de_palavras *p){
	int i;
	for(i=0;i<26;i++){
		if(p[i].palavras->ultimo != NULL){
			p[i].palavras->ultimo->atras=NULL;
		}
	}
}

//Reiniciar a lista de palavras de cada pote como vazias
void zeraPotes(potes_de_palavras *p){
	int i;
	for(i=0;i<26;i++){
		p[i].palavras->primeiro=NULL;
		p[i].palavras->ultimo=NULL;
	}
}


//Retirando elementos dos potes e inserindo em ordem na lista
void retiraDosPotes(potes_de_palavras *potes,lista_de_palavras *l){
	
	//auxiliares
	palavra *aux,*aux2;
	
	//reiniciando a lista de elementos
	l->primeiro=NULL;
	l->ultimo=NULL;
	
	//controle
	int i=0;
	
	while(i<26){
		
		//Caso haja alguma palavra naquele pote
		if(potes[i].palavras->primeiro  !=NULL){
			
			//Recebe todos os elementos daquele pote
			aux=potes[i].palavras->primeiro;
			
			while(aux != NULL){
				
				//Verifica se a lista ainda está vezia
				if(l->primeiro==NULL){
					l->primeiro=aux;
					l->ultimo=aux;
				}else{
					//Caso não insere o elemento na sequência
					l->ultimo->atras=aux;
					l->ultimo=aux;
				}
				//Indo para próxima palavra salva naquele pote
				aux=aux->atras;
			}
		}
		i++;
	}
	
	//Imprime a lista ao fim de cada interação
	printf("Lista ao fim desta interação :\n");
	imprime_palavras(l);
	printf("\n");
}

//Recebe uma lista de palavras
void imprime_palavras(lista_de_palavras* palavras_digitadas){
	if(palavras_digitadas->primeiro==NULL){
		printf("Primeiro insira palavras na lista.\n");
		return;
	}
	//Auiliares
	palavra *x=palavras_digitadas->primeiro;
	
	while(x !=NULL){
		printf("%s.\n",x->palavra);
		x=x->atras;
	}
}
// Insere nos potes um caracter para representar a letra que este contém e cria uma lista de palavras que podem ser ali armazenadas
void preenche_potes(potes_de_palavras *potes){
	int i,j=0;
	for(i=97;i<123;i++){
		potes[j].letra=i;
		potes[j].total=0;
		potes[j].palavras=cria_lista();
		j++;
	}
}

//Funcção para retornar em qual pote a palavra deve ser inserida considerando a posição da letra que está sendo analisada.
int ColocarQualPote(palavra *p,int posicao){
	int tamanho=strlen(p->palavra),j=0,i;
	char letra;
	tamanho-=1;
	//caso a palavra seja menor que o dígito que se está buscando é retorando a primeira letra da palvra
	if(posicao > tamanho){
		return 0;
	}else{
		//retorna a letra daquela posição
		letra=p->palavra[posicao];
	}
	
	// Verificar em qual pote está sendo guardado as palavras com a letra analisada 
	for(i=97;i<123;i++){
		if(letra==i){
			return j;
		}
		j++;
	}
}

//Busca o tamanho da maior palavra inserida para verificar quantas vezes o sistema deverá aplicar o algoritmo
int maiorPalavra(lista_de_palavras *l){
	palavra *x=l->primeiro;
	int tamanho=0;
	tamanho=strlen(x->palavra);
	while(x !=NULL){
		if(strlen(x->palavra)>tamanho){
			tamanho=strlen(x->palavra);
		}
		x=x->atras;
	}
	return tamanho;
}

//Método de ordenação aplicado em palavras criadas em forma de lista 
//recebe uma lista de palavras e os potes
void hadix_palavras(lista_de_palavras *lista,potes_de_palavras *potes){
	if(lista->primeiro==NULL){
		printf("Primeiro insira palavras na lista.\n");
		return;
	}
	
	// cria um auxiliar para ir recebendo as palavras
	palavra *aux=lista->primeiro,*aux2;
	
	//variaveis auxiliares
	int i=0,num_pote,quantidade=0,contador=0;
	
	//busca quantas vezes será necessário realizar as interações
	quantidade=maiorPalavra(lista);
	i=quantidade-1;
	printf("Será realizado %d interações.\n",quantidade);
	
	while(contador<quantidade){
		while(aux !=NULL){
			
			//recupera a posicao no vetor de potes em que a plavra atual deve ser inserida
			num_pote=ColocarQualPote(aux,i);
			
			//printf("Colocar no pote %d que tem a letra %c, por que a palavra %s na posicao %d.\n",num_pote,potes[num_pote].letra,aux->palavra,i);
			
			//caso já tenha palavras no pote
			if(potes[num_pote].palavras->primeiro !=NULL){
				potes[num_pote].palavras->ultimo->atras=aux;
				potes[num_pote].palavras->ultimo=aux;
			}else{
				//caso seja  a primeira palavra inserida naquele pote
				potes[num_pote].palavras->primeiro=aux;
				potes[num_pote].palavras->ultimo=aux;
			}
			//indo para a próxima palavra
			aux=aux->atras;
		}
		
		//retirar referências errôneas de últimas palavras
		remove_divergencias(potes);
		
		//retirar palavras do pote e inseri-las na lista
		retiraDosPotes(potes,lista);
		
		//colocar novamente todos os potes sem elementos
		zeraPotes(potes);
		
		//reiniciando o auxiliar para a próxima interação com base na nova organização da lista
		aux=lista->primeiro;
		contador++;
		i--;
	}
}




//Função para imprimir um vetor
void imprime_vetor_q(int *vetor,int inicio,int fim){
	int i;
	for(i=inicio;i<=fim-1;i++){
		printf("%d,",vetor[i]);
	}
	printf("\n\n");
}

// Quick Sort
void quick_sort(int *vetor,int inicio,int fim){
	if(fim<inicio){
		return;
	}
	int i,j=inicio,pivo,controle=0,atual=1,aux;
	pivo=vetor[inicio];
	i=fim+1;
	while(i != j ){
		if(atual==1){
			i--;
			if(vetor[i]<pivo){
				aux=vetor[i];
				vetor[i]=vetor[j];
				vetor[j]=aux;
				atual=0;
			}
		}else{
			j++;
			if(vetor[j]>pivo){
				aux=vetor[j];
				vetor[j]=vetor[i];
				vetor[i]=aux;
				atual=1;
			}
		}
	}
	quick_sort(vetor,inicio,i-1);
	quick_sort(vetor,i+1,fim);
}

// Heap Sort
void heap_sort(int *vetor,int tam,int *vet_aux){
	int i,aux;
	while(tam>0){
		for(i=tam-1;i>=0;i--){
			if(vetor[(i-1)/2]<vetor[i]){
				aux=vetor[i];
				vetor[i]=vetor[(i-1)/2];
				vetor[(i-1)/2]=aux;
			}
		}
		vet_aux[tam-1]=vetor[0];
		vetor[0]=vetor[tam-1];
		tam--;
	}
}

//Merge Sort
void merge_sort(int *vetor,int inicio,int fim){
	int i,j,k,cont,*vetor_aux,meio;
	if(inicio<fim-1){
		meio=(inicio+fim+1)/2;
		merge_sort(vetor,inicio,meio);
		merge_sort(vetor,meio,fim);
		vetor_aux=(int *)malloc(sizeof(fim-inicio));
		j=inicio;
		k=meio;
		for(i=0;i<fim-inicio;i++){
			if(k>=fim){
				vetor_aux[i]=vetor[j];
				j++;
			}
			else if(vetor[j]>vetor[k] || j>=meio){
				vetor_aux[i]=vetor[k];
				k++;
			}else{
				vetor_aux[i]=vetor[j];
				j++;
			}
		}
		j=0;
		for(i=inicio;i<fim;i++){
			vetor[i]=vetor_aux[j];
			j++;
		}
		free(vetor_aux);
	}
	
}
