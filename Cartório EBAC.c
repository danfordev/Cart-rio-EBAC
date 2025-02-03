#include<stdio.h> //biblioteca de comunicação com o usuário
#include<stdlib.h> //biblioteca de alocação de espaço na memória
#include<locale.h> //biblioteca de alocaçao de texto por região
#include<string.h> //biblioteca responsável por cuidar das strings


int registro() //Função responsável por cadastrar os usuários no sistema.
{
	// Início criação de variáveis/ strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criaçaõ da variáveis.
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário.
	scanf("%s", cpf); //%s refere-se a string.
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever.
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // Atualizar o arquivo o "a" significa atualizar.
	fprintf(file,", "); // Para fazer uma separação entre as informações.
	fclose(file);
	
	//Início do cadastro do usuário.
	
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
	
	// Fim do cadastro do usuário.
	
	system("pause");
}

int consultar() //Função responsável pela consulta dos usuários ao sistema.
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200]; // Reserva de alocação na memória.
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Lê o arquivo, a letra r significa ler. 
	
	if(file == NULL) // Caso a opção desejada não existir mostrar a mensagem abaixo.
	{
	
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
		system("pause");
	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
		system("pause");
		fclose(file);
	}
	

	}	

int deletar()
{

// Função responsável por deletar os usuários.

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
		printf("O usúario não se encontra no sistema!\n");
		system("pause");
	}
	
}

int main()
{
		int opcao=0; // Definindo variáveis
	int x=1;
	
	for(x=1;x=1;)
	{
	
		
	setlocale(LC_ALL, "Portuguese"); //Definindo a Línguagem
	
	system("cls");
	
	printf("### Cartório da EBAC ###\n\n"); //início do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registro de nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("opcão: "); //Fim do menu
	
	scanf("%d", &opcao); //armazenando a escolha do usuário
	
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
		printf("Essa opçao não está disponível!\n");
		system("pause");
		break;
	}
	}
}
		

