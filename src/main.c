#include <stdio.h>
#include "base.h"
#include "engine.h"
#include "proposition.h"
#include "options.h"

int main(int argc, char *argv[]) {

    Files_path paths = get_paths(argc, argv);
    
    Base base = read_base_file(paths.base_file);
    Prop_List facts = read_facts_file(paths.facts_file);

    Prop_List new_facts = engine(facts, base);
    print_proposition_list(new_facts);

    free_base(base);
    free_prop_list(facts);
    free_prop_list(new_facts);

    return 0;
}