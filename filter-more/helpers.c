#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i<height; i++){
        for (int j=0; j<width; j++){
            int average = round((image[i][j].rgbtBlue+image[i][j].rgbtRed+image[i][j].rgbtGreen)/3.0);
            image[i][j].rgbtBlue=average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i<height; i++){
        for (int j=0; j<width/2; j++){
            int temp[3];
            temp[0] =image[i][width-1-j].rgbtRed;
            temp[1] =image[i][width-1-j].rgbtBlue;
            temp[2] =image[i][width-1-j].rgbtGreen;
            image[i][width-1-j].rgbtBlue =image[i][j].rgbtBlue;
            image[i][width-1-j].rgbtGreen =image[i][j].rgbtGreen;
            image[i][width-1-j].rgbtRed= image[i][j].rgbtRed;
            image[i][j].rgbtRed = temp[0];
            image[i][j].rgbtBlue = temp[1];
            image[i][j].rgbtGreen = temp[2];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE averageholder[height][width];
    for (int i =0; i<height; i++){
        for (int j=0; j<width; j++){
            averageholder[i][j].rgbtBlue = image[i][j].rgbtBlue;
            averageholder[i][j].rgbtGreen = image[i][j].rgbtGreen;
            averageholder[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }
    for (int i =0; i<height; i++){
        int average[3];
        int w=3;
        int h =3;
        for (int j=0; j<width; j++){
            int counter =0;

            average[1]=0;
            average[0]=0;
            average[2]=0;

            if (width-j<3){
                w = width-j;
            }
            if (height-i<3){
                h = height-i;
            }
            if (i>0 && j>0){
                for (int m=i-1; m<(h+i-1); m++){
                    for (int n=j-1; n<(w+j-1);n++) {
                        average[0] += averageholder[m][n].rgbtRed;
                        average[1] += averageholder[m][n].rgbtGreen;
                        average[2] += averageholder[m][n].rgbtBlue;
                        counter+=1;
                }
            } } else if (i==0 && j==0 ) {
                for (int m=0; m<(2); m++){
                    for (int n=0; n<(2);n++) {
                        average[0] += averageholder[m][n].rgbtRed;
                        average[1] += averageholder[m][n].rgbtGreen;
                        average[2] += averageholder[m][n].rgbtBlue;
                        counter+=1;
                    }
                }


            } else if (j==0) {
                for (int m=i-1; m<(h+i-1); m++){
                    for (int n=0; n<(2);n++) {
                        average[0] += averageholder[m][n].rgbtRed;
                        average[1] += averageholder[m][n].rgbtGreen;
                        average[2] += averageholder[m][n].rgbtBlue;
                        counter+=1;
                    }
                }

            } else if (i==0) {
                for (int m=0; m<(2); m++){
                    for (int n=j-1; n<(w+j-1);n++) {
                        average[0] += averageholder[m][n].rgbtRed;
                        average[1] += averageholder[m][n].rgbtGreen;
                        average[2] += averageholder[m][n].rgbtBlue;
                        counter+=1;
                    }
                }

            } else {
                printf("failed");
                return;
            }
            average[0] /= counter;
            average[1] /= counter;
            average[2] /= counter;
            image[i][j].rgbtRed = average[0];
            image[i][j].rgbtBlue = average[2];
            image[i][j].rgbtGreen = average[1];

        }

    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE originalholder[height][width];
    int gx[3][3] = {
    {-1, 0, 1},
    {-2, 0, 2},
    {-1, 0, 1}
    };

    int gy[3][3] = {
    {-1, -2, -1},
    {0, 0, 0},
    {1, 2, 1}
    };
    for (int i =0; i<height; i++){
        for (int j=0; j<width; j++){
            originalholder[i][j].rgbtBlue = image[i][j].rgbtBlue;
            originalholder[i][j].rgbtGreen = image[i][j].rgbtGreen;
            originalholder[i][j].rgbtRed = image[i][j].rgbtRed;
        }
    }
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int bluex = 0;
            int redx=0;
            int greenx =0;
            int bluey = 0;
            int redy=0;
            int greeny =0;
            for (int k=(i-1); k<(i+2); k++) {
                for (int l=(j-1); l<(j+2); l++) {
                    int z = l-j+1;
                    int y= k-i+1;

                    if (k>height || l >width || l<0 || k<0) {
                        continue;
                    } else {
                        bluex+= originalholder[k][l].rgbtBlue * gx[y][z];
                        bluey+= originalholder[k][l].rgbtBlue * gy[y][z];
                        greenx+= originalholder[k][l].rgbtGreen * gx[y][z];
                        greeny+= originalholder[k][l].rgbtGreen * gy[y][z];
                        redx+= originalholder[k][l].rgbtRed * gx[y][z];
                        redy+= originalholder[k][l].rgbtRed * gy[y][z];



                    }
                }
            }
            int redmagnitude = sqrt(redx*redx +redy*redy);
            int bluemagnitude = sqrt(bluex*bluex +bluey*bluey);
            int greenmagnitude = sqrt(greenx*greenx +greeny*greeny);
            if (redmagnitude >255) {
                redmagnitude =255;
            }
            if (greenmagnitude >255) {
                greenmagnitude =255;
            }
            if (bluemagnitude >255) {
                bluemagnitude =255;
            }
            image[i][j].rgbtBlue = bluemagnitude;
            image[i][j].rgbtGreen = greenmagnitude;
            image[i][j].rgbtRed = redmagnitude;
        }
    }

    return;
}
