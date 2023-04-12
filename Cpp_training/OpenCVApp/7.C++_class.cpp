#include "common.h"

int main() {
	
	
	{//����
		Calc calc(1,1,'+');
		//calc.Clear();
		int score[5] = { 10,5,6,80,10 };
		int score_size = sizeof(score) / sizeof(score[0]);
		//calc.setValue(1, 2, '+');
		std::cout << "�μ��� �� : " << calc.Doresult() << std::endl;
		calc.setValue(1, 2, '-');
		std::cout << "�μ��� �� : " << calc.Doresult() << std::endl;
		calc.setValue(1, 2, '*');
		std::cout << "�μ��� �� : " << calc.Doresult() << std::endl;
		calc.setValue(1, 2, '/');
		std::cout << "�μ��� �� : " << calc.Doresult() << std::endl;
		std::cout << std::endl << "add : " << calc.add(score, score_size) << std::endl
		<< "avg : " << calc.average(score, score_size) << std::endl
 
			<< "max : " << calc.max(score, score_size) << std::endl
		<< "min : " << calc.min(score, score_size) << std::endl; 
		std::cout << calc.allsum(6, 7)<<std::endl;
		
	}
	
	{//�����Ҵ�
		Calc* pcalc = new Calc(1, 1, '+');
		int score[5] = { 10,5,6,80,10 };
		int score_size = sizeof(score) / sizeof(score[0]);
		std::cout << pcalc->add(score, score_size) << std::endl;

		if (pcalc != nullptr) {
			delete pcalc;
			pcalc = nullptr;
		}
	}
	
	{//����Ʈ ������
		std::shared_ptr<Calc> pcalc = std::make_shared < Calc>(1, 1, '+');
		int score[5] = { 10,5,6,80,10 };
		int score_size = sizeof(score) / sizeof(score[0]);
		std::cout << pcalc->add(score, score_size) << std::endl;
	}
	return 1;
}