/*
	Ethan Lawrence
	Yony Rober
	CmpSc 472, Spring 2026
	This program will open a file and write binary data into it.
	Ethan Lawrence is doing the WriteBinary. Yony Rober is doing the ReadBinary.
    */

#include <stdio.h>
#include <stdbool.h>
#include "LawrenceRober_BinaryIO.h"

int main(void) {
	/* Objectives
		Create a file. If it exists, scrub the old file.
		Have 1 integer, 1 float, 1 double, 1 bool, 1 char array
		Insert this data into the file
		Display the file name and its contents line by line
	*/ 

	// Overwrites the file or makes it.
    FILE *fp = fopen("C:/Temp/RoberLawrence_Data.bin", "wb");

	printf("File Name: RoberLawrence_Data.bin\n");
	printf("File Path: C:/Temp/RoberLawrence_Data.bin\n");
	printf("--------------------------------------------------\n"); 

	struct someFileData thisFileData;

	int i;

	/* Legacy Code
	int temp;

	printf("Type an integer and press enter: \t");
	scanf("%d", &thisFileData.myInt);
	// printf("Received: %d\n",thisFileData.myInt);

	printf("Type a float and press enter: \t");
	scanf("%f", &thisFileData.myFloat);
	// printf("Received: %f\n",thisFileData.myFloat);

	printf("Type an double and press enter: \t");
	scanf("%lf", &thisFileData.myDouble);
	// printf("Received: %f\n",thisFileData.myDouble);

	printf("Type an bool and press enter: \t");
	scanf("%d", &temp);
	thisFileData.myBool = temp;
	// printf("Received: %d\n",thisFileData.myBool);

	printf("Type a string and press enter: \t");
	scanf("%s", thisFileData.myChar);
	// printf("Received: %s\n", thisFileData.myChar); */

	// 5 Records
	for (i = 1; i <= 5; i++) {
		thisFileData.myInt = i * 2;
		thisFileData.myFloat = i * 1.42f;
		thisFileData.myDouble = i * 7.6543;
		thisFileData.myBool = (i % 2 == 0);
		sprintf(thisFileData.myChar, "Record-%d\n------------------\n", i);

		// Writes all of the Received Data
		fwrite(&thisFileData, sizeof(thisFileData), 1, fp); 

		printf("Received Inputs: %d\n%f\n%f\n%d\n%s\n",
	    	thisFileData.myInt, thisFileData.myFloat, thisFileData.myDouble,
	 		thisFileData.myBool, thisFileData.myChar);
	}

	fclose(fp);

    return 1;
}
