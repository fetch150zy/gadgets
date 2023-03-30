/**
 * @file plans.c
 * @author fetch150zy (Mars_zhewei@outlook.com)
 * @brief todo list app
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "include/data.h"

char *db_path;

/* data structure for storing plans */
struct planlist todos[SIZE];

/* the number of plans */
unsigned char length = 0;

#define ERROR_EXIT -1

int main(int argc, char** argv)
{
    system("clear||@cls");              /* clean srceen */
    printf("\033[38;5;226m");           /* set menu color */

    FILE *fp = NULL;
    db_path = getenv("HOME");        /* get home path */
    strcat(db_path, "/tododb");            /* add database name */
    if (access(db_path, F_OK) == -1) {    /* database is exist? */
        bool is_created = create_database(fp);
        if (!is_created) {                          /* failed to create */
            puts("The todolist app is crash!");
            return ERROR_EXIT;
        }
    }
    operate(fp);                                    /* main loop */
    
    return 0;
}