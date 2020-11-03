#include <stdio.h>
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"
#define MAX_M 100
#define MAX_N 100
#define FIRE_MAX MAX_M*MAX_N
#define false 0
#define true 1

typedef int BOOL;

int M,N,X;
int Building[MAX_M][MAX_N], Path[MAX_M][MAX_N];
int path[MAX_M][MAX_N];
char dir[5]={' ', 'U', 'L', 'R', 'D'};
int res_n, res_y, res_x;
char res[FIRE_MAX];
BOOL found;
int stx, sty;
int myQueue[FIRE_MAX][2];
int rear, front;