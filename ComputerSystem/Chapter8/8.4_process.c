#include <unistd.h>	/* getpid */
#include <stdlib.h> /* exit */
#include <stdio.h>

void unix_error(char *msg)
{
	fprintf(stderr, "%s: %s\n", msg, strerror(errno));
	exit(0);
}

pid_t Fork(void)
{
	pid_t pid;
	if ((pid = fork()) < 0)
		unix_error("Fork error");
	return pid;
}

int main()
{
	printf("%d\n", getpid());

	exit(0);
}