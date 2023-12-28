#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getFileNameFromPath(char* path)
{
    for(size_t i = strlen(path) - 1; i; i--)  
    {
        if (path[i] == '/')
        {
            return &path[i+1];
        }
    }
    return path;
}

int main(int argc, char *argv[])
{
    if(argc <= 2)
    {
        printf("Missing arguments\n");
        printf("%s destinationfolder/ filename ...\n", argv[0]);
        return 1;
    }

    char *dest = argv[1];

    for(int i = 2; i < argc; i++)
    {
        char *src_file = argv[i];

        char *filename = getFileNameFromPath(src_file);
        char dst_file[100];

        strcpy(dst_file, dest);
        strcat(dst_file, filename);

        FILE *output, *input;

        input = fopen(src_file, "r");
        output = fopen(dst_file, "w");

        if(input == NULL)
        {
            printf("File Error: %s\n", src_file);
            return 1;
        }

        if(output == NULL)
        {
            printf("File Error: %s\n", dst_file);
            return 1;
        }

        char buffer = '\0';
        char previous_char = '\0';
        char two_previous_char = '\0';

        while (fread(&buffer, sizeof(char), 1, input) != 0)
        {
            if(buffer != '/' && previous_char == '<' && two_previous_char == '>')
            {
                fseek(output, -1, SEEK_END);
                fprintf(output, "%c%c%c", '\n', '<', buffer);
            }
            else
                fprintf(output, "%c", buffer);

            two_previous_char = previous_char;
            previous_char = buffer;
        }

        fclose(input);
        fclose(output);
        printf("Finished: %s\n", src_file);
    }

    return 0;
}