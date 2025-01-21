#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0 ; i<height;i++){
        for(int j = 0; j<width;j++){
            RGBTRIPLE *color = &image[i][j];
            if(color->rgbtBlue == color->rgbtGreen && color->rgbtGreen == color->rgbtRed && color->rgbtBlue == color->rgbtRed) continue;
            BYTE gray1 = round((float)(color->rgbtBlue + color->rgbtGreen + color->rgbtRed)/3);
            color->rgbtBlue = gray1;
            color->rgbtGreen = gray1;
            color->rgbtRed = gray1;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            RGBTRIPLE *color = &image[i][j];
            int originalBlue = color->rgbtBlue;
            int originalGreen = color->rgbtGreen;
            int originalRed = color->rgbtRed;

            float sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            float sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            float sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);

            if(sepiaBlue > 255) sepiaBlue = 255;
            if(sepiaGreen > 255) sepiaGreen = 255;
            if(sepiaRed > 255) sepiaRed = 255;

            color->rgbtBlue = sepiaBlue;
            color->rgbtGreen = sepiaGreen;
            color->rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width/2; j++){
            int pixelOp = width - 1- j;
            RGBTRIPLE *left = &image[i][j];
            RGBTRIPLE *right = &image[i][pixelOp];
            RGBTRIPLE temp = *left;
            *left = *right;
            *right = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE pixel[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            pixel[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int red = 0, green = 0, blue = 0, prom = 0;

            for(int l = -1; l <= 1; l++){
                for(int k = -1; k <= 1; k++){
                    int pl = i + l;
                    int pk = j + k;

                    if(pl >= 0 && pl < height && pk >= 0 && pk < width){
                        RGBTRIPLE *positionPixel = &pixel[pl][pk];

                        red += positionPixel->rgbtRed;
                        blue += positionPixel->rgbtBlue;
                        green += positionPixel->rgbtGreen;
                        prom++;
                    }

                }
            }
            RGBTRIPLE *updatePixel = &image[i][j];

            updatePixel->rgbtRed = round((float)red/prom);
            updatePixel->rgbtGreen = round((float)green/prom);
            updatePixel->rgbtBlue = round((float)blue/prom);
        }
    }
    return;
}

