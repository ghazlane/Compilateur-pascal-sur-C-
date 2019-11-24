#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compile.h"
#define TRUE 0
#define FALSE 1

void OuvrirFichier(){
 fileCodeExecute = fopen(FichierCodeToCompile, "r");
}

void LireCaractere(){
 caractereCourant = tolower(fgetc(fileCodeExecute));
}

void initialisation(){
    //initialiser le tableau tableauMotClesDisplay
    strcpy(tableauMotClesDisplay[0],"PROGRAM_TOKEN");
    strcpy(tableauMotClesDisplay[1],"CONST_TOKEN");
    strcpy(tableauMotClesDisplay[2],"VAR_TOKEN");
    strcpy(tableauMotClesDisplay[3],"BEGIN_TOKEN");
    strcpy(tableauMotClesDisplay[4],"END_TOKEN");
    strcpy(tableauMotClesDisplay[5],"IF_TOKEN");
    strcpy(tableauMotClesDisplay[6],"THEN_TOKEN");
    strcpy(tableauMotClesDisplay[7],"WHILE_TOKEN");
    strcpy(tableauMotClesDisplay[8],"DO_TOKEN");
    strcpy(tableauMotClesDisplay[9],"READ_TOKEN");
    strcpy(tableauMotClesDisplay[10],"WRITE_TOKEN");
    //initialisation du tableau tableauMotCles
    strcpy(tableauMotCles[0],"program");
    strcpy(tableauMotCles[1],"const");
    strcpy(tableauMotCles[2],"var");
    strcpy(tableauMotCles[3],"begin");
    strcpy(tableauMotCles[4],"end");
    strcpy(tableauMotCles[5],"if");
    strcpy(tableauMotCles[6],"then");
    strcpy(tableauMotCles[7],"while");
    strcpy(tableauMotCles[8],"do");
    strcpy(tableauMotCles[9],"read");
    strcpy(tableauMotCles[10],"write");
    memset(mot_courant, 0, sizeof (mot_courant));
    taille_tableau_resultat_analyse_lexicale = 0 ;
    element_courant_dans_le_tableau_resultat_lexical = 0;
}

void LireMot(){
    int i ;
    memset (mot_courant, 0, sizeof (mot_courant));
    while(symoble_speciale() == TRUE){
        mot_courant[strlen(mot_courant)] = caractereCourant;
        LireCaractere();
    }
    for(i=0 ; i<11;i++){
        if(strcasecmp(tableauMotCles[i],mot_courant) == 0){
            printf("%s =====> %s\n",mot_courant,tableauMotClesDisplay[i]);
            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],tableauMotClesDisplay[i]);
            taille_tableau_resultat_analyse_lexicale++;
            return;
        }
    }
    printf("%s ===> %s\n",mot_courant,"ID_TOKEN");
    strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"ID_TOKEN");
    taille_tableau_resultat_analyse_lexicale++;
}

int symoble_speciale(){
if(caractereCourant != '<' && caractereCourant != '>' && caractereCourant != '(' && caractereCourant != ')' && caractereCourant != ':' && caractereCourant != '\n' && caractereCourant != ' ' && caractereCourant != '='&& caractereCourant != '+' && caractereCourant != ';'&& caractereCourant != '.'&& caractereCourant != '-'&& caractereCourant != '*'&& caractereCourant != '/'&& caractereCourant != ','){
    return TRUE;
}else return FALSE;
}

void LireNumber(){
    memset (mot_courant, 0, sizeof (mot_courant));
    while(caractereCourant >= '0' && caractereCourant <= '9'){
        mot_courant[strlen(mot_courant)] = caractereCourant;
        LireCaractere();
    }
    if(caractereCourant==' ' || caractereCourant=='\n' || caractereCourant == '<' || caractereCourant == '>' || caractereCourant == '(' || caractereCourant == ')' || caractereCourant == ':' || caractereCourant == '\n' || caractereCourant == ' ' || caractereCourant == '=' ||  caractereCourant == '+' || caractereCourant == ';'|| caractereCourant == '.'|| caractereCourant == '-'|| caractereCourant == '*' || caractereCourant == '/'|| caractereCourant == ',')
        {printf("%s =====> NUM_TOKEN\n",mot_courant);
        strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"NUM_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
    }else {
            while(caractereCourant!=' ' && caractereCourant!='\n' && caractereCourant != '<' && caractereCourant != '>' && caractereCourant != '(' && caractereCourant != ')' && caractereCourant != ':' && caractereCourant != '\n' && caractereCourant != ' ' && caractereCourant != '='&& caractereCourant != '+' && caractereCourant != ';'&& caractereCourant != '.'&& caractereCourant != '-'&& caractereCourant != '*'&& caractereCourant != '/'&& caractereCourant != ','){
        mot_courant[strlen(mot_courant)] = caractereCourant;
        LireCaractere();
    }
          printf("%s =====> ERRUR_TOKEN\n",mot_courant) ;
          strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"ERRUR_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
        }
}

void CloseFile(){
    fclose(fileCodeExecute);
}

void LireCaracterSpecialOrError(){
            switch(caractereCourant){
                case '=' : printf("%c =====> EG_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"EG_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case '+' : printf("%c =====> PLUS_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"PLUS_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case ';' : printf("%c =====> PV_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"PV_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case '.' : printf("%c =====> PT_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"PT_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case '-' : printf("%c =====> MOINS_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"MOINS_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case '*' : printf("%c =====> MULT_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"MULT_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case '/' : printf("%c =====> DIV_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"DIV_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case ',' : printf("%c =====> VIR_TOKEN\n",caractereCourant);
                           strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"VIR_TOKEN");
                           taille_tableau_resultat_analyse_lexicale++;
                           LireCaractere();
                                break ;
                case ':' : LireCaractere();
                           if(caractereCourant == '='){
                            printf(":= =====> AFF_TOKEN\n");
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"AFF_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                           }
                           break ;
                case '(' : printf("%c =====> PO_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"PO_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case ')' : printf("%c =====> PF_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"PF_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                                break ;
                case '>' : LireCaractere();
                           if(caractereCourant == '='){
                            printf(">= =====> SUPEG_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"SUPEG_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                           }else {
                            printf("%c =====> SUP_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"SUP_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                           }
                           break;
                case '<' : LireCaractere();
                           if(caractereCourant == '='){
                            printf("<= =====> INFEG_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"INFEG_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                           }else if(caractereCourant == '>'){
                               printf("<> =====> DIFF_TOKEN\n",caractereCourant);
                               strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"DIFF_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                            LireCaractere();
                           }else {
                            printf("< =====> INF_TOKEN\n",caractereCourant);
                            strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"INF_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                           }
                           break;
                case ' ' : LireCaractere();
                            break;
                case '\n' : LireCaractere();
                            break;
                default :
                    printf("%c =====> ERREUR_TOKEN\n", caractereCourant);
                    strcpy(tableauResultatAnalyseLexical[taille_tableau_resultat_analyse_lexicale],"ERREUR_TOKEN");
                            taille_tableau_resultat_analyse_lexicale++;
                    LireCaractere();
            }
}
