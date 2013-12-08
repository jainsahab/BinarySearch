#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_to_search_3_in_the_array_of_1_2_3");
	setup();
		test_to_search_3_in_the_array_of_1_2_3();
	tearDown();
	testEnded();
	testStarted("test_to_search_5_in_the_array_of_1_2_3_4_5");
	setup();
		test_to_search_5_in_the_array_of_1_2_3_4_5();
	tearDown();
	testEnded();
	testStarted("test_to_search_1_in_the_array_of_1_2_3_4_5");
	setup();
		test_to_search_1_in_the_array_of_1_2_3_4_5();
	tearDown();
	testEnded();
	testStarted("test_to_find_value_which_is_not_present");
	setup();
		test_to_find_value_which_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_to_search_3_in_the_array_of_1_2_3_4_5");
	setup();
		test_to_search_3_in_the_array_of_1_2_3_4_5();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
