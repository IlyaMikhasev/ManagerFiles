#include <iostream>
#include "ManagerFiles.h"
int main() {
	setlocale(LC_ALL, "Russian");
	M_Files<std::string> mfstring;
	M_Files<int> mfint;
	mfstring.Add_file(1, "book");
	mfstring.Add_file(3, "step");
	mfstring.Add_file(4, "flip");
	mfstring.Add_file(24, "lock");
	mfstring.Add_file(3, "hand");
	mfstring.Set_file(3, "hand");
	mfstring.Deleted_file(24);
	std::cout<<mfstring.Get_file(3)<<'\n';
	std::cout << "Часто используемый id: " << mfstring.mostPopularKeyToFind() << std::endl;
	return 0;
}