#include <stdio.h>
#include<stdlib.h>
#define n 11
int h[n] = {0};

void insert(int key)
{

	int i, index, flag = 0, hkey;
	hkey = key % n;
	for (i = 0; i < n; i++) {

		index = (hkey + i) % n;

		if (h[index] == 0) {
			h[index] = key;
			break;
		}
	}

	if (i == n)

		printf("\nHash Table is Full\n");
}


void q_probing(int key, int c1, int c2) {
	int i, hkey , index;
	hkey = key % n;
	for (i = 0; i < n; i++) {
		index = (hkey + (c1 * i) + (c2 * i * i)) % n;
		if (h[index] == 0) {
			h[index] = key;
			break;
		}
	}
}
void search(int key)
{

	int i, index, flag = 0, hkey;
	hkey = key % n;
	for (i = 0; i < n; i++)
	{
		index = (hkey + i) % n;
		if (h[index] == key)
		{
			printf("%d", index);
			break;
		}
	}
	if (i == n)
		printf("%d", -1);
}
void display()
{

	int i;
	for (i = 0; i < n; i++)

		printf("%d \t%d\n", i, h[i]);

}
int main() {
	int arr[] = {12, 23, 32, 3, 14, 27, 18, 87, 58};
	int m = sizeof(arr) / sizeof(arr[0]);

	printf("11. Using open addressing technique with the help of auxiliary hash function h′(x)=x to insert\n"
	       "the keys 12,23,32,3,14,27,18,87,58 into a hash table of length n=11"
	       "Consider inserting the keys 12,23,32,3,14,27,18,87,58 into a hash table of length n=11"
	       "using open addressing with the auxiliary hash function h′(x)=x.\n"
	       "i. Using linear Probing, by inserting these keys try to display the results.\n"
	       "ii. By applying quadratic probing of c1=1 and c2=3\n"
	       "iii. By applying double hashing, evaluate the function with p1(x)=x and p2(x) = 1+(x"
	       "mod (n−1)).\n\n");
	for (int i = 0; i < m; i++) {
		q_probing(arr[i], 1, 3);
	}
	display();

	printf("\n\n iii A)\n");




	printf("\tp1(x) = x\n");
	printf("\tp2(x) = 1 + x mod (n-1)\n");
	printf("\th(p1,p2) = (p1 + i * p2) mod n\n");
	printf("\tp1 = first hasing\n");
	printf("\tp2 = second hashing\n");
	printf("\tn = size of the table\n");
	printf("\ti = current table index\n");

	printf("\th(p1,p2) = (x + i(1 + x mod n-1) mod n\n");





	return 0;
}