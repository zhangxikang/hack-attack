#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>
#include <stdio.h>
#include<conio.h>

#include "hacker.h"

using namespace std;

#define WIDTH		80
#define HEIGHT	25

/*����cmd��С*/
void init(void) {
	//mode con cols=80 lines=40
	char cmd[128]; 
	sprintf(cmd, "mode con cols=%d lines=%d", WIDTH, HEIGHT);
	system(cmd);
}

/*��������*/
void input_pwd(char pwd[], int max_len) {
	char c;
	int i = 0;
		
	while (1) {
		c = getch();
        // getch�������뻺�����ж�ȡ
		//��getch�У��ѻس��������룬ʶ��Ϊ�س���'\r'
        //��getchar�У��ѻس��������룬ʶ��Ϊ���з�'\n'
		if (c == '\r' || i >= max_len) {  
			pwd[i] = 0;
			break;
		}
		pwd[i++] = c;
		printf("*", c);
	}
	printf("\n");
}


/*������ʾ�ַ���*/
void printInMiddle(string msg) {
	int space = (WIDTH - msg.length()) /2 ;
	for (int i=0; i<space; i++) {
		cout << " ";
	}
	cout << msg << endl;
}


void login(void) {
	string name;
	//string pwd;
	char pwd[16];

	while (1) {
		system("cls");

		std::cout << "�������˺ţ�";
		std::cin >> name;

		std::cout << "���������룺";
		//std::cin >> pwd;
		input_pwd(pwd, sizeof(pwd));

		if (name == "54hk" && !strcmp(pwd, "123456")) {
			//break;
			return;
		} else {
			cout << "�û������������!" << endl;
			system("pause");
		}
	}
}


/*�˵�*/
void menuShow(void) {
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.��վ�����޸�",
		"4.�鿴������¼",
		"5.�˳�"
	};

	system("cls");
	printInMiddle("---�ڿ͹���ϵͳ---");

	// ����˵���󳤶ȣ�
	int max = 0;
	int menuCount = sizeof(menu)/sizeof(menu[0]);
	for (int i=0; i< menuCount; i++) {
		if (menu[i].length() > max) {
			max = menu[i].length();
		}
	}

	int leftSpace = (WIDTH - max) / 2;

	for (int i=0; i<menuCount; i++) {
		for (int i=0; i<leftSpace; i++){
			printf(" ");
		}
		cout << menu[i] << endl;
	}
}


int menuChoise(void) {
	int n = 0;

	while (1) {
		cin >> n;
		if (cin.fail()) {
			cin.clear();
			cin.sync();
			cout << "��Ч����. ����������." << endl;
			system("pause");
		} else {
			break;
		}
	}

	return n;
}

void attack404(void) {
	char response[MAXSIZE] ;
	char id[64];

	memset(response, 0, sizeof(response));

	system("cls");
	printInMiddle("---��վ404����---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout << "����ִ��404����..." << endl;

	hk_404(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;
	
	system("pause");
}

void siteEdit(void) {
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printInMiddle("---��վ�۸Ĺ���---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));
	cout <<   "������Ƕ������ݣ�";
	cin >> attackText;

	GBKToUTF8(attackText);

	hk_tamper(id,  (char*)(attackText.c_str()), response);

	
	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void siteRepair(void) {
	char response[MAXSIZE];
	char id[16];
	std::string str;
	string attackText;

	system("cls");
	printInMiddle("---��վ�����޸�---");
	cout <<   "������׼����ѯ����վID��";
	scanf_s("%s", id, sizeof(id));

	hk_restore(id, response);

	string retStr = UTF8ToGBK(response);
	cout << retStr << endl;

	system("pause");
}

void attckRecord(void) {
	char response[MAXSIZE] ;
	char id[64];

	system("cls");
	printInMiddle("---������¼��ȡ---");
	cout <<   "������׼����������վID��";
	scanf_s("%s", id, sizeof(id));

	hk_record(id, response);
	
	string retStr = UTF8ToGBK(response);

	cout << retStr;
	system("pause");
}


int main(void) {
	init(); 
	// ��¼
	login();

	while (1) {
		menuShow();
		int n = menuChoise();
		switch (n) {
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			siteRepair();
			break;
		case 4:
			attckRecord();
			break;
		case 5:
			//break;
			return 0;
		default:
			cout << "��Ч����. ����������." << endl;
			system("pause");
			break;
		}
	}

	system("pause");
	return 0;
}
