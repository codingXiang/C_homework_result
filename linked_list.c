# include<stdio.h>
# include<stdlib.h>
# define MAX_COUNT 3
int get_score();
int check_score(int);
int get_score_process();
void show_all_score();

/*
	linked list
*/
struct student{
	int id;
	int score;
	struct student *next_node;
};
typedef struct student Student;

Student *get_head();
void get_linked_list_score();


Student *head_node, *current_node;

int main(void){
	head_node = get_head();
	current_node = head_node;
	get_linked_list_score();
	show_all_score();
	system("pause");
	return 0;
}
void get_linked_list_score(){
	int i;
	for (i = 1 ; i < MAX_COUNT ; i++){
		current_node->next_node = (Student *) malloc(sizeof(Student));
		current_node = current_node->next_node;
		current_node->id = i + 1;
		current_node->score = get_score_process();
		current_node->next_node = NULL;
	}
}
Student *get_head(){
	Student *std = (Student *) malloc(sizeof(Student));
	std->id = 1;
	std->score = get_score_process();
	std->next_node = NULL;
	return std;
}
int get_score(){
	int score;
	printf("請輸入成績：");
	scanf("%d", &score);
	return score;
}
int check_score(int score){
	if (score <= 100 && score >= 0){
		return 0;
	}
	return 1;
}
int get_score_process(){
	int score = get_score();
	if (check_score(score) == 0){
		return score;
	}
	printf("輸入錯誤成績！ 請重新輸入一次！\n");
	get_score_process();
} 
void show_all_score(){
	current_node = head_node;
	while (current_node != NULL){
		printf("No.%d - score = %d\n", current_node->id, current_node->score);
		current_node = current_node->next_node;
	}
}
