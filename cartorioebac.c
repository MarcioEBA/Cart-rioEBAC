#include <stdio.h> //bliblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //bilioteca repons�vel por cuidar das string

int registro() //a fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	
	printf("Digitar o CPF a ser cadastrado: "); //coletando informa��o do CPF do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write
	fprintf(file, cpf);  // salva o valor da variavel cpf
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // a - atualiza o arquivo
	fprintf(file, ","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do nome do usu�rio
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //a - atualiza o arquivo
	fprintf(file, nome); //adiciona o valro da vari�vel nome
	fclose(file); //fecha o arquivo
	
    file = fopen(arquivo, "a"); // a - atualiza o arquivo
	fprintf(file, ","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do sobrenome do usu�rio
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //a - atualiza o arquivo
	fprintf(file, sobrenome); //adiciona o valor da vari�vel sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //a - atualiza o arquivo
	fprintf(file, ",");  //adiciona uma v�rgula
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informa��o do sobrenome do usu�rio
	scanf("%s", cargo);  //%s refere-se a string
	
	file = fopen(arquivo, "a");  //a - atualiza o arquivo
	fprintf(file, cargo);  //adiciona o valor da vari�vel cargo
	fclose(file);  //fecha o arquivo
	
	system("pause");
		
	
		
}

int consulta()    //a fun��o respons�vel por consultar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do sobrenome do usu�rio
    scanf("%s", cpf); //%s refere-se a string
    
    FILE *file; 
    file = fopen(cpf, "r"); //r - faz a leitura do arquivo criado nomeado pela vari�vel CPF
    
    if(file == NULL)  //in�cio da fun��o para verificar se o arquivo exite
    {
    	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
  	}  //fim da fun��o para verificar se o arquivo exite
  	
  	while(fgets(conteudo, 200, file) != NULL) //in�cio da fun��o para mostrar na tela as informa��es do arquivo
  	{
  		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}  //fim da fun��o para mostrar na tela as informa��es do arquivo
    
    system("pause");
        
}

int deletar()   //a fun��o respons�vel por deletar o usu�rio do sistema
{
	char cpf[40];
	
    printf("Digite o CPF do usu�rio a ser deletado: "); 
    scanf("%s",cpf);
    
    remove(cpf);  //apaga o arquivo com a chave CPF
    
    FILE *file;
    file = fopen(cpf, "r"); //r - faz a leitura do arquivo criado nomeado pela vari�vel CPF
    
    if(file == NULL) //informa ao usu�rio caso a chave (cpf) digitado n�o conste no banco de dados
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
	}
 	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls");
	    
	    	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
     	printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Op��o: ");  //Fim do menu
	
	    scanf("%d", &opcao);  //Armazenando a escolha do usu�rio
	
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //In�cio da sele��o do menu
	    {
	    	
	    	case 1:
	    	registro();  //chamada de fun��es
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
		    printf("Essa op��o n�o est� dispon�vel!\n\n");
		    system("pause");
		    break;
	    	
		} //Fim da sele��o
	
	  	  	
    }
	
}
