#include "pcm2aac.h"

int main()
{
	wav2aac("../testfile/wav_out.wav", "../testfile/aac_out.aac");

	getchar();
	return 1;
}