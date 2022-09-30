#include <stdio.h>
#include <stdlib.h>

// prototypes des fonctions
int valeur_de(); //fonction
void init_des(int TtabE[3]); //procédure
void lancer_des(int TtabE[3]); //procédure
void affichage_combinaison(int TtabE[3]); //procédure
void choisir_des(int TtabE[3]); //procédure
void choix_combinaison(int TtabE[3]); //procédure
void nbr_des(int TtabE[3], int TtabV[6]); //procédure
int type_combinaison(int TtabV[6]); //fonction
void distribution_jetons(int *pot,int tab_compte_j1[6],int tab_compte_j2[6], int *nb_pions_j1, int *nb_pions_j2); //procédure

int main()
{
    // LEXIQUE
    int tour;
    int pot;
    int jetonJ1;
    int jetonJ2;
    int tabJ1[3];
    int tabJ2[3];
    int t1[6];
    int t2[6];

    // DEBUT
    pot=21;
    jetonJ1=0;
    jetonJ2=0;
    tour=1;

    do{
        init_des(tabJ1);
        printf("Joueur 1 : ");
        choix_combinaison(tabJ1);
        nbr_des(tabJ1,t1);
        jetonJ1 = type_combinaison(t1);
        printf("\nCombinaison J1 : ");
        affichage_combinaison(tabJ1);

        init_des(tabJ2);
        printf("\nJoueur 2 : \n");
        choix_combinaison(tabJ2);
        nbr_des(tabJ2,t2);
        jetonJ2 = type_combinaison(t2);
        printf("\nCombinaison J2 : ");
        affichage_combinaison(tabJ2);

        distribution_jetons(&pot,t1,t2,&jetonJ1,&jetonJ2);
        tour = tour + 1;
    } while (jetonJ1 != 21 && jetonJ2 !=21);

    if (jetonJ1 == 21)
    {
        printf("Joueur 2 a gagné la partie !");
    }else{
        printf("Joueur 1 a gagné la partie !");
    }
    return 0;
}

// définitions des fonctions et procédures
int valeur_de()
{
    int valeur_de;
    valeur_de = rand()%6 + 1;
    return valeur_de;
}

void init_des(int TtabE[3])
{
    int i;
    for(i=0 ; i< 3 ; i++)
    {
        TtabE[i]=-1;
    }
}

void lancer_des(int TtabE[3])
{
    int i;
    for(i=0 ; i< 3 ; i++)
    {
        if (TtabE[i]==-1)
        {
            TtabE[i]=valeur_de();
        }
    }
}

void affichage_combinaison(int TtabE[3])
{
    int i;
    for(i=0 ; i< 3 ; i++)
    {
        printf("%d",TtabE[i]);
    }
}

void choisir_des(int TtabE[3])
{
    int i;
    int relancerDe;
    for(i=0 ; i< 3 ; i++)
    {
        printf("\nVoulez-vous relancer le dé : %d. Si oui, entrez 1 sinon entrez 0.",i+1);
        scanf ("%d", &relancerDe);
        if (relancerDe==1)
        {
            TtabE[i]=valeur_de();
        }
    }
}

void choix_combinaison(int TtabE[3])
{
    int i;
    int j;
    lancer_des(TtabE);
    for(i=0 ; i< 3 ; i++)
    {
        affichage_combinaison(TtabE);
        choisir_des(TtabE);
        for(j=0 ; j< 2 ; j++)
        {
            if (TtabE[i]==-1)
            {
                TtabE[i]=valeur_de();
            }
        }
    }
    affichage_combinaison(TtabE);
}

void nbr_des(int TtabE[3], int TtabV[6])
{
    int i;
    for(i=0 ; i< 6 ; i++)
    {
        TtabV[i]=0;
    }
    for(i=0 ; i< 3 ; i++)
    {
        TtabV[TtabE[i]-1]=TtabV[TtabE[i]-1]+1;
    }
}

int type_combinaison(int TtabV[6])
{
    int nbJeton;
    if (TtabV[0]==1 && TtabV[1]==1 && TtabV[3]==1)
    {
        nbJeton=10;
    }else{
        if (TtabV[0]==3)
        {
            nbJeton=8;
        }else{
            if (TtabV[0]==2 && TtabV[5]==1)
            {
                nbJeton=7;
            }else{
                if (TtabV[5]==3)
                {
                    nbJeton=7;
                }else{
                    if (TtabV[4]==3)
                    {
                        nbJeton=6;
                    }else{
                        if (TtabV[0]==2 && TtabV[4]==1)
                        {
                            nbJeton=6;
                        }else{
                            if (TtabV[3]==3)
                            {
                                nbJeton=5;
                            }else{
                                if (TtabV[0]==2 && TtabV[3]==1)
                                {
                                    nbJeton=5;
                                }else{
                                    if (TtabV[2]==3)
                                    {
                                        nbJeton=4;
                                    }else{
                                        if (TtabV[0]==2 && TtabV[2]==1)
                                        {
                                            nbJeton=4;
                                        }else{
                                            if (TtabV[1]==3)
                                            {
                                                nbJeton=3;
                                            }else{
                                                if (TtabV[0]==2 && TtabV[1]==2)
                                                {
                                                    nbJeton=3;
                                                }else{
                                                    if (TtabV[0]==1 && TtabV[1]==1 && TtabV[2]==1)
                                                    {
                                                        nbJeton=2;
                                                    }else{
                                                        if (TtabV[3]==1 && TtabV[4]==1 && TtabV[5]==1)
                                                        {
                                                            nbJeton=2;
                                                        }else{
                                                            nbJeton=1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return nbJeton;
}

void distribution_jetons(int *pot,int tab_compte_j1[6],int tab_compte_j2[6], int *nb_pions_j1, int *nb_pions_j2)
{
    int score_1;
    int score_2;

    if(*pot != 0)
    {
        score_1 = type_combinaison(tab_compte_j1);
        score_2 = type_combinaison(tab_compte_j2);

        if(score_1 == score_2)
        {
            printf("\nEgalité !\n");
        }
        else
        {
            if(score_1 > score_2)
            {
                if(*pot - score_1 < 0)
                {
                    *nb_pions_j2 += *pot;
                    *pot = 0;
                }
                else
                {
                    *nb_pions_j2 += score_1;
                    *pot -= score_1;
                }
                printf("\nScore Joueur 1 : %d\nScore Joueur 2 : %d\nLe joueur 1 a gagné ce tour \n", score_1, score_2);
            }
            else
            {
                if(*pot - score_2 < 0)
                {
                    *nb_pions_j1 += *pot;
                    *pot = 0;
                }
                else
                {
                    *nb_pions_j1 += score_2;
                    *pot -= score_2;
                }
                printf("\nScore Joueur 1 : %d\nScore Joueur 2 : %d\nLe joueur 2 a gagné ce tour \n", score_1, score_2);
            }
        }

    }
    else
    {

        score_1 = type_combinaison(tab_compte_j1);
        score_2 = type_combinaison(tab_compte_j2);

        if(score_1 == score_2)
        {
            printf("\nEgalité !\n");
        }
        else
        {
            if(score_1 > score_2)
            {
                if(*nb_pions_j1 - score_1 < 0)
                {
                    *nb_pions_j2 += *nb_pions_j1;
                    *nb_pions_j1 = 0;
                }
                else
                {
                    *nb_pions_j1 -= score_1;
                    *nb_pions_j2 += score_1;
                }
                printf("\nScore Joueur 1 : %d\nScore Joueur 2 : %d\nLe joueur 1 a gagné ce tour \n", score_1, score_2);
            }
            else
            {
                if(*nb_pions_j2 - score_2 < 0)
                {
                    *nb_pions_j1 += *nb_pions_j2;
                    *nb_pions_j2 = 0;
                }
                else
                {
                    *nb_pions_j2 -= score_2;
                    *nb_pions_j1 += score_2;
                }
                printf("\nScore Joueur 1 : %d\nScore Joueur 2 : %d\nLe joueur 2 a gagné ce tour \n", score_1, score_2);
            }
        }
    }
}