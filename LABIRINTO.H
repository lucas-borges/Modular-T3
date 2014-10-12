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
*     
*
*
*
*************************************************************************/


/***** Declara��es exportadas pelo m�dulo *****/

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

   } LAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: GRF  &Criar Labirinto
*
*  $ED Descri��o da fun��o
*    
*  $EP Par�metros
*
*  $FV Valor retornado
*
*  $AE Assertivas de entrada
*
*  $AS Assertivas de sa�da
*
***********************************************************************/
void LAB_CriarLab (int altura, int largura);
void LAB_CriarCaminho (int x, int y, char direcao);
void LAB_MostraLab ( void );


/********** Fim do m�dulo de defini��o: GRF Grafo n�o orientado **********/