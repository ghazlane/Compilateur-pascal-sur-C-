#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

char tableauMotClesDisplay[11][50] = {"program","constante","var","begin","end","if","then","while","do","read","write"};

int main()
{
    int i,compteur_verification;
    initialisation();
    OuvrirFichier();
    LireCaractere();
    while(!feof(fileCodeExecute)){
        if((caractereCourant<='z' && caractereCourant>= 'a')){
            LireMot();
        }else if(caractereCourant<='9' && caractereCourant>= '0')
            LireNumber();
        else if(caractereCourant == '{')
                PasserCommentaire();
        else
            LireCaracterSpecialOrError();
    }
    /*
    for(compteur_verification=0; compteur_verification<taille_tableau_resultat_analyse_lexicale; compteur_verification++){
        printf("%s\t", tableauResultatAnalyseLexical[compteur_verification]);
    }
    */
    //analyse syntaxique
    num_token_courant= 0;
    CloseFile();
    analyseSybtaxique();
    return 0;
}
