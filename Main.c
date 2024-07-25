#include <stdio.h>
#include "Interface.c"


int main(){

    //Ajustement de la r�solution de l'ex�cutable:
    chng_resolution();

    //D�clarations et initialisations:
    ptr_paire plist;
    int nsk=0;
    t_skieur skieur;

    //Introduction du programme:
    introduction();

    //Corps du programme:
    afficher_menu_principal(&plist,skieur,&nsk);

    return 0;
}
