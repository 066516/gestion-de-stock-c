#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include"LibPileFileInt.c"
#include <time.h>
#include <string.h>


typedef struct Date
{
    int Day, Month, Year;
} Date;
typedef struct Article
{
    int bdw;
    int Ref;
    Date DatePer;
    float Prix;
    int Crit;
    int qte;
} Article;
typedef struct commande
{
    int qte;
    int id;
    char nomclient;
    int refarcmd;
    int refarart;
    float prixt;
    Date datecom;
} commande;
typedef struct achat_vente
{
    int ref;
    Date datecom;
    int ttc;
    float ht;
    //int id;
    int type; // if 0 achat else vente
} achat_vente;
typedef struct client_four
{
    int id;
    char nom, prenom;
    int tel;
    char adresse;
    int etat; // o client 1 fourniseur
} client_four;

// typedef struct EPilecl *Pilecl;
// typedef struct EPilecl
// {
//     achat_vente Val;
//     Pile Suiv;
// } CelluleP;
// d�claration de la File

typedef commande Telm;
typedef struct Element *EFile;
typedef struct Element
{
    Telm Val;
    EFile Suiv;
} CelluleF;
typedef struct File
{
    EFile Tete, Queue;
} File;
//// new type pile
typedef struct eleve{
    achat_vente vaac;
    File filecommende;
}eleve;
typedef struct EPilecl *Pilecl;
typedef struct EPilecl
{
     eleve Val;
     Pilecl Suiv;
 } CellulePav;
 /// finish
typedef struct ele
{
    client_four clfo;
    File filecommende;

} ele;
typedef struct EPile *Pile;
typedef struct EPile
{
    ele Val;
    Pile Suiv;
} CelluleP;
//new type struct
typedef Article Telmar;
typedef struct Elementar *EFilear;
typedef struct Elementar
{
    Telmar Val;
    EFilear Suiv;
} CelluleFar;
typedef struct
{
    EFilear Tete, Queue;
} Filear;
//finish new type struct
// primitives des Piles
// procedure Initpile
Pile Initpile()
{
    Pile P;
    P = NULL;
    return P;
}

// procedure Empiler
void Empiler(Pile *P, ele x)
{
    Pile V;
    V = malloc(sizeof(CelluleP));
    V->Val = x;
    V->Suiv = *P;
    *P = V;
}

// procedure Depiler
void Depiler(Pile *P, ele *x)
{
    Pile V;
    *x = (*P)->Val;
    V = *P;
    *P = (*P)->Suiv;
    free(V);
}

// Fonction Pilevide
int Pilevide(Pile P)
{
    if (P == NULL)
        return 1;
    else
        return 0;
}

// Fonction SommetPile
ele SommetPile(Pile P)
{
    return P->Val;
}
/////// new fuction new type
Pilecl Initpilecl()
{
    Pilecl P;
    P = NULL;
    return P;
}

// procedure Empiler
void Empilercl(Pilecl *P, eleve x)
{
    Pilecl V;
    V = malloc(sizeof(CellulePav));
    V->Val = x;
    V->Suiv = *P;
    *P = V;
}

// procedure Depiler
void Depilercl(Pilecl *P, eleve *x)
{
    Pilecl V;
    *x = (*P)->Val;
    V = *P;
    *P = (*P)->Suiv;
    free(V);
}

// Fonction Pilevide
int Pilevidecl(Pilecl P)
{
    if (P == NULL)
        return 1;
    else
        return 0;
}

// Fonction SommetPile
eleve SommetPilecl(Pilecl P)
{
    return P->Val;
}
///finish
////primitives des Files
// procedure Initfile
// void Initfile(File *F)
//{(*F).Tete=NULL; (*F).Queue=NULL;}

File Initfile()
{
    File F;
    F.Tete = NULL;
    F.Queue = NULL;
    return F;
}

// procedure Enfiler
void Enfiler(File *F, Telm x)
{
    EFile V;
    V = malloc(sizeof(CelluleF));
    V->Val = x;
    V->Suiv = NULL;
    if ((*F).Tete == NULL)
        (*F).Tete = V; // la file est vide
    else
        (*F).Queue->Suiv = V;
    (*F).Queue = V;
}

// procedure Defiler
void Defiler(File *F, Telm *x)
{
    EFile V;
    V = (*F).Tete;
    *x = V->Val; // ou  *x=(*F).Tete->Val;
    if ((*F).Tete == (*F).Queue)
    {
        (*F).Tete = NULL;
        (*F).Queue = NULL;
    }
    else
        (*F).Tete = (*F).Tete->Suiv; // ou  (*F).Tete=V->Suiv;
    free(V);
}

// Fonction Filevide
int Filevide(File F)
{
    if (F.Tete == NULL)
        return 1;
    else
        return 0;
}

// Fonction Tetefile
Telm Tetefile(File F)
{
    return F.Tete->Val;
}
//new function

////primitives des Files
// procedure Initfile
// void Initfile(File *F)
//{(*F).Tete=NULL; (*F).Queue=NULL;}

void Initfilear(Filear *F)
{
    (*F).Tete = NULL;
    (*F).Queue = NULL;
}

// procedure Enfiler
void Enfilerar(Filear *F, Telmar x)
{
    EFilear V;
    V = malloc(sizeof(CelluleFar));
    V->Val = x;
    V->Suiv = NULL;
    if ((*F).Tete == NULL)
        (*F).Tete = V; // la file est vide
    else
        (*F).Queue->Suiv = V;
    (*F).Queue = V;
}

// procedure Defiler
void Defilerar(Filear *F, Telmar *x)
{
    EFilear V;
    V = (*F).Tete;
    *x = V->Val; // ou  *x=(*F).Tete->Val;
    if ((*F).Tete == (*F).Queue)
    {
        (*F).Tete = NULL;
        (*F).Queue = NULL;
    }
    else
        (*F).Tete = (*F).Tete->Suiv; // ou  (*F).Tete=V->Suiv;
    free(V);
}

// Fonction Filevide
int Filevidear(Filear F)
{
    if (F.Tete == NULL)
        return 1;
    else
        return 0;
}

// Fonction Tetefile
Telmar Tetefilear(Filear F)
{
    return F.Tete->Val;
}

// finish new function
Article creerArticle()
{
    Article NewArticle;
    char C;

    printf("Donner la reference de l article : ");
    scanf("%d", &NewArticle.Ref);
    printf("Donner le prix : \n ");
    scanf("%f", &NewArticle.Prix);
    printf("Donner la date de peremption (DD MM YY) : \n ");
    scanf("%d%d%d", &NewArticle.DatePer.Day, &NewArticle.DatePer.Month, &NewArticle.DatePer.Year);
    printf("Est ce que l'article est critique (Y/N): ");
    scanf("%s", &C);

    if (toupper(C) == 'Y')
    {
        NewArticle.Crit = 1;
    }
    else
    {
        NewArticle.Crit = 0;
    }
    return NewArticle;
}

void rechercheparref(Filear f, int r)
{
    Article x;
    Filear p;
    Initfilear(&p);
    int i;
    i = 0;

    while (Filevidear(f) != 1)
    {
        Defilerar(&f, &x);
        Enfilerar(&p, x);
        if (x.Ref == r)
        {
            printf("ce aricle existe \n ");
            printf("son reference %d \n ", x.Ref);
            printf("son prix %f \n ", x.Prix);
            printf("sa date de peremption est le %d/%d/%d \n", x.DatePer.Day, x.DatePer.Month, x.DatePer.Year);
            if (x.Crit == 1)
            {
                printf("c est un consomable critique \n");
            }
            else
            {
                printf("ce n est pas un consomable critique\n ");
            }

            i = 1;
        }
    }
    if (i == 0)
    {
        printf("ce article n existe pas\n");
    }

    f = p;
}
void recherchepardateper(Filear f, Date d)
{
    Article y, x;
    Filear r;
    int i; // si i= 0 alors l'element n'existe pas
    Initfilear(&r);
    i = 0;
    while (Filevidear(f) != 1)
    {
        Defilerar(&f, &x);
        Enfilerar(&r, x);
        if (x.DatePer.Day == d.Day && x.DatePer.Month == d.Month && x.DatePer.Year == d.Year)
            ;
        y = x;
        i = 1;
    }
    f = r;
    if (i == 0)
    {
        printf(" ce article n existe pas \n ");
    }
    else
    {
        printf("ce aricle existe \n ");
        printf("son reference %d \n ", y.Ref);
        printf("son prix %f \n ", y.Prix);
        printf("sa date de peremption est le %d/%d/%d \n ", y.DatePer.Day, y.DatePer.Month, y.DatePer.Year);
        if (y.Crit == 1)
        {
            printf("c est un consomable critique \n ");
        }
        else
        {
            printf("ce n est pas un consomable critique \n ");
        }
    }
}

void affichageglobale(Filear *f)
{
    Article x;
    Filear r;
    Initfilear(&r);

    while (Filevidear(*f) == 0)
    {
        Defilerar(&(*f), &x);
        printf("reference de produit : %d \n ", x.Ref);
        printf("prix de produit : %.2f \n ", x.Prix);
        printf(" sa date de peremptio est le : %d / %d / %d \n ", x.DatePer.Day, x.DatePer.Month, x.DatePer.Year);
        if (x.Crit == 1)
        {
            printf("c est un consomable critique \n ");
        }
        else
        {
            printf("ce n est pas un consomable critique \n ");
        }
        Enfilerar(&r, x);
    }
    *f = r;
}
void ajout(Filear *f, Article x)
{
    Enfilerar(&(*f), x);
}

void modifier(Filear *f, int rn)
{
    Article x;
    int a, nr;
    float np;
    Date nd;
    Filear p;
    Initfilear(&p);
    while (Filevidear(*f) != 1)
    {
        Defilerar(&(*f), &x);

        if (x.Ref == rn)
        {
            printf("que ce que vous voulez modifier 1.reference 2.prix 3.date peremption  ");
            scanf("%d", &a);
            switch (a)
            {

            case 1:
            {
                printf("donnez la nouvelle reference ");
                scanf("%d", &nr);
                x.Ref = nr;
                break;
            }
            case 2:
            {
                printf("donnez le nouveau prix ");
                scanf("%f", &np);
                x.Prix = np;
                break;
            }
            case 3:
            {
                printf("donnez la nouvelle date  ");
                scanf("%d%d%d", &nd.Day, &nd.Month, &nd.Year);
                x.DatePer = nd;
                break;
            }
            default:
                printf("vous devez choisir un nbr entre 1-3\n");
            }
        }
        Enfilerar(&p, x);
    }
    *f = p;
}
void supprimer(Filear *f)
{
    int r;
    Article x, y;
    Filear p;

    printf(" donnez la reference de l element que vous voulez supprimer ");
    scanf("%d", &r);
    Initfilear(&p);
    // y=Tetefile(*f);   /// FIX THAT ACCORDING TO THE ALOGORITHM LOGIC !!
    while (!Filevidear(*f) && Tetefilear(*f).Ref != r)
    {

        Defilerar(&(*f), &x);
        Enfilerar(&p, x);
    }
    if (!Filevidear(*f))
    {
        Defilerar(&(*f), &x);
    }
    while (!Filevidear(*f))
    {
        Defilerar(&(*f), &x);
        Enfilerar(&p, x);
    }

    *f = p;
}

Date date()
{
    Date d;

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    d.Day = tm.tm_mday;
    d.Month = tm.tm_mon + 1;
    d.Year = tm.tm_year + 1900;
    return d;
}

void affichagePExpirer(Filear f)
{
    Article x;
    int expr;
    Date datt = date();

    while (Filevidear(f) != 1)
    {
        Defilerar(&f, &x);
        expr = 0;
        if (x.DatePer.Year < datt.Year)
            expr = 1;
        else if (x.DatePer.Year == datt.Year)
        {
            if (x.DatePer.Month < datt.Month)
                expr = 1;
            else if (x.DatePer.Month == datt.Month)

            {
                if (x.DatePer.Day <= datt.Day)
                    expr = 1;
            }
        }
        if (expr == 1)
        {
            printf("reference de produit : %d \n ", x.Ref);
            printf("prix de produit : %.2f \n ", x.Prix);
            printf(" sa date de peremptio est le : %d / %d / %d \n ", x.DatePer.Day, x.DatePer.Month, x.DatePer.Year);
            if (x.Crit == 1)
            {
                printf("c est un consomable critique \n ");
            }
            else
            {
                printf("ce n est pas un consomable critique \n ");
            }
        }
    }
}
void creecommande(Pile *p,Pilecl*pv,Filear f)
{
    Pile intr = Initpile();
    Pilecl intrv=Initpilecl();
    Telm newcommande;
    int refarcart, i = 0,j=1,k=1,yes;
    ele elem;
    eleve elev;
    // File f;
     Filear r; // une file d article
    Article x;
    float y;
    printf("donnez la reference de l article que vous souhaitez commandez\n ");
    scanf("%d", &refarcart);
    newcommande.refarart = refarcart;

     Initfilear(&r);

     while (Filevidear(f) != 1 && Tetefilear(f).Ref != refarcart)
     {
         Defilerar(&f, &x);
         Enfilerar(&r, x);

    }

    if ( Filevidear(f) != 1 && Tetefilear(f).Ref == refarcart)
    {

        i = 1;
       printf("l article est disponible \n");
       y = Tetefilear(f).Prix;
       newcommande.refarart = Tetefilear(f).Ref;

     while (Filevidear(r) != 1)
       {
           Defilerar(&r, &x);
           Enfilerar(&f, x);


      }


      }
       else
     {
         i = 0;
          printf("l article n est pas disponible \n ");
        while (Filevidear(r) != 1)
          {
             Defilerar(&r, &x);
             Enfilerar(&f, x);
         }
    }

    if (i == 1)
     {

           printf("donnez la quantite que vous voulez commandez \n");
           scanf("%d", &newcommande.qte);
           newcommande.prixt = newcommande.qte * y;
           printf("le prix total de votre commande est \n");
           scanf("%f",&newcommande.prixt);
           printf("donnez la date de commande  JJ/MM/AA \n");
           scanf("%d%d%d", &newcommande.datecom.Day, &newcommande.datecom.Month, &newcommande.datecom.Year);

          printf("donnez le ID de client\n ");
          scanf("%d", &newcommande.id);

     while (Pilevide(*p) == 0&& j==1)
    {
    Depiler(&(*p), &elem);

    if (elem.clfo.id == newcommande.id)
    {
        j = 0;
        Enfiler(&elem.filecommende, newcommande);
    }
    Empiler(&intr, elem);
    }
    if (j == 1)
    {
        printf(" le client pas existe \n");
        printf(" are you ajoute client yes 1 / no 0 \n");
        scanf("%d",&yes);
        if(yes==1){
            creeclient(p,newcommande.id);
            Depiler(&(*p), &elem);
            Enfiler(&elem.filecommende, newcommande);
            Empiler(&intr, elem);

            }
        else
            printf(" le commende annule \n");

    }


    while (Pilevide(intr) != 1)
    {
        Depiler(&intr, &elem);
        Empiler(&(*p), elem);
    }
    ////new
     while (Pilevidecl(*pv) == 0&& k==1)
    {
    Depilercl(&(*pv), &elev);

    if (elev.vaac.ref == newcommande.refarart)
    {
        j = 0;
        elev.vaac.ttc=elev.vaac.ttc+newcommande.qte;
        elev.vaac.ht=elev.vaac.ht+newcommande.qte*newcommande.prixt ;
        Enfiler(&elev.filecommende, newcommande);
    }
    Empilercl(&intrv, elev);
    }
    if (j == 1)
    {
        printf(" la vente pas existe \n");
        printf(" are you ajoute vente yes 1 / no 0 \n");
        scanf("%d",&yes);
        if(yes==1){
            creevente(pv,newcommande);
            Depilercl(&(*pv), &elev);
            Enfiler(&elev.filecommende, newcommande);
            Empilercl(&intrv, elev);

            }
        else
            printf(" le commende annule \n");

    }


    while (Pilevidecl(intrv) != 1)
    {
        Depilercl(&intrv, &elev);
        Empilercl(&(*pv), elev);
    }

}}



void modifiercommande(File *F, int refasupp)
{
    commande y;
    int b, nq, np;
    Date d;
    char nnom;
    File t;

    Initfile(&t);
    while (!Filevide(*F))
    {
        Defiler(&(*F), &y);
        if (y.refarcmd == refasupp)
        {
            printf(" que ce que vous voulez changer 1. quantite 2.prix 3.date de commande 4.nom client \n");
            scanf("%d", &b);
            if (b == 1)
            {
                printf(" donnez la nouvelle quantite \n");
                scanf("%d", &nq);
                y.qte = nq;
            }
            if (b == 2)
            {
                printf(" donnez le nouveau prix \n");
                scanf("%d", &np);
                y.prixt = np;
            }
            if (b == 3)
            {
                printf("donnez la nouvelle datte JJ/MM/AA\n");
                scanf("%d%d%d", &d.Day, &d.Month, &d.Year);
                y.datecom = d;
            }
            if (b == 4)
            {
                printf(" donnez le nouveau nom \n");
                scanf("%s", nnom);
                y.nomclient = nnom;
            }
            Enfiler(&t, y);
        }
        else
        {
            Enfiler(&t, y);
        }
    }
    *F = t;
}




void supprimercommande(File *F)
{
    File t;
    commande y;
    int r;
    printf(" donnez la reference de l element que vous voulez supprimer \n");
    scanf("%d", &r);
    Initfile(&t);
    y = Tetefile(*F);
    while (!Filevide(*F) && y.refarcmd != r)
    {
        Defiler(&(*F), &y);
        Enfiler(&t, y);
    }
    if (!Filevide(*F))
    {
        Defiler(&(*F), &y);
    }
    while (!Filevide(*F))
    {
        Defiler(&(*F), &y);
        Enfiler(&t, y);
    }

    *F = t;
    }




void affichageglobalcommande(File *F)
{
    commande y;
    File t;
    t=Initfile();
    printf(" affichage new lise commende \n");
    while (Filevide(*F) == 0)
    {
        Defiler(&(*F),&y);
        printf("la reference de commande est %d \n ", y.refarcmd);
        printf("le prix  de commande est %f \n", y.prixt);
        printf("la  quantite de commande est %d \n", y.qte);
        printf("le id de client  de commande est %d \n", y.id);
        printf("la date de commande  de commande est %d %d %d  \n", y.datecom.Day, y.datecom.Month, y.datecom.Year);
        printf("\n\n");
        Enfiler(&t, y);
    }
    if(Filevide(t)==0)
    *F = t;
}
void affichagecommandedonnee(File *F)
{
    commande y;
    File t;
    int refaff;
    t=Initfile(t);
    printf("donnez la reference de commande a affiche \n");
    scanf("%d", &refaff);
    while (Filevide(*F)==0)
    {
        Defiler(&(*F), &y);
        if (y.refarcmd == refaff)
        {
            printf("la reference de commande est %d \n", y.refarcmd);
            printf("le prix  de commande est %f\n ", y.prixt);
            printf("la  quantite de commande est  %d \n", y.qte);
            printf("le nom de client  de  commande est %d \n", y.nomclient);
            printf("la date de commande   est %d %d %d \n ", y.datecom.Day, y.datecom.Month, y.datecom.Year);
            Enfiler(&t, y);
        }
        else
        {
            Enfiler(&t, y);
        }
    }
    *F = t;
}
void creeclient(Pile *p,int id)
{
    ele x;
    //printf("donne id\n");
   // scanf("%d", &x.clfo.id);
    x.clfo.id=id;
    printf("asq client 0 ou fourneseur 1\n");
    scanf("%d", &x.clfo.etat);
    printf("donne adresse\n");
    scanf("%s", &x.clfo.adresse);
    printf("donne etat\n");
    scanf("%d", &x.clfo.etat);
    printf("donne nom\n");
    scanf("%s", &x.clfo.nom);
    printf("donne telephone\n");
    scanf("%d", &x.clfo.tel);
    x.filecommende = Initfile();
    Empiler(p, x);
}
void creevente(Pilecl *p,commande cmd)
{
    eleve x;
    //printf("donne id\n");
   // scanf("%d", &x.clfo.id);
    x.vaac.ref=cmd.refarart;
    printf("asq vente 0 ou achat 1\n");
    scanf("%d", &x.vaac.type);

    x.vaac.ttc=cmd.qte;
    x.vaac.ht=cmd.qte*cmd.prixt;
    x.filecommende = Initfile();
    Empilercl(p, x);
}
int nbrcmdcl(File F)
{
    int s=0;
    commande y;
    File t;
    t=Initfile();
    while (Filevide(F) == 0)
    {
        Defiler(&F,&y);
        Enfiler(&t, y);
        s++;
    }

    F = t;
    return s;
}
void artplusvent(Pilecl p){
    eleve x,y;
    y.vaac.ttc=0;

    Pilecl ptr=Initpilecl();
    while(Pilevidecl(p)){
            Depilercl(&p,&x);
        if(x.vaac.ttc>y.vaac.ttc)
            y=x;
        Empilercl(&ptr,x);
    }
    p=ptr;
     printf(" refrence de article plus vendu %d\n",y.vaac.ref);


}
//new



int main(int argc, char const *argv[])
{
    Pile plcl = Initpile();
    Pile plcl2 = Initpile();
    Pilecl plv = Initpilecl();
    Pilecl plv2 = Initpilecl();
    File f;
    Filear fart;
    int choise, bl;
    eleve x;
    ele y;
    f = Initfile();
     Initfilear(&fart);
     Article art= creerArticle();
     Enfilerar(&fart,art);


    /*// printf(" are you want ajoute client no 0 / yes 1");
    // scanf("%d", &bl);*/
    // creeclient(&plcl);

    printf(" 1_cree new commende\n2_modifier le commende\n3_supprem le commende\n4_afficher globam commende\n");
    scanf("%d", &choise);
    while (choise != 0)
    {
        switch (choise)
        {

        case 1:

            creecommande(&plcl,&plv,fart);




            //Empiler(&plcl, y);
            // printf("*** %d", f.Tete->Val.id);
            // Telm x;
            // Defiler(&f, &x);
            // printf(" ** %d", x.id);
            while(Pilevide(plcl)==0){
                  Depiler(&plcl,&y);
                  f = y.filecommende;
                  affichageglobalcommande(&f);
                  Empiler(&plcl2,y);
             }
             while(Pilevide(plcl2)==0){
                 Depiler(&plcl2,&y);
                 Empiler(&plcl,y);
             }
                printf(" nombre cmd cette  client %d \n",nbrcmdcl(f));
            break;

        case 2:
              y = SommetPile(plcl);
             f = y.filecommende;
              affichagecommandedonnee(&f);
            break;
        case 3:
            creecommande(&plcl,&plv,fart);
            while(Pilevidecl(plv)==0){
                  Depilercl(&plv,&x);
                  f = x.filecommende;
                  affichageglobalcommande(&f);
                  Empilercl(&plv2,x);
             }
             while(Pilevidecl(plv2)==0){
                 Depilercl(&plv2,&x);
                 Empilercl(&plv,x);
             }
            break;
        case 4:

            break;
        }
        scanf("%d", &choise);
    }
    return 0;
}
