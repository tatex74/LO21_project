#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>


typedef struct {
    char *base_file;
    char *facts_file;
} Files_path;

Files_path get_paths(int argc, char *argv[]);


#endif