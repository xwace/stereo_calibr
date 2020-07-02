//
// Created by qzj on 2020/6/27.
//
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <fstream>
#include "util.h"
#include <stdio.h>

using namespace cv;
using namespace std;

// 检查标定效果的文件
int main(int argc, char *argv[]) {
    cv::CommandLineParser parser(argc, argv,
                                 "{w|11|}{h|8|}{s|15|}{d|/media/qzj/Document/grow/research/slamDataSet/sweepRobot/round2/cali|}{show|true|}{help||}");
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }
    //读入总文件夹
    string root_path = parser.get<string>("d");
    string root_result_path = root_path + "/result/";
    //创建文件夹
    createDirectory(root_result_path);
    //选用参数文件
    string configYaml = root_result_path + "data_params_matlab.yaml";
     //可视化
     CheckStereoCali(root_path, configYaml);
}