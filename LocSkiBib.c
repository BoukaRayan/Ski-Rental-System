#include "LocSkiBib.h"



///Machine abstraite LLC: ///

void allouer_paire(ptr_paire *p){
    *p=malloc(sizeof(paire_ski));
}
void liberer_paire(ptr_paire p){
    free(p);
}
void aff_taille(ptr_paire p, int V){
    p->taille=V;
}
void aff_adr_paire(ptr_paire p, ptr_paire q){
    p->skisuiv=q;
}
void aff_loc(ptr_paire p, ptr_res q){
    p->loc=q;
}
ptr_paire suivant_paire(ptr_paire p){
    return(p->skisuiv);
}
int valeur_taille(ptr_paire p){
    return(p->taille);
}
ptr_res valeur_loc(ptr_paire p){
    return(p->loc);
}



///Machine abstraite Sous-LLC: ///

void allouer_res(ptr_res *p){
    *p=malloc(sizeof(res_ski));
}
void liberer_res(ptr_res p){
    free(p);
}
void aff_deb(ptr_res p,int V){
        p->deb=V;
}
void aff_fin(ptr_res p,int V){
        p->fin=V;
}
void aff_ind(ptr_res p,int V){
        p->ind=V;
}
void aff_adr_res(ptr_res p, ptr_res q){
    p->ressuiv=q;
}
ptr_res suivant_res(ptr_res p){
    return(p->ressuiv);
}
int valeur_deb(ptr_res p){
    return(p->deb);
}
int valeur_fin(ptr_res p){
    return(p->fin);
}
int valeur_ind(ptr_res p){
    return(p->ind);
}



///1. Création des structures et insertion d'elements: ///

/*a) Création des structures: */

//Fonction Random: renvoie un nombre aléatoire entre Min et Max.
int Random(int Min, int Max){
    return (rand()%(Max-Min+1)+Min);
}

//Procédure tri_bulles_paires: trie les paires de skis par ordre croissant sur la taille.
void tri_bulles_paires(ptr_paire plist){

    //Déclarations:
    ptr_paire p; //Pointeur de parcours.
    bool permut; //Variable booléenne qui signifie la présence des permutations.
    int sauv;

    //Le tri:
    do{
        permut=false;
        p=plist;
        while(suivant_paire(p)!=NULL){
            if (valeur_taille(p)>valeur_taille(suivant_paire(p))){
                //Permutation entre la taille du maillon p et son successeur:
                sauv=valeur_taille(p) ;
                aff_taille(p,valeur_taille(suivant_paire(p)));
                aff_taille(suivant_paire(p),sauv);
                permut=true;
            };
            p=suivant_paire(p);
        };
    }while(permut); //On continue tant qu'il reste des permutations à effectuer.
}

//Procédure creer_sous_struct: permet créer et remplire les sous-listes de réservations.
void creer_sous_struct(ptr_res *tete, int nsk){

    //Déclarations et initialisations:
    *tete=NULL;
    int nbr_res,ind,deb,fin;
    int i=1;
    int dernier=1;
    ptr_res p,q;
    nbr_res=Random(1,6); //Nombre des réservations de la paire de skis géneré aléatoirement.

    //Création de la sous-listes:
    while(i<=nbr_res && dernier<fin_sais){
        //Génération aléatoire des champs deb, fin et ind:
        deb=Random(dernier,fin_sais);
        fin=Random(deb,fin_sais);
        ind=Random(1,nsk);
        dernier=fin+1;
        //Création et insertion du sous-maillon:
        allouer_res(&p);
        aff_deb(p,deb);
        aff_fin(p,fin);
        aff_ind(p,ind);
        if(*tete==NULL) *tete=p ;
        else aff_adr_res(q,p);
        q=p;
        i++;
     };
     aff_adr_res(p,NULL);
}

//Procédure creer_struct: permet créer la LLC des paires de skis.
void creer_struct(ptr_paire *plist, int *nsk, t_skieur skieur){

    srand(time(NULL)); //Pour générer des nombres aléatoires différents.

    //Déclarations et initialisations:
    int tai,nbr_ski;
    ptr_paire p,q;
    ptr_res tete_sous_llc; //La tête de la sous-liste.
    nbr_ski=Random(15,25); //Nombre des paires de skis géneré aléatoirement.
    *nsk=Random(35,max_skieur-45); //La taille du tableau skieur.
    *plist=NULL;

    //Création des paires:
    for(int i=1; i<=nbr_ski; i++){
        tai=Random(16,40)*5; //Taille de la paire de skis.
        allouer_paire(&p);
        aff_taille(p,tai);
        creer_sous_struct(&tete_sous_llc,*nsk); //Création de la sous-liste de réservations.
        aff_loc(p,tete_sous_llc);
        if (*plist==NULL) *plist=p;
        else aff_adr_paire(q,p);
        q=p;
    };
    aff_adr_paire(q,NULL);
    //Création du tableau skieur et tri de la liste:
    creer_skieur(skieur,*nsk,*plist);
    tri_bulles_paires(*plist);
}

//Procédure fix_psk: fixe les champs psk nuls du tableau skieur.
void fix_psk(ptr_paire plist, t_skieur skieur, int nsk){

    //Déclarations et initialisations:
    ptr_paire p;
    ptr_res q,r;
    int deb,fin;
    int dernier=1;

    //Allocation d'un nouveau maillon:
    allouer_paire(&p);
    aff_taille(p,Random(16,40)*5);
    aff_loc(p,NULL);

    //Recherche et fixation des champs psk nuls:
    for(int j=1; j<=nsk; j++){
        if ((skieur[j].psk)==0){
            (skieur[j].psk)++;
            //Génération aléatoire des champs deb, fin et ind:
            deb=Random(dernier,dernier+5);
            fin=Random(deb,deb+5);
            dernier=fin+1;
            //Création et insertion du sous-maillon:
            allouer_res(&q);
            aff_deb(q,deb);
            aff_fin(q,fin);
            aff_ind(q,j);
            if (valeur_loc(p)==NULL) aff_loc(p,q);
            else aff_adr_res(r,q);
            r=q;
        };
    };
    aff_adr_res(q,NULL);
    if (valeur_loc(p)==NULL) liberer_paire(p); //Pas de champs psk nuls, on libere le maillon!
    else {
        //Insertion du maillon dans la liste:
        aff_adr_paire(p,suivant_paire(plist));
        aff_adr_paire(plist,p);
    };
}

//Procédure creer_skieur: permet de créer le tableau skieur.
void creer_skieur(t_skieur skieur, int nsk, ptr_paire plist){

    srand(time(NULL)); //Pour générer des nombres aléatoires différents.

    //Déclarations et initialisations:
    int i,dernier=1;
    int offset=Random(1,90);
    ptr_paire p;
    ptr_res q;
    p=plist;

    //Tableaux des noms et des wilayas:
    char wilayas[][max_adr]={"","ADRAR", "CHLEF", "LAGHOUAT", "OUM EL BOUAGHI", "BATNA", "BEJAIA", "BISKRA", "BECHAR", "BLIDA", "BOUIRA","TAMANRASSET", "TEBESSA", "TLEMCEN", "TIARET", "TIZI OUZOU", "ALGER", "DJELFA", "JIJEL", "SETIF", "SAIDA","SKIKDA","SIDI BEL ABBES", "ANNABA", "GUELMA", "CONSTANTINE", "MEDEA", "MOSTAGANEM", "M'SILA","MASCARA", "OUARGLA", "ORAN", "EL BAYADH", "ILLIZI", "BORDJ BOU ARRERIDJ", "BOUMERDES", "EL TARF", "TINDOUF", "TISSEMSILT","EL OUED", "KHENCHELA", "SOUK AHRAS", "TIPASA", "MILA", "AIN DEFLA", "NAAMA", "AIN TEMOUCHENT", "GHARDAIA", "RELIZANE", "TIMIMOUN", "BORDJ BADJI MOKHTAR", "OULED DJELLAL", "BENI ABBES", "IN SALAH", "IN GUEZZAM","TOUGGOURT", "DJANET", "M'GHAIR", "MENIAA"};
    char nom[][max_nom]={"ZEGHIMI", "SAHRAOUI", "MAHIEEDINE", "ATHAMNA", "FERIEL", "BEJBEJ", "HAMIDI", "SAIDJI", "KHALED", "SOUALAH", "HAMIDOUCHE", "BOUKAKIOU", "SIDAHMED", "MEZIANE", "AGAL", "KRIM", "ALLOUCHE", "SOUABNI", "MELLITI", "BELATRACHE", "BOUSKINE", "DERRADJI", "MENDJEL", "LADOUL", "HIDOUCHE", "FARHI", "CHIKHI", "BOUAB", "BOUDERBALA", "DOUAKHA", "ZERROUKI", "DJERFI", "CHOUCHAOUI", "ZIADI", "TAILEB", "REZZOUG", "MARAF", "ZITOUNI", "MOUCER", "MEKIRCHA", "KHIRALLAH", "FOUDILI", "HELLALET", "DEBBICHE", "BOUSDJIRA", "DJOUGHLAL", "AKAL", "ALOUANE", "CHERIF", "BEDRAOUI", "AZZOUZ", "BELHADJ", "IDIR", "LAYTH", "ZOUBIRI", "BETAYEB", "ACHOUCHE", "CHIKHE", "AITNOURI", "TAYBI", "ADRIANE", "ZAYD", "BOUZID", "LAKHDAR", "RAHMA", "WEKAL", "BOUGHERRA", "MAHREZ", "BADREDINE", "DIAR", "MARIA", "BADIS", "LAARBI", "MERRZOUGI", "SELAMI", "LAALI", "FERHAN", "AID", "RYAN", "BENNEFISSA", "MAAMAR", "BOUMISSA", "GHOUICI", "ABBACI", "BELHADJ", "BENDAOUD", "LAZREG", "SAIBI", "TORKI", "ZAIME", "AMARA", "HAOUAS", "BOUFELGHA", "TERKMANI", "GUERZOU", "BOUDISSA", "DERDIDI", "DJENANE", "KASMI", "KITMIE", "BELAILI", "MANSOURI"};

    //Remplissage des noms et des adresses:
    for( i=1; i<=nsk; i++){
        strcpy(skieur[i].adresse,wilayas[Random(1,58)]);
        strcpy(skieur[i].nom,nom[(i+offset)%99]);
        skieur[i].psk=0;
    };

     //Remplissage du champs psk:
     while(p!=NULL){
        q=valeur_loc(p);
        while(q!=NULL){
            skieur[valeur_ind(q)].psk++;
            q=suivant_res(q);
       };
        p=suivant_paire(p);
    };

    //fixation des champs psk nuls:
    fix_psk(plist,skieur,nsk);
}

/*b) Location: */

//Procédure tri_bulles_res: trie les réservations par ordre croissant sur les dates.
void tri_bulles_res(ptr_res premloc){

    //Déclarations:
    ptr_res p; //Pointeur de parcours.
    bool permut; //Variable booléenne qui signifie la présence des permutations.
    int sauv;

    //Le tri:
    do{
        permut=false;
        p=premloc;
        while(suivant_res(p)!=NULL){
            if (valeur_deb(p)>valeur_deb(suivant_res(p))){
                //Permutation entre la taille du maillon p et son successeur:
                sauv=valeur_deb(p);
                aff_deb(p,valeur_deb(suivant_res(p)));
                aff_deb(suivant_res(p),sauv);
                sauv=valeur_fin(p);
                aff_fin(p,valeur_fin(suivant_res(p)));
                aff_fin(suivant_res(p),sauv);
                permut=true;
            };
            p=suivant_paire(p);
        };
    }while(permut); //On continue tant qu'il reste des permutations à effectuer.
}
//Procedure insertete: insert un maillon contenant deb, fin et ind en tête de locski.
void insertete(ptr_res *premloc, int deb, int fin, int ind){
    //Déclarations et initialisations:
    ptr_res p;
    allouer_res(&p); //allocation d'un nouveau maillon
    aff_deb(p,deb); //affectation des
    aff_fin(p,fin); //champs deb, fin
    aff_ind(p,ind); //et ind
    aff_adr_res(p,*premloc);
    *premloc=p;
    tri_bulles_res(*premloc);
}
//Fonction location: réalise la location et renvoie vrai si c'est possible, faux sinon.
bool location(ptr_res *premloc, int deb, int fin, int ind, t_skieur skieur){

    //Déclarations et initialisations:
    ptr_res p; //Pointeur de parcours.
    bool loca=true; //Represente l'etat de la location.
    p=(*premloc);

    //Traitement:
    while(p!=NULL && (valeur_fin(p)<deb || valeur_deb(p)>fin)) p=suivant_res(p); //On teste si la période de location [deb, fin] ne chevauche pas la période de location du maillon courant p.
    if (p!=NULL) loca=false; //La paire de skis est déjà louée pour la période donnée
    else{
        insertete(&(*premloc),deb,fin,ind); //La paire de skis est disponible. On ajoute alors la réservation en tête de la sous-liste à l'aide de la procédure insertete
        (skieur[ind].psk)++;
    };

    return loca;
}

/*c) Réservation: */

//Fonction verfie_nom: renvoie vrai si le nom entré est valid, faux sinon.
bool verifie_nom(char nomloc[max_nom]){
    bool verif=true;
    int i=0;
    while (verif && nomloc[i]!='\0'){
        if (((nomloc[i]<41 || nomloc[i]>90) && (nomloc[i]<97 || nomloc[i]>122)) && nomloc[i]!='-'){
            printf("%23sLe nom introduit ne respecte pas les standards de nomination, veuillez consulter les informations complementaires!\n","");
            verif=false;
        }
        else i++;
    };
    return verif;
}

//Fonction verfie_adr: renvoie vrai si l'adresse entrée est valide, faux sinon.
bool verifie_adr(int adr){
    bool verif=true;
    if (adr<1 || adr>58){
        verif=false;
        printf("%45sAdresse erronee, veuillez consulter les informations complementaires!\n","");
    };
    return verif;
}

//Fonction verfie_taille: renvoie vrai si la taille entrée est valide, faux sinon.
bool verifie_taille(int tai){

    //Déclarations et initialisations:
    bool verif=true;

    //Vérification des dates:
    if (tai>200 || tai<80 || (tai%5)!=0){ //Taille invalide car elle n'est pas un multiple de 5 ou elle n'est pas entre 80 et 200
        printf("%46sTaille invalid, veuillez consulter les informations complementaires!\n","");
        verif=false;
    };

    return verif;
}

//Fonction verfie_deb_fin: renvoie vrai si les dates de début et fin sont valides, faux sinon.
bool verifie_deb_fin(int deb, int fin){

    //Déclarations et initialisations:
    bool verif=true;

    //Vérification des dates:
    if (deb>fin || deb<1 || fin>fin_sais){
        printf("%62sDates invalides! (1<=DEB<=FIN<=151)\n","");
        verif=false;
    };

    return verif;
}

//Procédure reservation: fait la réservation et renvoie une variable booléenne possible selon son l'état(Utilise la fonction location).
void reservation(ptr_paire plist, bool *possible, char nomloc[max_nom], int adr, int tai, int de, int fi, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    ptr_paire p;
    ptr_paire q;
    ptr_res premloc;
    p=plist;
    *possible=false;
    char wilayas[][max_adr]={"","ADRAR", "CHLEF", "LAGHOUAT", "OUM EL BOUAGHI", "BATNA", "BEJAIA", "BISKRA", "BECHAR", "BLIDA", "BOUIRA","TAMANRASSET", "TEBESSA", "TLEMCEN", "TIARET", "TIZI OUZOU", "ALGER", "DJELFA", "JIJEL", "SETIF", "SAIDA","SKIKDA","SIDI BEL ABBES", "ANNABA", "GUELMA", "CONSTANTINE", "MEDEA", "MOSTAGANEM", "M'SILA","MASCARA", "OUARGLA", "ORAN", "EL BAYADH", "ILLIZI", "BORDJ BOU ARRERIDJ", "BOUMERDES", "EL TARF", "TINDOUF", "TISSEMSILT","EL OUED", "KHENCHELA", "SOUK AHRAS", "TIPASA", "MILA", "AIN DEFLA", "NAAMA", "AIN TEMOUCHENT", "GHARDAIA", "RELIZANE", "TIMIMOUN", "BORDJ BADJI MOKHTAR", "OULED DJELLAL", "BENI ABBES", "IN SALAH", "IN GUEZZAM","TOUGGOURT", "DJANET", "M'GHAIR", "MENIAA"};

    //Traitement:
    if (verifie_nom(nomloc) && verifie_adr(adr) && verifie_taille(tai) && verifie_deb_fin(de,fi)){
        nomloc=strupr(nomloc);
        int ind=cherchskieur(skieur,*nsk,nomloc);
        if (ind==(-1)){ //Si le locataire n'existe pas dans le vecteur skieur on crée un locataire temporaire (fictif) et on essaie de louer une paire.
            ind=(*nsk)+1;
            skieur[ind].psk=0;
        };
        //Parcours de la liste et recherche d'une location possible:
        while (p!=NULL && valeur_taille(p)<=tai && !(*possible)){
            if (valeur_taille(p)==tai){
                premloc=valeur_loc(p);
                *possible=location(&premloc,de,fi,ind,skieur);
                q=p;
            };
            p=suivant_paire(p);
        };

        if (*possible){ //Si l'allocation est faite.
            aff_loc(q,premloc);
            if (ind>(*nsk)){ //Si c'est le locataire fictif, on affecte le nom et l'adresse.
                (*nsk)++;
                strcpy(skieur[ind].nom,nomloc);
                strcpy(skieur[ind].adresse,wilayas[adr]);
            };
        }
        else printf("%68sPaire de skis deja prise!\n","");
    };
}

/*d) Plusieurs réservations: */

//Procédure creer_res: permet de lire les tailles et les dates des différentes réservations et crée le tableau res.
void creer_res(t_res res, int *nr){
    gotoxy(1,nbr_lignes/2);
    textcolor(WHITE);
    printf("%49sEntrez le nombre de reservations(MAXIMUM 10 RESERVATIONS!): ","");
    textcolor(CYAN);scanf("%d",&(*nr));textcolor(WHITE);
    //Vérification du nombre de réservations:
    while((*nr)>10 || (*nr)<1){
        system("cls");
        gotoxy(1,nbr_lignes/2);
        printf("%59sATTENTION, nombre de reservations invalid!\n","");
        printf("%47sRe-entrez le nombre de reservations(MAXIMUM 10 RESERVATIONS!): ","");
        textcolor(CYAN);scanf("%d",&(*nr));textcolor(WHITE);
    };
    system("cls");
    //Lecture des réservations:
    for (int i=1; i<=(*nr); i++){
        gotoxy(1,(nbr_lignes/2)-1);
        textcolor(CYAN);printf("%68sReservation numero %d: \n","",i);textcolor(WHITE);
        //Lecture de la taille et les dates de début et fin:
        textcolor(WHITE);printf("%54sEntrez la taille de la paire de skis a louer: ","");textcolor(CYAN);
        scanf("%d",&(res[i].t));
        textcolor(WHITE);printf("%54sEntrez la periode de la reservation:\n","");
        printf("%56s> Debut: ","");textcolor(CYAN);
        scanf("%d",&(res[i].de));
        textcolor(WHITE);printf("%56s> Fin: ","");
        textcolor(CYAN);scanf("%d",&(res[i].fi));textcolor(WHITE);
        system("cls");
    };
}

//Procedure réservations: permet de réaliser si possible les réservations demandées et affiche les messages adéquats.
void reservations(ptr_paire plist, char nomloc[max_nom], int adr, t_skieur skieur, int *nsk){

    //Déclarations et initialisations:
    bool possible;
    t_res res;
    int nr;
    int Max_iter=Random(2,3);
    nomloc=strupr(nomloc);

    //Création du tableau res:
    creer_res(res,&nr);

    //Chargement:
    for (int j=0; j<Max_iter; j++){
        system("cls");
        gotoxy(1,nbr_lignes/2);
        printf("%70sAllocation en cours","");
        for(int i=0; i<3; i++){
            printf(".");
            delay(500);
        };
    };
    printf("cls");

    //Traitements des réservations:
    system("cls");
    gotoxy(1,(nbr_lignes/2)-(2*nr));
    for (int i=1; i<=nr; i++){
        textcolor(CYAN);printf("%70sReservation numero %d:\n","",i);textcolor(WHITE);
        reservation(plist,&possible,nomloc,adr,res[i].t,res[i].de,res[i].fi,skieur,&(*nsk));
        if (possible) printf("%49sReservation d'une paire de taille %d du %d au %d avec succes!\n\n","",res[i].t,res[i].de,res[i].fi);
        else printf("%49sEchec de la reservation d'une paire de taille %d du %d au %d!\n\n","",res[i].t,res[i].de,res[i].fi);
    };
}

///2. Parcours de liste: ///

/*a) Fonction nbskis: renvoie la longeur de la liste principale. */
int nbskis(ptr_paire plist){

    //Déclarations et initialisations:
    int cpt=0; //Le nombre d'elements(maillons).
    ptr_paire p; //Pointeur de parcours.
    p=plist;

    //Calcul du nombre de maillons:
    while(p!=NULL){
        cpt++;
        p=suivant_paire(p);
    };

    return cpt;
}

/*b) Fonction skit: retoure l’adresse du premier maillon contenant une paire de skis de taille t. */
ptr_paire skit(ptr_paire plist,int t){

    //Déclarations et initialisations:
    bool trouv=false; //On suppose que la taille 't' n'existe pas dans la liste.
    ptr_paire p; //Pointeur de parcours.
    ptr_paire q; //Maillon resultat.
    q=NULL;

    //La recherche:
    if (verifie_taille(t)){
        p=plist;
        while(p!=NULL && !trouv && valeur_taille(p)<=t){ //La troisième condition sert à éviter les itéations inutiles puisque la liste est triée.
            if(valeur_taille(p)==t){ //taille trouvée.
                trouv=true;
                q=p;
            }
            else p=suivant_paire(p);
        };
    };

    return q;
}

/*c) Fonction nbjloc: délivre le nombre de jours de location d’une paire de skis si elle existe dans la liste, 0 sinon. */
int nbjloc(ptr_paire plist,int t){

    //Déclarations et initialisations:
    bool trouv=false;
    int nbl=-1; //Le nombre de jours de location.
    ptr_paire p; //Pointeur de parcours de la liste principale.
    ptr_res sp; //Pointeur de parcours de la sous-liste.

    if (verifie_taille(t)){
        nbl=0;
        p=plist;
        while(p!=NULL && valeur_taille(p)<=t && !trouv){
            if (valeur_taille(p)==t){ //taille trouvée.
                trouv=true;
                sp=valeur_loc(p);
                while(sp!=NULL){
                    nbl+=(valeur_fin(sp)-valeur_deb(sp)+1); //calcul des jours de location.
                    sp=suivant_res(sp);
                };
            };
            p=suivant_paire(p);
        };
    };

    return nbl;
}

/*d) Fonction pg_reserv_nbj: renvoie la taille de la paire de skis la plus demandée(Selon le nombre des jours de locations). */
int pg_resrv_nbj(ptr_paire plist){

    //Déclarations et initialisations:
    ptr_paire p;
    ptr_res q;
    int pg=0;
    int pg_taille,nbjloc;
    p=plist;

    //Traitement:
    while(p!=NULL){
        q=valeur_loc(p);
        nbjloc=0;
        while(q!=NULL){
            nbjloc+=(valeur_fin(q)-valeur_deb(q)+1);
            q=suivant_res(q);
        }
        if(nbjloc>pg){
            pg=nbjloc;
            pg_taille=valeur_taille(p);
        }
        p=suivant_paire(p);
    };
    return pg_taille;
}

/*e) Fonction pg_reserv_loc: renvoie la taille de la paire de skis la plus demandée(Selon le nombre de locataires). */
int pg_resrv_loc(ptr_paire plist){

    //Déclarations et initialisations:
    ptr_paire p;
    ptr_res q;
    int pg=0;
    int pg_taille,calc;
    p=plist;

    //Traitement:
    while(p!=NULL){
        q=valeur_loc(p);
        calc=0;
        while(q!=NULL){
            calc++;
            q=suivant_res(q);
        }
        if(calc>pg){
            pg=calc;
            pg_taille=valeur_taille(p);
        }
        p=suivant_paire(p);
    };
    return pg_taille;
}

///3. Parcours de vecteurs: ///

/*a) Fonction cherchskieur: renvoie l'index du locataire nommé 'nomloc' s'il existe dans le vecteur skieur, -1 sinon. */
int cherchskieur(t_skieur skieur, int nsk, char nomloc[max_nom]){

    //Déclarations et initialisations:
    int i=1; //Indice courant(de parcours)
    int ind=(-1); //Indice du locataire initialisé à (-1) car on suppose que le locataire n'existe pas dans le vecteur
    nomloc=strupr(nomloc);

    //Parcours du vecteur et recherche:
    do{
        if (strcmp(skieur[i].nom,nomloc)==0) ind=i; //si la fonction strcmp(fonction standard qui compare les chaînes de caractères) retourne 0 ca veut dire aue le locataire est trouvé
        else i++;
    }while(i<=nsk && ind==(-1));

    return ind;
}

/*b) Procédure max_psk: renvoie l'indice et le psk du locataire ayant le plus grand psk. */
void max_psk(t_skieur skieur, int nsk, int *ind, int *psk){

    //Déclarations et initialisations:
    *ind=1;
    *psk=skieur[*ind].psk;

    //Parcours du vecteur et recherche:
    for(int j=2;j<=nsk;j++){
        if(skieur[j].psk>skieur[*ind].psk){
            *ind=j;
            *psk=skieur[*ind].psk;
        };
    };
}



///4. Suppression d'élements: ///

//Procédure annuleres: supprime toutes les réservations d'un locataire.
void annuleres(char nomloc[max_nom],t_skieur skieur,ptr_paire plist,int *nsk){

    //Déclarations et initialisations:
    ptr_paire p;
    nomloc=strupr(nomloc);
    ptr_res q,prec,sauv;
    int indice_loc=cherchskieur(skieur,*nsk,nomloc);

    //Traitement:
    if(indice_loc==(-1)){
        system("cls");
        gotoxy(1,nbr_lignes/2);
        printf("%58sDesole, cette personne n'est pas un client!\n","");
    }
    else{
        //Suppression du locataire du vecteur skieur(On le remplace par le dernier locataire dans le vecteur):
        strcpy(skieur[indice_loc].nom,skieur[*nsk].nom);
        strcpy(skieur[indice_loc].adresse,skieur[*nsk].adresse);
        skieur[indice_loc].psk=skieur[*nsk].psk;
        strcpy(skieur[*nsk].nom,"");
        strcpy(skieur[*nsk].adresse,"");
        skieur[*nsk].psk=0;
        p=plist;
        while(p!=NULL){
            q=valeur_loc(p);
            prec=NULL; //Le precedent (PREC).
           while(q!=NULL)
           {  if((valeur_ind(q)==(*nsk)) & (indice_loc!=(*nsk)) )
              { aff_ind(q,indice_loc);
                prec=q;
                q=suivant_res(q);
              }
            else
             if(valeur_ind(q)==(indice_loc))
               {
                 if(q==valeur_loc(p))
                  {  aff_loc(p,suivant_res(q));
                     sauv=q ;
                     q=suivant_res(q);
                     liberer_res(sauv);
                  }
               else
                if(suivant_res(q)==NULL)
                 { if(prec==NULL)
                    { aff_loc(p,NULL);
                      sauv=q ;
                      q=suivant_res(q);
                      liberer_res(sauv);
                    }
                    else
                    { aff_adr_res(prec,NULL);
                      sauv=q ;
                      q=suivant_res(q);
                      liberer_res(sauv);
                    }
                 }
                else //Si le maillon se trouve au milieu:
                 { aff_adr_res(prec,suivant_res(q));
                   sauv=q ;
                   q=suivant_res(q);
                   liberer_res(sauv);
                 }
             }
             else
              { prec=q;
                q=suivant_res(q);
              }
          }  //Fin du deuxieme WHILE.
           p=suivant_paire(p);

        } //Fin du premier WHILE.
        *nsk=(*nsk)-1;

        //Chargement:
        int Max_iter=Random(1,2);
        for (int j=0; j<Max_iter; j++){
            system("cls");
            gotoxy(1,nbr_lignes/2);
            printf("%70sSuppression en cours","");
            for(int i=0; i<3; i++){
                printf(".");
                delay(500);
            };
        };

        system("cls");
        gotoxy(1,nbr_lignes/2);
         printf("%65sSuppression faite avec succes!\n","");
    };//Fin du ELSE

}
