//
// Created by 苏建辉 on 2020/3/5.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_ROW 5
#define MAX_COL 5
int top=0;

struct point{
    int row;
    int col;
};

struct point stack[512];

int maze[MAX_ROW][MAX_COL] = {
        {0, 1, 1, 1, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 0},
};

struct point predecessor[MAX_ROW][MAX_COL] = {
        {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
        {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
        {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
        {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
        {{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
};

void print_maze()
{

    int i,j;

    for(i = 0;i<MAX_ROW;i++){
        for(j = 0;j<MAX_COL;j++){
            printf(" %d ",maze[i][j]);
        }
        putchar('\n');
    }
    sleep(1);
    printf("---------------------\n");
}

void push(struct point p)
{
    // store coordinate which visit just
    stack[top++] = p;
}

struct point pop()
{
    return stack[--top];
}

int is_empty()
{
    return top == 0;
}


void show_point(struct point p)
{
    printf("(%d,%d) top: %d \n",p.row,p.col,top);
}

void mark_path(int row,int col,struct point pre)
{
    maze[row][col] = 2;
    predecessor[row][col] = pre;
    pre.row = row;
    pre.col = col;
    push(pre);
}

int main(int argc, char ** argv)
{
    // set begin coordinate
    struct point p={0,0};
    maze[p.row][p.col] = 2;
    push(p);
    show_point(p);

    while(!is_empty())
    {
        p = pop();
        show_point(p);

        // if( (p.row + 1)  == MAX_ROW && (p.col + 1) == MAX_COL){
        if( p.row == (MAX_ROW - 1) && p.col == (MAX_COL - 1) ){
            break;
        }

        // 这样压栈有问题 属于单向压栈 遇到阻碍时无法回溯 仔细思考一下
        if(p.row + 1 < MAX_ROW && maze[p.row+1][p.col] == 0){
            mark_path(p.row + 1,p.col,p);
        } else if(p.col + 1 < MAX_COL && maze[p.row][p.col + 1] == 0) {
            mark_path(p.row,p.col + 1,p);
        } if(p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0) {
            mark_path(p.row,p.col - 1,p);
        } else if(p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0) {
            mark_path(p.row - 1,p.col,p);
        }

        print_maze();

    }

    if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
        printf("(%d, %d)\n", p.row, p.col);
        while (predecessor[p.row][p.col].row != -1) {
            p = predecessor[p.row][p.col];
            printf("(%d, %d)\n", p.row, p.col);
        }
    } else {
        printf("No path!\n");
    }



    return 0;
}