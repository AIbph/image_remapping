#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;

Mat src, dst, map_x, map_y;
int index = 0;
void unpdata_map(void);
int main(int argc, char** argv){
	// 像素重映射

	// 读取图像
	src = imread("D:/OpenCVProject/day1218/像素重映射/像素重映射/test.jpg");
	if (!src.data)
	{
		printf("could not load image.....");
	}
	imshow("origin image", src);

	// 生成映射表
	map_x.create(src.size(), CV_32FC1);
	map_y.create(src.size(), CV_32FC1);
	


	int c = 0;
	while (true)
	{
		// 等待键盘输入数值， 输入ESC键退出
		c = waitKey(500);
		if ((char)c == 27)
		{
			break;
		}
		index = c % 3;
		// 调用重映射方法
		unpdata_map();
		remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, Scalar(255, 0, 255));
		imshow("final image", dst);

	}	

	waitKey(0);
	return 0;
}

void unpdata_map(void){
	for (int row = 0; row < src.rows; row++)
	{
		for (int col = 0; col < src.cols; col++)
		{
			switch (index)
			{
			case 0:
				// X方向映射
				map_x.at<float>(row, col) = src.cols - col - 1;
				map_y.at<float>(row, col) = row;
				break;

			case 1:
				// y方向映射
				map_x.at<float>(row, col) = col;
				map_y.at<float>(row, col) = src.rows - row - 1;
				break;

			case 2:
				// x,y方向同时映射
				map_x.at<float>(row, col) = src.cols - col - 1;
				map_y.at<float>(row, col) = src.rows - row - 1;
				break;

			default:
				break;
			}
		}
	}



}