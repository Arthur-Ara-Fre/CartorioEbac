#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h>//biblioteca de aloca��es de texto por regi�o.
#include <string.h>//biblioteca respons�vel por cuidar das strings.

int registro()//fun��o respons�vel por cadastrar usu�rios no sistema.
{
	//in�cio das fun��es das variaveis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	int recadastro=0;
	//Final das fun��es das vari�veis/strings.
	
	printf("digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio.
	scanf("%s", cpf);//%s referente a string.
	fflush(stdin);
	
	//Quando um usu�rio ja existente � cadastrado, o antigo cadastro � substitu�do sem o usuario saber.
	//Alem de gastar mais tempo cadastrando um usuario que ja tinha sido casdastrado.
	//Deixar o cliente ciente de que o cadastro que ele est� fazendo j� existe.
	
	//come�o do re-cadastro.
	
	FILE *file;//cria o arquivo.
	file = fopen(cpf, "r");
	if (file != NULL)
	{
		printf("J� existe um usuario com este cpf cadastrado. Deseja sobrecreve-lo?\n1-Sim\n2-N�o\n\nop��o:");
		scanf("%d", &recadastro);
		fflush(stdin);//Limpar o buffer do teclado.
	}
	fclose(file);
	printf("\n");
	if(recadastro == 2)
	{
		return 0;
	}
	//fim do re-cadastro.
	system("cls");
	printf("CPF cadastrado:%s\n", cpf);
	
	strcpy (arquivo, cpf);//respons�vel por copiar os valores das strings.
	
	file = fopen(arquivo, "w");//cria o arquivo. "w" significa escrever.
	fprintf(file, "CPF:");
	fprintf(file,cpf);//salva o valor da variavel.
	fclose(file);//fecha o arquivo.
	
	file = fopen(arquivo, "a");//virgula
	fprintf(file, "\n");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	gets(nome);//pegar strings com espa�o, visto que o scanf n�o faz.
	fflush(stdin);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fclose(file);
	
	file =fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	gets(sobrenome);
	fflush(stdin);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file, sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	gets(cargo);
	fflush(stdin);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale (LC_ALL, "portuguese");//definindo o idioma.
	
	char cpf[40];
	char conteudo[100];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if (file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo. N�o localizado!\n");
	}
	else
	{
		printf("\nEssas s�o as informa��es do usuario:\n");
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
		
		printf("Usuario n�o encontrado\n");
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
	int opcao = 0;//definindo as vari�veis.
	int laco = 1;
	
	setlocale (LC_ALL, "portuguese");//definindo a linguagem.
	
	for(laco = 1; laco = 1;)	
	{
		system("cls");
		printf("### Cart�rio da EBAC ###\n\n");//inicio do menu.
	
		printf("Escolha a op��o desejada do menu:\n\n");//Menu.
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - sair do programa\n\n");
		printf("Op��o: ");//fim do menu.
	
		scanf("%d", &opcao);//aramzenamento a escolha do usu�rio.
		
		system("cls");//limpeza da tela para o usu�rio.
		
		switch (opcao)//in�cio da sele��o.
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
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
			break;
		}//fim da sele��o.
	}
}
