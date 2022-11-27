#include "../include/libcpe.h"

int main()
{
    float current_timer = 0.0;
    init_current_vector();
    while(current_timer < target_time)
    {
        current_timer += simulate_clock_pulse();
        accept_influence_vector(generate_influence_vector());
        printf("\n[TIME] %.1f s", current_timer);
        accept_correction_vector(calculate_correction_vector(&current_vector, &ideal_vector));        
    }
    printf("\n[INFO] Simulation completed successfully.\n");
    return 0;
}