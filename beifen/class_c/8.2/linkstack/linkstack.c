#include "linkstack.h"
//创建一个空的链栈
void InitStack(stack *s)
{
    s->top = NULL;
    s->length = 0;
}
//入栈
void push(stack *s,DataType num)
{
    if(NULL == s)
    {
        return;
        }
        Node *tmp = (Node *)malloc(sizeof(Node));
        tmp->data = num;
        tmp->next = NULL;
        tmp->next = s->top;
        s->top = tmp;
        s->length++;
}
//获取栈顶元素
DataType GetTop(stack *s)
{
    if(NULL == s)
    {
        return (DataType)-1;
        }
        if(s->top == NULL)
        {
            return (DataType)-1;
            }
            return s->top->data;
}
//出栈
DataType pop(stack *s)
{
    if(NULL == s)
    {
        return (DataType)-1;
        }
        if(NULL == s->top)
        {
            return (DataType)-1;
            }
            Node *tmp = s->top;
            DataType value = tmp->data;
            s->top = tmp->next;
            free(tmp);
            tmp = NULL;
            s->length--;
            return value;
}
//判断栈是否为空
int EmptyStack(stack *s)
{
    if(NULL == s)
    {
        return 1;
        }
        return s->top == NULL ? 1 : 0;
}
//练习：
int ClearStack(stack *s)
{
    if(NULL == s);
}

int Priority(char ch)
{
    switch (ch)
    {
        case '(':
        return 3;
        case '*':
        case '/':
        return 2;
        case '+':
        case '-':
        return 1;
        default:
        return 0;
        }
}
void Calculator()
{
    stack s_num,s_opt;
    InitStack(&s_num);
    InitStack(&s_opt);
    char opt[128] = {0};
    int i,tmp = 0,num1,num2;
    printf("请输入表达式：\n");
    scanf("%s",opt);
    while(opt[i] != '\0' || EmptyStack(&s_opt) != 1)
    {
        if(opt[i] >= '0' && opt[i] <= '9')
        tmp = tmp *10 + opt[i] - '0';
        i++;
        if(opt[i] < '0' || opt[i] > '9')
        {
            push(&s_num,tmp);
            tmp = 0;
            }
            
            else//操作符
            {
                if(EmptyStack(&s_opt) ||Priority(opt[i]) > Priority(GetTop(&s_opt))||(GetTop(&s_opt) == '(' && opt[i] != ')'))
                {
                    push(&s_opt,opt[i]);
                    i++;
                    continue;
                    }
                    if(GetTop(&s_opt) == '(' && opt[i] == ')')
                    {
                        pop(&s_opt);
                        i++;
                        continue;
                        }
                        if(Priority(opt[i]) <= Priority(GetTop(&s_opt)) || (opt[i] == ')' &&GetTop(&s_opt) != '(')||(opt[i] == '\0' && EmptyStack(&s_opt) != 1))
                        {
                            switch (pop(&s_opt))
                            {
                                case '+':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num,num1 + num2);
                                break;
                                case '-':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num,num2 - num1);
                                break;
                                case '*':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num,num1 * num2);
                                break;
                                case '/':
                                num1 = pop(&s_num);
                                num2 = pop(&s_num);
                                push(&s_num,num2 - num1);
                                break;
                                }
                                }
                                }
                                }
                                printf("%d\n",GetTop(&s_num));
                                }