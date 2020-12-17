/*
 * Program to implement a scientific calculator
 * ********************************************
 * Author	Dept.		Date		Notes
 * Jerry Xia	Soft. Eng.	Nov 2 2020	Included comment section.
 * Jerry Xia	Soft. Eng.	Nov 5 2020	Initial draft.
 * Jerry Xia	Soft. Eng.	Nov 6 2020	Final draft.
 * ********************************************
 */

#include<stdio.h>

int main(int argc, char *argv[])
{

  while(1)// while true
  {
    // check number of arguments
    if(argc != 4)
    {
      printf("Error: invalid number of arguments!\n");
      printf("scalc <operand1> <operator> <operand2>\n");
      return 1;
      break;
    }
    // check if second argument is '+' char
    if(argv[2][0] != (int)'+')
    {
      printf("Error: operator can only be + !\n");
      return 1;
      break;
    }

  // gets length of first operand
  int length1 = 0;
  for (; argv[1][length1] != '\0'; length1++);

  // accounts for integers only for first operand
  int counter1 = 0;
  int thiscount1 = 0;
  for(; counter1 < length1; counter1++)
  {
    if(argv[1][counter1] == '.')
      break;
    if(argv[1][counter1] != '.')
      thiscount1++;
    if(argv[1][counter1] == '\0')
      break;
  }

  // gets length of second operand
  int length2 = 0;
  for (; argv[3][length2] != '\0'; length2++);

  // accounts for integers only for second operand
  int counter2 = 0;
  int thiscount2 = 0;
  for(; counter2 < length2; counter2++)
  {
    if(argv[3][counter2] == '.')
      break;
    if(argv[3][counter2] != '.')
      thiscount2++;
    if(argv[3][counter2] == '\0')
      break;
  }

  //checks if both are integers
  if(thiscount1 != length1 || thiscount2 != length2)
  {
    printf("Error!! operand can only be positive integers\n");
    return 1;
    break;
  }

  // creates char arrays with appropriate lengths
  long arr1[1000];
  long arr2[1000];

  // puts args from argv[1] into arr1[] as integers
  int i = 0;
  for(; i < length1; i++)
        arr1[i]=argv[1][i]-'0';

  // puts args from argv[3] into arr2[] as integers
  int j = 0;
  for(; j < length2; j++)
        arr2[j]=argv[3][j]-'0';

int sum[1000];

  // START
  if(length1 > length2)
  {
    int x = 0;
    int carry1 = 0;
    for(; x < length2; x++)
    {
      //tmp_sum is reset every time (WORKS)
      int tmp_sum=arr1[length1-x-1]+arr2[length2-x-1]+carry1;
      int carry = (arr1[length1-x-1]+arr2[length2-x-1])/10;
      if(carry <= 0) carry1 = 0;
      if(carry > 0) carry1 = 1;
      sum[1000-x-1]=tmp_sum%10;

    }

    int y = 0;
    for(; y < length1-x-1; y++)
    {
      int tmp_sum=arr1[length1-x-1-y]+carry1;
      int carry = tmp_sum/10;
      if(carry <= 0) carry1 = 0;
      if(carry > 0) carry1 = 1;
      sum[1000-x-y-1]=tmp_sum%10;
    }
    if((arr1[length1-x-y-1]+carry1)==10)
    {
      sum[1000-x-y-1]=10;
      int f = 0;
      for(; f < length1; f++) printf("%d",sum[1000-x-y-1+f]);
      printf("\n");
      return 0;
      break;
    }
    else
    {
      sum[1000-x-y-1]=(arr1[length1-x-y-1]+carry1);
      int q = 0;
      for(; q < length1; q++) printf("%d", sum[1000-1-x-y+q]);
      printf("\n");
      return 0;
      break;
    }
  }

  if(length1 < length2)
  {
    int x = 0;
    int carry1 = 0;
    for(; x < length1; x++)
    {
      int tmp_sum=arr1[length1-x-1]+arr2[length2-x-1]+carry1;
      int carry = (arr1[length1-x-1]+arr2[length2-x-1])/10;
      if(carry <= 0) carry1 = 0;
      if(carry > 0) carry1 = 1;
      sum[1000-x-1]=tmp_sum%10;
    }

    int y = 0;
    for(; y < length2-x-1; y++)
    {
      int tmp_sum=arr2[length2-x-1-y]+carry1;
      int carry = tmp_sum/10;
      if(carry <= 0) carry1 = 0;
      if(carry > 0) carry1 = 1;
      sum[1000-x-y-1]=tmp_sum%10;
    }
    if((arr2[length2-x-y-1]+carry1)==10)
    {
      sum[1000-x-y-1]=10;
      int f = 0;
      for(; f < length2; f++) printf("%d",sum[1000-x-y-1+f]);
      printf("\n");
      return 0;
      break;
    }
    else
    {
      sum[1000-x-y-1]=(arr2[length2-x-y-1]+carry1);
      int q = 0;
      for(; q < length2; q++) printf("%d", sum[1000-1-x-y+q]);
      printf("\n");
      return 0;
      break;
    }

  }

if(length1==length2)
  {
    int x = 0;
    int carry1 = 0;
    //if less than any length
    for(; x < length2-1; x++)
    {
      int tmp_sum=arr1[length1-x-1]+arr2[length2-x-1]+carry1;
      int carry = (arr1[length1-x-1]+arr2[length2-x-1])/10;
      if(carry <= 0) carry1 = 0;
      if(carry > 0) carry1 = 1;
      sum[1000-x-1]=tmp_sum%10;
    }
    if((arr1[length1-x-1]+arr2[length2-x-1]+carry1)==10)
    {
      sum[1000-x-1]=10;
      int f = 0;
      for(; f < length2; f++) printf("%d",sum[1000-x-1+f]);
      printf("\n");
      return 0;
      break;
    }
    else
    {
      sum[1000-x-1]=(arr1[length1-x-1]+arr2[length2-x-1]+carry1);
      int q = 0;
      for(; q < length2; q++) printf("%d", sum[1000-1-x+q]);
      printf("\n");
      return 0;
      break;
    }
  }
  }
}
