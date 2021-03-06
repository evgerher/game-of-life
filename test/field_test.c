#include <ctest.h>

#include <field.h>

CTEST(endgame_check_suite, dead_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(4 * sizeof(char*));

    for (i = 0; i < 4; i++) {
        test_table[i] = malloc(4 * sizeof(char));
    }

    {
        test_table[0][0] = 0;
        test_table[0][1] = 0;
        test_table[0][2] = 0;
        test_table[0][3] = 0;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 0;
        test_table[2][2] = 0;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    test_field = field_create(4);
    table_set(test_field, test_table, 0);
    table_set(test_field, test_table, 1);

    // When
    const unsigned int result = field_endgame_check(test_field);
    field_delete(test_field);
    table_delete(test_table, 4);

    // Then
    const unsigned int expected_result = 1;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(endgame_check_suite, static_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(4 * sizeof(char*));

    for (i = 0; i < 4; i++) {
        test_table[i] = malloc(4 * sizeof(char));
    }

    {
        test_table[0][0] = 0;
        test_table[0][1] = 0;
        test_table[0][2] = 0;
        test_table[0][3] = 0;
        test_table[1][0] = 0;
        test_table[1][1] = 1;
        test_table[1][2] = 1;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 1;
        test_table[2][2] = 1;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    test_field = field_create(4);
    table_set(test_field, test_table, 0);
    table_set(test_field, test_table, 1);

    // When
    const unsigned int result = field_endgame_check(test_field);
    field_delete(test_field);
    table_delete(test_table, 4);

    // Then
    const unsigned int expected_result = 1;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(endgame_check_suite, continue_playing_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(4 * sizeof(char*));

    for (i = 0; i < 4; i++) {
        test_table[i] = malloc(4 * sizeof(char));
    }

    test_field = field_create(4);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[0][3] = 0;
        test_table[1][0] = 0;
        test_table[1][1] = 1;
        test_table[1][2] = 1;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    table_set(test_field, test_table, 0);

    {
        test_table[0][0] = 0;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[0][3] = 0;
        test_table[1][0] = 1;
        test_table[1][1] = 0;
        test_table[1][2] = 1;
        test_table[1][3] = 1;
        test_table[2][0] = 0;
        test_table[2][1] = 1;
        test_table[2][2] = 1;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    table_set(test_field, test_table, 1);

    // When
    const unsigned int result = field_endgame_check(test_field);
    field_delete(test_field);
    table_delete(test_table, 4);

    // Then
    const unsigned int expected_result = 0;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, square_top_left_corner_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = SQUARE;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 0;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, square_top_right_corner_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = SQUARE;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 0;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, square_bottom_left_corner_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = SQUARE;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 0;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, square_bottom_right_corner_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = SQUARE;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 0;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, tor_top_left_corner_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = TOR;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 3;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, tor_top_right_corner_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = TOR;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 3;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, tor_bottom_left_corner_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = TOR;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 3;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(neighbos_count_suite, tor_bottom_right_corner_field_test) {
    // Given
    unsigned int i;
    field *test_field;

    char **test_table = malloc(3 * sizeof(char*));

    for (i = 0; i < 3; i++) {
        test_table[i] = malloc(3 * sizeof(char));
    }

    test_field = field_create(3);

    {
        test_table[0][0] = 1;
        test_table[0][1] = 0;
        test_table[0][2] = 1;
        test_table[1][0] = 0;
        test_table[1][1] = 0;
        test_table[1][2] = 0;
        test_table[2][0] = 1;
        test_table[2][1] = 0;
        test_table[2][2] = 1;
    }

    table_set(test_field, test_table, 0);

    test_field->flat = TOR;

    // When
    const unsigned int result = field_neighbors_count(test_field, 0, 0);
    field_delete(test_field);
    table_delete(test_table, 3);

    // Then
    const unsigned int expected_result = 3;

    ASSERT_EQUAL(expected_result, result);
}

CTEST(next_gen_suite, next_gen_nonstatic_test) {
    // Given
    unsigned int i;
    unsigned int j;

    field *test_field;

    char **test_table = malloc(4 * sizeof(char*));

    for (i = 0; i < 4; i++) {
        test_table[i] = malloc(4 * sizeof(char));
    }

    test_field = field_create(4);

    {
        test_table[0][0] = 0;
        test_table[0][1] = 1;
        test_table[0][2] = 0;
        test_table[0][3] = 0;
        test_table[1][0] = 0;
        test_table[1][1] = 1;
        test_table[1][2] = 0;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 1;
        test_table[2][2] = 0;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    table_set(test_field, test_table, 0);

    {
        test_table[0][0] = 0;
        test_table[0][1] = 0;
        test_table[0][2] = 0;
        test_table[0][3] = 0;
        test_table[1][0] = 1;
        test_table[1][1] = 1;
        test_table[1][2] = 1;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 0;
        test_table[2][2] = 0;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    // When
    const unsigned int result = field_next_gen(test_field);
    unsigned int diff = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++) {
            if (test_field->current_table[i][j] != test_table[i][j]) {
                diff++;
            }
        }
    }

    field_delete(test_field);
    table_delete(test_table, 4);

    // Then
    const unsigned int expected_result = 0;
    const unsigned int expected_diff = 0;

    ASSERT_EQUAL(expected_result, result);
    ASSERT_EQUAL(expected_diff, diff);
}

CTEST(next_gen_suite, next_gen_static_test) {
    // Given
    unsigned int i;
    unsigned int j;

    field *test_field;

    char **test_table = malloc(4 * sizeof(char*));

    for (i = 0; i < 4; i++) {
        test_table[i] = malloc(4 * sizeof(char));
    }

    test_field = field_create(4);

    {
        test_table[0][0] = 0;
        test_table[0][1] = 0;
        test_table[0][2] = 0;
        test_table[0][3] = 0;
        test_table[1][0] = 0;
        test_table[1][1] = 1;
        test_table[1][2] = 1;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 1;
        test_table[2][2] = 1;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    table_set(test_field, test_table, 0);

    {
        test_table[0][0] = 0;
        test_table[0][1] = 0;
        test_table[0][2] = 0;
        test_table[0][3] = 0;
        test_table[1][0] = 0;
        test_table[1][1] = 1;
        test_table[1][2] = 1;
        test_table[1][3] = 0;
        test_table[2][0] = 0;
        test_table[2][1] = 1;
        test_table[2][2] = 1;
        test_table[2][3] = 0;
        test_table[3][0] = 0;
        test_table[3][1] = 0;
        test_table[3][2] = 0;
        test_table[3][3] = 0;
    }

    // When
    const unsigned int result = field_next_gen(test_field);
    unsigned int diff = 0;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++) {
            if (test_field->current_table[i][j] != test_table[i][j]) {
                diff++;
            }
        }
    }

    field_delete(test_field);
    table_delete(test_table, 4);

    // Then
    const unsigned int expected_result = 1;
    const unsigned int expected_diff = 0;

    ASSERT_EQUAL(expected_result, result);
    ASSERT_EQUAL(expected_diff, diff);
}