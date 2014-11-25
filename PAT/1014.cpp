#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int max_node = 1111;
int n, m, k, q, getQuery;
int convertToMinute(int h, int m) {
    return h * 60 + m; //ת��ʱ��Ϊ���ӣ�����ʱ�䴦��
}
struct Window {
    int endTime, popTime; //����һ��������˵���ж��ڵ�ǰ���������ڶӵ��˵Ĵ�����ʱ��endTime���ڶ�ͷ�˴��������˵ĵ�popTime
    queue<int> q;
    Window() {
        popTime = endTime = convertToMinute(8, 0);
    }
} window[20];
int ans[max_node], needTime[max_node];
int main() {
    int inIndex = 0;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for(int i = 0; i < k; i++) {
        ans[i] = -1; //���Ƚ������鸳ֵΪ-1
        scanf("%d", &needTime[i]); //������Ҫ�����ʱ��
    }
    for(int i = 0; i < min(n * m, k); i++) { //������һ���ӵĵط�����k���ܴ��� n * m�������Ͷ�������
        window[inIndex % n].q.push(inIndex); //��nȡ������ѭ���Ŷ�
        window[inIndex % n].endTime += needTime[inIndex]; //����������ڵĴ��������ʱ��Ҫ������������˵���Ҫʱ��
        ans[inIndex] = window[inIndex % n].endTime; //����inIndex������˵�������ʱ����ǵ�ǰ���ڴ������ʱ��
        inIndex++;
    }
    for(; inIndex < k; inIndex++) {
        int idx = -1, minPopTime = 1 << 30; //minPopTime�����絯��ʱ�䣬����Ҫ�ҵ����д��ڵ����ʱ�䣬�����˲��ܸ���ȥ
        for(int i = 0; i < n; i++) { //��ѽ��ѽ��ѽ��
            Window& W = window[i];
            if(W.popTime + needTime[W.q.front()] < minPopTime) {
                idx = i; //�ҵ��ˣ�
                minPopTime = W.popTime + needTime[W.q.front()]; //����
            }
        }
        if(idx != -1) { //����endTime��popTime
            Window& W = window[idx];
            W.endTime += needTime[inIndex];
            W.popTime += needTime[W.q.front()];
            W.q.pop();
            W.q.push(inIndex);
            ans[inIndex] = W.endTime; //��ô�
        } else break;
    }
    for(int i = 0; i < q; i++) {
        scanf("%d", &getQuery);
        if(ans[getQuery - 1] == -1 || ans[getQuery - 1] - needTime[getQuery - 1] >= convertToMinute(17, 0)) printf("Sorry\n");
        else printf("%02d:%02d\n", ans[getQuery - 1] / 60, ans[getQuery - 1] % 60);
    }
}
