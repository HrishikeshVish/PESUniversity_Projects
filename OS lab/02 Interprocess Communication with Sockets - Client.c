#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define LIST "list"
#define GET "get"

int main(int argc, char **argv) 
{
	int sockfd = 0;
	int bytesReceived = 0;
	char recvBuff[256];

	//memset(recvBuff, '0', sizeof(recvBuff));	// memset() is used to fill a block of memory with a particular value.

	struct sockaddr_in serv_addr;

		  /* Create a socket first */

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 	// Create socket
	{
		printf("\n Error : Could not create socket \n");
	        return 1;
  	}


	  /* Initialize sockaddr_in data structure */

	serv_addr.sin_family = AF_INET;				// A sockaddr_in is a structure containing an internet address. 
								// This structure is defined in <netinet/in.h>.
	serv_addr.sin_port = htons(5050);  			// port:5050
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	// local host IP address: 127.0.0.1


	  /* Attempt a connection */

	if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) // connect - initiate a connection on a socket.
	{
		printf("\n Error : Connect Failed \n");
		return 1;
	}
	
	printf("Connected\n");
	if (strcmp(LIST, argv[1]) == 0)
  	{
		// TODO:  Send LIST to the server using the write() system call using the "sockfd" file descriptor
		// TODO:  Use read() system call within a loop to read from the server using the "sockfd" file descriptor
		printf("Argument is list\n");
		if(write(sockfd,LIST,256) > 0){
			while(read(sockfd,recvBuff,256) > 0)
			{
				printf("%s\n",recvBuff);
			}
		}

  	}

		 /*Create file where data will be stored */

	if (strcmp(GET, argv[1]) == 0)
	{
		// TODO:  Send GET to the server using the "sockfd" file descriptor
		// TODO:  Send the filename to the server using the "sockfd" file descriptor
		// TODO: Create a file with the same name using the open() system call using appropriate flags

		/*TODO:  Receive data in chunks of 256 bytes */
    		// TODO:  Use the read() system call within a loop to fetch the contents of the file from the server
		// TODO:  Use the write() system call to write those contents in the file which was created above.
		if(write(sockfd,GET,256) > 0){
		
			if(write(sockfd,argv[2],256) > 0)
				while(read(sockfd,recvBuff,256) > 0)
				{
					int filefd=open(argv[2],O_CREAT | O_RDWR);
					write(filefd,recvBuff,strlen(recvBuff));
						printf("%s ",recvBuff);
				}
		}

    	}
  
	return 0;
}
