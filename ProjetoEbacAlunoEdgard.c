#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar os strings

int registro()//Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio cria��o da vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final cria��o da vari�veis/string 
	
	printf("Digite o CPF a ser cadastrado: ");//Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy (arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file;//Cria o arquivo no banco de dados
	file = fopen(arquivo, "w");//Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);//Salvo o valor da variavel
	fclose(file);//FECHA O ARQUIVO, MUITO IMPORTANTE.
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o foi localizado.\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL);
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	}
	

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL);
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");		
	}
	
	if(file != NULL);
	{
		printf("\nUsu�rio deletado com sucesso!\n");
		system("pause");
	}
	
}
int main()//Definindo Vari�veis

	{  	  
	int opcao=0;//Defininddo as vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)	
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
		printf("\t#### Cart�rio da EBAC ####\n\n");//Inicio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o:");//Fim do menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usu�rio	
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)//Inicio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			system("pause");
			break;
			
			case 2:
			consulta();
			system("pause");
			break;
			
			case 3:
			deletar();
		    system("pause");
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;//Fim da sele��o
		}
		
	}	
 }


