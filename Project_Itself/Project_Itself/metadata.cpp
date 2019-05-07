#include "matadata.h"
using namespace std;

void riff::fill_riff(string filename)
{
	ifstream in(filename, ios::binary);

	in.read((char*)&chunkId, sizeof(chunkId));//read RIFF
	in.read((char*)&chunkSize, sizeof(chunkSize));
	chunkSize += 8; //add readed chunkId(4) and chunkSize(4) sizes
	in.read((char*)&format, sizeof(format));//read WAVE
	in.close();
}


void subchank1::fill_subchank(string filename)
{
	ifstream in(filename, ios::binary);	subchank1 sub; sub;
	int trash;
	in.seekg(12);
	in.read((char*)&subchunk1Id, sizeof(subchunk1Id));
	in.read((char*)&subchunk1Size, sizeof(subchunk1Size));
	//in.read((char*)&audioFormat, sizeof(audioFormat));		2 bytes
	//in.read((char*)&numChannels, sizeof(numChannels));		2 bytes
	in.read((char*)&sampleRate, sizeof(sampleRate));
	in.read((char*)&byteRate, sizeof(byteRate));
	//in.read((char*)&blockAlign, sizeof(blockAlign));			2 bytes
	//in.read((char*)&bitsPerSample, sizeof(bitsPerSample));	2 bytes

}
