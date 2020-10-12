
#include "unity.h"
#include "trainticketreservationsystem.h"
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_enterchoice(void)
{
  TEST_ASSERT(enterchoice(1));
}
   
int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_enterchoice);
  
  
  
 
  
  


  /* Close the Unity Test Framework */
  return UNITY_END();
}
