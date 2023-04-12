#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif
using namespace std;


int main()
{

	std::cout << "Hello World!\n";
	cv::Mat img = cv::imread("jetson.bmp", cv::IMREAD_GRAYSCALE);
	cv::Mat color = cv::Mat(img.rows, img.cols, cv::IMREAD_COLOR);
	cv::imshow("jetson", img);
	if (img.empty()) {
		return -1;
	}
	for (size_t row = 0; row < img.rows; row++) {
		for (size_t col = 0; col < img.cols; col++) {
			int index = (row * img.cols + col);
			int y = img.data[index + 0];
			int cb = img.data[index + 1];
			int cr = img.data[index + 2];
			float r =	  1.000*y + 1.402*cr + 0.000*cb;
			float g =	  1.000*y + 0.714*cr -0.344 *cb;
			float b =	  1.000*y + 0.000*cr + 1.772*cb;
			color.data[index + 0] = static_cast<uchar>(b);
			color.data[index + 1] = static_cast<uchar>(g);
			color.data[index + 2] = static_cast<uchar>(r);
			
		}
		
	}
	cv::imshow("gray2color", color);

	cv::waitKey(0);
	cv::destroyAllWindows();
}