#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "analyseSyntaxique.h"
#include <unistd.h>
#define TRUE 0
#define FALSE 1

    char * code_erreur = "Code erreur";
    char * code_erreur2 = "Code erreur test";
    char * id_token = "ID_TOKEN";
    char * pv_token = "PV_TOKEN";
    char * pt_token = "PT_TOKEN";
    char * EG_TOKEN = "EG_TOKEN";
    char * NUM_TOKEN = "NUM_TOKEN";
    char * VIR_TOKEN = "VIR_TOKEN";
    char * AFF_TOKEN = "AFF_TOKEN";
    char * PO_TOKEN = "PO_TOKEN";
    char * PF_TOKEN = "PF_TOKEN";
    char * DIFF_TOKEN = "DIFF_TOKEN";
    char * INFEG_TOKEN = "INFEG_TOKEN";
    char * INF_TOKEN = "INF_TOKEN";
    char * SUPEG_TOKEN = "SUPEG_TOKEN";
    char * SUP_TOKEN = "SUP_TOKEN";
    char * PLUS_TOKEN = "PLUS_TOKEN";
    char * MOINS_TOKEN = "MOINS_TOKEN";
    char * MULT_TOKEN = "MULT_TOKEN";
    char * DIV_TOKEN = "DIV_TOKEN";


void analyseSybtaxique(){
    PROGRAM();
}

void PROGRAM(){
    printf("\nstart program");
    Test_Symbole(tableauMotClesDisplay[0], code_erreur);
    Test_Symbole(id_token, code_erreur);
    Test_Symbole(pv_token, code_erreur);
    BLOCK();
    Test_Symbole("PT_TOKEN", code_erreur);
    printf("\n end Programm");
}
void BLOCK(){
    printf("\nstart BLOCK ");
    CONSTS();
    VARS();
    INSTS();
    printf("\n End BLOCK");
}
void CONSTS(){
    printf("\nstart CONST");
    if(strcmp(tableauMotClesDisplay[1], tableauResultatAnalyseLexical[num_token_courant])==0){
    printf("\n test Const Valide");
    Test_Symbole(tableauMotClesDisplay[1], code_erreur);
    Test_Symbole(id_token, code_erreur);
    Test_Symbole(EG_TOKEN, code_erreur);
    Test_Symbole(NUM_TOKEN, code_erreur);
    Test_Symbole(pv_token, code_erreur);
    while(strcmp(id_token, tableauResultatAnalyseLexical[num_token_courant])==0){
        Test_Symbole(id_token, code_erreur);
        Test_Symbole(EG_TOKEN, code_erreur);
        Test_Symbole(NUM_TOKEN, code_erreur);
        Test_Symbole(pv_token, code_erreur);
    }
}
printf("\n End CONST");
}

void VARS(){
    printf("\nstart VARS");
    if(strcmp(tableauMotClesDisplay[2], tableauResultatAnalyseLexical[num_token_courant])==0){
        Test_Symbole(tableauMotClesDisplay[2], code_erreur);
        Test_Symbole(id_token, code_erreur);
        while(strcmp(VIR_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0){
         Test_Symbole(VIR_TOKEN, code_erreur);
         Test_Symbole(id_token, code_erreur);
        }
        Test_Symbole(pv_token, code_erreur);
    }
    printf("\n End VARS");
}

void INSTS(){
    printf("\nstart INSTS");
    Test_Symbole(tableauMotClesDisplay[3], code_erreur);
    INST();
    while(strcmp(pv_token, tableauResultatAnalyseLexical[num_token_courant])==0){
        Test_Symbole(pv_token, code_erreur);
        INST();
    }
     Test_Symbole(tableauMotClesDisplay[4], code_erreur2);
    printf("\n End INSTS");
}

void INST(){
    printf("\nstart INST");
    if(strcmp(tableauMotClesDisplay[3], tableauResultatAnalyseLexical[num_token_courant])==0) INSTS();
    if(strcmp(id_token, tableauResultatAnalyseLexical[num_token_courant])==0) AFFEC();
    if(strcmp(tableauMotClesDisplay[5], tableauResultatAnalyseLexical[num_token_courant])==0) SI();
    if(strcmp(tableauMotClesDisplay[7], tableauResultatAnalyseLexical[num_token_courant])==0) TANTQUE();
    if(strcmp(tableauMotClesDisplay[10], tableauResultatAnalyseLexical[num_token_courant])==0) ECRIRE();
    if(strcmp(tableauMotClesDisplay[9], tableauResultatAnalyseLexical[num_token_courant])==0) LIRE();
    printf("\n End INST");
}
void AFFEC(){
    printf("\n Start AFEC");
   Test_Symbole(id_token, code_erreur);
   Test_Symbole(AFF_TOKEN, code_erreur);
   EXPR();
   printf("\n End AFEC");
}
void SI(){
    printf("\n Start SI");
    Test_Symbole(tableauMotClesDisplay[5], code_erreur);
    COND();
    Test_Symbole(tableauMotClesDisplay[6], code_erreur);
    INST();
    printf("\n End SI");
}
void TANTQUE(){
    printf("\n start TANQUE");
    Test_Symbole(tableauMotClesDisplay[7], code_erreur);
    COND();
    Test_Symbole(tableauMotClesDisplay[8], code_erreur);
    INST();
    //_sleep(5000);
    //sleep(1000);
    printf("\n End TANTQUE");
}

void ECRIRE(){
    printf("\n start ECRIRE");
    Test_Symbole(tableauMotClesDisplay[10], code_erreur);
    Test_Symbole(PO_TOKEN, code_erreur);
    EXPR();
    while(strcmp(VIR_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0){
       Test_Symbole(VIR_TOKEN, code_erreur);
       EXPR();
    }
    Test_Symbole(PF_TOKEN, code_erreur);
    printf("\n End ECRIRE");
}
void LIRE(){
    printf("\n Start LIRE");
    Test_Symbole(tableauMotClesDisplay[9], code_erreur);
    Test_Symbole(PO_TOKEN, code_erreur);
    Test_Symbole(id_token, code_erreur);
     while(strcmp(VIR_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0){
       Test_Symbole(VIR_TOKEN, code_erreur);
       Test_Symbole(id_token, code_erreur);
    }
    Test_Symbole(PF_TOKEN, code_erreur);
    printf("\n End LIRE");
}
void COND(){
    printf("\n Start COND");
    EXPR();
    RELOP();
    EXPR();
    printf("\n End COND");
}
void RELOP(){
    printf("\n Strat RELOP");
    if(strcmp(EG_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(EG_TOKEN, code_erreur);
    else if(strcmp(DIFF_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(DIFF_TOKEN, code_erreur);
    else if(strcmp(INFEG_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(INFEG_TOKEN, code_erreur);
    else if(strcmp(SUP_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(SUP_TOKEN, code_erreur);
    else if(strcmp(SUPEG_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(SUPEG_TOKEN, code_erreur);
    else
        Test_Symbole(INF_TOKEN, code_erreur);
    printf("\n End RELOP");
}
void EXPR(){
    printf("\n Strat EXPR");
    TERM();
    if((strcmp(MOINS_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0) || (strcmp(PLUS_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)){
        ADDOP();
        TERM();
    }
printf("\n End EXPR");
}
void ADDOP(){
    printf("\n Start ADDOP");
    if(strcmp(MOINS_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(MOINS_TOKEN, code_erreur);
    else
        Test_Symbole(PLUS_TOKEN, code_erreur);
        printf("\n End ADDOP");
}
void TERM(){
    printf("\n Start TERM");
    FACT();
    if(strcmp(MULT_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0 || strcmp(DIV_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0){
        MULOP();
        FACT();
    }
printf("\n End TERM");
}
void MULOP(){
    printf("\n Start MULOP");
    if(strcmp(MULT_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(MULT_TOKEN, code_erreur);
    else
        Test_Symbole(DIV_TOKEN, code_erreur);
printf("\n End MULOP");
}
void FACT(){
    printf("\n Start FACT");
    if(strcmp(id_token, tableauResultatAnalyseLexical[num_token_courant])==0)
        Test_Symbole(id_token, code_erreur);
    else if(strcmp(NUM_TOKEN, tableauResultatAnalyseLexical[num_token_courant])==0)
         Test_Symbole(NUM_TOKEN, code_erreur);
    else{
        Test_Symbole(PO_TOKEN, code_erreur);
        EXPR();
        Test_Symbole(PF_TOKEN, code_erreur);
    }
    printf("\n End FACT");
}

void Test_Symbole (char * classe_lexical, char * COD_ERR){
if (strcmp(classe_lexical, tableauResultatAnalyseLexical[num_token_courant])==0)
{
    num_token_courant++;
    printf("\n %s ===> parfait",classe_lexical);
}
else
    printf("\n%s === >%s\n",classe_lexical,COD_ERR);
}

