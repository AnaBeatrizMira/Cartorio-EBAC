#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() 
{
	// In�cio da cria��o de vari�veis para armazenar os dados do usu�rio
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o de vari�veis
	
	// Coletando o CPF do usu�rio a ser cadastrado
	printf("Cpf a ser cadastrado: ");
	scanf("%s", cpf); // %s para ler string (sem espa�os)
	
	// Copia o CPF para a vari�vel 'arquivo', que ser� o nome do arquivo
	strcpy(arquivo, cpf);
	
	FILE *file; // Declara��o do ponteiro para o arquivo
	
	// Cria o arquivo com o nome do CPF para escrever os dados
	file = fopen(arquivo, "w"); // "w" indica modo de escrita (write)
	fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo para garantir que o dado foi salvo
	
	// Reabre o arquivo no modo de "append" para adicionar v�rgula (",") ap�s o CPF
	file = fopen(arquivo, "a"); // "a" indica modo de adi��o (append)
	fprintf(file, ","); // Adiciona uma v�rgula
	fclose(file); // Fecha o arquivo
	
	// Coleta e adiciona o nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	// Adiciona uma v�rgula ap�s o nome
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Coleta e adiciona o sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	// Adiciona uma v�rgula ap�s o sobrenome
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Coleta e adiciona o cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system("pause"); // Pausa para que o usu�rio veja a confirma��o
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem para portugu�s
	
	char cpf[40]; // Para armazenar o CPF a ser consultado
	char conteudo[200]; // Para armazenar o conte�do do arquivo
	
	// Solicita o CPF do usu�rio para consulta
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; // Declara��o do ponteiro para o arquivo
	file = fopen(cpf, "r"); // Tenta abrir o arquivo no modo de leitura ("r")
	
	// Verifica se o arquivo n�o existe
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado.\n"); // Mensagem de erro se o arquivo n�o existir
	}
	
	// L� o conte�do do arquivo linha por linha e exibe
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // Pausa para o usu�rio ver as informa��es
	fclose(file); // Fecha o arquivo
}

int deletar()
{
	char cpf[40]; // Para armazenar o CPF do usu�rio a ser deletado
	
	// Solicita o CPF do usu�rio a ser deletado
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	// Remove o arquivo com o nome do CPF
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Tenta abrir o arquivo novamente para verificar se foi removido
	
	// Verifica se o arquivo foi deletado com sucesso
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado.\n"); // Mensagem de sucesso se o arquivo n�o for encontrado
		system("pause"); // Pausa para o usu�rio ver a confirma��o
	}
}

int main()
{
	int opcao = 0; // Vari�vel para armazenar a op��o escolhida pelo usu�rio
	int laco = 1; // Vari�vel de controle do loop
	
	// In�cio do loop para o menu
	for(laco = 1; laco == 1;)
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Define a linguagem para portugu�s
		
		// Exibe o menu para o usu�rio
		printf("### Cart�rio da EBAC ###\n\n"); 
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: ");
		scanf("%d", &opcao); // Armazena a op��o do usu�rio
		
		system("cls"); // Limpa a tela antes de executar a op��o
		
		// Sele��o de op��es do menu
		switch(opcao)
		{
			case 1:
				registro(); // Chama a fun��o para registrar um usu�rio
				break;
			
			case 2:
				consultar(); // Chama a fun��o para consultar um usu�rio
				break;
			
			case 3:
				deletar(); // Chama a fun��o para deletar um usu�rio
				break;
			
			default:
				printf("Essa op��o n�o est� dispon�vel\n"); // Mensagem para op��o inv�lida
				system("pause"); // Pausa para o usu�rio ver a mensagem
				break;
		} //fim da sele��o
	}
}
