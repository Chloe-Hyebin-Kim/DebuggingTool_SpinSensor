// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "framework.h"

#ifndef _DEBUG
//#pragma comment(lib, "opencv_world3416.lib")
#pragma comment(lib, "opencv_world440.lib")
#else
//#pragma comment(lib, "opencv_world3416d.lib")
#pragma comment(lib, "opencv_world440d.lib")
#endif

#pragma comment(lib, "winmm.lib")

#include <opencv2/opencv.hpp> // for video
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


#define GZ_SHOTDB_ROOT		_T("C:\\GVS_SHOTDB")
#define GZ_SHOTDB_GRC		_T("C:\\GVS_SHOTDB\\GRC")
#define GZ_LOGDB_PATH		_T("C:\\GVS_SHOTDB\\LOG")

#define MAXLOGSIZE 1024

#define MAX_FILES 2
#define IMG_NUM 5
#define TIMERSEC 1000 //0.5초

#define MAXBALLRADIUS 120
#define MINBALLRADIUS 35


#define	RESOLUTION_X	2048 //#define FULLIMAGESIZEHOR 2048
#define RESOLUTION_Y	1088 //#define FULLIMAGESIZEVER 1088
#define CENTER_X	1024
#define CENTER_Y	544

#define READY_IMAGE_WIDTH		2048
#define READY_IMAGE_HEIGHT		1088

#define TRAJ_IMAGE_WIDTH		2048
#define TRAJ_IMAGE_HEIGHT		660

#define BALL_IMAGE_WIDTH 100
#define BALL_IMAGE_HEIGHT 100
#define BALL_IMAGE_SIZE 10000

#define SHOT_BUFFER_SIZE			20
#define PREVIEW_BUFFER_SIZE			90


#define	BALL_SIZE		(4.27) //cm
#define	BALL_HALF		(2.135)//cm

#define M_PI 3.14159265358979323846
#define DE2RA 0.01745329252
#define RA2DE 57.2957795129


#define COLOR_MAX 255
#define LOWER 0
#define UPPER 1


#endif //PCH_H
