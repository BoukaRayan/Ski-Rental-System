#include "Interface.h"

///Résolution de l'exécutable: ///

void chng_resolution(){

    //Déclarations et initialisations:
    int Max_iter=Random(2,3);

    //Changement de la résolution:
    gotoxy(1,nbr_lignes/2);
    for (int j=0; j<Max_iter; j++){
        system("cls");
        gotoxy(1,nbr_lignes/2);
        printf("%59sAjustement de la resolution de la fenetre","");
        for(int i=0; i<3; i++){
            printf(".");
            delay(500);
        };
    };

    system("mode con LINES=40 COLS=160");

    //Ameliorez votre experience:
    char amelio[161]="Il est recommande d'utiliser le systeme windows 10!";
    system("cls");
    gotoxy(1,nbr_lignes/2);
    printf("%54s","");
    for (int i=0; i<51; i++){
        delay(30);
        printf("%c",amelio[i]);
    };
    delay(1500);
    system("cls");
}

///Menu informations complémentaires: ///

void menu_inf(int choix){

    //Déclarations et initialisations:
    int i=0;
    char *mif[4]={" 1. Standards des entrees    ",
                  " 2. Concernant notre station ",
                  " 3. A propos de ce travail   ",
                  " 4. Retour au menu principal "};

    //Traitement et affichage du menu:
    bas_page();
    entete();
    logo();
    textcolor(WHITE);
    printf("%60s______________________________________\n\n","");
    while (i<4){
        if (i==choix){
            textcolor(CYAN);
            printf("%65s%s\n","",mif[i]);
            textcolor(WHITE);
        }
        else printf("%65s%s\n","",mif[i]);
        i++;
    };
    printf("%60s______________________________________\n\n","");

}

selection_inf(int choix, ptr_paire plist, t_skieur skieur, int *nsk){

    system("cls");

    //Déclarations et initialisations:
    int ch=' ';
    int tai;
    int Max_iter=Random(1,2);

    //Traitement:
    switch (choix){
        case 0: //STANDARDS DES ENTREES:
            for (int j=0; j<Max_iter; j++){
                system("cls");
                gotoxy(1,nbr_lignes/2);
                printf("%75sChargement","");
                for(int i=0; i<3; i++){
                    printf(".");
                    delay(400);
                };
            };
            system("cls");
            textcolor(CYAN);printf("\n\n\n%69sSTANDARDS DES ENTREES:\n\n\n\n\n","");textcolor(WHITE);
            printf("%37s _______________________________ ","");textcolor(CYAN);printf("LE NOM DU LOCATAIRE:");textcolor(WHITE);printf(" _______________________________ \n");
            printf("%37s|                                                                                    |\n","");
            printf("%37s|              * Le nom du locataire ne doit pas contenir des espaces *              |\n","");
            printf("%37s|         * Le nom du locataire ne doit pas contenir des caracteres speciaux *       |\n","");
            printf("%37s|                          Exemples: BOUKAKIOU, SOUALAH ...                          |\n","");
            printf("%37s|____________________________________________________________________________________|\n\n\n","");

            printf("%37s _____________________________ ","");textcolor(CYAN);printf("L'ADRESSE DU LOCATAIRE:");textcolor(WHITE);printf(" ______________________________ \n");
            printf("%37s|                                                                                    |\n","");
            printf("%37s|      * L'adresse du locataire est un entier (1<=ADR<=58) qui sera traduit par *    |\n","");
            printf("%37s|            * La suite au nom de la wilaya correspondant a cet entier *             |\n","");
            printf("%37s|                          Exemples: 1=Adrar, 14=Tiaret ...                          |\n","");
            printf("%37s|____________________________________________________________________________________|\n\n\n","");

            printf("%37s _________________________________ ","");textcolor(CYAN);printf("TAILLE DES PAIRES:");textcolor(WHITE);printf(" _______________________________ \n");
            printf("%37s|                                                                                    |\n","");
            printf("%37s|   * La  taille des paires de skis est un entier multiple de 5 entre 80 et 200 *    |\n","");
            printf("%37s|                          Exemples: 155, 90, 175, 100 ...                           |\n","");
            printf("%37s|____________________________________________________________________________________|\n","");


            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 1: //CONCERNANT NOTRE STATION:
            for (int j=0; j<Max_iter; j++){
                system("cls");
                gotoxy(1,nbr_lignes/2);
                printf("%75sChargement","");
                for(int i=0; i<3; i++){
                    printf(".");
                    delay(400);
                };
            };
            system("cls");
            textcolor(CYAN);printf("\n\n\n%67sCONCERNANT NOTRE STATION:\n\n\n\n\n","");
            printf("\t* HEURES D'OUVERTURE:");textcolor(WHITE);printf(" notre station est ouverte tous les jours de 9h00 a 18h00,sauf le vendredi, les horaires peuvent varier en fonction des\n");
            printf("\t                      conditions meteorologiques, alors assurez-vous de verifier en ligne.\n\n\n");
            textcolor(CYAN);printf("\t* PLUS DE SERVICES:");textcolor(WHITE);printf(" nous proposons egalement des cours de ski supplementaires pour tous les niveaux, des reparations de ski et des conseils\n");
            printf("\t                    de preparation pour votre voyage de ski. n'hesitez pas a nous contacter pour en savoir plus sur ces services!\n\n\n");
            textcolor(CYAN);printf("\t* CONSEILS DE SECURITE:");textcolor(WHITE);printf(" - assurez-vous de bien porter les skis pour eviter les blessures.\n");
            printf("\t                        - verifiez toujours que les fixations sont bien ajustees.\n");
            printf("\t                        - respectez les panneaux de signalisation et les instructions sur les pistes.\n\n\n");
            textcolor(CYAN);printf("\t* POLITIQUE DE LOCATION:");textcolor(WHITE);printf(" - nous exigeons un depot de garantie pour la location de tout equipement de ski.\n");
            printf("\t                         - les frais de retard s'appliquent si l'equipement n'est pas retourne a temps.\n");
            printf("\t                         - nous ne louons pas d'equipement a des personnes de moins de 18 ans sans la permission d'un parent ou d'un tuteur.\n\n");


            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 2: //A PROPOS DE CE TRAVAIL:
            for (int j=0; j<Max_iter; j++){
                system("cls");
                gotoxy(1,nbr_lignes/2);
                printf("%75sChargement","");
                for(int i=0; i<3; i++){
                    printf(".");
                    delay(400);
                };
            };
            system("cls");
            textcolor(CYAN);printf("\n\n\n%72sA PROPOS DU TP:\n\n\n\n\n","");
            textcolor(CYAN);printf("%20sTitre:","");textcolor(WHITE);printf(" Location des skis(TP1-ALSDD).\n\n");
            textcolor(CYAN);printf("%20sAuteur:","");textcolor(WHITE);printf(" SOUALAH MOHAMMED Zakaria  (A l'aide de BOUKAKIOU Rayan).\n\n");
            textcolor(CYAN);printf("%20sSuperviseur:","");textcolor(WHITE);printf(" Monsieur KERMI Adel.\n\n");
            textcolor(CYAN);printf("%20sDate:","");textcolor(WHITE);printf(" AVRIL 2023.\n\n\n\n");

            printf("\tLocation des skis est un travail pratique realise par SOUALAH MOAHMMED Zakaria &  BOUKAKIOU Rayan en 2023, sous la supervision de monsieur KERMI \n\tAdel. L'idee principale consiste a une station de ski qui souhaite gerer, organiser et representer la reservation et la location de ses skis \n\tdans une liste lineaire chainees de sous-listes lineaires chainees et un tableau d'enregistrement ou on peut creer, modifier, supprimer et parcourir \n\tces structures.\n\n\n\tToutes les taches demandees sont realisees(IHM, commentaires, modularite...) ainsi que plusieures modules supplementaires tels ques:\n\t    - La paire de skis la plus demandee selon les jours de location(pg_reserv_nbj).\n\t    - Le skieur le plus actif(max_psk).\n\t    - La paire de skis la plus demandee selon le nombre de locataires(pg_reserv_loc).\n\t    - Verification du nom, l'adresse, la taille et les dates.\n");

            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 3: //RETOUR:
            afficher_menu_principal(&plist,skieur,&(*nsk));
            break;
        default:
            break;
    };
}

void afficher_menu_inf(ptr_paire plist, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    int i=0;
    int ch=' ';

    //Traitement:
    system("cls");
    menu_inf(0);
    while(1){
        ch=getch();
        switch(ch){
            case 72:
                if (i==0) i=3;
                else i--;
                menu_inf(i);
                break;
            case 80:
                if (i==3) i=0;
                else i++;
                menu_inf(i);
                break;
            case 13:
                selection_inf(i,plist,skieur,&(*nsk));
                system("cls");
                menu_inf(i=0);
                break;
            default:
                menu_inf(i);
                break;
        };
    };
}

///Menu affichage des données: ///

void afficher_paires(ptr_paire plist, t_skieur skieur){

    ptr_paire p;
    ptr_res q;

    p=plist;
    while (p!=NULL){
        printf("%59s _______________________________________ \n","");delay(180);
        printf("%59s|%18s%3d%18s|\n","","",valeur_taille(p),"");delay(180);
        printf("%59s|_______________________________________|\n","");delay(180);
        q=valeur_loc(p);
        if (q==NULL){
            printf("%59s|          Paire non reservee!          |\n","","","");
            delay(180);
            printf("%59s|_______________________________________|\n\n","");
        }
        else{
            printf("%59s| IND |         NOM         | DEB | FIN |\n","");delay(180);
            printf("%59s|_____|_____________________|_____|_____|\n","");delay(180);
            while(q!=NULL){
                printf("%59s| %3d | %19s | %3d | %3d |\n","",valeur_ind(q),skieur[valeur_ind(q)].nom,valeur_deb(q),valeur_fin(q));
                delay(180);
                q=suivant_res(q);
            };
        printf("%59s|_____|_____________________|_____|_____|\n\n","");
        };
        delay(180);
        p=suivant_paire(p);
    };
}

void afficher_skieur(t_skieur skieur, int nsk){
    //Affichage du vecteur skieur:
    printf("%48s _____________________________________________________________\n%48s| IND |         NOM         |          ADRESSE          | PSK |\n%48s|_____|_____________________|___________________________|_____|\n","","","");
    for(int i=1;i<=nsk;i++) {
        printf("%48s| %3d | %19s | %25s | %3d |\n","",i,skieur[i].nom,skieur[i].adresse,skieur[i].psk);
        delay(180);
    };
    printf("%48s|_____|_____________________|___________________________|_____|\n","");
}

void menu_aff(int choix){

    //Déclarations et initialisations:
    int i=0;
    char *maf[3]={"  1. Affichage du vecteur skieur   ",
                  "  2. Affichage des paires de skis  ",
                  "  3. Retour au menu principal      "};

    //Traitement et affichage du menu:
    bas_page();
    entete();
    logo();
    textcolor(WHITE);
    printf("%60s______________________________________\n\n","");
    while (i<3){
        if (i==choix){
            textcolor(CYAN);
            printf("%62s%s\n","",maf[i]);
            textcolor(WHITE);
        }
        else printf("%62s%s\n","",maf[i]);
        i++;
    };
    printf("%60s______________________________________\n\n","");

}

selection_aff(int choix, ptr_paire plist, t_skieur skieur, int *nsk){

    system("cls");

    //Déclarations et initialisations:
    int ch=' ';
    int Max_iter=Random(2,3);

    //Traitement:
    switch (choix){
        case 0: //AFFICHAGE DU VECTEUR SKIEUR:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else{
                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%75sChargement","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(400);
                    };
                };

                system("cls");
                system("mode con LINES=65 COLS=160");
                printf("%71sLe vecteur skieur:\n","");
                afficher_skieur(skieur,(*nsk));
            };
            textcolor(CYAN);
            printf("\n%77sRetour\n\n","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            system("cls");
            system("mode con LINES=40 COLS=160");
            break;

        case 1: //RAFFICHAGE DES PAIRES DE SKIS:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%75sChargement","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(400);
                    };
                };

                system("cls");
                system("mode con LINES=350 COLS=160");
                printf("%70sLes paires de skis:\n","");
                afficher_paires(plist,skieur);
            };
            textcolor(CYAN);
            printf("\n%77sRetour\n\n","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            system("cls");
            system("mode con LINES=40 COLS=160");
            break;

        case 2: //RETOUR:
            afficher_menu_principal(&plist,skieur,&(*nsk));
            break;
        default:
            break;
    };
}

void afficher_menu_aff(ptr_paire plist, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    int i=0;
    int ch=' ';

    //Traitement:
    system("cls");
    menu_aff(0);
    while(1){
        ch=getch();
        switch(ch){
            case 72:
                if (i==0) i=2;
                else i--;
                menu_aff(i);
                break;
            case 80:
                if (i==2) i=0;
                else i++;
                menu_aff(i);
                break;
            case 13:
                selection_aff(i,plist,skieur,&(*nsk));
                system("cls");
                menu_aff(i=0);
                break;
            default:
                menu_aff(i);
                break;
        };
    };
}

///Menu des réservations: ///

void menu_res(int choix){

    //Déclarations et initialisations:
    int i=0;
    char *mr[3]={"  1. Reservation pour une personne  ",
                 "  2. Reservation pour une famille   ",
                 "  3. Retour au menu principal       "};

    //Traitement et affichage du menu:
    bas_page();
    entete();
    logo();
    textcolor(WHITE);
    printf("%60s______________________________________\n\n","");
    while (i<3){
        if (i==choix){
            textcolor(CYAN);
            printf("%62s%s\n","",mr[i]);
            textcolor(WHITE);
        }
        else printf("%62s%s\n","",mr[i]);
        i++;
    };
    printf("%60s______________________________________\n\n","");

}

selection_res(int choix, ptr_paire plist, t_skieur skieur, int *nsk){

    system("cls");

    //Déclarations et initialisations:
    int ch=' ';
    int Max_iter=Random(2,3);

    char nomloc[max_nom],adr[max_adr];
    int adrloc=1;
    int tai=0,deb=1,fin=1;
    bool possible;

    //Traitement:
    switch (choix){
        case 0: //RESERVATION POUR UNE PERSONNE:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                gotoxy(1,(nbr_lignes/2)-4);
                printf("%52sEntrez le nom du locataire(PAS D'ESPACES): ","");textcolor(CYAN);
                //Lecture du nom:
                int j=0;
                char c=' ';
                while (j<max_nom && c!=13){
                    c=getch();
                    if(c==8 && j>0){
                        printf("\b \b");
                        j--;
                    }
                    else if (c!=8){
                        printf("%c",c);
                        nomloc[j]=c;
                        j++;
                    };
                };
                j--;
                nomloc[j]='\0';
                printf("\n");
                ///
                if (cherchskieur(skieur,*nsk,strupr(nomloc))==(-1)){
                    textcolor(WHITE);printf("%52sEntrez son adresse(NUMERO DE LA WILAYA): ","");textcolor(CYAN);
                    int e=0;
                    char c=' ';
                    while (e<4 && c!=13){
                        c=getch();
                        if (c!=8 && e>=2) break;
                        if(c==8 && e>0){
                            printf("\b \b");
                            e--;
                        }
                        else if (c!=8 && c>=48 && c<=57 && e<2 ){
                            printf("%c",c);
                            adr[e]=c;
                            e++;
                        };
                    };
                    printf("\n");
                    adrloc=atoi(adr);
                };
                textcolor(WHITE);printf("%52sEntrez la taille de la paire de skis a louer: ","");textcolor(CYAN);
                scanf("%d",&tai);
                textcolor(WHITE);printf("%52sEntrez la periode de la reservation:\n","");
                printf("%56s> Debut: ","");textcolor(CYAN);
                scanf("%d",&deb);
                textcolor(WHITE);printf("%56s> Fin: ","");
                textcolor(CYAN);scanf("%d",&fin);textcolor(WHITE);

                //Chargement:
                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%70sTraitement en cours","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(350);
                    };
                };

                system("cls");
                gotoxy(1,nbr_lignes/2);
                reservation(plist,&possible,nomloc,adrloc,tai,deb,fin,skieur,&(*nsk));
                if (possible){

                    for (int j=0; j<4-Max_iter; j++){
                        system("cls");
                        gotoxy(1,nbr_lignes/2);
                        printf("%70sAllocation en cours","");
                        for(int i=0; i<3; i++){
                            printf(".");
                            delay(350);
                        };
                    };
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%68sReservation avec succes!\n","");
                }
                else printf("%68sEchac de la reservation!\n","");
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 1: //RESERVATION POUR UNE FAMILLE:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                gotoxy(1,nbr_lignes/2);
                printf("%52sEntrez le nom du locataire(PAS D'ESPACES): ","");textcolor(CYAN);
                //Lecture du nom:
                int j=0;
                char c=' ';
                while (j<max_nom && c!=13){
                    c=getch();
                    if(c==8 && j>0){
                        printf("\b \b");
                        j--;
                    }
                    else if (c!=8){
                        printf("%c",c);
                        nomloc[j]=c;
                        j++;
                    };
                };
                j--;
                nomloc[j]='\0';
                printf("\n");
                ///
                if (cherchskieur(skieur,*nsk,nomloc)==(-1)){
                    textcolor(WHITE);printf("%52sEntrez son adresse(NUMERO DE LA WILAYA): ","");textcolor(CYAN);
                    int e=0;
                    char c=' ';
                    while (e<4 && c!=13){
                        c=getch();
                        if (c!=8 && e>=2) break;
                        if(c==8 && e>0){
                            printf("\b \b");
                            e--;
                        }
                        else if (c!=8 && c>=48 && c<=57 && e<2 ){
                            printf("%c",c);
                            adr[e]=c;
                            e++;
                        };
                    };
                    printf("\n");
                    adrloc=atoi(adr);
                };
                textcolor(WHITE);
                system("cls");
                gotoxy(1,nbr_lignes/2);
                if (verifie_nom(nomloc) && verifie_adr(adrloc)) reservations(plist,nomloc,adrloc,skieur,&(*nsk));
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
                while (ch!=13) ch=getch();
            break;

        case 2: //RETOUR:
            afficher_menu_principal(&plist,skieur,&(*nsk));
            break;
        default:
            break;
    };
}

void afficher_menu_res(ptr_paire plist, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    int i=0;
    int ch=' ';

    //Traitement:
    system("cls");
    menu_res(0);
    while(1){
        ch=getch();
        switch(ch){
            case 72:
                if (i==0) i=2;
                else i--;
                menu_res(i);
                break;
            case 80:
                if (i==2) i=0;
                else i++;
                menu_res(i);
                break;
            case 13:
                selection_res(i,plist,skieur,&(*nsk));
                system("cls");
                menu_res(i=0);
                break;
            default:
                menu_res(i);
                break;
        };
    };
}

/// Menu de parcours des listes: ///

void menu_paire(int choix){

    //Déclarations et initialisations:
    int i=0;
    char *ms[4]={" 1. Nombre des paires dans la station ",
                 " 2. Les jours de location d'une paire ",
                 " 3. La paire de skis la plus demandee ",
                 " 4. Retour au menu principal          "};

    //Traitement et affichage du menu:
    bas_page();
    entete();
    logo();
    textcolor(WHITE);
    printf("%60s______________________________________\n\n","");
    while (i<4){
        if (i==choix){
            textcolor(CYAN);
            printf("%60s%s\n","",ms[i]);
            textcolor(WHITE);
        }
        else printf("%60s%s\n","",ms[i]);
        i++;
    };
    printf("%60s______________________________________\n\n","");

}

selection_paire(int choix, ptr_paire plist, t_skieur skieur, int *nsk){

    system("cls");

    //Déclarations et initialisations:
    int ch=' ';
    int tai;
    int Max_iter=Random(2,3);

    //Traitement:
    switch (choix){
        case 0: //NOMBRE DES PAIRES:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%66sCalcul du nombre des paires","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                system("cls");
                gotoxy(1,nbr_lignes/2);
                printf("%54sLe nombre des paires de skis dans la station est %d.","",nbskis(plist));
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 1: //NOMBRE DE JOURS DE LOCATION:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                gotoxy(1,nbr_lignes/2);
                printf("%60sEntrez la taille de la paire de skis: ","");textcolor(CYAN);
                scanf("%d",&tai);textcolor(WHITE);

                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%66sCalcul du nombre des jours","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                system("cls");
                gotoxy(1,nbr_lignes/2);
                int nbj=nbjloc(plist,tai);
                if (nbj>0) printf("%44sLe nombre de jours de location de la premiere paire de taille %d est %d.\n","",tai,nbj);
                else if (nbj==0) printf("%61sLa paire n'existe pas dans la station!\n","");
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 2: //LA PAIRE DE SKIS LA PLUS DEMANDEE:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%74sRecherche","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                system("cls");
                gotoxy(1,(nbr_lignes/2)-1);
                printf("%36sLa paire de skis la plus demandee en terme de duree de location est celle de taille %d!\n\n","",pg_resrv_nbj(plist));
                printf("%31sLa paire de skis la plus recherchee en proportion du nombre de locataires est celle de taille %d!\n\n","",pg_resrv_loc(plist));
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 3: //RETOUR:
            afficher_menu_principal(&plist,skieur,&(*nsk));
            break;
        default:
            break;
    };
}

void afficher_menu_paire(ptr_paire plist, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    int i=0;
    int ch=' ';

    //Traitement:
    system("cls");
    menu_paire(0);
    while(1){
        ch=getch();
        switch(ch){
            case 72:
                if (i==0) i=3;
                else i--;
                menu_paire(i);
                break;
            case 80:
                if (i==3) i=0;
                else i++;
                menu_paire(i);
                break;
            case 13:
                selection_paire(i,plist,skieur,&(*nsk));
                system("cls");
                menu_paire(i=0);
                break;
            default:
                menu_paire(i);
                break;
        };
    };
}

/// Menu de parcours du vecteur skieur: ///

void menu_skieur(int choix){

    //Déclarations et initialisations:
    int i=0;
    char *ms[4]={" 1. Recherche d'un locataire par index ",
                 " 2. Recherche d'un locataire par nom   ",
                 " 3. Locataire le plus actif (assidu)   ",
                 " 4. Retour au menu principal           "};

    //Traitement et affichage du menu:
    bas_page();
    entete();
    logo();
    textcolor(WHITE);
    printf("%60s______________________________________\n\n","");
    while (i<4){
        if (i==choix){
            textcolor(CYAN);
            printf("%60s%s\n","",ms[i]);
            textcolor(WHITE);
        }
        else printf("%60s%s\n","",ms[i]);
        i++;
    };
    printf("%60s______________________________________\n\n","");

}

selection_skieur(int choix, ptr_paire plist,t_skieur skieur, int *nsk){

    system("cls");

    //Déclarations et initialisations:
    int ch=' ';
    int Max_iter=Random(1,3);
    char nomloc[max_nom];
    int ind;

    //Traitement:
    switch (choix){
        case 1: //RECHERCHE D'UN LOCATAIRE PAR NOM:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                gotoxy(1,nbr_lignes/2);
                printf("%52sEntrez le nom du locataire: ","");textcolor(CYAN);
                //Lecture du nom:
                int j=0;
                char c=' ';
                while (j<max_nom && c!=13){
                    c=getch();
                    if(c==8 && j>0){
                        printf("\b \b");
                        j--;
                    }
                    else if (c!=8){
                        printf("%c",c);
                        nomloc[j]=c;
                        j++;
                    };
                };
                j--;
                nomloc[j]='\0';
                printf("\n");
                ///
                textcolor(WHITE);
                ind=cherchskieur(skieur,*nsk,nomloc);

                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%74sRecherche","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                system("cls");
                gotoxy(1,nbr_lignes/2);

                if (ind==(-1)){
                    gotoxy(1,nbr_lignes/2);
                    printf("%58sDesole, cette personne n'est pas un client!\n","");
                }
                else {
                    gotoxy(1,(nbr_lignes/2)-3);
                    printf("%68sLe client recherche est:\n","");
                    printf("%62s _________________________________ \n%62s| IND |         NOM         | PSK |\n%62s|_____|_____________________|_____|\n%62s| %3d | %19s | %3d |\n%62s|_____|_____________________|_____|\n","","","","",ind,skieur[ind].nom,skieur[ind].psk,"");
                };
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 2: //LE CLIENT LE PLUS PRESENT DANS LES LISTES DE RESERVATIONS:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                int ind,psk;
                max_psk(skieur,*nsk,&ind,&psk);

                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%74sRecherche","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                system("cls");
                gotoxy(1,(nbr_lignes/2)-3);
                printf("%49sLe client le plus present dans les listes de reservations est:\n","");
                printf("%62s _________________________________ \n%62s| IND |         NOM         | PSK |\n%62s|_____|_____________________|_____|\n%62s| %3d | %19s | %3d |\n%62s|_____|_____________________|_____|\n","","","","",ind,skieur[ind].nom,skieur[ind].psk,"");
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 0: //RECHERCHE D'UN LOCATAIRE PAR INDEX
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                gotoxy(1,nbr_lignes/2);
                printf("%64sLe nombre des locataires(nsk)=","");textcolor(CYAN);printf("%d\n",*nsk);textcolor(WHITE);
                printf("%65sEntrez l'indice du locataire: ","");textcolor(CYAN);
                scanf("%d",&ind);textcolor(WHITE);
                while(ind>(*nsk) || ind<1){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%67sAttention, indice invalid!\n","");
                    printf("%59sRe-entrez l'indice du locataire(","");textcolor(CYAN);printf("nsk=%d",*nsk);textcolor(WHITE);printf("): ");
                    textcolor(CYAN);scanf("%d",&ind);textcolor(WHITE);
                };

                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%74sRecherche","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                system("cls");
                gotoxy(1,(nbr_lignes/2)-3);
                printf("%68sLe client recherche est:\n","");
                printf("%62s _________________________________ \n%62s| IND |         NOM         | PSK |\n%62s|_____|_____________________|_____|\n%62s| %3d | %19s | %3d |\n%62s|_____|_____________________|_____|\n","","","","",ind,skieur[ind].nom,skieur[ind].psk,"");
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 3: //RETOUR:
            afficher_menu_principal(&plist,skieur,&(*nsk));
            break;
        default:
            break;
    };
}

void afficher_menu_skieur(ptr_paire plist, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    int i=0;
    int ch=' ';

    //Traitement:
    system("cls");
    menu_skieur(0);
    while(1){
        ch=getch();
        switch(ch){
            case 72:
                if (i==0) i=3;
                else i--;
                menu_skieur(i);
                break;
            case 80:
                if (i==3) i=0;
                else i++;
                menu_skieur(i);
                break;
            case 13:
                selection_skieur(i,plist,skieur,&(*nsk));
                system("cls");
                menu_skieur(i=0);
                break;
            default:
                menu_skieur(i);
                break;
        };
    };
}

///Introduction du programme: ///

void logo_intro(){

    printf("\n\n\n\e[0m%65s                \e[46m      \n",""); delay(100);
    printf("\e[0m%65s                \e[46m  \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s            \e[46m    \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s          \e[46m  \e[0m        \e[46m    \n",""); delay(100);
    printf("\e[0m%65s        \e[46m  \e[0m    \e[46m  \e[0m        \e[46m  \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s        \e[46m      \e[0m      \e[46m        \n",""); delay(100);
    printf("\e[0m%65s          \e[46m          \e[0m    \e[46m  \n",""); delay(100);
    printf("\e[0m%65s        \e[46m    \e[0m      \e[46m  \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s      \e[46m  \e[0m  \e[46m  \e[0m        \e[46m  \n",""); delay(100);
    printf("\e[0m%65s    \e[46m  \e[0m      \e[46m    \e[0m  \e[46m  \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s  \e[46m  \e[0m          \e[46m  \e[0m  \e[46m  \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s\e[46m  \e[0m          \e[46m  \e[0m  \e[46m    \e[0m  \e[46m  \n",""); delay(100);
    printf("\e[0m%65s            \e[46m  \e[0m  \e[46m    \e[0m  \e[46m  \e[0m      \e[46m  \n",""); delay(100);
    printf("\e[0m%65s  \e[46m                            \n\n",""); delay(100);

    printf("\n\t\t\t\t\t\t\t\e[0m     \e[46m       \e[0m \e[46m  \e[0m   \e[46m  \e[0m \e[46m  \e[0m     \e[46m  \e[0m \e[46m        \e[0m   \e[46m  \e[0m",""); delay(150);
    printf("\n\t\t\t\t\t\t\t\e[0m     \e[46m  \e[0m      \e[46m  \e[0m  \e[46m  \e[0m  \e[46m  \e[0m     \e[46m  \e[0m    \e[46m  \e[0m      \e[46m  \e[0m",""); delay(150);
    printf("\n\t\t\t\t\t\t\t\e[0m     \e[46m       \e[0m \e[46m     \e[0m   \e[46m  \e[0m     \e[46m  \e[0m    \e[46m  \e[0m      \e[46m  \e[0m",""); delay(150);
    printf("\n\t\t\t\t\t\t\t\e[0m          \e[46m  \e[0m \e[46m  \e[0m  \e[46m  \e[0m  \e[46m  \e[0m     \e[46m  \e[0m    \e[46m  \e[0m",""); delay(150);
    printf("\n\t\t\t\t\t\t\t\e[0m     \e[46m       \e[0m \e[46m  \e[0m   \e[46m  \e[0m \e[46m  \e[0m     \e[46m  \e[0m    \e[46m  \e[0m      \e[46m  \e[0m",""); delay(150);

    printf("\n\n\n");
};

void introduction(){

    char ch=' ';
    bool fait=false;

    //Animation SKI IT!:
    logo_intro();

    for(int j=0; j<=100; j++){

        //Chargement:
        gotoxy(1,25);
        printf("\n\n%73sChargement","");
        for (int i=1 ; i<=j%15; i=i+5) printf(".");
        for (int i=0; i<=15-j%15; i=i+5)printf(" ");
        printf("\n\n%29s","");
        printf("\033[46m");

        //Affichage de la barre:
        for (int k=1; k<=j; k++) printf(" ");

        //Le pourcentage:
        printf("\n\n\033[0m%77s%d%%\n\n\n","",j);
        delay(Random(30,60));
    };
    delay(200);

    //Ameliorer:
    char amelio[161]="Veuillez consulter les informations complementaires pour ameliorer votre experience!";
    system("cls");
    gotoxy(1,nbr_lignes/2);
    printf("%38s","");
    for (int i=0; i<84; i++){
        delay(30);
        printf("%c",amelio[i]);
    };
    delay(1500);

    //continuer:
    char cont[161]="<Appuyez sur ENTRER pour continuer>";
    system("cls");
    gotoxy(1,nbr_lignes/2);
    printf("%62s","");
    for (int i=0; i<35; i++){
        delay(30);
        printf("%c",cont[i]);
    };
    while (ch!=13) ch=getch();
    system("cls");
}

///Quitter le programme: ///

void quitter_outro(){

    bool fait;
    int del=Random(15,70);

    //Affichage du logo:
    system("cls");
    gotoxy(1,(nbr_lignes/2)-14);
    logo_intro(&fait);

    //Effacement:
    gotoxy(1,(nbr_lignes/2)-14);
    textbackground(BLACK);
    for (int i=0; i<25; i++){
        delay(100);
        printf("%160s\n","");
    };

    //Message:
    char message[161]="Merci d'avoir utilise notre application jusqu'a present, nous esperons vous revoir bientot!";
    system("cls");
    gotoxy(1,nbr_lignes/2);
    printf("%34s","");
    for (int i=0; i<92; i++){
        delay(40);
        printf("%c",message[i]);
    };
    delay(1000);
    gotoxy(1,1);
    for (int i=1; i<=nbr_lignes; i++){
        delay(20);
        printf("\e[46m%160s","");
    };
    exit(1);
}

void quitter(ptr_paire plist, t_skieur skieur, int *nsk){
    gotoxy(1,(nbr_lignes/2)-1);
    printf("%62sEtes-vous sur(e) de vouloir quitter?\n\n","");
    textcolor(CYAN);printf("%56sOUI(ENTRER)                          NON(ECHAP)\n\n\n","");textcolor(WHITE);
    int c=' ';
    bool choix=false;
    while(!choix){
        c=getch();
        if (c==13) quitter_outro();
        if (c==27){
            system("cls");
            afficher_menu_principal(&plist,skieur,&(*nsk));
        };
    };
}

/// Menu principal: ///

void entete(){
    time_t t;
    t = time(NULL);
    struct tm tm = *localtime(&t);
    textbackground(LIGHTGRAY);
    textcolor(BLACK);
    printf("  Location des skis                                  Ecole nationale Superieure d'Informatique ESI (ex INI)                                   Date: %02d/%02d/%04d  \n\n\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
    textcolor(WHITE);
    textbackground(BLACK);
}

void bas_page(){
    textbackground(LIGHTGRAY);
    textcolor(BLACK);
    gotoxy(1,nbr_lignes);
    printf("  SOUALAH MOHAMMED Zakaria et BOUKAKIOU Rayan                              2022/2023                                                                 TP1 ALSDD  ");
    textcolor(WHITE);
    textbackground(BLACK);
    gotoxy(1,1);
}

void logo(){
    printf("\n\t\t\t\t\t\t\e[46m  \e[0m       \e[46m      \e[0m   \e[46m      \e[0m  \e[46m     \e[0m  \e[46m        \e[0m \e[46m  \e[0m  \e[46m      \e[0m  \e[46m   \e[0m    \e[46m  \n","");
    printf("\t\t\t\t\t\t\e[46m  \e[0m      \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m      \e[46m  \e[0m   \e[46m  \e[0m    \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m    \e[46m  \e[0m \e[46m    \e[0m   \e[46m  \n","");
    printf("\t\t\t\t\t\t\e[46m  \e[0m      \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m      \e[46m       \e[0m    \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m \e[46m  \e[0m  \e[46m  \n","");
    printf("\t\t\t\t\t\t\e[46m  \e[0m      \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m      \e[46m  \e[0m   \e[46m  \e[0m    \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m    \e[46m  \e[0m \e[46m  \e[0m  \e[46m  \e[0m \e[46m  \n","");
    printf("\t\t\t\t\t\t\e[46m       \e[0m  \e[46m      \e[0m   \e[46m      \e[0m \e[46m  \e[0m   \e[46m  \e[0m    \e[46m  \e[0m    \e[46m  \e[0m  \e[46m      \e[0m  \e[46m  \e[0m   \e[46m    \n\n\n");
    ///
    printf("\t\t\t\t\t\t\e[0m     \e[46m      \e[0m  \e[46m       \e[0m \e[46m       \e[0m     \e[46m       \e[0m \e[46m  \e[0m   \e[46m  \e[0m \e[46m  \e[0m \e[46m       \n");
    printf("\t\t\t\t\t\t\e[0m     \e[46m  \e[0m   \e[46m  \e[0m \e[46m  \e[0m      \e[46m  \e[0m          \e[46m  \e[0m      \e[46m  \e[0m  \e[46m  \e[0m  \e[46m  \e[0m \e[46m  \n");
    printf("\t\t\t\t\t\t\e[0m     \e[46m  \e[0m   \e[46m  \e[0m \e[46m     \e[0m   \e[46m       \e[0m     \e[46m       \e[0m \e[46m     \e[0m   \e[46m  \e[0m \e[46m       \n");
    printf("\t\t\t\t\t\t\e[0m     \e[46m  \e[0m   \e[46m  \e[0m \e[46m  \e[0m           \e[46m  \e[0m          \e[46m  \e[0m \e[46m  \e[0m  \e[46m  \e[0m  \e[46m  \e[0m      \e[46m  \n");
    printf("\t\t\t\t\t\t\e[0m     \e[46m      \e[0m  \e[46m       \e[0m \e[46m       \e[0m     \e[46m       \e[0m \e[46m  \e[0m   \e[46m  \e[0m \e[46m  \e[0m \e[46m       \n");

    printf("\n\n\n");

}

void menu_principal(int choix){

    //Déclarations et initialisations:
    int i=0;
    char *m[max_choix]={"  1. Creation des structures      ",
                        "  2. Affichage des structures     ",
                        "  3. Reservation(s) des skis      ",
                        "  4. Parcours des paires de skis  ",
                        "  5. Parcours du vecteur skieur   ",
                        "  6. Suppression des reservations ",
                        "  7. Informations complementaires ",
                        "  8. Quitter l'application        "};

    //Traitement et afiichage du menu:
    bas_page();
    entete();
    logo();
    textcolor(WHITE);
    printf("%60s______________________________________\n\n","");
    while (i<max_choix){
        if (i==choix){
            textcolor(CYAN);
            printf("%63s%s\n","",m[i]);
            textcolor(WHITE);
        }
        else printf("%63s%s\n","",m[i]);
        i++;
    };
    printf("%60s______________________________________\n\n","");
}

void selection_principal(int choix, ptr_paire *plist, t_skieur skieur, int *nsk){

    srand(time(NULL));
    system("cls");

    //Déclarations et initialisations:
    int ch=' ';
    int Max_iter=Random(1,3);
    char nomloc[max_nom];

    //Traitement:
    switch (choix){
        case 0: //CREATION DES STRUCTURES:
            for (int j=0; j<Max_iter; j++){
                system("cls");
                gotoxy(1,nbr_lignes/2);
                printf("%66sCreation des paires de skis","");
                for(int i=0; i<3; i++){
                    printf(".");
                    delay(300);
                };
            };
            for (int j=0; j<4-Max_iter; j++){
                system("cls");
                gotoxy(1,nbr_lignes/2);
                printf("%67sCreation du vecteur skieur","");
                for(int i=0; i<3; i++){
                    printf(".");
                    delay(300);
                };
            };
            creer_struct(&(*plist),&(*nsk),skieur);
            system("cls");
            gotoxy(1,nbr_lignes/2);
            printf("%65sStructures creees avec succes!%65s\n","","");
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 1: //AFFICHAGE DES STRUCTURES:
            afficher_menu_aff(*plist,skieur,&(*nsk));
            break;

        case 2: //RESERVATION(S) DES SKIS:
            afficher_menu_res(*plist,skieur,&(*nsk));
            break;

        case 3: //PARCOURS DES PAIRES DE SKIS:
            afficher_menu_paire(*plist,skieur,&(*nsk));
            break;

        case 4: //PARCOURS DU VECTEUR SKIEUR:
            afficher_menu_skieur(*plist,skieur,&(*nsk));
            break;

        case 5: //SUPPRESSION DES RESERVATIONS:
            if (*nsk==0){
                gotoxy(1,nbr_lignes/2);
                printf("%61sIl faut d'abord creer les stuctures!\n","");
            }
            else {
                gotoxy(1,nbr_lignes/2);
                printf("%52sEntrer le nom du locataire(PAS D'ESPACES): ","");textcolor(CYAN);
                //Lecture du nom:
                int j=0;
                char c=' ';
                while (j<max_nom && c!=13){
                    c=getch();
                    if(c==8 && j>0){
                        printf("\b \b");
                        j--;
                    }
                    else if (c!=8){
                        printf("%c",c);
                        nomloc[j]=c;
                        j++;
                    };
                };
                j--;
                nomloc[j]='\0';
                printf("\n");
                ///
                textcolor(WHITE);

                for (int j=0; j<Max_iter; j++){
                    system("cls");
                    gotoxy(1,nbr_lignes/2);
                    printf("%70sTraitement en cours","");
                    for(int i=0; i<3; i++){
                        printf(".");
                        delay(500);
                    };
                };

                annuleres(nomloc,skieur,*plist,&(*nsk));
            };
            textcolor(CYAN);
            printf("\n%77sRetour","");
            textcolor(WHITE);
            while (ch!=13) ch=getch();
            break;

        case 6: //INFORMATIONS COMPLEMENTAIRES:
            afficher_menu_inf(*plist,skieur,&(*nsk));
            break;

        case 7: //QUITTER:
            quitter(*plist,skieur,&(*nsk));
            break;

        default:
            break;
    };
}

void afficher_menu_principal(ptr_paire *plist, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    int i=0;
    int ch=' ';

    //Traitememt:
    menu_principal(0);
    while(1){
        ch=getch();
        switch(ch){
            case 72:
                if (i==0) i=max_choix-1;
                else i--;
                menu_principal(i);
                break;
            case 80:
                if (i==max_choix-1) i=0;
                else i++;
                menu_principal(i);
                break;
            case 13:
                selection_principal(i,&(*plist),skieur,&(*nsk));
                system("cls");
                menu_principal(i=0);
                break;
            default:
                menu_principal(i);
                break;
        };
    };
}
