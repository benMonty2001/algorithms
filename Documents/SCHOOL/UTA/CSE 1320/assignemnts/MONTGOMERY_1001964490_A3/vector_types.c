#include "vector_types.h"

void vector_add_2(vec2f a, float x, float y){
	printf("[ %.2f, %.2f ] + [ %.2f, %.2f ] = [ %.2f, %.2f ]\n", a[0], a[1], x, y, a[0] + x, a[1] + y);
}
void vector_add_3(vec3f b, float x, float y, float z){
	printf("[ %.2f, %.2f, %.2f ] + [ %.2f, %.2f, %.2f ] = [ %.2f, %.2f, %.2f]\n", b[0], b[1], b[2], x, y, z, b[0] + x, b[1] + y, b[2] + z);
}
void vector_add_4(vec4f c, float w, float x, float y, float z){
	printf("[ %.2f, %.2f, %.2f, %.2f ] + [ %.2f, %.2f, %.2f, %.2f ] = [ %.2f, %.2f, %.2f, %.2f ]\n", c[0], c[1], c[2], c[3], w, x, y, z, c[0] + w, c[1] + x, c[2] + y, c[3] + z);
}

void scalar_mult_2(vec2f a, float x){
	printf("%.2f * [ %.2f, %.2f ] = [ %.2f, %.2f ]\n", x, a[0], a[1], a[0] * x, a[1] * x);
}

void scalar_mult_3(vec3f b, float y){
	printf("%.2f * [ %.2f, %.2f, %.2f ] = [ %.2f, %.2f, %.2f ]\n", y, b[0], b[1], b[2], b[0] * y, b[1] * y, b[2] * y);
}

void scalar_mult_4(vec4f c, float z){
	printf("%.2f * [ %.2f, %.2f, %.2f, %.2f ] = [ %.2f, %.2f, %.2f, %.2f ]\n", z, c[0], c[1], c[2], c[3], c[0] * z, c[1] * z, c[2] * z, c[3] * z);
}

int main(){
	vec2f a = { 1, 2 };
	vec3f b = { 1, 2, 3 };
	vec4f c = { 1, 2, 3, 4 };

	float w = 2, x = 3, y = 5, z = 8;

	printf("For vec2f...\n");
	vector_add_2(a, x, y);
	scalar_mult_2(a, x);
	printf("...\n");

	printf("For vec3f...\n");
	vector_add_3(b, x, y, z);
	scalar_mult_3(b, y);
	printf("...\n");


	printf("For vec4f...\n");
	vector_add_4(c, w, x, y, z);
	scalar_mult_4(c, z);
	printf("...\n");

	return 0;
}