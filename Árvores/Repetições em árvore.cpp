#include <stdio.h>

t = make_tree(x);

p = q = t;
//for(t; x != info(p) && q != NULL; p++)
while(x != node[p].info && q != NULL){
	p = q;
	if(x < node[p].info){
		q = node[p].left;
	} else {
		q = node[p].right;
	}
	if(x == node[p].info){
		prinf("numero repetido: %d", x);
	} else if(x < node[p].info){
		set_left(p, make_tree(x));
	} else {
		set_right(p, make_tree(x));
	}
}
