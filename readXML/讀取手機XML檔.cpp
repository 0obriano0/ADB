#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
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

string iso_8859_1_to_utf8(string &str)
{
	
    string strOut;
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        uint8_t ch = *it;
        if (ch < 0x80) {
            strOut.push_back(ch);
        }
        else {
            strOut.push_back(0xc0 | ch >> 6);
            strOut.push_back(0x80 | (ch & 0x3f));
        }
    }
    return strOut;
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
	string check_text = "";
	while((ch = fgetc(fp)) != EOF){ //Ū������ɮ� (�����ɮ׵���) , �C��Ū�X�@�Ӧr��  
    	if(!go_on){
    		if(ch == '<'){
    			check_text = "";
    			while((ch = fgetc(fp))!=' ' && ch != '>' && ch != EOF){
    				check_text += ch;
    			}
    			if(strcmp(check_text.c_str(),"node") == 0){
    				bool marker = false;
    				while(!(strcmp(check_text.c_str(),"</node") == 0)){
    					check_text = "";
    					string get_check_text = "";
    					while((ch = fgetc(fp))!='=' && ch != ' ' && ch != '>' && ch != EOF){
		    				check_text += ch;
		    			}
		    			if(ch == '='){
		    				if((ch = fgetc(fp)) == '"')
		    					marker = true;
		    				while(marker){
		    					if((ch = fgetc(fp)) == '"')
		    						break;
		    						get_check_text += ch;
		    				}
							
		    				if(strlen(check_text.c_str()) <= 9)
		    					printf("�{�����Ѽ�: %s\t\t���ޭ�: %s\n",check_text.c_str(),get_check_text.c_str());
		    				else
		    					printf("�{�����Ѽ�: %s\t���ޭ�: %s\n",check_text.c_str(),get_check_text.c_str());
							//cout << "�{�����Ѽ�: " << check_text << "\t���ޭ�: " << get_check_text << endl; 
		    			}
		    			if(strcmp(check_text.c_str(),"bounds") == 0)
		    				printf("\n----------------------------- NODE���j�u -----------------------------\n\n");
    				}
    				printf("\n############################### ���j�u ###############################\n\n");
    			}
				if(strcmp(check_text.c_str(),"</node") == 0)
		    		printf("\n ### [�T������]������@�� </node> mode 1 ###\n\n");
		    	if(strcmp(check_text.c_str(),"/node") == 0)
		    		printf("\n ### [�T������]������@�� </node> mode 2 ###\n\n");
    		}
    	}
	}
	fclose(fp);  //���� 
}

int main(){
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
}
