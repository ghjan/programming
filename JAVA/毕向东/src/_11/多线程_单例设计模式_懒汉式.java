package _11;
/*
 * ����ʽ�ӳټ���
 * �ڶ��߳��У�����ְ�ȫ����
 * ʹ��ͬ���������
 */
class Single{
	private static Single s = null;
	private Single(){}
	public static Single getInstance(){
		if(s==null){
			synchronized(Single.class){//ʹ�õ����ǣ������������ֽ������
				if(s==null)
					s = new Single();
			}
		}
		return s;
	}
}
public class ���߳�_�������ģʽ_����ʽ {

}
