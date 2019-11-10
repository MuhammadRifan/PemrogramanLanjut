#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	double arr[3][3][3] = { // lintasan
							{ // titik
								{2,3,1}, {3,5,4}, {6,3,5} // koordinat
							}, 
							
							{
								{2,-3,4}, {4,-9,10}, {8,-3,4}
							}, 
							
							{
								{3,5,-6}, {-4,7,8}, {9,1,-2}
							} 
						};
	
	int arr2[2][2][4] = {{{0,3,5,6}, {7,10,11,2}}, {{3,6,7,0}, {16,20,11,8}}};
	
	int x,y,z;
	double jarak, jatik;
	for (x=0; x<3; x++) {
		jatik = 0;
		printf("Lintasan %d:\n", x+1);
		printf("+---------------------------+\n");
		
		for (y=0; y<3; y++) {
			printf("Titik %d: ", y+1);
			jarak = 0;
			
			for (z=0; z<3; z++) {
				printf(" %.f", arr[x][y][z]);
				if (y < 2) {
					jarak = jarak + pow(arr[x][y+1][z]-arr[x][y][z],2);
				}
			}
			jatik = jatik + sqrt(jarak);
			printf("\n");
			
		}
		
		printf("+---------------------------+\n");
		printf("Jarak = %.2f\n\n", jatik);
	}

	return 0;
}
