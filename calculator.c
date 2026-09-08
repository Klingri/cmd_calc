/* ============================================================
 * calculator.c
 *
 * A simple, lightweight command-line calculator.
 * Supports +, -, *, / on two double-precision numbers.
 * Runs in a loop until the user chooses to quit.
 *
 * Standard: C99/C11, no external libraries beyond the C standard
 * library (stdio.h, stdlib.h).
 * ============================================================ */

#include <stdio.h>
#include <stdlib.h>

/* Function prototypes */
static int get_double(const char *prompt, double *out);
static int get_operator(char *op);

int main(void)
{
    printf("=== Simple Command-Line Calculator ===\n");
    printf("Enter two numbers and an operator (+, -, *, /) to compute.\n");
    printf("Type 'q' at the operator prompt to quit.\n\n");

    while (1) {
        double num1 = 0.0, num2 = 0.0, result = 0.0;
        char op = '\0';

        /* --- Get the operator first (also doubles as the exit check) --- */
        if (!get_operator(&op)) {
            /* get_operator returns 0 when the user wants to quit */
            printf("Goodbye!\n");
            break;
        }

        /* --- Get the first operand --- */
        if (!get_double("Enter first number: ", &num1)) {
            printf("Invalid number entered. Please try again.\n\n");
            continue;
        }

        /* --- Get the second operand --- */
        if (!get_double("Enter second number: ", &num2)) {
            printf("Invalid number entered. Please try again.\n\n");
            continue;
        }

        /* --- Perform the calculation using a switch-case --- */
        int success = 1; /* flag to track if calculation succeeded */

        switch (op) {
            case '+':
                result = num1 + num2;
                break;

            case '-':
                result = num1 - num2;
                break;

            case '*':
                result = num1 * num2;
                break;

            case '/':
                if (num2 == 0.0) {
                    printf("Error: Division by zero is not allowed.\n\n");
                    success = 0;
                } else {
                    result = num1 / num2;
                }
                break;

            default:
                /* Should not normally happen since get_operator validates,
                 * but kept here as a safety net. */
                printf("Error: Invalid operator '%c'.\n\n", op);
                success = 0;
                break;
        }

        /* --- Display the result if the calculation was successful --- */
        if (success) {
            printf("Result: %.2f %c %.2f = %.4f\n\n", num1, op, num2, result);
        }
    }

    return 0;
}

/* ============================================================
 * get_operator
 *
 * Prompts the user for an operator character.
 * Returns 1 and stores the operator in *op if valid.
 * Returns 0 if the user wants to quit ('q' or 'Q').
 * Loops internally until valid input is given.
 * ============================================================ */
static int get_operator(char *op)
{
    char buffer[64];

    while (1) {
        printf("Enter operator (+, -, *, /) or 'q' to quit: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            /* EOF or read error -> treat as quit */
            return 0;
        }

        /* Skip leading whitespace/newlines to find the actual input char */
        char c = '\0';
        if (sscanf(buffer, " %c", &c) != 1) {
            printf("No input detected. Please try again.\n");
            continue;
        }

        if (c == 'q' || c == 'Q') {
            return 0; /* signal caller to exit the program */
        }

        if (c == '+' || c == '-' || c == '*' || c == '/') {
            *op = c;
            return 1; /* valid operator found */
        }

        printf("Invalid operator '%c'. Please enter +, -, *, /, or q.\n", c);
    }
}

/* ============================================================
 * get_double
 *
 * Prompts the user with the given message and attempts to read
 * a double value from standard input.
 * Returns 1 on success (value stored in *out).
 * Returns 0 if the input could not be parsed as a valid number.
 * Also clears any leftover invalid input from stdin to avoid
 * an infinite loop on the next read.
 * ============================================================ */
static int get_double(const char *prompt, double *out)
{
    char buffer[128];

    printf("%s", prompt);

    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return 0; /* EOF or read error */
    }

    /* sscanf with "%lf" parses a double; check that exactly one
     * value was successfully converted. */
    if (sscanf(buffer, "%lf", out) != 1) {
        return 0; /* parsing failed - not a valid number */
    }

    return 1;
}