#pragma once
#include "common.h"
class KPhone
{
public:
	KPhone();
	~KPhone();
	std::string Send();
	int Receiver();
	std::string Number(std::string num);
	int Numbers(int* pAudioData, int length);
	int Cancel();//ÀüÈ­ ²÷±â
private:
	std::string strNumber;
	bool isConnected;
};



