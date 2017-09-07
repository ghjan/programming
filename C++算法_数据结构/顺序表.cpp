#include<stdio.h>
#include<malloc.h>
#define status int
struct sqlist
{
	int * elem;				//����ռ��ַ 
	int length;				//��ǰ���� 
	int listsize;			//����ڴ����� 
};
//˳�������ʼ��
void initlist(sqlist &l)
{
	l.elem=(int *)malloc(10*sizeof(int ));
	if(!l.elem)
	printf("overflow");
	else
	{
		l.length=0;
		l.listsize=10;			//Ĭ�ϴ�������Ϊ 10 
		printf("OK\n");
	}
}
//��������
status listinsert(sqlist &l,int i,int e)		// e λ����Ԫ��    i Ϊ�����λ�� 
{
	int *p,*q,*newbase;
	if(i<1|| i>l.length+1)
	{
		printf("%d error\n",i);
		return 0;
	}
	if(l.length>=l.listsize)
	{
		//����һ������Ŀռ�
		newbase=(int *)realloc(l.elem,(l.listsize+2)*sizeof(int ));
		 if(!newbase)
		 {
		 	printf("overflow\n");
		 	return 0;
		 }
		 l.elem=newbase;
		 l.listsize+=2;
	}
	q=&(l.elem[i-1]);   					 //  q  Ϊ����λ�� 
	for(p=&(l.elem[l.length -1]);p>=q;p--)	//����ƶ�  ֱ�� q  
	*(p+1)=*p;
	*q=e;									//����Ԫ�� 
	l.length++;						//�� ��һ 
	return 1; 
}
// �жϵ�ǰ˳����Ƿ�Ϊ��   Ϊ�� ����1 ���� ����0 
status listempty(sqlist l)
{
	if(l.length==0)
	return 1;
	else
	return 0;
}
//���˳���
void clearlist(sqlist &l)
{
	l.length=0;
 } 
 //��˳�����Ԫ�صĸ���
 int listlength(sqlist l)
 {
 	return l.length;
  } 
  status listdelete(sqlist &l,int i)			//ɾ��
 {
 	int *p,*q;
 	if(i<1|| i>l.length)
 	{
 		printf("i error\n");
 		return 0;
	 }
	 p=&(l.elem[i-1]);			//p   Ϊ��ɾԪ�ص�λ��
	 q=l.elem+l.length-1;		//*********************��ʼ��û����    ����q ָ���β��λ��
	 for(p++;p<=q;p++)
	 *(p-1)=*p;
	 l.length--;			//���� 1
	 return 1; 
  } 
 int main()
 {
 	status i;
 	int a,j,k,e;
 	sqlist l;
 	initlist(l);
 	printf("��ʼ��l��l.elem=%u\tl.length=%d\tl.listsize=%d\n",l.elem,l.length,l.listsize);	// %u �޷���ʮ������� 
 	printf("���ڱ�ͷ�Ȳ���5����\n");
 	for(j=1;j<=5;j++)
 	{
 		scanf("%d",&a);
 		i=listinsert(l,1,a);
	 }
	 
	 printf("ԭʼ����Ϊ:\n");
	 for(j=0;j<5;j++)
	 {
	 	printf("%d\t",*(l.elem+j));
	  } 
 	printf("\nl.elem=%u\tl.length=%d\tl.listsize=%d\n",l.elem,l.length,l.listsize);
 	clearlist(l);
 	printf("��պ�l.elem=%u\tl.length=%d\tl.listsize=%d\n",l.elem,l.length,l.listsize);
 	printf("�ڱ�β����l.elem=");
	for(j=5;j>0;j--)
	i=listinsert(l,1,j);
 	for(j=0;j<5;j++)
 	printf("%d\t",*(l.elem+j));
 	printf("\n");
 	k=listlength(l);
	for(j=k;j>0;j--)
	{
		printf("dong  ");
		i=listdelete(l,j);
		if(i==0)
		printf("error ");
		else
		printf("ɾ����%d��Ԫ�سɹ�:%d\n",j,l.elem[j-1]); 
	 } 
}
