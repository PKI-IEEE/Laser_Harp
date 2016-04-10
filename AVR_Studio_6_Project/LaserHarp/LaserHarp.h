/*
Josh Hansen
PKI Laser Harp Project
Oct 2015
 
 Note		Frequency(Hz)
 ------------------------
 C0			16.35
 C#0/Db0	17.32
 D0			18.35
 D#0/Eb0 	19.45
 E0			20.60
 F0			21.83
 F#0/Gb0 	23.12
 G0			24.50
 G#0/Ab0 	25.96
 A0			27.50
 A#0/Bb0 	29.14
 B0			30.87
 C1			32.70
 C#1/Db1 	34.65
 D1			36.71
 D#1/Eb1 	38.89
 E1			41.20
 F1			43.65
 F#1/Gb1 	46.25
 G1			49.00
 G#1/Ab1 	51.91
 A1			55.00
 A#1/Bb1 	58.27
 B1			61.74
 C2			65.41
 C#2/Db2 	69.30
 D2			73.42
 D#2/Eb2 	77.78
 E2			82.41
 F2			87.31
 F#2/Gb2 	92.50
 G2			98.00
 G#2/Ab2 	103.83
 A2			110.00
 A#2/Bb2 	116.54
 B2			123.47
 C3			130.81
 C#3/Db3 	138.59
 D3			146.83
 D#3/Eb3 	155.56
 E3			164.81
 F3			174.61
 F#3/Gb3 	185.00
 G3			196.00
 G#3/Ab3 	207.65
 A3			220.00
 A#3/Bb3 	233.08
 B3			246.94
 C4			261.63
 C#4/Db4 	277.18
 D4			293.66
 D#4/Eb4 	311.13
 E4			329.63
 F4			349.23
 F#4/Gb4 	369.99
 G4			392.00
 G#4/Ab4 	415.30
 A4			440.00
 A#4/Bb4 	466.16
 B4			493.88
 C5			523.25
 C#5/Db5 	554.37
 D5			587.33
 D#5/Eb5 	622.25
 E5			659.25
 F5			698.46
 F#5/Gb5 	739.99
 G5			783.99
 G#5/Ab5 	830.61
 A5			880.00
 A#5/Bb5 	932.33
 B5			987.77
 C6			1046.50
 C#6/Db6 	1108.73
 D6			1174.66
 D#6/Eb6 	1244.51
 E6			1318.51
 F6			1396.91
 F#6/Gb6 	1479.98
 G6			1567.98
 G#6/Ab6 	1661.22
 A6			1760.00
 A#6/Bb6 	1864.66
 B6			1975.53
 C7			2093.00
 C#7/Db7 	2217.46
 D7			2349.32
 D#7/Eb7 	2489.02
 E7			2637.02
 F7			2793.83
 F#7/Gb7 	2959.96
 G7			3135.96
 G#7/Ab7 	3322.44
 A7			3520.00
 A#7/Bb7 	3729.31
 B7			3951.07
 C8			4186.01
 C#8/Db8 	4434.92
 D8			4698.63
 D#8/Eb8 	4978.03
 E8			5274.04
 F8			5587.65
 F#8/Gb8 	5919.91
 G8			6271.93
 G#8/Ab8 	6644.88
 A8			7040.00	
 A#8/Bb8 	7458.62
 B8			7902.13
 */ 

#ifndef LASERHARP_H_
#define LASERHARP_H_

#include <avr/pgmspace.h>

#define TRUE 1
#define FALSE 0
#define THRESH 900 // adjust as needed (between 0 and 1023)

// OCR1A = 16MHz / (33.6*Freq)
//S indicates sharp
#define	C0 29125			
#define	Cs0 27494
#define	D0 25950			
#define	Ds0 24483
#define	E0 23116			
#define	F0 21814			
#define	Fs0 20596
#define	G0 19436			
#define	Gs0 18343
#define	A0 17316			
#define	As0 16341
#define	B0 15426		
#define	C1 14562		
#define	Cs1 13743
#define	D1 12972			
#define	Ds1 12245
#define	E1 11558			
#define	F1 10909			
#define	Fs1 10296	
#define	G1 9718			
#define	Gs1 9173
#define	A1 8658			
#define	As1 8172
#define	B1 7713			
#define	C2 7280			
#define	Cs2 6871
#define	D2	6486
#define	Ds2	6122
#define	E2	5778
#define	F2	5454
#define	Fs2	5148
#define	G2	4859
#define	Gs2	4586
#define	A2	4329
#define	As2	4086
#define	B2	3857
#define	C3	3640
#define	CS3	3436
#define	D3	3243
#define	Ds3	3061
#define	E3	2889
#define	F3	2727
#define	Fs3	2574
#define	G3	2430
#define	Gs3	2293
#define	A3	2165
#define	As3	2043
#define	B3	1928
#define	C4	1820
#define	Cs4	1718
#define	D4	1622
#define	Ds4	1531
#define	E4	1445
#define	F4	1364
#define	Fs4	1287
#define	G4	1215
#define	Gs4	1147
#define	A4	1082
#define	As4	1022
#define	B4	964
#define	C5	910
#define	Cs5	859
#define	D5	811
#define	Ds5	765
#define	E5	722
#define	F5	682
#define	Fs5	644
#define	G5	607
#define	Gs5	573
#define	A5	541
#define	As5	511
#define	B5	482
#define	C6	455
#define	Cs6	429
#define	D6	405
#define	Ds6	383
#define	E6	361
#define	F6	341
#define	Fs6	322
#define	G6	304
#define	Gs6	287
#define	A6	271
#define	As6	255
#define	B6	241
#define	C7	228
#define	Cs7 215
#define D7 203		
#define Ds7 191
#define E7 181		
#define F7 170		
#define Fs7 161
#define G7 152			
#define Gs7 143
#define A7 135			
#define As7 128
#define B7 121			
#define C8 114			
#define Cs8 107
#define D8 101			
#define Ds8 96
#define E8 90
#define F8 85			
#define Fs8 80
#define G8 76			
#define Gs8 72
#define A8 68			
#define As8 64
#define B8 60

//---------------FUNCTION PROTOTYPES-------------//
void playNote1(uint8_t note);
void playNote(uint16_t note);
void initBoard();		

// C4 8-bit Piano waveform (takes 10k of program mem)
extern const uint8_t pianoWaveform[10000] PROGMEM;

#endif /* LASERHARP_H_ */