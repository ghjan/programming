package com.dong.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletDemo1 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//������Ĭ�ϱ���ISO-8859-1����֧�����ģ�tomcat�涨��
		
		/*//���߷�����ʹ��ʲô����
		response.setCharacterEncoding("UTF-8");//��Ҫ��仰����ô�����������������Ͳ鲻�����ģ�����仰�˾��ܲ鵽������
		//���߿ͷ���ʹ��ʲô����
		response.setHeader("content-type", "text/html;charset=UTF-8");//�ͷ��˱���ͷ�������һ���ı�������ʽ
*/		
		//�������仰���Ժϳ�һ�仰
		response.setContentType("text/html;charset=GBK");//ֻҪͬ���������ˣ������������������Ҫ�����ģ�������������ģ�
		
		PrintWriter out = response.getWriter();//�õ�һ���ַ������
		out.write("������love!!!!!!!");//��ͷ�����Ӧ�ı�����
		
		System.out.println("Demo1");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
