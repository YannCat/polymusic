#ifndef FONCTIONS_H
#define FONCTIONS_H

extern FMOD_SYSTEM  *fmodsys;
extern FMOD_BOOL etat;
extern int choix, choix2;
extern FMOD_SOUND *sound;

void MENU_PRINCIPAL();
void ADMIN();
void USER();
void CONFIGURATION();
void ECOUTER_SON();

#endif
