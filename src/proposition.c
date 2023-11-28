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

        p->next = (Proposition*) malloc(sizeof(Proposition));
        p->next->proposition;

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
