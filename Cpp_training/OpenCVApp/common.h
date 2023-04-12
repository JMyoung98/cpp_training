#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <opencv2/opencv.hpp>
#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif
using namespace std;
using namespace cv;