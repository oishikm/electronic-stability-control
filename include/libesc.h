/*
 * Library definitions
 * 
 * Oishik Mukhopadhyay | 20 November 2022
 */

#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _vector_3d {
    float i, j, k;
} vector_3d;

typedef struct _point_3d {
    float x, y, z;
} point_3d;

vector_3d current_vector;