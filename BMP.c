#include <stdio.h>
#include <stdlib.h>

struct BMPHeader {
    unsigned short type;
    unsigned int size;   
    unsigned short res1, res2;
    unsigned int offset;      
    unsigned int headerSize;  
    int width;                
    int height;              
};

int main() {
    void *vptr = malloc(sizeof(struct BMPHeader));
    struct BMPHeader *sptr = (struct BMPHeader *)vptr;

    FILE *f = fopen("sample_1280×853.bmp", "rb");
    if (f != NULL){

    fread(sptr, sizeof(struct BMPHeader), 1, f);
    fclose(f);
    }
    if (sptr->type == 0x4D42) {
        printf("Status: Valid BMP\n");
        printf("---------------------------\n");
        printf("File Type    : %X (BM)\n", sptr->type);
        printf("File Size    : %u bytes\n", sptr->size);
        printf("Reserved 1   : %u\n", sptr->res1);
        printf("Reserved 2   : %u\n", sptr->res2);
        printf("Data Offset  : %u bytes\n", sptr->offset);
        printf("Header Size  : %u bytes\n", sptr->headerSize);
        printf("Image Width  : %d px\n", sptr->width);
        printf("Image Height : %d px\n", sptr->height);
        printf("Pointer Variable Address: %p\n", (void *)&sptr);
    }

    free(vptr);
    return 0;
}