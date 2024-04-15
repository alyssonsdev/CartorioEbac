#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�es
#include <string.h>//biblioteca respos�vel por cuidar das strings

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o da vari�vel string
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo,cpf);// Respons�vel por copiar os valores das strings
	
	FILE *file;//cria o arquivo no no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo e o 'w' significa escrever
	fprintf(file,cpf);// salvo o valor da vari�vel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separa��o por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	printf("Digite o nome a ser cadastrado: ");//coleta dados do usu�rio
	scanf("%s",nome);//l� uma string e guarda na vari�vel nome
	
	file = fopen(arquivo, "a");//abre o arquivo e 'a' atualiza
	fprintf(file,nome);//mostra para o usu�rio o aquivo nome
	fclose(file);//fecha o arquivo que foi aberto
	
	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separa��o por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta dados do usu�rio
	scanf("%s",sobrenome);//l� uma string e guarda na vari�vel sobrenome
	
	file = fopen(arquivo, "a");//abre o arquivo e 'a' atualiza
	fprintf(file,sobrenome);//mostra para o usu�rio o aquivo sobrenome
	fclose(file);//fecha o arquivo que foi aberto

	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separa��o por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	printf("Digite o cargo a ser cadastrado: ");//coleta dados do usu�rio
	scanf("%s",cargo);//l� uma string e guarda na vari�vel cargo
	
	file = fopen(arquivo, "a");//abre o arquivo e 'a' atualiza
	fprintf(file,cargo);//mostra para o usu�rio o aquivo cargo
	fclose(file);//fecha o arquivo que foi aberto
	
	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separa��o por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	system("pause");//permite que o usu�rio leia o resultado na tela
	
}

int consulta()//fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
	char cpf[40];//cri��o de vari�veis 
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//coleta dados do usu�rio
	scanf("%s",cpf);//faz a leitura da string e guarda em cpf
	
	FILE *file;//cri��o de arquivo
	file = fopen(cpf,"r");//abre o aquivo cpf e 'r' faz a leitura
	
	if(file == NULL)//define a condi��o para a exibi��o da linha seguinte
	{
		printf("N�o foi poss�bel abrir o arquivo, n�o localizado. \n");//mostra ao resultado da escolha do usu�rio
	}
	
	while(fgets(conteudo, 200, file) != NULL)//indica a condi��o para a execu��o da linha seguinte
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");//
		printf("%s",conteudo);//mostra as informa��es do usu�rio armazenadas na string conte�do
		printf("\n\n");//pula linhas 
	}
		
		system("pause");//permite que o usu�rio leia o resultado na tela
		
	
}


int deletar()//fun��o respons�vel por deletar usu�rios no sistema
{
	char cpf[40];//cria��o de string
	
	printf("Digite o cpf do usu�rio a ser deletado:");//coleta a op��o selecionada pelo usu�rio
	scanf("%s",cpf);//faz a leitura da string e guarda na vari�vel cpf
	
	remove(cpf);//comando deletar
	
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo cpf e 'r' signifca fazer a leitura
	
	if(file == NULL)//define a condi��o da escolha
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");//mostra o resuoltado da opera��o do usu�rio
		system("pause");//permite que o usu�rio leia o resultado na tela
		
	}
}
int main()//fun��o principal

{
	int opcao=0;//definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)//executa ate o fim das op��es e volta no menu 
	{
		system("cls");// repons�vel por limpar a tela
		
        setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
       	printf("### Cart�rio da EBAC###\n");//inicio do menu
	    printf("Escolha a op��o desejada no menu:\n");
	    printf("\t1- Registrar nomes\n");
	    printf("\t2- Consultar nomes\n");
	    printf("\t3- Deletar nomes\n\n");
	    printf("\t4- Sair do sistema!\n\n");
	    printf("Opcao: ");//fim do menu

        scanf("%d", &opcao);//armazenando a escolha do usu�rio
    
        system ("cls");
    
    
        switch(opcao)//in�cio da sele��o do menu
        {
        	case 1:
        	registro();//chamada de fun��es      	
            break;
            
            case 2:
			consulta();//chamada de fun��es
		    break;
		    
		    case 3:
		   	deletar();//chamada de fun��es
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
	    	default:
	    	printf("Essa op��o n�o est� dispon�vel!\n");//mostra pro usu�rio o resultado da op��o
	    	system("pause");
	    	break;//fim da chamada dd fun��es
       
	    }
	    
	    
    }
}
