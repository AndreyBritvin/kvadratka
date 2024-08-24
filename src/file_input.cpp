#include "file_input.h"

int open_file(FILE **fp, char * filename)
{


    if ((*fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Error in opening file: %s\n", filename);

        return FILE_UNSUCCESS;
    }
    return FILE_SUCCESS;
}

int close_file(FILE *fp,  char filename[])
{
    if (fclose(fp))
    {
        fprintf(stderr, "Error in closing file: %s", filename);

        return FILE_UNSUCCESS;
    }
    return FILE_SUCCESS;
}

char * read_line(FILE *fp)
{
    return "";
}
