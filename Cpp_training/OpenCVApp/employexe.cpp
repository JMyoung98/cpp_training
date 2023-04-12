#include"common.h"
#include"employee.h"

int main() {
	CDate cdata(2023, 02, 24);
	regularEmployee re("kcci", "Here", "010-1234-1234", cdata, 210);
	re.displayEmployee();
}