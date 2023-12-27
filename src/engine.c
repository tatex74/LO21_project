#include "engine.h"

Prop_List engine(Prop_List l_facts, Base base) {
    if (base != NULL && l_facts == NULL) {
        fprintf(stderr, "Error : base or l_facts NULL\n");
        return NULL;
    }

    Rule_List_Element *p_rule_elem = base;
    Prop_List l_new_facts = NULL;
    Prop_List_Element *p_fact_elem = l_facts;
    
    while (p_fact_elem != NULL) {
        p_rule_elem = base;
        while (p_rule_elem != NULL) {
            if (rule_contain_prop(p_rule_elem->rule, p_fact_elem->prop)) {
                p_rule_elem->rule = remove_prop_of_rule(p_rule_elem->rule, p_fact_elem->prop);
                if (p_rule_elem->rule.premise == NULL) {
                    l_new_facts = add_prop_in_tail_of_list(l_new_facts, p_rule_elem->rule.conclusion);
                    l_facts = add_prop_in_tail_of_list(l_facts, p_rule_elem->rule.conclusion);
                }
            }
            p_rule_elem = p_rule_elem->next;
        }      
        p_fact_elem = p_fact_elem->next;
    }

    return l_new_facts;

}


Base read_base_file(char filename[]) {
    FILE *base_file = fopen(filename, "r");

    if (base_file == NULL) {
        fprintf(stderr, "Enable to read base file\n");
        return NULL;
    }

    Base base = NULL;
    Rule rule = create_rule();

    char ligne[100];
    char c;
    int i = 0;

    do {
        c = fgetc(base_file);

        if (c == '\n' || c == EOF) {
            if (i != 0) {
                ligne[i] = '\0';
                rule = create_rule_from_string(ligne);
                if (rule.premise != NULL && rule.conclusion != NULL) {
                    base = add_rule_in_tail(base, rule);
                }
                i = 0;
            }
        }
        else if (c == ' ') {
            fprintf(stderr, "invalid rule in %s", filename);
            while (c != '\n' && c != EOF) {
                c = fgetc(base_file);
            }
            i = 0;
        }
        else {
            ligne[i] = c;
            i++;
        }
    } while (c != EOF);

    fclose(base_file);

    return base;
}


Prop_List read_facts_file(char filename[]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        fprintf(stderr, "Enable to read facts\n");
        return NULL;
    }

    Prop_List facts = NULL;

    char fact[100];
    char c;
    int i = 0;

    do {
        c = fgetc(file);

        if (c == '\n' || c == EOF) {
            if (i != 0) {
                fact[i] = '\0';
                facts = add_prop_in_tail_of_list(facts, fact);
                i = 0;
            }
        }
        else if (c == ';' || c == ' ') {
            fprintf(stderr, "invalid fact in %s", filename);
            while (c != '\n' && c != EOF) {
                c = fgetc(file);
            }
            i = 0;
        }
        else {
            fact[i] = c;
            i++;
        }
    } while (c != EOF);

    fclose(file);

    return facts;
}


