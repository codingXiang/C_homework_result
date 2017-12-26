#include <stdio.h>
#include <stdlib.h>
# define MAX_COUNT 10 // 設定最大輸入成績筆數 
void preload(); // 第一步 
/*
 第二步 
*/
void start_get_score_loop(); // 開始進入輸入成績迴圈 
int get_score(); // 取得個人成績 
int check_score(int); // 2a，判斷成績是否正確，正確回傳 1，錯誤回傳 0
int get_score_process(); // 取得成個人績總流程 
/*
	第三步 
*/
int continues(); // 第三步總流程 
int get_continues_input(); // 取得輸入的字元並且轉成 ASCII 
int handle_continues_input(int); // 判斷輸入的字並轉成 0, 1, -1 
int is_input_all_score(); // 判斷是否輸入所有的資料 
void control_input_counting(); // 判斷是否輸入所有資料的流程 
/*
	第五步 
*/
void show_final_message(); // 顯示第五步的訊息 
int get_final_input(); // 取得輸入 
int handle_final_input(int); // 分配輸入的任務 
void final_process(); // 第五步總流程 
/*
	第五步的功能 
*/
void show_all_score(); // 顯示所有成績 
void calculate_score_average(); // 計算成績平均
void bubble_sort(); // 成績氣泡排序
 
int score_list[MAX_COUNT];
int current_count = 0;
int is_over = 0;
int main(void){
	preload(); // 第一步
	start_get_score_loop();
	system("pause");
	return 0;
}

// 第一步
void preload(){
	for (int i = 0 ; i < MAX_COUNT ; i++){
		score_list[i] = -1; // 後續要來判斷顯示幾筆資料 
	}
	printf("Welcome to use this application!\n");	
}

/*
	第二步
*/
void start_get_score_loop(){
	while(current_count < MAX_COUNT && is_over == 0){
		score_list[current_count] = get_score_process(); // 第二步
		continues(); // 第三步 
	}
	final_process();
} 
// 取得個人成績 
int get_score(){
	int score;
	printf("Please input a student’s score:");
	scanf("%d", &score);
	return score;
}
// 2a，判斷成績是否正確，正確回傳 1，錯誤回傳 0 
int check_score(int score){
	if (score >= 0 && score <= 100){
		return 1;
	}
	return 0;
} 
// 取得成個人績總流程 
int get_score_process(){
	int score = get_score();
	if (check_score(score) == 1){
		return score;
	}
	printf("Wrong score!\n");
	get_score_process();
}
/*
	第三步 
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
		current_count += 1; // 第四步 
	}else{
		// 3c
		printf("You have completed the score input\n");
		is_over = 1;
	}
}
int get_continues_input(){
	char input;
	printf("You have inputted %d score information.\n", (current_count + 1));
	printf("Continue? Press ‘1’, ‘Y’, or ‘y’ for Yes, and ‘2’, ‘N’, or ‘n’ for No:");
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
	printf("Press ‘1’ to list all scores;\n");
	printf("Press ‘2’ to calculate the average of scores;\n");
	printf("Press ‘3’ to sort and list the scores (from minimum to maximum);\n");
	printf("Press ‘4’ to continue the score input;\n");
	printf("Press ‘5’ to quit this Java application.\n");
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

// 顯示所有成績 
void show_all_score(){
	printf("顯示所有成績:\n");
	for (int i = 0 ; i < MAX_COUNT ; i++){
		if (score_list[i] != -1){
			printf("No.%d - score = %d\n", (i + 1), score_list[i]);
		}
	}
} 

// 計算成績平均
void calculate_score_average(){
	printf("計算平均....自己打\n");
} 
// 成績氣泡排序
void bubble_sort(){
	printf("氣泡排序法....自己打\n");
} 
