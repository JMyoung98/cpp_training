#include"common.h"
#include"KPhone.h"

int main() {
	{//전화기를 든다
		KPhone* ph = new KPhone;
		int* pAudio = new int[11] {
			0, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8
		};
		//전화 번호 입력
		int length = 11;
		ph->Number("010-0111-1111");
		ph->Numbers(pAudio, length);//revision 2.0
		//전환 걸기
		ph->Send();

		ph->Cancel();
		//전화기를 내린다
		if (ph != nullptr) {
			delete ph;
			ph = nullptr;
		}
	}
	{
		//전화기를 듣다
		KPhone* pKphone = new KPhone();

		//전화 걸기
		pKphone->Receiver();

		//전화기를 내린다
		if (pKphone != nullptr)
		{
			delete pKphone;
			pKphone = nullptr;
		}
	}
	return 1;
}