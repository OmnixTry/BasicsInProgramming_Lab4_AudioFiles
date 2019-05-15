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

void riff::show_riff()
{
	cout << "chunkId\t\t" << chunkId << "\n";
	cout << "chunkSize\t" << chunkSize << "\n";
	cout << "format\t\t" << format << "\n";
}

void subchank1::fill_subchank1(string filename)
{
	ifstream in(filename, ios::binary);

	in.read((char*)&subchunk1Id, sizeof(subchunk1Id));
	in.read((char*)&subchunk1Size, sizeof(subchunk1Size));

	in.read((char*)&audioFormat, sizeof(audioFormat));		//  2 bytes
	in.read((char*)&numChannels, sizeof(numChannels));		//  2 bytes

	in.read((char*)&sampleRate, sizeof(sampleRate));
	in.read((char*)&byteRate, sizeof(byteRate));

	in.read((char*)&blockAlign, sizeof(blockAlign));		//	2 bytes
	in.read((char*)&bitsPerSample, sizeof(bitsPerSample));  //  2 bytes
	in.close();
}

void subchank1::show_subchank1()
{
	cout << "subchunk1Id\t" << subchunk1Id << "\n";
	cout << "subchunk1Size\t" << subchunk1Size << "\n";
	cout << "audioFormat\t" << audioFormat << "\n";
	cout << "numChannels\t" << numChannels << "\n";
	cout << "sampleRate\t" << sampleRate << "\n";
	cout << "byteRate\t" << byteRate << "\n";
	cout << "blockAlign\t" << blockAlign << "\n";
	cout << "bitsPerSample\t" << bitsPerSample << "\n";
}

void subchank2::fill_subchank2(string filename)
{
	ifstream in(filename, ios::binary);
	in.seekg(36);
	in.read((char*)&subchunk2Id, sizeof(subchunk2Id));// по 4 байта
	in.read((char*)&subchunk2Size, sizeof(subchunk2Size));
	in.close();
}

void subchank2::show_subchank2()
{
	cout << "subchunk2Id\t"<< subchunk2Id <<"\n";
	cout << "subchunk2Size\t"<< subchunk2Size <<"\n";
	//cout << "\t"<<  <<"\n"; for data
	//cout << "\t"<<  <<"\n";
}

void WAV::fill_wav(string filename)
{
	fill_riff(filename);
	fill_subchank1(filename);
	fill_subchank2(filename);
}

void WAV::show_wav()
{
	show_riff();
	show_subchank1();
	show_subchank2();
}
