package ����;

import java.beans.BeanInfo;
import java.beans.IntrospectionException;
import java.beans.Introspector;
import java.beans.PropertyDescriptor;

/*
 * static BeanInfo getBeanInfo(Class<?> beanClass) 
          �� Java Bean �Ͻ�����ʡ���˽����������ԡ������ķ������¼� 
          
          PropertyDescriptor[] getPropertyDescriptors() 
          ��� beans PropertyDescriptor�� 
 */
public class ��ʡ {
	public static void main(String[] args) throws Exception {
		BeanInfo info = Introspector.getBeanInfo(Person.class,Object.class);//introspector��ʡ
		PropertyDescriptor[] pd = info.getPropertyDescriptors();
		for(PropertyDescriptor p : pd){
			System.out.println(p.getName());
		}
		
	}
}
