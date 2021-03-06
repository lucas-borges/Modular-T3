/***************************************************************************
*
*  $MCD M�dulo de defini��o: LAB Labirinto
*
*  Arquivo gerado:              LABIRINTO.h
*  Letras identificadoras:      LAB
*
*  Projeto: INF 1301 Automatiza��o dos testes de m�dulos C
*  Gestor:  DI/PUC-Rio
*  Autores: cs  -  Clara Szwarcman
*			gs  -  Guilherme Simas
*			lb  -  Lucas Borges
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     1      csgslb 11/out/2014 in�cio desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa um labirinto utilizando um
*	  grafo n�o direcionado gen�rico. S� � poss�vel existir
*	  um labirinto em opera��o por vez.
*
*************************************************************************/

/***********************************************************************
*
*  $TC Tipo de dados: LAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do labirinto
*
***********************************************************************/

   typedef enum {

         LAB_CondRetOK ,
               /* Concluiu corretamente */
		 LAB_CondRetLabirintoNaoExiste,
			   /* Labirinto n�o foi criado */
		 LAB_CondRetNaoExisteCaminho,
			   /* Nao existe caminho entre as celulas */
		 LAB_CondRetErroArquivo,
			   /* Erro ao abrir ou gerar o arquivo */
		 LAB_CondRetSaida,
			   /* Corrente se encontra na sa�da */
		 LAB_CondRetForaLab,
			   /* Caminho vai para fora da �rea do labirinto */
		 LAB_CondRetMemoria,
			   /* Nao ha memoria suficiente para alocar a estrutura */
		 LAB_CondRetCaminhoJaExiste
			  /* Ja existe caminho entre as celulas do Labirinto*/
   } LAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: LAB  &Criar Labirinto
*
*  $ED Descri��o da fun��o
*      Cria um labirinto est�tico utilizando um grafo n�o direcionado
*	   gen�rico.
*
*  $EP Par�metros
*		altura - n�mero de c�lulas de altura do labirinto
*		largura - n�mero de c�lulas de largura do labirinto
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou labirinto sem problemas
*		LAB_CondRetMemoria - faltou mem�ria ao alocar espa�o
*
*  $AE Assertivas de entrada
*		- labirinto n�o existe
*		- altura � um valor v�lido (inteiro positivo e menor que 39)
*		- largura � um valor v�lido (inteiro positivo e menot que 39)
*
*  $AS Assertivas de sa�da
*		- labirinto foi criado
*		- valem as assertivas estruturais do grafo
*
***********************************************************************/

   LAB_tpCondRet LAB_CriarLab (int altura, int largura);

   /***********************************************************************
*
*  $FC Fun��o: LAB  &Criar Caminho
*
*  $ED Descri��o da fun��o
*      Cria caminho entre duas c�lulas do labirinto
*
*  $EP Par�metros
*		x - coordenada x da c�lula apartir da qual o caminho ser� criado
*		y - coordenada y da c�lula apartir da qual o caminho ser� criado
*		direcao - direcao para a qual se quer criar o caminho
*
*  $FV Valor retornado
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*		LAB_CondRetOK - criou caminho sem problemas
*		LAB_CondRetForaLab - caminho para a direcao desejada 
*							esta fora dos limites do labirinto
*		LAB_CondRetCaminhoJaExiste - caminho para a direcao desejada
*									 ja existia
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*		- x � um valor de coordenada v�lido (inteiro positivo e menor que largura)
*		- y � um valor de coordenada v�lido (inteiro positivo e menor que altura)
*		- direcao � um valor v�lido (caracter = 'n' ou 's' ou 'l' ou 'o')
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o caminho da celula para a direcao 
*			desejada nao existia, ele foi criado
*
***********************************************************************/

	LAB_tpCondRet LAB_CriarCaminho (int x, int y, char direcao);

/***********************************************************************
*
*  $FC Fun��o: LAB  &Mostra Lab
*
*  $ED Descri��o da fun��o
*      Imprime labirinto na tela
*
*  $EP Par�metros
*		
*  $FV Valor retornado
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*		LAB_CondRetOK - mostrou labirinto sem problemas
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o labirinto existe, ele � mostrado na tela
*
***********************************************************************/

	LAB_tpCondRet LAB_MostraLab ( void );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Criar Entrada
*
*  $ED Descri��o da fun��o
*      Cria entrada do labirinto.
*
*  $EP Par�metros
*		x - coordenada x da c�lula de entrada
*		y - coordenada y da c�lula de entrada
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou entrada sem problemas
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*		- x � um valor de coordenada v�lido
*		- y � um valor de coordenada v�lido
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o labirinto existe, a entrada foi criada
*
***********************************************************************/

	LAB_tpCondRet LAB_CriarEntrada (int x, int y );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Criar Saida
*
*  $ED Descri��o da fun��o
*      Cria saida do labirinto.
*
*  $EP Par�metros
*		x - coordenada x da c�lula de saida
*		y - coordenada y da c�lula de saida
*
*  $FV Valor retornado
*		LAB_CondRetOK - criou saida sem problemas
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*		- x � um valor de coordenada v�lido
*		- y � um valor de coordenada v�lido
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o labirinto existe, a saida foi criada
*
***********************************************************************/

	LAB_tpCondRet LAB_CriarSaida (int x, int y );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Andar
*
*  $ED Descri��o da fun��o
*      Anda para uma c�lula vizinha
*
*  $EP Par�metros
*		direcao - direcao para a qual se quer andar
*
*  $FV Valor retornado
*		LAB_CondRetOK - andou sem problemas
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*		LAB_CondRetNaoExisteCaminho - n�o existe caminho para a dire��o desejada
*		LAB_CondRetSaida - c�lula na dire��o desejada � a saida do labirinto
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*		- direcao � um valor v�lido
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o labirinto existe e existe caminho para a direcao desejada,
*		  a posicao no labirinto � alterada
*
***********************************************************************/

	LAB_tpCondRet LAB_Andar (char direcao );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Carrega
*
*  $ED Descri��o da fun��o
*      Carrega um labirinto a partir de um arquivo
*
*  $EP Par�metros
*		nome_entrada - ponteiro para nome do arquivo a partir do qual 
*					   se deseja carregar o labirinto
*
*  $FV Valor retornado
*		LAB_CondRetOK - carregou labirinto sem problemas
*		LAB_CondRetErroArquivo - n�o foi possivel abrir o arquivo
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se foi possivel abrir o arquivo, o labirinto foi carregado
*		  (sua entrada, saida, vertices e caminhos foram criados)
*
***********************************************************************/

	LAB_tpCondRet LAB_Carregar ( char * nome_entrada );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Solucionar Lab
*
*  $ED Descri��o da fun��o
*      Encontra caminho at� a saida do labirinto
*
*  $EP Par�metros
*		buffer_solucao - referencia para ponteiro do buffer 
*						no qual o caminho ser� armazenado
*
*  $FV Valor retornado
*		LAB_CondRetOK - solucionou labirinto sem problemas
*		LAB_CondRetLabirintoNaoExiste - n�o existe labirinto
*		LAB_CondRetNaoExisteCaminho - n�o existe caminho para a dire��o desejada
*		LAB_CondRetMemoria - faltou mem�ria ao alocar espa�o
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*		- buffer_solucao � um ponteiro valido
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o labirinto existe e a solucao � possivel o caminho ate a saida 
*		  � alocado no buffer_solucao caso este tenha sido fornecido
*
***********************************************************************/

	LAB_tpCondRet LAB_SolucionarLab ( int *** buffer_solucao );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Salvar
*
*  $ED Descri��o da fun��o
*      Salva um labirinto em um arquivo
*
*  $EP Par�metros
*		nome_saida - ponteiro para nome do arquivo no qual
*					 se deseja salvar o labirinto
*
*  $FV Valor retornado
*		LAB_LabirintoNaoExiste - n�o existe labirinto
*		LAB_CondRetOK - salvou labirinto sem problemas
*		LAB_CondRetErroArquivo - n�o foi possivel abrir o arquivo
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*
*  $AS Assertivas de sa�da
*		- Valem as assertivas estruturais do grafo
*		- Se o labirinto existe e foi possivel abrir o arquivo
*		  o labirinto foi salvo em um arquivo com o nome_saida
*
***********************************************************************/

	LAB_tpCondRet LAB_Salvar ( char * nome_saida );

/***********************************************************************
*
*  $FC Fun��o: LAB  &Destruir
*
*  $ED Descri��o da fun��o
*      Destr�i o labirinto se este existir
*
*  $EP Par�metros
*
*  $FV Valor retornado
*
*  $AE Assertivas de entrada
*		- Valem as assertivas estruturais do grafo
*
*  $AS Assertivas de sa�da
*		- Se o labirinto existia ele foi destruido
*
***********************************************************************/
	
	void LAB_DestruirLab ( void );



/********** Fim do m�dulo de defini��o: LAB Labirinto **********/
