#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER 1024

char ** get_input(char *string);

char ** get_input(char *string)
{
	char **temp=(char**)malloc(8*sizeof(char*));
	char *token=strtok(string," ");
	int i=0;
	while(token!=NULL)
	{
		temp[i]=(char*)malloc(sizeof(token));
		strcpy(temp[i],token);
		token=strtok(NULL," ");
		i++;
	}
	temp[i]=NULL;
	return temp;
	
}

int main(void) {
    char line[BUFFER];

    while(1) {
        printf("$ ");
        if(!fgets(line, BUFFER, stdin)) break;
        char *p = strchr(line, '\n');
        if (p) *p = 0;
        if(strcmp(line, "exit")==0) break;
        char **args=get_input(line);
        int pid= fork();              //fork child
        if(pid==0) {               //Child
            execvp(args[0], args);
            perror("exec");
            exit(1);
        } else {                    //Parent
            wait(NULL);
        }
    }

    return 0;
}
