#include <stdio.h>

int main() {

    float dKm, dMeters, dFeet, dInches, dCm;

    printf("Enter the distance between two locations (in kilometers): ");
    scanf("%f", &dKm);

    dMeters = dKm * 1000;
    dCm = dMeters * 100;
    dFeet = dKm * 3280.84;
    dInches = dFeet * 12;

    printf("Equivalent distance in meters: %.2f m\n", dMeters);
    printf("Equivalent distance in centimeters: %.2f cm\n", dCm);
    printf("Equivalent distance in feet: %.2f ft\n", dFeet);
    printf("Equivalent distance in inches: %.2f in\n", dInches);

    return 0;
}