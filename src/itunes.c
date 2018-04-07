#include <stdio.h>
#include <stdlib.h>
#include "fmod/fmod.h"
#include "fonctions.h"

int choix, choix2;
int a;
int lon = 0;

FMOD_SYSTEM  *fmodsys;
FMOD_RESULT result;
FMOD_SOUND *sound;
FMOD_CHANNELGROUP *channelgroup;
FMOD_CHANNEL *channel = 0;
FMOD_BOOL etat;
/*FILE *playlist;
playlist=fopen("files/playlist.txt","r");
char son[15];
char cherche[lon];

void LECTURE_PLAYLIST(){
	if(fichier == NULL)
			printf("Erreur lors de l'ouverture du fichier\n"); 				// si le fichier est introuvable, affiche une erreur
		else
		{
		printf("\e[1;1H\e[2J");
		printf("Que voulez-vous écouter?\n");
		scanf("%c", &
		}	
}*/


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

