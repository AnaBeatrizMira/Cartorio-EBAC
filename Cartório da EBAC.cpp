#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() 
{
	// Início da criação de variáveis para armazenar os dados do usuário
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação de variáveis
	
	// Coletando o CPF do usuário a ser cadastrado
	printf("Cpf a ser cadastrado: ");
	scanf("%s", cpf); // %s para ler string (sem espaços)
	
	// Copia o CPF para a variável 'arquivo', que será o nome do arquivo
	strcpy(arquivo, cpf);
	
	FILE *file; // Declaração do ponteiro para o arquivo
	
	// Cria o arquivo com o nome do CPF para escrever os dados
	file = fopen(arquivo, "w"); // "w" indica modo de escrita (write)
	fprintf(file, cpf); // Escreve o CPF no arquivo
	fclose(file); // Fecha o arquivo para garantir que o dado foi salvo
	
	// Reabre o arquivo no modo de "append" para adicionar vírgula (",") após o CPF
	file = fopen(arquivo, "a"); // "a" indica modo de adição (append)
	fprintf(file, ","); // Adiciona uma vírgula
	fclose(file); // Fecha o arquivo
	
	// Coleta e adiciona o nome
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	// Adiciona uma vírgula após o nome
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Coleta e adiciona o sobrenome
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	// Adiciona uma vírgula após o sobrenome
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	// Coleta e adiciona o cargo
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system("pause"); // Pausa para que o usuário veja a confirmação
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem para português
	
	char cpf[40]; // Para armazenar o CPF a ser consultado
	char conteudo[200]; // Para armazenar o conteúdo do arquivo
	
	// Solicita o CPF do usuário para consulta
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; // Declaração do ponteiro para o arquivo
	file = fopen(cpf, "r"); // Tenta abrir o arquivo no modo de leitura ("r")
	
	// Verifica se o arquivo não existe
	if(file == NULL)
	{
		printf("Arquivo não encontrado.\n"); // Mensagem de erro se o arquivo não existir
	}
	
	// Lê o conteúdo do arquivo linha por linha e exibe
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); // Pausa para o usuário ver as informações
	fclose(file); // Fecha o arquivo
}

int deletar()
{
	char cpf[40]; // Para armazenar o CPF do usuário a ser deletado
	
	// Solicita o CPF do usuário a ser deletado
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	// Remove o arquivo com o nome do CPF
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // Tenta abrir o arquivo novamente para verificar se foi removido
	
	// Verifica se o arquivo foi deletado com sucesso
	if(file == NULL)
	{
		printf("Arquivo não encontrado.\n"); // Mensagem de sucesso se o arquivo não for encontrado
		system("pause"); // Pausa para o usuário ver a confirmação
	}
}

int main()
{
	int opcao = 0; // Variável para armazenar a opção escolhida pelo usuário
	int laco = 1; // Variável de controle do loop
	
	// Início do loop para o menu
	for(laco = 1; laco == 1;)
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Define a linguagem para português
		
		// Exibe o menu para o usuário
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");
		scanf("%d", &opcao); // Armazena a opção do usuário
		
		system("cls"); // Limpa a tela antes de executar a opção
		
		// Seleção de opções do menu
		switch(opcao)
		{
			case 1:
				registro(); // Chama a função para registrar um usuário
				break;
			
			case 2:
				consultar(); // Chama a função para consultar um usuário
				break;
			
			case 3:
				deletar(); // Chama a função para deletar um usuário
				break;
			
			default:
				printf("Essa opção não está disponível\n"); // Mensagem para opção inválida
				system("pause"); // Pausa para o usuário ver a mensagem
				break;
		} //fim da seleção
	}
}
