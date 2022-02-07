#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.141592654

float is_overlap(int x_1, int y_1, int r_1, int x_2, int y_2, int r_2){
	
	//determine if circles are intersecting

	int d_x = abs(x_1 - x_2);
	int d_y = abs(y_1 - y_2);
	float d_centers = 0;

	int intersecting = 0;

	if(d_x != 0 && d_y != 0){
		d_centers = sqrt((d_x * d_x) + (d_y *d_y));
	} else if(d_x == 0 && d_y != 0){
		d_centers = d_y;
	} else if(d_x != 0 && d_y == 0){
		d_centers = d_x;
	}

	if((r_1 + r_2) >= d_centers){
		intersecting = 1;
	} else {
		intersecting = 0;
	}

	//calculate area of intersection

	float angle_c = 2 * acos((pow(r_2, 2) - pow(r_1, 2) - pow(d_centers, 2))/(-2 * r_1 * d_centers));
	float angle_b = 2 * acos((pow(r_1, 2) - pow(r_2, 2) - pow(d_centers, 2))/(-2 * r_2 * d_centers));
	float S_1 = (0.5 * pow(r_1, 2) * (angle_c - sin(angle_c)));
	float S_2 = (0.5 * pow(r_2, 2) * (angle_b - sin(angle_b)));
	float area_intersection = S_1 + S_2;

	//calculate area of smallest circle

	int smallest_r = 0;
	int equal_r = 0;

	if(r_1 < r_2){
		smallest_r = r_1;
	} else if(r_1 > r_2){
		smallest_r = r_2;
	} else {
		equal_r = 1;
	}

	float smallest_area = (PI * smallest_r * smallest_r);
	float equal_area = (PI * equal_r * equal_r);

	//Conclusion

	if(intersecting == 1 && area_intersection == smallest_area){
		return area_intersection;
	} else if(intersecting == 1 && area_intersection == equal_area){
		return area_intersection;
	} else if(intersecting == 1 && area_intersection == 0){
		return area_intersection;
	} else if(intersecting == 1 && isnan(area_intersection)){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	int x_1 = 0, y_1 = 0, r_1 = 0, x_2 = 0, y_2 = 0, r_2 = 0;

	int circle_1 = 0;
	int circle_2 = 0;

	while(circle_1 == 0){
		printf("Enter circle 1 parameters (x y radius): ");
		int check_1 = scanf("%d %d %d", &x_1, &y_1, &r_1);
		while(getchar() != '\n');
			
		if (check_1 != 3){
			printf("incorrect input! Try again!\n");
		} else {
			circle_1 = 1;
		}
	}

	while(circle_2 == 0){

		printf("Enter circle 2 parameters (x y radius): ");
		int check_2 = scanf("%d %d %d", &x_2, &y_2, &r_2);
		while(getchar() != '\n');

		if (check_2 != 3){
			printf("incorrect input! Try again!\n");
		} else {
			circle_2 = 1;
		}
	}

	if(is_overlap(x_1, y_1, r_1, x_2, y_2, r_2)){
		printf("Overlap detected!\n");
	} else {
		printf("No overlap detected!\n");
	}
}