/*
 * Random Influence Engine definitions
 * 
 * Oishik Mukhopadhyay | 20 November 2022
 */

#pragma once
#include <time.h>
#include "libesc.h"
#include "temp/cpe.h"
#include "temp/rie.h"

vector_3d* generate_influence_vector()
{
    srand(time(0));
    vector_3d* influence_vector = (vector_3d*)malloc(sizeof(vector_3d));
    int sign_x = pow(-1, rand()%3 + 1);
    int sign_y = pow(-1, rand()%3 + 1);
    int sign_z = pow(-1, rand()%3 + 1);
    float x = sign_x * ((float)rand()/RAND_MAX) * strength;
    float y = sign_y * ((float)rand()/RAND_MAX) * strength;
    float z = sign_z * ((float)rand()/RAND_MAX) * strength;
    influence_vector->i = x;
    influence_vector->j = y;
    influence_vector->k = z;
    return influence_vector;
}