#include <stdio.h>
#include "base.h"
#include "engine.h"
#include "proposition.h"
#include "options.h"

int main(int argc, char *argv[]) {

    Files_path paths = get_paths(argc, argv);

    if (paths.base_file == NULL || paths.facts_file == NULL) {
        return 0;
    }

    Base base;
    if ((base = read_base_file(paths.base_file)) == NULL) {
        fprintf(stderr, "Error : Unable to open base file\n");
        return 1;
    }
    Prop_List facts;
    if ((facts = read_facts_file(paths.facts_file)) == NULL) {
        fprintf(stderr, "Error : Unable to open facts file\n");
        free_base(base);
        return 1;
    }

    Prop_List new_facts = engine(facts, base);
    printf("New facts : ");
    print_proposition_list(new_facts);

    free_base(base);
    free_prop_list(facts);
    free_prop_list(new_facts);

    return 0;
}