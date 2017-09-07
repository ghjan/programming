package _07;
/**
 * ��ͽ���ģ�����ģʽ��
 * 
 * ʲô��ģ�巽���أ�
 * �ڶ��幦��ʱ�����ܵ�һ������ȷ���ģ�������һ�����ǲ�ȷ���ģ���ȷ���Ĳ���Ҫʹ�ò�ȷ���Ĳ��֣�
 * ��ô��ʱ�ͽ���ȷ���Ĳ��ֱ�¶��ȥ���ɸ��������ȥ���
 *
 * public static long currentTimeMillis()�����Ժ���Ϊ��λ�ĵ�ǰʱ�䡣ע�⣬������ֵ��ʱ�䵥λ�Ǻ���ʱ
 */
abstract class GetTime{
	public final void getTime(){					//����	final  ��Ϊ�� ���������า�Ǹ��෽��
		long  start = System.currentTimeMillis();
		
		runCode();
		
		long end = System.currentTimeMillis();
		
		System.out.println("\n����ʱ��:"+(double)(end - start)/1000);
	}
	
	public abstract void runCode();
}

class MyGetTime extends GetTime{
	public void runCode(){
		for(int i=0;i<100000;i++)
		{
			System.out.print(i+" ");
			if(i%100 == 0 )
				System.out.println();
		}
	}
}

public class ��ȡһ�γ������е�ʱ�� {
	public static void main(String[] args) {
		new MyGetTime().getTime();
	}
}
