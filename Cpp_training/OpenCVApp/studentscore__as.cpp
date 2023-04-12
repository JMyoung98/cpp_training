#include "common.h"
#include"studentscore_as.h"
#include<vector>
int main() {
	string strName;
	int scorekor, scoreEng, scoreMath;
	
	vector<studentscore_as> vstss;
	while (true) {
		studentscore_as stscore;
		cout << "Input Student name : ";
		cin >> strName;
		if (strName == "q") break;
		cout << "Input Student subject{kor, Eng, Math} score : ";
		cin >> scorekor >> scoreEng >> scoreMath;
		stscore.SetStudentName(strName);
		stscore.SetsubjectScore("kor", scorekor);
		stscore.SetsubjectScore("eng", scoreEng);
		stscore.SetsubjectScore("math", scoreMath);
		vstss.push_back(stscore);
	}
	for (int i = 0; i < vstss.size(); i++) {
		vstss[i].docalc();
	}
	return 0;
}