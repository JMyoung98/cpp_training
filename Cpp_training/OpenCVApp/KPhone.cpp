#include "KPhone.h"
#include "common.h"

KPhone::KPhone()
	:strNumber(""),
	isConnected(true)	// true : 전화중 x
						// false : 전화중
{
	std::cout << "KPHONE::Ctor" << std::endl;
}

KPhone::~KPhone()
{
	std::cout << "KPHONE::Dtor" << std::endl;
}

std::string KPhone::Send()
{
	
	/*if (isConnected ==true)
	{
		return strNumber;
	}
	else {
		return "전화중";
	}*/
	if (strNumber == "010-1111-1111") {
		std::cout << "wrong number" << std::endl;
		
	}
	if (isConnected == true) {
		std::cout << "On the phone" << std::endl;
		
	}
	std::cout << "calling" << std::endl;
	std::cout << "linked" << std::endl;
	isConnected = true;

	std::cout << "communication start" << std::endl;

	////Cancel
	//std::cout << "communication finish" << std::endl;
	//isConnected = false;

	return "";
}

int KPhone::Receiver()
{
	if (isConnected == true)
	{
		std::cout << "on the phone" << std::endl;
		
	}

	std::cout << "linked" << std::endl;

	isConnected = true;

	std::cout << "communication start" << std::endl;

	//Cancel
	//std::cout << "communication finish" << std::endl;
	//isConnected = false;
	return 0;
	//isConnected = !isConnected;
	//return isConnected;
}

std::string KPhone::Number(std::string num)
{
	strNumber = num;
	return strNumber;
}

int KPhone::Numbers(int* pAudioData, int length)
{
	//pAudioData 분석
	//음석인식 알고리즘 넣어줘
	std::string number = "010-1234-5678";// DoAnalysisAudioData(pAudioData, length);
	strNumber = number;
	//결과로 문자를 반환
	return 0;
}


int KPhone::Cancel()
{
	std::cout << "cancel button activated" << std::endl;

	//Cancel
	std::cout << "communication finish" << std::endl;
	isConnected = false;
	return 0;
}

