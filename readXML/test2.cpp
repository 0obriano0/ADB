#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <windows.h>
  
using namespace std;

// GB2312, BIG5, UTF8之?的??通?Unicode充?切?的?梁
// 例如: GB2312<->Unicode<->BIG5
 
#define CODEPAGE_GB2312		936
#define CODEPAGE_BIG5		950 
#define CODEPAGE_UTF8		65001
 
// ??成Unicode
wchar_t* ToWideChar(const char* pStr, int nCodePage)
{
	int nStrLen = MultiByteToWideChar(nCodePage, 0, pStr, -1, NULL, 0);
	wchar_t* pWStr = new wchar_t[nStrLen + 1];
	memset(pWStr, 0, nStrLen + 1);
	MultiByteToWideChar(nCodePage, 0, pStr, -1, pWStr, nStrLen);
	return pWStr;
}
 
// ??成多字?
char* ToMultiByte(const wchar_t* pWStr, int nCodePage)
{
	int nStrLen = WideCharToMultiByte(nCodePage, 0, pWStr, -1, NULL, 0, NULL, NULL);
	char* pStr = new char[nStrLen + 1];
	memset(pStr, 0, nStrLen + 1);
	WideCharToMultiByte(nCodePage, 0, pWStr, -1, pStr, nStrLen, NULL, NULL);
	return pStr;
}
 
char* CPTransform(const char* pStrSrc, int nCPSrc, int nCPTar)
{
	wchar_t* pWStr = ToWideChar(pStrSrc, nCPSrc);
	char* pStr = ToMultiByte(pWStr, nCPTar);
	delete [] pWStr;
	return pStr;
}
 
// GB2312?UTF8
char* GB2312ToUTF8(const char* pStrGB2312)
{
	return CPTransform(pStrGB2312, CODEPAGE_GB2312, CODEPAGE_UTF8);
}
 
// UTF8?GB2312
char* UTF8ToGB2312(const char* pStrUTF8)
{
	return CPTransform(pStrUTF8, CODEPAGE_UTF8, CODEPAGE_GB2312);
}
 
// GB2312?BIG5
char* GB2312ToBIG5(const char* pStrBIG5)
{
	return CPTransform(pStrBIG5, CODEPAGE_GB2312, CODEPAGE_BIG5);
}
 
// BIG5?GB2312
char* BIG5ToGB2312(const char* pStrBIG5)
{
	return CPTransform(pStrBIG5, CODEPAGE_BIG5, CODEPAGE_GB2312);
}
 
// UTF8?BIG5
char* UTF8ToBIG5(const char* pStrUTF8)
{
	return CPTransform(pStrUTF8, CODEPAGE_UTF8, CODEPAGE_BIG5);
}
 
// BIG5?UTF8
char* BIG5ToUTF8(const char* pStrBIG5)
{
	return CPTransform(pStrBIG5, CODEPAGE_BIG5, CODEPAGE_UTF8);
}

void openfile(char *st,int mode){
	FILE *fp;
	
	//若無此檔 c:\\test1.txt , 畫面會一閃而過(沒顯示訊息) 
	if((fp=fopen( st , "r")) == NULL){
		printf("此程式找不到檔案，請找程式設計者詢問\t");
		return 0;
	}
	char ch;
	//string str = "";
	char str_char[1000000];
	int str_char_index = 0;
	str_char[str_char_index] = '\0';
	while((ch = fgetc(fp))!= EOF){
		//str += ch;
		str_char[str_char_index] = ch;
		str_char[++str_char_index] = '\0';
		printf("ch = %c ch = %x\n",ch,ch);
	}
	if(mode == 1){
		
	}else if(mode == 2){
		//utf8_to_string(str_char);
		char buffer[10000];
		buffer[0]='\0';
		strcat(buffer,UTF8ToBIG5(str_char));
		str_char[0] = '\0';
		strcat(str_char,buffer);
	}
	
	//cout << "str = " << str.c_str() << endl << endl;
	cout << "str_char = " << str_char << endl << endl;
}

int main(){
	//string data = "中文";
	char data[14] = "所有應用程式2";
	cout << data << endl;
	//printf("data = %s\n\n",data.c_str());
	printf("data = %s\n\n",data);
	for(int loopnum1 = 0;data[loopnum1]!='\0';loopnum1++){
		printf("ch = %c ch = %x\n",data[loopnum1],data[loopnum1]);
	}
	cout << endl << endl << "-------------------------------------- test2(big5) --------------------------------------" << endl; 
	openfile("test2(big5).txt",0);
	cout << endl << endl << "------------------------------------- test2(gb2312) -------------------------------------" << endl; 
	openfile("test2(gb2312).txt",0);
	cout << endl << endl << "--------------------------------------- test2.txt ---------------------------------------" << endl; 
	openfile("test2.txt",0);
	cout << endl << endl << "--------------------------------------- test2.xml ---------------------------------------" << endl; 
	openfile("test2.xml",2);	/**/
	system("pause");
}
