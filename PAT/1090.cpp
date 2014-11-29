#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 100005;
vector<int> G[N];  //����ͼG��vector

int maxHeight = 0; //���߶�
int Ans = 0; //���߶ȵĸ���
void dfs(int root, int height) {
    if(G[root].size() == 0) { //û�ж��ӽڵ����˵��������
        if(height == maxHeight) {
            Ans++; //��������߶�һ�����𰸼�һ
        } else if (height > maxHeight) { //�����������
           maxHeight = height; //���´�
           Ans = 1; //����Ĵ���1����0
        }
        return;
    }
    for(int i = 0; i < G[root].size(); i++) {
        dfs(G[root][i], height + 1); //�����ӽڵ�ݹ�
    }
}

int main() {
    int n, fa, root;
    double p, r;
    scanf("%d%lf%lf", &n, &p, &r);
    for(int i = 0; i < n; i++) {
        scanf("%d", &fa);
        if(fa == -1) {
            root = i;
            continue;
        }
        G[fa].push_back(i); //����Ҫ���������
    }
    dfs(root, 0);
    printf("%.2lf %d\n", p * pow((1 + r / 100.0), maxHeight), Ans);
}
