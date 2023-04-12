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
		cout << "이름 : ";
		cin >> name;
		if (name == "q") {
			break;
		}
		cout << "과목 : ";
		for (int j = 0; j < 6; j++) {
			cin >> sub[j];
		}
		cout << "점수 : ";
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