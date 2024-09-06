#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mxbook 50

             typedef struct {
    char titre[50];
    char auteur[50];
    float prix;
    int quantite;
} livre;

livre stock[mxbook];
int lcompte = 0;

  void ajoutelivre() {
    
        printf("titre : ");
        scanf(" %d", &stock[lcompte].titre);
        printf("auteur : ");
        scanf(" %d", &stock[lcompte].auteur);
        printf("prix ");
        scanf("%f",&stock[lcompte].prix);
        printf("quantite: ");
        scanf("%d", &stock[lcompte].quantite);
           lcompte++;
    
    }
    void afiichlivre() {
    for (int i = 0; i < lcompte; i++) {
        printf("titre: %c, auteur: %c, prix: %.2f, quantité: %d\n", stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
    }
}
int recherchlivre() {
    char titre[50];
    printf("titre rechercher: ");
    scanf(" %d", &titre);
    for (int i = 0; i < lcompte; i++) {
    if (strcmp(stock[i].titre, titre) == 0) {
        printf("Livre trouve - Titre: %c, auteur: %c, arix: %.2f, auantité: %f\n", stock[i].titre, stock[i].auteur, stock[i].prix, stock[i].quantite);
        return i;
        }
    }
    printf("Livre non trouve.\n");
    return -1;
}
void modifiequantite() {
    char titre[50];
    int nouvquantite;
      printf("Titre du livre à mettre à jour: ");
      scanf("%d", &titre);
    for (int i = 0; i < lcompte; i++) {
        if (strcmp(stock[i].titre, titre) == 0) {
            printf("nouvelle quantite: ");
            scanf("%d", &nouvquantite);
            stock[i].quantite = nouvquantite;
            printf("quantite nouveau.\n");
    
        }
    }
    printf("Livre non trouve.\n");
}
void supremlivre() {
    char titre[50];
    printf("titre  supprimer: ");
    scanf(" %d", &titre);
    for (int i = 0; i < lcompte; i++) {
        if (strcmp(stock[i].titre, titre) == 0) {
            for (int j = i; j < lcompte - 1; j++) {
                stock[j] = stock[j + 1];
            }
            lcompte--;
            printf("Livre supprime.\n");
            return;
        }
    }
    printf("Livre non trouve.\n");
}
void totallivre() {
    int total = 0;
    for (int i = 0; i < lcompte; i++) {
        total += stock[i].quantite;
    }
    printf("Nombre total de livres en stock: %d\n", total);
}
int main() {
    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. ajouter un livre\n");
        printf("2. afficher tous les livres\n");
        printf("3. rechercher un livre\n");
        printf("4. mettre  jour la quantit d'un livre\n");
        printf("5. supprimer un livre\n");
        printf("6. afficher le nombre total de livres\n");
        printf("7. quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: ajoutelivre(); break;
            case 2: afiichlivre(); break;
            case 3: recherchlivre(); break;
            case 4: modifiequantite(); break;
            case 5: supremlivre(); break;
            case 6: totallivre(); break;

            default: printf("Choix invalide.\n");break;
            
        }
    } while (choix != 6);
    return 0;
}
  
  

