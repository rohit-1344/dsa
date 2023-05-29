#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct node
{
��� int data;
��� struct node *next;
};
void random(struct node **, int, int, int);
void sort(struct node **, int);
int main()
{
��� struct node *head = NULL;
��� int l, h, n, i;
��� char t;
��� printf("enter range L-H and size\n");
��� scanf("%d%d%d", &l, &h, &n);
��� random(&head, l, h, n);
��� sort(&head, n);
}
void random(struct node **head, int l, int h, int n)
{

��� int i, r;
��� FILE *fp;
��� fp = fopen("input.txt", "w");
��� for (i = 0; i < n; i++)
��� {
������� struct node *p;
������� p = (struct node *)malloc(sizeof(struct node));
������� p->data = rand() % (h - l) + l;
������� p->next = *head;
������� *head = p;
������� fprintf(fp, "%d\t", p->data);
��� }
��� fclose(fp);
}

void sort(struct node **head, int n)
{
��� struct node *top;
��� struct node *bot;
��� top = *head;
��� clock_t start, stop;
��� int i, j, x, min, test;
��� char t;
��� printf("sort method m,b,s,a(all)");
��� scanf("%*c%c", &t);
��� printf("enter no to be sorted");
��� scanf("%d", &x);
��� FILE *fp;
��� FILE *tp;
��� fp = fopen("output.txt", "w");
��� tp = fopen("log.txt", "w");

��� if (t == 's' || t == 'a')
��� {
������� start = clock();
������� for (i = 0; i < x; i++)
������� {
����������� min = top->data;
����������� bot = top;

����������� for (j = i; j < n; j++)
����������� {

��������������� if (min > (bot->data))
��������������� {
������������������� min = bot->data;
������������������� bot->data = top->data;
������������������� top->data = min;
��������������� }
��������������� bot = bot->next;
����������� }
����������� fprintf(fp, "%d\t", min);
����������� top = top->next;
������� }
������� fprintf(fp, "\n");
������� stop = clock();
������� float time_r = (float)(stop - start) / CLOCKS_PER_SEC;
������� fprintf(tp, "selection� %d�� %f sec\n", x, time_r);
��� }

}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int n, i, j, temp;
  clock_t start, end;
  double cpu_time_used;

  printf("Enter the number of elements to be sorted: ");
  scanf("%d", &n);

  int arr[n];


  srand(time(NULL));


  printf("Generating %d random numbers...\n", n);
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 100 + 1;
  }


  start = clock();


  for (i = 0; i < n-1; i++) {
    for (j = 0; j < n-i-1; j++) {
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }


  end = clock();


  cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;


  printf("Sorted array:\n");
  for (i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }


  FILE *fp;
  fp = fopen("sorted.txt", "w");

  if (fp == NULL) {
    printf("Unable to create file.\n");
    return 1;
  }

  fprintf(fp, "Sorted array:\n");
  for (i = 0; i < n; i++) {
    fprintf(fp, "%d ", arr[i]);
  }

  fprintf(fp, "\nTime taken to sort: %f seconds", cpu_time_used);

  fclose(fp);

  return 0;
}
