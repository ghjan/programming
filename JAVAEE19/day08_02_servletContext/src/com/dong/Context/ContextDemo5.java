package com.dong.Context;

import java.io.IOException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

//���´����¼�
public class ContextDemo5 extends HttpServlet {

	public void doGet(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		//�����
		System.out.println("����һ��");
		
		//��һ����Ӧ
		System.out.println("�Ұﲻ�ˣ������˰����");
		
		//�������´���
		ServletContext app = getServletContext();
		RequestDispatcher requestDispatcher = app.getRequestDispatcher("/servlet/ContextDemo6");
		requestDispatcher.forward(request, response);
		
		System.out.println("�°����");
	}

	public void doPost(HttpServletRequest request, HttpServletResponse response)
			throws ServletException, IOException {
		doGet(request, response);
	}

}
