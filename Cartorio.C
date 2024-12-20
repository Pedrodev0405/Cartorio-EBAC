#include <stdio.h> //biblioteca de comunicaçao com o usuário
#include <stdlib.h> //biblioteca de locação de espaco em memoria 
#include <locale.h> //biblioteca de locação de texto por régiao 
#include <string.h> //biblioteca responsavel por cuidar das string

int registro()//função responsavel por cadastrar os usuarios no sistema 
{
	char arquivo[40];//inicio e criacao das variaveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//final da criacao das variaveis/string
	
	printf("Digite o CPF a ser cadastrado:");//coletando informação do usuario
	scanf("%s", cpf);
	
    strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo,"w"); //cria arquivo e "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado:");//coletando informacoes
	scanf("%s",nome);//%s refere-se ao string
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,nome);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);//refere-se a string
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,sobrenome);//salva o valor da varaiavel
	fclose(file);//fecha o arquivo

	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,",");//valor da variavel
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:");//coletando informacoes 
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");//cria o arquivo
	fprintf(file,cargo);//valor da variavel
	fclose(file);//fecha o arquivo
	
	system("pause");//tempo de resposta 
	
}

int consulta()
{
	setlocale(LC_ALL,"portuguese");//defeinindo a linguagem
	
   char cpf[40];//inicio e crição das variaveis/string
   char conteudo[200];
   printf("digite o cpf  a ser consultado:" );
   scanf("%s",cpf);//%s refere-se a string
   
   FILE* file;
   file =fopen(cpf,"r");
   
   if(file==NULL)
   {
   	printf("Não foi possivel abrir arquivo,não localizado!\n");
   }
   
   while(fgets(conteudo,200 ,file)!=NULL)
   {
     printf("\nEssas são as informações do usuario:");
     printf("%s",conteudo);
     printf("\n\n");
   }
   
   system("pause");//tempo de resposta
}

int deletar()
{
    char cpf[40];
    
	printf("Digite o CPF do usuário ser deletado:" );//coletando informacoes
    scanf("%s",cpf);
    
   
	 remove(cpf);
    printf("usuario deletado com sucesso!\n");

    
    FILE *file;//cria o arquivo
    file = fopen(cpf,"r");//valor da variavel
    if(file==NULL)
    {
    	printf("O usuário não se encontrea no sistema!\n");
    	system("pause");//tempo de resposta
	}
}

int main()

{
	int opcao=0; //definindo váriaveis	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
 	
 	setlocale(LC_ALL, "Portuguese"); //definindo lingiagem
 	
 	printf("### Cartório da EBAC ### \n\n"); //inicio do menu
 	printf("Escolha a opção desejada do menu:\n\n");
 	printf("\t1-Registrar nomes\n");
 	printf("\t2-Consultar nomes\n");
     printf("\t3-Deletar nomes\n\n"); 
     printf("\t4-sair do sistema\n\n");
     printf("Opção:"); //fim do menu
     
     scanf("%d",&opcao); //armazenando a escolha do usuário
       
     system("cls"); //responsavel po limpar a tela

     switch(opcao)	 //inicio da selecao
       {
    	 case 1:
    	 registro();//chamada de funcoes 
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
		 printf("Essa opção não está disponivel!\n");
		 system("pause");
		 break;//fim da selecao
	   }
    
     
	 
	} 
}
