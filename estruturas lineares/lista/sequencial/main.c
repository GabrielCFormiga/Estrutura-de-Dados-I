#include <stdio.h>
#include "vector.h"

int main() {
    Vector vec;
    init(&vec, 3);
    push_back(&vec, 1);
    push_back(&vec, 2);
    push_back(&vec, 3);
    vec_print(&vec);

    insert(&vec, 1, 4);
    vec_print(&vec);

    vec_free(&vec);
    return 0;
}