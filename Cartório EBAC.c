#include<stdio.h> //biblioteca de comunica��o com o usu�rio
#include<stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include<locale.h> //biblioteca de aloca�ao de texto por regi�o
#include<string.h> //biblioteca respons�vel por cuidar das strings


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema.
{
	// In�cio cria��o de vari�veis/ strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria�a� da vari�veis.
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio.
	scanf("%s", cpf); //%s refere-se a string.
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever.
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Atualizar o arquivo o "a" significa atualizar.
	fprintf(file,", "); // Para fazer uma separa��o entre as informa��es.
	fclose(file);
	
	//In�cio do cadastro do usu�rio.
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,".");
	fclose(file);
	
	// Fim do cadastro do usu�rio.
	
	system("pause");
}

int consultar() //Fun��o respons�vel pela consulta dos usu�rios ao sistema.
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200]; // Reserva de aloca��o na mem�ria.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // L� o arquivo, a letra r significa ler. 
	
	if(file == NULL) // Caso a op��o desejada n�o existir mostrar a mensagem abaixo.
	{
	
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");
		system("pause");
	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
		fclose(file);
	}
	

	}	

int deletar()
{

// Fun��o respons�vel por deletar os usu�rios.

	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	printf("O CPF digitado foi deletado com sucesso!\n");
	system("pause");
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if (file == NULL)
	
	{
		printf("O us�ario n�o se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
{
		int opcao=0; // Definindo vari�veis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a L�nguagem
	
	system("cls");
	
	printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registro de nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("opc�o: "); //Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	system("cls");
	
	switch(opcao)
	{
			case 1:
		registro();
		break;
	
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("Essa op�ao n�o est� dispon�vel!\n");
		system("pause");
		break;
	}
	}
}
		

