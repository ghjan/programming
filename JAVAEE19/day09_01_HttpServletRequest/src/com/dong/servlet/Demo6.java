package com.dong.servlet;

import java.io.IOException;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class Demo6 extends HttpServlet {

	//��ӷǱ�����
	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		response.setContentType("text/html;charset=UTF-8");//��Ӧ���ݵ�ʱ��ͳһ����
		String code = (String) request.getAttribute("code");
		System.out.println(code);

		//���԰����Attribute�Ƴ�
		request.removeAttribute("code");
		System.out.println("�ٴγ��Դ�ӡcode��"+(String) request.getAttribute("code"));
		
		System.out.println("C:�°����");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
