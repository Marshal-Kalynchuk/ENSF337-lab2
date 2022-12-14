/*
 * File Name: lab2exe_A.c
 * Assignment: Lab 2 Exercise A
 * Lab section: B02
 * Completed by: Marshal Kalynchuk
 * Development Date: Sept 27, 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    return 0;
}
void create_table(double v) {
    printf("| Angle |   Time    | Distance  |\n");
    printf("| (deg) |   (sec)   | (meters)  |\n");
    for (int i = 0; i <= 90; i+=5) {
        printf("|  %3d  |%10lf |%10lf |\n", i, Projectile_travel_time(i, v), Projectile_travel_distance(i, v));
    }
}

double degree_to_radian(double d) {
    return d * PI / 180;
}

double Projectile_travel_distance(double a, double v) {
    return (v * v / G) * sin(2 * degree_to_radian(a));
}

double Projectile_travel_time(double a, double v) {
    return (2 * v * sin(degree_to_radian(a))) / G;
}

/* UNCOMMENT THE CALL TO THE create_table IN THE main FUNCTION, AND COMPLETE THE PROGRAM */
