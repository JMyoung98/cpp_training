#include "common.h"
#include "StudentScore.h"
#include <vector>
int main() {
	string name;
	string sub[6];
	int score[6] = { 0, };
	vector<StudentScore> vst;
	while (true) {
		StudentScore st;
		st.struct_clear();
		cout << "�̸� : ";
		cin >> name;
		if (name == "q") {
			break;
		}
		cout << "���� : ";
		for (int j = 0; j < 6; j++) {
			cin >> sub[j];
		}
		cout << "���� : ";
		for (int k = 0; k < 6; k++) {
			cin >> score[k];
		}
		st.SetStudentName(name);
		st.SetSubjectScore(sub, score);
		//st.Docalc();
		vst.push_back(st);
	}
	for (int i = 0; i < vst.size(); i++)
	{
		StudentScore* pSt = &vst[i];
		pSt->Docalc();
	}
}