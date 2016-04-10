// Author: Josh Hansen
// Pre-programmed Music by Brain Felderman
// Date: Oct 2015
// Description: PKI Laser Harp Project
// Uses variable PWM frequency to play an 8-bit piano note waveform

#define F_CPU 16000000 // 16 MHz clock freq

#include <util/delay.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include "LaserHarp.h"
#include "music.h"

//---------------GLOBAL VARIABLES---------------//
volatile unsigned int waveformCounterNote1 = 0; // used for waveform array index

// Change this array to change the notes the harp plays. 
// The letter is the note, the number the octave and s indicates sharp
// See the header file for a define list of all the possible notes
const uint16_t noteArray1[8] = {A3,B3,C4,D4,E4,F4,G4,A4}; 
volatile uint8_t playEnabled = TRUE; // state variable to ensure note does not play more than once per beam break

void initBoard() {
	DDRC = 0; // ADC port input
	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0); // ADC Enable, ADC prescaler /8
	
	DDRD = 0xFF; // set port D pins as output
	PORTD = 0; // initialize port D pins to 0
	OCR0A = 0;
	TCCR0A |= (1<<WGM00) | (1<<WGM01) | (1<<COM0A1) | (1<<COM0A0); // set up Timer0 for PWM
	TCCR0B |= (1<<CS00); // Enable Timer0 with prescaler of 1
	
	OCR1A = 0;
	TCCR1B|=(1<<WGM12); // Timer1 in CTC mode
	TIMSK1|=(1<<OCIE1A); // Enable Timer1, CTC Compare A interrupt
	TCCR1B|=(1<<CS10); // Enable Timer1 with prescaler of F_CPU/1

}

ISR(TIMER1_COMPA_vect) { // Timer 1 Compare A Interrupt Handler
	if(playEnabled == TRUE) { // if we should play the note
		OCR0A = pgm_read_word(&(pianoWaveform[waveformCounterNote1++])); // put the next value of the waveform out to PWM pin
	}

	if(waveformCounterNote1 >= 4000) { // if we have played the entire note 10000
		waveformCounterNote1 = 0; // reset the waveform array index
		playEnabled = FALSE; // disable playing the note again
	}
}

void playNote(uint16_t note) {
	playEnabled = TRUE; // reset state variable
	waveformCounterNote1 = 0; // reset waveform array index
	OCR1A = note; // adjust PWM freq to required note
}

void playNote1(uint8_t note) {
	playEnabled = TRUE; // reset state variable
	waveformCounterNote1 = 0; // reset waveform array index
	OCR1A = noteArray1[note]; // adjust PWM freq to required note
}

int main(void) {
	initBoard();
	uint8_t adcLow = 0; // declare and initialize low byte of ADC value
	uint8_t adcHigh = 0; // declare and initialize high byte of ADC value
	uint16_t adcRaw = 0; // declare and initialize 16-bit variable for ADC value
	static uint8_t loopCounter = 0; // loop counter used to check all eight lasers
	static uint8_t noteLocked[8] = {FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE,FALSE}; // array of state variables to ensure note plays through once without restarting
	sei(); // enable global interrupts
	// Any music/note playing must be done after global interrupts have been enabled
	playStarWars();
	
    while(1) {		
		ADMUX = (loopCounter & 0x0F); // select ADC channel
		ADCSRA |= (1<<ADSC); // start ADC conversion
		while((ADCSRA & (1<<ADIF))==0); // wait for ADC conversion
		adcLow = ADCL; // get ADC low value
		adcHigh = ADCH; // get ADC high value
		adcRaw = ((adcHigh << 8) | (adcLow));// combine ADC value

		if((adcRaw < THRESH) && (noteLocked[loopCounter] == FALSE)) { // if the ADC reading is below threshold value (beam is broken) and the note isn't locked
			playNote1(loopCounter); // play the note corresponding to the beam that was broken
			noteLocked[loopCounter] = TRUE;	// lock the note so it doesn't restart immediately
		}
		else if(adcRaw >= THRESH) { // if the beam is not broken then we should unlock the note
			noteLocked[loopCounter] = FALSE; // unlock the note
		}
		
		loopCounter++; // increase the counter to test next beam
		if(loopCounter >= 8) { // we only have 8 lasers/notes so reset the counter
			loopCounter = 0; // reset the counter 
		}	
	}
}