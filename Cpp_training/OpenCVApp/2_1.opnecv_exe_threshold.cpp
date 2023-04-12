#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif

int main()
{

	std::cout << "Hello World!\n";
	cv::Mat img = cv::imread("jetson.bmp", cv::IMREAD_GRAYSCALE);

	cv::imshow("jetson", img);
	int width = img.cols;
	int height = img.rows;
	unsigned char* pData = img.data;

	int threshold = 180;

	int mask_width = 3; int mask_heihgt = 3;
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			int index = row * width + col;
			//for (int i = 0; i < 3; i++) {
				//if (col >= 0 && col < mask_width) {
				//	if (row >= 0 && row < mask_heihgt) {
						//for (int i = 0; i < 3; i++) {
						if (pData[index] > threshold) {
							pData[index] = 255;
						}
						else {
							pData[index] = 0;
						}
						//}
				//	}
				//}
				//if (col >= width - mask_width && col < width) {
				//	if (row >= 0 && row < mask_heihgt) {
				//		//for (int i = 0; i < 3; i++) {
				//		pData[index ] = 255;
				//		//}
				//	}
				//}
				//if (col >= 0 && col < mask_width) {
				//	if (row >= height - mask_heihgt && row < height) {
				//		//for (int i = 0; i < 3; i++) {
				//		pData[index ] = 255;
				//		//}
				//	}
				//}
				//if (col >= width - mask_width && col < width) {
				//	if (row >= height - mask_heihgt && row < height) {
				//		//for (int i = 0; i < 3; i++) {
				//		pData[index ] = 255;
				//		//}
				//	}
				//}
			//}
		}
	}
	cv::Mat thrimg;
	cv::threshold(img, thrimg, threshold, 255, cv::THRESH_BINARY);
	cv::imshow("jetson", img);
	cv::waitKey(0);
	cv::destroyAllWindows();

}