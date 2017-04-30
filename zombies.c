/*
	This program is used to generate zombie processes so SysAdmins can learn how to 
	troubleshoot misbehaving programs.
*/

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	pid_t pid;


	printf("fork()'ing 10 times\n");
	for (int i = 0; i<10; i++) {
		pid = fork();

		if (pid == 0) {
			break;
		} else if (pid < 0) {
			printf("fork() failed\n");
			break;
		}
	}

	if (pid > 0) {
		printf("Parent sleeping for 1 min. Do 'ps axo stat,pid,ppid,comm | grep Z' to see processes in zombie state. Since this program does not handle the SIGCHLD signal, you'll have to kill the parent.\n");
		sleep(60000);
	}

	return 0;
}
