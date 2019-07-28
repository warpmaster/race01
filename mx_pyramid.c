void mx_printchar(char c);

static void print_line(int spaces_before, int spaces_mid, int spaces_after, char left_char) {
    for (int i = 0; i < spaces_before; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
    for (int j = 0; j < spaces_mid; j++) {
        mx_printchar(' ');
    }
    mx_printchar('\\');
    for (int k = 0; k < spaces_after; k++) {
        mx_printchar(' ');
    }
    mx_printchar(left_char);
    mx_printchar('\n');
}

void mx_pyramid(int n) {
    int spaces_before = n - 2;
    int spaces_mid = 1;
    int spaces_after = 1;

    if (n < 2 || n % 2 != 0) {
        return;
    }
    // printing the top of a pyramid
    for (int i = 0, len = n - 1; i < len; i++) {
        mx_printchar(' ');
    }
    mx_printchar('/');
    mx_printchar('\\');
    mx_printchar('\n');
    // printing the mid-lines of a pyramid
    for (int i = 0, len = n / 2 - 1; i < len; i++) {
        print_line(spaces_before, spaces_mid, spaces_after, '\\');
        spaces_before--;
        spaces_mid += 2;
        spaces_after++;
    }
    spaces_after--;
    for (int i = 0, len = n / 2 - 1; i < len; i++) {
        print_line(spaces_before, spaces_mid, spaces_after, '|');
        spaces_before--;
        spaces_mid += 2;
        spaces_after--;
    }
    // printing the bottom line of a pyramid
    mx_printchar('/');
    for (int i = 0, len = 2 * n - 3; i < len; i++) {
        mx_printchar('-');
    }
    mx_printchar('\\');
    mx_printchar('|');
    mx_printchar('\n');
}
