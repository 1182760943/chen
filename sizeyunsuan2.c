#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fuhao(int x,char y);
int yunsuan(int num1,int num2,char x);

main(){
	int score=0;    //��¼��Եķ���
	int x1,x2;   //���������������
	int flag1,flag2;   //��¼����˳��
	int num,num1,num2,num3,i,answer1,answer2;   //num Ϊ��Ŀ������num1~num3Ϊ�������������֣�iΪѭ������answer1Ϊ��ȷ��,answer2Ϊ�û�����Ĵ�
	char f1,f2;  //����

	printf("��������Ŀ��������");
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
	
		//��������������ȼ������������ɵ���ʽ����ȷ��
		if(flag2==1 && flag1==0)
		{
			answer1=yunsuan(num1,yunsuan(num2,num3,x2),x1);
		}
		else
		{
			answer1=yunsuan(yunsuan(num1,num2,x1),num3,x2);
		}

		//��С���� ��������
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
				printf("�ش������ȷ�Ĵ�Ϊ��%d\n",answer1);
			}
			else
			{
				score++;
			}
		}
	}
	printf("\n\n��Ĵ������Ϊ(��ȷ/����)��%d/%d  ,����Ϊ��%.2f\n",score,num,score/(float)num*100);
	system("pause");
}

//�����y���������������  ����ֵ����¼��������ȼ�
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

//���㲢���ؽ��
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