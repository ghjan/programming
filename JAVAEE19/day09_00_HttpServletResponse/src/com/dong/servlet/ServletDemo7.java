package com.dong.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ServletDemo7 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		System.out.println("���Ǯ");
		System.out.println("��û��Ǯ���ҿ��Ը�����˭��Ǯ");
		/*//���߿ͷ����ض����µ���Դ
		response.setStatus(302);
//������������Ҫȥ��(ע������Ƿ������Լ�������ת����ô/ ����ľ��ǵ�ǰӦ��day09����ĵ�ַ��������������ô / ����ľ���8080����ĵ�ַ)������
		response.setHeader("location", "/day09_00_HttpServletResponse/servlet/ServletDemo1");*/
		
		//�������仰Ҳ���Ժϳ�һ�仰
		response.sendRedirect("https://www.baidu.com/");//redirect ���ģ��ż��ȣ�������ַ; �ı䷽��
		
		System.out.println("������");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
