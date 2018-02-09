#include <stdio.h>
#include "msg.h"

extern int *
printmessage_1(msg, req)
	char **msg;
	CLIENT* req;
{
	static int result;
	FILE *f;
	f = fopen("/dev/console", "w");
	if (f == (FILE *)NULL) {
		result = 0;
		return (&result);
	}
	fprintf(f, "%s\n", *msg);
	fclose(f);
	result = 1;
	return (&result);
}

extern int *
printmessage_1_svc(msg, req)
	char **msg;
	struct svc_req *req;
{
	static int result;
	FILE *f;
	f = fopen("/dev/console", "w");
	if (f == (FILE *)NULL) {
		result = 0;
		return (&result);
	}
	fprintf(f, "%s\n", *msg);
	fclose(f);
	result = 1;
	return (&result);
}
