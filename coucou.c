#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

void interrupt()//Gestion de l'interruption
{
	printf("Fermerture du coucou ...\n");
	exit(0);
}

int main(int argc, char const *argv[])
{
	printf("coucou\n");
	signal(SIGUSR1,interrupt);
	return 0;
}