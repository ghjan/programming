#include<stdio.h>
struct dong
{
	void (*nand_reset)(void);		// nand_reset ������� (* )����     ������н��� 
}nand_chip;
//�������  ���� typedef {}t_nand_chip  ����Ͱ�ע��ȥ��      ��ʵ���Ǽ����� typedef �� ��dong �Ϳ���ȥ���ˣ�   struct dong ���൱�� t_nand_chip 
//t_nand_chip nand_chip;
void s3c2440_nand_reset(void)
{
	printf("hello dong\n");
}
void nand(void)		
{
    nand_chip.nand_reset();
}
int main1()
{
	nand_chip.nand_reset=s3c2440_nand_reset;
	nand();
 } 
 // ����Ƕ��ʽ�Ƚϸ��� ���Ҫ��һ�δ�����ͨ����   ��ʱ�����������Ȧ�ӵĴ��� 
 //�ȴ�  nand�е��ýṹ���е� nand.reset�������ָ��  ���������ָ����ָ�� s3c2440 
  
 
 // ��������  �����ǰٶȵ����� 
 //C���Լ���--�ڽṹ����ʹ�ú������ӣ�����һ��ָ������ָ�룩 .����ͽ����� Ϊʲô ����Ҫ���ڣ�* �������� 
  
#include <malloc.h>   
#include <memory.h>   
#define DECLARATION int (*ptr)(int x,int y)   
#define DEFINITION(x,y) ptr(x,y)   
int sum(int x,int y)
{   
 printf("x:%d\n",x);
 printf("y:%d\n",y);

    return(x+y);   
}
int mul(int a,int b)
{
	return a*b;
}
typedef struct {  
        int r;  
  int (*ptr)(int x,int y);   //��ֻ��һ��ָ�룬����ָ���κ�  ���������β����ĺ��� 
} mystr;  
int main()  
{  
    int a,b,c;  
    scanf("%d%d",&a,&b);  
    mystr stru;    
  	
	stru.ptr=sum;   
	c=stru.ptr(a,b); 
    printf("a=%d,b=%d,sum=%d\n",a,b,c);
    
    stru.ptr = mul;
    c=stru.ptr(a,b);
    printf("mul = %d",c);
      
    /* mystr *stru1;   */
    /* stru1=(mystr *)malloc(sizeof(mystr));   */
    /* memset(stru1,0,sizeof(mystr));   */
    /* c=stru1->DEFINITION(a,b); */

 
  
    /* //c=stru->ptr(a,b);    */
    /* printf("a=%d,b=%d,sum=%d\n",a,b,c);   */
 /* memset(stru1,0,sizeof(mystr));   */
 /* free(stru1);  xz */
}   
