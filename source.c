#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 1000
#define BUCKETS 10
#define DIGITS 4

void counting_sort(int *list, int n, int exp) {//n�� 0~9�� ��Ÿ��, k�� ��� ° �ڸ�
	int output[MAX_NUM];
	int count[10];
	int i;

	for (i = 0; i < n + 1; i++) {//Count ���� �ʱ�ȭ
		count[i] = 0;
	}
	for (i = 0; i < MAX_NUM; i++)//�� �ڸ����� ���� count�� �ֱ�
		count[(list[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)//������ ����� �༭ �� ���ڰ� � index�� �� �� ������ֱ�
		count[i] += count[i - 1];

	for (i = MAX_NUM - 1; i >= 0; i--)
	{
		output[count[(list[i] / exp) % 10] - 1] = list[i];//���� index�� �°� output�� ���� �־��ֱ�
		count[(list[i] / exp) % 10]--;//�̹� ���� �ϳ��� ������ index �ϳ� - ���Ѽ� output �� �־��ֱ� ����
	}

	for (i = 0; i < MAX_NUM; i++) {
		list[i] = output[i];
	}
}

void radix_sort(int *list, int n) {
	int i = 0;
	int exp = 1;//�ڸ� �� ������ ����. 1,10,100,1000���� ����.

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

	printf("������ \n");

	for (i = 0; i < 20; i++)
		printf("%d ", list[i]);
}
