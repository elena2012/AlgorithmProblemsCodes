#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int lim = 333; //�趨һ�����ڸ���100000������
stack<int> st;
int size, a, q;
char cmd[20];
int bucket[lim]; // �ŵ���ÿ��Ͱ�����ɵ�������ÿ��Ͱ����¼����ÿ��lim���������ɵ�Ԫ�ظ���
int table[100005]; //��hash����ô�������¼������ֵ�����
int main() {
	for (int i = 0; i < 100005; i++)table[i] = 0; //��ʼ����hash��
	for (int i = 0; i < lim; i++) bucket[i] = 0; //��ʼ��Ͱ
	scanf("%d", &q);
	while (q--) {
		scanf("%s", cmd);
		if (cmd[1] == 'o') {
			if (st.empty()) {
				printf("Invalid\n");
			} else {
				a = st.top(); //���ջ��
				table[a]--; //hash��a�±�Ԫ�ؼ�ȥ1
				bucket[a/lim]--; //a���ڵ�Ͱ������������ȥ1
				printf("%d\n", a);//��ӡ
				st.pop();//��ջ
			}
		} else if (cmd[1] == 'u') {
			scanf("%d", &a);
			st.push(a);//��ջ
			table[a]++;//hash��a�±�Ԫ�ؼ���1
			bucket[a/lim]++;//a���ڵ�Ͱ��������������1
		} else {
			if (st.empty()) {
				printf("Invalid\n");
			} else {
				size = st.size();
				size = size & 1 ? (size + 1) / 2 : size / 2;
				int b = size / lim;
				int cur = 0; //cur��ʾ���ǵ�ǰ���rank
				int idx = 0;//ö�ٵ�Ͱ�±�
				for (idx = 0; idx < lim; idx++) {
					if (cur + bucket[idx] < size) cur += bucket[idx];//��������ÿһ��Ͱ�����������û�д���size��ֱ�Ӽ���ȥ
					else break;
				}
				b = idx * lim; //b��ʾ������hash����ö�ٵ��±�
				for ( ; b <= b + lim; b++) { //�϶��������[b, b+lim]�������������ɲ���
					int ff = table[b];
					if (cur + ff >= size) { //�������size��֤����һ�����߶��Ԫ�أ�˵��b��������Ҫ�ҵ�Ԫ��
						printf("%d\n", b);
						break;
					} else cur += ff; //�������b������
				}
			}
		}
	}
}
