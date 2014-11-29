#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 111;
int origin[N], changed[N], t[N]; //�ֱ�Ϊԭʼ���飬���м�״̬���飬����ʱ����
int n;
bool isSame(int* A, int* B) { //�ж��Ƿ�һ��
	for (int i = 0; i < n; i++) {
		if (A[i] != B[i]) return false;
	}
	return true;
}

bool showArray(int *A) { //����𰸺���
	for (int i = 0; i < n; i++) {
		if (i == 0) printf("%d", A[i]);
		else printf(" %d", A[i]);
	}
	printf("\n");
}

bool insertSort() {
	bool flag = false; //�ж��Ƿ����м�״̬
	for (int i = 1; i < n; i++) {

		if (isSame(t, changed)) flag = true; //��������м�״̬��
		if (t[i] < t[i-1]) { //����Ϊ�����������
			int temp = t[i], j = i;
			while (j > 0 && temp < t[j - 1]) {
				t[j] = t[j - 1];
				j--;
			}
			t[j] = temp;
			if (flag) { //���ǰ��һ��״̬���м�״̬�������Ҫ����
				return true;
			}
		}
	}
	return false;
}

void  mergeSort() {
	bool flag = false;//�ж��Ƿ����м�״̬

	for (int step = 2; ; step *= 2) { //�����step��mergeSortÿ�δ�������䳤
	    if (isSame(t, changed)) { //��������м�״̬��
			flag = true;
		}
		for (int i = 0; i < n; i++) t[i] = origin[i]; //ÿ�ι�ԭʼ״̬ö��
		if (step > n) { //������Ҫ���е��ǵ�ö�ٵ�step���������������ʱ�����ʱ��϶���ȫ���Ѿ�����õ���
			sort(t, t + n);
			showArray(t);
			return;
		}
		for (int i = 0; i < n - step; i += step) { //��������������ֱ�ӱ���sort
			sort(t + i, t + i + step);
		}
		if (n % step != 0) { //ע�⴦��������䳤����Ϊstep�������������
			sort(t + n / step * step, t + n);
		}
		if (flag) { //���ǰ��һ��״̬���м�״̬�������Ҫ����
			showArray(t);
			return;
		}

	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", origin + i);
		t[i] = origin[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", changed + i);
	}
	if (insertSort()) {
		printf("Insertion Sort\n");
		showArray(t);
	} else {
		printf("Merge Sort\n");
		mergeSort();
	}
}
