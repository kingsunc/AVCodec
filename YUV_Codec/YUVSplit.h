#pragma once
#include <windows.h>
#include "stdio.h"

class YUVSplit
{
public:
	YUVSplit();
	~YUVSplit();

	// 分割YUV444文件的Y、U、V数据到 strFileY、 strFileU、 strFileV文件;
	static int YUV444_Split(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum,
		const char* strFileY, const char* strFileU, const char* strFileV);

	// 分割YUV420文件的Y、U、V数据到 strFileY、 strFileU、 strFileV文件;
	static int YUV420_Split(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum,
		const char* strFileY, const char* strFileU, const char* strFileV);

	// 将YUV420文件的亮度Y数据减半;
	static int YUV420_Half(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum, const char* strFileHalf);

	// 将YUV420图像进行灰处理(所有UV数据为128);
	static int YUV420_Gray(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum, const char* strFileGray);

	// 将YUV420图像进行边框范围处理;
	static int YUV420_Border(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum, 
		const char* strFileBorder, const int iBorder);

	// RGB24->BMP;
	static int RGB24_To_BMP(const char* strFileRGB24, const int iWidth, const int iHeight, const char* strFileBmp);

};