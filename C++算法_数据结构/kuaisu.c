void kuaisu(int a[],int n)
{
	quick(a,0,n-1);
 } 
 void quick(int a[],int left,int right)
{
	int t,l,r;
	l=left;
	r=right;
	t=a[l];
	if(l<r)
	{
	while(l<r)
	{
		while((a[r]>=t)&&(l<r))
		r--;
		a[l]=a[r];
		while((a[l]<=t)&&(l<r))
		 l++;
		a[r]=a[l];
	}
	a[l]=t;					/*��������ѭ����r=l*/ 
	quick(a,left,l-1);		/*����Ҫ��һ�㣺�ݹ����l��r��Ӱ�������l,r,Ҳ����˵�����r+1�е�r����Ӱ��*/ 
	quick(a,r+1,right);		/*r+1Ҳ���Ի���l+1����Ϊ����r=l,,�ݹ鲻�ı��ⲿ����r,l��ֵ��*/ 
}
}
