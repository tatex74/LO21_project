#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


typedef struct {
    char base_file[100];
    char facts_file[100];
} Files_path;

Files_path *get_paths(int argc, char *argv[]);


#endif