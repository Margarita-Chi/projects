#include <stdio.h>  
#include <stdlib.h>  
  
#include "index_first_even.h"
#include "index_last_odd.h"
#include "sum_between_even_odd.h"
#include "sum_before_even_and_after_odd.h"

int action(char value, int* array) { 
 switch (value) { 
 case '0': 
  printf("%d\n", index_first_even(array)); 
  break; 
 case '1': 
  printf("%d\n", index_last_odd(array)); 
  break; 
 case '2': 
  printf("%d\n", sum_between_even_odd(array)); 
  break; 
 case '3': 
  printf("%d\n", sum_before_even_and_after_odd(array)); 
  break; 
 default: 
  printf("Данные некорректны\n"); 
  break; 
 } 
 return 0; 
} 

#include <iostream>
#include <unistd.h>
#include <getopt.h>

void is_pkay_I_and_G(int check_input, int left_x, int up_y, int right_x, int down_y) {
    if (check_input != 2) {
        //ошибка введен не все данные
    }
    if (left_x > right_x) {
        // ошибка неправильне координаты
    }
    if (up_y < down_y){
        // шибка неправильне координаты
    }
}

#pragma pack(push,1)

typedef struct {
    unsigned short signature;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct {
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsInColorTable;
    unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct {
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Rgb;

#pragma pack(pop)

Rgb** read_bmp(char file_name[], BitmapFileHeader* bmfh, BitmapInfoHeader* bmif) {
    FILE* f = fopen(file_name, "rb");
    fread(bmfh, 1, sizeof(BitmapFileHeader), f);
    fread(bmif, 1, sizeof(BitmapInfoHeader), f);
    unsigned int Height = bmif->height;
    unsigned int Width = bmif->width;
    Rgb** arr = (Rgb**)malloc(Height * sizeof(Rgb*));
    for (int i = 0; i < Height; i++) {
        arr[i] = (Rgb *) malloc(Width * sizeof(Rgb) + (Width * 3) % 4); //выделение памяти с учетом выравнивания???? хз до сих пор не понимаю
        fread(arr[i], 1, Width * sizeof(Rgb) + (Width * 3) % 4, f);
    }
    fclose(f);
    return arr;
}

void write_bmp(char file_name[], Rgb** arr, int H, int
    W, BitmapFileHeader bmfh, BitmapInfoHeader bmif) {
    FILE* ff = fopen(file_name, "wb");
    fwrite(&bmfh, 1, sizeof(BitmapFileHeader), ff);
    fwrite(&bmif, 1, sizeof(BitmapInfoHeader), ff);
    for (int i = 0; i < H; i++) {
        fwrite(arr[i], 1, W * sizeof(Rgb) + (W * 3) % 4,
            ff);
    }
    fclose(ff);
}


int main(int argc, char* argv[]) { //argument count & argument vector
    struct option long_options[] = {
        {"inverse", no_argument, NULL, 'i'},
        {"gray", no_argument, NULL, 'g'},
        {"resize", no_argument, NULL, 'r'},
        {"line", no_argument, NULL, 'l'},
        {"help", no_argument, NULL, 'h'},
        {"info", no_argument, NULL, 'n'},
        {"output", required_argument, NULL, 'o'},
        {NULL, 0, NULL, 0} 
    };
    struct option coord[] = {
        {"left_up", required_argument, NULL, 'u'},
        {"right_down", required_argument, NULL, 'd'},
        {NULL, 0, NULL, 0}
    };
    struct option resize[] = {
        {"left", required_argument, NULL, 'L'},
        {"right", required_argument, NULL, 'R'},
        {"above", required_argument, NULL, 'A'},
        {"below", required_argument, NULL, 'B'},
        {"color", required_argument, NULL, 'C'},
        {NULL, 0, NULL, 0}
    };
    int option;
    int left_x_I, up_y_I, right_x_I, down_y_I;
    int left_x_G, up_y_G, right_x_G, down_y_G;
    int left_resize, right_resize, above_resize, below_resize;
    int check_input;
    while ((option = getopt_long(argc, argv, "igrlhno:", long_options, NULL)) != -1) {
        switch (option) {
            case 'i':
                check_input = 0;
                while ((coord_input = getopt_long(argc, argv, "u:d:", coord, NULL)) != -1) {
                    switch (option) {
                        case 'u':
                            if (sscanf(optarg, "%d.%d", &left_x_I, &up_y_I) != 2) {
                                // ошибка неправильнй тип данных
                            }
                            check_input++;
                            break;
                        case 'd':
                            if (sscanf(optarg, "%d.%d", &right_x_I, &down_y_I) != 2) {
                                // ошибка неправильнй тип данных
                            }
                            check_input++;
                            break;
                    }
                }
                is_pkay_I_and_G(check_input, left_x_I, up_y_I, right_x_I, down_y_I);
                // взов соотв функции
            case 'g':
                check_input = 0;
                while ((coord_input = getopt_long(argc, argv, "u:d:", coord, NULL)) != -1) {
                    switch (option) {
                    case 'u':
                        if (sscanf(optarg, "%d.%d", &left_x_G, &up_y_G) != 2) {
                            // ошибка неправильнй тип данных
                        }
                        check_input++;
                        break;
                    case 'd':
                        if (sscanf(optarg, "%d.%d", &right_x_G, &down_y_G) != 2) {
                            // ошибка неправильнй тип данных
                        }
                        check_input++;
                        break;
                    }
                }
                is_pkay_I_and_G(check_input, left_x_G, up_y_G, right_x_G, down_y_G);
                // взов соотв функции
                break;
            case 'r':
                check_input = 0;
                while ((coord_input = getopt_long(argc, argv, "L:R:A:B:C:", resize, NULL)) != -1) {
                    switch (option) {
                    case 'L':
                        if (sscanf(optarg, "%d", &left_resize) != 1) {
                            // ошибка неправильнй тип данных
                        }
                        check_input++;
                        break;
                    case 'R':
                        if (sscanf(optarg, "%d", &right_resize) != 1) {
                            // ошибка неправильнй тип данных
                        }
                        check_input++;
                        break;
                    case 'A':
                        if (sscanf(optarg, "%d", &above_resize) != 1) {
                            // ошибка неправильнй тип данных
                        }
                        check_input++;
                        break;
                    case 'B':
                        if (sscanf(optarg, "%d", &below_resize) != 1) {
                            // ошибка неправильнй тип данных
                        }
                        check_input++;
                        break;
                    case 'C':
                        //здесь работа со светом
                        break;
                    }
                }
                break;
            case 'l':
            
                break;
            case 'h':

                break;
            case 'n':

                break;
            case 'o':

                break;
            default:
                break;
        }
    }

}
