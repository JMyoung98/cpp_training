#include"common.h"
#include"KPhone.h"

int main() {
	{//��ȭ�⸦ ���
		KPhone* ph = new KPhone;
		int* pAudio = new int[11] {
			0, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8
		};
		//��ȭ ��ȣ �Է�
		int length = 11;
		ph->Number("010-0111-1111");
		ph->Numbers(pAudio, length);//revision 2.0
		//��ȯ �ɱ�
		ph->Send();

		ph->Cancel();
		//��ȭ�⸦ ������
		if (ph != nullptr) {
			delete ph;
			ph = nullptr;
		}
	}
	{
		//��ȭ�⸦ ���
		KPhone* pKphone = new KPhone();

		//��ȭ �ɱ�
		pKphone->Receiver();

		//��ȭ�⸦ ������
		if (pKphone != nullptr)
		{
			delete pKphone;
			pKphone = nullptr;
		}
	}
	return 1;
}