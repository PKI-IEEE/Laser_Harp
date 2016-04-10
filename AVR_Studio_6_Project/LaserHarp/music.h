// Author: Josh Hansen
// Pre-programmed Music by Brain Felderman
// Date: Oct 2015

#ifndef MUSIC_H_
#define MUSIC_H_

#include <avr/io.h>

void play32Note(uint16_t note);
void playQNote(uint16_t note);
void playENote(uint16_t note);
void playEdotNote(uint16_t note);
void playHNote(uint16_t note);
void play16Note(uint16_t note);

void playStarWars();
void playBumbleBee();


#endif 