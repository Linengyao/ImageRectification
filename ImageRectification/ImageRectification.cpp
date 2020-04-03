// ImageRectification.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat	srcMat = cv::imread("E:\\课程\\大二下\\数字图像处理\\lena_rot.jpg", 1);
	if (srcMat.empty())	return -1;

	int height = srcMat.rows; //行数
	int width = srcMat.cols;//每行元素数量
	//变换前的四点坐标
	cv::Point2f pts1[4];
	//左上角
	for (int j = 0; j < width; j++)
	{
		int i = 0;
		if ((srcMat.at<Vec3b>(i,j)[0] > 250) && (srcMat.at<Vec3b>(i,j)[1] > 250) && (srcMat.at<Vec3b>(i,j)[2] > 250))
		{

		}
		else

		{
			pts1[0] = cv::Point2f(j,i);
			break;
		}
	}

	//右上角
	for (int i = 0; i < height; i++)
	{
		int j = width-1;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[1] = cv::Point2f(j,i);
			break;
		}
	}
	//右下角
	for (int j = width-1; j >=0; j--)
	{
		int i = height-1;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[2] = cv::Point2f(j,i);
			break;
		}
	}
	//左下角
	for (int  i= height-1; i >=0;	i--)
	{
		int j = 0;
		if ((srcMat.at<Vec3b>(i, j)[0] > 250) && (srcMat.at<Vec3b>(i, j)[1] > 250) && (srcMat.at<Vec3b>(i, j)[2] > 250))
		{

		}
		else

		{
			pts1[3] = cv::Point2f(j, i);
			break;
		}
	}


	//变换后的四点坐标
	cv::Point2f pts2[] = {
						cv::Point2f(0,0),
						cv::Point2f(width - 1,0),
						cv::Point2f(width - 1,height - 1),
						cv::Point2f(0,height - 1) };
	//透视变换行列式计算
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	//变换
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());

	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
