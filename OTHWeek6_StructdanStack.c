#include <stdio.h>

struct node
{
    struct node *link;
    char alphabet;
};

int main()
{
    // Node initialization
    struct node l1, l2, l3, l4, l5, l6, l7, l8, l9;

    l1.link = NULL;
    l1.alphabet = 'F';

    l2.link = NULL;
    l2.alphabet = 'M';

    l3.link = NULL;
    l3.alphabet = 'A';

    l4.link = NULL;
    l4.alphabet = 'I';

    l5.link = NULL;
    l5.alphabet = 'K';

    l6.link = NULL;
    l6.alphabet = 'T';

    l7.link = NULL;
    l7.alphabet = 'N';

    l8.link = NULL;
    l8.alphabet = 'O';

    l9.link = NULL;
    l9.alphabet = 'R';

    // Linking nodes
    l4.link = &l7; // N
    l7.link = &l1; // F
    l1.link = &l8; // O
    l8.link = &l9; // R
    l9.link = &l2; // M
    l2.link = &l3; // A
    l3.link = &l6; // T
    l6.link = &l4; // I

    // Print linked list
    printf("%c", l4.alphabet);                                                 // I
    printf("%c", l4.link->alphabet);                                           // N
    printf("%c", l4.link->link->alphabet);                                     // F
    printf("%c", l4.link->link->link->alphabet);                               // O
    printf("%c", l4.link->link->link->link->alphabet);                         // R
    printf("%c", l4.link->link->link->link->link->alphabet);                   // M
    printf("%c", l4.link->link->link->link->link->link->alphabet);             // A
    printf("%c", l4.link->link->link->link->link->link->link->alphabet);       // T
    printf("%c", l4.link->link->link->link->link->link->link->link->alphabet); // I

    l4.link = &l5;
    l5.link = &l3;

    printf("%c", l4.link->alphabet);       // K
    printf("%c", l4.link->link->alphabet); // A

    return 0;
}