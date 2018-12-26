
#include <stdlib.h>
#include <stdio.h>

struct Node {
  char *left;
  char *middle;
  char *right;
};

struct Node return_node(char *word[], int i){
  struct Node n;
  n.right = word[i+1];
  n.middle = word[i];
  n.left = word[i-1];
  return n;
};

int main(){

  char *words_list[] = {"F", "is", "for", "friends",
                        "who", "do", "stuff", "together"};

  struct Node node_list[8] = {};

  for (int i = 1; i < 8; i++){
    struct Node my_node = return_node(words_list, i);
    node_list[i] = my_node;
  }

  printf("%s %s %s?\n", node_list[5].left, node_list[1].middle, node_list[6].right);

  return 0;
}
