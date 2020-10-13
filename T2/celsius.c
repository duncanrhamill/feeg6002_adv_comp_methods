/**
 * @file celsius.c
 * @author Duncan Hamill (duncanrhamill@googlemail.com)
 * @brief Prints a table of conversions for Celsius to Farenheit
 * @version 1.0
 * @date 2020-10-13
 * 
 * @copyright Copyright (c) Duncan Hamill 2020
 */

/* -------------------------------------------------------------------------
 * INCLUDES
 * ------------------------------------------------------------------------- */

#include <stdio.h>

/* -------------------------------------------------------------------------
 * CONSTANTS
 * ------------------------------------------------------------------------- */

/**
 * @brief The inclusive start point of the table in Celsius
 */
const int table_start_celsius = -30;

/**
 * @brief The step of the table in Celsius
 */
const int table_step_celsius = 2;

/**
 * @brief The inclusive stop point of the table in Celsisus
 */
const int table_stop_celsius = 30;

/* -------------------------------------------------------------------------
 * FUNCTION DECLARATIONS
 * ------------------------------------------------------------------------- */

/**
 * @brief Convert a temperature in Celsius to a temperature in Farenheit
 * 
 * Note: Does not enforce absolute zero.
 * 
 * @param celsius The temperature in degrees Celsius
 * @return float The corresponding temperature in degrees Farenheit
 */
float conv_celsius_to_farenheit(float celsius_in);

/* -------------------------------------------------------------------------
 * MAIN
 * ------------------------------------------------------------------------- */

/**
 * @brief Main entry function
 * 
 * @return int OS return code, 0 indicates success, other indicates failure
 */
int main(void) {
    
    /* ---- DECLARATIONS & INITIALISATIONS ---- */
    
    /* The current celsius value */
    int celsius = table_start_celsius;

    /* ---- MAIN TABLE PRINTING ---- */

    for (
        /* index init is done in the declaration & init section */; 
        celsius <= table_stop_celsius; 
        celsius += table_step_celsius
    ) {
        printf(
            "%3d = %5.1f\n", 
            celsius, 
            conv_celsius_to_farenheit((float)celsius)
        );
    }

    return 0;
}

/* -------------------------------------------------------------------------
 * FUNCTION IMPLEMENTATIONS
 * ------------------------------------------------------------------------- */

float conv_celsius_to_farenheit(float celsius_in) {
    return celsius_in * (9.0 / 5.0) + 32.0;
}