/* <Exercise 1.15> 
print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version 
*/
#include <stdio.h>

float FahrToCels(float fahrInputValue);

int main()
{
    float fahr;
    float lower, upper, step;

    lower = 0; /* lower limit of temperatuire scale */
    upper = 300; /* upper limit */
    step = 20; /* step size */
    fahr = lower;

    while (fahr <= upper) {
        FahrToCels(fahr);
        fahr = fahr + step;
    }
}

float FahrToCels(float fahrInputValue)
{
    float celsius;
    celsius = (5.0/9.0) * (fahrInputValue-32.0);
    printf("%3.0f %6.1f\n", fahrInputValue, celsius);
    return celsius;
}