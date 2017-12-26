#include <stdio.h>
#include <stdlib.h>
# define MAX_COUNT 10 // �]�w�̤j��J���Z���� 
void preload(); // �Ĥ@�B 
/*
 �ĤG�B 
*/
void start_get_score_loop(); // �}�l�i�J��J���Z�j�� 
int get_score(); // ���o�ӤH���Z 
int check_score(int); // 2a�A�P�_���Z�O�_���T�A���T�^�� 1�A���~�^�� 0
int get_score_process(); // ���o���ӤH�Z�`�y�{ 
/*
	�ĤT�B 
*/
int continues(); // �ĤT�B�`�y�{ 
int get_continues_input(); // ���o��J���r���åB�ন ASCII 
int handle_continues_input(int); // �P�_��J���r���ন 0, 1, -1 
int is_input_all_score(); // �P�_�O�_��J�Ҧ������ 
void control_input_counting(); // �P�_�O�_��J�Ҧ���ƪ��y�{ 
/*
	�Ĥ��B 
*/
void show_final_message(); // ��ܲĤ��B���T�� 
int get_final_input(); // ���o��J 
int handle_final_input(int); // ���t��J������ 
void final_process(); // �Ĥ��B�`�y�{ 
/*
	�Ĥ��B���\�� 
*/
void show_all_score(); // ��ܩҦ����Z 
void calculate_score_average(); // �p�⦨�Z����
void bubble_sort(); // ���Z��w�Ƨ�
 
int score_list[MAX_COUNT];
int current_count = 0;
int is_over = 0;
int main(void){
	preload(); // �Ĥ@�B
	start_get_score_loop();
	system("pause");
	return 0;
}

// �Ĥ@�B
void preload(){
	for (int i = 0 ; i < MAX_COUNT ; i++){
		score_list[i] = -1; // ����n�ӧP�_��ܴX����� 
	}
	printf("Welcome to use this application!\n");	
}

/*
	�ĤG�B
*/
void start_get_score_loop(){
	while(current_count < MAX_COUNT && is_over == 0){
		score_list[current_count] = get_score_process(); // �ĤG�B
		continues(); // �ĤT�B 
	}
	final_process();
} 
// ���o�ӤH���Z 
int get_score(){
	int score;
	printf("Please input a student��s score:");
	scanf("%d", &score);
	return score;
}
// 2a�A�P�_���Z�O�_���T�A���T�^�� 1�A���~�^�� 0 
int check_score(int score){
	if (score >= 0 && score <= 100){
		return 1;
	}
	return 0;
} 
// ���o���ӤH�Z�`�y�{ 
int get_score_process(){
	int score = get_score();
	if (check_score(score) == 1){
		return score;
	}
	printf("Wrong score!\n");
	get_score_process();
}
/*
	�ĤT�B 
*/ 
int continues(){
	if (current_count > 0){
		int input = get_continues_input();
		switch(handle_continues_input(input)){
			case 0:
				control_input_counting();
				break;
			case 1:
				is_over = 1;
				break;
			default: // 3b
				printf("Wrong Information!\n");
				continues();
				break;
		}
	}else{
		current_count += 1;
	}
}
void control_input_counting(){
	if (is_input_all_score() == 1){
		current_count += 1; // �ĥ|�B 
	}else{
		// 3c
		printf("You have completed the score input\n");
		is_over = 1;
	}
}
int get_continues_input(){
	char input;
	printf("You have inputted %d score information.\n", (current_count + 1));
	printf("Continue? Press ��1��, ��Y��, or ��y�� for Yes, and ��2��, ��N��, or ��n�� for No:");
	scanf(" %c", &input);
	return input;
}
// Y = 89, y = 121 ; N = 78, n = 110
int handle_continues_input(int input){
	if (input == 89 || input == 121 || input == 49){
		return 0;
	}else if (input == 78 || input == 110 || input == 50){
		return 1;
	}else{
		return -1;
	}
}

int is_input_all_score(){
	if (current_count == (MAX_COUNT - 1)){
		return 0;
	}
	return 1;
} 

void show_final_message(){
	printf("What operation do you want to execute?\n");
	printf("Press ��1�� to list all scores;\n");
	printf("Press ��2�� to calculate the average of scores;\n");
	printf("Press ��3�� to sort and list the scores (from minimum to maximum);\n");
	printf("Press ��4�� to continue the score input;\n");
	printf("Press ��5�� to quit this Java application.\n");
}
int get_final_input(){
	int input;
	scanf("%d", &input);
	return input;
}
int handle_final_input(int input){
	switch(input){
		case 1:
			show_all_score();
			final_process();
			break;
		case 2:
			calculate_score_average();
			final_process();
			break;
		case 3:
			bubble_sort();
			final_process();
			break;
		case 4:
			is_over = 0;
			start_get_score_loop();
			break;
		case 5:
			printf("Thank you for using this C application! Goodbye!\n");
			break;
	}
}

void final_process(){
	show_final_message();
	int input = get_final_input();
	handle_final_input(input);
}

// ��ܩҦ����Z 
void show_all_score(){
	printf("��ܩҦ����Z:\n");
	for (int i = 0 ; i < MAX_COUNT ; i++){
		if (score_list[i] != -1){
			printf("No.%d - score = %d\n", (i + 1), score_list[i]);
		}
	}
} 

// �p�⦨�Z����
void calculate_score_average(){
	printf("�p�⥭��....�ۤv��\n");
} 
// ���Z��w�Ƨ�
void bubble_sort(){
	printf("��w�ƧǪk....�ۤv��\n");
} 
