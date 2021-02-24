/*
 *
 *
 * 32-bit machine.

little endian, the x in the memory will be something like:

       higher memory
          ----->
    +----+----+----+----+
    |0x01|0x00|0x00|0x00|
    +----+----+----+----+
    A
    |
   &x

so (char*)(&x) == 1, and *y+48 == '1'.

big endian, it will be:

    +----+----+----+----+
    |0x00|0x00|0x00|0x01|
    +----+----+----+----+
    A
    |
   &x
 *
 * so  x = '0'.
*/

#include <stdio.h>

int end_tst();
int end_check();
int end_end();

int main() {
  int x = 1;
  int ans = -99;

  char *y = (char*)&x;

  printf("%c\n",*y+48);
  ans = *y+48;

  printf("endian == %c, %d\n", ans, ans);
  if (ans == 1) printf("little endian == %c, %d\n", ans, ans);
  if ((*y+48) == 0) printf("big    endian == %c, %d\n", ans, ans);
  else  printf("NOT big endian == %c, %d\n", ans, ans);
  if (ans) printf("little endian == %c, %d\n", ans, ans);

  ans = end_tst();
  ans = end_check();
  ans = end_end();
  return ans;
}

/*
int x = 0x76543210;
char *c = (char*) &x;

Big endian format:
------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
              +++++++++++++++++++++++++++++
Byte content  | 0x76 | 0x54 | 0x32 | 0x10 |
			 
Little endian format:
---------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
              +++++++++++++++++++++++++++++
Byte content  | 0x10 | 0x32 | 0x54 | 0x76 |
*/

int end_tst()
{
  unsigned int x = 0x76543210;
  char *c = (char*) &x;

  printf ("*c is: 0x%x\n", *c);
  if (*c == 0x10)
    printf ("Underlying architecture is little endian. \n");
  else
    printf ("Underlying architecture is big endian. \n");

  return 0;
}



int check_for_endianness()
{
  unsigned int x = 1;
  char *c = (char*) &x;
  return (int)*c;
}

int end_check()
{
    if (check_for_endianness())
	    printf("architecture is little endian. \n");
    else
	    printf("architecture is big endian. \n");

    return 0;
}


#define LITTLE_ENDIAN 0
#define BIG_ENDIAN    1

int endian() {
    int i = 1;
    char *p = (char *)&i;

    if (p[0] == 1)
        return LITTLE_ENDIAN;
    else
        return BIG_ENDIAN;
}

int end_end()
{
	if (endian() == LITTLE_ENDIAN)
		printf("endianess == LITTLE_ENDIAN\n");
	else if (endian() == BIG_ENDIAN)
		printf("endianess == BIG_ENDIAN\n");

	return 0;
}
