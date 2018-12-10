/***************************************************************

Trabalho de Grafos

Verifica se o grafo 1 da lista é Euleriano ou Semi-Euleriano,
partindo do princípio de que é um grafo conexo.



******************************************************************/


# include <stdio.h>
# include <stdlib.h>
# define MAX 50 

void main (){

	FILE *arq;
	char *arquivo = "entrada.txt";
	int i, j, arestas, vertices, aux;
	int grafo[MAX+1][MAX+1];
	int grau[MAX+1];
	i = 0;
    j = 0;

// Inicializacao das matrizes com -1
    for(j=0; j<=MAX; j++)
	   for(i=0; i<=MAX; i++){
	   		grafo[j][i] = -1;
	   }

	for (i = 0; i<=MAX; i++){
		grau[i] = 0;
	}

    arq = fopen(arquivo, "r");
     
    fscanf(arq, "%i", &vertices);
    fscanf(arq, "%i", &arestas);

// Tratamento da entrada
    if(vertices > MAX){
		printf("\nO numero de vertices deve ser <= %i\n", MAX);
		exit(1);
    }

// Inicializacão da matriz
    for(i=0; i<=vertices; i++)
	   for (j=0; j<=vertices; j++){
	   		grafo[i][j] = 0;
	   }
       aux = arestas;
       i = 0;
       j = 0;

// Colocando as arestas na matriz
    while (aux > 0){
		fscanf(arq, "%i", &i);
	 	fscanf(arq, "%i", &j);
	 	grafo[i][j] = 1;
	 	grafo[j][i] = 1;
	 	aux--;
    }

// Calculando o grau dos vertices
    for (i = 1; i<=MAX; i++)
		for(j = 0; j<=MAX; j++){
	   		if (grafo[i][j] == 1)
	    	grau[i]++;
	  	}

// Verificando a quantidade de vertices com grau impar
    j = 2; aux = 0;
    for(i = 1; i<=MAX; i++){
		if(grau[i]%j != 0){
	   		aux++;
	   		grau[i] = -1;
	  	}
    }


// Classificação do grafo
	if (aux == 0){
	 	printf("\nTodos os vertices possuem grau par, portanto o grafo é Euleriano.");
	}
	else{
	    if (aux == 2){
	    	printf("\nExistem 2 vertices com grau impar, portanto o grafo é Semi-Euleriano.");
	    }
	    else{
	      	printf("\nExiste(m) %i vertice(s) com grau impar, portanto ", aux);
	      	printf("o grafo não é Euleriano e nem Semi-Euleriano");
	    }
	}
		printf("\n");
}