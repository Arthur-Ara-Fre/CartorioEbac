#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro()//função responsavel por cadastrar usuarios no sistema
{
	//inicio das funções das variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int recadastro;
	//Final das funções das variaveis/strings
	
	printf("digite o CPF a ser cadastrado: ");//coletando informação do usuario
	scanf("%s", cpf);//%s referente a string
	
	//Quando um usuario ja existente é cadastrado, o antigo cadastro é substituido.
	//Deixar o cliente ciente de que o cadastro que ele está fazendo já existe 
	
	FILE *file;//cria o arquivo
	file = fopen(cpf, "r");
	if (file != NULL)
	{
		printf("Já existe um usuario com este cpf cadastrado. Deseja sobrecreve-lo?\n1-Sim\n2-Não\n\nopção:");
		scanf("%d", &recadastro);
	}
	fclose(file);
	printf("\n");
	if(recadastro == 2)
	{
		return 0;
	}
	//fim do recadastro
	system("cls");
	printf("CPF cadastrado:%s\n", cpf);
	
	strcpy (arquivo, cpf);//responsável por copiar os valores das strings
	
	file = fopen(arquivo, "w");//cria o arquivo. "w" significa escrever
	fprintf(file, "CPF:");
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//virgula
	fprintf(file, "\n");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("Não foi possivel abrir o arquivo. Não localizado!\n");
	}
	else
	{
		printf("\nEssas são as informações do usuario:\n");
		while(fgets(conteudo, 200, file) != NULL)
		{
			
			printf("%s", conteudo);
			
		}
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	int usuario = 0;
	
	printf("Digite o cpf a ser deletado:\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		
		printf("Usuario não encontrado\n");
	}
	else if(cpf != NULL)
	{
		printf("usuario encontrado\n");
		usuario = 1;	
	}
	fclose(file);
	remove(cpf);
	
	if(usuario == 1)
	{
		printf("O usuario saiu do sistema\n");
	}
	
		
	system("pause");
}

int main()
{
	int opcao = 0;//definindo as variáveis
	int laco = 1;
	
	setlocale (LC_ALL, "portuguese");//definindo a linguagem
	
	for(laco = 1; laco = 1;)	
	{
		system("cls");
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
	
		printf("Escolha a opção desejada do menu:\n\n");//Menu
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao);//aramzenamento a escolha do usuário
		
		system("cls");//limpeza da tela para o usuário
		
		switch (opcao)//inicio da seleção
		{
			case 1:
				registro();
			break;	
		
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n");
			system("pause");
			break;
		}//fim da seleção
	}
}
