#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fuhao(int x,char y);
int yunsuan(int num1,int num2,char x);

main(){
	int score=0;    //记录答对的分数
	int x1,x2;   //储存随机符号数字
	int flag1,flag2;   //记录运行顺序
	int num,num1,num2,num3,i,answer1,answer2;   //num 为题目数量，num1~num3为三个阿拉伯数字，i为循环数，answer1为正确答案,answer2为用户输入的答案
	char f1,f2;  //符号

	printf("请输入题目的数量：");
	scanf("%d",&num);

	for(i=0;i<num;i++)
	{
		num1 = rand() % 100+1;
		num2 = rand() % 100+1;
		num3 = rand() % 100+1;

		x1=rand()%4;
		x2=rand()%4;
		flag1=fuhao(x1,&f1);
		flag2=fuhao(x2,&f2);
	
		//根据运算符的优先级计算出随机生成的算式的正确答案
		if(flag2==1 && flag1==0)
		{
			answer1=yunsuan(num1,yunsuan(num2,num3,x2),x1);
		}
		else
		{
			answer1=yunsuan(yunsuan(num1,num2,x1),num3,x2);
		}

		//答案小于零 重新生成
		if(answer1<0)
		{
			i--;
		}
		else
		{
			printf("%d%c%d%c%d=",num1,f1,num2,f2,num3);
			scanf("%d",&answer2);
			if(answer2!=answer1)
			{
				printf("回答错误，正确的答案为：%d\n",answer1);
			}
			else
			{
				score++;
			}
		}
	}
	printf("\n\n你的答题情况为(正确/总数)：%d/%d  ,分数为：%.2f\n",score,num,score/(float)num*100);
	system("pause");
}

//传入的y用来储存运算符号  返回值来记录运算的优先级
int fuhao(int x,char* y)
{
	if(x==0){
		*y='+';
		return 0;
	}else if(x==1){
		*y='-';
		return 0;
	}else if(x==2){
		*y='*';
		return 1;
	}else if(x==3){
		*y='/';
		return 1;
	}
}

//计算并返回结果
int yunsuan(int num1,int num2,char x)
{
	if(x==0){
		return num1+num2;
	}else if(x==1){
		return num1-num2;
	}else if(x==2){
		return num1*num2;
	}else if(x==3){
		return num1/num2;
	}
}