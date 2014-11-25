#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int K = 111;
const int inf = 1111111111;
struct Customer {
    int come, server;
    Customer(int _come, int _server) {
        come = _come;
        server = _server >= 3600 ? 3600 : _server; //������3600�룬һ��Сʱ
    }
};
vector<Customer> custom;
int convertTime(int h, int m, int s) {
    return h*3600+m*60+s;  //ʱ��ת��Ϊ�룬���㴦��
}
bool cmp(Customer a, Customer b) {
    return a.come < b.come; //��������ʱ��������
}
int startTime[K]; //�����ܹ���ʼ��һ�η����ʱ��
int main() {
    int c, w, totTime = 0;
    int stTime = convertTime(8, 0, 0); //��ʼʱ����һ�������
    int edTime = convertTime(17, 0, 0); //����ʱ����һ������
    scanf("%d%d", &c, &w);
    for(int i = 0; i < w; i++) startTime[i] = stTime; //��ʼû�й˿ͣ����Կ�ʼ��ʱ�����8:00
    for(int i = 0; i < c; i++) {
        int h, m, s, server;
        scanf("%d:%d:%d %d", &h, &m, &s, &server); //����˿���Ϣ
        int comeTime = convertTime(h, m, s); //ת����ʼʱ��
        if(comeTime > edTime) continue; //������ıȹ���ʱ�仹������
        custom.push_back(Customer(comeTime, server * 60)); //�ŵ��˿�vector
    }
    sort(custom.begin(), custom.end(), cmp); //����ʱ������
    for(int i = 0; i < custom.size(); i++) {
        int idx = -1, t = inf; //idx��ʾ�����ܹ�����Ĵ��ڵ��±�,t���ô���Ϊ���ҵ��������������˿͵�ʱ��
        for(int j = 0; j < w; j++) {
            if(startTime[j] >= custom[i].come && startTime[j] < t) {
                t = startTime[j];//�ҵ�һ���ܷ���ģ���ô�͸������ķ���ʱ�䣬�ҵ�һ����С��
                idx = j;
            }
        }
        totTime += (startTime[idx] - custom[i].come); //��ʼ��������˿͵ķ���ʱ��
        startTime[idx] += custom[i].server; //��������´��ܷ����ʱ����Ȼ�ǿ�ʼ����ʱ��+����˿���Ҫ��ʱ��
    }
    printf("%.1f\n", custom.size() == 0 ? 0 : totTime * 1.0 / 60 / custom.size());
    return 0;
}
