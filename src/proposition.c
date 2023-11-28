#include "proposition.h"

Proposition *create_prop() {
    Proposition *new_prop = (Proposition*) malloc(sizeof(Proposition));
    new_prop->next = NULL;
    strcpy(new_prop->proposition, "");

    return new_prop;
}


Proposition *add_prop_in_tail_of_list(Proposition *list, char prop_string[]) {
    Proposition *new_prop = (Proposition*) malloc(sizeof(Proposition));
    new_prop->next = NULL;
    strcpy(new_prop->proposition, prop_string);

    if (list == NULL) {
        return new_prop;
    }
    else {
        Proposition *p = list;
        
        while (p->next != NULL) {
            p = p->next;
        }

        p->next = new_prop;

        return list;
    }
}



int list_contain_prop(Proposition *list, char prop[]) {
    if (list == NULL) {
        return 0;
    }
    else if (strcmp(list->proposition, prop) == 0) {
        return 1;
    }
    else {
        list = list->next;
        return list_contain_prop(list, prop);
    }
}



Proposition *remove_prop_of_list(Proposition *list, char prop[]) {
    if (list == NULL) {
        return list; 
    }
    else {
        if (strcmp(list->proposition, prop) == 0) {
            Proposition *tmp = list->next;
            free(list);
            list = tmp;
        }
        else {
            Proposition *p = list;

            while (p->next != NULL && strcmp(p->next->proposition, prop) != 0) {
                p = p->next;
            }
            
            if (p->next != NULL) {
                Proposition *tmp = p->next->next;
                free(p->next);
                p->next = tmp; // Supprime une proposition dans le milieu ou à la fin de la prémisse
            }
        }
        return list;
    }
}


void print_proposition_list(Proposition *l_prop) {
    if (l_prop != NULL) {
        Proposition *p_prop = l_prop;

        while (p_prop != NULL) {
            printf("%s", p_prop->proposition);
            if (p_prop->next != NULL) {
                printf(", ");
            }
            p_prop = p_prop->next;
        }

        printf("\n");
        
    }
}