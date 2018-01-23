#include <cstdio>
#include <cstdlib>
#include <cassert>
#include "Skip-list.cpp"

int main(){

	SkipList* slist = new SkipList;
	int n,m,x,y,c;
	scanf("%d %d",&n, &m);
	printf("%d %d\n",n,m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&x);
		slist->insert(x);
	}
	slist->display(1);
	int cc = 0;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d",&y,&c);
		node* p = slist->find(y);
		if (!p){
	       	  printf("%d %d\n",y,c);
		  if (c!=0) ++cc;
		}
	       else printf("%d=?%d %d=?%d\n",y,p->value,c,p->info);
	}
	printf("%d\n",cc);
	puts("done");
	return 0;
}
