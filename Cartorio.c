#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro() // Função Responsável por cadastrar os usúarios no sistema
{
	//inicio das criações das variáveis/string
	char arquivo[40]; //char representa caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das criações das variáveis/string
	
	printf("## CADASTRO DE USUÁRIOS ##\n\n");
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf ); //%s refere-se as string,salvar uma string
	
	strcpy(arquivo , cpf); //Responsável por copiar os valores das string
	
	FILE *file;  //cria o arquivo
	file= fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);  //salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file= fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ",");
	fclose(file); //usado para fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file= fopen(arquivo, "a"); //abrir o arquivo especificado em modo de anexação
	fprintf(file,nome); //função que permite escrever informações no caso a variável nome
	fclose(file); //usado para fechar o arquivo
	
	file= fopen(arquivo, "a"); //abrir o arquivo especificado em modo de anexação
	fprintf(file,","); // Escreve conteúdo do arquivo
	fclose(file); //usado para fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //ler e armazenar a variável sobrenome
	
	file= fopen(arquivo, "a"); //abrir o aquivo
	fprintf(file,sobrenome); //permite escrever informações no caso a variável sobrenome
	fclose(file); //usado para fechar o aquivo
	
	file= fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,","); //Escreve conteúdo do arquivo
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //ler e armazenar a variável cargo(salvar uma string)
	
	file= fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,cargo); //permite escrever informações no caso a variável cargo
	fclose(file); //fechar o programa
	
	
		
	system("pause"); //usado para pausar o programa até que o usuário pressione a tecla		
}

int consulta() //função responsável pela consulta do usuário cadastrado
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //opção para ler e armazenar a variável cpf( ler e salvar uma string)
	
	FILE *file; //opção utilizada para realizar operações de leitura,escrita ou manipulação no arquivo associado
	file = fopen(cpf,"r"); //função que permite abrir o arquivo
	
	if(file== NULL) //verifica se houve falha ao abrir o arquivo(verifica se a abertura do arquivo foi bem sucedida)
{
	printf("Não foi possível abrir o arquivo, não localizado!.");	//Mensagem que será apresentado caso arquivo CPF não seja encontrado
}

	while(fgets(conteudo, 200, file) != NULL) // while > condicional que realiza caso encontre verdadeiro, fgets realiza a leitura da string,	
	{
		printf("\nEssas são as informações dos usuários: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause"); // Função que permite pausar o sistema para aguardar novo comando	
}

int deletar() //função que permite deletar o usuário cadastrado
{
	char cpf[40];
	
	printf ("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //estrutura condicional
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
			
	}
	
}


int main () //int main significa que a função principal retorna um valor inteiro e não aceita argumentos
   {
     
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {  
		system("cls"); //responsável por limpar a tela
		
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
		
	
		
		printf ("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n"); 
		printf("Opção: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
			
		system("cls"); //responsável por limpar a tela
		
		switch(opcao)  //inicio da seleção do menu
		{
			case 1:
			registro();	 //chamada de funções
		  	break;	
			
			case 2:
			consulta();
		  	break;
			
			case 3:
			deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;	
			
			default:
			printf("Essa opção não está disponível!\n");
		    system("pause");
			break;	
		}
	} //Fim da Seleção
	
} 

