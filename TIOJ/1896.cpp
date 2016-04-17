#include "lib1896.h"

int c[1500];
void initialize(int n){
    for (int i=0 ;i<n ;i++ )c[i]=0 ;
}

int hasEdge(int u , int v ){
    return ++c[ u>v?u:v ] == (u>v?u:v) ;
}
