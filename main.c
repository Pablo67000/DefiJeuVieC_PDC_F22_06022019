#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 10 //taille de la grille du jeu personnalisable

void initTableau(int mTableau[TAILLE][TAILLE]);
void compterVoisin(int mTableauBis[TAILLE][TAILLE],int mTableau[TAILLE][TAILLE]);
void changementCellule(int mTableau[TAILLE][TAILLE]);
void afficherTableau(int mTableau[TAILLE][TAILLE]);

int main()
{
    srand(time(NULL));
    int nCpt;
    int nNbrActualisation;
    int mTableau[TAILLE][TAILLE];
    printf("-------------------------------\n");
    printf("BIENVENUE DANS LE JEU DE LA VIE\n");
    printf("-------------------------------\n\n");
    printf("Entrez nombre d'actualisation de la grille : ");
    scanf("%d",&nNbrActualisation);
    printf("\n");
    initTableau(mTableau);
    printf("La grille s'est remplie aleatoirement\n");
    printf("('#' = cellule vivante, '.' = cellule morte)\n\n");
    afficherTableau(mTableau);
    printf("\n");

    for(nCpt=0;nCpt<nNbrActualisation;nCpt++)
    {
        changementCellule(mTableau);
        printf("Actualisation %d\n\n",nCpt+1);

        afficherTableau(mTableau);
        printf("\n");
    }
    return 0;
}

//INITIALISATION TABLEAU
/*-----------------------------------
 Descriptions : on initialise et remplie notre tableau de manière random
 Entrées : Tableau vide
 Sorties : Tableau rempli
-----------------------------------*/
void initTableau(int mTableau[TAILLE][TAILLE])
{
    int nLig,nCol;
    for(nLig=0;nLig<TAILLE;nLig++)
    {
        for(nCol=0;nCol<TAILLE;nCol++)
        {
            mTableau[nLig][nCol]=rand()%2;
        }
    }
}

//COMPTER VOISIN
/*-----------------------------------
 Descriptions : on compte pour chaque cellule le nombre de voisins vivants et on le stocke dans un tableau secondaire
 Entrées : Tableau
 Sorties : Nombre de voisins stockés
-----------------------------------*/
void compterVoisin(int mTableauBis[TAILLE][TAILLE],int mTableau[TAILLE][TAILLE])
{
    int nLig,nCol;

    for(nLig=1;nLig<TAILLE;nLig++)
    {
        for(nCol=1;nCol<TAILLE;nCol++)
        {
            mTableauBis[nLig][nCol]=mTableau[nLig-1][nCol-1]+mTableau[nLig][nCol-1]+mTableau[nLig+1][nCol-1]+mTableau[nLig-1][nCol]+mTableau[nLig+1][nCol]+mTableau[nLig-1][nCol+1]+mTableau[nLig][nCol+1]+mTableau[nLig+1][nCol+1];
        }
    }
}

//ACTUALISER CELLULE
/*-----------------------------------
 Descriptions : On actualise l'état de chaque cellule en fonction de son nombre de voisins
 Entrées : Nombre voisins par cellule
 Sorties : Nombre de voisins stockés
-----------------------------------*/
void changementCellule(int mTableau[TAILLE][TAILLE])
{
    int mTableauBis[TAILLE][TAILLE]={0};
    int nLig,nCol;
    compterVoisin(mTableauBis,mTableau);

    for(nLig=0;nLig<TAILLE;nLig++)
    {
        for(nCol=0;nCol<TAILLE;nCol++)
        {
            if((mTableau[nLig][nCol]==1)&&(mTableauBis[nLig][nCol]< 2||mTableauBis[nLig][nCol]>3))
            {
                mTableau[nLig][nCol]=0;
            }
            else if((mTableau[nLig][nCol]==0)&&(mTableauBis[nLig][nCol]==3))
            {
                mTableau[nLig][nCol]=1;
            }
        }
    }
}

void afficherTableau(int mTableau[TAILLE][TAILLE])
{
    int nLig,nCol;
    for(nLig=0;nLig<=TAILLE-1;nLig++)
    {
        for(nCol=0;nCol<=TAILLE-1;nCol++)
        {
            if(mTableau[nLig][nCol]==1)
            {
                printf("%c ",'#');
            }
            else
            {
                printf("%c ",'.');
            }
        }
        printf("\n");
    }
}
