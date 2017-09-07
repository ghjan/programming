package com.dong.servlet;

import java.beans.IntrospectionException;
import java.beans.PropertyDescriptor;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.Enumeration;
import java.util.Map;

import javax.persistence.PrePersist;
import javax.servlet.ServletException;
import javax.servlet.ServletInputStream;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.commons.beanutils.BeanUtils;

import com.dong.entity.User;

public class Server extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//���߷�����ʹ��ʲô���룬�Լ���html������ʲô���룬���������ʲô���룬һ��htmlĬ��UTF-8
		request.setCharacterEncoding("UTF-8");//��仰ֻ��post�ύ����
					//�����get�ύ��ôҪ�� new String(name.getBytes("iso-8859-1"),"UTF-8");��ÿһ�仰����ת��
		
		//��ȡ������
		/*ServletInputStream is = request.getInputStream();
		int len = 0;
		byte[] b = new byte[1024];
		while((len = is.read(b))!=-1){
			System.out.println(new String(b,0,len));
		}*/
		
		test4(request);
	}
	//�ñ��˵Ŀ󽨽��з�װ��ֻ��Ҫһ�仰
	private void test4(HttpServletRequest request) {
		User u = new User();
		System.out.println("��װǰ��"+u);
		
		try {
			//�ÿ������װ����	����commons-beanutils-1.8.3.jar commons-logging-1.1.1.jar����jar��
			BeanUtils.populate(u, request.getParameterMap());//ֻҪһ�仰
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		System.out.println("��װ��"+u);
	}
	//��װ����
	private void test3(HttpServletRequest request) {
		try {
			User u = new User();
			System.out.println("��װ����ǰ"+u);
			//��ȡ������
			Map<String,String[]> map = request.getParameterMap();//ȫ���ŵ�map������
			//�ӿ� Map<K,V> �������ķ��� Set<Map.Entry<K,V>> entrySet()
			//Map�л���һ��Ƕ����static interface Map.Entry<K,V>  
			for (Map.Entry<String, String[]> m : map.entrySet()) {
				String name = m.getKey();
				String[] value = m.getValue();
				
				//�����������������ҵ���ָ�����е�get set��������������û�кܹ淶��дget set��������ô���Ҳ�����
				PropertyDescriptor pd = new PropertyDescriptor(name,User.class);
				//�õ�setter����
				Method setter = pd.getWriteMethod();//�õ���д����
				
				if(value.length == 1){//���ֵΨһ�Ļ�
					setter.invoke(u, value[0]);//��ֵ�ŵ� u ��ȥ
				}else{
					setter.invoke(u, (Object)value);//������ӣ�Object�� map���value��ɼ���ֵ��ǿת�Ժ󵱳�һ��ֵ
				}
			}
			System.out.println("��װ���ݺ�"+u);
			
//			���濴�Ÿ��ӵ���ͨ�ã���������һ��һ��ŪҲ����
//			String[] str = map.get("username");
//			u.setUsername(str);		//������Ҳ����
//			System.out.println("����"+str[0]);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	private void test2(HttpServletRequest request) {
		//��ȡ��name����
		Enumeration names = request.getParameterNames();//����������һ��ö��
		while(names.hasMoreElements()){
			String name = (String) names.nextElement();//�õ�����
			String[] value = request.getParameterValues(name);//�������֣��õ�ֵ
			for (int i = 0;name!=null && i < value.length; i++) {
				System.out.println(name+"\t"+value[i]);
			}
		}
	}
	//��ȡ������
	private void test1(HttpServletRequest request) {
		//���ݱ���name���Ե�������ȡvalue���Ե�ֵ����
		String username = request.getParameter("username");
		String pwd = request.getParameter("pwd");
		String sex = request.getParameter("sex");
		String[] hobby = request.getParameterValues("hobby");//����е㲻ͬ����ȡ����һ���ַ�������
		String city = request.getParameter("city");
		
		System.out.println(username);
		System.out.println(pwd);
		System.out.println(sex);
		System.out.println(city);
		//System.out.println(hobby);//��hobby��һ����û�б��򹳾���null
		if(hobby==null){
			System.out.println("û�а���");
		}else{
			for (int i = 0; i < hobby.length; i++) {
				System.out.println(hobby[i]+"\t");
			}
		}
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
