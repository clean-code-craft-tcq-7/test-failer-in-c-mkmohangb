#include <stdio.h>
#include <assert.h>

int colorIndexToPairNumber(int majorColorIndex, int minorColorIndex) {
    return majorColorIndex * 5 + minorColorIndex;
}

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", colorIndexToPairNumber(i,j) , majorColor[i], minorColor[j]);
        }
    }
    return i * j;
}

int testPrintColorMap() {
    printf("\nPrint color map test\n");
    int result = printColorMap();
    assert(result == 25);
    assert(colorIndexToPairNumber(0, 0) == 1);
    assert(colorIndexToPairNumber(0, 1) == 2);
    assert(colorIndexToPairNumber(1, 0) == 6);
    assert(colorIndexToPairNumber(4, 4) == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
