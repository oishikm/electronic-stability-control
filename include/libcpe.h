/*
 * Core Physics Engine definitions
 * 
 * Oishik Mukhopadhyay | 20 November 2022
 */

#include"libesc.h"

vector_3d* calculate_target_velocity(point_3d* start, point_3d* finish, float target_time)
{
    float delta_x, delta_y, delta_z, total_displacement;
    delta_x = (finish->x) - (start->x);
    delta_y = (finish->y) - (start->y);
    delta_z = (finish->z) - (start->z);
    total_displacement = sqrt(pow(delta_x,2) + pow(delta_y,2) + pow(delta_z,2));
    vector_3d* target_velocity = (vector_3d*)malloc(sizeof(vector_3d));
    target_velocity->i = delta_x/target_time;
    target_velocity->j = delta_y/target_time;
    target_velocity->k = delta_z/target_time;
    printf("\n[INFO] Vehicle will have target velocity : %fi + %fj + %fk", 
            target_velocity->i, target_velocity->j, target_velocity->k);
    if(target_time > 3600)        
        printf("\n[WARNING] Simulation will run for more than an hour.");   
    printf("\n[INFO] Simulation will run for %f seconds.", target_time);
    return target_velocity;
}