#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <string.h>
#include<fcntl.h>
int main(void){

	int dp, nb;
	char buf[255];
	char bufTem[255];
	
	while(1){
		sleep(1);

		dp=open("pipe",O_RDONLY);
		nb=read(dp,bufTem,255);

		if (strcmp(buf, bufTem)!=0)
		{
			sprintf(buf,"%s", bufTem);
			system("clear");
		}

		
		buf[nb]='\0';
		printf("%s\n",buf );
		close(dp);
	}
	exit(0);

	return 0;
}