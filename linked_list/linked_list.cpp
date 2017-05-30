#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

void display(struct node *start);
struct node *addatbeg(struct node *start, int num);
void addatend(struct node *start, int num);
void addafter(struct node *start, int num, int num2);
struct node *addbefore(struct node *start, int num, int num2);
struct node *del(struct node *start);
void searchNode(struct node *start, int num);
void countNode(struct node *start);


int main()
{
    struct node *start = NULL;
    int choice, num, num2;
    while(1)
    {
        printf("1. Display :\n");
        printf("2. Add to empty list / add at beginning :\n");
        printf("3. Add at end :\n");
        printf("4. Add after node :\n");
        printf("5. Add before a node :\n");
        printf("6. Delete from list :\n");
        printf("7. Search node :\n");
        printf("8. Count number of node :\n");
        printf("9. Exit :\n");

        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("\nOUTPUT #: ");
            display(start);
            break;
        case 2:
            printf("Enter the number to be inserted : ");
            scanf("%d",&num);
            start = addatbeg(start, num);
            break;
        case 3:
            printf("Enter the number to be inserted : ");
            scanf("%d", &num);
            addatend(start, num);
            break;
        case 4:
            printf("Enter the number to be inserted : ");
            scanf("%d", &num);
            printf("Enter the number after which to insert : ");
            scanf("%d", &num2);
            addafter(start, num, num2);
            break;
        case 5:
            printf("Enter the number to be inserted : ");
            scanf("%d", &num);
            printf("Enter the number before which to insert : ");
            scanf("%d", &num2);
            start = addbefore(start, num, num2);
            break;
        case 6:
            start = del(start);
            break;
        case 7:
            printf("Enter the number to be searched: ");
            scanf("%d", &num);
            searchNode(start, num);
            break;
        case 8:
            countNode(start);
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}

struct node *addatbeg(struct node *start, int num)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;
    temp->link = start;
    start = temp;
    printf("\n\n");
    return start;
}
void display(struct node *start)
{
    struct node *p;
    if(start == NULL)
    {
        printf("List is empty.\n\n");
        return;
    }
    p = start;
    while(p!=NULL)
    {
        printf("%d ", p->info);
        p = p->link;
    }
    printf("\n\n");
}
void addatend(struct node *start, int num)
{
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;
    p = start;
    while(p->link != NULL)
    {
        p = p->link;
    }
    p->link = temp;
    temp->link = NULL;
}
void addafter(struct node *start, int num, int num2)
{
    struct node *temp, *p;
    p = start;
    while(p!= NULL)
    {
        if(p->info == num2)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = num;
            temp->link = p->link;
            p->link = temp;
            printf("\n");
            return;
        }
        p = p->link;
    }
    printf("\nOUTPUT #: %d is not present in the list.\n\n", num2);
}
void searchNode(struct node *start, int num)
{
    struct node *p;
    p = start;
    while(p != NULL)
    {
        if(p->info == num)
        {
            printf("\nOUTPUT #: %d found in the list\n\n", num);
            return;
        }
        p = p->link;
    }
    printf("\nOUTPUT #: %d not found in the list.\n\n", num);

}
void countNode(struct node *start)
{
    int cnt = 0;
    struct node *p;
    p = start;
    while(p != NULL)
    {
        p = p->link;
        cnt++;
    }
    printf("\nOUTPUT #: Number of node %d.\n\n", cnt);
}
struct node *del(struct node *start)
{
    int num;
    struct node *temp, *p;
    if(start == NULL)
    {
        printf("\nOUTPUT #: List is empty\n\n");
        return start;
    }
    else
    {
        printf("Enter the number to be deleted : ");
        scanf("%d", &num);
    }

    if(start->info == num)
    {
        temp = start;
        start = start->link;
        free(temp);
        printf("\nOUTPUT #: %d deleted\n\n", num);
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == num)
        {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            printf("\nOUTPUT #: %d deleted\n\n", num);
            return start;
        }
        p= p->link;
    }
    printf("\nOUTPUT #: %d is not present in the list\n\n", num);
    return start;
}
struct node *addbefore(struct node *start, int num, int num2)
{
    struct node *temp, *p;
    if(start->info == num2)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->info = num;
        temp->link = start;
        start = temp;
        printf("\n\n");
        return start;
    }
    p = start;
    while(p->link != NULL)
    {
        if(p->link->info == num2)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->info = num;
            temp->link = p->link;
            p->link = temp;
            printf("\n\n");
            return start;
        }
        p= p->link;
    }
    printf("\nOUTPUT #: %d is not present in the list.\n\n", num2);
    return start;
}


