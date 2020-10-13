/**
 * @file interest.c
 * @author Duncan Hamill (duncanrhamill@googlemail.com)
 * @brief Calculates iterest accumulated on a debt
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
 * @brief The ammount of initial debt in GBP.
 * 
 * Note: This is actually a bad way to store currency, since this would give us
 * no fractional pounds. If you wanted to include pence too this should be 
 * given in pence, or if including fractions of a penny then as a float, but be
 * careful as floating point arithmetic can result in £0.10 + £0.20 != £0.30!
 */
const int debt_initial_gbp = 1000;

/**
 * @brief The total number of months for which the loan is borrowed.
 */
const int loan_duration_months = 24;

/**
 * @brief The interest rate at which applies to the loan.
 */
const float interest_rate = 0.03;

/* -------------------------------------------------------------------------
 * FUNCTION DECLARATIONS
 * ------------------------------------------------------------------------- */

/**
 * @brief Accumulate debt and return statistics
 * 
 * @param debt_initial_gbp_in The initial debt value
 * @param interest_rate_in The interest rate
 * @param p_debt_gbp_inout Pointer to the current value of the debt. The value
 *        points to will be modified.
 * @param p_accumulated_interest_gbp_out Pointer to the ammount of debt 
 *        accumulated. The value it points to will be modified.
 * @param p_total_interest_gbp_out Pointer to the total interest accumulated so
 *        far. The value it points to will be modified.
 * @param p_total_interest_to_initial_debt_ratio_out Pointer to the ratio of current
 *        interest to initial debt. The value it points to will be modified.
 */
void accumulate_interest(
    float  debt_initial_gbp_in,
    float  interest_rate_in,
    float *p_debt_gbp_out,
    float *p_accumulated_interest_gbp_out,
    float *p_total_interest_gbp_out,
    float *p_total_interest_to_initial_debt_ratio_out
);

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

    /* The current running debt value in GBP */
    float debt_gbp = (float)debt_initial_gbp;

    /* The current interest for this month */
    float interest_gbp = 0.0;

    /* The total interest accumulated */
    float total_interest_gbp = 0.0;

    /* The ratio of total interest to initial debt */
    float total_interest_to_initial_debt_ratio = 0.0;

    /* The current month index */
    int month = 0;

    /* ---- MAIN LOOP ---- */

    for (
        /* index init is done in the init seciton */;
        month < loan_duration_months;
        month++
    ) {

        /* Accumulate interest on the loan */
        accumulate_interest(
            debt_initial_gbp,
            interest_rate,
            &debt_gbp,
            &interest_gbp,
            &total_interest_gbp,
            &total_interest_to_initial_debt_ratio
        );

        printf(
            "month %d: debt=%.2f, interest=%.2f, total_interest=%.2f, frac=%.2f%%\n",
            month + 1,
            debt_gbp,
            interest_gbp,
            total_interest_gbp,
            total_interest_to_initial_debt_ratio * 100.0
        );
    }

    return 0;
}

/* -------------------------------------------------------------------------
 * FUNCTION IMPLEMENTATIONS
 * ------------------------------------------------------------------------- */

void accumulate_interest(
    float  debt_initial_gbp_in,
    float  interest_rate_in,
    float *p_debt_gbp_out,
    float *p_accumulated_interest_gbp_out,
    float *p_total_interest_gbp_out,
    float *p_total_interest_to_initial_debt_ratio_out
) {
    /* Calculate the accumulated interest */
    *p_accumulated_interest_gbp_out = *p_debt_gbp_out * interest_rate_in;

    /* Add this interest to the current debt and return */
    *p_debt_gbp_out += *p_accumulated_interest_gbp_out;

    /* Calculate total interest */
    *p_total_interest_gbp_out += *p_accumulated_interest_gbp_out;

    /* Calculate the ratio */
    *p_total_interest_to_initial_debt_ratio_out 
        = *p_total_interest_gbp_out / debt_initial_gbp;
}
