package com.dong.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/*	ת�����ض��������
 * 
 * 	ת�� request �ɷ�����ִ��
	�ͻ���ֻ����һ������
	��ַ�����������������������������������������
	ת���ܹ���������***************************
	ת��Ҳ��һ�������
	servletContxt

	�ض��� response �ɿͻ���ִ��
	�ͻ��˷�����������
	��ַ���ᷢ���仯����������������������������������
	���ܴ�������*******************************
	������ת������Ӧ��***************************
*/

public class Demo5 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		request.setCharacterEncoding("UTF-8");//���߷�������ʲô���봦��������е�����
		response.setContentType("text/html;charset=UTF-8");//��Ӧ���ݵ�ʱ��ͳһ����
		
		System.out.println("A:�������");
		System.out.println("B:�Ұ첻�ˣ��ҿ��԰������˰���");
		
		//���Ǳ�������ӵ�request������
		request.setAttribute("code", "B:������ҵĺ����ѣ���������");
		
		
		//������ת��demo6��
		request.getRequestDispatcher("/servlet/Demo6").forward(request, response);
		//ע������ת�� ������ת������Ӧ��  ���ĸ�Ŀ¼ʼ������/http://localhost:8080/����
		//request.getRequestDispatcher("http://www.baidu.com").forward(request, response);//dispatcher ����
		
		
		//�ض���		(�����������ӣ�����ͬʱִ��)
		//request.getContextPath()�����˵�ǰapp����day09_01_HttpServletRequest  Ŀ�ģ������ǻ����ļ��������������У����øĴ���
		//response.sendRedirect(request.getContextPath()+"/servlet/Demo6");//redirect ���ģ��ż��ȣ�������ַ; �ı䷽��
		//ע���ض��������ת������Ӧ��
		//response.sendRedirect("http://www.baidu.com/");
		
		System.out.println("B:�°�����");
		
		System.out.println("����������������������൱�ڰ�Demo6�еĴ���ֱ��copy��������������");
		
		request.getRequestDispatcher("/servlet/Demo6").include(request, response);
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
