/*
 * cc fork.c && ./a.out
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

#define DEVFILE "/dev/devone"

int open_file(void)
{
	int fd;

	fd = open(DEVFILE, O_RDWR);
	if (fd == -1) {
		perror("open");
	}

	return (fd);
}

void close_file(int fd)
{
	if (close(fd != 0)) {
		perror("close");
	}
}

int main(void)
{
	int fd;
	int status;

	fd = open_file();
	if (fork() == 0) {
		sleep(3);
		close_file(fd);
		exit(1);
	}
	wait(&status);
	sleep(10);
	close(fd);

	return 0;
}
