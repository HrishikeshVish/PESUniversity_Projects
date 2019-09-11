#include<stdio.h>

#include<stdlib.h>

#include<unistd.h>

#include<sys/types.h>

#include<sys/wait.h>

#include<string.h>

 

 

int main()

{

                int count=0;

                char commands[100];

                

                printf("> ");

                scanf("%[^\n]s",commands);

                printf("%s\n__\n",commands);

                char *command1,*command2,*token;

                char *args1[50],*args2[50];

                int i=1;

                command1=strtok(commands," ");

                args1[0]=command1;

                while(strcmp((token=strtok(NULL," ")),"|")!=0)

                {

                                args1[i]=token;i++;

                }

                args1[i]=NULL;

                command2=strtok(NULL," ");

                args2[0]=command2;

                i=1;         

                while((token=strtok(NULL," "))!=NULL)

                {

                                args2[i]=token;i++;

                }

                args2[i]=NULL;

                printf("%s , %s\n",command1,command2);

                printf("%s\n",args2[0]);

                int fd[2];

                pipe(fd);

                pid_t fork_status= fork();

                

                                if(fork_status==0)

                                {

                                                printf("Child process called\n");

                                                close(fd[0]);

                                                dup2(fd[1], 1);                                   

                                                execvp(command1,args1);                                          

                                }

                                else if(fork_status > 0){

                                                printf("Parent process\n");

                                                close(fd[1]);

                                                dup2(fd[0],0);

                                                execvp(command2,args2);                                          

                                }

                close(fd[0]);

                close(fd[1]);

                wait(NULL);        

}
