#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000
#define BUCKETS 10
#define DIGITS 4

void counting_sort(int *list, int n, int exp) {//n은 0~9를 나타냄, k는 몇번 째 자리
	int output[MAX_NUM];
	int count[10];
	int i;

	for (i = 0; i < n + 1; i++) {//Count 변수 초기화
		count[i] = 0;
	}
	for (i = 0; i < MAX_NUM; i++)//각 자리수의 숫자 count에 넣기
		count[(list[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)//누적합 계산해 줘서 각 숫자가 어떤 index에 들어갈 지 계산해주기
		count[i] += count[i - 1];

	for (i = MAX_NUM - 1; i >= 0; i--)
	{
		output[count[(list[i] / exp) % 10] - 1] = list[i];//각각 index에 맞게 output에 숫자 넣어주기
		count[(list[i] / exp) % 10]--;//이미 숫자 하나가 들어갔으니 index 하나 - 시켜서 output 에 넣어주기 가능
	}

	for (i = 0; i < MAX_NUM; i++) {
		list[i] = output[i];
	}
}

void radix_sort(int *list, int n) {
	int i = 0;
	int exp = 1;//자리 수 나누는 변수. 1,10,100,1000까지 증가.

	for (i = 0; i < DIGITS; i++) {
		counting_sort(list, n, exp);
		exp *= 10;
	}
}

int main() {
	int i;
	int list[MAX_NUM];
	int temp;

	for (i = 0; i < MAX_NUM; i++) {
		temp = (rand() / (double)RAND_MAX) * 10000;
		list[i] = temp;
	}

	for (i = 0; i < 20; i++)
		printf("%d ", list[i]);

	radix_sort(list, 9);

	printf("정렬후 \n");

	for (i = 0; i < 20; i++)
		printf("%d ", list[i]);
}
