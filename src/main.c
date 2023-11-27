#include "base.h"
#include "engine.h"






int main(int argc, char *argv[]) {
    
    Base *base = new_read_base_file("base_file.txt");

    printf("%s", base->head->conclusion);

    return 0;
}