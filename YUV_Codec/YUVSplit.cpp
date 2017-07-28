#include "YUVSplit.h"
#include <assert.h>
#include <memory.h>

YUVSplit::YUVSplit()
{
}

YUVSplit::~YUVSplit()
{
}

int YUVSplit::YUV444_Split(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum,
	const char* strFileY, const char* strFileU, const char* strFileV)
{
	FILE* pFileYUV = fopen(strFileYUV, "rb+");
	FILE* pFileY = fopen(strFileY, "wb+");
	FILE* pFileU = fopen(strFileU, "wb+");
	FILE* pFileV = fopen(strFileV, "wb+");
	assert(pFileYUV && pFileY && pFileU && pFileV);

	int iYUVLen = iWidth * iHeight * 12 / 4;
	int iYLen = iWidth * iHeight;
	int iULen = iWidth * iHeight;
	int iVLen = iWidth * iHeight;

	unsigned char* pNewFrame = new unsigned char[iYUVLen];
	unsigned char* pPicFrame = pNewFrame;
	for (int i = 1; i <= iFrameNum; i++)
	{
		fread(pPicFrame, 1, iYUVLen, pFileYUV);
		// Y
		fwrite(pPicFrame, 1, iYLen, pFileY);
		pPicFrame += iYLen;
		// U
		fwrite(pPicFrame, 1, iULen, pFileU);
		pPicFrame += iULen;
		// V
		fwrite(pPicFrame, 1, iVLen, pFileV);
		pPicFrame += iVLen;

		printf("FrameNum : %d , YUV444_Split Finished ! \n", iFrameNum);
	}

	delete []pNewFrame;
	fclose(pFileYUV);
	fclose(pFileY);
	fclose(pFileU);
	fclose(pFileV);

	return 1;
}

int YUVSplit::YUV420_Split(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum,
	const char* strFileY, const char* strFileU, const char* strFileV)
{
	FILE* pFileYUV = fopen(strFileYUV, "rb+");
	FILE* pFileY   = fopen(strFileY,   "wb+");
	FILE* pFileU   = fopen(strFileU,   "wb+");
	FILE* pFileV   = fopen(strFileV,   "wb+");
	assert(pFileYUV && pFileY && pFileU && pFileV);

	int iYUVLen = iWidth * iHeight * 6 / 4;
	int iYLen   = iWidth * iHeight * 4 / 4;
	int iULen   = iWidth * iHeight * 1 / 4;
	int iVLen   = iWidth * iHeight * 1 / 4;

	unsigned char* pNewFrame = new unsigned char[iYUVLen];
	unsigned char* pPicFrame = pNewFrame;
	for (int i = 1; i <= iFrameNum; i++)
	{
		fread(pPicFrame, 1, iYUVLen, pFileYUV);
		// Y
		fwrite(pPicFrame, 1, iYLen, pFileY);
		pPicFrame += iYLen;
		// U
		fwrite(pPicFrame, 1, iULen, pFileU);
		pPicFrame += iULen;
		// V
		fwrite(pPicFrame, 1, iVLen, pFileV);
		pPicFrame += iVLen;

		printf("FrameNum : %d , YUV420_Split Finished ! \n", iFrameNum);
	}

	delete []pNewFrame;
	fclose(pFileYUV);
	fclose(pFileY);
	fclose(pFileU);
	fclose(pFileV);

	return 1;
}

int YUVSplit::YUV420_Half(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum, const char* strFileHalf)
{
	FILE* pFileYUV  = fopen(strFileYUV,  "rb+");
	FILE* pFileHalf = fopen(strFileHalf, "wb+");
	assert(pFileYUV && pFileHalf);

	int iYUVLen = iWidth * iHeight * 6 / 4;
	int iYLen   = iWidth * iHeight;

	unsigned char* pNewFrame = new unsigned char[iYUVLen];
	unsigned char* pPicFrame = pNewFrame;
	for (int i = 1; i <= iFrameNum; i++)
	{
		fread(pPicFrame, 1, iYUVLen, pFileYUV);
		// 减半处理;
		for (int j = 0; j < iYLen; j++)
		{
			unsigned char temp = pPicFrame[j] / 2;
			//printf("%d,\n",temp);
			pPicFrame[j] = temp;
		}
		// Half输出;
		fwrite(pPicFrame, 1, iYUVLen, pFileHalf);

		printf("FrameNum : %d , YUV420_Half Finished ! \n", iFrameNum);
	}

	delete []pNewFrame;
	fclose(pFileYUV);
	fclose(pFileHalf);

	return 1;
}

int YUVSplit::YUV420_Gray(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum, const char* strGrayFile)
{
	FILE* pFileYUV = fopen(strFileYUV, "rb+");
	FILE* pFileGray = fopen(strGrayFile, "wb+");
	assert(pFileYUV && pFileGray);

	int iYUVLen = iWidth * iHeight * 6 / 4;
	int iYLen   = iWidth * iHeight;
	int iUVLen  = iWidth * iHeight / 2;

	unsigned char* pNewFrame = new unsigned char[iYUVLen];
	unsigned char* pPicFrame = pNewFrame;
	for (int i = 1; i <= iFrameNum; i++)
	{
		fread(pPicFrame, 1, iYUVLen, pFileYUV);
		// 置灰处理;
		memset(pPicFrame + iYLen, 128, iUVLen);
		// Half输出;
		fwrite(pPicFrame, 1, iYUVLen, pFileGray);

		printf("FrameNum : %d , YUV420_Gray Finished ! \n", iFrameNum);
	}

	delete []pNewFrame;
	fclose(pFileYUV);
	fclose(pFileGray);

	return 1;
}

int YUVSplit::YUV420_Border(const char* strFileYUV, const int iWidth, const int iHeight, const int iFrameNum, 
	const char* strFileBorder, const int iBorder)
{
	FILE* pFileYUV    = fopen(strFileYUV,   "rb+");
	FILE* pFileBorder = fopen(strFileBorder, "wb+");
	assert(pFileYUV && pFileBorder);

	int iYUVLen = iWidth * iHeight * 6 / 4;
	int iYLen = iWidth * iHeight;

	unsigned char* pNewFrame = new unsigned char[iYUVLen];
	unsigned char* pPicFrame = pNewFrame;
	for (int i = 1; i <= iFrameNum; i++)
	{
		fread(pPicFrame, 1, iYUVLen, pFileYUV);
		for (int j = 0; j < iHeight; j++)
		{
			if ( j >= iBorder && j <= (iHeight - iBorder) )
			{
				continue;
			}
			for (int k = 0; k < iWidth; k++)
			{
				if (k >= iBorder && k <= (iWidth - iBorder))
				{
					continue;
				}
				pPicFrame[j*iWidth + k] = 255;	// 边框白色;
				//pPicFrame[j*iWidth + k] = 0;	// 边框黑色;
			}
		}
		fwrite(pPicFrame, 1, iYUVLen, pFileBorder);

		printf("FrameNum : %d , YUV420_Border Finished ! \n", iFrameNum);
	}

	delete[]pNewFrame;
	fclose(pFileYUV);
	fclose(pFileBorder);

	return 1;
}

int YUVSplit::RGB24_To_BMP(const char* strFileRGB24, const int iWidth, const int iHeight, const char* strFileBmp)
{
	BITMAPFILEHEADER bmpFileHeader;
	memset(&bmpFileHeader, 0, sizeof(bmpFileHeader));

	bmpFileHeader.bfType = unsigned char('B') << 8 + unsigned char('M');
	bmpFileHeader.bfSize = 100;
	bmpFileHeader.bfOffBits = sizeof(BITMAPINFOHEADER);

	BITMAPINFOHEADER	bmpInfoHeader;
	memset(&bmpInfoHeader, 0, sizeof(bmpInfoHeader));


	return 1;
}
