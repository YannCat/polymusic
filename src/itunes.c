#include <stdio.h>
#include <stdlib.h>
#include "fmod/fmod.h"

int choice;
int choice1;
int choose;
int a;

FMOD_SYSTEM  *fmodsys;
FMOD_RESULT result;
FMOD_SOUND *sound;
FMOD_CHANNELGROUP *channelgroup;
FMOD_CHANNEL *channel = 0;
FMOD_BOOL etat;

int MENU () {
		while(1){
		printf("\e[1;1H\e[2J");
		printf("---MENU---\n");
		printf("1) ADMIN\n");
		printf("2) USER\n");
		printf("3) CONFIGURATION\n");
		printf("4) PLAY SOUND\n");
		printf("CHOIX DU MENU : ");
		scanf("%d",&choice);
		switch (choice) {
			case 1:
			printf("\e[1;1H\e[2J");
			printf("---ADMIN CONTROL PANEL---\n");
			printf("1) RETOUR\n");
			printf("CHOIX : ");
			scanf("%d",&choice1);
			if ( choice1 == 1 )
				{
					MENU();
				}
			else if (choice1 > 2)
				printf("\e[1;1H\e[2J");
				printf("Le choix selectionner n'existe pas\n");
				MENU();	
			break;
			
			case 2 :
			printf("\e[1;1H\e[2J");
			printf("---USER CONTROL PANEL---\n");
			break;
			
			case 3 :
			printf("\e[1;1H\e[2J");
			printf("---CONFIGURATION CONTROL PANEL---\n");
			break;
			
			case 4 :
			printf("\e[1;1H\e[2J");
			printf("---PLAY SOUND---\n");
			FMOD_System_PlaySound(fmodsys,sound ,NULL, 0, NULL);
			printf("1) PAUSE\n");
			printf("2) PLAY\n");
			printf("3) STOP\n");
			printf("4) EXIT\n");
			scanf("%d",&choose);
			switch (choose) {
				case 1:
					FMOD_System_PlaySound(fmodsys,sound ,NULL, 1, NULL);
				break;	
				
				case 2 :
					FMOD_ChannelGroup_GetPaused(0, &etat);
					if (etat == 1)
						FMOD_ChannelGroup_SetPaused(0, 0); 
					else
						FMOD_ChannelGroup_SetPaused(0, 1);
				break;
				
				case 3:
					FMOD_System_PlaySound(fmodsys,sound ,NULL, 0, NULL);
				break;
					
			}
			break;
			
		}
	}
}	

int main()
{		
		FMOD_System_Create(&fmodsys);		
		FMOD_System_Init(fmodsys, 1, FMOD_INIT_NORMAL, NULL);
		result = FMOD_System_CreateSound(fmodsys, "/home/user/Documents/projet_algo/music/051_1.WAV", FMOD_CREATESTREAM, 0, &sound);
		if ( result != FMOD_OK ) 
		{
				fprintf(stderr, "Impossible de lire le fichier audio\n");
				exit(EXIT_FAILURE);
		}
		MENU();
		scanf("%d",&a);
		FMOD_Sound_Release(sound);
		FMOD_System_Close(fmodsys);
		FMOD_System_Release(fmodsys);
			
}

