/*
 * Electronic Stability Engine definitions
 * 
 * Oishik Mukhopadhyay | 20 November 2022
 */

#include"libesc.h"

vector_3d* calculate_correction_vector(vector_3d* current, vector_3d* ideal)
{
    float delta_i, delta_j, delta_k, total_delta;
    delta_i = (ideal->i) - (current->i);
    delta_j = (ideal->j) - (current->j);
    delta_k = (ideal->k) - (current->k);
    total_delta = sqrt(pow(delta_i,2) + pow(delta_j,2) + pow(delta_k,2));
    vector_3d* correction_vector = (vector_3d*)malloc(sizeof(vector_3d));
    correction_vector->i = delta_i;
    correction_vector->j = delta_j;
    correction_vector->k = delta_k;
    if(total_delta > 0.001)
        printf("\n[INFO] ESControl Engine found delta : %f", total_delta);
    return correction_vector;
}