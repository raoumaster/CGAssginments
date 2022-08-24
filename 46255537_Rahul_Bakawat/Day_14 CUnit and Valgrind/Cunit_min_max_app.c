/******************************************************************************
* File Name:min_max_app.c
* Purpose: demo code for cunit. Invokes functions getMin() and getMax()
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "min_max.h"
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"    

char* longestString(char* s1, char* s2){
    if(strlen(s1) > strlen(s2))
        return s1;
    else
        return s2;
}

// writing the test case functions

// checking for longestString("Audi", "BMW")
void test_longestString_0(void)
{
    CU_ASSERT_EQUAL(longestString("Audi", "BMW"), "Audi");
}

// checking for longestString("Chevrolet", "Ford")
void test_longestString_1(void)
{
    CU_ASSERT_EQUAL(longestString("Chevrolet", "Ford"), "Chevrolet");
}

// checking for longestString("Ferrari", "Lamborghini")
void test_longestString_2(void)
{
    CU_ASSERT_EQUAL(longestString("Ferrari", "Lamborghini"), "Lamborghini");
}

// checking for longestString("Mercedes", "Porsche")
void test_longestString_3(void)
{
    CU_ASSERT_EQUAL(longestString("Mercedes", "Porsche"), "Porsche");
}

// checking for longestString("Rolls-Royce", "Toyota")
void test_longestString_4(void)
{
    CU_ASSERT_EQUAL(longestString("Rolls-Royce", "Toyota"), "Rolls-Royce");
}

// checking for longestString("Volkswagen", "Tesla")
void test_longestString_5(void)	
{
    CU_ASSERT_EQUAL(longestString("Volkswagen", "Tesla"), "Tesla");
}

// checking for longestString("Mitsubishi", "Mazda")
void test_longestString_6(void)
{
    CU_ASSERT_EQUAL(longestString("Mitsubishi", "Mazda"), "Mitsubishi");
}

// checking for longestString("Volvo", "Maserati")
void test_longestString_7(void)
{
    CU_ASSERT_EQUAL(longestString("Volvo", "Maserati"), "Maserati");
}

// checking for longestString("Jaguar", "Land Rover")
void test_longestString_8(void)
{
    CU_ASSERT_EQUAL(longestString("Jaguar", "Land Rover"), "Land Rover");
}

int main()
{
	int arr[]={0,0,0,0,0};

	int min = getMin(arr, sizeof(arr)/sizeof(arr[0]));
	int max = getMax(arr, sizeof(arr)/sizeof(arr[0]));

	printf("\n min:%d max:%d\n", min, max);

	CU_initialize_registry();
    	CU_pSuite longestStringSuite = CU_add_suite("longestString", NULL, NULL);
    	CU_add_test(longestStringSuite, "longestString('Audi', 'BMW')",test_longestString_0);
 	CU_add_test(longestStringSuite, "longestString('Chevrolet', 'Ford')",test_longestString_1);
	CU_add_test(longestStringSuite, "longestString('Ferrari', 'Lamborghini')",test_longestString_2);
    	CU_add_test(longestStringSuite, "longestString('Mercedes', 'Porsche')",test_longestString_3);
    	CU_add_test(longestStringSuite, "longestString('Rolls-Royce', 'Toyota')",test_longestString_4);
    	CU_add_test(longestStringSuite, "longestString('Volkswagen', 'Tesla')",test_longestString_5);
    	CU_add_test(longestStringSuite, "longestString('Mitsubishi', 'Mazda')",test_longestString_6);
    	CU_add_test(longestStringSuite, "longestString('Volvo', 'Maserati')",test_longestString_7);
    	CU_add_test(longestStringSuite, "longestString('Jaguar', 'Land Rover')",test_longestString_8);
    	CU_basic_run_tests();
    	CU_cleanup_registry();
	
	return 0;

}
