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

/*typedef struct XMLdatabase{          //�����X�Ӫ�NODE�򥻪���� 
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
		printf("�п�J�nŪ�������(�t���ɦW):");
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
	
	//�Y�L���� c:\\test1.txt , �e���|�@�{�ӹL(�S��ܰT��) 
	if((fp=fopen( st , "r")) == NULL){
		printf("���{���䤣���ɮסA�Ч�{���]�p�̸߰�\t");
		return 0;
	}
	bool go_on = false;
	char ch;
	//string check_text = "";
	char check_text_char[10000];
	check_text_char[0] = '\0';
	int check_text_char_index = 0;
	while((ch = fgetc(fp)) != EOF){ //Ū������ɮ� (�����ɮ׵���) , �C��Ū�X�@�Ӧr��  
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
		    					printf("�{�����Ѽ�: %s\t\t���ޭ�: %s\n",check_text.c_str(),get_check_text.c_str());
		    				else
		    					printf("�{�����Ѽ�: %s\t���ޭ�: %s\n",check_text.c_str(),get_check_text.c_str());*/
		    				char buffer[200000];
		    				codecvt_char codecvtc ;
							buffer[0]='\0';
							strcat(buffer,codecvtc.UTF8ToBIG5(get_check_text_char));
							get_check_text_char[0] = '\0';
							strcat(get_check_text_char,buffer);
		    				if(strlen(check_text_char) <= 9)
		    					printf("�{�����Ѽ�: %s\t\t���ޭ�: %s\n",check_text_char,get_check_text_char);
		    				else
		    					printf("�{�����Ѽ�: %s\t���ޭ�: %s\n",check_text_char,get_check_text_char);
							//cout << "�{�����Ѽ�: " << check_text << "\t���ޭ�: " << get_check_text << endl; 
		    			}
		    			if(strcmp(check_text_char,"bounds") == 0)
		    				printf("\n----------------------------- NODE���j�u -----------------------------\n\n");
    				}
    				printf("\n############################### ���j�u ###############################\n\n");
    			}
				if(strcmp(check_text_char,"</node") == 0)
		    		printf("\n ### [�T������]������@�� </node> mode 1 ###\n\n");
		    	if(strcmp(check_text_char,"/node") == 0)
		    		printf("\n ### [�T������]������@�� </node> mode 2 ###\n\n");
    		}
    	}
	}
	fclose(fp);  //���� 
}
