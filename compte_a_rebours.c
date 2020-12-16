#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <unistd.h>



int heure = -1, minute = -1, seconde = -1;

int heure1 =-1, minute1 = -1, seconde1 = -1;

int heure2 =-1, minute2 = -1, seconde2 = -1;

int choix = 0;



int main(void)

{

		

	while ((heure<0 || heure>23) || (minute<0 || minute>59) || (seconde<0 || seconde>59))

	{

	    printf("Entrez le temps du compte a rebours au format hh:mm:ss\n");

	    scanf("%d:%d:%d", &heure, &minute, &seconde);

	}



	printf("combien de temps de sonnerie intermediaires voulez vous? (0,1 ou 2)\n");

	scanf("%d",&choix);

	system("clear");

	

	switch(choix)

	{

		case 0:

		

			while(heure>=0)

			{

				while(minute>=0)

				{

					while(seconde>=0)

					{

						printf("%d:%d:%d\n", heure, minute, seconde);

						sleep(1);

						seconde--;

						if (heure==0 && minute==0 && seconde==0)

						{

							printf("%d:%d:%d\n", heure, minute, seconde);

							system("cvlc --play-and-exit SON/son1.wav"); // la musique se joue et cela quitte le programme une fois la musique terminée

							printf("Compte a rebour termine\n");

							break;

						}

					}

					seconde=59;

					minute--;

				}

				minute=59;

				heure--;

			}

			

			break;

			

		case 1:

			while ((heure1<0 || heure1>23) || (minute1<0 || minute1>59) || (seconde1<0 || seconde1>59))

			{

	    		printf("Entrez le temps de l'interruption 1 au format hh:mm:ss\n");

	    		scanf("%d:%d:%d", &heure1, &minute1, &seconde1);

			}

			while(heure>=0)

			{

				while(minute>=0)

				{

					while(seconde>=0)

					{

						printf("%d:%d:%d\n", heure, minute, seconde);

						sleep(1);

						seconde--;

						if (heure==heure1 && minute==minute1 && seconde==seconde1)

						{

							system("cvlc --play-and-exit SON/son1.wav"); // la musique se joue et cela quitte le programme une fois la musique terminée

						}

						if (heure==0 && minute==0 && seconde==0)

						{

							printf("%d:%d:%d\n", heure, minute, seconde);

							system("cvlc --play-and-exit SON/son1.wav"); // la musique se joue et cela quitte le programme une fois la musique terminée

							printf("Compte a rebour termine\n");

							break;

						}

					}

					seconde=59;

					minute--;

				}

				minute=59;

				heure--;

			}

			

			break;

						

		case 2:

			while ((heure1<0 || heure1>23) || (minute1<0 || minute1>59) || (seconde1<0 || seconde1>59))

			{

	    		printf("Entrez le temps de l'interruption 1 au format hh:mm:ss\n");

	    		scanf("%d:%d:%d", &heure1, &minute1, &seconde1);

			}

			while ((heure2<0 || heure2>23) || (minute2<0 || minute2>59) || (seconde2<0 || seconde2>59))

			{

	    		printf("Entrez le temps de l'interruption 1 au format hh:mm:ss\n");

	    		scanf("%d:%d:%d", &heure2, &minute2, &seconde2);

			}

			while(heure>=0)

			{

				while(minute>=0)

				{

					while(seconde>=0)

					{

						printf("%d:%d:%d\n", heure, minute, seconde);

						sleep(1);

						seconde--;

						if (heure==heure1 && minute==minute1 && seconde==seconde1)

						{

							system("cvlc --play-and-exit SON/son1.wav"); // la musique se joue et cela quitte le programme une fois la musique terminée

						}

						if (heure==heure2 && minute==minute2 && seconde==seconde2)

						{

							system("cvlc --play-and-exit SON/son1.wav"); // la musique se joue et cela quitte le programme une fois la musique terminée

						}

						if (heure==0 && minute==0 && seconde==0)

						{

							printf("%d:%d:%d\n", heure, minute, seconde);

							system("cvlc --play-and-exit SON/son1.wav"); // la musique se joue et cela quitte le programme une fois la musique terminée

							printf("Compte a rebour termine\n");

							break;

						}

					}

					seconde=59;

					minute--;

				}

				minute=59;

				heure--;

			}

			

			break;	

			

	}

	

    return 0;

}




