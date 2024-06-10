//stack
// o(n) - сложность

#include <stdio.h>
#include <stdlib.h>
 
// Структура данных для представления stack
struct stack
{
    int maxsize;    // определяем максимальную емкость stack
    int top;
    int *items;
};
 
// Вспомогательная функция для инициализации stack
struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);
 
    return pt;
}
 
// Вспомогательная функция для возврата размера stack
int size(struct stack *pt) {
    return pt->top + 1;
}
 
// Вспомогательная функция для проверки, пуст stack или нет
int isEmpty(struct stack *pt) {
    return pt->top == -1;                   // или return size(pt) == 0;
}
 
// Вспомогательная функция для проверки, заполнен ли stack или нет
int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;      // or return size(pt) == pt->maxsize;
}
 
// Вспомогательная функция для добавления элемента `x` в stack
void push(struct stack *pt, int x)
{
    // проверяем, не заполнен ли уже stack. Тогда вставка элемента будет
    // привести к переполнению stack
    if (isFull(pt))
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Inserting %d\n", x);
 
    // добавляем элемент и увеличиваем индекс вершины
    pt->items[++pt->top] = x;
}
 
// Вспомогательная функция для возврата верхнего элемента stack
int peek(struct stack *pt)
{
    // проверка на пустой stack
    if (!isEmpty(pt)) {
        return pt->items[pt->top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Вспомогательная функция для извлечения верхнего элемента из stack
int pop(struct stack *pt)
{
    // проверка на опустошение stack
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    printf("Removing %d\n", peek(pt));
 
    // уменьшаем размер stack на 1 и (необязательно) возвращаем извлеченный элемент
    return pt->items[pt->top--];
}
 
int main()
{
    // создаем stack емкостью 5
    struct stack *pt = newStack(5);
 
    push(pt, 1);
    push(pt, 2);
    push(pt, 3);
 
    printf("The top element is %d\n", peek(pt));
    printf("The stack size is %d\n", size(pt));
 
    pop(pt);
    pop(pt);
    pop(pt);
 
    if (isEmpty(pt)) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}