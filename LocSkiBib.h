#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "conio.c"

#define max_nom 20 //Nombre maximal de caractéres d'un nom.
#define max_adr 20 //Nombre maximal de caractéres d'une adresse(wilaya).
#define max_skieur 100 //Nombre maximal de locataires.
#define fin_sais 151 //La fin de la saison.
#define max_res 10 //Nombre maximum des réservations par personne é la fois.
#define nbr_lignes 40



///Les Stuctures de données: ///

///* Les structures de données sont faites tels qu'elles sont décrites dans l'énonce du Tp! *///

//Structure des sous-listes linéaires chaénées:
typedef struct res_ski res_ski;
typedef res_ski* ptr_res;
typedef struct res_ski{
    int deb;
    int fin;
    int ind;
    ptr_res ressuiv;
};

//Structure des listes linéaires chaénées:
typedef struct paire_ski paire_ski;
typedef paire_ski* ptr_paire;
typedef struct paire_ski{
    int taille;
    ptr_res loc;
    ptr_paire skisuiv;
};

//Structure du tableau skieur:
typedef struct elm_skieur elm_skieur;
typedef struct elm_skieur{
    char nom[max_nom];
    char adresse[max_adr];
    int psk;
};

//Structure du tableau res des réservations:
typedef elm_skieur t_skieur[max_skieur];

typedef struct elm_res elm_res;
typedef struct elm_res{
    int de,fi,t;
};
typedef elm_res t_res[max_res];



///Machine abstraite LLC: ///

void allouer_paire(ptr_paire *p);
void liberer_paire(ptr_paire p);
void aff_taille(ptr_paire p, int V);
void aff_adr_paire(ptr_paire p, ptr_paire q);
void aff_loc(ptr_paire p, ptr_res q);
ptr_paire suivant_paire(ptr_paire p);
int valeur_taille(ptr_paire p);
ptr_res valeur_loc(ptr_paire p);



///Machine abstraite Sous-LLC: ///

void allouer_res(ptr_res *p);
void liberer_res(ptr_res p);
void aff_deb(ptr_res p,int V);
void aff_fin(ptr_res p,int V);
void aff_ind(ptr_res p,int V);
void aff_adr_res(ptr_res p, ptr_res q);
ptr_res suivant_res(ptr_res p);
int valeur_deb(ptr_res p);
int valeur_fin(ptr_res p);
int valeur_ind(ptr_res p);



///1. Création des structures et insertion d'elements: ///

/*a) Création des structures: */
int Random(int Min, int Max); //Fonction Random: renvoie un nombre aléatoire entre Min et Max.
void tri_bulles_paires(ptr_paire plist); //Procédure tri_bulles_paires: trie les paires de skis par ordre croissant sur la taille.
void creer_sous_struct(ptr_res *tete, int nsk); //Procédure creer_sous_struct: permet créer et remplire les sous-listes de réservations.
void creer_struct(ptr_paire *plist, int *nsk, t_skieur skieur); //Procédure creer_struct: permet créer la LLC des paires de skis.
void fix_psk(ptr_paire plist, t_skieur skieur, int nsk); //Procédure fix_psk: fixe les champs psk nuls du tableau skieur.
void creer_skieur(t_skieur skieur, int nsk, ptr_paire plist); //Procédure creer_skieur: permet de créer le tableau skieur.

/*b) Location: */
void tri_bulles_res(ptr_res premloc); //Procédure tri_bulles_res: trie les réservations par ordre croissant sur les dates.
void insertete(ptr_res *premloc, int deb, int fin, int ind); //Procedure insertete: insert un maillon contenant deb, fin et ind en téte de locski.
bool location(ptr_res *premloc, int deb, int fin, int ind, t_skieur skieur); //Fonction location: réalise la location et renvoie vrai si c'est possible, renvoie faux sinon.

/*c) Réservation: */

bool verifie_nom(char nomloc[max_nom]); //Fonction verfie_nom: renvoie vrai si le nom entré est valid, faux sinon.
bool verifie_adr(int adr); //Fonction verfie_adr: renvoie vrai si l'adresse entrée est valide, faux sinon.
bool verifie_taille(int tai); //Fonction verfie_taille: renvoie vrai si la taille entrée est valide, faux sinon.
bool verifie_deb_fin(int deb, int fin); //Fonction verfie_taille: renvoie vrai si les dates de début et fin sont valides, faux sinon.
void reservation(ptr_paire plist, bool *possible, char nomloc[max_nom], int adr, int tai, int de, int fi, t_skieur skieur, int *nsk); //Procédure reservation: et renvoie une variable booléenne possible selon l'état de la réservation.

/*d) Plusieurs réservations: */
void creer_res(t_res res, int *nr); //Procédure creer_res: permet de lire les tailles et les dates des différentes réservations et crée le tableau res.
void reservations(ptr_paire plist, char nomloc[max_nom], int adr, t_skieur skieur, int *nsk); //Procedure réservations: permet de réaliser si possible les réservations demandées et affiche les messages adéquats.

///2. Parcours de liste: ///

int nbskis(ptr_paire plist); /*a) Fonction nbskis: renvoie la longeur de la liste principale. */
ptr_paire skit(ptr_paire plist,int t); /*b) Fonction skit: retoure léadresse du premier maillon contenant une paire de skis de taille t. */
int nbjloc(ptr_paire plist,int t); /*c) Fonction nbjloc: délivre le nombre de jours de location déune paire de skis si elle existe dans la liste, 0 sinon. */
int pg_resrv_nbj(ptr_paire plist); /*d) Fonction pg_reserv_nbj: renvoie la taille de la paire de skis la plus demandée(Selon le nombre des jours de locations). */
int pg_resrv_loc(ptr_paire plist); /*e) Fonction pg_reserv_loc: renvoie la taille de la paire de skis la plus demandée(Selon le nombre de locataires). */



///3. Parcours de vecteurs: ///

int cherchskieur(t_skieur skieur, int nsk, char nomloc[max_nom]); /*a) Fonction cherchskieur: renvoie l'index du locataire nommé 'nomloc' s'il existe dans le vecteur skieur, -1 sinon. */
void max_psk(t_skieur skieur, int nsk, int *ind, int *psk); /*b) Procédure max_psk: renvoie l'indice et le psk du locataire ayant le plus grand psk. */

///4. Suppression d'élements: ///

 void annuleres(char nomloc[max_nom],t_skieur skieur,ptr_paire plist,int *nsk); //Procédure annuleres: supprime toutes les r�servations d'un locataire.


