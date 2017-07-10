/* example2.c */

#include <stdio.h>

#include "emd.h"


float _COST[2][3] = {
  1,2,2,
  3,10,10
};

  /*float _COST[3][5] ={
    3,0,1,8,7,
    5,2,1,4,6,
    2,5,3,3,5
  };*/

float dist(feature_t *F1, feature_t *F2) { return _COST[*F1][*F2]; }

main()
{
  feature_t   f1[2] = { 0, 1 },
	      f2[3] = { 0, 1, 2 };
  float       w1[2] = { 0.6, 0.3},
              w2[3] = { 0.3, 0.3, 0.3 };
  signature_t s1 = { 2, f1, w1},
	      s2 = { 3, f2, w2};
  float       e;
  flow_t      flow[3];
  int         i, flowSize;

  e = emd(&s1, &s2, dist, flow, &flowSize);
  //e = emd(&s2, &s1, dist, flow, &flowSize);

  printf("emd=%f\n", e);
  printf("\nflow:\n");
  printf("from\tto\tamount\n");
  for (i=0; i < 3; i++)
    if (flow[i].amount > 0)
      printf("%d\t%d\t%f\n", flow[i].from, flow[i].to, flow[i].amount);
}
