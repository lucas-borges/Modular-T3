#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "LABIRINTO.H"


/***** Prot�tipos das fun��es *****/

void Titulo ( void );
void MenuPrincipal ( void ) ;
void JogarLab ( void );
char ConvDir (int cod);
void TelaPrbs ( void );
int ReobterEntrada ( void );
void CriarLab ( void );
void ObtemPosicaoValida(int altura,int largura,int *x,int *y);
void limpa_stdin(void);


/***************************************************************************
*
*  Fun��o: Main
*****/
int main (void)
{
	int entrada;

	MenuPrincipal();

	printf("Entre sua escolha: ");
	scanf(" %d",&entrada);
	limpa_stdin();

	while (entrada!=4) 
	{
		/* tratar criar labirinto */
		if(entrada==1)
		{
			system("cls");
			CriarLab();
		}
		/* tratar carregar arquivo */
		else if (entrada == 2)
		{
			char arq[35];
			
			printf("\nQual o nome do arquivo? (maximo de 30 caracteres)\n");
			scanf(" %30[^\n]",arq);
			strcat(arq,".lab");
			if(LAB_Carregar(arq)==LAB_CondRetErroArquivo)
			{
				printf("\nERRO: Erro ao abrir arquivo.\n\n");
				system("pause");
			}
			else
			{
				system("cls");
				JogarLab();
			} /* if */	
		}
		/* tratar abrir arquivo demo */
		else if (entrada == 3)
		{

			if(LAB_Carregar("lab_demo.lab")==LAB_CondRetErroArquivo)
			{
				printf("\nERRO: Erro ao abrir arquivo.\n\n");
				system("pause");
			}
			else
			{
				system("cls");
				JogarLab();
			} /* if */
		}
		else
		{
			entrada=ReobterEntrada();
		} /* if */

		system("cls");
		MenuPrincipal();

		printf("Entre sua escolha: ");
		scanf("%d",&entrada);
		limpa_stdin();

	} /* while */

	LAB_DestruirLab();

	return 0;
} /* Fim fun��o: Main */

/***************************************************************************
*
*  Fun��o: Mostrar titulo
*****/
void Titulo ( void )
{
		printf("\n\n");
	printf("\t\t _           _     _      _       _        \n"
		   "\t\t| |         | |   (_)    (_)     | |       \n"
		   "\t\t| |     __ _| |__  _ _ __ _ _ __ | |_ ___  \n"
		   "\t\t| |    / _` | '_ \\| | '__| | '_ \\| __/ _ \\ \n"
		   "\t\t| |___| (_| | |_) | | |  | | | | | || (_) |\n"
		   "\t\t\\_____/\\__,_|_.__/|_|_|  |_|_| |_|\\__\\___/ \n"
		   "                                           \n"
		   "                                           \n");

} /* Fim fun��o: Mostrar titulo */

/***************************************************************************
*
*  Fun��o: Menu Principal
*****/
void MenuPrincipal ( void ) {

	Titulo();
	printf("\t\t\tMENU PRINCIPAL\n"
			"\t\t\t1 - Criar um labirinto\n"
			"\t\t\t2 - Carregar um labirinto\n"
			"\t\t\t3 - Jogar labirinto demo\n"
			"\t\t\t4 - Sair\n");

	printf("\n\n");
} /* Fim fun��o: Menu principal */

/***************************************************************************
*
*  Fun��o: Jogar labirinto
*****/
void JogarLab ( void )
{
	int entrada;
	system("cls");
	LAB_MostraLab();

	printf("\n\n1 - Mover-se para Sul\n"
			"2 - Mover-se para Norte\n"
			"3 - Mover-se para Oeste\n"
			"4 - Mover-se para Leste\n"
			"5 - Ver caminho solucao\n"
			"6 - Voltar ao menu principal\n\n"
			"Escolha uma das opcoes: ");
	scanf("%d",&entrada);
	limpa_stdin();

	while (entrada<1 || entrada >6)
	{
		entrada=ReobterEntrada();
	} /* while */

	while ( 1 )
	{
		if (entrada >=1 && entrada <= 4)
		{
			if (LAB_Andar(ConvDir(entrada))==LAB_CondRetSaida)
			{
				LAB_DestruirLab();
				TelaPrbs();
				return;
			} /* if */
		}
		else if(entrada == 5)
		{
			int i=1, j=0, ret;
			int ** solucao;
			ret=LAB_SolucionarLab ( &solucao );
			printf("\n");
			if (ret == LAB_CondRetOK)
			{
				printf("O caminho ate a saida e: ");
				while (solucao[i][0]!=-1)
				{
					printf("(%d,%d) ",solucao[i][0],solucao[i][1]);
					i++;
				} /* while */
				printf("\n\n");
				system("pause");
				free(solucao);
			}
			else if (ret == LAB_CondRetNaoExisteCaminho)
			{
				printf("Labirinto impossivel, nao existe caminho ate a saida!!\n\n");
				system("pause");
			} /* if */
		}

		else if (entrada ==6)
		{
			int resp;
			system("cls");
			printf("Tem certeza que quer voltar ao menu principal?\n"
					"O progresso de seu jogo sera perdido.\n"
					"1 - SIM\n"
					"2 - NAO\n");
			scanf("%d", &resp);
			limpa_stdin();

			while (resp !=1 && resp!=2)
			{
				resp=ReobterEntrada();
			} /* while */
			if (resp == 1 )
			{
				LAB_DestruirLab();
				return; 
			} /* if */

		} /* if */
		
		system("cls");
		LAB_MostraLab();

		printf("\n\n1 - Mover-se para Sul\n"
				"2 - Mover-se para Norte\n"
				"3 - Mover-se para Oeste\n"
				"4 - Mover-se para Leste\n"
				"5 - Ver caminho solucao\n"
				"6 - Voltar ao menu principal\n\n"
				"Escolha uma das opcoes: ");
		scanf("%d",&entrada);
		limpa_stdin();

		while (entrada<1 || entrada >6)
		{
			entrada=ReobterEntrada();
		} /* while */
	}
}/* Fim fun��o: Jogar labirinto */

/***************************************************************************
*
*  Fun��o: Converter dire��o
*****/
char ConvDir (int cod)
{
	if (cod == 1)
	{
		return 's';
	}
	else if (cod == 2)
	{
		return 'n';
	}
	else if (cod == 3)
	{
		return 'o';
	}
	else
	{
		return 'l';
	} /* if */

} /* Fim fun��o: Converter dire��o */

/***************************************************************************
*
*  Fun��o: Tela parab�ns
*****/
void TelaPrbs ( void )
{
	system("cls");
	printf("\n\n\t _____        _____            ____  ______ _   _  _____ _ _ \n"
			"\t|  __ \\ /\\   |  __ \\     /\\   |  _ \\|  ____| \\ | |/ ____| | |\n"
			"\t| |__) /  \\  | |__) |   /  \\  | |_) | |__  |  \\| | (___ | | |\n"
			"\t|  ___/ /\\ \\ |  _  /   / /\\ \\ |  _ <|  __| | . ` |\\___ \\| | |\n"
			"\t| |  / ____ \\| | \\ \\  / ____ \\| |_) | |____| |\\  |____) |_|_|\n"
			"\t|_| /_/    \\_\\_|  \\_\\/_/    \\_\\____/|______|_| \\_|_____/(_|_)\n\n\n");
	system("pause");
} /* Fim fun��o: Tela parab�ns */

/***************************************************************************
*
*  Fun��o: Reobter entrada
*****/
int ReobterEntrada ( void )
{
	int entrada;
	printf("Opcao invalida, por favor escolha uma das listadas acima: ");
	scanf("%d", &entrada);
	limpa_stdin();

	return entrada;
} /* Fim fun��o: Reobter entrada */

/***************************************************************************
*
*  Fun��o: Criar labirinto
*****/
void CriarLab ( void )
{
	int altura, largura, x,y,x2,y2, entrada;
	LAB_tpCondRet lab_ret; 
	LAB_DestruirLab();
	printf("Criando Labirinto...\n\n");
	Titulo();

	printf("Quantas celulas de altura deve ter o labirinto? (Maximo de 38)\n");
	scanf("%d",&altura);
	limpa_stdin();
	while(altura<=0 || altura >38)
	{
		printf("Altura invalida, forneca uma entre 1 e 38: ");
		scanf("%d",&altura);
		limpa_stdin();
	} /* while */

	printf("Quantas celulas de largura deve ter o labirinto? (Maximo de 38)\n");
	scanf("%d",&largura);
	limpa_stdin();
	while(largura<=0 || largura >38)
	{
		printf("Largura invalida, forneca uma entre 1 e 38: ");
		scanf("%d",&largura);
		limpa_stdin();
	} /* while */

	LAB_CriarLab(altura,largura);

	system("cls");
	printf("Criando Labirinto...\n\n");
	LAB_MostraLab();

	printf("\n\nQual a posicao da entrada? (x,y)\n");
	ObtemPosicaoValida(altura,largura,&x,&y);
	LAB_CriarEntrada(x,y);

	printf("\nQual a posicao da saida? (x,y)\n");
	ObtemPosicaoValida(altura,largura,&x2,&y2);
	while (x==x2 && y==y2) 
	{
		printf("\nJa e a entrada. Qual a posicao da saida? (x,y)\n");
		ObtemPosicaoValida(altura,largura,&x2,&y2);
	}
	LAB_CriarSaida(x2,y2);

	system("cls");
	printf("Criando Labirinto...\n\n");
	LAB_MostraLab();

	printf("\nComandos:\n"
			"1 - Selecionar celula para criar caminho\n"
			"2 - Salvar\n"
			"3 - Jogar!\n"
			"4 - Voltar ao menu principal\n"
			"\nEscolha uma das opcoes: ");
	scanf("%d", &entrada);
	limpa_stdin();

	while (entrada<1 || entrada >4)
	{
		entrada=ReobterEntrada();
	} /* while */

	while ( 1 )
	{
		if (entrada ==1 )
		{
			printf("\nQual a celula? (x,y)\n");
			ObtemPosicaoValida(altura,largura,&x,&y);


			printf("\nSelecione uma direcao para o caminho:\n"
				"1 - Caminho para Sul\n"
				"2 - Caminho para Norte\n"
				"3 - Caminho para Oeste\n"
				"4 - Caminho para Leste\n"
				"5 - Voltar\n"
				"\nEscolha uma das opcoes: ");
			scanf("%d",&entrada);
			limpa_stdin();
			while (entrada<1 || entrada >5)
			{
				entrada=ReobterEntrada();
			} /* while */
			while (entrada !=5)
			{
				lab_ret = LAB_CriarCaminho(x,y,ConvDir(entrada));

				if (lab_ret == LAB_CondRetForaLab)
				{
					printf("Nao e possivel criar um caminho para fora do labirinto!!\n\n");
				}
				else if (lab_ret == LAB_CondRetCaminhoJaExiste)
				{
					printf("Caminho ja existe!\n\n");
				}
				else if (entrada == 1)
				{
					printf("Caminho ao Sul criado com sucesso.\n\n");
				}
				else if (entrada == 2)
				{
					printf("Caminho ao Norte criado com sucesso.\n\n");
				}
				else if (entrada == 3)
				{
					printf("Caminho ao Oeste criado com sucesso.\n\n");
				}
				else if (entrada == 4)
				{
					printf("Caminho ao Leste criado com sucesso.\n\n");
				} /* if */

				printf("Escolha uma das opcoes: ");
				scanf("%d",&entrada);
				limpa_stdin();
				while (entrada<1 || entrada >5)
				{
					entrada=ReobterEntrada();
				} /* while */
			} /* while */
		}
		else if (entrada == 2)
		{
				char arq[35];
				printf("\nQual o nome do arquivo? (maximo de 30 caracteres)\n");
				scanf(" %30[^\n]",arq);
				strcat(arq,".lab");

				if(LAB_Salvar(arq)==LAB_CondRetOK)
				{
					printf("\nLabirinto salvo com sucesso\n\n");
				} 
				else
				{
					printf("Erro ao salvar arquivo\n\n");
				} /* if */
				system("pause");
		}
		else if (entrada == 3)
		{
			int resp;
			
			printf("\nTem certeza que quer jogar?\n"
					"Perdera o progresso nao salvo do labirinto criado.\n"
					"1 - SIM\n"
					"2 - NAO\n");
			scanf("%d", &resp);
			limpa_stdin();

			while (resp !=1 && resp!=2)
			{
				resp=ReobterEntrada();
			} /* while */

			if (resp == 1 )
			{
				JogarLab(); 
				return;
			} /* if */
			
		}
		else if (entrada == 4)
		{
			int resp;
			
			printf("\nTem certeza que quer sair e voltar ao menu principal?\n"
					"Perdera o progresso nao salvo do labirinto criado.\n"
					"1 - SIM\n"
					"2 - NAO\n");
			scanf("%d", &resp);
			limpa_stdin();

			while (resp !=1 && resp!=2)
			{
				resp=ReobterEntrada();
			} /* while */

			if (resp == 1 )
			{
				LAB_DestruirLab();
				return; 
			} /* if */
		} /* if */

	
		system("cls");
		printf("Criando Labirinto...\n\n");
		LAB_MostraLab();

		printf("\nComandos:\n"
			"1 - Selecionar celula para criar caminho\n"
			"2 - Salvar\n"
			"3 - Jogar!\n"
			"4 - Voltar ao menu principal\n"
			"\nEscolha uma das opcoes: ");
		scanf("%d", &entrada);
		limpa_stdin();

		while (entrada<1 || entrada >4)
		{
			entrada=ReobterEntrada();
		} /* while */
	} /* while */
} /* Fim fun��o: Criar labirinto */

/***************************************************************************
*
*  Fun��o: Obt�m posi��o v�lida
*****/
void ObtemPosicaoValida(int altura,int largura,int *x,int *y)
{
	*x=-1;
	*y=-1;
	scanf("%d,%d",x,y);
	limpa_stdin();
	while (*x<1 || *x>largura )
	{
		printf("Posicao x invalida, forneca uma coordenada entre 1 e %d: ", largura);
		scanf("%d",x);
		limpa_stdin();
	} /* while */
	while ( *y<1 || *y>altura)
	{
		printf("Posicao y invalida, forneca uma coordenada entre 1 e %d: ", altura);
		scanf("%d",y);
		limpa_stdin();
	} /* while */
} /* Fim fun��o: Obt�m posi��o v�lida */

/***************************************************************************
*
*  Fun��o: Limpa stdin
*****/
void limpa_stdin(void)
{
    int c;

    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
} /* Fim fun��o: Limpa stdin */