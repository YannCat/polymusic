#include "fmod/fmod.h"
#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"

void ADMIN(){
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
}

void USER (){
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
}
	
void CONFIGURATION() {
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
}

void ECOUTER_SON() {
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
}

void MENU_PRINCIPAL () {
	while(1){
		printf("\e[1;1H\e[2J");
		printf("---MENU---\n");
		printf("1) ADMIN\n");
		printf("2) USER\n");
		printf("3) CONFIGURATION\n");
		printf("4) ECOUTER UN SON\n");
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
						ADMIN();
					break;
					
					case 2 :
						USER();
					break;
					
					case 3:
						CONFIGURATION();
					break;
					
					case 4 :
						ECOUTER_SON();
					break;
					
					case 5:
						printf("\e[1;1H\e[2J");
						exit(0);
					break;
			//}
		}
	}
}
