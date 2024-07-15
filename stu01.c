/*

	A TESTU01 tester ingesting data from stdin.

	Rafael Alvarez (c) 2015

*/


/* headers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>


//#include <unif01.h>
#include <bbattery.h>
#include <sknuth.h>

/* constants */


/* data types */

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t  u8;

/* globals */

/* prototypes */

unsigned int GenP2(void);
void MainUsage();
void MainSCrush();
void MainMCrush();
void MainBCrush();
void MainBRabbit();
void MainBAlphabit();

int main(int argc, char *argv[])
{



	if(argc<2) MainUsage();	// print message if no targets given
	else {
		for(int i=1; i<argc; i++) {
			for(int j=0; j<strlen(argv[i]); j++) {	// make lower case
				argv[i][j] = tolower(argv[i][j]);
			}

			if(strcmp(argv[i],"scrush")==0)	// small crush
				MainSCrush();
			else if(strcmp(argv[i],"mcrush")==0)	// medium crush
				MainMCrush();
			else if(strcmp(argv[i],"bcrush")==0)	// big crush
				MainBCrush();
			else if(strcmp(argv[i],"rabbit")==0)	// rabbit
				MainBRabbit();
			else if(strcmp(argv[i],"alphabit")==0)	// alphabit
				MainBAlphabit();
			else {
				printf("\nUnrecognized target '%s' \n",argv[i]);
				MainUsage();
			}
		}
	}

	return 0;
}

void MainUsage() {
	printf("\n\nstu01 (c) Rafael Alvarez\n");
	printf("\nUsage: tu01 target1 target2 ... targetn\n");
	printf("\nWhere target can be:\n\n");
	printf("scrush \t small crush (testu01)\n");
	printf("mcrush \t medium crush (testu01)\n");
	printf("bcrush \t big crush (testu01)\n");
	printf("rabbit \t rabbit (testu01)\n");
	printf("alphabit \t alphabit (testu01)\n");
	printf("\n\n");
	exit(1);
}



void MainSCrush() {
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits("GenP2", GenP2);
	bbattery_SmallCrush(gen);
	unif01_DeleteExternGenBits(gen);
}

void MainMCrush() {
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits("GenP2", GenP2);
	bbattery_Crush(gen);
	unif01_DeleteExternGenBits(gen);
}

void MainBCrush() {
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits("GenP2", GenP2);
	bbattery_BigCrush(gen);
	unif01_DeleteExternGenBits(gen);
}

void MainBRabbit() {
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits("GenP2", GenP2);
	bbattery_Rabbit(gen,100000);
	unif01_DeleteExternGenBits(gen);
}

void MainBAlphabit() {
	unif01_Gen *gen;
	gen = unif01_CreateExternGenBits("GenP2", GenP2);
	bbattery_Alphabit(gen,1000000,0,32);
	unif01_DeleteExternGenBits(gen);
}

unsigned int gV;

unsigned int GenP2()
{
	fread(&gV, 4, 1, stdin);
	printf("%x\t", gV);
	return gV;
}
