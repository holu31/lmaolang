// BY HOLU31

// -------- includes ----------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <time.h>

// CODE IS DISTRIBUTED UNDER THE GPL
// КОД РАСПРОСТРАНЯЕТСЯ ПО ЛИЦЕНЗИИ GPL
// 代碼根據 GPL 分發
// IL CODICE E' DISTRIBUITO SOTTO LA GPL
// EL CÓDIGO SE DISTRIBUYE BAJO LA GPL

// ============== DEFINES ==================

#define VERSION (char*)"v0.1.0-rc0"
#define TOTAL_NUMBER_OF_ARGUMENTS_FOR_ACCEPTANCE 2
#define FILE_CONTENT_SIZE 100000
#define LMAO_TRUE 1
#define LMAO_FALSE 0
// -------------- errors -------------------
#define ERROR "error"
#define FILEREAD_ERROR "file read error"
#define UNDEFINDED_TKN "undefinded name"
// -----------------------------------------

// =========================================

// .. global variables -

// lmao interpreter
// by holu31

// text processing in a script for toxicons and lexicons ans parsing
void *interpretator(char *filecontent){
	int strings = 1; // number of lines
	char *string = strtok(filecontent, "\n"); // curent line
	char *value; // current token
	while(string != NULL) {
		value = strtok(string, " ");
		int run = LMAO_TRUE;
		while(run){
			// SHORT: CHECK THE NAME OF THE TOKENS
			if(value == NULL) run = LMAO_FALSE;
			if(strcmp(value, "echo") == 0){
				value = strtok(NULL, " "); // GET NEXT TOKEN
				if(value == NULL){
					// I briefly explain, guys, listen carefully, the information is important, at this stage I'm tired of making macros for errors :)
					printf("%s:%d: where is the sequel?\n", ERROR, strings);
					exit(1);
				}
				char result[1024]; // result of my ass
				while(value != NULL){
					strcat(result, value);
					strcat(result, " ");
					value = strtok(NULL, " ");
				}
				printf("%s\n", result);
				run = LMAO_FALSE;
			}
			else {
				printf("%s:%d: %s \"%s\"\n", ERROR, strings, UNDEFINDED_TKN, value);
			}
			value = strtok(NULL, " ");
		}
		strings++;
		string = strtok(NULL, "\n");
	}
}

// TODO: not realesed... is hard
/*FILE *read_file_to_return_readed_file(char* filename_){
	FILE *file;
	return file;
}*/

/// <returns> The standard function to start the code with </returns>
/// <param name="argc">parameter that takes the number of arguments
///	that were passed to the program</param>
/// <param name="argv">parameter that takes arguments</param>
int main(int argc, char *argv[]){
	// In this line of code, we can see how we are looking for a file name
	// We assess the situation of the outside world
	// Find out how many parameters were passed to the console
	// find filename
	if(argc < TOTAL_NUMBER_OF_ARGUMENTS_FOR_ACCEPTANCE)
		return 0;
	char *filename = argv[1];
	if(strcmp(filename, "-version") == 0 ||
		strcmp(filename, "--version") == 0 ||
		strcmp(filename, "-v") == 0 ||
		strcmp(filename, "-V") == 0)
	{
		printf("CURRENT VERSION OF THIS LANG - %s\n", VERSION);
		printf("Copyright (C) 2022-1325 lmao.lmao, holu31\n");
		printf("Project completely made by me\n");
		printf("\tLmao xD lol...\n\n\n");
		return 0;
	}
	// i use arch btw
	// TODO: support for current versions only on Arch Linux
	FILE *file; // crete variable to save file to this variable and check content on functino other
	if ((file = fopen(filename, "r")) == NULL) // ??????? WHAT IS THIS?? I FOUND THIS CODE ON GOOGLE
{		printf("%s: %s", ERROR, FILEREAD_ERROR); // PRINT ERROR IF FILE READ ERROR
    		return 0;
  	}
	char filecontent[FILE_CONTENT_SIZE] = "";
	char cc[256] = "";
	while((fgets(cc, 256, file))!=NULL)
    {
        	strcat (filecontent, cc);
    }
	//printf("DEBUG: %s", filecontent);
	fclose(file); // close file with computer
	///* CALL FUNCTION HANDLER FILES  *///
	interpretator(filecontent);
	return 0;
}
