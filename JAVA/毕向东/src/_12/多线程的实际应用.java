package _12;
/*
	for(int i=0;i<10;i++)
	System.out.println("for1..........."+i);
	
		for(int i=0;i<10;i++)
	System.out.println("for1..........."+i);
	
		for(int i=0;i<10;i++)
	System.out.println("for1..........."+i);
	
	���Ǿ�����Ҫ�ܼ���ѭ��
 */
public class ���̵߳�ʵ��Ӧ�� {

	public static void main(String[] args) {
		
		new Thread(){							//�����ڲ���			�ü̳еķ�ʽ
			public void run(){
			for(int i=0;i<10;i++)
				System.out.println("for1..........."+i);
			}
		}.start();
		
		Runnable r = new Runnable(){//��Runnable�ӿ�
			public void run(){
				for(int i=0;i<10;i++)
					System.out.println("for2..........."+i);
				}
		};
		new Thread(r).start();
		
		for(int i=0;i<10;i++)
			System.out.println("for3..........."+i);
	}
}
