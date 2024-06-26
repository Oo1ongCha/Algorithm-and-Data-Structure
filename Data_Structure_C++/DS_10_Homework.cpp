// Homework10.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;
class Show_Poems {
	vector <wstring>  poem;
public:
	Show_Poems(const string& fname) {
		wifstream  infile(fname.c_str());
		infile.imbue(locale("zh_TW.UTF-8"));  // 用來表示檔案為 UTF-8 檔
		wstring line;

		while (getline(infile, line)) {
			poem.push_back(line);
		}
	}

	friend wostream& operator << (wostream& out, const Show_Poems& foo) {
		int i, j, k, n;
		for (i = 0; i < 7; i++) { // 7列
			for (j = 0; j < 7; j++) { // 7首詩
				for (k = 0; k < 4; k++) { // 4行
					if (foo.poem[j].size() < 25) {
						if (i < 5) {
							n = 20 - 5 * (k + 1) + i;
							out << foo.poem[j][n];
						}
						else out << "  ";
					}
					else {
						n = 28 - 7 * (k + 1) + i;
						out << foo.poem[j][n];
					}
				}
				out << "  ";
			}
			out << endl;
		}
		return out;
	};
};

int main()
{
	setlocale(LC_ALL, "zh_TW.UTF-8");
	Show_Poems  foo("poem.dat");
	wcout << foo << endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣:
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案