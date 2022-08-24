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

// checking for longestString("Football", "Cricket")
void test_longestString_0(void)
{
	CU_ASSERT_EQUAL(longestString("Football", "Cricket"), "Football");
}

// checking for longestString("Carrom", "Chess")
void test_longestString_1(void)
{
	CU_ASSERT_EQUAL(longestString("Carrom", "Chess"), "Carrom");
}

// checking for longestString("Ford", "Suzuki")
void test_longestString_2(void)
{
	CU_ASSERT_EQUAL(longestString("Ford", "Suzuki"), "Suzuki");
}

// checking for longestString("Yamaha", "Kawasaki")
void test_longestString_3(void)
{
	CU_ASSERT_EQUAL(longestString("Yamaha", "Kawasaki"), "Kawasaki");
}

// checking for longestString("Table-Tennis", "Badminton")
void test_longestString_4(void)
{
	CU_ASSERT_EQUAL(longestString("Table-Tennis", "Badminton"), "Table-Tennis");
}

// checking for longestString("Android", "IOS")
void test_longestString_5(void)	
{
	CU_ASSERT_EQUAL(longestString("Android", "IOS"), "Android");
}

// checking for longestString("Mobile", "Tab")
void test_longestString_6(void)
{
	CU_ASSERT_EQUAL(longestString("Mobile", "Tab"), "Mobile");
}

// checking for longestString("Sports", "Athletics")
void test_longestString_7(void)
{
	CU_ASSERT_EQUAL(longestString("sports", "Athletics"), "Athletics");
}

// checking for longestString("Suzuki", "Mercedes")
void test_longestString_8(void)
{
	CU_ASSERT_EQUAL(longestString("Suzuki", "Mercedes"), "Mercedes");
}

int main()
{
	int arr[]={0,0,0,0,0};

	int min = getMin(arr, sizeof(arr)/sizeof(arr[0]));
	int max = getMax(arr, sizeof(arr)/sizeof(arr[0]));

	printf("\n min:%d max:%d\n", min, max);

	CU_initialize_registry();
	CU_pSuite longestStringSuite = CU_add_suite("longestString", NULL, NULL);
	CU_add_test(longestStringSuite, "longestString('Football', 'Cricket')",test_longestString_0);
	CU_add_test(longestStringSuite, "longestString('Carrom', 'Chess')",test_longestString_1);
	CU_add_test(longestStringSuite, "longestString('Ford', 'Suzuki')",test_longestString_2);
	CU_add_test(longestStringSuite, "longestString('Yamaha', 'Kawasaki')",test_longestString_3);
	CU_add_test(longestStringSuite, "longestString('Table-Tennis', 'Badminton')",test_longestString_4);
	CU_add_test(longestStringSuite, "longestString('Android', 'IOS')",test_longestString_5);
	CU_add_test(longestStringSuite, "longestString('Mobile', 'Tab')",test_longestString_6);
	CU_add_test(longestStringSuite, "longestString('sports', 'Athletics')",test_longestString_7);
	CU_add_test(longestStringSuite, "longestString('Suzuki', 'Mercedes')",test_longestString_8);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return 0;

}
