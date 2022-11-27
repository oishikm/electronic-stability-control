/*
 * Core Physics Engine definitions
 * 
 * Oishik Mukhopadhyay | 20 November 2022
 */

#pragma once
#include "libesc.h"
#include "librie.h"
#include "libese.h"

vector_3d* calculate_target_vector(point_3d* start, point_3d* finish, float target_time)
{
    float delta_x, delta_y, delta_z;
    delta_x = (finish->x) - (start->x);
    delta_y = (finish->y) - (start->y);
    delta_z = (finish->z) - (start->z);
    vector_3d* target_vector = (vector_3d*)malloc(sizeof(vector_3d));
    target_vector->i = delta_x/target_time;
    target_vector->j = delta_y/target_time;
    target_vector->k = delta_z/target_time;
    printf("\n[INFO] Vehicle will have target vector : ");
    display_vector(target_vector);
    if(target_time > 3600)        
        printf("\n[WARNING] Simulation will run for more than an hour. \n");   
    printf("\n[INFO] Simulation will run for %.2f second(s). \n", target_time);
    return target_vector;
}

void accept_correction_vector(vector_3d* correction_vector)
{
    current_vector.i += correction_vector->i;
    current_vector.j += correction_vector->j;
    current_vector.k += correction_vector->k;
    printf("\n[INFO] Received correction vector : ");
    display_vector(correction_vector);
    free(correction_vector);
}

void accept_influence_vector(vector_3d* influence_vector)
{
    current_vector.i += influence_vector->i;
    current_vector.j += influence_vector->j;
    current_vector.k += influence_vector->k;
    free(influence_vector);
}

void init_current_vector()
{
    vector_3d* temp_vector = calculate_target_vector(&start_coord, &finish_coord, target_time);
    ideal_vector.i = temp_vector->i;
    ideal_vector.j = temp_vector->j;
    ideal_vector.k = temp_vector->k;
    current_vector.i = temp_vector->i;
    current_vector.j = temp_vector->j;
    current_vector.k = temp_vector->k;
    free(temp_vector);
}