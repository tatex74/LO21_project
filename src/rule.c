#include "rule.h"

// Crée une nouvelle règle vide
Rule create_rule() {
    Rule new_rule;
    new_rule.premise = NULL;
    new_rule.conclusion = NULL;

    return new_rule;
}

Rule add_prop_in_tail_of_rule(Rule rule, Proposition prop) {
    
    // Allocation dynamique pour le nouvel élément de la liste de prémisse
    Prop_List_Element *new_prop = (Prop_List_Element*) malloc(sizeof(Prop_List_Element));
    if (new_prop ==  NULL) {
        fprintf(stderr, "Error : Prop_List_Element* allocation\n");
        return rule;
    }
    new_prop->prop = (Proposition) malloc(sizeof(char)*(strlen(prop)+1));
    if (new_prop->prop == NULL) {
        fprintf(stderr, "Error : Proposition allocation\n");
        return rule;
    }
    strcpy(new_prop->prop, prop);
    new_prop->next = NULL;

    if (rule.premise == NULL) {
        rule.premise = new_prop;
    } 
    else {
        Prop_List_Element *p_elem = rule.premise;
        while (p_elem->next != NULL) {
            p_elem = p_elem->next;
        }
        p_elem->next = new_prop;
    }

    return rule;
}



Rule create_rule_conclusion(Rule rule, Proposition conclusion) {
    if (rule.conclusion != NULL) {
        fprintf(stderr, "Error : Cannot create rule conclusion, conclusion not NULL\n");
        return rule;
    }

    rule.conclusion = (Proposition) malloc(sizeof(char)*(strlen(conclusion)+1));
    if (rule.conclusion == NULL) {
        fprintf(stderr, "Error : Proposition allocation\n");
        return rule;
    }
    strcpy(rule.conclusion, conclusion);

    return rule;
}


// Vérifie si une proposition est dans la prémisse d'une règle (récursivement)
int rule_contain_prop(Rule rule, Proposition prop) {
    if (rule.premise == NULL) {
        return 0; // Si la prémisse est vide, la proposition n'est pas présente
    }
    else if (strcmp(rule.premise->prop, prop) == 0) {
        return 1; // Si la proposition est trouvée, retourne 1 (vrai)
    }
    else {
        return rule_contain_prop((Rule){rule.premise->next, rule.conclusion}, prop); // Recherche récursive dans le reste de la prémisse
    }
}


// Supprime une proposition de la prémisse d'une règle
Rule remove_prop_of_rule(Rule rule, Proposition prop) {
    if (rule.premise == NULL) {
        return rule; // Si la prémisse est vide, rien à faire
    }
    else {
        Prop_List_Element *tmp;
        if (strcmp(rule.premise->prop, prop) == 0) {
            tmp = rule.premise->next;
            free(rule.premise->prop);
            free(rule.premise);
            rule.premise = tmp; // Supprime la première proposition si c'est celle recherchée
        }
        else {
            Prop_List_Element *p_elem = rule.premise;

            while (p_elem->next != NULL && strcmp(p_elem->next->prop, prop) != 0) {
                p_elem = p_elem->next;
            }
            
            if (p_elem->next != NULL) {
                tmp = p_elem->next->next;
                free(p_elem->next->prop);
                free(p_elem->next);
                p_elem->next = tmp; // Supprime une proposition dans le milieu ou à la fin de la prémisse
            }
        }
        return rule;
    }
}


int is_empty_premise(Rule rule) {
    if (rule.premise == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}


Proposition accessing_head_proposition_of_rule(Rule rule) {
    if (rule.premise != NULL) {
        return rule.premise->prop;
    }
    else {
        return NULL;
    }
}

Proposition accessing_conclusion_of_rule(Rule rule) {
    return rule.conclusion;
}


Rule create_rule_from_string(char *string_rule) {
    Rule new_rule = create_rule();

    if (!is_valid_string_rule(string_rule)) {
        return new_rule;
    }
    
    int i = 0;
    int j = 0;
    char prop[PROPOSISTION_BUFFER];

    while (string_rule[i] != '\0') {
        if (string_rule[i] == ';') { // fin d'une proposition
            prop[j] = '\0';
            j = 0;
            new_rule = add_prop_in_tail_of_rule(new_rule, prop);
        }
        else {
            prop[j] = string_rule[i];
            j++;
        }
        i++;
    } 

    prop[j] = '\0';
    new_rule = create_rule_conclusion(new_rule, prop); // ajout de la derniere proposition en conclusion

    return new_rule;
}

// verifie qu'un regle ecrite sous forme de chaine de cractere est valide
// une regle est valide si elle appartient a la grammaire : ([a-z]^n;)^n[a-z]
int is_valid_string_rule(char rule[]) {

    if (rule == NULL) {
        return 0;
    }

    if (strlen(rule) == 0) {
        return 0;
    }

    if (rule[0] == ';' || rule[0] == '\0') {
        return 0;
    }

    int i = 0;
    int buffer = 0;

    while (rule[i] != '\0' && buffer < PROPOSISTION_BUFFER-1) {
        if (rule[i] == ';') {
            if (rule[i+1] == ';') {
                return 0;
            }
            buffer = 0;
        }
        else if (!isalpha(rule[i]) && !isalnum(rule[i])) {
            return 0;
        }
        else {
            buffer++;
        }
        i++;
    }

    if (buffer >= PROPOSISTION_BUFFER-1) {
        return 0;
    }

    if (i != 0 && rule[i-1] == ';') {
        return 0;
    }

    return 1;
}



// Supprime une règle, y compris sa prémisse, de la mémoire
void free_rule_list_element(Rule_List_Element *rule_elem) {
    if (rule_elem != NULL) { // Vérifie si la règle n'est pas NULL
        if (rule_elem->rule.premise != NULL) { // Vérifie si la prémisse de la règle n'est pas NULL
            Prop_List_Element *p = rule_elem->rule.premise;
            Prop_List_Element *tmp;
            while (p != NULL) {
                tmp = p->next;
                free(p->prop); // Libère la mémoire de chaque proposition dans la prémisse
                free(p);
                p = tmp;
            }
        }
        free(rule_elem); // Libère la mémoire de la règle elle-même
    }
}


