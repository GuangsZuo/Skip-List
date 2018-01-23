#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "Skip-list.cpp"

int main(){

	SkipList* slist = new SkipList;
	int n,m,x,y,c;
	scanf("%d %d",&n, &m);
	printf("%d %d",n,m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&x);
		slist->insert(x);
		printf("%d\n",i);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d",&y,&c);
		node* p = slist->find(y);
		assert(y==p->value);
		assert(c==p->info);
	}
	puts("done");
	return 0;
}