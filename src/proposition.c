#include "proposition.h"


// Ajoute une proposition à la prémisse d'une règle
Prop_List add_prop_in_tail_of_list(Prop_List list, Proposition prop) {
    
    //Allocation dynamique pour le nouvel élément de la liste de prémisse
    Prop_List_Element *new_prop = (Prop_List_Element*) malloc(sizeof(Prop_List_Element));
    if (new_prop ==  NULL) {
        fprintf(stderr, "Error : Prop_List_Element* allocation\n");
        return list;
    }
    new_prop->prop = (Proposition) malloc(sizeof(char)*(strlen(prop)+1));
    if (new_prop->prop == NULL) {
        fprintf(stderr, "Error : Proposition allocation\n");
        return list;
    }
    strcpy(new_prop->prop, prop);
    new_prop->next = NULL;
   
    if (list == NULL) {
        list = new_prop;
    }
    else {
        Prop_List_Element *p = list;
        
        while (p->next != NULL) {
            p = p->next;
        }

        p->next = new_prop;
    }

    return list;
}


int list_contain_prop(Prop_List list, Proposition prop) {
    if (list == NULL) {
        return 0;
    }
    else if (strcmp(list->prop, prop) == 0) {
        return 1;
    }
    else {

        return list_contain_prop((Prop_List){list->next}, prop);
    }
}

Prop_List remove_prop_of_list(Prop_List list, Proposition prop) {
    if (list == NULL) {
        return list; 
    }
    else {
        if (strcmp(list->prop, prop) == 0) {
            Prop_List_Element *tmp = list->next;
            free(list->prop);
            free(list);
            return tmp;
        }
        else {
            Prop_List_Element *p_elem = list;

            while (p_elem->next != NULL && strcmp(p_elem->next->prop, prop) != 0) {
                p_elem = p_elem->next;
            }
            
            if (p_elem->next != NULL) {
                Prop_List_Element *tmp = p_elem->next->next;
                free(p_elem->next->prop);
                free(p_elem->next);
                p_elem->next = tmp;
            }
            
            return list;
        }
    }
}


void free_prop_list(Prop_List list) {
    Prop_List_Element *p = list;
    Prop_List_Element *tmp;

    while (p != NULL) {
        tmp = p->next;
        free(p->prop);
        free(p);
        p = tmp;
    }

}


void print_proposition_list(Prop_List list) {
    if (list != NULL) {
        Prop_List_Element *p_prop = list;

        while (p_prop != NULL) {
            printf("%s", p_prop->prop);
            if (p_prop->next != NULL) {
                printf(", ");
            }
            p_prop = p_prop->next;
        }
        printf("\n");
    }
}