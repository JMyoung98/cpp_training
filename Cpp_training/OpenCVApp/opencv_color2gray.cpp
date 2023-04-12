#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif
using namespace std;

int sum(const uchar* const pData, int width, int height,
	int start_row, int finish_row, int start_col, int finish_col) {
	int sum = 0;

	for (int rows = start_row; rows <= finish_row; rows++) {
		for (int cols = start_col; cols <= finish_col; cols++) {
			int index = (rows * width + cols);
			cout << rows*finish_col+cols << " : " << static_cast<int>(pData[index])<<"\t";
			sum += static_cast<int>(pData[index]);
		}
		cout << endl;
	}
	return sum;
}

int main()
{

	std::cout << "Hello World!\n";
	cv::Mat img = cv::imread("jetson.bmp", cv::IMREAD_COLOR);
	cv::Mat gray = cv::Mat(img.rows, img.cols, cv::IMREAD_GRAYSCALE);
	cv::imshow("jetson", img);
	if (img.empty()) {
		return -1;
	}
	for (size_t row = 0; row < img.rows; row++) {
		for (size_t col = 0; col < img.cols; col++) {
			int index = (row * img.cols + col)*3;
			int b = img.data[index + 0];
			int g = img.data[index + 1];
			int r = img.data[index + 2];
			float y = (0.299 * r + 0.587 * g + 0.114 * b);
			float cb =(-(0.169 * r) - (0.331 * g) + (0.500 * b));
			float cr = ((0.500 * r) - (0.419 * g) - (0.0813 * b));
			
			gray.data[index/3] = static_cast<uchar>(y);
		}
		
	}
	cout << "image data sum = " << sum(gray.data, gray.cols, gray.rows, 1, 3, 1, 3) << endl;
	cv::imshow("color2gray", gray);

	cv::waitKey(0);
	cv::destroyAllWindows();
}