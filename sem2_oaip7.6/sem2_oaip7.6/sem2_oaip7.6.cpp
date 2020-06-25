



//6. Удалить из левой ветви дерева узел с максимальным значением ключа
//и все связанные с ним узлы.

#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

int amount_of_knot = 0;
struct Tree {
	int info;
	string name;
	Tree* right, * left;
}*root;
Tree* create_list(int info) {
	Tree* p = new Tree;
	p->info = info;
	cout << "Введите Имя: ";
	cin.ignore();
	getline(cin, p->name);
	p->right = p->left = NULL;
	return p;
}
void create_knot(Tree* root, int info) {
	Tree* prev = NULL, * p;
	p = root;
	bool find = true;
	while (p && find) {
		prev = p;
		if (p->info == info)
			find = false;
		else {
			if (info < p->info)
				p = p->left;
			else p = p->right;
		}
	}
	if (find) {
		p = create_list(info);
		if (info < prev->info)
			prev->left = p;
		else prev->right = p;
	}
}
void view_tree(Tree* p, int level) {
	if (p) {
		view_tree(p->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "       ";
		cout << p->info << "-" << p->name << endl << endl;
		view_tree(p->left, level + 1);
	}
}

void view_list(Tree* p) {
	if (p) {
		view_list(p->left);
		cout << p->info << "-" << p->name << endl;
		view_list(p->right);
	}
}
void tree_to_arr(Tree* p, Tree* t) {
	if (p) {
		tree_to_arr(p->left, t);
		t[amount_of_knot].info = p->info;
		t[amount_of_knot].name = p->name;
		amount_of_knot++;
		tree_to_arr(p->right, t);
	}
}
void del_tree(Tree* p) {
	if (p != NULL) {
		del_tree(p->right);
		del_tree(p->left);
		delete p;
	}
}
void balans_tree(Tree** p, int n, int k, Tree* new_tree) {
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->info = new_tree[m].info;
		(*p)->name = new_tree[m].name;
		balans_tree(&(*p)->left, n, m, new_tree);
		balans_tree(&(*p)->right, m + 1, k, new_tree);
	}
}
void balans() {
	Tree* new_tree = new Tree[100];
	tree_to_arr(root, new_tree);
	del_tree(root);
	balans_tree(&root, 0, amount_of_knot, new_tree);
	amount_of_knot = 0;
}
void find(Tree* p, int info) {
	while (p != NULL && p->info != info) {
		if (info > p->info)p = p->right;
		else p = p->left;
	}
	if (p == NULL) {
		puts("Узел не найден!");
		return;
	}
	cout << "Искомое имя : " << p->name;
}
Tree* del_info(Tree* root, int info) {
	Tree* del, * prev_del = NULL, * r, * prev_r;
	del = root;
	while (del != NULL && del->info != info) {
		prev_del = del;
		if (info > del->info)del = del->right;
		else del = del->left;
	}
	if (del == NULL) {
		puts("Узел не найден!");
		return root;
	}
	if (del->right == NULL)r = del->left;
	else
		if (del->left == NULL)r = del->right;
		else {
			prev_r = del;
			r = del->left;
			while (r->right != NULL) {
				prev_r = r;
				r = r->right;
			}
			if (prev_r == del)r->right = del->right;
			else {
				r->right = del->right;
				prev_r->right = r->left;
				r->left = prev_r;
			}
		}
	if (del == root)root = r;
	else
		if (del->info > prev_del->info)prev_del->right = r;
		else prev_del->left = r;
	delete del;
	return root;
}
int findMax(Tree* root) {
	if (root == NULL)
		return INT_MIN;

	int res = root->info;
	int left = findMax(root->left);
	int right = findMax(root->right);
	if (left > res)
		res = left;
	if (right > res)
		res = right;
	return res;
}
//
//Tree* getParent(Tree* root, int info) {
//	if (root == NULL) return NULL;
//	else if (root->right->info == info || root->left->info == info) return root;
//	else if (root->info > info) return getParent(root->left, info);
//	else return getParent(root->right, info);
//}
//
Tree* Max_Key(Tree* root) {
	while (root->right != NULL) root = root->right;
	return root;
}


void removeMaxBranch(Tree* root) {
	//find max
	int max = findMax(root->left);
	Tree* max2 = Max_Key(root->left);
	if (max2->left != NULL)
	{
		max2->left = NULL;
	}
	if (max2->right != NULL)
	{
		max2->right = NULL;
	}
	del_info(root, max);
	//remove max branch
	
}




int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	int info;
	int menu = 0;
	while (menu != 7) {
		puts("\nВыберите пункт меню");
		puts("\tМеню программы:");
		puts("1 – Добавление узла");
		puts("2 – Просмотр дерева");
		puts("3 – Сбалансировать дерево");
		puts("4 – Посмотреть узел");
		puts("5 - Удалить узел ");
		puts("6 - Индивидуальное задание");
		puts("7 – ВЫХОД ");
		scanf_s("%d", &menu);
		switch (menu) {
		case 1: {
			puts("Введите индефикационный номер : ");
			cin >> info;
			if (root == NULL)root = create_list(info);
			else create_knot(root, info); break;
		}
		case 2: {
			int view;
			puts("1 - Просмотреть деревом\n2 - Просмотреть списком");
			cin >> view;
			if (view == 1)
				view_tree(root, 0);
			if (view == 2)
				view_list(root); break;
		}
		case 3: {
			balans();
			view_tree(root, 0); 
			break;
		}
		case 4: {

			puts("Введите индефикационный номер : ");
			cin >> info;
			find(root, info); break;


		}
		case 5: {
			puts("Введите индефикационный номер : ");
			cin >> info;
			root = del_info(root, info);
			break;
		}
		case 6:
		{
			removeMaxBranch(root);
			puts("Удаление из левой ветви дерева узел с максимальным значением ключа:\n");
			view_tree(root, 0);
			break;
		}
		case 7: {
			exit(0);
		}

		default: {
			puts("\tНеобходимо выбрать из предложенного списка!\n");

			break;
		}
		}
	}
}