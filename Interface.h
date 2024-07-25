#include "LocSkiBib.c"

#define max_choix 8

///Résolution de l'exécutable: ///

void chng_resolution();

///Menu informations complémentaires: ///

void menu_inf(int choix);
selection_inf(int choix, ptr_paire plist, t_skieur skieur, int *nsk);
void afficher_menu_inf(ptr_paire plist, t_skieur skieur, int *nsk);

///Menu affichage des données: ///

void afficher_paires(ptr_paire plist, t_skieur skieur);
void afficher_skieur(t_skieur skieur, int nsk);
void menu_aff(int choix);
selection_aff(int choix, ptr_paire plist, t_skieur skieur, int *nsk);
void afficher_menu_aff(ptr_paire plist, t_skieur skieur, int *nsk);

///Menu des reservations: ///

void menu_res(int choix);
selection_res(int choix, ptr_paire plist, t_skieur skieur, int *nsk);
void afficher_menu_res(ptr_paire plist, t_skieur skieur, int *nsk);

/// Menu de parcours des listes: ///

void menu_paire(int choix);
selection_paire(int choix, ptr_paire plist, t_skieur skieur, int *nsk);
void afficher_menu_paire(ptr_paire plist, t_skieur skieur, int *nsk);

/// Menu de parcours du vecteur skieur: ///

void menu_skieur(int choix);
selection_skieur(int choix, ptr_paire plist,t_skieur skieur, int *nsk);
void afficher_menu_skieur(ptr_paire plist, t_skieur skieur, int *nsk);

///Introduction du programme: ///

void logo_intro();

/// Menu principal: ///

void entete();
void bas_page();
void logo();
void menu_principal(int choix);
void selection_principal(int choix, ptr_paire *plist, t_skieur skieur, int *nsk);
void afficher_menu_principal(ptr_paire *plist, t_skieur skieur, int *nsk);
