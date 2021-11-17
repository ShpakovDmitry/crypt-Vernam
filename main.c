#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool isCorrectInputParameters(int argc, char** argv);

bool isCorrectInputParameters(int argc, char** argv) {
    bool res = true;

    if ( argc != 4 ) {
        printf("Usage: crypt [ source file ] [ destination file ] [ key ]\n");
        res = false;
    } else if ( ( strlen(argv[1]) == 0) || ( strlen(argv[2]) == 0 ) ) {
        printf("Incorrect file name!\n");
        res = false;
    } else if ( strlen(argv[3] ) == 0 ) {
        printf("Incorrect key!\n");
        res = false;
    }

    return res;
}

int main(int argc, char *argv[]) {
    FILE *destination;
    FILE *source;
    char c;
    unsigned int i = 0;
    unsigned int j;
    unsigned int keySize = 0;
	
    if ( !isCorrectInputParameters(argc, argv)) {
        return EXIT_FAILURE;
    }

    keySize = strlen(argv[3]);
	
	//-----
	
	if( (argv[1][0] == '-') && (argv[1][1] == 's') && (argv[1][2] == '\0') )
	{
		destination = fopen(argv[2], "r"); // 
		if(destination != NULL)
		{
			printf("File with name %s already exist's.\nAppend? (y or n) ", argv[2]);
			//char c = getchar();
			char c;
			scanf("%c", &c);
			if( (c == 'n') || (c == 'N') )
			{
				printf("Rewrite? (y or n) ");
				//c = getchar();
				scanf("\n%c", &c);
				if( (c == 'n') || (c == 'N') )
				{
					fclose(destination);
					return 1;
				}
				else
				{
					fclose(destination);
					destination = fopen(argv[2], "w");
					if(destination == NULL)
					{
						printf("Can't create destination file\"%s\"\n", argv[2]);
						return -1;
					}
				}
				
			}
			else
			{
				fclose(destination);
				destination = fopen(argv[2], "a");
				if( destination == NULL )
				{
					printf("Can't append to destination file\"%s\"\n", argv[2]);
					return -1;
				}
			}
		}
		else
		{
			destination = fopen(argv[2], "w");
			if(destination == NULL)
			{
				printf("Can't create destination file\"%s\"\n", argv[2]);
				return -1;
			}
		}
	//===============================Алгоритм кодирования========================================//
	
	printf("Crypting...\n");
	getchar();
	while( (c = getchar() ) != EOF )
	{
		c ^= argv[3][i];
		
		fprintf(destination,"%c", c);
		if( (i++) > (keySize-1) )
		{
			i = 0;
		}
	}
	
	printf("\nDone\n");
	
	//===========================================================================================//
	
	fclose(destination);
	
	return 0;
	
	}
	
	
	
	//-----
	
	source = fopen(argv[1], "r"); // открыть файл источник для чтения
	if(source == NULL) // проверяем его существование
	{
		printf("Can't open source file\"%s\" or file does not exist\n", argv[1]);
		return -1;
	}
	
	destination = fopen(argv[2], "r"); // 
	if(destination != NULL)
	{
		printf("File with name %s already exist's.\nRewrite? (y or n) ", argv[2]);
		char c = getchar();
		if( (c == 'n') || (c == 'N') )
		{
			fclose(source);
			fclose(destination);
			return 1;
		}
		else
		{
			fclose(destination);
			destination = fopen(argv[2], "w");
		}
	}
	else
	{
		destination = fopen(argv[2], "w");
		if(destination == NULL)
		{
			printf("Can't create destination file\"%s\"\n", argv[2]);
			return -1;
		}
	}
	
	
	
	//===============================Алгоритм кодирования========================================//
	
	printf("Crypting...");
	
	while( fscanf(source,"%c", &c) != EOF )
	{
		c ^= argv[3][i];
		
		fprintf(destination,"%c", c);
		if( (i++) > (keySize-1) )
		{
			i = 0;
		}
	}
	
	printf("\nDone\n");
	
	//===========================================================================================//
	
	
	
	fclose(source);
	fclose(destination);
	return 0;
}
