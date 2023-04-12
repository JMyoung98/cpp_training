#include "common.h"
#include"studentscore1_0.h"
#include<vector>
int main() {
	string strName;
	int scoresub;
	int subcnt;
	string strsub;
	cout << "Add subject's count : ";
	cin >> subcnt;
	vector<studentscore1_0> vstss;
	while (true) {
		studentscore1_0 stscore;
		cout << "Input Student name : ";
		cin >> strName;
		if (strName == "q") break;
		stscore.SetStudentName(strName);
		for (int j = 0; j < subcnt; j++) {
			cout << "Input subject : ";
			cin >> strsub;
			cout << "Input Student subject score : ";
			cin >> scoresub;
			stscore.SetsubjectScore(strsub, scoresub);
		}	
		vstss.push_back(stscore);
	}
	for (int i = 0; i < vstss.size(); i++) {
		vstss[i].docalc();
	}
	return 0;
}