#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

 int registro()//fun��o responsavel por cadastrar usuario do sistemas
 {
 	//inicio cria��o de vari�vel/string
    char arquivo[40];
 	char cpf[40];
    char nome[40];
 	char sobrenome[40];
    char cargo[40];
    //final cria��o de vari�vel/string
    
    
    printf("digite o CPF a ser cadastrado:  \n");
    scanf("%s", cpf);//%s refere-se a string 
   
    strcpy(arquivo, cpf);//responsavel pelo valor da string
   
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
    fprintf(file, cpf);//salva arquivo
    fclose(file);//fecha arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ":");
    fclose(file);
    
    printf("digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, " ");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("digite o cargo a ser cadastrado: ");
    scanf ("%s",cargo);
     
	file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
     file = fopen(arquivo, "a");
    fprintf(file, ".\n");
    fclose(file);
    

	 }
	 

 int consultar()

  {
  	setlocale(LC_ALL, "portuguese");
  	
  	
 	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado; \n");
	scanf("%S",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	
	{
		printf("N�o foi possivel abrir, arquivo n�o localizado!\n");
		
	}
   
    while(fgets(conteudo, 200, file) != NULL )

    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	
	}

	system("pause");
 
  }
 
 int deletar()
 
 {
    char cpf[40];

    printf("digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen("cpf", "r");
	
	if(file == NULL) 
	{
		printf("usuario n�o cadastrado!. \n");
		system("pause");		
	}   
	

 } 


 int main()
 {
    int opcao=0;//definindo variavel
    int x=1;//x = la�o
    
    
    for(x=1;x=1;)
    {
    
	  system("cls");	
		
    	
        setlocale(LC_ALL, "portuguese"); //DEFININDO A LIGUAGEM
    
            	printf("_____CART�RIO DO IGOR_____\n\n"); //TITULO DO MENU 	
                printf("ESCOLHA A OP��O DESEJADA:\n\n"); //INICIO DO MENU
 	            printf("\t1 - Registrar nomes\n");
 	            printf("\t2 - Consultar nomes\n");
 	            printf("\t3 - Deletar nomes\n\n\n");
				printf("Op��o:");  //FIM DO MENU
 	
 	
    scanf("%d", &opcao);//armazenando a escolha 
    system("cls");//variavel de limpeza
    switch(opcao)//switch subistituindo o IF
    {
    	case 1:
        registro(); //chamado de fun��es
        break;
        	    
        case 2:
        consultar(); 
        break; 
        	    
        case 3:
        deletar();
        break;
         
	
        default:
         printf("op��o invalida\n");
		 system("pause");
				break;
	}///fim da sele��o 
    
       
    }
     
}
