char tableauMotClesDisplay[11][50];
char tableauMotCles[11][20];
char tableauReglesLexicaux[16][20];
char tableauReglesLexicauxDisplay[16][20];
FILE * fileCodeExecute;
FILE * fichierResutatAnalyseLexical;
char caractereCourant;
char mot_courant[20];
int taille_tableau_resultat_analyse_lexicale;
int element_courant_dans_le_tableau_resultat_lexical;
char tableauResultatAnalyseLexical[400][20];

//declaration analyse syntaxique
int num_token_courant; // pour parcouriir le tableau qui contient le resultat de l'analyse lexicale


