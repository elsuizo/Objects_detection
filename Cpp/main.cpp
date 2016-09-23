/* -------------------------------------------------------------------------
@file main.cpp

@date 09/21/16 14:18:54
@author Martin Noblia
@email martin.noblia@openmailbox.org

@brief
test for working with chromatic_coordinates
@detail

Licence:
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
---------------------------------------------------------------------------*/
/* begin */
/* -------------------------------------------------------------------------
                           includes
---------------------------------------------------------------------------*/
#include<opencv2/opencv.hpp>
#include"opencv2/highgui/highgui.hpp"
#include<stdio.h>
#include<iostream>
/* -------------------------------------------------------------------------
                           namespaces
---------------------------------------------------------------------------*/
using namespace cv;
using namespace std;
/* -------------------------------------------------------------------------
                           main
---------------------------------------------------------------------------*/
Mat chromatic_coordinates(cv::Mat &image);
int main(void)
{
   Mat img_original;
   Mat img_transform;

   /* read the image */
   img_original = imread("../Images/hands1.png", CV_LOAD_IMAGE_COLOR);
   img_transform = chromatic_coordinates(img_original);
   /* windows */
   namedWindow("Original Image");
   //namedWindow("Transform Image");
   /* shows */
   imshow("Original Image", img_transform);
   //imshow("Transform Image", img_transform);
   waitKey(0);
   destroyAllWindows();

   return 0;

}

Mat chromatic_coordinates(cv::Mat &image)
{
   const int number_of_rows = image.rows;
   const int number_of_cols = image.cols;
   Mat output;
   output = Mat::zeros(Size(number_of_cols, number_of_rows), CV_32FC3);
   Mat_<Vec3b> _I = image;
   Mat_<Vec3f> _O = output;
   uchar r, g, b, s;
   for(int i = 0; i <= number_of_rows; ++i)
      for(int j = 0; j <= number_of_cols; ++j)
         {
             r = _I(i,j)[0];
             g = _I(i,j)[1];
             b = _I(i,j)[2];
             s = r + g + b;
             if(s != 0)
             {
                _O(i,j)[0] = r/(double)s;
                _O(i,j)[1] = g/(double)s;
                _O(i,j)[2] = b/(double)s;

             }

      }
   output = _O;
   return output;
}



