#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por regiões
#include <string.h>//biblioteca resposável por cuidar das strings

int registro()//função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação da variável string
	
	printf("Digite o cpf a ser cadastrado: ");//coletando informação do usuário
	scanf("%s", cpf);//%s refere-se a strings
	
	strcpy(arquivo,cpf);// Responsável por copiar os valores das strings
	
	FILE *file;//cria o arquivo no no banco de dados
	file = fopen(arquivo, "w");//cria o arquivo e o 'w' significa escrever
	fprintf(file,cpf);// salvo o valor da variável
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separação por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	printf("Digite o nome a ser cadastrado: ");//coleta dados do usuário
	scanf("%s",nome);//lê uma string e guarda na variável nome
	
	file = fopen(arquivo, "a");//abre o arquivo e 'a' atualiza
	fprintf(file,nome);//mostra para o usuário o aquivo nome
	fclose(file);//fecha o arquivo que foi aberto
	
	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separação por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	printf("Digite o sobrenome a ser cadastrado: ");//coleta dados do usuário
	scanf("%s",sobrenome);//lê uma string e guarda na variável sobrenome
	
	file = fopen(arquivo, "a");//abre o arquivo e 'a' atualiza
	fprintf(file,sobrenome);//mostra para o usuário o aquivo sobrenome
	fclose(file);//fecha o arquivo que foi aberto

	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separação por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	printf("Digite o cargo a ser cadastrado: ");//coleta dados do usuário
	scanf("%s",cargo);//lê uma string e guarda na variável cargo
	
	file = fopen(arquivo, "a");//abre o arquivo e 'a' atualiza
	fprintf(file,cargo);//mostra para o usuário o aquivo cargo
	fclose(file);//fecha o arquivo que foi aberto
	
	file = fopen(arquivo,"a");//abre o arquivo e 'a' atualiza
	fprintf(file,",");//mostra a separação por virgula
	fclose(file);//fecha o arquivo que foi aberto
	
	system("pause");//permite que o usuário leia o resultado na tela
	
}

int consulta()//função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
	char cpf[40];//crição de variáveis 
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");//coleta dados do usuário
	scanf("%s",cpf);//faz a leitura da string e guarda em cpf
	
	FILE *file;//crição de arquivo
	file = fopen(cpf,"r");//abre o aquivo cpf e 'r' faz a leitura
	
	if(file == NULL)//define a condição para a exibição da linha seguinte
	{
		printf("Não foi possíbel abrir o arquivo, não localizado. \n");//mostra ao resultado da escolha do usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL)//indica a condição para a execução da linha seguinte
	{
		printf("\nEssas são as informações do usuário: ");//
		printf("%s",conteudo);//mostra as informações do usuário armazenadas na string conteúdo
		printf("\n\n");//pula linhas 
	}
		
		system("pause");//permite que o usuário leia o resultado na tela
		
	
}


int deletar()//função responsável por deletar usuários no sistema
{
	char cpf[40];//criação de string
	
	printf("Digite o cpf do usuário a ser deletado:");//coleta a opção selecionada pelo usuário
	scanf("%s",cpf);//faz a leitura da string e guarda na variável cpf
	
	remove(cpf);//comando deletar
	
	
	FILE *file;
	file = fopen(cpf,"r");//abre o arquivo cpf e 'r' signifca fazer a leitura
	
	if(file == NULL)//define a condição da escolha
	{
		printf("O usuário não se encontra no sistema!.\n");//mostra o resuoltado da operação do usuário
		system("pause");//permite que o usuário leia o resultado na tela
		
	}
}
int main()//função principal

{
	int opcao=0;//definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)//executa ate o fim das opções e volta no menu 
	{
		system("cls");// reponsável por limpar a tela
		
        setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
       	printf("### Cartório da EBAC###\n");//inicio do menu
	    printf("Escolha a opção desejada no menu:\n");
	    printf("\t1- Registrar nomes\n");
	    printf("\t2- Consultar nomes\n");
	    printf("\t3- Deletar nomes\n\n");
	    printf("\t4- Sair do sistema!\n\n");
	    printf("Opcao: ");//fim do menu

        scanf("%d", &opcao);//armazenando a escolha do usuário
    
        system ("cls");
    
    
        switch(opcao)//início da seleção do menu
        {
        	case 1:
        	registro();//chamada de funções      	
            break;
            
            case 2:
			consulta();//chamada de funções
		    break;
		    
		    case 3:
		   	deletar();//chamada de funções
	    	break;
	    	
	    	case 4:
	    	printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
				
	    	default:
	    	printf("Essa opção não está disponível!\n");//mostra pro usuário o resultado da opção
	    	system("pause");
	    	break;//fim da chamada dd funções
       
	    }
	    
	    
    }
}
