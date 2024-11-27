#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

// Définir la structure Tache
typedef struct {
    char titre[50], description[100], date_echeance[15], priorite[10];
} Tache;

// Déclarer un tableau de tâches et une variable pour le nombre de taches
Tache taches[MAX_TACHES];
int n = 0;

// Variable pour afficher le message de bienvenue une seule fois
int afficheBienvenue = 0;

// Fonction pour afficher le menu principal
void afficherMenu() {
    if (afficheBienvenue == 0) {
        printf("Bienvenue dans le programme de l'association ONEHAND!\n");
        afficheBienvenue = 1; // Marquer que le message a été affiché
    }

    // Affichage du menu
    printf("\n==== Menu de Gestion des Taches ====\n");
    printf("Choisir une option : \n");
    printf(" 1. Ajouter une tache\n");
    printf(" 2. Afficher toutes les taches\n");
    printf(" 3. Modifier une tache\n");
    printf(" 4. Supprimer une tache\n");
    printf(" 5. Filtrer une tache\n");
    printf(" 0. Quitter\n");
    printf("Votre choix : ");
}

// Fonction pour ajouter une tâche à la liste
void ajouter() {
    if (n >= MAX_TACHES) {
        printf("Impossible d'ajouter une nouvelle tache, liste pleine.\n");
        return;
    }
    
    printf("Titre: ");
    scanf(" %[^\n]", taches[n].titre);
    printf("Description: ");
    scanf(" %[^\n]", taches[n].description);
    printf("Date_echeance(DD/MM/AA): ");
    scanf(" %[^\n]", taches[n].date_echeance);
    printf("Priorite(Low/High): ");
    scanf(" %[^\n]", taches[n].priorite);

    n++; // Incrémenter le nombre de tâches
}

// Fonction pour afficher toutes les tâches
void afficher() {
    if (n == 0) {
        printf("Aucune tache a afficher.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\nTache %d:\n", i + 1);
        printf("Titre: %s\n", taches[i].titre);
        printf("Description: %s\n", taches[i].description);
        printf("Date_echeance: %s\n", taches[i].date_echeance);
        printf("Priorite: %s\n", taches[i].priorite);
        printf("\n***********************************\n");
    }
}

// Fonction pour modifier une tâche
void modifier() {
    int idx;
    printf("Entrez l'index de la tache a modifier (1-%d): ", n);
    scanf("%d", &idx);
    if (idx < 1 || idx > n) { // Vérifier si l'index est valide
        printf("Index invalide.\n");
        return;
    }
    
    // Demander les nouvelles informations
    printf("Nouvelle Titre: ");
    scanf(" %[^\n]", taches[idx - 1].titre);
    printf("Nouvelle Description: ");
    scanf(" %[^\n]", taches[idx - 1].description);
    printf("Nouvelle Date_echeance: ");
    scanf(" %[^\n]", taches[idx - 1].date_echeance);
    printf("Nouvelle Priorite: ");
    scanf(" %[^\n]", taches[idx - 1].priorite);

    printf("Tache modifiée avec succes !\n");
}

// Fonction pour supprimer une tâche de la liste
void supprimer() {
    int idx;
    printf("Entrez l'index de la tache a supprimer (1-%d): ", n);
    scanf("%d", &idx); // Demander à l'utilisateur l'index de la tâche à supprimer
    if (idx < 1 || idx > n) { // Vérifier si l'index est valide
        printf("Index invalide.\n");
        return;
    }
    // Décaler les tâches suivantes pour occuper la place
    for (int i = idx - 1; i < n - 1; i++) {
        taches[i] = taches[i + 1];
    }
    n--; // Réduire le nombre de tâches
    printf("Tache supprimee avec succes !\n");
}

// Fonction pour filtrer les tâches par priorité
void filtrer() {
    char filtre[10];
    printf("Entrez la priorite a filtrer : ");
    scanf(" %[^\n]", filtre);
    int trouve = 0;
    for (int i = 0; i < n; i++) {
        // Comparer la priorité de la tâche avec le filtre
        if (strcmp(taches[i].priorite, filtre) == 0) {
            // Afficher les tâches filtrées
            printf("\nTache %d: %s\n", i + 1, taches[i].titre);
            trouve = 1;
        }
    }
    // Si aucune tâche ne correspond à la priorité filtrée, afficher un message
    if (!trouve) {
        printf("Aucune tache trouvee.\n");
    }
}

// Fonction principale pour afficher le menu et exécuter les actions
int main() {
    int choix;
    do {
        afficherMenu();
        scanf("%d", &choix); // Lire le choix de l'utilisateur

        // Exécuter l'option choisie
        switch (choix) {
            case 1: ajouter(); break;
            case 2: afficher(); break;
            case 3: modifier(); break;
            case 4: supprimer(); break;
            case 5: filtrer(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide.\n"); break;
        }

        // Répéter jusqu'à ce que l'utilisateur choisisse de quitter
    } while (choix != 0);

    return 0;
}