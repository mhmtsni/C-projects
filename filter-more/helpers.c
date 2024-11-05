#include "helpers.h"
#include <math.h>
// Convert image to grayscale
int gx_gy(int numbers[9]);
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{   
    float new_pixel;
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++){
            new_pixel = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3.0;
            new_pixel = (int)(new_pixel + 0.5);
            image[i][j].rgbtBlue = new_pixel;   
            image[i][j].rgbtRed = new_pixel;
            image[i][j].rgbtGreen = new_pixel;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++) {
        for(int j = 0; j < width / 2; j++){
            temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float average_of_red;
    float average_of_green;
    float average_of_blue;
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if((i == 0 && j == 0)){
                
                average_of_red = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed+ image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 4.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 4.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 4.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
                

            }else if(i == 0 && j == width - 1) {
                average_of_red = (image[i][j].rgbtRed + image[i + 1][j - 1].rgbtRed+ image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed) / 4.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue) / 4.0;
                average_of_green = (image[i][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen) / 4.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
            }else if(i == height - 1 && j == 0) {
                average_of_red = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed+ image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 4.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 4.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 4.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
            }else if(i == height - 1 && j == width - 1) {
                average_of_red = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed+ image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 4.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 4.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 4.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
            }
            
            else if(i == 0){
                average_of_red = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / 6.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 6.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 6.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);

            }else if(j == 0) {
                average_of_red = (image[i][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
            }else if(i == height - 1) {
                average_of_red = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / 6.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 6.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 6.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
            }else if(j == width - 1) {
                average_of_red = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed) / 6.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue) / 6.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen) / 6.0;
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
            }
            
            else {
                average_of_red = (image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / 9.0;
                average_of_blue = (image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / 9.0;
                average_of_green = (image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / 9.0;
                temp[i][j].rgbtRed = (int)(average_of_red + 0.5);
                temp[i][j].rgbtBlue = (int)(average_of_blue + 0.5);
                temp[i][j].rgbtGreen = (int)(average_of_green + 0.5);
                


            }
        }
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
        image[i][j] = temp[i][j];
    }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int numbers_red[9];
    int numbers_blue[9];
    int numbers_green[9];
    int new_red;
    int new_blue;
    int new_green;
    int index = 0;
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int di = -1; di < 2; di++) {
                for (int dj = -1; dj < 2; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    if(ni >= 0 && ni < height && nj >= 0 && nj < width) {
                        numbers_blue[index] = image[ni][nj].rgbtBlue;
                        numbers_red[index] = image[ni][nj].rgbtRed;

                        numbers_green[index] = image[ni][nj].rgbtGreen;

                            index++;
                        if(index == 9) {
                            index = 0;

                        }
                    }else{
                        numbers_red[index] = 0;
                        numbers_blue[index] = 0;
                        numbers_green[index] = 0;
                        index++;
                        if(index == 9) {
                            index = 0;
                        }
                    }
                    


                }
                new_red = gx_gy(numbers_red);
                new_green = gx_gy(numbers_green);
                new_blue = gx_gy(numbers_blue);
            }
            temp[i][j].rgbtBlue = new_blue;
            temp[i][j].rgbtRed = new_red;
            temp[i][j].rgbtGreen = new_green;

        }
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
        image[i][j] = temp[i][j];
    }
    }
    return;
}

int gx_gy(int numbers[9]) {
    int gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    float gx_value = 0.0;
    float gy_value = 0.0;
    float final_value = 0.0;
    for (int i = 0; i < 9; i++) {
        gx_value += gx[i] * numbers[i];
        gy_value += gy[i] * numbers[i];

    }
    final_value = gx_value * gx_value + gy_value * gy_value;
    int rounded_value = (int)(sqrt(final_value) + 0.5);
    if(rounded_value > 255) {
        return 255;
    }else if(rounded_value < 0) {
        return 0;
    }else {
        return rounded_value;

    }
}