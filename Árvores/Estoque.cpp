#include <stdio.h>

int main (){
	int estoque[5][5]= {{150,0,100,150,200}, {200,300,230,100,90}, {250,300,0,200,150}, {300,100,90,450,0},{350,300,400,250,200}};
	int l = 0, c = 0, qtd = 0;

	while(l != -1){
		printf("\nDigite a linha e coluna correspondentes ao produto:\n");
		printf("Linha:");
		scanf("%d", &l);
		if(l == -1){
			return 0;
		}
		printf("Coluna:");
		scanf("%d", &c);
	
		printf("Digite a quantidade a ser retirada:\n");
		printf("Quantidade:");
		scanf("%d", &qtd);
	
		if(estoque[l][c] <= qtd){
			printf("Estoque com quantidade insuficiente para atender ao pedido.");
		} else {
			estoque[l][c] = estoque[l][c] - qtd;
			printf("Novo estoque do produto na linha %d e coluna %d: %d", l, c, estoque[l][c]);
		}
	}
	
	return 0;
}
