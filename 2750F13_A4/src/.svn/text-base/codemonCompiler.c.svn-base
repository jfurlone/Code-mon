#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "y.tab.h"
#include "labelList.h"
#include "CodeParser.h"
#include "codemonPkg4_JFurlone_A4_codemonGui.h"

int yyparse(void);
char * saveFilePath;
FILE * yyin;

JNIEXPORT jint JNICALL Java_codemonPkg4_JFurlone_A4_codemonGui_JavaLexxYaccCompile(JNIEnv * env, jobject obj, jstring filename1, jstring filename2)
{
	const char *cFilename1;
	const char *cFilename2;

	
	cFilename1 = ((*env)->GetStringUTFChars(env, filename1, NULL));
	cFilename2 = ((*env)->GetStringUTFChars(env, filename2, NULL));
	
//	printf("\nC: Filename1: %s\n", cFilename1);
//	printf("C: Filename2: %s\n\n", cFilename2);
	fflush(stdout);
	
	char * filePath1 = malloc(sizeof(cFilename1)+2000);
	saveFilePath = malloc(sizeof(cFilename2)+2000);

	strcpy(filePath1, cFilename1);
	strcpy(saveFilePath, cFilename2);
	//strcpy(saveFilePath, filePath2);
	
	yyin = fopen(filePath1, "r");
	if(yyin == NULL)
	{
		printf("wtf\n\n\n");
	}
	else
	{
	//	printf("filePath1: %s\n",filePath1);
	//	printf("saveFilePath: %s\n", saveFilePath);
		printf("retVal: %d\n",yyparse());
		//printf("HEya\n\n");
		fclose(yyin);
	}
	
	
	
//	printf("\nFile1: %s\n", filePath1);
//	printf("File2: %s\n\n", filePath2);	
//	ReadFile(filePath1, filePath2);
	
	//bitWiseOp(char *opCmd, char aMode1, unsigned int fOne, char aMode2, unsigned int fTwo, char * pathTo);
	
	

	(*env)->ReleaseStringUTFChars(env, filename1, cFilename1);
	(*env)->ReleaseStringUTFChars(env, filename2, cFilename2);
	
	free(filePath1);
	//free(saveFilePath);
	return 0;
}


JNIEXPORT jint JNICALL Java_codemonPkg4_JFurlone_A4_codemonGui_JavaCompileFile(JNIEnv * env, jobject obj, jstring filename1, jstring filename2)
{
	const char *cFilename1;
	const char *cFilename2;
	
	cFilename1 = ((*env)->GetStringUTFChars(env, filename1, NULL));
	cFilename2 = ((*env)->GetStringUTFChars(env, filename2, NULL));
	
	printf("\nC: Filename1: %s\n", cFilename1);
	printf("C: Filename2: %s\n\n", cFilename2);
	fflush(stdout);
	
	char * filePath1 = malloc(sizeof(cFilename1)+2000);
	char * filePath2 = malloc(sizeof(cFilename2)+2000);

	strcpy(filePath1, cFilename1);
	strcpy(filePath2, cFilename2);
	
//	printf("\nFile1: %s\n", filePath1);
//	printf("File2: %s\n\n", filePath2);
	
	ReadFile(filePath1, filePath2);
	printf("afterReadFile\n\n");
	(*env)->ReleaseStringUTFChars(env, filename1, cFilename1);
	(*env)->ReleaseStringUTFChars(env, filename2, cFilename2);
	printf("JString free?\n\n\n");
	
	free(filePath1);
	free(filePath2);
	return 0;
}

JNIEXPORT jint JNICALL Java_codemonPkg4_JFurlone_A4_codemonGui_JavaTestCodemon(JNIEnv * env, jobject obj, jstring codemon, jstring iteration)
{
	const char *cCodemon1;
	const char *cIteration;
	int reportID = 0;
	
	cCodemon1 = ((*env)->GetStringUTFChars(env, codemon, NULL));
	cIteration = ((*env)->GetStringUTFChars(env, iteration, NULL));
	
	
	printf("\nC: cCodemon1: %s\n", cCodemon1);
	printf("\nC: cIteration: %s\n", cIteration);
	fflush(stdout);
	
	char * filePath1 = malloc(sizeof(cCodemon1)+2000);
	char * iLimit = malloc(sizeof(cIteration)+10);

	strcpy(filePath1, cCodemon1);
	strcpy(iLimit, cIteration);
	
	reportID = ReadCodemon(filePath1, iLimit , NULL);
	//printf("Report ID %d\n",reportID);
	(*env)->ReleaseStringUTFChars(env, codemon, cCodemon1);
	(*env)->ReleaseStringUTFChars(env, iteration, cIteration);
	
	free(filePath1);
	free(iLimit);
	
	return (reportID);
}

JNIEXPORT jint JNICALL Java_codemonPkg4_JFurlone_A4_codemonGui_JavaSelfCodemon (JNIEnv * env, jobject obj, jstring codemon1, jstring codemon2, jstring iteration)
{
	const char *cCodemon1;
	const char *cCodemon2;
	const char *cIteration;
	int reportID = 0;
	
	cCodemon1 = ((*env)->GetStringUTFChars(env, codemon1, NULL));
	cCodemon2 = ((*env)->GetStringUTFChars(env, codemon2, NULL));
	cIteration = ((*env)->GetStringUTFChars(env, iteration, NULL));
	
	
	printf("\nC: cCodemon1: %s\n", cCodemon1);
	printf("\nC: cCodemon2: %s\n", cCodemon2);
	printf("\nC: cIteration: %s\n", cIteration);
	fflush(stdout);
	
	char * filePath1 = malloc(sizeof(cCodemon1)+2000);
	char * filePath2 = malloc(sizeof(cCodemon2)+2000);
	char * iLimit = malloc(sizeof(cIteration)+10);
	
	strcpy(filePath1, cCodemon1);
	strcpy(filePath2, cCodemon2);
	strcpy(iLimit, cIteration);
	
	reportID = ReadCodemon(filePath1, filePath2 , iLimit);
	//printf("Report ID %d\n",reportID);
	(*env)->ReleaseStringUTFChars(env, codemon1, cCodemon1);
	(*env)->ReleaseStringUTFChars(env, codemon2, cCodemon2);
	(*env)->ReleaseStringUTFChars(env, iteration, cIteration);
	
	free(filePath1);
	free(filePath2);
	free(iLimit);
	return (reportID);
	
}

JNIEXPORT jint JNICALL Java_codemonPkg4_JFurlone_A4_codemonGui_JavaRunPvp(JNIEnv * env, jobject obj, jstring codemon, jint pvp)
{
	const char *cCodemon1;
	int reportID = 0;
	
	cCodemon1 = ((*env)->GetStringUTFChars(env, codemon, NULL));
	
	
	printf("\nC: cCodemon1: %s\n", cCodemon1);
	fflush(stdout);
	
	char * filePath1 = malloc(sizeof(cCodemon1)+2000);

	strcpy(filePath1, cCodemon1);
	
	reportID = codemonPvp(filePath1, pvp);
	(*env)->ReleaseStringUTFChars(env, codemon, cCodemon1);
	
	free(filePath1);
	
	return (reportID);
}


JNIEXPORT jint JNICALL Java_codemonPkg4_JFurlone_A4_codemonGui_JavaGetReport(JNIEnv *env, jobject obj, jint reportID, jstring filename)
{
	const char * newFilename;
	int getReturnVal = 0;
	FILE * filePtr;
	
	newFilename = ((*env)->GetStringUTFChars(env, filename, NULL));
	filePtr = fopen(newFilename, "w+");
	
	
	printf("\nC: newFilename: %s\n", newFilename);
	fflush(stdout);
	
	//char * reportPath = malloc(sizeof(newFilename)+2000);

	//strcpy(reportPath, newFilename);
	
	getReturnVal = getReport(reportID, filePtr);
	
	fclose(filePtr);

//	printf("getReturnVal: %d\n\n", getReturnVal);
	
	return getReturnVal;
}