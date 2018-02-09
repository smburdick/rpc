/*
 * rprintmsg.c: remote version of "printmsg.c"
 */
#include <stdio.h>
#include <stdlib.h>
#include "msg.h"

int main(int argc, char *argv[])
{
	CLIENT *clnt;
	int *result;
	char *server;
	char *message;

	if (argc != 3) {
		fprintf(stderr, "usage: %s host	message\n", argv[0]);
		exit(1);
	}

	server = argv[1];
	message = argv[2];
	/*
	 * Create client "handle" used for
	 * calling MESSAGEPROC on the server
	 * designated on the command line.
	 */
	clnt = clnt_create(server, MESSAGEPROG,
					PRINTMESSAGEVERS,
					"visible");
	if (clnt == (CLIENT *)NULL) {
		/*
		 * couldn't establish connection with
		 * server. print error message and die.
		 */
		clnt_pcreateerror(server);
		exit(1);
	}

	/*
	 * Call the remote procedure "printmessage"
	 * on the server.
	 */
	result = printmessage_1(&message, clnt);
	if (result == (int *)NULL) {
		/*
                 * couldn't establish connection with
                 * server. print error message and die.
                 */
		clnt_perror(clnt, server);
		exit(1);
	}
	/* OK, we successfully called the remote procedure. */
	if (*result == 0) {
		/*
		 * server was unable to print our message.
		 * print error message and die.
		 */
		fprintf(stderr,
			"%s: could not print your message\n", argv[0]);
		exit(1);
	}
	/* The message got printed on the server's console */
	printf("Message delivered to %s\n", server);
	clnt_destroy(clnt);
	exit(0);
}
