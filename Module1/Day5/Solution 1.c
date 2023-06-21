/* Use structures to find the volume and the total surface area of the box. 
   You need to access the members of the structure with the help of a structure pointer:
    a. With the help of (*) asterisk or indirection operator and (.) dot operator.
    b. With the help of ( -> ) Arrow operator using pointer as well as dot representation.*/

#include <stdio.h>
struct Box {
    double length;
    double width;
    double height;
};
void calculateVolumeAndSurfaceArea(struct Box* boxPtr) {
    double volume, surfaceArea;
    volume = boxPtr->length * boxPtr->width * boxPtr->height;
    surfaceArea = 2 * (boxPtr->length * boxPtr->width + boxPtr->length * boxPtr->height + boxPtr->width * boxPtr->height);
    printf("Volume of the box: %.2f\n", volume);
    printf("Surface area of the box: %.2f\n", surfaceArea);
}

int main() {
    
    struct Box myBox = { 10.0, 20.0, 30.0 };
    struct Box* boxPtr = &myBox;
    printf("Using (*) asterisk and (.) dot operator:\n");
    calculateVolumeAndSurfaceArea(&myBox);
    printf("\nUsing (->) arrow operator with pointer representation:\n");
    calculateVolumeAndSurfaceArea(boxPtr);
    printf("\nUsing (->) arrow operator with dot representation:\n");
    calculateVolumeAndSurfaceArea(&(*boxPtr));
    return 0;
}
