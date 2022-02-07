#ifndef VECTOR_TYPES_H_
#define VECTOR_TYPES_H_

#include <stdio.h>

typedef float vec2f[2];
typedef float vec3f[3];
typedef float vec4f[4];

void vector_add_2(vec2f, float, float);
void scalar_mult_2(vec2f, float);

void vector_add_3(vec3f, float, float, float);
void scalar_mult_3(vec3f, float);

void vector_add_4(vec4f, float, float, float, float);
void scalar_mult_4(vec4f, float);

#endif//VECTOR_TYPES_H