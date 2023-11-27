#include "engine.h"


Proposition *engine(Proposition *l_facts, Base *base) {
    if (base != NULL && base->head != NULL && l_facts != NULL) {
        Rule *p_rule;
        Proposition *l_new_facts;
        Proposition *p_fact;
        
        while (p_rule != NULL && l_facts != NULL) {
            if (p_rule->premise == NULL) {
                if (!list_contain_prop(l_new_facts, p_rule->conclusion)) {
                    l_new_facts = add_prop_in_tail_of_list(l_new_facts, p_rule->conclusion);
                }
            }
            if (contain_prop(*p_rule, p_fact->proposition)) {
                p_rule = remove_prop_of_rule(p_rule, p_fact->proposition);
                l_facts = remove_prop_of_list(l_facts, p_fact->proposition);
                if (p_rule->premise == NULL) {
                    l_new_facts = add_prop_in_tail_of_list(l_new_facts, p_rule->conclusion);
                }
            }
            p_rule = p_rule->next;
        }        

        return l_new_facts;
    }
    else {
        return NULL;
    }
}


Base *new_read_base_file(char filename[]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        return NULL;
    }

    Base *base = create_base();

    char ligne[100];
    char c;
    int i = 0;

    do {
        c = fgetc(file);

        if (c == '\n' || c == EOF) {
            if (i != 0) {
                ligne[i] = '\0';
                base = add_rule_in_tail_string(base, ligne);
                i = 0;
            }
        }
        else if (c != ' ') {
            ligne[i] = c;
            i++;
        }
    } while (c != EOF);

    return base;
}


int is_valid_string_rule(char rule[]) {

    if (rule == NULL) {
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
        else {
            buffer++;
        }
        i++;
    }

    if (buffer >= PROPOSISTION_BUFFER-1) {
        return 0;
    }

    if (rule[i-1] == ';') {
        return 0;
    }

    return 1;
}


Base *add_rule_in_tail_string(Base *base, char rule[]) {
    if (is_valid_string_rule(rule)) {
        Rule *new_rule = create_rule();
        if (new_rule == NULL) {
            return base;
        }

        int i = 0;
        int j = 0;
        char prop[100];

        while (rule[i] != '\0') {
            if (rule[i] == ';') { // fin d'une proposition
                prop[j] = '\0';
                j = 0;
                add_prop_in_tail_of_rule(new_rule, prop);
            }
            else {
                prop[j] = rule[i];
                j++;
            }
            i++;
        } 

        prop[j] = '\0';
        strcpy(new_rule->conclusion, prop); // ajout de la derniere proposition en conclusion

        base = add_rule_in_tail(base, new_rule);
    }
    

    return base;
}
