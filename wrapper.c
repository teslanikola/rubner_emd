#include <stdio.h>
#include <math.h>
//#include "emd.h"
#include "HelloJNIWMD.h"

double euclideanDist(double *x, double *y,int length) {

	double output = 0.0;
	for(int i=0;i<length;i++) {
		double xVal = *(x+i);
		double yVal = *(y+i); 
		double sq = (xVal-yVal)*(xVal-yVal);
		output+=sq;
	}

	return sqrt(output);
}

JNIEXPORT jdouble JNICALL Java_HelloJNIWMD_computeDistance
  (JNIEnv *env, jobject obj, jdoubleArray w1, jdoubleArray w2, jobjectArray dist) {

  	jint w1Size = (*env)->GetArrayLength(env,w1);
  	jint w2Size = (*env)->GetArrayLength(env,w2);

  	jboolean isCopy1;

     //double* distPtr  = (*env)->GetDoubleArrayElements(env,dist,&isCopy1);

  	jint width = (*env)->GetArrayLength(env, dist);
  	for(int i=0;i<width;i++) {
  		jdoubleArray *line =   (*env)->GetObjectArrayElement(env, dist, i);
  		int height = (*env)->GetArrayLength(env, line);
  		jdouble *pos = (*env)->GetDoubleArrayElements(env, line, 0);
  		for(int j=0;j<height;j++) {
  			printf("Element at position%d,%d,=%f\n",i,j,*(pos+j));
  		}
  	}

  	return 0.0;
  }

/*int main() {
	double w1[5] = { 0.4, 0.2, 0.2, 0.1, 0.1 },
              w2[5] = { 0.6, 0.2, 0.1, 0.2,0.2 };
    double ed = euclideanDist(w1,w2,5);
    printf("Eucledian Distance = %f\n", ed);
}*/