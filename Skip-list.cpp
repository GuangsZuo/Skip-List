#include <cstdlib>
#include <cstdio>
#include <ctime>

#define MAXLEVEL 16
#define P 4

struct node{
    int value;
    node** forward;
    int info; 
    int maxlevel; 
    node(int v = 0) {
    	value = v;
      maxlevel = 1;
    	forward = new node* [MAXLEVEL]; 
    }
};

class SkipList{

public:
	SkipList() {
		list = new node;
		srand(time(NULL)); 
	}
	node* insert (int v);
	bool del (int v);
	node* find (int v);

private:
  node* list;
	int random_level(){
		int l = 1;
		while (l < MAXLEVEL - 1 && rand() % P + 1 <= 1) 
			l ++;
		return l;
	}
};

node* SkipList::insert(int v) {
  node* update[MAXLEVEL];
  node* iterator = list;
  puts("done1");
	for (int level = list->maxlevel - 1 ; level >= 0; --level) {
    while (iterator->forward[level] != NULL && iterator->forward[level]->value < v)
      iterator = iterator->forward[level];
    // if the v is already in the skip list , then change the info attr.
    if (iterator->forward[level] != NULL && iterator->forward[level]->value == v) {
      iterator->forward[level]->info += 1;
      return iterator->forward[level];
    } else {
      update[level] = iterator->forward[level];
    }
  }
  puts("done2");
  int v_level = random_level();
  node* v_node = new node(v);
  for (int i = 0; i < v_level; ++i) {
    v_node->forward[i] = update[i];
    update[i] = v_node->forward[i];
  }
  puts("done3");
}

node* SkipList::find(int v) {
  node * iterator = list;
  for (int level = list->maxlevel - 1; level >= 0; --level) {
    while (iterator->forward[level] != NULL && iterator->forward[level]->value < v)
      iterator = iterator->forward[level];
    if (iterator->forward[level] != NULL && iterator->forward[level]->value == v) {
      return iterator->forward[level];
    }
    return NULL;
  }
}


