#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ADH 4 //Nombre d'adhérents maximum dans la bibliothèque
#define MAX 5 //Nombre d'ouvrages maximum et de résa dans la bibliothèque
#define MAX_exemplaire 5 // Nombre d'exemplaire maximum par livre

typedef struct personnes
{
    char prenom[80]; // Exemple : Leanna
	char nom[80]; // Exemple : CONTRERAS
	int num_adh; // Exemple : 1 (Numéro unique)
	char ville[20]; // Exemple : Marignane
	int nb_livre_emprunte; // Exemple : 3
	//compteur qui indique le nombre de livre qu'a emprunté l'adhérent au total
} ADHERENT; // Struct des adhérents à la bibliothèque

typedef struct ouvrages
{
	char nom_auteur[80]; // Exemple : J.K_Rowling
	char titre_livre[80]; // Exemple : Harry_potter_volume_1
	int num_livre; // Exemple : 15 (Numéro Unique)
	// C'est le numéro du livre donnée à la sortie
	int nb_exemplaire; // Exemple : 5
	int num_exemplaire[10]; // A gerer comme une PILE 
	int nb_livres_dispo; // Exemple : 2
} LIVRE; // Struct des ouvrages de la bibliothèque

typedef struct reservations
{
	int num_resa; // Exemple : 1
	int num_livre; // Exemple : 15
	int num_exemplaire_emprunte; // Exemple : 3 
	int num_adh; // Exemple : 1
	char date_debut_emprunt[10]; // Exemple : 15/11/2013
} RESA; // Struct des emprunts de la bibliothèque

void remplissage_adherent (ADHERENT *t,int *nbe)
{
	FILE *fichier;
	int i;
	i=0;
	fichier=fopen ("adh.txt","r"); // J'ouvre le fichier dans la variable

	if (fichier==NULL) // Si erreur
	{
		printf("Désolée il y à un probleme de chargement des données à partir du fichier adherent\n");
		printf("Veuillez verifier avant de ccontinuer\n");
		return;
	}

	while(!feof(fichier)) // Tant que c'est pas fini
	{
        fscanf(fichier,"%s",t[i].prenom);
        fpurge(stdin);
		fscanf(fichier,"%s",t[i].nom);
        fscanf(fichier,"%d",&t[i].num_adh);
        fpurge(stdin);
		fscanf(fichier,"%s",t[i].ville);
		fscanf(fichier,"%d",&t[i].nb_livre_emprunte);
		i++;
	}
	fclose(fichier); // Fermeture fichier
	*nbe=i; // nombre d'element total --> 1ere case vide
	return;
}

void affichage_adherent(ADHERENT *t, int nbe)
{
	int i;
    i=0;
    
    printf("Prénom\tNom\n");
	while(i<nbe) 
	{
        // affichage
        printf("\n%s\t",t[i].prenom);
		printf("%s\n",t[i].nom);
		printf("N° adherent : %d\n",t[i].num_adh);
		printf("Ville : %s\n",t[i].ville);
		printf("Emprunt total : %d\n",t[i].nb_livre_emprunte);
		i++;
		printf("\n");
	}
	return;
}

void remplissage_livre (LIVRE *t,int *nbe)
{
	FILE *fichier;
	int i,j;
	i=0;
	fichier=fopen ("livre.txt","r");

	if (fichier==NULL) // Si erreur
	{
		printf("Désolée il y à un probleme de chargement des données à partir du fichier livre\n");
		printf("Veuillez verifier avant de ccontinuer\n");
		return;
	}

	while(!feof(fichier))
	{
        fscanf(fichier,"%s",t[i].nom_auteur);
        fpurge(stdin);
		fscanf(fichier,"%s",t[i].titre_livre);
		fscanf(fichier,"%d",&t[i].num_livre);
		fscanf(fichier,"%d",&t[i].nb_exemplaire);
		j=0; // La boucle permet de ne pas remplir le tableau des numéro d'exemplaire en entier
		while (j<t[i].nb_exemplaire)
		{
			fscanf(fichier,"%d",&t[i].num_exemplaire[j]);
			j++;
        }
		fscanf(fichier,"%d",&t[i].nb_livres_dispo);
		i++;
	}
	fclose(fichier);
	*nbe=i; // rang du dernier element
	return;
}

void affichage_livre(LIVRE *t, int nbe)
{
	int i,j;
	i=0;

	printf("Auteur\t\tTitre\n");
	while(i<nbe)
	{
		printf("%s\t",t[i].nom_auteur);
		printf("%s\n",t[i].titre_livre);
		printf("N° livre : %d\n",t[i].num_livre);
		printf("Nombre d'exemplaire : %d\n",t[i].nb_exemplaire);
		j=0;
		printf("Exemplaire dispo : ");
		while(j<t[i].nb_exemplaire)
		{
			printf("%d\t",t[i].num_exemplaire[j]);
			j++;
		}
		printf("\n");
		printf("Nombre disponible : %d\n",t[i].nb_livres_dispo);
		printf("\n");
		i++;
	}
	return;
}

void remplissage_reservation(RESA *t, int *nbe)
{
    FILE *fichier;
	int i;
	i=0;
	fichier=fopen ("resa.txt","r");

	if (fichier==NULL) // Si erreur
	{
		printf("Désolée il y à un probleme de chargement des données à partir du fichier resa\n");
		printf("Veuillez verifier avant de ccontinuer\n");
		return;
	}

	while(!feof(fichier))
	{
		fscanf(fichier,"%d",&t[i].num_resa);
		fscanf(fichier,"%d",&t[i].num_livre);
		fscanf(fichier,"%d",&t[i].num_exemplaire_emprunte);
        fscanf(fichier,"%d",&t[i].num_adh);
        fpurge(stdin);
        fscanf(fichier,"%s",t[i].date_debut_emprunt);
        fpurge(stdin);
		i++;
	}
	fclose(fichier);
	*nbe=i; // rang du dernier element
	return;  
}

void affichage_reservation(RESA *t, int nbe)
{
	int i,j;
	i=0;
	while(i<nbe)
	{
		printf("Réservation n° : %d\n",t[i].num_resa);
		printf("N° Livre : %d\n",t[i].num_livre);
		printf("N° exemplaire : %d\n",t[i].num_exemplaire_emprunte);
		printf("N° adhérent : %d\n",t[i].num_adh);
        printf("Emprunt le %s\n",t[i].date_debut_emprunt);
		i++;
	}
	printf("\n");
	return;
}

int plein (int nbe, int M)
{
	int flag;
	if (nbe==M)
	{
		flag = 1;
	}
	return flag;
}

void saisie_adherent (ADHERENT*t,int *nbe)
{
	printf("Donnez le prénom :\n");
	scanf("%s",t[*nbe].prenom);
	printf("Donnez le nom : \n");
	scanf("%s",t[*nbe].nom);
	printf("Le dernier numéro adherent attribué est : %d\n",*nbe);
	printf("Donnez le numero d'adherent :\n");
	scanf("%d",&t[*nbe].num_adh);
	printf("Donnez la ville : \n");
	scanf("%s",t[*nbe].ville);
	t[*nbe].nb_livre_emprunte=0; // C'est à 0 car comme il adhere il n'a pas pu encore emprunté
	*nbe=*nbe+1;
	
	return;
}

void consigne_ecriture ()
{
	printf("Consigne à respecter : \n");
	printf("- Veuillez ecrire en minuscule s'il vous plait\n");
	printf("- Veuillez remplacer les espaces par : _\n");
	printf("- Lorsque vous tapez une date, séparer les chiffres avec : /\n");
	printf("\n");
	return;
}

void separation_menu()
{
	printf("—————————————————————————————————————");
	printf("\n");
	return;
}

void saisie_ouvrage(LIVRE *t,int *nbe)
{
	int i;
	printf("\nDonner le titre de l'auteur : ");
	scanf("%s",t[*nbe].nom_auteur);
	printf("Donner le titre du livre : ");
	scanf("%s",t[*nbe].titre_livre);
	printf("Le dernier numéro de livre attribué est : %d\n",*nbe);
	printf("Donner le numéro du livre : ");
	scanf("%d",&t[*nbe].num_livre);
	printf("Donnez le nombre d'exemplaire : ");
	scanf("%d",&t[*nbe].nb_exemplaire);
	printf("Donnez les numéros d'exemplaire : \n");
	i=0;
	while(i<t[*nbe].nb_exemplaire)
	{
		scanf("%d",&t[*nbe].num_exemplaire[i]);
		i++;
	}
	t[*nbe].nb_livres_dispo=t[*nbe].nb_exemplaire;
	return;
}
/*
void saisie_reservation (LIVRE *tl,RESA *tr, int *nbe)
{
	printf("\nLe dernier numéro de réservation attribué est : %d\n",*nbe);
	printf("N° de réservation : ");
	scanf("%d",&tr[*nbe].num_resa);
	printf("N° du livre réservé : ");
	scanf("%d",&tr[*nbe].num_livre);


	printf("L'adhérent empruntera le numéro d'exemplaire : %d",);

	printf("N° de l'exemplaire emprunté : ");
	scanf("%d",&tr[*nbe].num_exemplaire_emprunte);
	printf("N° de l'adherent : ");
	scanf("%d",&tr[*nbe].num_adh);
	fpurge(stdin);
	printf("Date de début de l'emprunt : ");
	scanf("%s",tr[*nbe].date_debut_emprunt);
	fpurge(stdin);

	*nbe=*nbe+1
	return;
}
*/
void livre_disponible (LIVRE *t,int nbe)
{
	int flag, i, num_livre,j;
	char nomlivre[80];
	char nom[80];
	flag=0;

	printf("De quel livre voulait vous trouver la disponibilité\n");
	printf("Donnez le titre : ");
	scanf("%s",nomlivre); // je prend le nom du livre de l'utilisateur
	i=0;
	while (i<nbe && flag == 0) // je cherche son numéro
	{
		// je copie le nom du livre dans le tableau pour comprarer 
		strcpy(nom,t[i].titre_livre);
		// Si le nom est le meme, je recupere  le numero sinon j'augmente i
		if (strcmp(nom,nomlivre)==0)
		{
			flag=1; 
			num_livre=t[i].num_livre;
		}
		else
		{
			i++;
		}
	}
	// je verifie s'il est disponible 
	if(flag==0)
	{
		printf("désolée, ce livre n'est pas disponible dans notre bibliothèque\n");
	}
	else
	{
		// si flag==1 ca veut dire qu'il est disponible, reste a savoir si on a des exemplaires
		if(t[i].nb_livres_dispo==0)
		{
			printf("Désolée, le livre %s n'est pas disponible pour le moment\n",nomlivre);
		}
		else
		{
			printf("Le livre %s est bien disponible\n",nomlivre);
			printf("Son numéro est : %d\n",num_livre);
			printf("L'adherent peut donc emprunter ce livre\n");
		}
	}
	return;
}

int main()
{
	ADHERENT tab_adh[ADH];
	LIVRE tab_livre[MAX];
	RESA tab_emprunt[MAX];

	int nbe_adh, nbe_livre, nbe_resa, choix_menu, choix_sous_menu;

	printf("Bonjour madame, la bibliothèque ouvre ses portes \n");
	printf("Initialisation des données dans les bases\n");
    // Remplissage des structures par les fichiers
    // les fichiers doivent être au même endroit que le programme et le a.out (ou .exe)
    remplissage_adherent(tab_adh,&nbe_adh);
    remplissage_livre(tab_livre,&nbe_livre);
    remplissage_reservation(tab_emprunt,&nbe_resa);

	do
	{	// Menu qui répertorie les fonctions principales qui son ensuite décomposé en sous menu
		printf("\n***** MENU PRINCIPAL *****\n");
		printf("\nQue voulez vous faire ?\n");
		printf("\n1- Ajouter (adhérent, livre ou réservation)\n");
		printf("2- Afficher\n");
		printf("3- Rechercher\n");
		printf("4- Trier\n");
		printf("5- Supprimer\n");
		printf("0- Fin de la journée\n");
		printf("\nTaper votre choix : ");
		fpurge(stdin);
		scanf("%d",&choix_menu);

		if (choix_menu==1)
		{
			separation_menu();
			printf("\n***** SOUS MENU AJOUT *****\n");
			printf("\n1- Ajouter un adherent\n");
			printf("2- Ajouter un ouvrage\n");
			printf("3- Un adherent emprunte un livre\n");
			printf("\nTapez votre choix : ");
			fpurge(stdin);
			scanf("%d",&choix_sous_menu);

			if (choix_sous_menu==1)
			{
				if (plein(nbe_adh,ADH)==1)
				{
					printf("Désolée, il y a trop d'adhérent pour l'instant. Nous vous recontacterons.\n");
				}
				else
				{
					consigne_ecriture();
					saisie_adherent(tab_adh,&nbe_adh);
					printf("L'adhérent à bien été enregistré\n");
				}
			}
			if (choix_sous_menu==2)
			{
				if (plein(nbe_livre,MAX)==1)
				{
					printf("Désolée, la bibliothèque ne peut plus recevoir de nouveau ouvrage tant que nous n'agrandissons pas.\n");
				}
				else
				{
					consigne_ecriture();
					saisie_ouvrage(tab_livre,&nbe_livre);
					printf("Le livre à bien été ajouté à la bibliothèque\n");
				}
			}
			if (choix_sous_menu==3)
			{
				if (plein(nbe_livre,MAX)==1)
				{
					printf("Désolée, la bibliothèque ne peut plus recevoir de nouvelle réservations tant que les autres adhérents en nous ramène pas les livres.\n");
				}
				else
				{
					consigne_ecriture();
					livre_disponible(tab_livre,nbe_livre);
					/*
					saisie_reservation(tab_livre,tab_emprunt,&nbe_resa);
					printf("La réservation à bien été effectué\n");

					*/
				}
			}

		}

		if (choix_menu==2)
		{
			separation_menu();
			printf("\n***** SOUS MENU AFFICHAGE *****\n");
			printf("\n1- Afficher les adhérents de la bibliothèque\n");
			printf("2- Afficher les livres\n");
			printf("3- Afficher les réservations\n");
			printf("4- Afficher l'adherent qui à emprunté un certain livre\n");
			printf("5- Afficher les emprunts en cours d'un adherent\n");
			printf("6- Afficher le nombre de livre emprunté pour un certain jour\n");
			printf("\nTapez votre choix : ");
			fpurge(stdin);
			scanf("%d",&choix_sous_menu);

			if (choix_sous_menu==1)
			{
				affichage_adherent(tab_adh,nbe_adh);
			}
			if (choix_sous_menu==2)
			{
				affichage_livre(tab_livre,nbe_livre);
            }
            if (choix_sous_menu==3)
            {
                affichage_reservation(tab_emprunt,nbe_resa);
            }
		}

		if (choix_menu==3)
		{
			separation_menu();
			printf("\n***** SOUS MENU RECHERCHE *****\n");
			printf("\n1- Chercher un adherent en fonction de son numero d'adherent\n");
			printf("2- Chercher si un livre est disponible\n");
			printf("3- Chercher le livre qui à le plus d'exemplaire disponible\n");
			printf("4- Chercher le nombre de livre emprunté par un adherent depuis son adhesion\n");
			printf("5- Verifier si un adherent n'est pas en retard pour rendre un livre\n");
			printf("\nTapez votre choix : ");
			fpurge(stdin);
			scanf("%d",&choix_sous_menu);

			if (choix_sous_menu==2)
			{
				consigne_ecriture();
				livre_disponible(tab_livre,nbe_livre);
			}
		}

		if (choix_menu==4)
		{
			separation_menu();
			printf("\n***** SOUS MENU TRIER *****");
			printf("\n1- Trier les adhérents par ordre alphabétique\n");
			printf("2- Trier les livres par nombre d'exemplaire dans l'ordre decroissant");
			printf("\nTapez votre choix : ");
			fpurge(stdin);
			scanf("%d",&choix_sous_menu);
		}

		if(choix_menu==5)
		{
			separation_menu();
			printf("\n***** SOUS MENU SUPPRIMER *****\n");
			printf("\n1- Supprimer un adherent\n");
			printf("2- Supprimer un livre\n");
			printf("3- Supprimer une réservation (Rendre un livre)\n");
			printf("\nTapez votre choix : ");
			fpurge(stdin);
			scanf("%d",&choix_sous_menu);
		}

		fpurge(stdin);
		separation_menu();
	}while (choix_menu != 0);
	return 0;
}