#include<opencv2/opencv.hpp>
#include<iostream>
#include<math.h>
using namespace cv;

Mat src, dst, map_x, map_y;
int index = 0;
void unpdata_map(void);
int main(int argc, char** argv){
	// ������ӳ��

	// ��ȡͼ��
	src = imread("D:/OpenCVProject/day1218/������ӳ��/������ӳ��/test.jpg");
	if (!src.data)
	{
		printf("could not load image.....");
	}
	imshow("origin image", src);

	// ����ӳ���
	map_x.create(src.size(), CV_32FC1);
	map_y.create(src.size(), CV_32FC1);
	


	int c = 0;
	while (true)
	{
		// �ȴ�����������ֵ�� ����ESC���˳�
		c = waitKey(500);
		if ((char)c == 27)
		{
			break;
		}
		index = c % 3;
		// ������ӳ�䷽��
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
				// X����ӳ��
				map_x.at<float>(row, col) = src.cols - col - 1;
				map_y.at<float>(row, col) = row;
				break;

			case 1:
				// y����ӳ��
				map_x.at<float>(row, col) = col;
				map_y.at<float>(row, col) = src.rows - row - 1;
				break;

			case 2:
				// x,y����ͬʱӳ��
				map_x.at<float>(row, col) = src.cols - col - 1;
				map_y.at<float>(row, col) = src.rows - row - 1;
				break;

			default:
				break;
			}
		}
	}



}