#include "testUtils.h"
#include "bSearchLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int compareInt(void* key,void* element){
	int result;
	if ( *(int*)key <  *(int*)element ) result = -1;
  	if ( *(int*)key == *(int*)element ) result = 0;
  	if ( *(int*)key >  *(int*)element ) result = 1;
  	return result;
}

int compareFloat(void* key,void* element){
	int result;
	if ( *(float*)key <  *(float*)element ) result = -1;
  	if ( *(float*)key == *(float*)element ) result = 0;
  	if ( *(float*)key >  *(float*)element ) result = 1;
  	return result;
}

int compareDouble(void* key,void* element){
	int result;
	if ( *(double*)key <  *(double*)element ) result = -1;
  	if ( *(double*)key == *(double*)element ) result = 0;
  	if ( *(double*)key >  *(double*)element ) result = 1;
  	return result;
}

void test_to_search_3_in_the_array_of_1_2_3(){
	int arr[3]={1,2,3};
	int key=3;
	ASSERT(3==*(int*)binarySearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compareInt));
	ASSERT(&arr[2] == binarySearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compareInt));
}

void test_to_search_5_in_the_array_of_1_2_3_4_5(){
	int arr[]={1,2,3,4,5};
	int key=5;
	ASSERT(5==*(int*)binarySearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compareInt));
}

void test_to_search_1_in_the_array_of_1_2_3_4_5(){
	int arr[]={1,2,3,4,5};
	int key=1;
	ASSERT(1==*(int*)binarySearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compareInt));
}

void test_to_find_value_which_is_not_present(){
	int arr[]={1,2,3,4,5};
	int key=7;
	ASSERT(NULL==(int*)binarySearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compareInt));
}

void test_to_search_3_in_the_array_of_1_2_3_4_5(){
	int arr[]={1,2,3,4,5};
	int key=3;
	ASSERT(3==*(int*)binarySearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compareInt));
}