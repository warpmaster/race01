void mx_printchar(char c);

static void print_horizontal_edge(int sections, char c1, char c2, int spaces_before, int spaces_after) {
    for (int i = 0; i < spaces_before; i++) {
        mx_printchar(' ');
    }
    mx_printchar(c1);
    for (int j = 0; j < sections; j++) {
        mx_printchar(c2);
    }
    mx_printchar(c1);
    for (int i = 0; i < spaces_after; i++) {
        mx_printchar(' ');
    }
}
static void print_line(int sections, char c1, char c2, int spaces_before, int spaces_after) {
    for (int i = 0; i < spaces_before; i++) {
        mx_printchar(' ');
    }
    mx_printchar(c1);
    for (int i = 0; i < sections; i++) {
        mx_printchar(' ');
    }
    mx_printchar(c1);
     for (int i = 0; i < spaces_after; i++) {
        mx_printchar(' ');
    }
    mx_printchar(c2);
    mx_printchar('\n');
}

void mx_cube(int n) {
    int len = (n % 2 == 0 ? n / 2 - 1 : n / 2);
    char c1 = '/';
    char c2 = '|';
    char c3 = '+';
    char c4 = '-';

    if (n < 2) {
        return;
    }
    print_horizontal_edge(n * 2, c3, c4, n / 2 + 1, 0);
    mx_printchar('\n');

    for (int i = 0, lines = n / 2, max = n / 2; i < max; i++, lines--) {
        print_line(n * 2, c1, c2, lines, i);
    }
    print_horizontal_edge(n * 2, c3, c4, 0, n / 2);
    mx_printchar('|');
    mx_printchar('\n');

    for (int j = 0 ; j < len; j++) {
        print_line(n * 2, c2, c2, 0, n / 2);
    }
    print_horizontal_edge(n * 2, c2, ' ', 0, n / 2);
    mx_printchar(c3);
    mx_printchar('\n');

    for (int i = 0, lines = n / 2, max = n / 2; i < max; i++, lines--) {
        print_line(n * 2, c2, c1, 0, lines - 1);
    }
    print_horizontal_edge(n * 2, c3, c4, 0, n / 2);
    mx_printchar('\n');
}
