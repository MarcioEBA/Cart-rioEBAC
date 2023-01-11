#include <stdio.h> //bliblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //bilioteca reponsável por cuidar das string

int registro() //a função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	
	printf("Digitar o CPF a ser cadastrado: "); //coletando informação do CPF do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa write
	fprintf(file, cpf);  // salva o valor da variavel cpf
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // a - atualiza o arquivo
	fprintf(file, ","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do nome do usuário
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //a - atualiza o arquivo
	fprintf(file, nome); //adiciona o valro da variável nome
	fclose(file); //fecha o arquivo
	
    file = fopen(arquivo, "a"); // a - atualiza o arquivo
	fprintf(file, ","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do sobrenome do usuário
	scanf("%s", sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //a - atualiza o arquivo
	fprintf(file, sobrenome); //adiciona o valor da variável sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");  //a - atualiza o arquivo
	fprintf(file, ",");  //adiciona uma vírgula
	fclose(file);  //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informação do sobrenome do usuário
	scanf("%s", cargo);  //%s refere-se a string
	
	file = fopen(arquivo, "a");  //a - atualiza o arquivo
	fprintf(file, cargo);  //adiciona o valor da variável cargo
	fclose(file);  //fecha o arquivo
	
	system("pause");
		
	
		
}

int consulta()    //a função responsável por consultar os usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do sobrenome do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    FILE *file; 
    file = fopen(cpf, "r"); //r - faz a leitura do arquivo criado nomeado pela variável CPF
    
    if(file == NULL)  //início da função para verificar se o arquivo exite
    {
    	printf("Não foi possível abrir o arquivo, não localizado!\n\n");
  	}  //fim da função para verificar se o arquivo exite
  	
  	while(fgets(conteudo, 200, file) != NULL) //início da função para mostrar na tela as informações do arquivo
  	{
  		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}  //fim da função para mostrar na tela as informações do arquivo
    
    system("pause");
        
}

int deletar()   //a função responsável por deletar o usuário do sistema
{
	char cpf[40];
	
    printf("Digite o CPF do usuário a ser deletado: "); 
    scanf("%s",cpf);
    
    remove(cpf);  //apaga o arquivo com a chave CPF
    
    FILE *file;
    file = fopen(cpf, "r"); //r - faz a leitura do arquivo criado nomeado pela variável CPF
    
    if(file == NULL) //informa ao usuário caso a chave (cpf) digitado não conste no banco de dados
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
	}
 	
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	    
	    system("cls");
	    
	    	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
     	printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("Escolha a opção desejada no menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Opção: ");  //Fim do menu
	
	    scanf("%d", &opcao);  //Armazenando a escolha do usuário
	
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //Início da seleção do menu
	    {
	    	
	    	case 1:
	    	registro();  //chamada de funções
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
		    printf("Essa opção não está disponível!\n\n");
		    system("pause");
		    break;
	    	
		} //Fim da seleção
	
	  	  	
    }
	
}
