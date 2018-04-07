#include <stdio.h>
#include <stdlib.h>
#include "fmod/fmod.h"

int choix, choix2;
int a;

FMOD_SYSTEM  *fmodsys;
FMOD_RESULT result;
FMOD_SOUND *sound;
FMOD_CHANNELGROUP *channelgroup;
FMOD_CHANNEL *channel = 0;
FMOD_BOOL etat;

int MENU_PRINCIPAL () {
	
	while(1){
		printf("\e[1;1H\e[2J");
		printf("---MENU---\n");
		printf("1) ADMIN\n");
		printf("2) USER\n");
		printf("3) CONFIGURATION\n");
		printf("4) PLAY SOUND\n");
		printf("5) QUITTER\n");
		printf("CHOIX DU MENU : ");
		scanf("%d",&choix);
			/*if(choix != 1 || choix != 2 || choix != 3 || choix != 4 || choix != 5)
				{
					printf("Choix impossible. Choisissez une option entre 1 et 4");
				}*/
			//else{
				switch (choix){
					case 1 :
						printf("\e[1;1H\e[2J");
						printf("---ADMIN CONTROL PANEL---\n");
						printf("1) RETOUR\n");
						printf("CHOIX : ");
						scanf("%d",&choix);
						if(choix != 1)
						{
							printf("Choix impossible. Choisissez une option entre 1 et 1");
						}
						else
						{
							MENU_PRINCIPAL();
						}
					break;
					
					case 2 :
						printf("\e[1;1H\e[2J");
						printf("---USER CONTROL PANEL---\n");
						printf("1) RETOUR\n");
						printf("CHOIX : ");
						scanf("%d",&choix);
						if(choix != 1)
						{
							printf("Choix impossible. Choisissez une option entre 1 et 1");
						}
						else
						{
							MENU_PRINCIPAL();
						}
					break;
					
					case 3:
						printf("\e[1;1H\e[2J");
						printf("---CONFIGURATION CONTROL PANEL---\n");
						printf("1) RETOUR\n");
						printf("CHOIX : ");
						scanf("%d",&choix);
						if(choix != 1)
						{
							printf("Choix impossible. Choisissez une option entre 1 et 1");
						}
						else
						{
							MENU_PRINCIPAL();
						}
					break;
					
					case 4 :
						FMOD_System_PlaySound(fmodsys, sound, NULL, 0, NULL);
						while(choix2 != 3){
							printf("\e[1;1H\e[2J");
							printf("---PLAY SOUND---\n");
							printf("1) PLAY/PAUSE\n");
							printf("2) STOP\n");
							printf("3) RETOUR\n");
							printf("CHOIX DU MENU : ");
							scanf("%d",&choix2);
							switch (choix2) {
								case 1:
									FMOD_Channel_GetPaused(0, &etat);

									if (etat == 1) 								// Si la chanson est en pause
										FMOD_Channel_SetPaused(0, 0); 			// On enlève la pause
									else 										// Sinon, elle est en cours de lecture
										FMOD_Channel_SetPaused(0, 1); 			// On met en pause
								break;	
								
								case 2 :
									FMOD_System_PlaySound(fmodsys,sound ,NULL, 1, NULL);
								break;	
							}
							MENU_PRINCIPAL();
						}
					break;
					
					case 5:
						printf("\e[1;1H\e[2J");
						exit(0);
					break;
			//}
		}
	}
}


int main()
{		
		FMOD_System_Create(&fmodsys);		
		FMOD_System_Init(fmodsys, 1, FMOD_INIT_NORMAL, NULL);
		result = FMOD_System_CreateSound(fmodsys, "music/049_1.WAV", FMOD_CREATESTREAM, 0, &sound);
		if ( result != FMOD_OK ) 
		{
				fprintf(stderr, "Impossible de lire le fichier audio\n");
				exit(EXIT_FAILURE);
		}
		MENU_PRINCIPAL();
		scanf("%d",&a);
		FMOD_Sound_Release(sound);
		FMOD_System_Close(fmodsys);
		FMOD_System_Release(fmodsys);
			
}

