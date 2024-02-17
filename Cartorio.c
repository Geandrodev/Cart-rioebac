#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro() // Fun��o Respons�vel por cadastrar os us�arios no sistema
{
	//inicio das cria��es das vari�veis/string
	char arquivo[40]; //char representa caracteres
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das cria��es das vari�veis/string
	
	printf("## CADASTRO DE USU�RIOS ##\n\n");
	
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf ); //%s refere-se as string,salvar uma string
	
	strcpy(arquivo , cpf); //Respons�vel por copiar os valores das string
	
	FILE *file;  //cria o arquivo
	file= fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf);  //salva o valor da variavel
	fclose(file);  // fecha o arquivo
	
	file= fopen(arquivo, "a"); //cria o arquivo
	fprintf(file, ",");
	fclose(file); //usado para fechar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file= fopen(arquivo, "a"); //abrir o arquivo especificado em modo de anexa��o
	fprintf(file,nome); //fun��o que permite escrever informa��es no caso a vari�vel nome
	fclose(file); //usado para fechar o arquivo
	
	file= fopen(arquivo, "a"); //abrir o arquivo especificado em modo de anexa��o
	fprintf(file,","); // Escreve conte�do do arquivo
	fclose(file); //usado para fechar o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); //ler e armazenar a vari�vel sobrenome
	
	file= fopen(arquivo, "a"); //abrir o aquivo
	fprintf(file,sobrenome); //permite escrever informa��es no caso a vari�vel sobrenome
	fclose(file); //usado para fechar o aquivo
	
	file= fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,","); //Escreve conte�do do arquivo
	fclose(file); //fechar o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //ler e armazenar a vari�vel cargo(salvar uma string)
	
	file= fopen(arquivo, "a"); //abrir o arquivo
	fprintf(file,cargo); //permite escrever informa��es no caso a vari�vel cargo
	fclose(file); //fechar o programa
	
	
		
	system("pause"); //usado para pausar o programa at� que o usu�rio pressione a tecla		
}

int consulta() //fun��o respons�vel pela consulta do usu�rio cadastrado
{
	setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //op��o para ler e armazenar a vari�vel cpf( ler e salvar uma string)
	
	FILE *file; //op��o utilizada para realizar opera��es de leitura,escrita ou manipula��o no arquivo associado
	file = fopen(cpf,"r"); //fun��o que permite abrir o arquivo
	
	if(file== NULL) //verifica se houve falha ao abrir o arquivo(verifica se a abertura do arquivo foi bem sucedida)
{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.");	//Mensagem que ser� apresentado caso arquivo CPF n�o seja encontrado
}

	while(fgets(conteudo, 200, file) != NULL) // while > condicional que realiza caso encontre verdadeiro, fgets realiza a leitura da string,	
	{
		printf("\nEssas s�o as informa��es dos usu�rios: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause"); // Fun��o que permite pausar o sistema para aguardar novo comando	
}

int deletar() //fun��o que permite deletar o usu�rio cadastrado
{
	char cpf[40];
	
	printf ("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //estrutura condicional
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
			
	}
	
}


int main () //int main significa que a fun��o principal retorna um valor inteiro e n�o aceita argumentos
   {
     
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {  
		system("cls"); //respons�vel por limpar a tela
		
		setlocale (LC_ALL, "Portuguese"); //Definindo a linguagem
		
	
		
		printf ("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do Sistema\n\n"); 
		printf("Op��o: "); //Fim do Menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
			
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)  //inicio da sele��o do menu
		{
			case 1:
			registro();	 //chamada de fun��es
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
			printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
			break;	
		}
	} //Fim da Sele��o
	
} 

