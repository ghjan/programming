#include <stdio.h>
#include <string.h>
int main()
{
 char word[100];int ok=0;
 scanf("%s",word);
 int l=strlen(word);
 for (int i=1; i<=l; ++i)//���ڱ���1��l,��Ϊ1�����ǳ�����
 {
  if (l%i==0)//��С���ڱ��ǳ��ȵ�Լ��			��һ���ǳ���Ҫ   
  {
   int ok=1;
   for (int j=i; j<l; ++j)
   {
//word[j]Ϊ�ڶ����ڵĵ�һ���ַ�,word[j%i]��ǰһ�����ڵĵ�һ���ַ�(��Ϊ
//j=i;j%i=0;jÿ��1,j%iҲ��1,ֱ�����һ��word[j]������word[j%i],��iΪ����
    if (word[j%i]!=word[j])//������Ϊj-1��� 
     {
      ok=0;
      break;
     }
   }
   if (ok) 
   {
    printf("%d\n",i);
    break;// this is the least cycle 
   }
  }
  else 
   continue;
 }
 return 0;
}
