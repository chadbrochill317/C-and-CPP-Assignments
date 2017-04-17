/*# Start of file merge.c */

/*# MIPSMARK 1.0 1/5/98 Copyright 1998 J. Waldron. */

/*  	Write a C function to merge 2 arrays, assumed to be ordered by ascending values,
	and store the result in a 3rd array, so it in turn is ordered.
    Follow the function prototype given above the cut line.
	Put your entire function between thge cut lines	*/
/*# Output format must be:		*/
/*# "/-1/1/2/2/3/4/7/8/11"		*/
#include <stdio.h>       /* for printf in C programs */
#include <stdlib.h>	 /* for exit() in C programs */


#define LEN1	4
#define LEN2	5

int* merge (const int[], int , const int[], int); //allocates and returns an arrray

int main() {
  int a[LEN1] = {1,2,3,8};
  int b[LEN2] = {-1,2,4,7,11};
  int* m;	// to hold pointer to merged arrayy,  should free
  int* mp;	// point to successive result elements

  m = merge( a, LEN1, b, LEN2);
  mp = m;
  for (int i=0; i<LEN1+LEN2; i++)
     printf ("/%d",*mp++);
  free(m);
  printf("\n");
  return 0;
}


/* Any changes above this line will be discarded by
 mipsmark. Put your answer between dashed lines. */
/*-------------- start cut ----------------------- */

/*  Student's Name:	Samuel Essery 2130654	*/

void merge (const int a, int m, const int b, int n, int sorted []) {
    int i;
    int j;
    int k;
    m = LEN1;
    n = LEN2;
    j = k = 0;

    for (i=0; i < m + n;){
        if (j < m && k < m){
            if (a[j] < b[k]) {
                sorted[i] = a[j];
                j++;
            }else {
                sorted[i] = b[k];
                k++;
            }
            i++;
        }else if (j == m;) {
            for (i < m + n){
                sorted[i] = b[k];
                k++;
                i++;
            }
        }else {
            for (; i < m + n;) {
                sorted[i] = a[j];
                j++;
                i++;
            }
        }
    }
}

/*--------------  end cut  -----------------------
# Any changes below this line will be discarded by
# mipsmark. Put your answer between dashed lines.

   End of file merge.c		*/
