/*
 * Library definitions
 * 
 * Oishik Mukhopadhyay | 20 November 2022
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

typedef struct _vector_3d {
    float i, j, k;
} vector_3d;

typedef struct _point_3d {
    float x, y, z;
} point_3d;

vector_3d ideal_vector;
vector_3d current_vector;

void display_vector(vector_3d* vector)
{
    char sign_i = '+', sign_j = '+', sign_k = '+';
    if(vector->i < 0)
    {
        sign_i = '-';
        vector->i *= -1;
    }
    if(vector->j < 0)
    {
        sign_j = '-';
        vector->j *= -1;
    }
    if(vector->k < 0)
    {
        sign_k = '-';
        vector->k *= -1;
    }
    printf("%c(%.3f)i %c(%.3f)j %c(%.3f)k \n", sign_i, vector->i, sign_j, vector->j, sign_k, vector->k);
}

int simulate_clock_pulse()
{
    int pulse_duration = 1;
    sleep(pulse_duration);
    return pulse_duration;
}