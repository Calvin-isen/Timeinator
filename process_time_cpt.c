#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

void interrupt()
{
	printf("Signal reçu par la tache fille\n");
}

int main(int argc, char* argv[])
{
	printf("coucou\n");
	printf("Timer : %s\n", argv[1]);
	int nbsec=atoi(argv[1]);
	signal(SIGINT,interrupt); // On connecte le signal
	while(nbsec > 0){
		printf("il reste %dsec\n", nbsec);
		sleep(1); // On attend un signal de la tache mère
		nbsec-=1;
	}
	
	

	
	printf("Fin de la tache fille\n");
	exit(0);
	
	return 0;
}