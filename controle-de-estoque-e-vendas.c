#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

struct produto{
	int codigo;
	char nome[50];
	double valorUnitario;
	int estoque;
};

struct produto produtos[200];
struct produto entrada;
int sequencia=0,nvendas=0;
double vendas[200];
FILE *arquivo;

cadastrarProduto(){
	int igual;
	char ok[5]={'0'};
	system("cls");
	produtos[sequencia].codigo=sequencia+1;
	entrada.codigo=produtos[sequencia].codigo;
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(produtos[sequencia].nome);
   	igual=strcmp(produtos[sequencia].nome,ok);
   	if(igual!=0){
	   	strcpy(entrada.nome,produtos[sequencia].nome);
		printf("\nDigite o valor unitario: ");
		scanf("%lf",&produtos[sequencia].valorUnitario);
		entrada.valorUnitario=produtos[sequencia].valorUnitario;
		fflush(stdin);
		printf("\nDigite a quantidade do estoque inicial: ");
		scanf("%d",&produtos[sequencia].estoque);
		entrada.estoque=produtos[sequencia].estoque;
		system("cls");
		printf("\nConfira o cadastro");
		printf("\ncodigo: %d",produtos[sequencia].codigo);
		printf("\nNome: %s",produtos[sequencia].nome);
		printf("\nValor unitario: %0.2lf",produtos[sequencia].valorUnitario);
		printf("\nEstoque: %d\n",produtos[sequencia].estoque);
		sequencia++;
		arquivo=fopen("produtos.txt","a");
		fprintf(arquivo,"codigo: %d nome: %s valor: %0.2lf estoque: %d"
		,entrada.codigo
		,entrada.nome
		,entrada.valorUnitario
		,entrada.estoque);
		fclose(arquivo);
	}else{
		printf("\nRetornando ao menu...\n");
		system("pause");
		return;
	}
	system("pause");
}

listarProdutosArquivo(){
	system("cls");
	FILE *leitura;
	char saida[150];
	leitura=fopen("produtos.txt","r");
	while(!feof(leitura)){
		fscanf(leitura,"%d %s %lf %d",&entrada.codigo,&entrada.nome,&entrada.valorUnitario,&entrada.estoque);
		printf("codigo: %d nome: %s- Valor: %0.2lf - Estoque: %d\n",entrada.codigo,entrada.nome,entrada.valorUnitario,entrada.estoque);
	}
	fclose(leitura);
	system("pause");
}

listarProdutosVetor(){
	system("cls");
	int x;
	if(produtos[0].codigo>0){
		for(x=0;x<sequencia;x++){
			printf("\n______________________________\n");
			printf("\ncodigo: %d",produtos[x].codigo);
			printf("\nNome: %s",produtos[x].nome);
			printf("\nValor unitario: %0.2lf",produtos[x].valorUnitario);
			printf("\nEstoque: %d\n",produtos[x].estoque);
		}
	}else{
		printf("\nNenhum produto cadastrado!\n");
	}
	system("pause");
}

listarVendas(){
	system("cls");
	int x;
	if(vendas[0]>0){
		for(x=0;x<nvendas;x++){
			printf("\n______________________________\n");
			printf("\nVenda: %d",x+1);
			printf("\nValor: %0.2lf\n",vendas[x]);
		}
	}else{
		printf("\nNenhuma venda encontrada!\n");
	}
	system("pause");
}

entradaEstoque(){
	system("cls");
	int codigo,x,estoque,achou=0;
	printf("\nDigite o codigo do produto para insercao de estoque: ");
	scanf("%d",&codigo);
	if(codigo!=0){
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\ncodigo: %d",produtos[x].codigo);
				printf("\nNome: %s",produtos[x].nome);
				printf("\nEstoque atual: %d\n\n",produtos[x].estoque);
				printf("\nDigite a quantidade de entrada em estoque: ");
				scanf("%d",&estoque);
				produtos[x].estoque+=estoque;
				printf("\nEstoque atualizado com sucesso!\n");
				printf("\nNovo valor do estoque: %d\n",produtos[x].estoque);
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
		if(achou==0){
			printf("\nProduto nao encontrado!\n");
		}
	}else{
		printf("\nRetornando ao menu...\n");
		system("pause");
		return;
	}
	system("pause");
}

ajusteEstoque(){
	system("cls");
	int codigo,x,estoque,achou=0;
	printf("\nDigite o codigo do produto para ajuste de estoque: ");
	scanf("%d",&codigo);
	if(codigo!=0){
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\ncodigo: %d",produtos[x].codigo);
				printf("\nNome: %s",produtos[x].nome);
				printf("\nEstoque atual: %d\n\n",produtos[x].estoque);
				printf("\nDigite a quantidade para ajuste em estoque: ");
				scanf("%d",&estoque);
				produtos[x].estoque=estoque;
				printf("\nEstoque ajustado com sucesso!\n");
				printf("\nNovo valor do estoque: %d\n",produtos[x].estoque);
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
		if(achou==0){
			printf("\nProduto nao encontrado!\n");
		}
	}else{
		printf("\nRetornando ao menu...\n");
		system("pause");
		return;
	}
	system("pause");
}

ajusteCadastro(){
	system("cls");
	int codigo,x,estoque,achou=0;
	printf("\nDigite o codigo do produto para atualizar o cadastro: ");
	scanf("%d",&codigo);
	if(codigo!=0){
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\ncodigo: %d",produtos[x].codigo);
				printf("\nNome: %s",produtos[x].nome);
				printf("\nValor: %0.2lf",produtos[x].valorUnitario);
				printf("\nDigite o nome do produto: ");
				fflush(stdin);
				gets(produtos[x].nome);
				printf("\nDigite o valor unitario: ");
				scanf("%lf",&produtos[x].valorUnitario);
				printf("\nDados atualizados com sucesso!\n");
				achou=1;
				break;
			}else{
				achou=0;
				printf("\nProduto nao encontrado!\n");
			}
		}
		printf("\nProduto nao encontrado!\n");
	}else{
		printf("\nRetornando ao menu...\n");
		system("pause");
		return;
	}
	system("pause");
}

buscarProduto(){
	system("cls");
	int x,codigo,achou=0;
	printf("\nDigite o codigo do produto que deseja: ");
	scanf("%d",&codigo);
	if(codigo!=0){
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\nCodigo: %d",produtos[x].codigo);
				printf("\nNome: %s",produtos[x].nome);
				printf("\nValor: %0.2lf",produtos[x].valorUnitario);
				printf("\nEstoque: %d\n",produtos[x].estoque);
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
		if(achou==0){
			printf("\nProduto nao encontrado!\n");	
		}
	}else{
		printf("\nRetornando ao menu...\n");
		system("pause");
		return;
	}
	system("pause");
}

venda(){
	system("cls");
	int codigo,x,qtde,continuar,achou=0;
	double subtotal,total;
	do{
		printf("\nDigite o codigo do produto: ");
		scanf("%d",&codigo);
		for(x=0;x<sequencia;x++){
			if(produtos[x].codigo==codigo){
				printf("\ncodigo: %d - Nome: %s - Valor unitario: %0.2lf"
				,produtos[x].codigo,produtos[x].nome,produtos[x].valorUnitario);
				achou=1;
				break;
			}else{
				achou=0;
			}
		}
		if(achou==0){
			printf("\nProduto nao encontrado!\n");
		}else{
			printf("\nDigite a quantidade: ");
			scanf("%d",&qtde);
			if(produtos[x].estoque>0 && qtde<=produtos[x].estoque){
				produtos[x].estoque-=qtde;
				subtotal=qtde*produtos[x].valorUnitario;
				total+=subtotal;
			}else{
				printf("\nSem produto em estoque!\n");
				system("pause");
			return;
			}
		}
		printf("\nDeseja inserir mais algum produto? 1-sim 2-nao:  ");
		scanf("%d",&continuar);
	}while(continuar!=2);
	if(achou!=0){
		printf("\nO total da compra foi de %0.2lf\n",total);
		printf("\nForma de pagamento: ");
		printf("\n1-dinheiro 2-crédito: ");
		int pag;
		scanf("%d",&pag);
		if(pag==1){
			printf("\nPagamento em dinheiro, valor: R$%0.2lf\n",total);
		}else if(pag==2){
			total=total*1.03;
			printf("\nPagamento em cartão, valor total com acrescimo de 3%%: R$%0.2lf\n",total);
		}else{
			printf("\nForma de pagamento invalida!");
		}
		vendas[nvendas]=total;
		nvendas++;
		system("pause");
	}
}

main(){
	setlocale(LC_ALL, "Portuguese");
	int x;
	do{
		system("cls");
		printf("\nDigite 1 para cadastrar um produto");
		printf("\nDigite 2 para dar entrada em estoque");
		printf("\nDigite 3 para ajustar um estoque");
		printf("\nDigite 4 para ajustar o cadastro");
		printf("\nDigite 5 para listar todos os produtos");
		printf("\nDigite 6 para buscar um produto por codigo");
		printf("\nDigite 7 para realizar uma venda");
		printf("\nDigite 8 para listar vendas");
		printf("\nDigite sua opcao: ");
		scanf("%d",&x);
		switch(x){
			case 1:
				cadastrarProduto();
			break;
			case 2:
				entradaEstoque();
			break;
			case 3:
				ajusteEstoque();
			break;
			case 4:
				ajusteCadastro();
			break;
			case 5:
				system("cls");
				printf("\nDigite 1 para leitura de arquivo");
				printf("\nDigite 2 para leitura do vetor: ");
				int op;
				scanf("%i",&op);
				switch(op){
					case 1:
						listarProdutosArquivo();
					break;
					case 2:
						listarProdutosVetor();
					break;
					default:
						printf("Opcao invalida!");
				}	
			break;
			case 6:
				buscarProduto();
			break;
			case 7:
				venda();
			break;
			case 8:
				listarVendas();
			break;
			default:
				printf("\nopcao invalida!\n");
		}
	}while(x!=0);
	return 0;
}
