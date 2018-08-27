#include "codecvt_char.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
 
using namespace std;

static string XML_db_code_name[] = {
		"class","bounds","selected","password",
		"long-clickable","scrollable","focused",
		"focusable","enabled","clickable",
		"checked","checkable","content-desc",
		"package","resource-id","text","index","end;"};

/*typedef struct XMLdatabase{          //手機抓出來的NODE基本的資料 
	char* class_name;
	int bounds[2];
	bool selected;
	bool password;
	bool long_clickable;
	bool scrollable;
	bool focused;
	bool focusable;
	bool enabled;
	bool clickable;
	bool checked;
	bool checkable;
	char* content_desc;
	char* package;
	char* resource_id;
	char* text;
	int index;
	struct XMLdatabase *link;
}XMLdb;

XMLdb database;

*/

void get_node(char* st);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	while(1){
		system("cls");
		char str[1000];
		printf("請輸入要讀取的文件(含副檔名):");
		scanf("%s",str);
		printf("\n\n\n");
		
		//get_node("testcode.xml");
		//get_node("index.xml");
		get_node(str);
		//printf("XMLdb size is : %d",sizeof(database));
		system("pause");
	}
	return 0;
}

void get_node(char* st){
	FILE *fp;
	
	//若無此檔 c:\\test1.txt , 畫面會一閃而過(沒顯示訊息) 
	if((fp=fopen( st , "r")) == NULL){
		printf("此程式找不到檔案，請找程式設計者詢問\t");
		return 0;
	}
	bool go_on = false;
	char ch;
	//string check_text = "";
	char check_text_char[10000];
	check_text_char[0] = '\0';
	int check_text_char_index = 0;
	while((ch = fgetc(fp)) != EOF){ //讀取整個檔案 (直到檔案結尾) , 每次讀出一個字元  
    	if(!go_on){
    		if(ch == '<'){
    			//check_text = "";
    			check_text_char_index = 0;
    			check_text_char[check_text_char_index] = '\0';
    			while((ch = fgetc(fp))!=' ' && ch != '>' && ch != EOF){
    				//check_text += ch;
    				check_text_char[check_text_char_index] = ch;
    				check_text_char[++check_text_char_index] = '\0';
    			}
    			//if(strcmp(check_text.c_str(),"node") == 0){
    			if(strcmp(check_text_char,"node") == 0){
    				bool marker = false;
    				//while(!(strcmp(check_text.c_str(),"</node") == 0)){
    				while(!(strcmp(check_text_char,"</node") == 0)){
    					//check_text = "";
    					check_text_char_index = 0;
    					check_text_char[check_text_char_index] = '\0';
    					
    					//string get_check_text = "";
    					char get_check_text_char[100000];
    					int get_check_text_char_index = 0;
    					get_check_text_char[get_check_text_char_index] = '\0';
    					while((ch = fgetc(fp))!='=' && ch != ' ' && ch != '>' && ch != EOF){
		    				//check_text += ch;
		    				check_text_char[check_text_char_index] = ch;
    						check_text_char[++check_text_char_index] = '\0';
		    			}
		    			if(ch == '='){
		    				if((ch = fgetc(fp)) == '"')
		    					marker = true;
		    				while(marker){
		    					if((ch = fgetc(fp)) == '"')
		    						break;
		    					//get_check_text += ch;
		    					get_check_text_char[get_check_text_char_index] = ch;
    							get_check_text_char[++get_check_text_char_index] = '\0';
		    				}
		    				/*if(strlen(check_text.c_str()) <= 9)
		    					printf("程式抓到參數: %s\t\t索引值: %s\n",check_text.c_str(),get_check_text.c_str());
		    				else
		    					printf("程式抓到參數: %s\t索引值: %s\n",check_text.c_str(),get_check_text.c_str());*/
		    				char buffer[200000];
		    				codecvt_char codecvtc ;
							buffer[0]='\0';
							strcat(buffer,codecvtc.UTF8ToBIG5(get_check_text_char));
							get_check_text_char[0] = '\0';
							strcat(get_check_text_char,buffer);
		    				if(strlen(check_text_char) <= 9)
		    					printf("程式抓到參數: %s\t\t索引值: %s\n",check_text_char,get_check_text_char);
		    				else
		    					printf("程式抓到參數: %s\t索引值: %s\n",check_text_char,get_check_text_char);
							//cout << "程式抓到參數: " << check_text << "\t索引值: " << get_check_text << endl; 
		    			}
		    			if(strcmp(check_text_char,"bounds") == 0)
		    				printf("\n----------------------------- NODE分隔線 -----------------------------\n\n");
    				}
    				printf("\n############################### 分隔線 ###############################\n\n");
    			}
				if(strcmp(check_text_char,"</node") == 0)
		    		printf("\n ### [訊息提供]偵測到一個 </node> mode 1 ###\n\n");
		    	if(strcmp(check_text_char,"/node") == 0)
		    		printf("\n ### [訊息提供]偵測到一個 </node> mode 2 ###\n\n");
    		}
    	}
	}
	fclose(fp);  //關檔 
}
