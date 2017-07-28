#include "YUVSplit.h"

int main()
{
	/*YUVSplit::YUV444_Split("./testfile/yuv444_split/lena_256x256.yuv", 256, 256, 1,
		"./testfile/yuv444_split/lena_256x256.y",
		"./testfile/yuv444_split/lena_256x256.u",
		"./testfile/yuv444_split/lena_256x256.v");

	YUVSplit::YUV420_Split("./testfile/yuv420_split/lena_256x256.yuv", 256, 256, 1,
		"./testfile/yuv420_split/lena_256x256.y",
		"./testfile/yuv420_split/lena_256x256.u",
		"./testfile/yuv420_split/lena_256x256.v");

	YUVSplit::YUV420_Half("./testfile/lena_256x256_420.yuv", 256, 256, 1, "./testfile/lena_256x256_420_half.yuv");

	YUVSplit::YUV420_Gray("./testfile/lena_256x256_420.yuv", 256, 256, 1, "./testfile/lena_256x256_420_gray.yuv");

	YUVSplit::YUV420_Border("./testfile/lena_256x256_420.yuv", 256, 256, 1, "./testfile/lena_256x256_420_border.yuv", 5);*/

	YUVSplit::RGB24_To_BMP("./testfile/lena_256x256_420.rgb", 256, 256, "./testfile/lena_256x256_420.bmp" );

	return 1;
}